# Firehose Loader Search - OnePlus Watch 3 (OPWWE251)

## Executive Summary
- **Platform:** Qualcomm Snapdragon W5+ Gen 1 (`monaco`, SW5100 / SDA5100)
- **Objective:** Locate a Firehose loader (EDL flash programmer, e.g., `prog_firehose_ddr.elf` or `xbl_s_devprg_ns.melf`) for Emergency Download mode (EDL 9008).
- **Status:** **NOT FOUND** (No standalone Firehose programmer file is included in the public OTA update image).

---

## Scanned Binaries

| Filename | File Size | Signature Scan Results (binwalk / unblob) | Detected EDL / Sahara Signatures |
|---|---|---|---|
| `xbl.elf` | 2.83 MB | ELF 64-bit; UEFI FV (0x6C000); GZIP (0xA9368); Embedded ELF64 (0x279000) | `Sahara: Hello pkt sent`, `pmic DevPrg init`, `Entering DeviceProg lite`, `sbl1_sahara.c`, `dload_entry` |
| `NON-HLOS.bin` | 33.05 MB | FAT16 / MBN baseband modem subsystem | `qdlDg*b` (random string / no protocol implementation) |
| `xbl_config.elf` | 23.47 KB | ELF 64-bit LSB (XBL / PMIC configuration) | No Firehose/Sahara signatures |
| `dspso.bin` | 64.00 MB | Hexagon DSP shared library image | No Firehose/Sahara signatures |
| `static_nvbk.bin`| 10.00 MB | Persistent NVRAM backup storage | No Firehose/Sahara signatures |
| `qupv3fw.elf` | 58.01 KB | ELF 64-bit LSB (QUP v3 engine firmware) | No Firehose/Sahara signatures |
| `rpm.mbn` | 243.47 KB | MBN Cortex-M3 (Resource Power Manager) | No Firehose/Sahara signatures |
| `abl.elf` | 263.42 KB | UEFI FV (`_FVH`), LinuxLoader PE32 | `WriteRecoveryMessageEdl`, `fastboot` |
| `imagefv.elf` | 16.00 KB | UEFI FV (`_FVH`), BMP graphical icon resources | No Firehose/Sahara signatures |
| `hyp.mbn` | 354.51 KB | MBN EL2 (Qualcomm Hypervisor) | No Firehose/Sahara signatures |
| `tz.mbn` | 2.94 MB | MBN EL3 (Qualcomm TrustZone OS) | No Firehose/Sahara signatures |

---

## Identified Signatures

String analysis results recorded in `reports/firehose_search/signatures_found.txt`:

```text
=== xbl.elf ===
boot_dload.c
boot_dload_check
boot_dload_debug_target.c
boot_dload_dump.c
boot_dload_dump_security_regions
boot_dload_handle_forced_dload_timeout
boot_error_handler: Ramdump allowed. Trying to enter DLOAD
boot_init_for_dload
DloadCookieAddr
DloadCookieAddr = 0x003D3000 
DloadCookieAddr not found in uefiplat.cfg
DloadCookieValue
DloadCookieValue = 0x10
DloadCookieValue not found in uefiplat.cfg
EDL: sbl1_dload_entry: dload_entry_count > 1
EMERGENCY_DLOAD_TIMEOUT_COOKIE_SET: Reset
ERROR: Failed to set DLOAD cookie
pmic DevPrg init
Sahara: Hello pkt sent
Sahara: Hello Response Received
Sahara: Reset request received
sbl1_hw_dload_init
sbl1_sahara.c
=== NON-HLOS.bin ===
qdlDg*b
=== xbl_config.elf ===
=== dspso.bin ===
=== static_nvbk.bin ===
=== qupv3fw.elf ===
=== rpm.mbn ===
=== abl.elf ===
=== imagefv.elf ===
=== hyp.mbn ===
=== tz.mbn ===
```

Additionally, in `xbl.elf` (binary offset `0x3e510` - `0x3e530`), the following strings were identified:
- `pmic DevPrg init`
- `Entering DeviceProg lite`
- `/dev/icbcfg/boot`
- `sbl1_save_ddr_training_data`

---

## Matched Files (melf, devprg, firehose)

Workspace-wide search results (`reports/firehose_search/file_search.txt`):

```text
./extracted_images/vendor_dump/firmware/mcufirmware/OPWWE251/programmer.bin
./extracted_images/vendor_dump/firmware/mcufirmware/OWWE251/programmer.bin
./mcu_firmware/OPWWE251/programmer.bin
```

*Note:* The `programmer.bin` files belong to the Bestechnic BES2610 microcontroller (RTOS co-processor), not to the Qualcomm Snapdragon W5+ platform.

---

## Conclusions

- **Was a Firehose loader found?** **NO**.
  The stock OTA update package does not contain a standalone Firehose programmer file (`prog_firehose_ddr.elf` or `prog_firehose_lite.elf`), which is standard practice among OEMs (Qualcomm and OnePlus distribute Firehose programmers strictly within internal factory servicing packages such as MSM Download Tool / Oppo Flash Tool).
- **Key Internal Findings:**
  1. `xbl.elf` integrates `DevPrg lite` bootstrap routines (`Entering DeviceProg lite`, `pmic DevPrg init`).
  2. At byte offset `0x279000` (2,592,768 B) inside `xbl.elf`, a standalone ELF64 binary was identified and extracted (**`reports/firehose_search/xbl_melf_candidate.bin`**, 376,832 bytes).
  3. The extracted image is **`XBLRamDump`** (`XBLRamDump.dll`), implementing the Qualcomm Sahara protocol (`sbl1_sahara.c`), QPST reset handling, and emergency memory dump procedures over USB (`QUSB_BULK`).

---

## Next Steps

- [ ] In-depth disassembly in Ghidra for `xbl.elf` and the extracted `xbl_melf_candidate.bin` to analyze Sahara command handling and DeviceProg entry conditions.
- [ ] Investigate firmware dumps from **Mobvoi TicWatch Pro 5 / TicWatch Pro 5 Enduro** (same Qualcomm Snapdragon W5+ Gen 1 / SW5100 platform) to see if the community obtained a compatible Firehose MELF/ELF loader.
- [ ] Monitor for leaked OnePlus/Oppo factory servicing tools (Oppo Flash Tool for OPWWE251).
- [ ] Consult with the EDL research community on the XDA Developers forum.
