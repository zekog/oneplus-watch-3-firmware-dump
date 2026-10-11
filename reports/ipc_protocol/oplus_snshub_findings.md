# Oplus Sensor Hub (`oplus_snshub.ko`) Deep Analysis Report

**Target Binary**: `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_boot_dump/vendor_ramdisk/ramdisk_extracted/lib/modules/oplus_snshub.ko`  
**Target Hardware**: OnePlus Watch 3 (Snapdragon W5 Gen 1 / SW5100 AP <---> Bestechnic BES2610 Sensor Hub Coprocessor)  
**Device Tree Node**: `<&osh>` (`compatible = "oplus,sensor-hub"`)  
**Kernel Environment**: Android 14, Linux 5.15 GKI (AArch64)

---

## 1. Exported Symbols & Module Inventory

The module serves as the central hardware controller and lifecycle manager for the BES2610 MCU, exporting APIs for inter-driver coordination (notably for `oplus_comm_master.ko` and `oplus_comm_master_bt.ko`):

| Symbol Name | Type | Size | Description |
|---|---|---|---|
| `is_mcureseting` | Global Func | 68 B | Checks if an MCU reset operation is currently in progress |
| `wait_mcureseting` | Global Func | 88 B | Blocks the calling thread until an ongoing MCU reset completes |
| `oplus_snshub_reset` | Global Func | 40 B | Triggers a full pulse reset sequence of the MCU |
| `oplus_snshub_assert_reset` | Global Func | 124 B | Asserts the MCU reset pin low and notifies pre-reset listeners |
| `oplus_snshub_deassert_reset`| Global Func | 128 B | Deasserts the MCU reset pin high and notifies post-reset listeners |
| `oplus_snshub_power_off_once`| Global Func | 484 B | Performs a hard power cycle (toggling buck/power regulators) |
| `oplus_snshub_wakeup_data_uevent` | Global Func | 208 B | Emits a uevent notifying userspace that coprocessor data is available |
| `oplus_snshub_states_uevent` | Global Func | 336 B | Emits an MCU state change uevent (`first`, `normal`, `crash`, `dump`) |
| `oplus_snshub_hw_gpio_in` | Global Func | 88 B | Reads the raw hardware state of the reset pin |
| `oplus_snshub_get_disable_uevent` | Global Func | 16 B | Returns whether state uevents are currently disabled |
| `oplus_snshub_set_disable_uevent` | Global Func | 92 B | Configures whether state uevents should be suppressed |
| `oplus_snshub_reset_notifier_register` | Global Func | 88 B | Registers a callback for MCU pre- and post-reset events |
| `oplus_snshub_reset_notifier_unregister` | Global Func | 88 B | Unregisters a reset notifier callback |

---

## 2. Decompiled Functions & Analysis

### 2.1 `is_mcureseting` (`0x00101bac`)
* **Purpose**: Returns whether an MCU hardware reset is actively executing.
* **GPIOs**: None directly.
* **Uevents**: None.
* **Decompiled Code**:
```c
bool is_mcureseting(void)
{
    if (g_snshub == NULL) {
        printk(KERN_ERR "g_snshub is NULL\n");
        return false;
    }
    // Field offset +0x270: mcureseting atomic flag
    return *(int *)((uintptr_t)g_snshub + 0x270) != 0;
}
```

---

### 2.2 `wait_mcureseting` (`0x00101334`)
* **Purpose**: Polls and sleeps in 20 ms increments until the `mcureseting` flag clears.
* **GPIOs**: None directly.
* **Uevents**: None.
* **Decompiled Code**:
```c
void wait_mcureseting(void)
{
    if (g_snshub == NULL) {
        printk(KERN_ERR "g_snshub is NULL\n");
        return;
    }
    while (*(int *)((uintptr_t)g_snshub + 0x270) != 0) {
        msleep(20);
    }
}
```

---

### 2.3 `oplus_snshub_reset` (`0x001016b8`) & `__oplus_snshub_reset` (`0x001016e0`)
* **Purpose**: Executes a synchronized hardware reset pulse on the MCU reset pin with pre/post notifier broadcasts.
* **GPIOs Touched**:
  * `gpio_ap_state` (TLMM GPIO): set LOW before reset, restored HIGH after reset.
  * `gpio_reset` (TLMM GPIO 64, active low): pulled LOW for `reset_time * 10 ms` (10 ms default), then released HIGH.
