# Oplus Communication Master (`oplus_comm_master.ko`) Deep Analysis Report

**Target Binary**: `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_dlkm_extracted/lib/modules/oplus_comm_master.ko`  
**Companion Module**: `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_boot_dump/vendor_ramdisk/ramdisk_extracted/lib/modules/oplus_snshub.ko`  
**Device Tree Node**: `qupv3_se2_spi / slave@0` (`compatible = "oplus,dual_comm_slave"`)  
**Target Hardware**: OnePlus Watch 3 (Snapdragon W5 Gen 1 / SW5100 AP <---> Bestechnic BES2610 MCU/RTOS)  
**Kernel Environment**: Android 14, Linux 5.15 GKI (AArch64)

---

## 1. Inventory & Symbol Analysis

### 1.1 ELF Properties
* **Format**: ELF 64-bit LSB Relocatable (`ET_REL`), ARM AArch64.
* **Build ID**: `5e90cfbda20810b33e196d053b81ffa3906ff084` (unstripped, full symbol table and `.BTF` type debug info present).

### 1.2 Exported Kernel Symbols (`EXPORT_SYMBOL_GPL`)
These symbols are exported via `__ksymtab_gpl` for use by other kernel drivers (such as `oplus_comm_master_bt.ko`):
| Symbol Name | Type | Section Offset | Description |
|---|---|---|---|
| `ccch_open` | Global Func | `.text + 0x0b38` | Opens a logical communication channel character device |
| `ccch_close` | Global Func | `.text + 0x0da0` | Closes a logical channel cdev |
| `ccch_read` | Global Func | `.text + 0x0700` | Reads received packet data from a channel's RX kfifo |
| `ccch_write` | Global Func | `.text + 0x0370` | Pushes a packet into a channel's TX kfifo for download to MCU |
| `is_kernel_used` | Global Func | `.text + 0x0e0c` | Checks if a channel is in use by kernel subsystems |
| `data_cdev_remove` | Global Func | `.text + 0x0e1c` | Cleans up and unregisters data character devices |

### 1.3 Internal Functions (`.text` Section)
| Virtual Address / Offset | Size | Binding | Function Name |
|---|---|---|---|
| `0x000004d8` | 552 B | LOCAL | `wfifo_in` |
| `0x000008e4` | 284 B | LOCAL | `rfifo_out` |
| `0x00000a00` | 312 B | LOCAL | `cdev_fifo_out_frame` |
| `0x00000ecc` | 2572 B | LOCAL | `spidev_probe` |
| `0x000018d8` | 8 B | LOCAL | `spidev_remove` |
| `0x000018e0` | 20 B | LOCAL | `snshub_suspend` |
| `0x000018f4` | 20 B | LOCAL | `snshub_resume` |
| `0x00001908` | 140 B | LOCAL | `slave_ready_cb` |
| `0x00001994` | 232 B | LOCAL | `get_gpio_from_devtree` |
| `0x00001a7c` | 120 B | LOCAL | `s2m_int_irq_fn` |
| `0x00001af4` | 220 B | LOCAL | `spidev_gpio_request_irq` |
| `0x00001bd0` | 64 B | LOCAL | `s2m_ans_irq_fn` |
| `0x00001c10` | 3748 B | LOCAL | `comm_master_upload_thread` |
| `0x00002ab4` | 1036 B | LOCAL | `comm_master_download_thread` |
| `0x00002ec0` | 2940 B | LOCAL | `comm_master_download` |
| `0x00003a3c` | 324 B | LOCAL | `spidev_spi_sync` |
| `0x00003b80` | 916 B | LOCAL | `spidev_read` |
| `0x00003f38` | 776 B | LOCAL | `spidev_write` |
| `0x00004264` | 356 B | LOCAL | `spidev_open` |
| `0x000043c8` | 204 B | LOCAL | `spidev_release` |
| `0x00004494` | 244 B | LOCAL | `log_show` |
| `0x00004588` | 164 B | LOCAL | `log_store` |
| `0x0000462c` | 444 B | LOCAL | `info_show` |
| `0x000047e8` | 320 B | LOCAL | `info_store` |
| `0x00004928` | 56 B | LOCAL | `commstop_show` |
| `0x00004960` | 492 B | LOCAL | `commstop_store` |
| `0x00004b4c` | 60 B | LOCAL | `auto_reset_mcu_show` |
| `0x00004b88` | 140 B | LOCAL | `auto_reset_mcu_store` |
| `0x00004c14` | 360 B | LOCAL | `speedtest_show` |
| `0x00004d7c` | 8 B | LOCAL | `speedtest_store` |
| `0x00004d84` | 888 B | LOCAL | `speedtest_thread` |
| `0x00008b54` | 284 B | GLOBAL | `init_module` |
| `0x00008c70` | 4 B | GLOBAL | `cleanup_module` |

