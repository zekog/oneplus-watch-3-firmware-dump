# OnePlus Watch 3 (OPWWE251) - Engineer Mode Deep Dive

## Introduction

The OnePlus Watch 3 (OPWWE251) includes a full-featured factory engineering suite packaged as `HeyEngineerModeHuaQin.apk` (located in `/system/priv-app/HeyEngineerModeHuaQin/` or `/system/app/`). This application provides access to diagnostic menus, low-level hardware calibration, RF front-end testing, firmware upgrading for the coprocessor MCU, and security authorization endpoints.

This directory documents the reverse-engineered architecture, APIs, secret order codes, and security mechanisms governing Engineer Mode.

---

## Directory Contents

| Document | Description |
| :--- | :--- |
| [`secret_codes.txt`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/secret_codes.txt) | Complete list of all 77/78 secret codes parsed from `engineer_order_list.xml` with target activities and intents. |
| [`activities.txt`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/activities.txt) | Complete catalog of all 275 activities and aliases declared in `AndroidManifest.xml`. |
| [`engineer_hal_api.md`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/engineer_hal_api.md) | Exhaustive documentation of `vendor.oplus.hardware.engineer@1.0::IEngineer` HIDL interface methods. |
| [`oplus_manager_api.md`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/oplus_manager_api.md) | Documentation of `android.os.OplusManager` reflection wrapper (`b0.java`). |
| [`reboot_manager_analysis.md`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/reboot_manager_analysis.md) | In-depth code analysis of `RebootManager.java` and Qualcomm `reboot_eng` mode transition. |
| [`security_model.md`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/security_model.md) | Security evaluation of `android:exported="false"`, Secrecy bitmasks, and modding hurdles. |
| [`write_protect_flow.md`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/write_protect_flow.md) | Visual sequence and architectural diagram of partition write-protect toggling and ATM reset. |

---

## Key Secret Order Codes

The complete XML table is defined in [`reports/engineer_mode/engineer_order_list.xml`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/engineer_order_list.xml). The most significant codes include:

| Code | Target Component | Description / Function | Risk Level |
| :--- | :--- | :--- | :--- |
| `*#8020#` | `WifiAdbHelper` | Enables wireless ADB debugging without USB connection. | Low |
| `*#9434#` | `WifiDecryptionActivity` | Secrecy authorization portal (ADB, LOG, APP decryption). | Medium |
| `*#649010#` | `DiagEnabled` | Enables Qualcomm USB DIAG diagnostic port (QPST/QXDM interface). | Medium |
| `*#800#` | `OppoLogkitMainActivity` | Full wearable system logging toolkit (kernel, radio, tcpdump). | Low |
| `*#8003#` | `DataTransfer` | Low-level data transfer testing. | Low |
| `*#8004#` | `WristTempTest` | Skin temperature sensor diagnostic and readout. | Low |
| `*#3644321#` | `RebootManager` | Toggles write-protection off and enters `reboot_eng` (requires secrecy decrypt). | High |
| `*#3644999#` | `RebootManager` | Restores write-protection, clears ATM flags, and reboots. | Medium |
| `*#7001#` | Broadcast | Triggers `START_SYNC_WATCH_FACE` health synchronization. | Low |
| `*#7002#` | `HardwareScanResultActivity`| Factory hardware component scan results. | Low |
| `*#8778#` | `MasterClear` | **⚠️ FACTORY RESET:** Instantly wipes all user data and settings. | **CRITICAL** |
| `*#*#700#` | `McuUpgradeActivity` | **⚠️ MCU FLASH:** Flashes Bestechnic BES2610 RTOS firmware images directly. | **CRITICAL** |

> [!CAUTION]
> **NEVER TEST `*#8778#` OR `*#*#700#` ON A DAILY DRIVER DEVICE.**
> `*#8778#` triggers an irreversible immediate factory data wipe.
> `*#*#700#` directly flashes the NOR flash of the Bestechnic BES2610 RTOS co-processor; interrupted flashing will brick the MCU and permanently disable heart rate, Bluetooth, and battery charging logic.

---

## Engineer HAL API Summary

`vendor.oplus.hardware.engineer@1.0::IEngineer` exposes over 60 low-level control functions via HIDL binder IPC:
- **Write-Protection:** `setPartionWriteProtectState(bool)`, `getPartionWriteProtectState()`.
- **Raw Partition Access:** `readData(...)`, `writeData(...)`, `readEngineerData(...)`, `saveEngineerData(...)`.
- **Hardware Calibration:** AW86927 haptic calibration (`setVibratorCalibrateData`, `getVibratorCalibrateResult`), AMOLED display gamma calibration (`saveDisplayCaliData`), battery health config (`getBadBatteryConfig`, `setBatteryBatteryConfig`).
- **Attestation & Secrecy:** ATTK cryptographic keypair generation (`generateAttkKeyPair`, `verifyAttkKeyPair`, `exportAttkKeyPair`), Secrecy configuration loading/saving (`loadSecrecyConfig`, `saveSecrecyConfig`).
- **Cellular DCI Diagnostics:** GSM, CDMA, WCDMA, LTE, and 5G NR RF transmitter overrides (`dci*SetTxOn`, `dci*GetTxAdc`), RF front-end register readouts (`dciDisplayAllRffeRegistValue`), and modem crash injection (`dciTriggerModemCrash`).

---

## OplusManager API Summary

Through reflection in `b0.java`, `android.os.OplusManager` provides:
- `readRawPartition(int id, int offset)`: Reads raw partition sectors bypassing normal file system restrictions.
- `cleanItem(int id)`: Invalidates NVRAM / calibration state items (used to clear ATM mode flags 101 and 1125).
- `readCriticalData` / `writeCriticalData`: Manipulates critical device parameters stored in non-volatile memory.
- `syncCacheToEmmc()`: Issues a hardware-level flush barrier to flash memory before shutdown.

---

## Secrecy Subsystem & Authentication

Before entering privileged diagnostic modes (such as write-protection disablement via `*#3644321#`), `RebootManager` checks `k0.b(4)` (`SECRECY_ADB`). If locked, it displays `"decrypt first"`.

Decryption can only be satisfied by:
1. **Challenge-Response Token:** Generated via `dumpsys secrecy -config imei=<IMEI>.unlock_type=id.encrypt_all=false.stamp=<timestamp>`, signed by OnePlus proprietary private keys, and verified by on-device native library `l.a()`.
2. **Employee Login:** Authenticated via OnePlus corporate intranet credentials through `EmployeeDecryptionMethodActivity`.

---

## The `android:exported="false"` Barrier

All sensitive components in `HeyEngineerModeHuaQin.apk` (`EngineerModeOrderReceiver`, `RebootManager`, etc.) are declared with `android:exported="false"`.

Because Wear OS 14 does not include an interactive dialer application, and Android's `ActivityTaskManager` strictly prevents untrusted processes (including ADB shell `uid=2000`) from invoking non-exported components, standard ADB users cannot directly trigger these activities or broadcast secret codes. Bypassing this barrier requires either achieving `uid=0` (root) via an exploit, obtaining system signature privileges, or flashing modified partitions via EDL.
