### Architecture Note
* **Target Architecture**: **ARM 32-bit (ARMv7-A / Thumb-2, ELF32 LSB)**, not AArch64. The Wear OS userspace on Snapdragon W5 Gen 1 (SW5100) is built as 32-bit.
* **Component Roles**:
  * [`vendor.oplus.hardware.engineer@1.0.so`](file:///home/zek/Pobrane/opw3%20firmware/extracted_images/vendor_dump/lib/vendor.oplus.hardware.engineer@1.0.so): HIDL stub/proxy library implementing `BpHwEngineer`, `BnHwEngineer`, and parcel serialization.
  * [`vendor.oplus.hardware.engineer@1.0-service`](file:///home/zek/Pobrane/opw3%20firmware/extracted_images/vendor_dump/bin/hw/vendor.oplus.hardware.engineer@1.0-service): The hardware service daemon implementing the actual partition write protection read/write logic (`Engineer::getPartionWriteProtectState` and `Engineer::setPartionWriteProtectState`).

---

### 1. Symbol Search Results

#### In `vendor.oplus.hardware.engineer@1.0.so`:
| Symbol Name | Demangled Name | Virtual Address | Size |
|---|---|---|---|
| `_ZN6vendor5oplus8hardware8engineer4V1_012BpHwEngineer27getPartionWriteProtectStateEv` | `BpHwEngineer::getPartionWriteProtectState()` | `0x000187c5` | 26 B |
| `_ZN6vendor5oplus8hardware8engineer4V1_012BpHwEngineer27setPartionWriteProtectStateEb` | `BpHwEngineer::setPartionWriteProtectState(bool)` | `0x000187df` | 34 B |
| `_ZN6vendor5oplus8hardware8engineer4V1_012BpHwEngineer33_hidl_getPartionWriteProtectStateEPN7android8hardware10IInterfaceEPNS6_7details16HidlInstrumentorE` | `BpHwEngineer::_hidl_getPartionWriteProtectState(...)` | `0x00011e6d` | 492 B |
| `_ZN6vendor5oplus8hardware8engineer4V1_012BpHwEngineer33_hidl_setPartionWriteProtectStateEPN7android8hardware10IInterfaceEPNS6_7details16HidlInstrumentorEb` | `BpHwEngineer::_hidl_setPartionWriteProtectState(...)` | `0x00012059` | 504 B |
| `_ZN6vendor5oplus8hardware8engineer4V1_012BnHwEngineer33_hidl_getPartionWriteProtectStateEPN7android4hidl4base4V1_08BnHwBaseERKNS5_8hardware6ParcelEPSC_NSt3__18functionIFvRSC_EEE` | `BnHwEngineer::_hidl_getPartionWriteProtectState(...)` | `0x0001a101` | 248 B |
| `_ZN6vendor5oplus8hardware8engineer4V1_012BnHwEngineer33_hidl_setPartionWriteProtectStateEPN7android4hidl4base4V1_08BnHwBaseERKNS5_8hardware6ParcelEPSC_NSt3__18functionIFvRSC_EEE` | `BnHwEngineer::_hidl_setPartionWriteProtectState(...)` | `0x0001a1f9` | 276 B |

#### In `vendor.oplus.hardware.engineer@1.0-service` (recovered via `.gnu_debugdata`):
| Symbol Name | Demangled Name | Virtual Address | Size |
|---|---|---|---|
| `_ZN6vendor5oplus8hardware8engineer4V1_014implementation8Engineer27getPartionWriteProtectStateEv` | `Engineer::getPartionWriteProtectState()` | `0x000105e1` | 212 B |
| `_ZN6vendor5oplus8hardware8engineer4V1_014implementation8Engineer27setPartionWriteProtectStateEb` | `Engineer::setPartionWriteProtectState(bool)` | `0x000106b5` | 196 B |
| `_ZN6vendor5oplus8hardware8engineer4V1_014implementation13readInterfaceEPKciPvi` | `readInterface(char const*, int, void*, int)` | `0x0000956d` | 156 B |
| `_ZN6vendor5oplus8hardware8engineer4V1_014implementation14writeInterfaceEPKciS6_i` | `writeInterface(char const*, int, char const*, int)` | `0x00009609` | 188 B |

---

### 2. Decompilation of Functions

#### HIDL IPC Server Stub: `BnHwEngineer::_hidl_setPartionWriteProtectState` (`0x0001a1f8`)
```c
status_t BnHwEngineer::_hidl_setPartionWriteProtectState(
    BnHwBase *_hidl_this,
    const Parcel &_hidl_data,
    Parcel *_hidl_reply,
    TransactCallback _hidl_cb)
{
    if (!_hidl_data.enforceInterface("vendor.oplus.hardware.engineer@1.0::IEngineer")) {
        return BAD_TYPE;
    }

    bool state = false;
    status_t _hidl_err = _hidl_data.readBool(&state);
    if (_hidl_err != OK) {
        return _hidl_err;
    }

    // Call implementation virtual method at vtable slot +0x40
    IEngineer *impl = reinterpret_cast<IEngineer*>(_hidl_this->getImpl());
    Return<bool> _hidl_out_status = impl->setPartionWriteProtectState(state);

    _hidl_reply->writeStatus(Status::ok());
    _hidl_reply->writeBool(_hidl_out_status.isOk() ? (bool)_hidl_out_status : false);
    return OK;
}
```

#### HIDL IPC Server Stub: `BnHwEngineer::_hidl_getPartionWriteProtectState` (`0x0001a100`)
```c
status_t BnHwEngineer::_hidl_getPartionWriteProtectState(
    BnHwBase *_hidl_this,
    const Parcel &_hidl_data,
    Parcel *_hidl_reply,
    TransactCallback _hidl_cb)
{
    if (!_hidl_data.enforceInterface("vendor.oplus.hardware.engineer@1.0::IEngineer")) {
        return BAD_TYPE;
    }

    // Call implementation virtual method at vtable slot +0x3c
    IEngineer *impl = reinterpret_cast<IEngineer*>(_hidl_this->getImpl());
    Return<bool> _hidl_out_status = impl->getPartionWriteProtectState();

    _hidl_reply->writeStatus(Status::ok());
    _hidl_reply->writeBool(_hidl_out_status.isOk() ? (bool)_hidl_out_status : false);
    return OK;
}
```

#### Service Implementation: `Engineer::setPartionWriteProtectState` (`0x000106b5`)
```c
Return<bool> Engineer::setPartionWriteProtectState(bool state) {
    char *buf = new char[9](); // 9 bytes zero-initialized

    if (state) {
        // 0x029041ce == 43008462 (exact 8-byte ASCII string "43008462")
        snprintf(buf, 9, "%d", 43008462);
    }

    const char *partition_path;
    int offset;

    if (g_partition_mode != 0) {
        if (access("/dev/block/by-name/opporeserve1", F_OK) == 0) {
            partition_path = "/dev/block/by-name/opporeserve1";
        } else {
            partition_path = "/dev/block/by-name/oplusreserve1";
        }
        // Base: 0x41a400. If secondary flag is 0: 0x41a400 + 0x12c00 = 0x42d000
        offset = (g_sub_flag == 0) ? 0x42d000 : 0x41a400;
    } else {
        partition_path = "/dev/block/bootdevice/by-name/reserve4";
        offset = 0xf00600; // 15,730,176 bytes
    }

    // Write exactly 8 bytes to the reserve partition
    int written = writeInterface(partition_path, offset, buf, 8);
    delete[] buf;

    // Returns true if written == 8, else false
    return (written == 8);
}
```

#### Service Implementation: `Engineer::getPartionWriteProtectState` (`0x000105e1`)
```c
Return<bool> Engineer::getPartionWriteProtectState() {
    char *buf = new char[9]();

    const char *partition_path;
    int offset;

    if (g_partition_mode != 0) {
        if (access("/dev/block/by-name/opporeserve1", F_OK) == 0) {
            partition_path = "/dev/block/by-name/opporeserve1";
        } else {
            partition_path = "/dev/block/by-name/oplusreserve1";
        }
        offset = (g_sub_flag == 0) ? 0x42d000 : 0x41a400;
    } else {
        partition_path = "/dev/block/bootdevice/by-name/reserve4";
        offset = 0xf00600;
    }

    int bytes_read = readInterface(partition_path, offset, buf, 8);
    __android_log_print(ANDROID_LOG_DEBUG, "ENGINEER", 
                        "getPartionWriteProtectState wpState=%s", buf);

    bool is_protected = false;
    if (bytes_read == 8) {
        int val = atoi(buf);
        delete[] buf;
        // Check: val + 0xfd6fbe32 == 0  <=>  val == 43008462 (0x029041ce)
        if (val == 43008462) {
            is_protected = true;
        }
    } else {
        delete[] buf;
    }

    return is_protected;
}
```

---

### 3. Detailed Answers for `setPartionWriteProtectState`

1. **What memory address or register does it modify?**
   * It **does not modify hardware registers or memory-mapped I/O**.
   * It writes directly to raw disk block devices (eMMC/UFS reserve partitions):
     * **Device Node**: `/dev/block/by-name/opporeserve1` (or `/dev/block/by-name/oplusreserve1`, or fallback `/dev/block/bootdevice/by-name/reserve4`).
     * **Disk Offset**: `0x42d000` (4,378,624 bytes) or `0x41a400` on `oplusreserve1`; `0xf00600` (15,730,176 bytes) on `reserve4`.
     * **Payload**:
       * When enabling write protection (`true`): writes the 8-byte magic string `"43008462"` (`0x029041ce`).
       * When disabling write protection (`false`): writes 8 zero-bytes (`\0\0\0\0\0\0\0\0`).

2. **What function calls does it make?**
   * `operator new[](unsigned int)` (`0x0001d8f0`)
   * `snprintf(char*, size_t, const char*, ...)` (`0x0000b949`)
   * `access(const char*, int)` (`0x0001d8e0`)
   * `writeInterface(const char*, int, const char*, int)` (`0x00009609`)
     * Inside `writeInterface`:
       * `__open_2(path, O_WRONLY)` (`0x0001d820`)
       * `lseek(fd, offset, SEEK_SET)` (`0x0001d830`)
       * `__write_chk(fd, buf, 8, -1)` (`0x0001d890`)
       * `fsync(fd)` (`0x0001d8a0`)
       * `close(fd)` (`0x0001d880`)
   * `operator delete[](void*)` (`0x0001d910`)

3. **Does it invoke any syscall, ioctl, or file operation?**
   * **Syscalls / File Operations**: Yes, standard POSIX filesystem operations:
     * `sys_faccessat` / `access` (checking for `/dev/block/by-name/opporeserve1`)
     * `sys_openat` / `open` (`O_WRONLY`)
     * `sys_lseek` / `_llseek`
     * `sys_write` / `write`
     * `sys_fsync` / `fsync`
     * `sys_close` / `close`
   * **Ioctl**: **None**.

4. **Does it communicate with PMIC via SPMI, RPMB, or another bus?**
   * **No**. There is no SPMI, PMIC register access, or RPMB ioctl involved. The write protection state is a software flag persisted directly in the OEM reserve block partition.

---

### 4. Detailed Answers for `getPartionWriteProtectState`

1. **What memory address or register does it read?**
   * Reads 8 bytes from the exact same reserve block partition and offset:
     * `/dev/block/by-name/oplusreserve1` (or `opporeserve1`) at offset `0x42d000` / `0x41a400`, or `reserve4` at `0xf00600`.
2. **What function calls does it make?**
   * `operator new[](unsigned int)` (`0x0001d8f0`)
   * `access(const char*, int)` (`0x0001d8e0`)
   * `readInterface(const char*, int, void*, int)` (`0x0000956d`)
     * Inside `readInterface`: `open(path, O_RDONLY)`, `lseek(fd, offset, SEEK_SET)`, `read(fd, buf, 8)`, `close(fd)`.
   * `__android_log_print(ANDROID_LOG_DEBUG, "ENGINEER", ...)` (`0x0001d870`)
   * `atoi(const char*)` (`0x0001dae0`)
   * `operator delete[](void*)` (`0x0001d910`)
3. **Validation Logic**:
   * Evaluates `atoi(buf) + 0xfd6fbe32 == 0`.
   * If the stored ASCII decimal value equals `43008462`, returns `true` (`1`); otherwise returns `false` (`0`).

---

### 5. Cross-References (Callers in the Library)

In [`vendor.oplus.hardware.engineer@1.0.so`](file:///home/zek/Pobrane/opw3%20firmware/extracted_images/vendor_dump/lib/vendor.oplus.hardware.engineer@1.0.so):

1. **`BpHwEngineer::getPartionWriteProtectState` (`0x000187c5`)**:
   * Stored in `vtable for BpHwEngineer` (slot 15).
   * Calls: `BpHwEngineer::_hidl_getPartionWriteProtectState` (`0x00011e6d`).
2. **`BpHwEngineer::setPartionWriteProtectState` (`0x000187df`)**:
   * Stored in `vtable for BpHwEngineer` (slot 16).
   * Calls: `BpHwEngineer::_hidl_setPartionWriteProtectState` (`0x00012059`).
3. **`BpHwEngineer::_hidl_getPartionWriteProtectState` (`0x00011e6d`)**:
   * Serializes `vendor.oplus.hardware.engineer@1.0::IEngineer` interface token.
   * Invokes IPC transaction **Code 3 (`0x3`)** via `remote()->transact(3, data, &reply, 0)`.
4. **`BpHwEngineer::_hidl_setPartionWriteProtectState` (`0x00012059`)**:
   * Serializes interface token and `bool` parameter.
   * Invokes IPC transaction **Code 4 (`0x4`)** via `remote()->transact(4, data, &reply, 0)`.
5. **`BnHwEngineer::_hidl_getPartionWriteProtectState` (`0x0001a101`)**:
   * Called by `BnHwEngineer::onTransact(...)` at `0x0001e830` when incoming IPC transaction code is **`3`**.
   * Dispatches virtual call `impl->getPartionWriteProtectState()` (vtable offset `+0x3c`).
6. **`BnHwEngineer::_hidl_setPartionWriteProtectState` (`0x0001a1f9`)**:
   * Called by `BnHwEngineer::onTransact(...)` at `0x0001e86a` when incoming IPC transaction code is **`4`**.
   * Dispatches virtual call `impl->setPartionWriteProtectState(state)` (vtable offset `+0x40`).