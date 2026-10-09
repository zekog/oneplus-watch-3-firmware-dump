#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Automated Android OTA update processing script:
1. Verifies and installs required dependencies (brotli, requests).
2. Decompresses *.dat.br files to *.dat using the brotli module.
3. Downloads or creates sdat2img.py and converts (.transfer.list + .new.dat -> .img).
4. Copies existing partition images (.img) and places generated ones into extracted_images/.
5. Validates files and generates a comprehensive verification report with sizes in MB.
"""

import os
import sys
import time
import shutil
import subprocess
from pathlib import Path

SDAT2IMG_URL = "https://raw.githubusercontent.com/xpirt/sdat2img/master/sdat2img.py"

FALLBACK_SDAT2IMG_CODE = '''#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys, os, errno

def rangeset(src):
    src_set = src.split(',')
    num_set = [int(item) for item in src_set]
    if len(num_set) != num_set[0] + 1:
        print(f"Error parsing rangeset: {src}", file=sys.stderr)
        sys.exit(1)
    return tuple([(num_set[i], num_set[i+1]) for i in range(1, len(num_set), 2)])

def main(transfer_list_file, new_data_file, output_image_file):
    BLOCK_SIZE = 4096
    with open(transfer_list_file, 'r', encoding='utf-8') as trans_list:
        version = int(trans_list.readline().strip())
        new_blocks = int(trans_list.readline().strip())
        if version >= 2:
            trans_list.readline()
            trans_list.readline()

        commands = []
        for line in trans_list:
            parts = line.strip().split(' ')
            if not parts or not parts[0]:
                continue
            cmd = parts[0]
            if cmd in ('erase', 'new', 'zero'):
                commands.append((cmd, rangeset(parts[1])))

    all_blocks = [r for c in commands for r in c[1]]
    max_file_size = max((r[1] for r in all_blocks), default=0) * BLOCK_SIZE

    with open(new_data_file, 'rb') as dat_in, open(output_image_file, 'wb') as img_out:
        for cmd, ranges in commands:
            if cmd == 'new':
                for begin, end in ranges:
                    img_out.seek(begin * BLOCK_SIZE)
                    to_copy = (end - begin) * BLOCK_SIZE
                    while to_copy > 0:
                        chunk = dat_in.read(min(to_copy, 1024 * 1024))
                        if not chunk:
                            break
                        img_out.write(chunk)
                        to_copy -= len(chunk)
            elif cmd == 'zero':
                for begin, end in ranges:
                    img_out.seek(begin * BLOCK_SIZE)
                    zeros = b'\\x00' * min((end - begin) * BLOCK_SIZE, 1024 * 1024)
                    to_zero = (end - begin) * BLOCK_SIZE
                    while to_zero > 0:
                        cz = min(to_zero, len(zeros))
                        img_out.write(zeros[:cz])
                        to_zero -= cz

        if img_out.tell() < max_file_size:
            img_out.truncate(max_file_size)

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: sdat2img.py <transfer_list> <new_dat> [output_img]")
        sys.exit(1)
    out_img = sys.argv[3] if len(sys.argv) > 3 else "system.img"
    main(sys.argv[1], sys.argv[2], out_img)
'''


def check_and_install_dependencies():
    """Step 1: Checks for brotli and requests modules, installs them if missing."""
    print("=" * 70)
    print("STEP 1: Checking required dependencies (brotli, requests)...")
    print("=" * 70)

    modules_to_check = {
        "brotli": "brotli",
        "requests": "requests",
    }

    missing_packages = []
    for mod_name, pkg_name in modules_to_check.items():
        try:
            __import__(mod_name)
            print(f"  [OK] Module '{mod_name}' is already installed.")
        except ImportError:
            print(f"  [!] Missing module '{mod_name}' in environment.")
            missing_packages.append(pkg_name)

    if missing_packages:
        print(f"[*] Installing missing packages: {', '.join(missing_packages)}...")
        try:
            subprocess.check_call([sys.executable, "-m", "pip", "install"] + missing_packages)
        except subprocess.CalledProcessError:
            # Fallback for externally-managed environments (PEP 668)
            print("[*] Retrying installation with --break-system-packages flag...")
            subprocess.check_call(
                [sys.executable, "-m", "pip", "install", "--break-system-packages"] + missing_packages
            )

        # Verification after installation
        for mod_name in modules_to_check:
            __import__(mod_name)
            print(f"  [OK] Verified import for '{mod_name}'.")

    print("[OK] All dependencies are ready.\n")


def ensure_sdat2img(sdat2img_file: Path) -> Path:
    """Step 2: Ensures sdat2img.py script exists (downloads or creates fallback)."""
    print("=" * 70)
    print("STEP 2: Checking / downloading sdat2img conversion tool...")
    print("=" * 70)

    if sdat2img_file.exists() and sdat2img_file.stat().st_size > 0:
        print(f"  [OK] Script {sdat2img_file.name} is already present in the workspace.")
        return sdat2img_file

    import requests

    print(f"  [*] Downloading sdat2img.py from: {SDAT2IMG_URL}...")
    try:
        response = requests.get(SDAT2IMG_URL, timeout=15)
        if response.status_code == 200 and len(response.text) > 500:
            sdat2img_file.write_text(response.text, encoding="utf-8")
            sdat2img_file.chmod(0o755)
            print("  [OK] sdat2img.py successfully downloaded from GitHub repository.")
            return sdat2img_file
        else:
            print(f"  [!] Download returned HTTP {response.status_code}. Creating local fallback...")
    except Exception as e:
        print(f"  [!] Network error ({e}). Creating local fallback script...")

    sdat2img_file.write_text(FALLBACK_SDAT2IMG_CODE, encoding="utf-8")
    sdat2img_file.chmod(0o755)
    print("  [OK] Local fallback sdat2img.py successfully created.")
    return sdat2img_file


def get_expected_dat_size(transfer_list_path: Path):
    """Reads block count from .transfer.list and calculates expected .new.dat size."""
    try:
        with open(transfer_list_path, "r", encoding="utf-8") as f:
            version = int(f.readline().strip())
            new_blocks = int(f.readline().strip())
            return new_blocks * 4096
    except Exception:
        return None


def decompress_dat_br_files(work_dir: Path):
    """Step 3: Finds *.dat.br files and decompresses them to *.dat using brotli."""
    import brotli

    print("=" * 70)
    print("STEP 3: Decompressing .dat.br files to .dat (brotli streaming)...")
    print("=" * 70)

    br_files = sorted(work_dir.glob("*.dat.br"))
    if not br_files:
        print("  [i] No .dat.br files found in the current directory.")
        return

    for br_file in br_files:
        # e.g. product.new.dat.br -> product.new.dat
        target_dat = br_file.with_name(br_file.name[:-3])
        prefix = target_dat.name.replace(".new.dat", "").replace(".dat", "")
        transfer_list = work_dir / f"{prefix}.transfer.list"
        expected_size = get_expected_dat_size(transfer_list) if transfer_list.exists() else None

        # Check if already decompressed and complete
        if target_dat.exists() and target_dat.stat().st_size > 0:
            if expected_size is None or target_dat.stat().st_size == expected_size:
                size_mb = target_dat.stat().st_size / (1024 * 1024)
                print(f"  [SKIPPED] {target_dat.name} already exists and is complete ({size_mb:.2f} MB).")
                continue
            else:
                print(f"  [!] {target_dat.name} exists but size is incomplete. Re-decompressing...")

        src_size_mb = br_file.stat().st_size / (1024 * 1024)
        print(f"  [*] Decompressing {br_file.name} ({src_size_mb:.2f} MB) -> {target_dat.name}...")
        t0 = time.time()

        temp_target = target_dat.with_suffix(target_dat.suffix + ".part")
        decompressor = brotli.Decompressor()
        bytes_in = 0
        bytes_out = 0

        with open(br_file, "rb") as f_in, open(temp_target, "wb") as f_out:
            while True:
                chunk = f_in.read(2 * 1024 * 1024)
                if not chunk:
                    break
                bytes_in += len(chunk)
                decompressed = decompressor.process(chunk)
                if decompressed:
                    f_out.write(decompressed)
                    bytes_out += len(decompressed)

        temp_target.rename(target_dat)
        elapsed = time.time() - t0
        out_mb = bytes_out / (1024 * 1024)
        print(f"  [OK] Decompressed: {target_dat.name} in {elapsed:.2f}s ({out_mb:.2f} MB).")

    print("[OK] All .dat.br files successfully decompressed.\n")


def convert_partitions_to_img(work_dir: Path, output_dir: Path, sdat2img_file: Path):
    """Step 4: Converts .transfer.list and .new.dat pairs into .img filesystem images."""
    print("=" * 70)
    print("STEP 4: Converting .transfer.list and .new.dat pairs to .img files...")
    print("=" * 70)

    transfer_lists = sorted(work_dir.glob("*.transfer.list"))
    if not transfer_lists:
        print("  [!] No .transfer.list files found for conversion.")
        return

    output_dir.mkdir(parents=True, exist_ok=True)

    for trans_file in transfer_lists:
        prefix = trans_file.name[:-len(".transfer.list")]
        # Search for corresponding dat file (prefer prefix.new.dat, then prefix.dat)
        new_dat = work_dir / f"{prefix}.new.dat"
        if not new_dat.exists():
            new_dat = work_dir / f"{prefix}.dat"

        if not new_dat.exists():
            print(f"  [!] Missing corresponding .dat file for {trans_file.name}. Skipping.")
            continue

        target_img = output_dir / f"{prefix}.img"
        expected_size = get_expected_dat_size(trans_file)

        if target_img.exists() and target_img.stat().st_size > 0:
            if expected_size is None or target_img.stat().st_size >= expected_size:
                size_mb = target_img.stat().st_size / (1024 * 1024)
                print(f"  [SKIPPED] {target_img.name} already exists ({size_mb:.2f} MB).")
                continue

        print(f"  [*] Converting: {trans_file.name} + {new_dat.name} -> {target_img.name}...")
        t0 = time.time()
        cmd = [sys.executable, str(sdat2img_file), str(trans_file), str(new_dat), str(target_img)]

        result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if result.returncode != 0:
            print(f"  [ERROR] Conversion failed for {prefix}:")
            print(result.stderr)
            continue

        elapsed = time.time() - t0
        img_size_mb = target_img.stat().st_size / (1024 * 1024) if target_img.exists() else 0
        print(f"  [OK] Generated {target_img.name} ({img_size_mb:.2f} MB) in {elapsed:.2f}s.")

    print("[OK] Partition image generation complete.\n")


def copy_existing_images(work_dir: Path, output_dir: Path):
    """Step 5: Copies pre-existing .img images (boot.img, init_boot.img, vendor_boot.img)."""
    print("=" * 70)
    print("STEP 5: Copying pre-existing .img images into extracted_images/...")
    print("=" * 70)

    # Images residing directly in the root working folder
    existing_images = sorted([f for f in work_dir.glob("*.img") if f.is_file()])
    if not existing_images:
        print("  [i] No ready .img images found in source root directory.")
        return

    output_dir.mkdir(parents=True, exist_ok=True)

    for img in existing_images:
        dest = output_dir / img.name
        if dest.exists() and dest.stat().st_size == img.stat().st_size:
            size_mb = dest.stat().st_size / (1024 * 1024)
            print(f"  [SKIPPED] {img.name} already present in {output_dir.name}/ ({size_mb:.2f} MB).")
            continue

        print(f"  [*] Copying: {img.name} -> {dest.relative_to(work_dir)}...")
        shutil.copy2(img, dest)
        size_mb = dest.stat().st_size / (1024 * 1024)
        print(f"  [OK] Copied: {dest.name} ({size_mb:.2f} MB).")

    print("[OK] Copying pre-existing images complete.\n")


def generate_verification_report(output_dir: Path):
    """Step 6: Verifies output directory contents and generates a detailed report."""
    print("=" * 70)
    print("STEP 6: Validating files and generating final verification report...")
    print("=" * 70)

    images = sorted(output_dir.glob("*.img"))
    if not images:
        print("  [!] No .img files found in output directory!")
        return []

    report_lines = []
    header = f"{'No.':<4} | {'Filename':<20} | {'Size (MB)':<14} | {'Size (Bytes)':<16} | {'Status'}"
    separator = "-" * len(header)

    report_lines.append("ANDROID OTA FIRMWARE EXTRACTION VERIFICATION REPORT")
    report_lines.append(f"Directory: {output_dir.resolve()}")
    report_lines.append(f"Generated at: {time.strftime('%Y-%m-%d %H:%M:%S')}")
    report_lines.append("")
    report_lines.append(separator)
    report_lines.append(header)
    report_lines.append(separator)

    print("\n" + separator)
    print(header)
    print(separator)

    total_bytes = 0
    file_details = []

    for idx, img in enumerate(images, start=1):
        size_bytes = img.stat().st_size
        total_bytes += size_bytes
        size_mb = size_bytes / (1024 * 1024)

        status = "VALID" if size_bytes > 0 else "ERROR (0 B)"
        line = f"{idx:<4} | {img.name:<20} | {size_mb:>10.2f} MB | {size_bytes:>16,d} B | {status}"
        report_lines.append(line)
        print(line)
        file_details.append({
            "name": img.name,
            "size_mb": size_mb,
            "size_bytes": size_bytes,
            "status": status,
        })

    total_mb = total_bytes / (1024 * 1024)
    total_gb = total_bytes / (1024 * 1024 * 1024)
    summary_sep = "=" * len(header)
    summary_line = f"Total: {len(images)} .img files | {total_mb:,.2f} MB ({total_gb:.2f} GB)"

    report_lines.append(separator)
    report_lines.append(summary_line)
    report_lines.append(summary_sep)

    print(separator)
    print(summary_line)
    print(summary_sep + "\n")

    # Save report to text file
    report_file = output_dir / "verification_report.txt"
    report_file.write_text("\n".join(report_lines), encoding="utf-8")
    print(f"[OK] Verification report saved to: {report_file.relative_to(output_dir.parent)}\n")

    return file_details


def main():
    work_dir = Path(".").resolve()
    output_dir = work_dir / "extracted_images"
    sdat2img_file = work_dir / "sdat2img.py"

    print("\n" + "#" * 70)
    print("STARTING AUTOMATED ANDROID OTA FIRMWARE PROCESSING")
    print(f"Working Directory : {work_dir}")
    print(f"Output Directory  : {output_dir}")
    print("#" * 70 + "\n")

    start_total_time = time.time()

    # Step 1: Verify and install dependencies
    check_and_install_dependencies()

    # Step 2: Ensure sdat2img.py is present
    ensure_sdat2img(sdat2img_file)

    # Step 3: Decompress .dat.br files to .dat
    decompress_dat_br_files(work_dir)

    # Step 4: Convert .transfer.list + .new.dat pairs to .img
    convert_partitions_to_img(work_dir, output_dir, sdat2img_file)

    # Step 5: Copy pre-existing images (.img)
    copy_existing_images(work_dir, output_dir)

    # Step 6: Validate files and generate report
    generate_verification_report(output_dir)

    total_time = time.time() - start_total_time
    print(f"[SUCCESS] Total execution time: {total_time:.2f} s.\n")


if __name__ == "__main__":
    main()
