# OnePlus Watch 3 (OPWWE251) - OplusManager API Documentation

## Overview

The `android.os.OplusManager` framework service is a proprietary OnePlus/OPPO system extension embedded in the Android framework (`framework.jar` / `services.jar`). It handles low-level NVRAM variables, critical device metadata, battery/charging statistics, hardware tamper logs, and raw partition reads.

In Engineer Mode, it is invoked via reflection through `com.oppo.engineermode.util.b0` (decompiled in [`reports/engineer_mode/oplus_manager_api.java`](file:///home/zek/Pobrane/opw3%20firmware/reports/engineer_mode/oplus_manager_api.java)).

---

## Method Catalog

### 1. `readRawPartition(int partitionId, int offset)`
- **Signature:** `public static String readRawPartition(int partitionId, int offset)`
- **Return Type:** `String` (encoded partition block / hex dump)
- **Description:** Directly accesses and reads raw storage partition blocks without requiring standard Linux filesystem mounting.
- **Modding Impact:** Provides a channel to read out protected partitions (e.g., devcfg, persist, modemst1/st2, static_nvbk) from userspace if accessed by a privileged UID.

### 2. `readCriticalData(int id)`
- **Signature:** `public static int readCriticalData(int id)`
- **Return Type:** `int`
- **Description:** Reads critical integer telemetry or status values by key ID (e.g., boot counts, factory test completion status, thermal trip counters, battery health flags).

### 3. `readCriticalData(int id, int offset)`
- **Signature:** `public static String readCriticalData(int id, int offset)`
- **Return Type:** `String`
- **Description:** Reads critical string data (serial numbers, PCB barcodes, calibration checksums, cryptographic watermarks) from persistent storage offsets.

### 4. `writeCriticalData(int id, String str)`
- **Signature:** `public static int writeCriticalData(int id, String str)`
- **Return Type:** `int` (status code: 0 on success, negative on error)
- **Description:** Commits critical system parameters and hardware configuration records into secure non-volatile storage.

### 5. `cleanItem(int id)`
- **Signature:** `public static int cleanItem(int id)`
- **Return Type:** `int` (status code: 0 on success, negative on error)
- **Description:** Wipes or resets specific critical data items back to zero / uninitialized state.
- **Used in Write-Protect Reset:**
  When resetting ATM (After-sales Test Mode) in `com.oppo.engineermode.util.a.c()`, two specific critical items are purged:
  ```java
  b0.a(101);   // Clears critical item 101 (ATM mode flag / factory authorization)
  b0.a(1125);  // Clears critical item 1125 (engineering mode test session state)
  b0.e();      // Forces sync to storage
  ```

### 6. `syncCacheToEmmc()`
- **Signature:** `public static int syncCacheToEmmc()`
- **Return Type:** `int`
- **Description:** Issues a hardware barrier and cache synchronization command (`fsync`/`blkdev_issue_flush`) directly to the eMMC / UFS storage controller, guaranteeing that pending critical data writes are permanently written to flash memory before a reboot occurs.

---

## Access Restrictions

`OplusManager` methods are guarded inside `system_server` by Android system signature permissions (`android.permission.CONNECTIVITY_INTERNAL` or `oplus.permission.OPLUS_COMPONENT_SAFE`). Only system-signed privileged apps (`priv-app`) sharing the system UID (`android.uid.system`) or root can invoke these methods successfully. Standard ADB shell (`uid=2000`) cannot invoke them without elevated privileges.
