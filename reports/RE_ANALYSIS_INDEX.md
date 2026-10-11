# Reverse Engineering Analysis Index

This directory contains the complete reverse engineering analysis of the
OnePlus Watch 3 (OPWWE251) firmware, performed using REA + Ghidra.

## Summary of Key Findings

### 1. Bootloader & EDL (xbl_analysis/)
- **Auto-EDL watchdog**: dload_entry_count > 1 triggers EDL (var @ 0x0c29bbb0)
- **FDL via EDL cable**: D+ short to GND triggers "enter forced EDL"
- **FDL via VBUS low**: threshold ~4.25V on PMIC comparator
- **TCSR cookie**: 0x003D3000 |= 1 signals PBL to enter EDL

### 2. ABL / BCB (abl_analysis/)
- ABL reads BCB from misc partition at boot
- Commands: "boot-recovery", "boot-fastboot" (fastbootd)
- Reboot commands: reboot, reboot-bootloader, reboot-recovery, reboot-fastboot

### 3. IPC Protocol (ipc_protocol/)
- **MSPI frame**: CRC16 (2B) + seq (2B) + type (1B) + count (1B) + len (2B) + payload
- **9 channels**: dcc_data (0x01), mcu_factory (0x02), gps_data (0x03),
  std_sns (0x04), dcc_datah (0x07), whs (0x0b), haptic (0x0d),
  audiok (0x0e), audioh (0x10)
- **77 MCU commands** documented
- **Char devices**: /dev/ccch_* (major 153)

### 4. RTOS Analysis (rtos_analysis/)
- **Secure Boot DISABLED** (SEC_BOOT_EN eFuse unblown)
- Custom RTOS firmware possible (only CRC32 + magic 0xBE57EC1C required)
- Bootloader BES2610 does NOT verify cryptographic signatures

### 5. Health Features (health_features/)
- **AFib algorithm exists in RTOS**, region-locked only on Android
- Enable AFib with 16-byte packet to /dev/dcc_data
- 12+ algorithms: sleep, heartrate, activity, sleep_spo2, stress,
  sensor_osa, afib, allday_spo2, breathrate, wrist_temp, altitude,
  baro, run_data, DRV_ECG

### 6. Hardware GPIO (hardware_gpio/)
- **tlmm_gpio_test_pin**: GPIO 64
- **tlmm_total_gpio**: 112
- **MCU reset GPIO**: 64 (10ms pulse)
- **MCU power GPIO**: 112
- **MCU buck enable**: GPIO 33
- **MCU dead pin**: GPIO 109
- **MCU dump pin**: GPIO 1017

### 7. Haptic Analysis (haptic_analysis/)
- AW86927 driver
- 31 waveform .bin files
- Custom waveforms via /sys/class/leds/vibrator/ram_update
- Haptic audio via /sys/class/leds/vibrator/haptic_audio

### 8. Engineer HAL (engineer_hal/)
- setPartionWriteProtectState writes 8 bytes to oplusreserve1 @ 0x42d000
- Value "43008462" = protected, 8 zeros = unprotected
- No PMIC or RPMB - purely software flag

## How to Use This Analysis

This reverse engineering documentation is structured by subsystem to aid developers, modders, and security researchers in understanding the OnePlus Watch 3 architecture:
1. **Unbricking and Low-Level Recovery:** Refer to `xbl_analysis/` and `hardware_gpio/` for emergency download (EDL) triggers, pinouts, and hardware watchdog thresholds.
2. **Boot Flow & Fastbootd:** Refer to `abl_analysis/` for BCB commands and entering `fastbootd` without button combos.
3. **Inter-Processor Communication & Custom Daemons:** Refer to `ipc_protocol/` for channel IDs, packet framing, and character device nodes (`/dev/ccch_*`, `/dev/dcc_data`) to communicate directly with the Bestechnic BES2610 coprocessor.
4. **Custom MCU Firmware & RTOS Hacking:** Refer to `rtos_analysis/` for eFuse configurations, image formats, and flashing protocols.
5. **Feature Activation (AFib & Sensors):** Refer to `health_features/` for the binary packets required to enable dormant health algorithms.
6. **Hardware Control & Vibrations:** Refer to `haptic_analysis/` for custom haptic feedback patterns and `engineer_hal/` for partition write-protection toggling.

## Files

### `xbl_analysis/`
- `xbl_findings.md`: Analysis of Qualcomm secondary bootloader (XBL), boot counters, and auto-EDL watchdog.
- `fedl_findings.md`: PMIC and USB D+/D- forced EDL detection mechanisms and VBUS voltage thresholds.

### `abl_analysis/`
- `abl_findings.md`: Analysis of Android Bootloader (ABL/LinuxLoader.efi), BCB parsing from the `misc` partition, and reboot handling.

### `hardware_gpio/`
- `devcfg_findings.md`: Qualcomm device configuration (devcfg) GPIO mapping, test pins, and MCU control lines.

### `ipc_protocol/`
- `oplus_comm_master_findings.md`: Inter-chip communication driver (`oplus_comm_master.ko`), SPI transport layer, state machine, and channel demultiplexing.
- `oplus_snshub_findings.md`: Sensor hub driver (`oplus_snshub.ko`), power management, uevents, and reset handling.
- `bes2610_findings.md`: BES2610 MSPI driver, Wi-Fi/BT FullMAC commands, and host sleep signaling.
- `transfer_findings.md`: HIDL Transfer HAL service (`vendor.oplus.hardware.transfer@1.0.so`) and diagnostic socket bridges.

### `rtos_analysis/`
- `rtos_whs_findings.md`: RTOS memory layout, Wearable Health Service (`whs`) channel, algorithm dispatch tables, and execution flow.
- `programmer_findings.md`: Flashing programmer binary, Secure Boot eFuse verification, and header magic parsing.

### `health_features/`
- `dcc_command_21_findings.md`: Reverse engineering of `APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW` (Command 21), AFib switch, packet structures, and userspace access.
- `whs_handler_findings.md`: Dispatcher routines and algorithm management for 12+ health algorithms in RTOS.

### `haptic_analysis/`
- `haptic_findings.md`: AW86927 haptic motor driver, RAM waveform updates, and RTP audio-to-haptics streaming.

### `engineer_hal/`
- `engineer_so_findings.md`: Partition write protect implementation in `vendor.oplus.hardware.engineer@1.0.so` and `oplusreserve1` storage offset.

### Decompiled Sources (`reports/*.c`)
- `abl_decompiled.c`: Decompiled routines from ABL (LinuxLoader.efi).
- `bes2610_decompiled.c`: Decompiled MSPI and command exchange routines from `bes2610.ko`.
- `ghidra_decompiled.c`: Selected decompiled functions from initial XBL exploration.
- `haptic_decompiled.c`: AW86927 driver decompiled routines from `haptic.ko`.
- `libmcuupdater_decompiled.c`: MCU firmware update protocol from `libmcuupdater.so`.
- `oplus_comm_master_decompiled.c`: Driver decompilation of `oplus_comm_master.ko`.
- `oplus_snshub_decompiled.c`: Driver decompilation of `oplus_snshub.ko`.
- `programmer_decompiled.c`: Decompiled eFuse and flashing routines from `programmer.bin`.

## Important Notes

- These findings are for educational and interoperability purposes.
- Modifying the device voids warranty.
- Unlocking the bootloader disables Google Wallet.
- Use the OFP package for recovery via EDL.
