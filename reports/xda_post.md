# [DEV][DUMP] OnePlus Watch 3 (OPWWE251) – Full OTA Dump: Kernel ELF, DTS, RTOS Binaries, Vendor DLKM Modules

Hey everyone on XDA,

We've performed an in-depth reverse engineering and technical dump of the **OnePlus Watch 3 (model OPWWE251)** firmware (OTA build `OPWWE251_11_A.165`). 

This release provides kernel hackers, custom ROM developers, and smartwatch tinkerers with decompiled device tree sources, a reconstructed symbol ELF for the Wear OS GKI Linux kernel, extracted RTOS co-processor binaries, and the complete set of dynamic vendor kernel modules (`vendor_dlkm`).

---

### 🔍 Platform & Hardware Overview

* **Primary Application Processor (AP):** Qualcomm Snapdragon W5+ Gen 1 (`monaco`, SW5100 / SDA5100)
* **Operating System:** Wear OS (Android 14) with Generic Kernel Image (GKI Linux 5.15.170)
* **Low-Power Co-Processor (MCU/RTOS):** **Bestechnic BES2610** (Dual-core ARM Cortex-M55)
  * *Correction note:* Earlier analysis mislabeled this co-processor as BES2800. The kernel driver is explicitly named `bes2610.ko` and the DTS compatible string is `bes2610,master_spi`.
* **Rotary Crown (Encoder):** Dual-sourced optical motion sensors driven by `oplus_crown.ko` (Mixosense MOT6010 / PixArt PAT9125).
* **Touchscreen:** Dual-sourced controllers: FocalTech FTS (`focaltech_fts.ko`, I2C `0x38`) and Zinitix BT541 (`zinitix.ko`, I2C `0x20`).
* **Display Panels:** Chipone ICNA3311 1.43" AMOLED (466x466) and FocalTech FT2390 1.502" AMOLED via MIPI DSI (`msm_drm.ko`).
* **Health PPG / Heart Rate:** PixArt PMW5100 / PM5100 SPMI front-end (`pmw5100-spmi_dlkm.ko`).
* **Battery & Charging:** Qualcomm QBG (`qti-qbg-main.ko`) + PM5100 SMB Lite charger (`qpnp-smblite-main.ko`).

---

### 📦 What is Included in this Dump

#### 1. Reconstructed Kernel Symbols (`kernel_with_symbols.elf`)
* **Format:** ELF 64-bit ARM64 executable, unstripped.
* **Size:** ~48.34 MB.
* **Symbol Table:** **141,777 unstripped symbols** recovered from the GKI kernel image (`boot.img`) using `vmlinux-to-elf`. Ready for Ghidra, IDA Pro, and Binary Ninja.

#### 2. Decompiled Device Tree Sources (`device_tree/`)
* **`monaco_base_soc.dts`** (10,241 lines): Base platform SoC device tree detailing all Qualcomm SW5100 buses, SPMI channels, regulators, and clocks.
* **`dtbo_overlay_00.dts` to `dtbo_overlay_09.dts`**: 10 board overlay revisions for the `Monaco Watch` hardware revisions (V4B01 and V5B01).

#### 3. RTOS MCU Binaries (`mcu_firmware/OPWWE251/`)
* `OPWWE251_M55C0_2505201801.bin` (6.34 MB): Primary Cortex-M55 RTOS image.
* `OPWWE251_M55C1_2505201801.bin` (5.57 MB): Secondary Cortex-M55 RTOS image.
* `OPWWE251_SSHUB_2505201801.bin` (980 KB): Sensor Subsystem Hub (SSHUB) firmware.
* `bootloader.bin` & `programmer.bin`: MCU bootstrap and flashing routines.

#### 4. Vendor Kernel Modules (`vendor_dlkm` - 137 Modules)
All kernel drivers are dynamic GKI modules extracted directly from `vendor_dlkm.img`:
* **Touch:** `focaltech_fts.ko`, `zinitix.ko`
* **Display & Graphics:** `msm_drm.ko`, `panel_event_notifier.ko`, `msm_kgsl.ko` (Adreno GPU)
* **Co-processor Bridge:** `bes2610.ko`, `besbev_dlkm.ko`, `besbev-slave_dlkm.ko`
* **Rotary Crown & OPlus Features:** `oplus_crown.ko`, `oplus_comm_master.ko`, `oplus_comm_master_bt.ko`, `oplus_link_power.ko`, `slate_events_bridge.ko`
* **Sensors & Health:** `pmw5100-spmi_dlkm.ko`, `qcom-spmi-adc5*.ko`, `qti_qmi_sensor.ko`
* **Power & Battery:** `qti-qbg-main.ko`, `qpnp-smblite-main.ko`, `qpnp-power-on.ko`, `bcl_soc.ko`
* **Audio:** `bolero_cdc_dlkm.ko`, `wsa883x_dlkm.ko`, `wcd_core_dlkm.ko`, `swr_dlkm.ko`, `snd_event_dlkm.ko`, `spf_core_dlkm.ko`
* **Connectivity & Wireless:** `cfg80211.ko`, `bluesleep.ko`, `dummy_nfc.ko`
* **Security:** `qseecom_dlkm.ko`, `smcinvoke_dlkm.ko`, `qcrypto-msm_dlkm.ko`, `tz_log_dlkm.ko`, `qrng_dlkm.ko`

#### 5. Early Boot Modules (`vendor_boot` Ramdisk - 212 Modules)
* Essential storage, interconnect, and bus drivers (`arm_smmu.ko`, `oplus_snshub.ko`, `qcom_glink_*.ko`, `sdhci-msm.ko`, `spmi-pmic-arb.ko`).

---

### 📂 GitHub Repository & Reports

The source repository with all DTS files, reconstructed ELF, CSV module indexes, and extraction scripts is hosted at:
🔗 **GitHub:** [https://github.com/zekog/oneplus-watch-3-firmware-dump](https://github.com/zekog/oneplus-watch-3-firmware-dump)

**Generated Reports Available in Repo:**
* `reports/vendor_dlkm_modules.csv`: Full list of all 137 modules with sizes, symbol counts, and driver descriptions.
* `reports/dts_hardware_map.md`: Complete pinout, compatible strings, and peripheral map.
* `reports/kernel_driver_check.txt`: Audit of GKI kernel symbols vs out-of-tree dynamic drivers.

Happy hacking!
