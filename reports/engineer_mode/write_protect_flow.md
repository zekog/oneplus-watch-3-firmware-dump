# OnePlus Watch 3 (OPWWE251) - Partition Write-Protect Flow

## Overview

Disabling write protection on OnePlus devices allows persistent modifications to read-only partitions (`system`, `vendor`, `product`, `system_ext`) during factory servicing. On the OnePlus Watch 3 (OPWWE251), this flow is orchestrated between `HeyEngineerMode`, the `OplusManager` framework service, and the `vendor.oplus.hardware.engineer@1.0` HAL daemon.

---

## Architecture Flow Diagram

```mermaid
sequenceDiagram
    autonumber
    actor Tech as Technician / Service Tool
    participant RM as RebootManager
    participant SH as SecrecyHelper (k0)
    participant SS as ISecrecyService (secrecy)
    participant WPH as WriteProtectHelper (a)
    participant EHL as EngineerHidlHelper (q)
    participant HAL as vendor.oplus.hardware.engineer@1.0-service
    participant OM as OplusManager (b0)
    participant PM as PowerManager

    Tech->>RM: Trigger *#3644321# (Intent extra order)
    RM->>SH: Check secrecy state: k0.d() & !k0.b(4)
    SH->>SS: getSecrecyState(4) [SECRECY_ADB]
    
    alt Secrecy Locked
        SS-->>SH: true (locked)
        SH-->>RM: Blocked
        RM-->>Tech: Toast "decrypt first" & finish()
    else Secrecy Unlocked
        SS-->>SH: false (unlocked)
        SH-->>RM: Authorized
        RM->>WPH: a.a(true)
        WPH->>EHL: q.r(true)
        EHL->>HAL: IEngineer.setPartionWriteProtectState(true)
        HAL-->>EHL: true (write-protection disabled)
        EHL-->>WPH: true
        WPH-->>RM: true
        RM->>RM: setprop persist.vendor.meta.connecttype "usb"
        RM->>PM: sleep(200ms) -> reboot("reboot_eng")
        PM-->>Tech: Reboots into Qualcomm Engineering Test Mode
    end
```

---

## Detailed Step-by-Step Breakdown

### Phase 1: Authentication & Secrecy Check
1. The execution enters `RebootManager.onCreate()` with `order="*#3644321#"`.
2. `RebootManager` invokes `k0.d()` to verify if Secrecy is supported, and `k0.b(4)` to check the authorization status of the ADB debug channel.
3. If Bit 4 is set, access is denied immediately with `"decrypt first"`.

### Phase 2: Calling the HAL Layer
1. `com.oppo.engineermode.util.a.a(true)` is invoked.
2. Helper method `a.a` delegates to `com.oppo.engineermode.util.q.r(true)`.
3. Method `q.r` obtains the HIDL proxy handle to `vendor.oplus.hardware.engineer.V1_0.IEngineer` and calls:
   ```java
   IEngineer.setPartionWriteProtectState(true);
   ```
4. The HAL daemon (`vendor.oplus.hardware.engineer@1.0-service`) handles the request:
   - Modifies eMMC / UFS controller write-protect flags via proprietary vendor ioctl or sysfs interfaces.
   - Clears dm-verity verification flags in memory for the active session.

### Phase 3: Transition to Engineering Mode
1. `RebootManager` verifies successful execution by polling `a.b()` (`IEngineer.getPartionWriteProtectState()`).
2. If confirmed, property `persist.vendor.meta.connecttype` is set to `"usb"`.
3. `PowerManager.reboot("reboot_eng")` is called.
4. Android `init` handles the property change and signals the Qualcomm bootloader (`abl.elf`) to load the engineering environment.

---

## Write-Protect Restoration & ATM Mode Reset Flow

To restore write protection and exit After-sales Test Mode (ATM), the inverse code `*#3644999#` is executed:

```mermaid
sequenceDiagram
    autonumber
    actor Tech as Technician / Service Tool
    participant RM as RebootManager
    participant WPH as WriteProtectHelper (a)
    participant EHL as EngineerHidlHelper (q)
    participant HAL as vendor.oplus.hardware.engineer@1.0-service
    participant OM as OplusManager (b0)
    participant PM as PowerManager

    Tech->>RM: Trigger *#3644999# (Intent extra order)
    RM->>WPH: a.b() (isPartionWriteProtectDisabled)
    alt Already Protected
        WPH-->>RM: false
        RM-->>Tech: Toast "already config done" & finish()
    else Write Protect Disabled
        RM->>WPH: a.c() [Reset ATM Procedure]
        WPH->>EHL: q.r(false)
        EHL->>HAL: IEngineer.setPartionWriteProtectState(false)
        WPH->>WPH: setprop vendor.oppo.quit.atm "true"
        WPH->>WPH: setprop vendor.oppo.engineer.usb.config "adb"
        WPH->>OM: b0.a(101) [cleanItem: ATM flag]
        WPH->>OM: b0.a(1125) [cleanItem: test session]
        WPH->>OM: b0.e() [syncCacheToEmmc()]
        WPH-->>RM: true
        RM->>PM: sleep(200ms) -> reboot("reboot_eng")
        PM-->>Tech: Reboots into standard locked mode
    end
```