### 1.4 Imported Kernel Symbols (`UND`)
The driver interfaces with the following key kernel facilities:
* **SPI Subsystem**: `__spi_register_driver`, `spi_sync`.
* **GPIO & Interrupts**: `of_get_named_gpio_flags`, `gpio_request`, `gpio_to_desc`, `gpiod_direction_input`, `gpiod_direction_output_raw`, `gpiod_get_raw_value`, `gpiod_to_irq`, `request_threaded_irq`, `enable_irq`, `disable_irq_nosync`, `irq_set_irq_wake`.
* **Inter-driver Synchronization**: `oplus_spi_slave_ready_cb_register`, `oplus_snshub_states_uevent`, `wait_mcureseting`.
* **Memory & Fifos**: `__kfifo_alloc`, `__kfifo_in`, `__kfifo_out`, `kmem_cache_alloc_trace`, `kmalloc_order_trace`, `kfree`.
* **Task Management & Power**: `kthread_create_on_node`, `wake_up_process`, `kthread_stop`, `sched_setscheduler`, `cpu_latency_qos_add_request`, `cpu_latency_qos_update_request`, `wakeup_source_add`, `__pm_stay_awake`, `__pm_relax`, `pm_wakeup_ws_event`.
* **Userspace Interfaces**: `__class_create`, `class_create_file_ns`, `__register_chrdev`, `device_create`, `device_destroy`.

---

## 2. Channel & Packet Structure

### 2.1 Channel Table (`g_cdev_info_list`)
Channels are identified by **16-bit unsigned integer IDs (`uint16_t`)** and associated with string names. The driver statically defines 9 channels in the array `g_cdev_info_list` (located in `.data + 0x00`, each entry is 24 bytes):

| Index | Channel ID (Hex) | Channel ID (Dec) | Channel Name | Typical Function / Purpose |
|---|---|---|---|---|
| 0 | `0x000e` | 14 | `audiok` | Audio kernel subsystem data stream |
| 1 | `0x0007` | 7 | `dcc_datah` | Dual-Core Communication High Priority |
| 2 | `0x0001` | 1 | `dcc_data` | Standard Dual-Core Communication (IPC) |
| 3 | `0x0002` | 2 | `mcu_factory` | Factory test / calibration interface |
| 4 | `0x0003` | 3 | `gps_data` | GNSS/GPS NMEA & raw positioning packets |
| 5 | `0x0004` | 4 | `std_sns` | Standard sensor data (accelerometer, gyro) |
| 6 | `0x000b` | 11 | `whs` | Wrist Heart-rate Sensor / PPG / SpO2 |
| 7 | `0x000d` | 13 | `haptic` | Haptic vibration motor commands |
| 8 | `0x0010` | 16 | `audioh` | Audio host stream |
| *Special* | `0x03b8` | 952 | `speedtest_str` | Throughput benchmarking string data |
| *Special* | `0x03b9` | 953 | `speedtest_pkt` | Throughput benchmarking raw packet |

### 2.2 Packet and Frame Format

The protocol utilizes a two-tier framing model: an upper-level **Packet (`comm_packet_t`)** encapsulated within a physical **Datalink Frame (`comm_frame_t`)** over SPI.

```
+-------------------------------------------------------------------------------------------------------+
|                                    SPI DATALINK FRAME (comm_frame_t)                                  |
+-------------------+-------------------+-------------------+-------------------+-----------------------+
|  seq_num (2B)     |  flags/chk (2B)   |  payload_chk (2B) |  total_len (2B)   |   PACKET DATA (N B)   |
|  puVar26[0]       |  puVar26[1]       |  puVar26[2]       |  puVar26[3]       |   puVar26 + 4         |
+-------------------+-------------------+-------------------+-------------------+-----------------------+
                                                                                |
                                         +--------------------------------------+
                                         v
+-------------------------------------------------------------------------------+
|                        UPPER-LEVEL PACKET (comm_packet_t)                     |
+-----------------------+-----------------------+-------------------------------+
|  channel_id (2B)      |  payload_length (2B)  |   PAYLOAD (length Bytes)      |
|  [0..1]               |  [2..3]               |   [4 .. length+3]             |
+-----------------------+-----------------------+-------------------------------+
```

