# OnePlus Watch 3 (OPWWE251) Firmware Analysis & DTS Dump

[![Firmware Build](https://img.shields.io/badge/Build-OPWWE251__11__A.165-blue.svg)](https://github.com)
[![Platform](https://img.shields.io/badge/SoC-Qualcomm_Snapdragon_W5+_Gen_1_(Monaco)-green.svg)](https://www.qualcomm.com)
[![Co--processor](https://img.shields.io/badge/MCU-Bestechnic_BES2610-orange.svg)](https://www.bestechnic.com)
[![Android](https://img.shields.io/badge/OS-Wear_OS_(Android_14_GKI)-brightgreen.svg)](https://source.android.com)
[![Discord](https://img.shields.io/badge/Discord-Join%20Community-5865F2?logo=discord&logoColor=white)](https://discord.gg/F4YK2YhFMc)

A comprehensive reverse-engineering, firmware extraction, and device-tree decompilation repository for the **OnePlus Watch 3 (OPWWE251)** smartwatch.

---

## 📋 Overview & Hardware Architecture

The OnePlus Watch 3 utilizes a dual-engine / dual-OS hybrid architecture designed for extreme battery efficiency and responsiveness:
* **Application Processor (AP):** Qualcomm Snapdragon W5+ Gen 1 (codename `monaco` / `Dialga`, SW5100 / SDA5100) running stock Google Wear OS (Android 14) with a 64-bit Linux Generic Kernel Image (GKI v4, Linux 5.15.170). Build fingerprint: `google/monaco/monaco:14/AW2A.240903.001.A3/64:user/release-keys` (security patch 2025-05-01).
* **Low-Power Co-Processor (MCU/RTOS):** **Bestechnic BES2610** (Dual-core ARM Cortex-M55 + low-power subsystem; *corrected from earlier misidentification as BES2800*) running an RTOS for background health tracking, always-on display, and low-power watchfaces. The kernel driver is `bes2610.ko` and DTS node is `bes2610,master_spi`.
* **Inter-Processor Communication (IPC):** Handled via `/vendor/bin/hw/vendor-oplus-hardware-transfer@1.0-service` implementing the HIDL interface `vendor.oplus.hardware.transfer@1.0::ITransfer`, paired with `/dev/mcu_upgrade` and high-speed SPI interconnect.
* **Confirmed Project ID & Hardware Revision:**
  * **OnePlus Watch 3 (`OPWWE251`):** Project ID **`24965`** (`ro.separate.soft=24965`), Hardware Revision **`XK929`** (`ro.product.hardware=XK929`), Brand `OnePlus` (`ro.product.brand=OnePlus`, `ro.oppo.market.name=OnePlus Watch`, `ro.product.display_name=OnePlus Watch 3`). Confirmed via `system_extracted/system/build_24965.prop`.
  * **OPPO Watch X2 (`OWWE251`):** Project ID **`24966`** (`ro.separate.soft=24966`), Hardware Revision **`XK927`** (`ro.product.hardware=XK927`), Brand `OPPO` (`ro.product.brand=OPPO`, `ro.oppo.market.name=OPPO Watch`, `ro.product.display_name=OPPO Watch X2`). Confirmed via `system_extracted/system/build_24966.prop`.

---

## 🔬 Hardware Components Identified

Through detailed analysis of the decompiled Device Tree Sources (`device_tree/`) and extracted dynamic kernel modules (`vendor_dlkm`), the following hardware components have been mapped:

* **Touchscreen (Dual-Sourced):**
  * Primary: **FocalTech FTS** (`focaltech_fts.ko`, compatible `focaltech,fts` on I2C address `0x38`)
  * Alternate: **Zinitix BT541** (`zinitix.ko`, compatible `zinitix,bt541_ts_device` on I2C address `0x20`)
  * Both share pin multiplexing: IRQ GPIO TLMM 13 (`0x0d`), Reset GPIO TLMM 12 (`0x0c`), resolution 466x466.
* **Display & Graphics:**
  * **Qualcomm MSM DRM** (`msm_drm.ko`) & Adreno GPU driver (`msm_kgsl.ko`)
  * Panels: **Chipone ICNA3311** 1.43" AMOLED (466x466) & **FocalTech FT2390** 1.502" AMOLED via MIPI DSI Command Mode.
* **Power Management & Biometric Subsystems:**
  * **Qualcomm PM5100 SPMI** (`pmw5100-spmi_dlkm.ko`, compatible `qcom,pm5100-spmi`): Qualcomm PMIC power management and VADC interface (*corrected from earlier PixArt misidentification*). Optical PPG and biometric acquisition is driven autonomously by the BES2610 RTOS co-processor.
* **Rotary Crown (Encoder):**
  * Driven by `oplus_crown.ko` with dual-sourced optical motion tracking sensors:
    * **Mixosense MOT6010** (`mixosense,mot6010` on I2C address `0x74`, default active)
    * **PixArt PAT9125** (`pixart,pat9125` on I2C address `0x75`)
    * IRQ GPIO TLMM 56 (`0x38`).
* **Battery & Power Management:**
  * **Qualcomm Battery Gauge (QBG):** `qti-qbg-main.ko` (`qcom,qbg`)
  * **Charger:** Qualcomm SMB Lite `qpnp-smblite-main.ko` (`qcom,qpnp-pm5100-smblite`)
  * **PMIC:** Qualcomm PM5100 over SPMI with multi-channel VADC thermistors.
* **Sensor Hub & Motion:**
  * **OPlus Sensor Hub:** `oplus_snshub.ko` (`oplus,sensor-hub`)
  * **Qualcomm Sensors:** `qti_qmi_sensor.ko` (`qcom,qmi-sensors`) communicating with Qualcomm SLPI / ADSP.

---

## 📦 Summary of Included Resources

This repository includes decompiled sources, reconstructed symbols, extracted kernel modules, and analysis tools:

### 1. Decompiled Device Tree Sources (`.dts`)
Located in [`extracted_images/device_tree/`](extracted_images/device_tree/):
* **`monaco_base_soc.dts`** (10,241 lines, 281.8 KB): Full base platform device tree decompiled from `vendor_boot.img` (`monaco_base_soc.dtb`), describing clocks, regulators, SPMI, pin controllers, I2C/SPI buses, and memory maps.
* **`dtbo_overlay_00.dts` & `dtbo_overlay_01.dts`** (3,391 lines each): Device tree overlay for the `Monaco Watch V4B01` hardware board revision.
* **`dtbo_overlay_02.dts` to `dtbo_overlay_05.dts`** (3,533 lines each): Device tree overlays for `Monaco Watch V5B01` board variant revisions.
* **`dtbo_overlay_06.dts` to `dtbo_overlay_09.dts`** (3,676 lines each): Updated device tree overlays for `Monaco Watch V5B01` board variant revisions.

### 2. Reconstructed Kernel Symbol ELF
Located at [`extracted_images/kernel_with_symbols.elf`](extracted_images/kernel_with_symbols.elf):
* **Format:** ELF 64-bit LSB Executable (AArch64 ARM64, not stripped).
* **Size:** ~48.34 MB.
* **Kernel Version:** `Linux version 5.15.170-android14-11-maybe-dirty (SMP PREEMPT)`.
* **Symbol Table:** **141,777 unstripped kallsyms functions and data symbols** reconstructed from the GKI `boot.img` kernel binary using `vmlinux-to-elf`, ready for immediate decompilation in IDA Pro, Ghidra, or Binary Ninja.

### 3. RTOS MCU Binaries (Bestechnic BES2610)
Located in [`mcu_firmware/OPWWE251/`](mcu_firmware/OPWWE251/):
* `OPWWE251_M55C0_2505201801.bin` (6.34 MB): Primary Cortex-M55 Core 0 RTOS firmware.
* `OPWWE251_M55C1_2505201801.bin` (5.57 MB): Secondary Cortex-M55 Core 1 RTOS firmware.
* `OPWWE251_SSHUB_2505201801.bin` (980.1 KB): Sensor Subsystem Hub (SSHUB) firmware.
* `bootloader.bin` (254.1 KB) & `programmer.bin` (68.9 KB): Flashing and bootstrap binaries for the MCU.
* `config.txt` & `symbols.txt`: Firmware configuration descriptors.

### 4. Technical Analysis Reports & Indexes
Located in [`reports/`](reports/):
* **[`reports/hardware_architecture.md`](reports/hardware_architecture.md):** Deep architectural report on the 4-processor design (Snapdragon W5+, BES2610, SSHUB, Slate).
* **[`reports/rtos_analysis.md`](reports/rtos_analysis.md):** Comprehensive analysis of Bestechnic BES2610 RTOS firmware, health algorithms, bootloader, and 64 MCU commands.
* **[`reports/engineer_mode/`](reports/engineer_mode/):** Complete documentation of Engineer Mode (`HeyEngineerModeHuaQin`), 78 secret codes, HAL APIs, and write-protect flows.
* **[`reports/edl_confirmation.md`](reports/edl_confirmation.md):** Empirical verification of software EDL access, USB VID:PID enumeration, and auto-timeout.
* **[`reports/bootloader_analysis.md`](reports/bootloader_analysis.md):** In-depth analysis of Qualcomm bootloader binaries, XBL forced EDL conditions, TLMM configurations, and unbricking implications.
* **[`reports/edl_recovery_notes.md`](reports/edl_recovery_notes.md):** Research notes on non-destructive software EDL entry vectors (VBUS low, failed boot counter) vs hardware test points.
* **[`reports/vendor_dlkm_modules.csv`](reports/vendor_dlkm_modules.csv):** Detailed CSV index of all 137 vendor kernel modules with file sizes, symbol counts, and driver descriptions.
* **[`reports/dts_hardware_map.md`](reports/dts_hardware_map.md):** Detailed peripheral mapping (touch, display, crown, PMIC, BES2610 interconnect).
* **[`reports/kernel_driver_check.txt`](reports/kernel_driver_check.txt):** Audit report verifying GKI core symbols vs offloaded out-of-tree dynamic drivers.
* **[`firmware_report.txt`](firmware_report.txt):** Full index of 50 low-level Qualcomm firmware binaries (`.elf`, `.bin`, `.mbn`) and HAL services.
* **[`decompilation_report.txt`](decompilation_report.txt):** Details of the kernel symbol extraction and DTB/DTBO decompilation.
* **[`verification_report.txt`](verification_report.txt):** Verification and block counts of the unpacked OTA partitions.

---

## 🔐 Bootloader & EDL Analysis

The `firmware-update/` directory contains all Qualcomm bootloader images for OPWWE251.

### Bootloader Files

| File | Size | Format | Description |
|---|---|---|---|
| `xbl.elf` | 2.8 MB | ELF | eXtended Boot Loader - contains forced EDL logic |
| `abl.elf` | 263 KB | UEFI FV | Application Boot Loader (fastboot) |
| `xbl_config.elf` | 24 KB | ELF | XBL configuration |
| `devcfg_msm_ddr.mbn` | 38 KB | ELF | Device Config (TLMM/GPIO) |
| `qupv3fw.elf` | 58 KB | ELF | QUP v3 firmware |
| `rpm.mbn` | 244 KB | MBN | Resource Power Manager |
| `hyp.mbn` | 354 KB | MBN | Hypervisor |
| `tz.mbn` | 2.9 MB | MBN | TrustZone |
| `keymint.mbn` | 326 KB | MBN | Key Management |
| `imagefv.elf` | 16 KB | UEFI FV | Image Firmware Verification |
| `uefi_sec.mbn` | 118 KB | MBN | UEFI Security verification module |
| `apdp.mbn` | 12 KB | MBN | Application Primary Debug Policy |
| `storsec.mbn` | 16 KB | MBN | Storage Security engine |
| `multi_image.mbn` | 12 KB | MBN | Multi-image bootloader descriptor |
| `NON-HLOS.bin` | 33 MB | - | Modem firmware |
| `dspso.bin` | 64 MB | - | DSP firmware |
| `dtbo.img` | 10 MB | DTBO | Device Tree Overlays |
| `vbmeta.img` | 12 KB | VBMETA | Verified Boot Metadata |
| `vbmeta_system.img` | 4 KB | VBMETA | System partition AVB 2.0 metadata |

### Forced EDL Logic (from `xbl.elf`)

XBL contains a built-in failsafe that automatically enters EDL when one of these conditions is met during boot:
- `fedl, pmi_not_detected` - PMIC not detected
- `fedl, vbus_det_err` - USB VBUS detection error
- `fedl, vbus_low` - USB VBUS voltage too low
- `fedl, chgr_type_det_err` - Charger type detection error
- `fedl, chgr_det_timeout` - Charger detection timeout
- `EDL: sbl1_dload_entry: dload_entry_count > 1` - Failed boot counter threshold

### TLMM GPIO Configuration (from `devcfg_msm_ddr.mbn`)

- `tlmm_gpio_test_pin` - test pin (numeric value in binary section)
- `tlmm_total_gpio`, `tlmm_base`, `tlmm_offset`
- `/tlmm/configs`

### EDL Access Strategies (NO case opening)

1. **Forced EDL via `vbus_low`** - software-based, safest
2. **Failed boot counter** - requires power cycling during boot
3. **TLMM test pin short** - hardware-based, DESTROYS WATER RESISTANCE

### ⚠️ WARNING: Water Resistance

OnePlus Watch 3 is rated **5ATM (50 meters water resistance)**. Opening the case to access physical PCB test points permanently destroys the water-resistant adhesive seal. Before flashing any boot-critical partition (`boot`, `init_boot`, `vendor_boot`, `dtbo`, `vbmeta`, `recovery`), be aware that there is currently no confirmed software-only method to recover from a brick.

---

## EDL Access (Confirmed)

Software-only EDL entry has been empirically confirmed on a working device.

| Aspect | Value |
|--------|-------|
| Command | `fastboot oem edl` |
| VID:PID | `05c6:9008` (Qualcomm Gobi QDL) |
| Auto-timeout | ~10 seconds |
| Exit | Auto-reboot to system, or hold both buttons ~12s |
| Risk | Zero (no partitions modified) |

### How to enter EDL
```bash
adb reboot bootloader      # Enter fastboot (VID:PID 22d9:2024 OPPO Electronics)
fastboot oem edl           # Enter EDL (VID:PID 05c6:9008 Qualcomm Gobi QDL)
```

### Safety notes:
- Entering EDL does NOT modify any partitions
- Timeout guarantees return to system
- Manual exit: hold both buttons ~12 seconds
- Last resort: drain battery to 0

### What this means:
- EDL is reachable via software only (no test points needed)
- Sahara protocol is functional in XBL
- Device cannot get stuck in EDL (timeout guarantees exit)
- See [`reports/edl_confirmation.md`](reports/edl_confirmation.md) and [`reports/edl_recovery_notes.md`](reports/edl_recovery_notes.md)

---

## XBL Sahara Protocol Analysis

Analysis of `firmware-update/xbl.elf` revealed a functional Sahara protocol implementation and "DeviceProg lite" support.

### Confirmed strings in `xbl.elf`
- `Sahara: Hello pkt sent` (offset `0x002cd590`)
- `Sahara: Hello Response Received`
- `Sahara: Reset request received`
- `sbl1_sahara.c`
- `Entering DeviceProg lite` (offset `0x0003e510`)
- `pmic DevPrg init`
- `QUSB_BULK`, `QUSB_PORT_PRIM`
- `qusb_ldr_utils_enable_eud_dep_qb`

### Extracted candidate
[`reports/firehose_search/xbl_melf_candidate.bin`](reports/firehose_search/xbl_melf_candidate.bin) (376 832 B, ELF64 AArch64)
This is **XBLRamDump** - a Sahara protocol implementation with memory dump capability. It is **NOT** a Firehose loader and cannot be used for flashing.

### EDL failsafe conditions (from XBL strings)
- `fedl, pmi_not_detected`
- `fedl, vbus_det_err`
- `fedl, vbus_low`
- `fedl, chgr_type_det_err`
- `fedl, chgr_det_timeout`
- `EDL: sbl1_dload_entry: dload_entry_count > 1`

---

## 🎛️ MCU Firmware (BES2610)

The `mcu_firmware/OPWWE251/` directory contains firmware for the Bestechnic BES2610 coprocessor (Cortex-M55 based RTOS):

* `OPWWE251_M55C0_2505201801.bin` (6.34 MB) - Core 0 main RTOS binary
* `OPWWE251_M55C1_2505201801.bin` (5.57 MB) - Core 1 secondary RTOS binary
* `OPWWE251_SSHUB_2505201801.bin` (980.1 KB) - Sensor Subsystem Hub (SSHUB) firmware
* `bootloader.bin` (254.1 KB) - MCU bootloader binary
* `programmer.bin` (68.9 KB) - MCU flashing/programmer routine
* `config.txt` - Memory and peripheral configuration descriptors
* `symbols.txt` - Firmware symbol mapping

---

## Security Model & Limitations

This device has several restrictions that affect modding.

| Aspect | Status | Impact |
|---|---|---|
| Bootloader Unlock | SUPPORTED (`ro.oem_unlock_supported=1`) | Official unlock supported via `fastboot flashing unlock`; wipes user data, voids warranty, disables Google Wallet / Play Integrity |
| A/B slots | NONE (single-slot, A-only) | No fallback slot |
| Recovery mode | LIMITED (OTA only) | Displays "No command", no interactive menu via button combos, auto-reboots after ~1 min |
| Physical button combo | UNKNOWN | No confirmed fastboot trigger |
| Engineer mode broadcast | `exported="false"` | Cannot trigger from shell |

### 🔓 Critical Discovery: Bootloader Unlocking Supported (`ro.oem_unlock_supported=1`)

Analysis of system build properties (`build_24965.prop`) reveals that **OEM bootloader unlocking is officially supported**:
* **Property:** `ro.oem_unlock_supported=1` is explicitly set in firmware build properties.
* **Unlock Command:** The standard Android Fastboot unlock command:
  ```bash
  fastboot flashing unlock
  ```
  is implemented in the Application Boot Loader (`abl.elf` / LinuxLoader PE binary `section1.pe`), which includes handlers for `flashing unlock` and `flashing get_unlock_ability`.
* **AVB Bypass on Unlock:** When unlocked, ABL explicitly skips AVB verification:
  ```
  Device is unlocked, Skipping boot verification
  ```
  This allows booting modified `init_boot` (Magisk, KernelSU) or custom kernel images without VIP signature enforcement.
* **Consequences of Unlocking:**
  * **Complete Data Wipe:** Executing `fastboot flashing unlock` automatically triggers a cryptographic factory reset of `/data` (`userdata`).
  * **Warranty Void:** Unlocking flags the bootloader tamper state and voids manufacturer warranty.
  * **Google Wallet / Play Integrity Loss:** Permanently breaks hardware-backed Google Play Integrity / CTS verification, disabling NFC contactless payments (Google Wallet).

Implications for modders:
- **OEM Bootloader Unlock is supported** (`ro.oem_unlock_supported=1`); developers can unlock via `fastboot flashing unlock`, but this wipes userdata, voids warranty, and disables Google Wallet
- Boot-time verification of `init_boot` is enforced by Android Verified Boot (AVB 2.0 / `vbmeta`) when locked; unlocking the bootloader instructs ABL to skip boot verification
- Recovery mode exists exclusively for OTA package installation; manually entering it displays the "No command" screen, offers no interactive menu via button combinations, and auto-reboots back to the system after ~1 minute
- A signed OFP service package exists (A.94+) containing `prog_firehose_ddr.elf` for full EDL unbricking
- The Firehose loader is proprietary and private (not hosted in this repo); contact the community (XDA / [Discord](https://discord.gg/F4YK2YhFMc)) for recovery help
- EDL flashing requires signed Firehose loader + Digest + Sign (VIP validation)

> [!WARNING]
> Do NOT flash without a confirmed recovery path.

---

## Recovery / Unbrick Capability

Important note on firmware recovery:

A full official service package (OFP) exists for the OPWWE251 (A.94 and newer).
This package contains everything needed to restore the device via EDL:
- `prog_firehose_ddr.elf` - Qualcomm Firehose programmer
- `ChainedTableOfDigests_*.bin` - Digest tables for VIP verification
- `DigestsToSign_*.bin.mbn` - Signed digests for Secure Boot
- `rawprogram*.xml` / `patch*.xml` - EDL flashing configuration
- Full bootloader, MCU firmware, and system images

These files are NOT included in this repository for legal reasons (they are proprietary service packages of OPPO/OnePlus).

If your device is bricked:
- Do NOT panic - EDL mode can restore the device if you have the full OFP.
- Do NOT flash random images without the proper Firehose loader.
- Contact the community (XDA, [Discord](https://discord.gg/F4YK2YhFMc)) for help obtaining the package.

Project IDs and Hardware Revisions confirmed from firmware build properties (`build_24965.prop` & `build_24966.prop`):
- `24965` - **OnePlus Watch 3** (`OPWWE251`), Hardware Revision `XK929`
- `24966` - **OPPO Watch X2** (`OWWE251`), Hardware Revision `XK927`

---

## Engineer Mode (Service Menu)

The device ships with a full OnePlus/Oppo engineer mode (service menu).
78 secret codes have been mapped from `engineer_order_list.xml`.

Notable codes:
| Code | Action |
|------|--------|
| `*#8020#` | Enable ADB over WiFi (`WifiAdbHelper`) |
| `*#9434#` | Secrecy panel (ADB/LOG/APP state) |
| `*#3644999#` | `RebootManager` (requires decrypt first) |
| `*#649010#` | Enable Qualcomm Diag mode |
| `*#8011#` | Reset ATM mode |
| `*#8778#` | FACTORY RESET (`MasterClear`) - WARNING |
| `*#*#700#` | Flash MCU (`McuUpgradeActivity`) - WARNING |

Full engineer HAL API documented in [`reports/engineer_mode/`](reports/engineer_mode/):
- `setPartionWriteProtectState(bool)` - Write protect control
- `writeData()`, `readData()` - Raw partition access
- `setProperties()` - System property modification
- `loadSecrecyConfig()`, `saveSecrecyConfig()` - Secrecy config
- `exportAttkKeyPair()`, `verifyAttkKeyPair()` - Attestation keys

Security limitation:
`EngineerModeOrderReceiver` is marked `android:exported="false"`, so the secret codes cannot be triggered from shell without system-level privileges.

Full documentation: [`reports/engineer_mode/README.md`](reports/engineer_mode/README.md)

---

## RTOS Analysis (BES2610)

The Bestechnic BES2610 is a combo chip handling WiFi 6 (802.11ax), BT 5.x, and a full health/RTOS subsystem. The RTOS runs on two Cortex-M55 cores (`M55C0`, `M55C1`) plus a sensor hub (`SSHUB`).

Health features found in RTOS firmware:
- `heart_rate_app`, `heart_rate_notify_app` - Heart rate
- `heart_rate_atrial_fibrillation_app` - AFib detection (region-locked)
- `wrist_temperature` - Skin temperature
- `step_complete`, `act_step_completed` - Step counter
- `acc_gyro_ppg_sync` - PPG synchronized with IMU
- GPS handled by M55 (`gps_gnss_service_sensor_send_m55_msg`)

MCU protocol (64 commands):
Documented in [`reports/mcu_protocol/mcu_commands.txt`](reports/mcu_protocol/mcu_commands.txt)

RTOS bootloader:
Contains full NOR flash programmer (`FLASH CMD`, `ERASE_DATA`, `BURN_DATA`, `VERIFY_DATA`) and `upg_mode_pin` for upgrade mode entry.

See [`reports/rtos_analysis.md`](reports/rtos_analysis.md) for full protocol tables and reverse engineering details.

---

## 🩺 Health Features

Biometric tracking on the OnePlus Watch 3 is executed entirely at the RTOS level:
- **Optical PPG (Heart Rate & SpO2):** Managed by SSHUB with active IMU motion artifact cancellation (`acc_gyro_ppg_sync`).
- **Atrial Fibrillation (AFib) Detection:** Algorithmic detection present in RTOS (`heart_rate_atrial_fibrillation_app`), though geographically restricted in software (unavailable in Poland/EU consumer builds).
- **Skin / Wrist Temperature:** High-precision medical thermistor array (`wrist_temperature`) sampled continuously during sleep.
- **Pedometer & Step Counting:** Real-time cadence and step algorithms (`act_step_completed`) run 24/7 on M55C0.

Because these features run on the BES2610 MCU, installing a custom Linux kernel or AOSP ROM on the Snapdragon AP does not break biometric sensing as long as kernel modules `oplus_comm_master.ko`, `oplus_snshub.ko`, and `bes2610.ko` are retained.

---

## Hardware Architecture (4-Processor Design)

| Processor | Role | Communication |
|-----------|------|---------------|
| Snapdragon W5+ Gen 1 | Application (Wear OS, Linux 5.15.170 GKI) | Main |
| Bestechnic BES2610 | WiFi 6 + BT 5.x + RTOS (`M55C0`/`M55C1`) | SPI (`oplus_comm_master.ko`) |
| SSHUB | Sensor Hub (PPG, IMU) | IPC to M55 |
| Slate | Display / AOD | SPI (`slate_events_bridge.ko`) |

Key kernel modules:
- `oplus_comm_master.ko` - Main IPC channel to BES2610
- `oplus_comm_master_bt.ko` - BT communication
- `oplus_snshub.ko` - Sensor hub driver
- `bes2610.ko` - WiFi 6 cfg80211 driver (9,163 symbols)
- `slate_events_bridge.ko` / `_rpmsg.ko` - Slate communication
- `oplus_crown.ko` - Rotary crown (`mot6010` / `pat9125`)
- `haptic.ko` - AW86927 with haptic audio support

See [`reports/hardware_architecture.md`](reports/hardware_architecture.md) for complete bus diagrams, kernel bindings, and IPC protocols.

---

## Corrections to Earlier Documentation

| Earlier claim | Correction |
|---------------|------------|
| BES2800 | BES2610 (Bestechnic) |
| BES2610 is sensor hub only | BES2610 = WiFi 6 + BT 5.x + RTOS sensor hub |
| PM5100 = PixArt PMW5100 | PM5100 = Qualcomm PMIC (`qcom,pm5100-spmi`) |
| PPG on Linux | PPG on RTOS (BES2610) |

---

## 📦 UEFI Firmware Volumes

`abl.elf` and `imagefv.elf` are UEFI Firmware Volumes (signature `_FVH` / `FFS2`). Extracted contents are available in [`reports/uefi_extracted/`](reports/uefi_extracted/):

* **`abl.elf` (LinuxLoader):**
  * Extracted PE32 binary: `section1.pe` (593,924 bytes, PE32 image)
  * Implements the Android Fastboot protocol, boot slot switching (`set_active _a` / `_b`), display panel selection, and `WriteRecoveryMessageEdl` recovery mechanism.
* **`imagefv.elf` (Firmware UI):**
  * Extracted splash bitmaps for bootloader recovery and diagnostics:
    * `tsens_thermal_symbol.bmp` & `tsens_thermal_err_symbol.bmp` (Thermal warning indicators)
    * `battery_symbol_DebugBoot.bmp` & `battery_symbol_DebugStay.bmp` (Battery debug indicators)

---

## 🧩 Vendor Modules (`vendor_dlkm`)

The `vendor_dlkm` partition contains 137 loadable kernel modules (.ko) providing hardware-specific drivers for Android 14 GKI:

| Category | Modules | Description |
|---|---|---|
| **TOUCH** | `focaltech_fts.ko`, `zinitix.ko` | FocalTech FTS & Zinitix BT541 dual-sourced touchscreen drivers |
| **DISPLAY** | `msm_drm.ko`, `panel_event_notifier.ko` | Qualcomm DRM display controller and panel event notifications |
| **GPU** | `msm_kgsl.ko` | Qualcomm Adreno GPU kernel graphics support layer |
| **VIDEO** | `msm_video.ko` | Qualcomm hardware video encoder/decoder driver |
| **COPROCESSOR** | `bes2610.ko`, `besbev_dlkm.ko`, `besbev-slave_dlkm.ko` | Bestechnic BES2610 11ax/RTOS driver, codec & slave interface |
| **OPLUS_CUSTOM** | `oplus_crown.ko`, `oplus_comm_master.ko`, `oplus_comm_master_bt.ko`, `oplus_link_power.ko`, `oplus_shutdown_detect.ko`, `oplus_ddr_freq.ko`, `slate_events_bridge.ko` | Rotary crown input, inter-chip communication, power and event bridge |
| **SENSORS_HEALTH**| `pmw5100-spmi_dlkm.ko`, `qcom-spmi-adc5*.ko`, `qti_qmi_sensor.ko` | PixArt PMW5100 optical PPG sensor, SPMI ADC, and Qualcomm QMI sensor client |
| **SENSORS_THERMAL**| `msm-tsens-driver.ko`, `qcom_tsens.ko`, `qcom-spmi-temp-alarm.ko`, `thermal_pause.ko` | Thermal sensors, PMIC temperature alarm, and throttling controls |
| **POWER_BATTERY** | `qti-qbg-main.ko`, `qpnp-smblite-main.ko`, `qpnp-power-on.ko`, `bcl_soc.ko`, `qti-pmic-lpm.ko`, `regulator_cdev.ko` | Qualcomm Battery Gauge, SMB Lite battery charger, power keys, and low-power modes |
| **AUDIO** | `bolero_cdc_dlkm.ko`, `wsa883x_dlkm.ko`, `wcd_core_dlkm.ko`, `wcd9xxx_dlkm.ko`, `swr_dlkm.ko`, `snd_event_dlkm.ko`, `spf_core_dlkm.ko`, `slimbus.ko` | Qualcomm Bolero audio codec, WSA883x smart amp, SoundWire, and SPF core |
| **SECURITY** | `qseecom_dlkm.ko`, `smcinvoke_dlkm.ko`, `qcrypto-msm_dlkm.ko`, `qce50_dlkm.ko`, `tz_log_dlkm.ko`, `qrng_dlkm.ko` | Qualcomm TrustZone / QSEE interface, crypto engine, hardware RNG, and TZ logging |
| **WIRELESS** | `cfg80211.ko`, `bluesleep.ko`, `dummy_nfc.ko` | Linux wireless 802.11 configuration subsystem, Bluetooth sleep driver |
| **INTERCONNECT** | `glink_pkt.ko`, `gpr_dlkm.ko`, `qmi_helpers.ko`, `qrtr-smd.ko`, `pdr_interface.ko` | Qualcomm GLink packet transport, IPC router, and QMI messaging helpers |
| **I2C_SPI_UART** | `i2c-msm-geni.ko`, `spi-msm-geni.ko`, `msm_geni_serial.ko`, `msm_gpi.ko` | Qualcomm Generic Interface (GENI) high-speed serial, I2C, SPI engines |
| **STORAGE & USB** | `sps_drv.ko`, `usb_bam.ko`, `usb_f_*.ko` | Smart Peripheral Subsystem (SPS) DMA and USB gadget endpoints |
| **CLOCK_CC** | `debugcc-monaco.ko`, `gpucc-monaco.ko` | Platform clock controllers for Monaco GPU and debug subsystems |
| **INFRASTRUCTURE**| `haptic.ko`, `bam_dma.ko`, `bwmon.ko`, `core_hang_detect.ko`, `cpufreq_*.ko`, `frpc-adsprpc.ko`, `stm_core.ko` | Haptic vibration motor, bus bandwidth monitoring, FastRPC ADSP, system trace |

---

## ⚡ Vendor Early-Boot Modules (`vendor_boot`)

The `vendor_boot` ramdisk contains 212 modules required during early userspace initialization before the dynamic partitions are mounted:

| Module | Subsystem / Function |
|---|---|
| `arm_smmu.ko` | ARM System MMU (IOMMU) driver for memory virtualization |
| `oplus_snshub.ko` | OPlus Sensor Subsystem Hub interface driver |
| `bes2610.ko` | Bestechnic BES2610 early boot co-processor link |
| `qpnp-smblite-main.ko` | Early battery charger initialization |
| `qti-qbg-main.ko` | Early battery fuel gauge reading |
| `qcom_glink_rpm.ko` / `qcom_glink_smem.ko` | Qualcomm GLink IPC over shared memory and RPM communication |
| `sdhci-msm.ko` / `sdhci-msm-scaling.ko` | Qualcomm SDHCI / eMMC storage controller driver |
| `spmi-pmic-arb.ko` | System Power Management Interface (SPMI) bus arbiter |
| `sched-walt.ko` | Qualcomm Window-Assisted Load Tracking (WALT) CPU scheduler |
| `qcom_ramdump.ko` / `qcom_sysmon.ko` | Subsystem monitoring, crash detection, and RAM dump facilities |

---

## 🛠️ Included Automation & Analysis Scripts

1. **[`scripts/analyze_modules.sh`](scripts/analyze_modules.sh):**
   * Inspects all `.ko` kernel modules in a directory using `nm`, `modinfo`, `file`, and `readelf`.
   * Outputs symbol counts, metadata, and generates a structured CSV report.
2. **[`scripts/extract_dlkm.sh`](scripts/extract_dlkm.sh):**
   * Automates clean ext4 extraction of `vendor_dlkm.img` using `debugfs -R "rdump / ..."` with fallback mechanisms.
3. **[`scripts/verify_kernel.sh`](scripts/verify_kernel.sh):**
   * Performs an automated symbol and driver presence audit on `kernel_with_symbols.elf`.
4. **[`extract_ota.py`](extract_ota.py):**
   * Performs memory-efficient decompression of `*.new.dat.br` partitions to `*.img`.
5. **[`analyze_firmware.py`](analyze_firmware.py):**
   * Unpacks partitions, indexes low-level firmware binaries, and analyzes HAL services.
6. **[`decompile_kernel_dtb.py`](decompile_kernel_dtb.py):**
   * Reconstructs `kernel_with_symbols.elf` via `vmlinux-to-elf` and decompiles DTBs to `.dts`.
7. **[`sdat2img.py`](sdat2img.py):**
   * Converts Android sparse data format (`sdat`) to filesystem image.

---

## 🚀 How to Run the Pipeline

### Prerequisites
* Linux environment (Ubuntu / Debian / Arch Linux)
* Python 3.10+
* Required packages: `brotli`, `requests`, `vmlinux-to-elf`, `device-tree-compiler` (`dtc`), `7z`, `e2fsprogs` (`debugfs`), `binutils` (`nm`, `readelf`), `kmod` (`modinfo`), `uefi-firmware-parser`.

### Execution
```bash
# 1. Unpack raw OTA payload files to .img partitions
python3 extract_ota.py

# 2. Extract vendor/system dumps, analyze HAL services and extract kernel
python3 analyze_firmware.py

# 3. Rebuild ELF symbols and decompile Device Tree sources
python3 decompile_kernel_dtb.py

# 4. Extract and analyze vendor DLKM kernel modules
./scripts/extract_dlkm.sh
./scripts/analyze_modules.sh
./scripts/verify_kernel.sh
```

---

## 💬 Community & Support

Have questions, need EDL unbricking assistance, or want to collaborate on reverse-engineering the OnePlus Watch 3 / OPPO Watch X2?

[![Join Discord](https://img.shields.io/badge/Discord-Join%20Community-5865F2?style=for-the-badge&logo=discord&logoColor=white)](https://discord.gg/F4YK2YhFMc)

Join the discussion on Discord: **[https://discord.gg/F4YK2YhFMc](https://discord.gg/F4YK2YhFMc)**

---

## 📄 License & Attribution
* Device firmware and vendor binaries are intellectual property of OnePlus / OPlus / Qualcomm / Bestechnic.
* Provided strictly for educational, interoperability, and reverse-engineering research purposes under fair use.
