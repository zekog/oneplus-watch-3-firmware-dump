# OnePlus Watch 3 (OPWWE251) Firmware Analysis & DTS Dump

[![Firmware Build](https://img.shields.io/badge/Build-OPWWE251__11__A.165-blue.svg)](https://github.com)
[![Platform](https://img.shields.io/badge/SoC-Qualcomm_Snapdragon_W5+_Gen_1_(Monaco)-green.svg)](https://www.qualcomm.com)
[![Co--processor](https://img.shields.io/badge/MCU-Bestechnic_BES2610-orange.svg)](https://www.bestechnic.com)
[![Android](https://img.shields.io/badge/OS-Wear_OS_(Android_14_GKI)-brightgreen.svg)](https://source.android.com)
[![Discord](https://img.shields.io/badge/Discord-Join%20Community-5865F2?logo=discord&logoColor=white)](https://discord.gg/F4YK2YhFMc)

A comprehensive reverse-engineering, firmware extraction, and device-tree decompilation repository for the **OnePlus Watch 3 (OPWWE251)** smartwatch.

---

## ⚡ What Works and What Doesn't

Current modding, flashing, and recovery capabilities on the OnePlus Watch 3:

### Works:
- **Fastboot flash:** Fully functional with unlocked bootloader (`fastboot flashing unlock`) from a running system or via software reboot.
- **Magisk / Root:** Confirmed viable (matches OnePlus Watch 2 / AArch64 Wear OS GKI boot image patching).
- **Custom kernel:** Standard Linux 5.15 GKI v4 with out-of-tree vendor modules (`vendor_dlkm`).
- **EDL read:** Memory dumps and partition reading via `edl r` / `printgpt`.
- **Auto-EDL failsafe:** Automatic transition to Emergency Download (9008) mode after 2 consecutive boot failures.

### Doesn't Work:
- **EDL flash:** Blocked by Qualcomm VIP (Validated Image Programming) requiring 2 real-time server-signed authorization packets from OPPO (OCSM/WCSM).
- **Fastboot on brick:** Unreachable when the OS fails to boot (no physical button combination enters fastboot).
- **CVE-2026-25262 bypass:** Sahara write-what-where vulnerability is patched in XBL, Firehose loader is encrypted, and PBL ROM is inaccessible.

---

## 📋 Overview & Hardware Architecture

The OnePlus Watch 3 utilizes a 4-processor hybrid architecture designed for extreme battery efficiency and responsiveness:

| Processor | Role | Communication |
|-----------|------|---------------|
| **Snapdragon W5+ Gen 1** (SW5100 / `monaco`) | Primary Application Processor (Wear OS, Linux 5.15 GKI) | Host |
| **Bestechnic BES2610** (`M55C0` / `M55C1`) | WiFi 6 + BT 5.x + 24/7 RTOS Health & Coprocessor Subsystem | High-Speed SPI (`oplus_comm_master.ko`) |
| **SSHUB** | Sensor Subsystem Hub (Optical PPG, IMU motion cancellation) | Internal IPC to M55 |
| **Slate** | Display Controller & Always-On Display (AOD) Engine | SPI (`slate_events_bridge.ko`) |

### Confirmed Project IDs & Hardware Revisions
* **OnePlus Watch 3 (`OPWWE251`):** Project ID **`24965`** (`ro.separate.soft=24965`), Hardware Revision **`XK929`** (`ro.product.hardware=XK929`), Brand `OnePlus` (`ro.oppo.market.name=OnePlus Watch`, `ro.product.display_name=OnePlus Watch 3`).
* **OPPO Watch X2 (`OWWE251`):** Project ID **`24966`** (`ro.separate.soft=24966`), Hardware Revision **`XK927`** (`ro.product.hardware=XK927`), Brand `OPPO` (`ro.oppo.market.name=OPPO Watch`, `ro.product.display_name=OPPO Watch X2`).

---

## 🔍 Major Reverse Engineering Discoveries

Comprehensive reverse-engineering of the bootloader, RTOS firmware, and kernel modules revealed several critical architectural mechanisms:

1. **Auto-EDL Watchdog:** The secondary bootloader (XBL) tracks boot attempts via `dload_entry_count` (`0x0c29bbb0`). If the device fails to boot twice consecutively, XBL automatically forces Qualcomm Sahara Emergency Download mode (`05c6:9008`).
2. **Hardware EDL Cable:** Shorting USB D+ to GND at power-on coupled with switching the MCU to smart mode forces EDL entry immediately (`qusb_pmi_check_edl_pin_trigger`).
3. **VBUS Low Trigger:** Dropping the USB VBUS supply voltage below ~4.25V trips the PMIC comparator (`qusb_pmi_charger_detect_forced_edl`) and directs XBL into forced EDL.
4. **BCB Fastbootd Support:** The Android Boot Loader (ABL) parses the Bootloader Control Block (`misc` partition). Writing `"boot-fastboot"` directly instructs the device to boot into userspace `fastbootd`.
5. **Secure Boot is DISABLED on BES2610 RTOS:** The Cortex-M55 coprocessor firmware does **not** enforce cryptographic signature checks (`SEC_BOOT_EN` eFuse unblown). Custom RTOS code is possible requiring only CRC32 and the `0xBE57EC1C` header magic.
6. **AFib Algorithm Unlock:** The Atrial Fibrillation detection engine exists fully formed inside RTOS firmware; restriction is enforced only at the Android userspace level and can be toggled via DCC Command 21 over `/dev/dcc_data`.
7. **Complete IPC Protocol Documented:** 9 dedicated communication channels, 77 unique MCU commands, and character device interfaces (`/dev/ccch_*`, `/dev/dcc_data`) fully decoded.
8. **Partition Write Protection is a Software Flag:** The `setPartionWriteProtectState` HAL API writes an 8-byte ASCII flag to offset `0x42d000` of `oplusreserve1` (pure software, no RPMB or PMIC registers).
9. **Custom Haptic Waveforms:** The AW86927 haptic motor driver supports uploading custom vibration waveforms via `/sys/class/leds/vibrator/ram_update`.
10. **Button Combination Audit:** Physical button combos are strictly handled by the PMIC PON block. Holding both buttons ~12s triggers a PMIC hardware power-cycle; holding a button 5s during early boot triggers Recovery (`keyPressed LP 5s, entry recovery`).

> [!TIP]
> Full reports, disassembled routines, and pseudo-code are available in the [`reports/`](reports/) directory. See [`reports/RE_ANALYSIS_INDEX.md`](reports/RE_ANALYSIS_INDEX.md) for the master index.

---

## 🔐 Bootloader, EDL & Recovery Deep-Dive

### Bootloader Files Inventory (`firmware-update/`)

| File | Size | Format | Description |
|---|---|---|---|
| `xbl.elf` | 2.8 MB | ELF | eXtended Boot Loader (SBL1) - contains Sahara & forced EDL failsafes |
| `abl.elf` | 263 KB | UEFI FV | Application Boot Loader (`section1.pe` LinuxLoader / fastboot) |
| `xbl_config.elf` | 24 KB | ELF | XBL DDR and platform configuration |
| `devcfg_msm_ddr.mbn` | 38 KB | ELF | Device Config (TLMM GPIO, clock, and auth settings) |
| `qupv3fw.elf` | 58 KB | ELF | QUP v3 serial bus engine firmware |
| `rpm.mbn` | 244 KB | MBN | Resource Power Manager firmware |
| `hyp.mbn` | 354 KB | MBN | Qualcomm Type-1 Hypervisor |
| `tz.mbn` | 2.9 MB | MBN | TrustZone / QSEE security kernel |
| `keymint.mbn` | 326 KB | MBN | Hardware Keymint / Keymaster enclave |
| `imagefv.elf` | 16 KB | UEFI FV | Image Firmware Verification & splash UI bitmaps |
| `uefi_sec.mbn` | 118 KB | MBN | UEFI Security verification module |
| `NON-HLOS.bin` | 33 MB | FAT | Baseband modem firmware image |
| `dspso.bin` | 64 MB | ELF | Hexagon DSP firmware image |
| `dtbo.img` | 10 MB | DTBO | Board variant Device Tree Overlays |
| `vbmeta.img` | 12 KB | VBMETA | Android Verified Boot (AVB 2.0) root descriptor |
| `vbmeta_system.img` | 4 KB | VBMETA | System partition AVB 2.0 metadata |

---

### EDL Entry & Failsafe Mechanisms

Software and hardware EDL access has been empirically confirmed:
* **USB VID:PID:** `05c6:9008` (Qualcomm Gobi QDL).
* **Software Trigger:** `adb reboot bootloader` followed by `fastboot oem edl`.
* **Hardware Trigger (EDL Cable):** Short D+ to GND on boot, signal MCU to switch to smart mode.
* **Auto-Timeout:** ~10 seconds before handshake; once the Sahara handshake completes, the session stays open indefinitely without timing out.
* **Exit:** Hold both buttons for ~12 seconds to force a PMIC Stage 2 hardware reboot.

---

### Complete EDL Flash Protocol & The Two Missing Packets

Full reverse-engineering of the EDL flashing stream for OPWWE251 revealed the protocol pipeline:
* **Protocol:** Qualcomm Firehose + OPPO VIP (Validated Image Programming) + Secure Boot.
* **Packet Stream:** ~4,235 packets are required for a complete Android-side restoration.
* **Reproducibility:** 4,233 of the 4,235 packets are byte-reproducible directly from the stock OFP service package.

#### The Two Missing Packets:
1. **Packet 4 (`flash-sign`):** Per-firmware authorization token generated dynamically by OPPO's online signing service. Sent after `<verify>`, immediately preceding GPT patching.
   - A.94: `445b937d961b24639d3faf8003631b328f45fc7d873875ede69dd1403bd76dbd`
   - A.108: `6d56a50fcb3f556ff85870532dfa7499af8626cff7cf2302978bf9f5b5dd8057`
2. **Packet 8 (`signed CDT`):** 1024-byte signed Cellular Device Table ("OSIG") that is firmware-independent and valid across all OPWWE251 devices.
   - SHA-256: `4672bd0f78688267e0e581520f1fcaedf960a41e634287705d776bf5b9ea7b82`

Both packets are generated at flash-time by OPPO's OCSM/WCSM backend and discarded immediately; neither is stored in any OFP or OTA archive. However, because these tokens are **device-independent**, capturing a single set of packets from an authorized flash session unlocks offline EDL unbricking for every OnePlus Watch 3.

> [!NOTE]
> See [`reports/edl_complete_analysis.md`](reports/edl_complete_analysis.md) for the full protocol analysis and replay pipeline architecture.

---

### Fastboot Accessibility on Bricked Devices

On a hard-bricked OnePlus Watch 3, Fastboot cannot be reached via hardware buttons:
* **Reboot Reason Dependency:** The ABL fastboot handler executes only if an explicit reboot-reason cookie is present in RAM or set via the `misc` BCB partition.
* **Suppressed Menu UI:** While ABL contains navigation handlers for Fastboot Menu items (`START`, `Restart bootloader`, `Recovery`, `Power off`), the menu display is hard-coded as disabled (`"Display menu is not enabled!"`).
* **EDL Limitations:** Firehose does not support rebooting directly into Fastboot mode; write operations to set reboot cookies are blocked without VIP authentication.

> [!NOTE]
> See [`reports/fastboot_analysis.md`](reports/fastboot_analysis.md) and [`reports/button_combo_findings.md`](reports/button_combo_findings.md).

---

### Secure Boot & eFuse Analysis

* **Snapdragon W5+ Gen 1 Status:** Statically undecidable (eFuses are read at runtime by TrustZone via SMC `0x82000119`).
* **Evidence Leaning Toward Unblown (~50–60% Chance of Bypass):**
  - `SEC_BOOT_EN` bit 0 = 0 (`SecurityFlag = 0xC4`).
  - `devcfg` parameters `OEM_rot_enable_transfer_APPS = 0` and `OEM_rot_pk_hash1_fuse_values = 0`.
* **Evidence for Blown:** OTA update archives include the full signing verification stack (`qcom.tz.uefisecapp`).
* **BES2610 eFuse:** Secure boot is unblown on the BES2610 coprocessor; however, this is an independent chip and does not affect the Snapdragon application processor.

> [!NOTE]
> See [`reports/secure_boot_efuse_analysis.md`](reports/secure_boot_efuse_analysis.md).

---

### CVE-2026-25262 Vulnerability Analysis: Dead End

Analysis of the reported Qualcomm Sahara write-what-where vulnerability confirmed that it **does not apply** to the OPWWE251:
* **Encrypted Firehose:** `prog_firehose_ddr.elf` has an entropy of 7.93 bits/byte (no ELF header magic, no plain text strings).
* **Patched XBL:** The Sahara handler (`FUN_45e36a68`) utilizes a fixed `0x400` buffer with strict packet size bounds checking.
* **False Positive Check:** The `[x+0x38] -> cmp #5` instruction sequence matches the BGCOM SPI bridge for the BES2610 coprocessor, not authentication logic.
* **PBL Inaccessibility:** Primary Boot Loader code resides in on-chip masked ROM and cannot be inspected statically.

> [!NOTE]
> See [`reports/cve_2026_25262_analysis.md`](reports/cve_2026_25262_analysis.md).

---

### OplusFlashTool Protocol Analysis

Reverse engineering of the factory service tool (`OplusFlashTool`) documented the remote authentication flow:
* **Server Endpoints:** OCSM (`api.myoas.com/asymes/service/secLoginExt.json`), WCSM (`service-{sg,eu,in-wcsm}.myoppo.com`), and CRMNA (`crmna.oneplus.com`).
* **Cryptographic Keys:** `auth.pub` contains 57 platform RSA-2048 keys (no entry for Monaco / W5+); `nv_ecdsa.pub` contains ECDSA P-384.
* **Binary Hardening:** `FTLibBase.dll` is protected with VMProtect (`.vmp0`/`.vmp1`, entropy 7.97).
* **Signing Flow:** Packet 4 (`execGetSignData`) and Packet 8 (`execWriteCdtData`) are calculated server-side after engineer credentials are authenticated.

> [!NOTE]
> See [`reports/oplus_flashtool_analysis.md`](reports/oplus_flashtool_analysis.md).

---

## 🔓 Security Model & Bootloader Unlocking

### Official Bootloader Unlock Supported (`ro.oem_unlock_supported=1`)

Analysis of system build properties (`build_24965.prop`) confirms that OEM unlocking is officially supported:
* **Property:** `ro.oem_unlock_supported=1`.
* **Fastboot Command:**
  ```bash
  fastboot flashing unlock
  ```
* **AVB Bypass on Unlock:** When the device is unlocked, ABL explicitly bypasses Android Verified Boot (AVB 2.0) verification:
  ```text
  Device is unlocked, Skipping boot verification
  ```
  This allows booting modified `init_boot` images (Magisk, KernelSU) and custom GKI kernels.
* **Consequences of Unlocking:**
  - **Data Wipe:** Automatically triggers a cryptographic factory reset of `/data`.
  - **Google Wallet / Play Integrity Loss:** Permanently breaks hardware-backed Play Integrity, disabling NFC Google Wallet payments.
  - **Warranty Void:** Flags the tamper state in bootloader parameters.

---

## 🎛️ MCU Firmware, RTOS & Health Subsystems (BES2610)

The Bestechnic BES2610 coprocessor runs an RTOS across dual Cortex-M55 cores and manages all low-power tasks:

### RTOS Firmware Files (`mcu_firmware/OPWWE251/`)
* `OPWWE251_M55C0_2505201801.bin` (6.34 MB) - Core 0 main RTOS binary.
* `OPWWE251_M55C1_2505201801.bin` (5.57 MB) - Core 1 secondary RTOS binary.
* `OPWWE251_SSHUB_2505201801.bin` (980.1 KB) - Sensor Subsystem Hub firmware.
* `bootloader.bin` (254.1 KB) & `programmer.bin` (68.9 KB) - MCU flashing and bootstrap code.

### Biometrics & AFib Unlock
Biometric sensing runs autonomously on the BES2610:
* **Supported Algorithms:** Heart rate, continuous SpO2, sleep tracking, OSA (Sleep Apnea), wrist temperature, pedometer, and AFib (Atrial Fibrillation).
* **AFib Enablement:** The detection engine is dormant in EU/Poland builds due to software licensing. It can be activated by writing a 16-byte packet to `/dev/dcc_data` (DCC Module `0x3F`, Command ID `21` `APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW`):
  ```hex
  01 00 08 00 3F 00 01 00 15 00 04 00 01 00 00 00
  ```

### Inter-Processor Communication (IPC) Protocol
* **Physical Layer:** High-speed SPI interconnect managed by `oplus_comm_master.ko`.
* **Channels (9 Total):** `dcc_data` (`0x01`), `mcu_factory` (`0x02`), `gps_data` (`0x03`), `std_sns` (`0x04`), `dcc_datah` (`0x07`), `whs` (`0x0b`), `haptic` (`0x0d`), `audiok` (`0x0e`), `audioh` (`0x10`).
* **Frame Format:** CRC16 (2B) + Sequence (2B) + Type (1B) + Count (1B) + Length (2B) + Payload.
* **Commands:** 77 unique `MCU_*` commands documented in [`reports/ipc_protocol/bes2610_findings.md`](reports/ipc_protocol/bes2610_findings.md).

---

## 🔬 Hardware Components & Peripheral Mapping

* **Touchscreen (Dual-Sourced):**
  * FocalTech FTS (`focaltech_fts.ko`, I2C `0x38`) & Zinitix BT541 (`zinitix.ko`, I2C `0x20`). Shared IRQ GPIO TLMM 13, Reset GPIO TLMM 12.
* **Display & Graphics:**
  * Chipone ICNA3311 (466x466) & FocalTech FT2390 AMOLED via MIPI DSI Command Mode (`msm_drm.ko`).
* **Rotary Crown (Encoder):**
  * Mixosense MOT6010 (`0x74`) & PixArt PAT9125 (`0x75`) on IRQ GPIO TLMM 56 (`oplus_crown.ko`).
* **Haptic Motor:**
  * Awinic AW86927 driver (`haptic.ko`) with 31 built-in waveforms and RTP real-time audio-to-haptics streaming.
* **Power Management:**
  * Qualcomm PM5100 PMIC over SPMI, Battery Gauge (`qti-qbg-main.ko`), and SMB Lite Charger (`qpnp-smblite-main.ko`).

---

## 🧩 Kernel & Dynamic Vendor Modules

* **Reconstructed Kernel Symbols:** [`extracted_images/kernel_with_symbols.elf`](extracted_images/kernel_with_symbols.elf) contains **141,777 unstripped symbols** reconstructed from the GKI Linux 5.15.170 kernel.
* **Dynamic Modules (`vendor_dlkm`):** 137 dynamic `.ko` modules covering touch, display, wireless (WiFi 6 `bes2610.ko`), audio, and security.
* **Early-Boot Modules (`vendor_boot`):** 212 ramdisk drivers including `arm_smmu.ko`, `oplus_snshub.ko`, and `qpnp-smblite-main.ko`.

---

## 🛠️ Included Automation & Analysis Scripts

1. **[`scripts/analyze_modules.sh`](scripts/analyze_modules.sh):** Audits and indexes all vendor `.ko` modules into CSV.
2. **[`scripts/extract_dlkm.sh`](scripts/extract_dlkm.sh):** Automates clean ext4 extraction of `vendor_dlkm.img` via `debugfs`.
3. **[`scripts/verify_kernel.sh`](scripts/verify_kernel.sh):** Verifies symbols and driver presence in `kernel_with_symbols.elf`.
4. **[`extract_ota.py`](extract_ota.py):** Unpacks and decompresses `*.new.dat.br` partitions to `.img`.
5. **[`analyze_firmware.py`](analyze_firmware.py):** Indexes low-level firmware binaries and dumps HAL services.
6. **[`decompile_kernel_dtb.py`](decompile_kernel_dtb.py):** Reconstructs kernel symbols and decompiles DTBs to `.dts`.
7. **[`sdat2img.py`](sdat2img.py):** Converts Android sparse image formats to raw filesystem images.

---

## 💬 Community & Support

Have questions, need unbricking assistance, or want to collaborate on OnePlus Watch 3 / OPPO Watch X2 reverse engineering?

[![Join Discord](https://img.shields.io/badge/Discord-Join%20Community-5865F2?style=for-the-badge&logo=discord&logoColor=white)](https://discord.gg/F4YK2YhFMc)

Join the discussion on Discord: **[https://discord.gg/F4YK2YhFMc](https://discord.gg/F4YK2YhFMc)**

---

## 📄 License & Attribution

* Device firmware, vendor binaries, and proprietary descriptors are intellectual property of OnePlus, OPlus, Qualcomm, and Bestechnic.
* Documentation, scripts, and reverse-engineering findings are provided strictly for educational, interoperability, and research purposes under fair use.