#### Detailed Field Descriptions:
1. **Datalink Header (8 Bytes)**:
   * **`seq_num`** (`uint16_t`): Monotonically increasing sequence number (`up_selnum` / `dn_selnum`).
   * **`flags / header_checksum`** (`uint16_t`):
     * Bits `[7:0]`: `is_first_frame` boolean flag.
     * Bits `[15:8]`: 8-bit inverted additive checksum over the header fields.
   * **`payload_checksum`** (`uint16_t`): 16-bit 1's complement Internet checksum (`~sum`) calculated over the entire packet data.
   * **`total_length`** (`uint16_t`): Total length of the enclosed packet (`length + 4`). Maximum frame size is `0x3ff4` (16,372 bytes).
2. **Packet Header (4 Bytes)**:
   * **`channel_id`** (`uint16_t`): Target channel ID matching `g_cdev_info_list`.
   * **`payload_length`** (`uint16_t`): Length of payload following the 4-byte packet header.
   * **`payload`** (`uint8_t[]`): Raw payload bytes.

### 2.3 Packet Ingestion & Routing (`distribute_packet_to_data_cdev`)
Inlined into `comm_master_upload_thread` (`0x00114c10`):
* Reads incoming SPI frame into `comm_master_upload_thread_packet_area`.
* Validates `payload_checksum` and `seq_num`.
* Extracts `channel_id` from offset 0.
* Matches `channel_id` against `g_cdev_info_list` to find the corresponding `cdev_info` instance `lVar12`.
* Pushes `length + 4` bytes into `lVar12->tx_fifo` using `__kfifo_in`.
* Increments `lVar12->rx_packet_to_fifo` counter.
* Triggers semaphore `up(&lVar12->packet_cnt_sem)` to unblock readers waiting in `ccch_read`.
* Signals PM wake lock event: `pm_wakeup_ws_event(lVar12->wakesrc, 1000, 0)`.

---

## 3. MCU State Machine

The driver manages the lifecycle and health of the BES2610 MCU via an enumerated state machine shared with `oplus_snshub.ko`:

```
           +---------------------+
           |   MCU_STATES_FIRST  | (0) Initial Boot / Handshake
           +----------+----------+
                      |
                      v
           +---------------------+
  +------->|  MCU_STATES_NORMAL  | (1) Operational / Heartbeat
  |        +----------+----------+
  |                   | Communication failure / CRC errors / Timeout
  |                   v
  |        +---------------------+
  |        |   MCU_STATES_CRASH  | (2) Dead pin asserted or consecutive SPI fails
  |        +----------+----------+
  |                   |
  |                   v
  |        +---------------------+
  |        |   MCU_STATES_DUMP   | (3) RAM dump initiated via dump IRQ
  |        +----------+----------+
  |                   |
  +-------------------+ (Post-dump hardware reset)
```

### 3.1 State Enumeration (`mcu_states_t`)
Defined in BTF debug info:
* `MCU_STATES_FIRST = 0`: Initial boot state or first-time sync.
* `MCU_STATES_NORMAL = 1`: Normal operational state.
* `MCU_STATES_CRASH = 2`: MCU communication failed, link dropped, or hard crash.
* `MCU_STATES_DUMP = 3`: MCU triggered RAM dump.
* `MCU_STATES_MAX = 4`: State boundary limit.

### 3.2 Transitions & Triggers
1. **Transition to `MCU_STATES_CRASH` (`2`)**:
   * **Trigger 1**: Consecutive download handshake timeouts (`DAT_001002a0 > 2`).
   * **Trigger 2**: Excessive SPI transfer error retries (`DAT_00100298 > 19`).
   * **Trigger 3**: Consecutive upload synchronization failures.
   * **Trigger 4**: Dead GPIO (`dead-gpio`, TLMM 109) high assertion.
   * **Action**: Emits kernel uevent:
     ```c
     oplus_snshub_states_uevent(MCU_STATES_CRASH, "ocm");
     ```
     which dispatches a `kobject_uevent_env` containing `ACTION=change`, `MCU_UEVENT`, `MCU_STATES=crash`, `ocm`.
