# OnePlus Watch 3 (OPWWE251) - Security Model Analysis

## Overview

The OnePlus Watch 3 (OPWWE251) implements a multi-tier defense-in-depth architecture designed to prevent unauthorized firmware modification, rooting, and service menu access. This report documents the component-level security controls uncovered during reverse engineering of `HeyEngineerModeHuaQin.apk`, framework services, and system properties.

---

## 1. Application-Level Access Controls (`android:exported="false"`)

In Android's security model, components (activities, receivers, services) that lack `android:exported="true"` can **only** be invoked by the application itself or by processes running as `android.uid.system` (`uid=1000`) and `root` (`uid=0`).

### Manifest Audit

Inspection of `AndroidManifest.xml` in `HeyEngineerModeHuaQin.apk` reveals strict confinement:

1. **`EngineerModeOrderReceiver`:**
   ```xml
   <receiver android:name="com.oppo.engineermode.EngineerModeOrderReceiver"
             android:exported="false">
       <intent-filter>
           <action android:name="android.provider.Telephony.SECRET_CODE"/>
           <data android:scheme="android_secret_code"/>
       </intent-filter>
   </receiver>
   ```
   - **Impact:** Dialing secret codes via standard Android `*#...#` telephonic intents is only routed if the dialer has identical signature or runs with system permissions. Furthermore, on Wear OS there is no default stock dialer app, so codes cannot be dialed directly by a user.
   - **Shell Execution Test:**
     ```bash
     adb shell am broadcast -a android.provider.Telephony.SECRET_CODE -d android_secret_code://3644321
     ```
     Fails with: `SecurityException: Permission Denial: not exported from uid 1000`.

2. **`RebootManager`:**
   ```xml
   <activity android:name="com.oppo.engineermode.RebootManager"
             android:exported="false"/>
   ```
   - Standard shell execution (`adb shell am start -n com.oppo.engineermode/.RebootManager`) is blocked by Android `ActivityTaskManager`.

---

## 2. The Secrecy Subsystem (`ISecrecyService`)

OnePlus/OPPO incorporates a proprietary lockdown service named `ISecrecyService` (registered as binder service `"secrecy"`).

### State Mask Architecture

The service manages bitmask flags queried via `k0.b(int bit)`:
- **Bit 1 (`0x01`):** `SECRECY_LOG` – Restricts kernel and logcat debugging extraction.
- **Bit 2 (`0x02`):** `SECRECY_APP` – Restricts launching sensitive internal testing applications.
- **Bit 4 (`0x04`):** `SECRECY_ADB` – Restricts ADB engineering privileges and partition write-protect toggling.

### Decryption Gateways

To clear Bit 4 (`ADB state`), the device requires authorization through one of two mechanisms:
1. **Challenge-Response Token (`AuthTokenDecryptionMethodActivity`):**
   - The device computes a challenge based on device IMEI, timestamp, and challenge type:
     ```bash
     dumpsys secrecy -config imei=<IMEI>.unlock_type=id.encrypt_all=false.stamp=<TIMESTAMP>
     ```
   - The technician enters an authorization token issued by OnePlus service infrastructure.
   - Native verification function `l.a()` checks the cryptographic signature using a compiled-in public key.
2. **Employee Login (`EmployeeDecryptionMethodActivity`):**
   - Authenticates against OnePlus internal cloud endpoints (`c4.a.b().c()`).
   - Requires valid company LDAP/SSO credentials.

Without valid decryption, invoking engineering commands triggers `"decrypt first"` and terminates execution.

---

## 3. Firmware & Partition Security

1. **Single-Slot Layout (A-only):**
   - `fastboot getvar all` confirms the absence of `slot-count` and `current-slot`.
   - The device does not utilize modern Android A/B seamless updates.
2. **Missing Recovery Partition:**
   - There is no independent recovery environment (`recovery.img`). Recovery operations are integrated directly into userspace factory reset workflows via `MasterClear` (`android.settings.FACTORYRESET`) and bootloader metadata.
3. **Hardware Key Combinations:**
   - No hardware button combination (digital crown + side key) has been found to enter Fastboot or EDL from a cold powered-off state. Both modes currently require initial software-based entry (`adb reboot bootloader` -> `fastboot oem edl`).
4. **Bootloader Locking:**
   - `getvar unlocked` reports `no`.
   - `abl.elf` enforces signature checks across `boot`, `init_boot`, `vendor_boot`, and `dtbo`.
5. **EDL Failsafe Watchdog:**
   - The Qualcomm XBL bootloader enforces a **~10 second hardware watchdog** while in Emergency Download mode (`05c6:9008`). If a host does not maintain an active Sahara session, the device resets itself automatically to avoid accidental bricking.

---

## 4. Potential Modification Routes

| Route | Feasibility | Current Blocker |
| :--- | :--- | :--- |
| **Direct Shell Dialing** | ❌ Blocked | `android:exported="false"` prevents `uid=2000` from launching activities/receivers. |
| **Fastboot OEM Commands** | ⚠️ Partial | `fastboot oem edl` functions. Partition flashing commands are rejected by locked bootloader. |
| **EDL Firehose Flashing** | ⏳ Blocked | EDL mode (`05c6:9008`) is accessible, but requires a signed Firehose programmer (`prog_firehose_ddr.elf` / `xbl_s_devprg_ns.melf`) for SW5100. |
| **Privilege Escalation** | 🔍 Viable | A kernel vulnerability in Linux 5.15.170 (GKI) or Wear OS 14 framework would grant `uid=0`, bypassing `exported="false"` and enabling direct IPC with `vendor.oplus.hardware.engineer@1.0::IEngineer`. |
| **Secrecy Token Emulation** | 🔬 Theoretical | Reverse engineering the cryptographic verification in `l.a()` may allow local offline token generation. |
