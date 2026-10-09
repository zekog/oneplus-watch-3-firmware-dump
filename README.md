# OnePlus Watch 3 (OPWWE251) Firmware Analysis & DTS Dump

[![Firmware Build](https://img.shields.io/badge/Build-OPWWE251__11__A.165-blue.svg)](https://github.com)
[![Platform](https://img.shields.io/badge/SoC-Qualcomm_Snapdragon_W5+_Gen_1_(Monaco)-green.svg)](https://www.qualcomm.com)
[![Co--processor](https://img.shields.io/badge/MCU-Bestechnic_BES2610-orange.svg)](https://www.bestechnic.com)
[![Android](https://img.shields.io/badge/OS-Wear_OS_(Android_14_GKI)-brightgreen.svg)](https://source.android.com)

A comprehensive reverse-engineering, firmware extraction, and device-tree decompilation repository for the **OnePlus Watch 3 (OPWWE251)** smartwatch.

---

## 📋 Overview & Hardware Architecture

The OnePlus Watch 3 utilizes a dual-engine / dual-OS hybrid architecture designed for extreme battery efficiency and responsiveness:
* **Application Processor (AP):** Qualcomm Snapdragon W5+ Gen 1 (codename `monaco`, SW5100 / SDA5100) running Wear OS (Android 14) with a 64-bit Linux Generic Kernel Image (GKI v4, Linux 5.15.170).
* **Low-Power Co-Processor (MCU/RTOS):** **Bestechnic BES2610** (Dual-core ARM Cortex-M55 + low-power subsystem; *corrected from earlier misidentification as BES2800*) running an RTOS for background health tracking, always-on display, and low-power watchfaces. The kernel driver is `bes2610.ko` and DTS node is `bes2610,master_spi`.
* **Inter-Processor Communication (IPC):** Handled via `/vendor/bin/hw/vendor-oplus-hardware-transfer@1.0-service` implementing the HIDL interface `vendor.oplus.hardware.transfer@1.0::ITransfer`, paired with `/dev/mcu_upgrade` and high-speed SPI interconnect.

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
* **Health & PPG Sensor:**
  * **PixArt PMW5100 / PM5100 SPMI** (`pmw5100-spmi_dlkm.ko`, compatible `qcom,pm5100-spmi`), optical PPG front-end for heart rate, SpO2, and biometric measurements.
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
* **[`reports/vendor_dlkm_modules.csv`](reports/vendor_dlkm_modules.csv):** Detailed CSV index of all 137 vendor kernel modules with file sizes, symbol counts, and driver descriptions.
* **[`reports/dts_hardware_map.md`](reports/dts_hardware_map.md):** Detailed peripheral mapping (touch, display, crown, PMIC, BES2610 interconnect).
* **[`reports/kernel_driver_check.txt`](reports/kernel_driver_check.txt):** Audit report verifying GKI core symbols vs offloaded out-of-tree dynamic drivers.
* **[`reports/xda_post.md`](reports/xda_post.md):** Complete developer release post formatted for XDA Developers.
* **[`firmware_report.txt`](firmware_report.txt):** Full index of 50 low-level Qualcomm firmware binaries (`.elf`, `.bin`, `.mbn`) and HAL services.
* **[`decompilation_report.txt`](decompilation_report.txt):** Details of the kernel symbol extraction and DTB/DTBO decompilation.
* **[`verification_report.txt`](verification_report.txt):** Verification and block counts of the unpacked OTA partitions.

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
* Required packages: `brotli`, `requests`, `vmlinux-to-elf`, `device-tree-compiler` (`dtc`), `7z`, `e2fsprogs` (`debugfs`), `binutils` (`nm`, `readelf`), `kmod` (`modinfo`).

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

## 📄 License & Attribution
* Device firmware and vendor binaries are intellectual property of OnePlus / OPlus / Qualcomm / Bestechnic.
* Provided strictly for educational, interoperability, and reverse-engineering research purposes under fair use.