2. **Transition to `MCU_STATES_DUMP` (`3`)**:
   * **Trigger**: MCU asserts `mcu_dump_int` line, triggering `mcu_dump_int_irq_fn`.
   * **Handler**:
     * Queues work to `_system_wq` via `queue_work_on(0x20, _system_wq, &g_snshub->dump_work)`.
     * `mcu_states_dump()` executes, emitting uevent `MCU_STATES=dump` with origin `"snshub"`.
     * Userspace daemon (`oplus_snshub_store_dump_notify`) responds by toggling dump strobe GPIO 1017 (`0x3f9`) high for 100 ms to capture MCU SRAM/DRAM registers.

---

## 4. Auto-Reset Mechanism

### 4.1 Sysfs Attribute
* **Sysfs Path**: `/sys/class/ocm/auto_reset_mcu`
* **Access Mode**: `0644` (Read / Write)
* **Underlying Variable**: `spidev->auto_reset_mcu_switch` (located at offset `spidev + 0x3b8`).
* **Initial Value**: `0` (Disabled by default upon `kzalloc` in `spidev_probe`).

### 4.2 Decompiled Functions

#### `auto_reset_mcu_show` (`0x00117b4c`):
```c
ssize_t auto_reset_mcu_show(struct class *class, struct class_attribute *attr, char *buf)
{
    return snprintf(buf, PAGE_SIZE, "%d\n", spidev->auto_reset_mcu_switch);
}
```

#### `auto_reset_mcu_store` (`0x00117b88`):
```c
ssize_t auto_reset_mcu_store(struct class *class, struct class_attribute *attr, const char *buf, size_t count)
{
    if (buf[0] == '1') {
        spidev->auto_reset_mcu_switch = 1;
    } else if (buf[0] == '0') {
        spidev->auto_reset_mcu_switch = 0;
    } else {
        return -EINVAL; // 0xffffffffffffffea
    }
    // Set grace period countdown
    dci.grace_counter = -10; // 0xfffffff6
    return count;
}
```

### 4.3 Execution Chain
When enabled (`auto_reset_mcu_switch == 1`), consecutive SPI transmission failures trigger the reset handler:
```
comm_master_download failure (retry limit exceeded)
  └─► oplus_snshub_states_uevent(MCU_STATES_CRASH, "ocm")
        └─► userspace daemon / oplus_snshub_reset()
              └─► __oplus_snshub_reset()
```

---

## 5. Hardware Reset & Power Control

From device tree overlay (`dtbo_overlay_00.dts`, `fragment@29` for target `<&osh>`):

### 5.1 GPIO Pin Allocation
| Signal Name | Device Tree Property | Controller | GPIO Number (Dec) | GPIO Number (Hex) | Active State |
|---|---|---|---|---|---|
| **MCU Reset** | `reset-gpio` | `<&tlmm>` | **GPIO 64** | `0x40` | Active Low |
| **MCU Power** | `power-gpio` | `<&tlmm>` | **GPIO 112** | `0x70` | Active High |
| **Buck Enable** | `buck-enable-gpio` | `<&tlmm>` | **GPIO 33** | `0x21` | Active High |
| **Dead/Crash Detect** | `dead-gpio` | `<&tlmm>` | **GPIO 109** | `0x6d` | Active High |
| **Dump Strobe** | `mcu_dump_gpio` | `<&tlmm>` | **GPIO 1017** | `0x3f9` | Strobe High |

### 5.2 Reset Sequence & Pulse Timing
In `__oplus_snshub_reset` (`0x001016e0` in `oplus_snshub.ko`):
```c
void __oplus_snshub_reset(struct snshub_data *snshub, void *data)
{
    mutex_lock(&snshub->reset_lock);
    snshub->is_resetting = 1;

    // 1. Notify listeners that MCU reset is starting
    blocking_notifier_call_chain(&snshub->notifier_list, 0, data);

    // 2. Set AP State GPIO to low
    gpiod_direction_output_raw(snshub->pdata->ap_state_gpio, 0);

    // 3. Assert Reset GPIO (pull LOW)
    gpiod_direction_output_raw(snshub->pdata->reset_gpio, 1);

    // 4. Hold Reset Pulse: reset_time * 10 ms (default: 10 ms)
    msleep(reset_time * 10);

    // 5. Deassert Reset GPIO (float or pull HIGH)
    gpiod_direction_output_raw(snshub->pdata->reset_gpio, 0);

    // 6. Restore AP State GPIO
    gpiod_direction_output_raw(snshub->pdata->ap_state_gpio, 1);

    // 7. Post-reset recovery delay: reset_time * 50 ms (default: 50 ms)
    msleep(reset_time * 50);

    // 8. Notify listeners that MCU reset completed
    blocking_notifier_call_chain(&snshub->notifier_list, 1, data);
    snshub->is_resetting = 0;
    mutex_unlock(&snshub->reset_lock);
}
```