* **Timing**: 10 ms reset pulse + 50 ms post-reset recovery delay.
* **Uevents**: None directly (triggers notifications via blocking notifier chain).
* **Decompiled Code**:
```c
void __oplus_snshub_reset(struct oplus_snshub *snshub, void *data)
{
    mutex_lock(&snshub->reset_lock);
    snshub->mcureseting = 1;

    // 1. Notify listeners that MCU is entering reset (SNSHUB_PRE_RESET = 0)
    blocking_notifier_call_chain(&snshub->rst_nh, SNSHUB_PRE_RESET, data);

    // 2. Set AP State GPIO low
    if (snshub->pdata->gpio_ap_state < 512) {
        gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_ap_state),
                                   snshub->pdata->gpio_ap_state_active_low);
    }

    // 3. Assert Reset GPIO (active low -> output 1 raw / pull low)
    if (snshub->pdata->gpio_reset < 512) {
        if (snshub->pdata->gpio_reset_active_low) {
            gpiod_direction_input(gpio_to_desc(snshub->pdata->gpio_reset));
        } else {
            gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_reset), 1);
        }
    }

    printk(KERN_INFO "mcu reset start, hold time: %d ms\n", reset_time * 10);
    msleep(reset_time * 10); // Hold reset for 10 ms

    // 4. Deassert Reset GPIO (release back high)
    if (snshub->pdata->gpio_reset < 512) {
        if (!snshub->pdata->gpio_reset_active_low) {
            gpiod_direction_input(gpio_to_desc(snshub->pdata->gpio_reset));
        } else {
            gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_reset), 1);
        }
    }

    // 5. Restore AP State GPIO high
    if (snshub->pdata->gpio_ap_state < 512) {
        gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_ap_state),
                                   !snshub->pdata->gpio_ap_state_active_low);
    }

    // 6. Hold recovery time
    msleep(reset_time * 50); // 50 ms post-reset recovery delay
    printk(KERN_INFO "mcu reset complete, recovery time: %d ms\n", reset_time * 50);

    // 7. Notify listeners that reset finished (SNSHUB_POST_RESET = 1)
    blocking_notifier_call_chain(&snshub->rst_nh, SNSHUB_POST_RESET, data);
    snshub->mcureseting = 0;
    mutex_unlock(&snshub->reset_lock);
}
```

---

### 2.4 `oplus_snshub_assert_reset` (`0x00101b30`)
* **Purpose**: Locks the reset mutex, fires the pre-reset notifier, and pulls the MCU reset pin active low.
* **GPIOs**: `gpio_reset` (GPIO 64).
* **Decompiled Code**:
```c
void oplus_snshub_assert_reset(struct device *dev)
{
    struct oplus_snshub *snshub = dev_get_drvdata(dev);
    mutex_lock(&snshub->reset_lock);
    blocking_notifier_call_chain(&snshub->rst_nh, SNSHUB_PRE_RESET, dev);

    if (snshub->pdata->gpio_reset < 512) {
        if (snshub->pdata->gpio_reset_active_low) {
            gpiod_direction_input(gpio_to_desc(snshub->pdata->gpio_reset));
        } else {
            gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_reset), 1);
        }
    }
    msleep(10);
}
```

---

### 2.5 `oplus_snshub_deassert_reset` (`0x00101ab0`)
* **Purpose**: Releases the MCU reset pin high, sleeps 50 ms for MCU crystal stabilization, fires post-reset notifier, and unlocks reset mutex.
* **GPIOs**: `gpio_reset` (GPIO 64).
* **Decompiled Code**:
```c
void oplus_snshub_deassert_reset(struct device *dev)
{
    struct oplus_snshub *snshub = dev_get_drvdata(dev);
    if (snshub->pdata->gpio_reset < 512) {
        if (!snshub->pdata->gpio_reset_active_low) {
            gpiod_direction_input(gpio_to_desc(snshub->pdata->gpio_reset));
        } else {
            gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_reset), 1);
        }
    }
    msleep(50);
    blocking_notifier_call_chain(&snshub->rst_nh, SNSHUB_POST_RESET, dev);
    mutex_unlock(&snshub->reset_lock);
}
```

---

### 2.6 `oplus_snshub_power_off_once` (`0x00101864`)
* **Purpose**: Cycles power lines and hardware buck converters to force a cold reboot of the BES2610.
* **GPIOs Touched**:
  * `gpio_ap_state`
  * `gpio_reset` (GPIO 64)
  * `gpio_power` (GPIO 112)
  * `gpio_buck_enable` (GPIO 33)
* **Timing**:
  * Asserts reset: 10 ms delay.
  * Disables buck and power GPIOs: **200 ms** power discharge delay.
  * Re-enables buck and power GPIOs: 10 ms stabilization delay.
  * Deasserts reset: 50 ms boot recovery delay.
