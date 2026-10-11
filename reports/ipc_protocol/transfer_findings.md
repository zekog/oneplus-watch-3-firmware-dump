Here is the complete analysis of [`vendor.oplus.hardware.transfer@1.0.so`](file:///home/zek/Pobrane/opw3%20firmware/extracted_images/vendor_dump/lib/vendor.oplus.hardware.transfer@1.0.so) and its corresponding HAL service backend [`vendor-oplus-hardware-transfer@1.0-service`](file:///home/zek/Pobrane/opw3%20firmware/extracted_images/vendor_dump/bin/hw/vendor-oplus-hardware-transfer@1.0-service).

---

### Architecture Note
* **Target Architecture**: **ARM 32-bit (ARMv7-A / Thumb-2, ELF32 LSB)** — not AArch64. Wear OS on the Snapdragon W5 Gen 1 (SW5100) runs a 32-bit userspace for memory footprint reasons.
* **Component Split**:
  * **HIDL Proxy/Stub Library**: `vendor.oplus.hardware.transfer@1.0.so` (defines interface stubs, parcels, and `BnHwTransfer::onTransact`).
  * **HIDL Service Daemon**: `vendor-oplus-hardware-transfer@1.0-service` (implements the actual `VendorTransfer` class logic).

---

### 1. `BnHwTransfer::onTransact` Implementation (Transaction Code 2)

In [`vendor.oplus.hardware.transfer@1.0.so`](file:///home/zek/Pobrane/opw3%20firmware/extracted_images/vendor_dump/lib/vendor.oplus.hardware.transfer@1.0.so), `BnHwTransfer::onTransact` is located at `0x0000c834` (Thumb mode):

```c
// BnHwTransfer::onTransact(uint32_t _hidl_code, const Parcel& _hidl_data, Parcel* _hidl_reply, uint32_t _hidl_flags, TransactCallback _hidl_cb)
android::status_t BnHwTransfer::onTransact(
    uint32_t _hidl_code,
    const android::hardware::Parcel &_hidl_data,
    android::hardware::Parcel *_hidl_reply,
    uint32_t _hidl_flags,
    TransactCallback _hidl_cb)
{
    switch (_hidl_code) {
        case 1: /* 0x1 */
            return _hidl_setCallback(this, _hidl_data, _hidl_reply, _hidl_cb);

        case 2: /* 0x2 -> sendToServer */
            return _hidl_sendToServer(this, _hidl_data, _hidl_reply, _hidl_cb);

        default:
            // Fall back to base HIDL interface dispatcher
            return android::hidl::base::V1_0::BnHwBase::onTransact(
                this, _hidl_code, _hidl_data, _hidl_reply, _hidl_flags, _hidl_cb
            );
    }
}
```

---

### 2. Decompilation of `_hidl_sendToServer`

Located at `0x0000c670` in `vendor.oplus.hardware.transfer@1.0.so`:

```c
// android::status_t _hidl_sendToServer(IHwInterface* _hidl_this, const Parcel& _hidl_data, Parcel* _hidl_reply, TransactCallback _hidl_cb)
android::status_t BnHwTransfer::_hidl_sendToServer(
    android::hardware::IHwInterface *_hidl_this,
    const android::hardware::Parcel &_hidl_data,
    android::hardware::Parcel *_hidl_reply,
    TransactCallback _hidl_cb)
{
    // 1. Enforce interface descriptor
    status_t _hidl_err = _hidl_data.enforceInterface("vendor.oplus.hardware.transfer@1.0::ITransfer");
    if (_hidl_err != OK) {
        return _hidl_err;
    }

    // 2. Unmarshal the hidl_string argument
    const android::hardware::hidl_string *data;
    size_t _hidl_data_parent;
    _hidl_err = _hidl_data.readBuffer(sizeof(android::hardware::hidl_string), &_hidl_data_parent, (const void**)&data);
    if (_hidl_err != OK) {
        return _hidl_err;
    }
    _hidl_err = _hidl_data.readEmbeddedFromParcel(
        const_cast<android::hardware::hidl_string*>(data),
        _hidl_data_parent,
        0
    );
    if (_hidl_err != OK) {
        return _hidl_err;
    }

    // 3. Resolve implementation and dispatch virtual method
    // vtable slot offset: +0x38 (ITransfer::sendToServer)
    ITransfer *impl = static_cast<ITransfer*>(_hidl_this->getImpl());
    bool _hidl_out_status = impl->sendToServer(*data);

    // 4. Serialize reply status and return boolean
    _hidl_reply->writeStatus(OK);
    _hidl_reply->writeBool(_hidl_out_status);

    return OK;
}
```

---

### 3. Destination, Expected Format, and Command Parsing

Tracing into the HAL daemon implementation [`vendor-oplus-hardware-transfer@1.0-service`](file:///home/zek/Pobrane/opw3%20firmware/extracted_images/vendor_dump/bin/hw/vendor-oplus-hardware-transfer@1.0-service) (`VendorTransfer` class):

#### Where does the string go?
* **Destination**: It does **NOT** write directly to `/dev/mcu_*`, SPI, or an `ioctl`.
* Instead, it writes to a **UNIX domain socket** (`AF_LOCAL`, `SOCK_STREAM`).
  * In `VendorTransfer::initSocketServer()` (`0x00002bec`), the service creates and binds a local UNIX domain socket server using `socket_local_server` (`libcutils`) and spawns `VendorTransfer::socketListener` (`0x00002cd1`).
  * When a client connects (such as an ATM / Wi-Fi / MCU routing daemon), its descriptor is stored in `this->client_fd` (`this + 0x0c`).
  * `sendToServer()` passes the string to `VendorTransfer::SendMessageToSocketClient(char const*)` (`0x00003244`), which writes to `this->client_fd`.

#### What format does it expect?
* **Format**: Standard null-terminated **ASCII / UTF-8 string**.
  * The string is read from the HIDL parcel as a `hidl_string` (up to 256 bytes per packet in `sendToServer`), and formatted into a 512-byte buffer in `SendMessageToSocketClient`.

#### Is there any command parsing?
* **No command parsing**: The HAL acts strictly as an **IPC bridge / transparent relay**. It does not parse prefixes, split commands, or validate tokens. It logs the packet:
  ```c
  ALOGD("[%s] sendToServer() data = [%s]", "sendToServer", data.c_str());
  ```
  and immediately pushes the raw payload over the socket.

---

### 4. Implementation in `VendorTransfer` Service Daemon

Decompiled implementation from `vendor-oplus-hardware-transfer@1.0-service`:

```c
// VendorTransfer::sendToServer (0x0000378c)
android::hardware::Return<bool> VendorTransfer::sendToServer(const android::hardware::hidl_string& data) {
    __android_log_print(ANDROID_LOG_DEBUG, "VENDOR_TRANSFER", 
                        "[%s] sendToServer() data = [%s]", "sendToServer", data.c_str());

    bool result = false;
    if (data.c_str() != nullptr) {
        result = SendMessageToSocketClient(data.c_str());
    }
    return result;
}

// VendorTransfer::SendMessageToSocketClient (0x00003244)
bool VendorTransfer::SendMessageToSocketClient(const char *msg) {
    pthread_mutex_lock(&this->mMutex); // offset +0x14

    int fd = this->client_fd;          // offset +0x0c
    if (fd <= 0) {
        __android_log_print(ANDROID_LOG_ERROR, "VENDOR_TRANSFER", 
                            "SendMessageToSocketClient: client fd invalid (%d)", fd);
        pthread_mutex_unlock(&this->mMutex);
        return false;
    }

    size_t len = strlen(msg);
    size_t total_written = 0;
    int retry_count = 0;

    while (total_written < len && retry_count < 5) {
        // Calls checked libc write: __write_chk(fd, buf + total_written, len - total_written, 512)
        ssize_t ret = write(fd, msg + total_written, len - total_written);
        if (ret < 0) {
            if (errno == EINTR) continue;
            retry_count++;
            continue;
        }
        total_written += ret;
    }

    pthread_mutex_unlock(&this->mMutex);
    return (total_written == len);
}
```

---

### 5. Ultimate Syscall Trace

The write operation follows this exact execution chain down to the Linux kernel:

```
ITransfer::sendToServer(data)
  └─► BnHwTransfer::_hidl_sendToServer()                   [vendor.oplus.hardware.transfer@1.0.so @ 0x0000c670]
        └─► VendorTransfer::sendToServer()                 [vendor-oplus-hardware-transfer@1.0-service @ 0x0000378c]
              └─► VendorTransfer::SendMessageToSocketClient() [vendor-oplus-hardware-transfer@1.0-service @ 0x00003244]
                    └─► __write_chk() / write()            [libc.so]
                          └─► SVC 0 (sys_write, syscall 4) [Linux Kernel (AArch32)]
```

* **Syscall**: `sys_write`
* **Syscall Number**: `4` (ARM EABI `__NR_write`, `r7 = 4`, `svc 0x00000000`)
* **Target Descriptor**: Connected client socket FD (`AF_LOCAL` stream socket).