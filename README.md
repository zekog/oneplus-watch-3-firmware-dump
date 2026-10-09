# OnePlus Watch 3 (OPWWE251) Firmware Analysis & DTS Dump

[![Firmware Build](https://img.shields.io/badge/Build-OPWWE251__11__A.165-blue.svg)](https://github.com)
[![Platform](https://img.shields.io/badge/SoC-Qualcomm_Snapdragon_W5+_Gen_1_(Monaco)-green.svg)](https://www.qualcomm.com)
[![Co--processor](https://img.shields.io/badge/MCU-Bestechnic_BES2800_/_BES2700-orange.svg)](https://www.bestechnic.com)
[![Android](https://img.shields.io/badge/OS-Wear_OS_(Android_14_GKI)-brightgreen.svg)](https://source.android.com)

A comprehensive reverse-engineering, firmware extraction, and device-tree decompilation repository for the **OnePlus Watch 3 (OPWWE251)** smartwatch.

---

## 📋 Overview & Hardware Architecture

The OnePlus Watch 3 utilizes a dual-engine / dual-OS hybrid architecture designed for extreme battery efficiency and responsiveness:
* **Application Processor (AP):** Qualcomm Snapdragon W5+ Gen 1 (codename `monaco`, SW5100 / SDA5100) running Wear OS (Android 14) with a 64-bit Linux Generic Kernel Image (GKI v4).
* **Low-Power Co-Processor (MCU/RTOS):** Bestechnic BES2800 / BES2700 series dual-core ARM Cortex-M55 + HiFi4 DSP / Sensor Subsystem Hub (SSHUB) running an RTOS for background health tracking, always-on display, and low-power watchfaces.
* **Inter-Processor Communication (IPC):** Handled via `/vendor/bin/hw/vendor-oplus-hardware-transfer@1.0-service` implementing the HIDL interface `vendor.oplus.hardware.transfer@1.0::ITransfer`, paired with the kernel driver `/dev/mcu_upgrade`.

---

## 📦 Summary of Included Resources

This repository includes decompiled sources, reconstructed symbols, and analysis tools (excluding raw multi-gigabyte disk images):

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

### 3. RTOS MCU Binaries (Bestechnic BES2800 / BES2700)
Located in [`mcu_firmware/OPWWE251/`](mcu_firmware/OPWWE251/):
* `OPWWE251_M55C0_2505201801.bin` (6.34 MB): Primary Cortex-M55 Core 0 RTOS firmware.
* `OPWWE251_M55C1_2505201801.bin` (5.57 MB): Secondary Cortex-M55 Core 1 RTOS firmware.
* `OPWWE251_SSHUB_2505201801.bin` (980.1 KB): Sensor Subsystem Hub (SSHUB) firmware.
* `bootloader.bin` (254.1 KB) & `programmer.bin` (68.9 KB): Flashing and bootstrap binaries for the MCU.
* `config.txt` & `symbols.txt`: Firmware configuration descriptors.

### 4. Technical Analysis Reports
* **[`firmware_report.txt`](firmware_report.txt):** Full index of 50 firmware binaries (`.elf`, `.bin`, `.mbn`), HAL services in `/vendor/bin/hw/`, sensors (`/dev/std_sns`), power management, and RTOS transfer services.
* **[`decompilation_report.txt`](decompilation_report.txt):** Details of the kernel symbol extraction and DTB/DTBO decompilation.
* **[`extracted_images/verification_report.txt`](extracted_images/verification_report.txt):** Verification and block counts of the unpacked OTA partitions.

---

## 🛠️ Included Automation & Analysis Scripts

1. **[`extract_ota.py`](extract_ota.py):**
   * Verifies/installs required dependencies (`brotli`, `requests`).
   * Performs memory-efficient streaming decompression of `*.new.dat.br` OTA partitions to `*.new.dat`.
   * Invokes [`sdat2img.py`](sdat2img.py) to convert `.transfer.list` and `.new.dat` pairs into standard filesystem `.img` files.
   * Copies pre-existing images (`boot.img`, `init_boot.img`, `vendor_boot.img`) into `extracted_images/`.
   * Generates verification metrics and size reports.

2. **[`analyze_firmware.py`](analyze_firmware.py):**
   * Unpacks `vendor.img` and `system.img` using `7z`.
   * Indexes and categorizes all low-level firmware binaries (`.elf`, `.bin`, `.mbn`).
   * Analyzes HAL services in `/vendor/bin/hw/` (sensors, thermal, power, and RTOS IPC).
   * Unpacks GKI Android 14 `init_boot.img` (`ramdisk.cpio`) and `boot.img` (`kernel`) using `magiskboot`.

3. **[`decompile_kernel_dtb.py`](decompile_kernel_dtb.py):**
   * Runs `vmlinux-to-elf` on the extracted kernel Image to rebuild `kernel_with_symbols.elf`.
   * Extracts the base SoC DTB from `vendor_boot.img` via `magiskboot`.
   * Parses the Android `dtbo.img` header table (`0xD7B7AB1E`) to split individual hardware board overlays.
   * Invokes `dtc` to decompile all DTBs into human-readable `.dts` files.

---

## 🚀 How to Run the Pipeline

### Prerequisites
* Linux environment (Arch Linux / Ubuntu / Debian)
* Python 3.10+
* Required packages: `brotli`, `requests`, `vmlinux-to-elf`, `device-tree-compiler` (`dtc`), `7z`, `magiskboot`.

### Execution
```bash
# 1. Unpack raw OTA payload files to .img partitions
python3 extract_ota.py

# 2. Extract vendor/system dumps, analyze HAL services and extract kernel
python3 analyze_firmware.py

# 3. Rebuild ELF symbols and decompile Device Tree sources
python3 decompile_kernel_dtb.py
```

---

## 📄 License & Attribution
* Device firmware and vendor binaries are intellectual property of OnePlus / OPlus / Qualcomm / Bestechnic.
* Provided strictly for educational, interoperability, and reverse-engineering research purposes under fair use.