* **Reset Pulse Duration**: **10 milliseconds** (`reset_time * 10`).
* **Post-Reset Recovery Time**: **50 milliseconds** (`reset_time * 50`).
* **Regulator/PMIC Calls**: **None directly**. Power is controlled through dedicated hardware buck regulator enable lines (`buck-enable-gpio` = GPIO 33, `power-gpio` = GPIO 112).

---

## 6. SPI Communication Layer

From device tree overlay (`dtbo_overlay_00.dts`, `fragment@27` for target `<&qupv3_se2_spi>`):

### 6.1 SPI Controller & Physical Layer
* **Bus / Controller**: **`qupv3_se2_spi`** (Qualcomm QUPv3 Serial Engine 2 configured as SPI Master).
* **Chip Select**: **CS 0** (`reg = <0x00>`).
* **SPI Mode**: **Mode 1** (CPOL = 0, CPHA = 1). Set via:
  ```c
  spi->mode |= SPI_CPHA; // (param_1 + 0x3a8 |= 1)
  ```
* **Clock Frequency**: **48,000,000 Hz (48 MHz)** (`spi-max-frequency = <0x2dc6c00>`).
* **Word Size**: **32 bits** (`spi_bits_per_word = <0x20>`), with fallback to 8 bits.
* **Max Transfer Size**: **16,380 bytes** (`0x3ffc`). The buffer allocations in `spidev_probe` allocate 4 pages of `0x3ffc` bytes (`kmalloc_order_trace(0x3ffc, ...)`). Maximum frame payload is `0x3ff0` (16,368 bytes).

### 6.2 Handshake & Flow Control GPIOs
SPI master/slave synchronization uses 4 dedicated interrupt lines:
* **`m2s_int_gpio`** = **GPIO 32** (`0x20`): Master to Slave Interrupt (signals MCU that AP has data to send).
* **`s2m_ans_gpio`** = **GPIO 24** (`0x18`): Slave to Master Answer (MCU acknowledges AP interrupt).
* **`s2m_int_gpio`** = **GPIO 25** (`0x19`): Slave to Master Interrupt (MCU signals AP that it has data to upload).
* **`m2s_ans_gpio`** = **GPIO 85** (`0x55`): Master to Slave Answer (AP acknowledges MCU interrupt).

---

## 7. Sysfs Control Surface

The driver exposes 5 attributes under `/sys/class/ocm/`:

| Attribute Name | Sysfs Path | Mode | Show Function | Store Function | Description |
|---|---|---|---|---|---|
| `log` | `/sys/class/ocm/log` | `0644` (rw) | `log_show` | `log_store` | Reads/writes driver debug log mask (`log_array`). |
| `info` | `/sys/class/ocm/info` | `0644` (rw) | `info_show` | `info_store` | Shows upload/download frame stats and per-channel FIFO counters. Writing `1` clears stats. |
| `commstop` | `/sys/class/ocm/commstop` | `0644` (rw) | `commstop_show` | `commstop_store` | Controls `close_comm_state`: writing `1` suspends/stops SPI communication to MCU. |
| `auto_reset_mcu` | `/sys/class/ocm/auto_reset_mcu` | `0644` (rw) | `auto_reset_mcu_show` | `auto_reset_mcu_store` | Reads/sets `auto_reset_mcu_switch`: writing `1` enables auto-reset on link failures, `0` disables. |
| `speedtest` | `/sys/class/ocm/speedtest` | `0644` (rw) | `speedtest_show` | `speedtest_store` | Runs SPI bus throughput stress test using channels 0x3b8/0x3b9. |

Additionally, the character device driver registers major number **`153` (`0x99`)** for channel device nodes under `/dev/ccch_*` (e.g., `/dev/ccch_dcc_data`, `/dev/ccch_std_sns`).
