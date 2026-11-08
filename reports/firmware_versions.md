# Firmware Versions & Dump Coverage - OnePlus Watch 3 (OPWWE251)

This document records exactly which OTA builds this repository contains, and why
the newest build cannot be dumped from the published update package.

---

## 1. Covered Build: `OPWWE251_11_A.127`

| Property                             | Value                                                                                           |
| ------------------------------------ | ----------------------------------------------------------------------------------------------- |
| OTA version (`ro.build.version.ota`) | `OPWWE251_11.A.127_1270_202505202143`                                                           |
| Display ID (`ro.build.display.id`)   | `OPWWE251_11_A.127`                                                                             |
| Full ID (`ro.build.display.full_id`) | `OPWWE251_11_A.127_250520`                                                                      |
| Build fingerprint                    | `OnePlus/OPWWE251/OPWWE251:14/AW2A.240903.001.A3.OPWWE251_11_A.127.250520/01:user/release-keys` |
| Build date                           | Tue May 20 22:59:40 CST 2025 (`ro.build.date.utc=1747753180`)                                   |
| Security patch level                 | `2025-05-01`                                                                                    |
| Android / Wear OS                    | Android 14 (Wear OS), GKI boot image header v4                                                  |
| Linux kernel                         | **5.15.170**-android14-11-maybe-dirty                                                           |
| Bootloader string                    | `OPWWE251-OPWWE251_11_A.127_250520`                                                             |
| Package type                         | **Full OTA** (`ota-type=BLOCK`, complete `*.new.dat.br` payloads)                               |

Source: `META-INF/com/android/metadata` and
`extracted_images/system_dump/system/build_24965.prop`.

All artifacts in this repository come from this build:

- `extracted_images/kernel`, `extracted_images/kernel_with_symbols.elf` (141,777 symbols)
- `extracted_images/*.img` (`system`, `vendor`, `product`, `system_ext`, `vendor_dlkm`, `system_dlkm`, `boot`, `init_boot`, `vendor_boot`, `dtbo`)
- `extracted_images/device_tree/*.dts`
- `extracted_images/vendor_dlkm_extracted/lib/modules/*.ko` (vermagic `5.15.170-android14-11-maybe-dirty`)
- `mcu_firmware/OPWWE251/*` (BES2610 RTOS, build tag `2505201801`)
- `firmware-update/*` (XBL/ABL/TZ/HYP/RPM/DSP images shipped with the OTA)

---

## 2. Not Covered: `OPWWE251_11_A.165`

| Property                     | Value                                         |
| ---------------------------- | --------------------------------------------- |
| OTA version                  | `OPWWE251_11_A.165`                           |
| Linux kernel                 | **5.15.185**                                  |
| Package type                 | **Incremental (delta) OTA**                   |
| Full firmware dump available | **No - impossible from the published update** |

### Why there is no A.165 dump

OnePlus distributes A.165 as an incremental update. Such a package contains only
block-level **patch** data (`*.patch.dat` plus a `transfer.list` that references
the already-installed blocks), not whole partition images:

- There is no `*.new.dat.br` payload to decompress.
- `extract_ota.py` requires full-OTA payloads; it cannot reconstruct partitions
  from a delta package, because the missing blocks must be read from the
  previously installed A.127 images.
- Consequently there is nothing to extract, unpack, or analyze. No A.165 kernel,
  DTS, kernel module, HAL binary, or RTOS firmware exists in this repository.

### How A.165 could still be obtained

1. **Device-side pull** from a watch already running A.165
   (`adb shell dd` / `edl r` of `boot`, `init_boot`, `vendor_boot`, `system`,
   `vendor`, `product`, `system_ext`, `vendor_dlkm`, `system_dlkm`, `dtbo`).
2. **Full OTA package** for A.165, if/when OnePlus publishes one (look for a
   `*.new.dat.br`-style payload, not `*.patch.dat`).
3. Applying the incremental update on a captured A.127 base and reconciling the
   patches offline.

---

## 3. Impact on Existing Documentation

Every finding in this repository was produced against **A.127 / Linux 5.15.170**,
including:

- kernel symbol count (141,777) and the driver/module audit
- the `vendor_dlkm` module inventory and `vermagic` values
- DTS/DTBO decompilation
- kernel-version references in security analysis (e.g. privilege-escalation notes)

Kernel-version-sensitive claims should be treated as **A.127-only** until
re-verified against an A.165 (5.15.185) dump.
