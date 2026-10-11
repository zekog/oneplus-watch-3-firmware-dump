# Deep Analysis: Command ID 21 (`APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW`)
**Target System:** OnePlus Watch 3 (Snapdragon W5 AP <---> Bestechnic BES2610 MCU)  
**Binary Analyzed:**  
- `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_dlkm_extracted/lib/modules/bes2610.ko`  
- `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_dlkm_extracted/lib/modules/oplus_comm_master.ko`  
- `/home/zek/Pobrane/opw3 firmware/mcu_firmware/OPWWE251/OPWWE251_M55C0_2505201801.bin`  
- `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_dump/lib/hw/android.hardware.sensors@1.0-impl.so`  
- `/system/bin/dccservice` & `/system/lib/liboppoDeamonData.so`

---

## 1. Binary Architecture & Module Clarification

* **`bes2610.ko` Architecture & Scope:**
  Analysis of `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_dlkm_extracted/lib/modules/bes2610.ko` reveals it is **exclusively the Wi-Fi 802.11 FullMAC & Bluetooth MSPI driver** (contains `rwnx_*`, `bes_mspi_*`, Wi-Fi scanning, and calibration routines). It contains **0 references** to DCC commands, fitness settings, or health monitoring switches.
* **Driver Implementing the Channel Bus (`oplus_comm_master.ko`):**
  The actual inter-processor communication bus and character device nodes (`/dev/dcc_data`, `/dev/std_sns`, `/dev/whs`, `/dev/ccch_*`) are implemented in **`oplus_comm_master.ko`**.
* **Target Binary Implementing the Handler:**
  The command enum `APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW` and its parser logic reside in the **Cortex-M55 RTOS Firmware (`OPWWE251_M55C0_2505201801.bin`)**.

---

## 2. Handler Disassembly & References (Command ID 21)

### A. String & Registration
* **Log String:** `"APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW = %d"` located at VMA **`0x1065ff6c`**.
* **Handler Descriptor:** Registered in DCC module dispatcher table at **`0x10743408`** under handler name `"dcc_setting_fitness_handler"`:
  ```c
  // Module registration at 0x103204b6
  dcc_register(MODULE_ID_FITNESS_SETTINGS /* 63 / 0x3F */, &dcc_setting_fitness_handler);
  ```

### B. Command 21 Inbound Handler (`dcc_setting_fitness_parser` @ `0x1031fbde`)
When an incoming packet arrives from Android containing Command ID 21:
```armasm
1031fbde:  movs   r2, #8
1031fbe0:  movs   r0, #21            ; Command ID = 21 (0x15: APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW)
1031fbe2:  add    r1, sp, #232
1031fbe4:  bl     0x1031f6b4         ; Look up current switch status in RAM cache
1031fbe8:  ldr    r3, [sp, #28]      ; Load new value from incoming DCC payload
1031fbea:  ldr    r2, [sp, #232]     ; Load current value
1031fbec:  cmp    r3, r2             ; Has the state changed?
1031fbee:  beq.n  0x1031ff06         ; If identical -> skip update
1031fbf2:  str    r3, [sp, #232]     ; Store new state: 0 = Disabled, 1 = Enabled
1031fbf4:  bl     0x102dd2e4         ; Query current system tick/timestamp
1031fbf8:  str    r0, [sp, #236]     ; Record update timestamp
1031fbfa:  movs   r0, #21
1031fbfc:  add    r1, sp, #232
1031fbfe:  movs   r2, #8
1031fc00:  strb.w r0, [sp, #10]
1031fc04:  bl     0x1031f634         ; Commit updated switch setting to NVRAM/flash
```

### C. Outbound Status Query (`dcc_setting_fitness_query` @ `0x10320018`)
When Android queries the active configuration or synchronizes state:
```armasm
10320018:  movs   r0, #21            ; Command ID 21
1032001a:  bl     0x1031f6b4         ; Fetch state from cache
10320024:  str    r3, [r4, #40]      ; Pack into outgoing telemetry frame buffer
```

---

## 3. Communication Pipeline & Transmitting Functions

```
+-------------------------------------------------------+
|  Android Framework / UI                               |
|  - HeyHealthService.apk / HeyHeartRate.apk            |
|  - Setting: "Irregular Heart Rhythm Warning" Toggle   |
+---------------------------+---------------------------+
                            | Binder IPC
                            v
+-------------------------------------------------------+
|  Native Service: /system/bin/dccservice               |
|  - android::IDeamonService (liboppoDeamonData.so)     |
|  - android::DeamonDataWriter::threadLoop()            |
|  - Invokes write(fd, packet_buf, 16)                  |
+---------------------------+---------------------------+
                            | write() to /dev/dcc_data
                            v
+-------------------------------------------------------+
|  Linux Kernel: oplus_comm_master.ko                   |
|  - ccch_write() (0x00000370)                          |
|  - Enqueues to g_cdev_info_list[1].tx_fifo            |
|  - comm_master_download_thread() (0x00002ab4)         |
|  - Transmits via spidev_spi_sync() (0x00003a3c)       |
+---------------------------+---------------------------+
                            | SPI Physical Bus
                            v
+-------------------------------------------------------+
|  Bestechnic BES2610 RTOS (Cortex-M55)                 |
|  - SPI RX interrupt -> dcc_setting_fitness_handler    |
|  - dcc_setting_fitness_parser() (0x1031fbde)          |
|  - Activates AFib / Irregular PPG monitoring          |
+-------------------------------------------------------+
```