* **Decompiled Code**:
```c
void oplus_snshub_power_off_once(struct device *dev)
{
    struct oplus_snshub *snshub = dev_get_drvdata(dev);
    mutex_lock(&snshub->power_lock);
    blocking_notifier_call_chain(&snshub->power_nh, 0, dev);
    snshub->mcureseting = 1;

    // Put AP state low and assert reset
    gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_ap_state),
                               snshub->pdata->gpio_ap_state_active_low);
    gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_reset), 1);
    msleep(10);

    // Cut power to MCU
    gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_power),
                               !snshub->pdata->gpio_power_active_low);
    gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_buck_enable),
                               !snshub->pdata->gpio_buck_enable_active_low);
    msleep(200); // 200 ms cold discharge

    // Restore power to MCU
    gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_power),
                               snshub->pdata->gpio_power_active_low);
    gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_buck_enable),
                               snshub->pdata->gpio_buck_enable_active_low);
    msleep(10);

    // Release reset
    gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_reset), 0);
    gpiod_direction_output_raw(gpio_to_desc(snshub->pdata->gpio_ap_state),
                               !snshub->pdata->gpio_ap_state_active_low);
    msleep(50);

    blocking_notifier_call_chain(&snshub->power_nh, 1, dev);
    snshub->mcureseting = 0;
    mutex_unlock(&snshub->power_lock);
}
```

---

### 2.7 `oplus_snshub_wakeup_data_uevent` (`0x0010138c`)
* **Purpose**: Dispatches a kernel uevent signaling that the MCU has awakened the AP with pending sensor/IPC data.
* **GPIOs**: None.
* **Uevents Emitted**:
  * `ACTION=change` (enum `KOBJ_CHANGE` = 2)
  * Environment strings:
    * `MCU_UEVENT`
    * `WAKEUP_UEVENT=update`
    * Origin module name passed via `param_1` (e.g., `"ocm"`)
* **Decompiled Code**:
```c
void oplus_snshub_wakeup_data_uevent(const char *origin)
{
    if (origin == NULL) {
        printk(KERN_ERR "snshub: origin is null\n");
        return;
    }
    if (g_snshub == NULL) {
        printk(KERN_ERR "g_snshub is NULL\n");
        return;
    }

    char *envp[] = {
        "MCU_UEVENT",
        (char *)origin,
        "WAKEUP_UEVENT=update",
        NULL
    };
    kobject_uevent_env(&g_snshub->dev->kobj, KOBJ_CHANGE, envp);
}
```

---

### 2.8 `oplus_snshub_states_uevent` (`0x0010145c`)
* **Purpose**: Dispatches state change uevents to userspace Android daemons.
* **GPIOs**: None.
* **Uevents Emitted**:
  * `ACTION=change` (enum `KOBJ_CHANGE` = 2)
  * Environment strings:
    * `MCU_UEVENT`
    * Origin module name passed via `param_2` (e.g., `"ocm"`, `"snshub"`)
    * State tag indexed from internal string table:
      * `0` -> `MCU_STATES=first`
      * `1` -> `MCU_STATES=normal`
      * `2` -> `MCU_STATES=crash`
      * `3` -> `MCU_STATES=dump`
* **Filtering**: If `g_snshub->disable_uevent == 1`, state emission is suppressed.
* **Decompiled Code**:
```c
void oplus_snshub_states_uevent(uint32_t state, const char *origin)
{
    static const char * const state_strings[] = {
        "MCU_STATES=first",
        "MCU_STATES=normal",
        "MCU_STATES=crash",
        "MCU_STATES=dump"
    };

    if (state >= 4 || origin == NULL || g_snshub == NULL) {
        return;
    }

    if (state == MCU_STATES_CRASH && g_snshub->disable_uevent != 0) {
        // Suppress crash uevent if disabled by userspace
        return;
    }

    char *envp[] = {
        "MCU_UEVENT",
        (char *)origin,
        (char *)state_strings[state],
        NULL
    };
    kobject_uevent_env(&g_snshub->dev->kobj, KOBJ_CHANGE, envp);
}
```

---

## 3. All Uevent Emission Points & Triggers

There are exactly **3 call sites** for `kobject_uevent_env` in `oplus_snshub.ko`:

| Virtual Address | Calling Function | Uevent String Sent | Origin | Trigger Condition |
|---|---|---|---|---|
| `0x0010140c` | `oplus_snshub_wakeup_data_uevent` | `WAKEUP_UEVENT=update` | `param_1` (e.g. `"ocm"`) | MCU asserts data interrupt (`s2m_int`) indicating sensor data waiting in hardware FIFO. |
| `0x00101568` | `oplus_snshub_states_uevent` | `MCU_STATES=first`<br>`MCU_STATES=normal`<br>`MCU_STATES=crash`<br>`MCU_STATES=dump` | `param_2` | State transition triggered by SPI link watchdog timeout (`crash`), cold boot synchronization (`first`), or normal keepalive (`normal`). |
| `0x0010250c` | `mcu_states_dump` | `MCU_STATES=dump` | `"snshub"` | Hardware interrupt triggered on `mcu_dump_int` GPIO line (`mcu_dump_int_irq_fn`). |

---

## 4. Sysfs Device Attributes

