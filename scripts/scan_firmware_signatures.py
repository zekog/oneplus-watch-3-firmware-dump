#!/usr/bin/env python3
"""
scan_firmware_signatures.py
Comprehensive firmware signature scanner and binwalk-compatible parser.
Scans for standard container headers (ELF, MBN, UEFI, MELF, Fat, Zip, etc.)
and records file metadata and offsets.
"""

import sys
import os
import hashlib
import struct
import re
from pathlib import Path

COMMON_SIGNATURES = [
    (b"\x7fELF\x02\x01\x01", "ELF 64-bit LSB executable/relocatable"),
    (b"\x7fELF\x01\x01\x01", "ELF 32-bit LSB executable/relocatable"),
    (b"_FVH", "UEFI Firmware Volume Header (_FVH)"),
    (b"\x8a\xe6\x2b\x07", "UEFI FFS GUID (072be68a-6ec0-b209-9b83)"),
    (b"\x93\xfd\x21\x9e", "UEFI FFS GUID (9e21fd93-9c72-4c15-8c4b)"),
    (b"MELF", "Qualcomm Multi-ELF (MELF) container header"),
    (b"melf", "Qualcomm multi-elf marker"),
    (b"MSDOS5.0", "FAT Filesystem (MSDOS 5.0)"),
    (b"FAT16", "FAT16 Volume Identifier"),
    (b"PK\x03\x04", "Zip archive data"),
    (b"\x1f\x8b\x08", "GZIP compressed data"),
    (b"\xfd7zXZ\x00", "XZ compressed data"),
    (b"7z\xbc\xaf\x27\x1c", "7-Zip archive data"),
    (b"hsqs", "Squashfs filesystem, little endian"),
    (b"070701", "ASCII cpio archive (SVR4 with no CRC)"),
    (b"\x28\xb5\x2f\xfd", "Zstandard compressed data"),
    (b"\xd7\xb7\xab\x1e", "Android DTBO table header"),
    (b"AVB0", "Android Verified Boot (AVB) header"),
]

def scan_file(filepath: Path) -> dict:
    data = filepath.read_bytes()
    size = len(data)
    sha256 = hashlib.sha256(data).hexdigest()
    
    matches = []
    
    # 1. Signature scan
    for sig, desc in COMMON_SIGNATURES:
        start = 0
        while True:
            idx = data.find(sig, start)
            if idx == -1:
                break
            # Adjust offset for _FVH which is 0x28 bytes into the volume header
            if sig == b"_FVH" and idx >= 0x28:
                vol_offset = idx - 0x28
                matches.append((vol_offset, f"UEFI Firmware Volume (header at 0x{idx:X})"))
            else:
                matches.append((idx, desc))
            start = idx + 1

    # 2. Check for MBN header if size >= 40
    if size >= 40:
        magic = struct.unpack_from("<I", data, 0)[0]
        version = struct.unpack_from("<I", data, 4)[0]
        if magic in (3, 5, 6, 7, 8) and version in (3, 5, 6, 7, 8, 0):
            matches.append((0, f"Qualcomm MBN header (image_id={magic}, version={version})"))

    # 3. Search for Qualcomm strings
    keywords = [
        b"Sahara", b"Firehose", b"prog_firehose", b"devprg", b"s_devprg",
        b"xbl_s_devprg", b"programmer", b"sahara_protocol", b"dload_entry"
    ]
    for kw in keywords:
        pos = data.find(kw)
        if pos != -1:
            matches.append((pos, f"Qualcomm keyword string: '{kw.decode()}'"))

    matches.sort(key=lambda x: x[0])
    
    # Deduplicate matches at exact same offset
    dedup = []
    seen = set()
    for off, desc in matches:
        key = (off, desc)
        if key not in seen:
            seen.add(key)
            dedup.append((off, desc))

    return {
        "path": filepath,
        "size": size,
        "sha256": sha256,
        "matches": dedup
    }

def main():
    if len(sys.argv) < 3:
        print("Usage: scan_firmware_signatures.py <input_file> <output_report>")
        sys.exit(1)
        
    infile = Path(sys.argv[1])
    outfile = Path(sys.argv[2])
    
    if not infile.exists():
        print(f"Error: {infile} does not exist")
        sys.exit(1)
        
    res = scan_file(infile)
    
    outfile.parent.mkdir(parents=True, exist_ok=True)
    with open(outfile, "w", encoding="utf-8") as f:
        f.write(f"Scan Report for: {res['path'].name}\n")
        f.write(f"Full Path: {res['path']}\n")
        f.write(f"Size: {res['size']:,} bytes ({res['size'] / (1024*1024):.2f} MB)\n")
        f.write(f"SHA-256: {res['sha256']}\n\n")
        f.write(f"{'DECIMAL':<12} {'HEXADECIMAL':<14} {'DESCRIPTION'}\n")
        f.write(f"{'-'*12} {'-'*14} {'-'*50}\n")
        
        if not res["matches"]:
            f.write("No standard signatures recognized.\n")
        else:
            for off, desc in res["matches"]:
                f.write(f"{off:<12} 0x{off:<12X} {desc}\n")
                
    print(f"[+] Written report to {outfile}")

if __name__ == "__main__":
    main()
