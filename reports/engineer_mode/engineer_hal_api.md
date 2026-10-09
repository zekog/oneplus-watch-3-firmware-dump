# OnePlus Watch 3 (OPWWE251) - Engineer HAL API Documentation

## Overview

The Engineer HAL provides a hardware abstraction interface for low-level diagnostics, hardware calibration, raw partition manipulation, security attestation, and RF subsystem testing on OnePlus/OPPO devices running Android/Wear OS.

- **Interface Name:** `vendor.oplus.hardware.engineer@1.0::IEngineer`
- **Native Implementation Binary:** `/vendor/bin/hw/vendor.oplus.hardware.engineer@1.0-service`
- **Client Library:** `/vendor/lib/vendor.oplus.hardware.engineer@1.0.so`
- **VINTF Manifest:** `/vendor/etc/vintf/manifest/manifest_engineer.xml`
- **Java Client Wrapper:** `com.oppo.engineermode.util.q` (decompiled in [`reports/engineer_mode/engineer_hal_impl.java`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/engineer_hal_impl.java))

The Java client communicates with the HAL via HIDL Binder IPC (`android.os.IHwBinder`) using Java reflection to invoke HIDL stubs dynamically.

---

## Complete Method Catalog

### 1. Partition Protection & Storage Operations

These methods interact directly with raw storage partitions and eMMC/UFS write protection mechanisms.

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `setPartionWriteProtectState(boolean enable)` | `boolean` | **Critical Function.** Toggles write protection on system/vendor partitions. When disabled (`false`), enables writing to protected blocks. |
| `getPartionWriteProtectState()` | `boolean` | Queries the current write-protection state (`true` = protected, `false` = write protection disabled). |
| `writeData(String partition, int offset, boolean sync, int length, byte[] data)` | `int` | Writes raw binary buffers to specified partitions at given byte offsets. |
| `readData(String partition, int offset, int length, readDataCallback cb)` | `void` | Reads raw binary blocks from specified partitions asynchronously via HIDL callback. |
| `readEngineerData(int type)` | `byte[]` | Reads proprietary factory calibration or test data records by index. |
| `saveEngineerData(int type, byte[] data, int length)` | `boolean` | Commits proprietary calibration data back to persistent engineer partitions. |
| `queryMountPointMounted(String mountPoint)` | `int` | Checks if a filesystem mount point is currently mounted. |
| `getEmmcHealthInfo()` | `byte[]` | Queries eMMC/UFS wear-out estimation, life time estimation, and bad block counts. |

---

### 2. Device Attestation & Security Credentials (ATTK & Secrecy)

Handles OnePlus/OPPO proprietary ATTK (Authentication Key) cryptographic keypairs and Secrecy subsystem policies.

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `generateAttkKeyPair(int keyType)` | `int` | Generates a new on-device cryptographic keypair for factory attestation. |
| `verifyAttkKeyPair()` | `int` | Verifies the validity and signature of the installed ATTK keypair. |
| `exportAttkKeyPair(exportAttkKeyPairCallback cb)` | `void` | Exports the public component / CSR of the ATTK keypair to the caller. |
| `loadSecrecyConfig(loadSecrecyConfigCallback cb)` | `void` | Retrieves encryption and lockdown configuration for the Secrecy subsystem. |
| `saveSecrecyConfig(String config)` | `boolean` | Saves updated Secrecy access control configuration. |
| `getDeviceId(getDeviceIdCallback cb)` | `void` | Returns hardware unique identifier (IMEI/MEID/Chip serial) via callback. |
| `getHeytapID(int type)` | `String` | Retrieves HeyTap device identification token. |
| `saveHeytapID(int type, String id)` | `boolean` | Persists HeyTap device identifier to secure NV storage. |

---

### 3. Factory Calibration & Hardware Testing

Controls on-board transducers, haptic feedback actuators, displays, and sensors.

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `getProductLineTestResult()` | `byte[]` | Reads bitmask of factory production line testing results (pass/fail per module). |
| `setProductLineTestResult(int index, int result)` | `boolean` | Sets pass/fail status for a given production line test stage. |
| `resetProductLineTestResult()` | `boolean` | Resets all production test flags to factory defaults. |
| `setVibratorCalibrateData(String type, int calVal)` | `void` | Calibrates AW86927 linear resonant actuator (LRA) haptic motor. |
| `getVibratorCalibrateResult(String type, getVibratorCalibrateResultCallback cb)` | `void` | Queries resonance frequency and calibration response of the haptic driver. |
| `getImpedance(getImpedanceCallback cb)` | `void` | Measures electrical impedance of audio speakers / coils. |
| `startVibrate(int duration, int amplitude, int frequency)` | `void` | Commands the haptic motor to vibrate at specific parameters. |
| `startAgeVibrate(int duration, int cycle)` | `void` | Starts continuous burn-in / stress vibration test for manufacturing QC. |
| `startAmbient(String mode)` | `void` | Triggers ambient display light / color sensor testing. |
| `saveDisplayCaliData(String panelType, byte[] data)` | `boolean` | Writes gamma, color balance, and brightness calibration parameters for AMOLED panels. |
| `saveCameraPersistParams(String param, byte[] data, int w, int h, boolean flag)` | `boolean` | Saves camera/sensor persist parameters (inherited interface stub). |
| `getBadBatteryConfig(int param1, int param2)` | `byte[]` | Reads battery degradation and impedance thresholds. |
| `setBatteryBatteryConfig(int param1, int param2, byte[] data)` | `boolean` | Writes battery gauge calibration and cycle counter parameters. |