Exposed under the platform device directory `/sys/devices/platform/soc/soc:osh/` (target `<&osh>`, `compatible = "oplus,sensor-hub"`):

| Attribute | Path | Mode | Permissions | Show Function | Store Function | Description |
|---|---|---|---|---|---|---|
| `disable_uevent` | `/sys/devices/platform/soc/soc:osh/disable_uevent` | `0660` | Read / Write | `oplus_snshub_show_disable_uevent` | `oplus_snshub_store_disable_uevent` | Reads or writes `g_snshub->disable_uevent`. Writing `1` suppresses all MCU state uevents to prevent crash storms during factory testing. |
| `power_mcu` | `/sys/devices/platform/soc/soc:osh/power_mcu` | `0200` | Write-Only | None | `oplus_snshub_store_power_mcu` | Writing a non-zero integer triggers `oplus_snshub_power_off_once()`, performing a full 200 ms cold power cycle. |
| `reset` | `/sys/devices/platform/soc/soc:osh/reset` | `0200` | Write-Only | None | `oplus_snshub_store_reset` | Writing an integer sets `reset_time` (ms multiplier) and triggers `__oplus_snshub_reset()`. |
| `dump_notify` | `/sys/devices/platform/soc/soc:osh/dump_notify` | `0200` | Write-Only | None | `oplus_snshub_store_dump_notify` | Strobes GPIO 1017 (`0x3f9`) high for 100 ms to notify the MCU that userspace has finished saving crash dump logs. |

---

## 5. Global State Variable: `g_snshub`

The singleton driver instance is stored in `g_snshub` (exported global pointer at `0x0000000000000000` in `.bss`, size 8 bytes). It points to a dynamically allocated `struct oplus_snshub` (size 632 bytes / `0x278` bytes):

```c
struct oplus_snshub {
    struct device                   *dev;                 // +0x000 (8 B)  Pointer to platform device
    struct oplus_snshub_platform_data *pdata;             // +0x008 (8 B)  Parsed device tree GPIO configuration
    struct mutex                    reset_lock;           // +0x010 (48 B) Mutex protecting reset operations
    struct blocking_notifier_head   rst_nh;               // +0x040 (72 B) Notifier chain for PRE/POST reset events
    struct mutex                    power_lock;           // +0x088 (48 B) Mutex protecting power toggle operations
    struct blocking_notifier_head   power_nh;             // +0x0b8 (72 B) Notifier chain for power events
    struct mutex                    dump_lock;            // +0x100 (48 B) Mutex protecting dump operations
    uint32_t                        disable_uevent;       // +0x130 (4 B)  Uevent suppression flag (1 = disabled)
    uint32_t                        _pad1;                // +0x134 (4 B)  Alignment padding
    struct mutex                    disable_uevent_lock;  // +0x138 (48 B) Mutex protecting disable_uevent
    int32_t                         dump_irq;             // +0x168 (4 B)  Linux IRQ number for dump GPIO
    uint32_t                        _pad2;                // +0x16c (4 B)  Alignment padding
    struct work_struct              dump_work;            // +0x170 (48 B) Deferred work item executing mcu_states_dump
    struct wakeup_source            *dump_wakesrc;        // +0x1a0 (208 B) Wake lock held during dump processing
    int32_t                         mcureseting;          // +0x270 (4 B)  Flag: 1 if MCU reset is active, 0 otherwise
    uint32_t                        _pad3;                // +0x274 (4 B)  Structure tail padding
};
```

### Sub-structure: `struct oplus_snshub_platform_data` (48 bytes / `0x30` bytes):
Parsed during `oplus_snshub_probe` from device tree node `<&osh>`:
```c
struct oplus_snshub_platform_data {
    int32_t  gpio_reset;                 // +0x00: TLMM GPIO 64  ("reset-gpio")
    int32_t  gpio_reset_active_low;      // +0x04: Active low flag (1)
    int32_t  gpio_power;                 // +0x08: TLMM GPIO 112 ("power-gpio")
    int32_t  gpio_power_active_low;      // +0x0c: Active high flag (0)
    int32_t  gpio_buck_enable;           // +0x10: TLMM GPIO 33  ("buck-enable-gpio")
    int32_t  gpio_buck_enable_active_low;// +0x14: Active high flag (0)
    int32_t  gpio_ap_suspend;            // +0x18: AP suspend GPIO
    int32_t  gpio_ap_suspend_active_low; // +0x1c: Active low flag
    int32_t  gpio_ap_state;              // +0x20: AP operational state GPIO
    int32_t  gpio_ap_state_active_low;   // +0x24: Active high flag
    int32_t  gpio_dump;                  // +0x28: TLMM GPIO 109 ("dead-gpio" / dump int)
    int32_t  gpio_dump_active_low;       // +0x2c: Active high flag (1)
};
```
