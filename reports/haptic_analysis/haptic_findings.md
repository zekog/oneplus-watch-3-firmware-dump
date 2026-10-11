# Awinic AW86927 Haptic Driver Analysis (`haptic.ko`)

## 1. Executive Summary & Binary Information
- **Binary:** `/home/zek/Pobrane/opw3 firmware/extracted_images/vendor_dlkm_extracted/lib/modules/haptic.ko`
- **Architecture:** AArch64 (ARM 64-bit relocatable Linux kernel module, GKI Linux 5.15)
- **Target Chip:** Awinic AW86927 High-Voltage Haptic Driver / Vibrator (with support for AW869x, AW869xx, AW8671x, and AW8692x families)
- **Decompiled Source:** `/home/zek/Pobrane/opw3-re/haptic_decompiled.c`

---

## 2. Function `input_upload_effect` & Supported Effects

### Location
- **Address:** `0x001228c0` (Symbol: `input_upload_effect`)
- **Companion Playback Function:** `0x00122be8` (`input_playback`)

### Decompiled Pseudo-Code
```c
undefined4 input_upload_effect(struct input_dev *dev, struct ff_effect *effect)
{
  long haptic = *(long *)(dev + 0x2d8);
  short custom_id = 0;
  
  mutex_lock(haptic + 0x2f0);
  short type = effect->type;
  
  if (type == 0x51) { /* FF_PERIODIC */
    unsigned long custom_data_ptr = *(unsigned long *)((char *)effect + 0x28); /* u.periodic.custom_data */
    
    /* Copy 16-bit integer (waveform / effect index) from userspace */
    if (__arch_copy_from_user(&custom_id, custom_data_ptr, 2) != 0) {
      mutex_unlock(haptic + 0x2f0);
      return -EINVAL; /* -22 */
    }
    
    printk("haptic_hv: input_upload_effect: waveform id = %d\n", custom_id);
    
    if ((unsigned int)(custom_id - 1) < 3) {
      /* IDs 1, 2, 3: RAM Waveform Playback Mode */
      *(int *)(haptic + 0x4c) = (int)custom_id;
      *(char *)(haptic + 0x16) = 1; /* Mode 1: RAM mode */
    }
    else if ((custom_id < 5) || ((int)(*(unsigned char *)(haptic + 0x4bc) + 0x1d) < (int)custom_id)) {
      /* ID 4 is reserved/invalid.
         IDs > (0x1D + custom_count) are out of bounds. */
      *(char *)(haptic + 0x16) = 0;
      printk("haptic_hv: input_upload_effect: invalid effect id\n");
      mutex_unlock(haptic + 0x2f0);
      return -EINVAL;
    }
    else {
      /* IDs 5 through (0x1D + custom_count): RTP (Real-Time Playback) Mode */
      *(char *)(haptic + 0x16) = 2; /* Mode 2: RTP mode */
      *(int *)(haptic + 0x98) = (int)custom_id - 4; /* RTP sequence index (0-based) */
    }
  }
  else if (type == 0x52) { /* FF_CONSTANT */
    *(char *)(haptic + 0x16) = 5; /* Mode 5: Constant/Continuous Vibration */
    *(int *)(haptic + 0x4c) = 4;
    *(unsigned int *)(haptic + 0x5c) = (unsigned int)effect->u.constant.level; /* Intensity / Gain */
  }
  else {
    /* All other Force Feedback types rejected */
    printk("haptic_hv: input_upload_effect: unsupported effect type 0x%x\n", type);
    mutex_unlock(haptic + 0x2f0);
    return -EINVAL;
  }
  
  mutex_unlock(haptic + 0x2f0);
  return 0;
}
```

### Supported Effect Types
1. **`FF_PERIODIC` (`0x51`):**
   - Reads a 16-bit waveform ID from `effect->u.periodic.custom_data`.
   - **IDs 1–3:** Triggers **Mode 1 (RAM mode)** to play one of the pre-loaded waveforms stored in AW86927 on-chip SRAM.
   - **IDs 5–`max_seq`:** Triggers **Mode 2 (RTP mode)**, playing RTP waveform sequence index `custom_id - 4`.
   - Out of bounds or ID 4 returns `-EINVAL`.
2. **`FF_CONSTANT` (`0x52`):**
   - Triggers **Mode 5 (Continuous vibration)**.
   - Vibration intensity is configured via `effect->u.constant.level`.
3. **All other FF effect types:** Rejected with `-EINVAL`.

---

## 3. "Haptic Audio" Implementation