---

### 4. Carrier Configuration, SIM Lock, & Radio NVRAM

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `getCarrierVersion()` | `String` | Queries software carrier/operator target branding. |
| `setCarrierVersion(String carrier)` | `boolean` | Sets operator profile. |
| `getCarrierVersionFromNvram()` | `byte[]` | Reads raw operator configuration directly from modem NVRAM. |
| `saveCarrierVersionToNvram(byte[] data)` | `boolean` | Flashes operator profile into modem NVRAM. |
| `getCalibrationStatusFromNvram()` | `byte[]` | Queries RF calibration flags from NVRAM. |
| `getRegionNetlockStatus()` | `String` | Checks whether regional network lock (carrier simlock) is engaged. |
| `setRegionNetlock(String lockState)` | `boolean` | Toggles regional network lock state. |
| `getSingleDoubleCardStatus()` | `String` | Queries single vs dual SIM / eSIM capability. |
| `setSingleDoubleCard(String status)` | `boolean` | Toggles SIM configuration. |
| `getSimOperatorSwitchStatus()` | `String` | Queries dynamic SIM operator switching status. |
| `setSimOperatorSwitch(String status)` | `boolean` | Configures dynamic SIM operator switching. |
| `getDownloadStatus()` | `String` | Queries OTA/image download staging status. |
| `getBootImgWaterMark()` | `String` | Reads security watermark embedded in boot image metadata. |
| `isEngineerItemInBlackList(int id, String name)` | `boolean` | Verifies whether a specific test procedure is blacklisted on this SKU. |

---

### 5. System Properties & Instrumentation

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `setProperties(String key, String value)` | `boolean` | Sets system properties through the privileged HAL context (bypasses standard property service restrictions). |
| `notifySyspropsChanged()` | `void` | Broadcasts property modification signal to all system processes. |
| `setHALInstrumentation()` | `void` | Toggles HIDL profiling and tracing hooks. |

---

### 6. DCI (Direct Control Interface) RF / Modem Subsystem

The Engineer HAL exposes Qualcomm DCI methods allowing raw baseband diagnostic testing, RF power stage control, and antenna calibration:

- **Initialization:** `dciInit(int mode)`, `dciDeinit(int mode)`, `dciMobileEnterMode(...)`
- **Cellular TX Override:**
  - GSM: `dciGsmSetTxOn(...)`, `dciGsmGetTxAdc(...)`
  - CDMA: `dciCdmaSetTxOn(...)`, `dciCdmaGetTxAdc(...)`
  - WCDMA: `dciWcdmaSetTxOn(...)`, `dciWcdmaGetTxAdc(...)`
  - TDSCDMA: `dciTdscdmaSetTxOn(...)`, `dciTdscdmaGetTxAdc(...)`
  - LTE: `dciLteSetTxOn(...)`, `dciLteGetTxAdc(...)`, `dciControlLteRxChains(...)`
  - 5G NR: `dciNr5gSetTxOn(...)`, `dciNr5gGetTxAdc(...)`, `dciInitEM5G()`, `dciUnInitEM5G()`, `dciGetEM5GParams(...)`
- **Hardware Diagnostics:**
  - `dciQueryAntNum()`: Queries antenna count and routing switch state.
  - `dciDisplayAllRffeRegistValue(int id)`: Dumps RF Front-End (RFFE) register values across all transceivers.
  - `dciQlinkPingTest(...)`, `dciQlinkBlerTest(...)`, `dciQlinkReasSlavedId(...)`: Tests Qualcomm QLink baseband-to-transceiver bus integrity.
  - `dciTriggerModemCrash()`: Intentionally asserts modem hardware crash line for Subsystem Restart (SSR) and RAM dump extraction.

---

## Security Context & Access Control

- **Service UID/GID:** Runs under `vendor.oplus.hardware.engineer@1.0-service` as `system` / `vendor_engineermode`.
- **SELinux Domains:** `hal_engineer_default`, `vendor_engineermode`, `engineer_system_daemon`.
- **Client Access Restriction:** Only applications with SELinux domain `engineermode_app` or system clients holding `vendor.oplus.permission.ENGINEER` can connect to `vendor.oplus.hardware.engineer@1.0::IEngineer`. Standard `shell` (UID 2000) or untrusted applications cannot obtain the binder handle directly.