---

## 4. Channel & Packet Specification

### Channel Selection:
* **Channel ID `0x0001` (`dcc_data`)** or high-priority **`0x0007` (`dcc_datah`)**.
* **Why not `0x04` (`std_sns`)?** `std_sns` is allocated strictly for streaming Android Sensor HAL events (accelerometer, step detector, optical PPG pulses).
* **Why not `0x0b` (`whs`)?** `whs` is dedicated to Wearable Health Service real-time algorithm controls (`oplus_whs_handler` msgid 1 tracking, msgid 2 workout sessions).
* **Why `0x01` (`dcc_data`)?** DCC Module `0x3F` (63) is the dedicated channel for fitness and health configuration persistence.

### Exact 16-Byte Packet Layout:
```
+-----------------------------------------------------------------------------------+
| Upper-Level Frame Header (comm_packet_t)                                          |
+-----------------------------------+-----------------------------------------------+
| channel_id (uint16_t, LE)         | payload_len (uint16_t, LE)                    |
| 0x0001 (dcc_data)                 | 0x0008 (8 Bytes)                              |
+-----------------------------------+-----------------------------------------------+
| DCC Protocol Header                                                               |
+-----------------------------------+-----------------------------------------------+
| module_id (uint16_t, LE)          | subcommand (uint16_t, LE)                     |
| 0x003F (63 = FITNESS_SETTINGS)    | 0x0001 (SET_SINGLE_SETTING)                   |
+-----------------------------------+-----------------------------------------------+
| Command 21 Payload                                                                |
+-----------------------------------+-----------------------------------------------+
| command_id (uint16_t, LE)         | value_len (uint16_t, LE)                      |
| 0x0015 (21 = IRREG_HEART_WARN_SW) | 0x0004 (4 Bytes)                              |
+-----------------------------------+-----------------------------------------------+
| switch_value (uint32_t, LE)                                                       |
| 0x00000001 = ENABLE (0x00000000 = DISABLE)                                        |
+-----------------------------------------------------------------------------------+
```

### Raw Hex Sequences:
* **Enable Irregular Heart Warning:**
  ```hex
  01 00 08 00 3F 00 01 00 15 00 04 00 01 00 00 00
  ```
* **Disable Irregular Heart Warning:**
  ```hex
  01 00 08 00 3F 00 01 00 15 00 04 00 00 00 00 00
  ```

---

## 5. Userspace Accessibility Evaluation

* **Device Nodes:** `/dev/dcc_data` (Major 510, Minor 1) and `/dev/dcc_datah` (Minor 7).
* **Permissions (`/system/etc/init/dccservice.rc`):**
  ```init
  on post-fs-data
      chmod 0664 /dev/dcc_data
      chmod 0664 /dev/dcc_datah
      chown system /dev/dcc_data
      chown system /dev/dcc_datah
  ```
* **Can we send this directly from userspace?**
  * **As `root` (`su`):** **YES.** Full read/write capability. Running `echo -ne "\x01\x00\x08\x00\x3f\x00\x01\x00\x15\x00\x04\x00\x01\x00\x00\x00" > /dev/dcc_data` commits the change directly to the MCU.
  * **As `system` (UID 1000):** **YES.** Permitted by file group/owner permissions (`0664` system:system).
  * **As unprivileged shell (`shell` UID 2000):** **NO.** Blocked by `0664` discretionary access permissions and SELinux domain confinement on `dcc_device`.

---

## 6. HAL Service Inventory & Evaluation

* **Android Sensor HAL (`android.hardware.sensors@1.0-impl.so`):**
  * **Result:** **NO.**
  * Operates exclusively on `/dev/std_sns` (`MCUSensor::activate`). Handles standard sensor streams (`android.sensor.heart_rate`, `android.sensor.ecg`).
* **Transfer HAL (`vendor.oplus.hardware.transfer@1.0.so`):**
  * **Result:** **NO.**
  * Provides engineering test and diagnostic bridges (`oppo_mcu_diag`), not runtime health settings.
* **Native Android Service (`/system/bin/dccservice`):**
  * **Result:** **YES.**
  * Implements the Binder service `android::IDeamonService`, manages write loops on `/dev/dcc_data`, and translates framework commands into DCC packets.