### Overview
The `haptic_audio` subsystem enables real-time vibration streaming synchronized with audio playback (e.g. game sound effects, ringtones, or music).

### Key Components & Flow
- **Sysfs Node:** `/sys/class/leds/vibrator/haptic_audio`
- **Store Function:** `haptic_audio_store` (`0x00129b60`)
- **Show Function:** `haptic_audio_show` (`0x00129b24`)
- **Sampling Interval Node:** `/sys/class/leds/vibrator/haptic_audio_time` (`0x00129a24` / `0x00129a90`)

### Operational Protocol
1. **Input Format:** `sscanf(buf, "%d %d %d %d %d %d", &v1, &v2, &v3, &v4, &v5, &v6)`
   - Takes 6 integer arguments per frame representing audio haptic control descriptors and amplitude packets.
2. **Turn-Off Trigger:**
   - If the second integer is `-1` (`cVar3 == -1`), `haptic_audio_store` executes `audio_off(aw_haptic)` (`0x00129ef4`), which cancels active `hrtimer` instances, flushes and frees the audio control queue, and powers down the haptic engine.
3. **Queue & Scheduling:**
   - For valid packets, descriptors are allocated (`kmem_cache_alloc_trace`) and inserted into the linked list `aw_haptic->haptic_audio.list` (`audio_ctrl_list_ins`).
   - If `hrtimer` (`aw_haptic->haptic_audio.timer`) is inactive, it starts with the period configured in `haptic_audio_time` (default microsecond delay).
4. **Timer Handler (`audio_timer_func` @ `0x0012a054`):**
   - Enqueues `audio_work_routine` onto `system_wq` (`queue_work_on(0x20, _system_wq, ...)`).
   - Re-arms `hrtimer_start_range_ns` for continuous streaming.
5. **Work Routine (`audio_work_routine` @ `0x0012a0e0`):**
   - Dequeues audio vibration frames, translates amplitude levels into AW86927 FIFO/gain registers, and streams RTP vibration pulses matching the audio waveform.

---

## 4. Embedded Firmware & Waveform Files (31 `.bin` Files)

All `.bin` waveform files referenced in `haptic.ko` (loaded via kernel `request_firmware`):

### A. Oscillator Calibration & Base SRAM Waveforms
1. `aw86927_haptic_rtp_osc_24K_5s.bin` (24 kHz 5-second oscillator calibration RTP pattern)
2. `aw86927_rtp_3.5_seconds.bin` (3.5-second continuous calibration RTP pattern)
3. `aw86927_haptic_ram.bin` (Base multi-waveform container flashed to AW86927 internal SRAM on boot)

### B. Gaming RTP Effects (Honor of Kings / MOBA Haptics)
4. `aw86927_honor_fisrt_kill_RTP_60.bin` (First kill)
5. `aw86927_honor_two_kill_RTP_61.bin` (Double kill)
6. `aw869274_honor_three_kill_RTP_62.bin` (Triple kill)
7. `aw86927_honor_four_kill_RTP_63.bin` (Quadra kill)
8. `aw86927_honor_five_kill_RTP_64.bin` (Penta kill)
9. `aw86927_honor_three_continu_kill_RTP_65.bin` (Killing spree)
10. `aw86927_honor_four_continu_kill_RTP_66.bin` (Rampage)
11. `aw86927_honor_unstoppable_RTP_67.bin` (Unstoppable)
12. `aw86927_honor_thousands_kill_RTP_68.bin` (Godlike)
13. `aw86927_honor_lengendary_RTP_69.bin` (Legendary)

### C. Alarms & System Notifications
14. `aw86927_alarm1_RTP.bin`
15. `aw86927_alarm2_RTP.bin`
16. `aw86927_alarm3_RTP.bin`
17. `aw86927_alarm4_RTP.bin`
18. `aw86927_msg_clasic_RTP.bin`
19. `aw86927_msg_delight_RTP.bin`
20. `aw86927_msg_health1_RTP.bin`
21. `aw86927_msg_health2_RTP.bin`
22. `aw86927_msg_long1_RTP.bin`
23. `aw86927_msg_long2_RTP.bin`
24. `aw86927_msg_one_RTP.bin`
25. `aw86927_msg_short1_RTP.bin`
26. `aw86927_msg_short2_RTP.bin`
27. `aw86927_msg_short3_RTP.bin`
28. `aw86927_msg_short4_RTP.bin`
29. `aw86927_msg_short5_RTP.bin`
30. `aw86927_msg_short6_RTP.bin`
31. `aw86927_msg_short7_RTP.bin`

---

## 5. Sysfs Attributes Reference

Exposed under `/sys/class/leds/vibrator/`:

| Attribute Name | Mode | Functionality |
| :--- | :--- | :--- |
| `activate` | RW | Start/stop vibrator playback |
| `activate_mode` | RW | Select operation mode (RAM=1, RTP=2, TRIG=3, CONT=5) |
| `duration` | RW | Set vibration duration in milliseconds |
| `state` | RW | Get or set active vibrator power state |
| `index` | RW | Select RAM waveform slot index (1–3) |
| `loop` | RW | Configure waveform playback loop repeat count |
| `seq` | RW | Configure custom playback sequence order |
| `gain` | RW | Global haptic gain / intensity level |
| `vmax` | RW | Set maximum output drive voltage |
| `auto_boost` | RW | Automatic boost voltage management |
| `vbat_monitor` | RW | Monitor battery voltage for dynamic compensation |
| `lra_resistance` | RO | Measured LRA resonant motor voice coil resistance |
| `rtp` | RW | Select and trigger Real-Time Playback sequence ID |
| `haptic_audio` | RW | Stream realtime audio haptic data packets |
| `haptic_audio_time` | RW | Configure audio haptics timer delay period (us) |
| `ram_update` | WO | Trigger reload of RAM firmware from `/vendor/firmware` |
| `ram_num` | RO | Number of waveforms embedded in current SRAM image |
| `ram_f0` | RO | Resonant frequency detected from RAM waveform |
| `ram_cali` | RW | Run calibration against RAM waveform |
| `ram_vbat_comp` | RW | Enable/disable battery compensation in RAM mode |
| `cont` | RW | Start/stop continuous frequency mode |
| `cont_drv` | RW | Continuous drive level |
| `cont_drv_lvl` | RW | Continuous drive voltage level |
| `cont_drv_time` | RW | Continuous drive duration |
| `cont_brk_time` | RW | Active braking duration for sharp stopping |
| `cont_wait_num` | RW | Wait cycles count between bursts |
| `cont_zc_thr` | RW | Zero-crossing detection threshold |
| `cont_td` | RW | Tracking delay parameter |
| `cont_num_brk` | RW | Number of braking pulses |
| `f0` | RO | Current tracked motor resonant frequency (F0) |
| `f0_save` | RW | Save calibrated F0 value to non-volatile storage |
| `cali` | RW | Trigger motor calibration routine |
| `osc_cali` | RW | Trigger oscillator calibration using RTP waveform |
| `osc_save` | RW | Save oscillator calibration results |
| `prctmode` | RW | Over-current / thermal protection mode control |
| `reg` | RW | Direct read/write to AW86927 I2C/SPI registers (debug) |
| `awrw` | RW | Multi-register batch read/write tool |
| `trig` | RW | Hardware trigger pin configuration (Trig 1/2/3) |
| `gun_type` | RW | Gaming weapon recoil haptic preset |
| `bullet_nr` | RW | Gaming burst / bullet count parameter |

---

## 6. Uploading Custom Waveforms

### Can We Upload Custom Waveforms?
**YES.** There are two direct pathways to upload and execute arbitrary custom haptic waveforms:

### Method 1: On-The-Fly SRAM Container Reload (`ram_update`)
1. Place a modified waveform container binary at `/vendor/firmware/aw86927_haptic_ram.bin` (or remount/bind-mount over it).
2. Trigger the kernel loader:
   ```bash
   echo 1 > /sys/class/leds/vibrator/ram_update
   ```
3. `ram_update_store` (`0x001287c8`) calls `request_firmware_nowait(&__this_module, 1, aw_ram_name, ...)`, reading the new file and flashing the waveform tables into the AW86927 SRAM.

### Method 2: RTP Sequence Streaming / Injection
1. Place custom RTP waveform files into `/vendor/firmware/` matching any of the 28 RTP slots.
2. Trigger the playback directly via sysfs:
   ```bash
   echo <seq_id> > /sys/class/leds/vibrator/rtp
   ```
   Or dynamically stream arbitrary real-time waveforms over time via:
   ```bash
   echo "<v1> <v2> <v3> <v4> <v5> <v6>" > /sys/class/leds/vibrator/haptic_audio
   ```
3. Alternatively, standard Linux Force Feedback input events (`ioctl(fd, UI_FF_UPLOAD, &effect)` with `FF_PERIODIC` and custom IDs $\ge 5$) can trigger custom RTP sequences from any userspace process with input device access.
