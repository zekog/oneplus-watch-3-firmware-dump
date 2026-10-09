# OnePlus Watch 3 (OPWWE251) - DTS Hardware Mapping & Peripheral Architecture

This document maps physical hardware peripherals and controllers extracted from the Device Tree Sources (`monaco_base_soc.dts` and `dtbo_overlay_00.dts` through `dtbo_overlay_09.dts`).

---

## 1. Platform Summary

- **Device Model:** OnePlus Watch 3 (OPWWE251)
- **Primary SoC:** Qualcomm Snapdragon W5+ Gen 1 (Architecture: "monaco", SW5100 / SDA5100)
- **Co-Processor / RTOS MCU:** Bestechnic BES2610 (Dual-core ARM Cortex-M55 + low-power subsystem)
- **PMIC:** Qualcomm PM5100 (SPMI Bus)
- **Display Resolution:** 466 x 466 AMOLED (`0x1d2` x `0x1d2`)

---

## 2. Touchscreen Subsystem (Dual-Sourced)

The OnePlus Watch 3 features a dual-sourced touchscreen configuration supported via two dynamic vendor drivers. Pin multiplexing and interrupts are shared.

| Hardware Controller | Compatible String | Bus / Address | IRQ GPIO | Reset GPIO | Resolution | Vendor Module |
|---|---|---|---|---|---|---|
| **FocalTech Touch** | `focaltech,fts` | I2C (`&qupv3_se1_i2c`) @ `0x38` | TLMM GPIO 13 (`0x0d`) | TLMM GPIO 12 (`0x0c`) | 466 x 466 (`0x1d2`) | `focaltech_fts.ko` |
| **Zinitix Touch** | `zinitix,bt541_ts_device` | I2C (`&qupv3_se1_i2c`) @ `0x20` | TLMM GPIO 13 (`0x0d`) | TLMM GPIO 12 (`0x0c`) | 466 x 466 (`0x1d2`) | `zinitix.ko` |
| **Parade Core Adapter** | `parade,pt_i2c_adapter` | I2C (`&qupv3_se1_i2c`) @ `0x24` | TLMM GPIO 80 (`0x50`) | - | - | Built-in / In-tree |

### Power Supplies & Pin Control
- **Digital VDD (1.8V):** `tp_vdd_1v8`
- **Analog VDD (3.0V):** `tp_vdd_3v0`
- **Bus Pull-up:** `&L21A`
- **Pinctrl States:** `pmx_ts_active`, `pmx_ts_suspend`, `pmx_ts_release`

---

## 3. Display & Panel Subsystem

- **DRM Driver:** `msm_drm.ko` (Qualcomm Mobile Display Subsystem - MDSS / DSI)
- **Notification Interface:** `panel_event_notifier.ko`

| Panel Controller | Node Label / Model | Type | Bus Interface | Features |
|---|---|---|---|---|
| **Chipone ICNA3311** | `qcom,mdss_dsi_icna3311_amoled_143_cmd` | 1.43" AMOLED (466x466) | MIPI DSI (1 Data Lane) | DSI Command Mode, TE Pin sync, Burst mode |
| **Chipone ICNA3311 v2** | `qcom,mdss_dsi_icna3311_amoled_143_v2_cmd`| 1.43" AMOLED (466x466) | MIPI DSI (1 Data Lane) | Updated revision command mode |
| **FocalTech FT2390** | `qcom,mdss_dsi_ft2390_amoled_1502_cmd` | 1.502" AMOLED | MIPI DSI (1 Data Lane) | Extended size AMOLED variant |

### Display Controls
- **Power Control:** `qcom,platform-vci3p3-en-gpio` (via TLMM)
- **TE (Tearing Effect):** `qcom,platform-te-gpio`

---

## 4. Rotary Crown Input Subsystem (Encoder)

The physical rotating crown is handled by optical motion tracking sensors driven by `oplus_crown.ko`. Dual-sourcing support exists across hardware revisions:

| Sensor Component | Compatible String | I2C Address | Interrupt GPIO | Status in Final Overlay |
|---|---|---|---|---|
| **Mixosense MOT6010** | `mixosense,mot6010` | `0x74` | TLMM GPIO 56 (`0x38`) | `okay` (Default active in Overlay 09) |
| **PixArt PAT9125** | `pixart,pat9125` | `0x75` | TLMM GPIO 56 (`0x38`) | `disabled` (Supported alternate) |

### Crown Driver Attributes
- **Module:** `oplus_crown.ko`
- **Interrupt States:** `oplus_crown_int_active`, `oplus_crown_int_suspend`, `oplus_crown_int_release`
- **Custom Properties:** `oplus_crown,notify_id`, `oplus_crown,force_init`, `oplus_crown,default_init`

---

## 5. RTOS Co-Processor / MCU Interconnect (BES2610)

The ultra-low power co-processor is a **Bestechnic BES2610** (previously misidentified as BES2800). It manages always-on watch faces, continuous background sensor polling, and power management handoffs.

- **DTS Node:** `bes_wlan: slave@0`
- **Compatible String:** `bes2610,master_spi`
- **SPI Maximum Frequency:** 48 MHz (`0x2dc6c00`)
- **SPI Word Size:** 32 bits (`0x20`)
- **Kernel Drivers:** `bes2610.ko`, `besbev_dlkm.ko`, `besbev-slave_dlkm.ko`

### Hardware GPIO Handshake Lines
- **WIFI/MCU Power Enable:** TLMM GPIO 27 (`0x1b`)
- **Slave RX Ready:** TLMM GPIO 74 (`0x4a`)
- **Slave TX Ready:** TLMM GPIO 75 (`0x4b`)
- **Master TX Indication:** TLMM GPIO 26 (`0x1a`)
- **Master CRC OK:** TLMM GPIO 6 (`0x06`)
- **Slave CRC OK:** TLMM GPIO 82 (`0x52`)
- **Master-to-Slave / Slave-to-Master Interrupts:** `m2s_int_gpio`, `s2m_ans_gpio`, `s2m_int_gpio`, `m2s_ans_gpio`

---

## 6. Power Management, PMIC & Battery

- **PMIC:** Qualcomm PM5100 over SPMI (`pm5100@0`)
- **Charger Driver:** `qpnp-smblite-main.ko` (`qcom,qpnp-pm5100-smblite`)
- **Fuel Gauge / Battery:** `qti-qbg-main.ko` (`qcom,qbg`)
- **Low Power Mode:** `qti-pmic-lpm.ko`
- **Real-Time Clock:** `qcom,pm5100-rtc`

### SPMI ADC (VADC) Thermistor Channels
- `pm5100_die_temp`: Internal PMIC die temperature
- `pm5100_xo_therm`: Crystal oscillator thermistor
- `pm5100_bat_therm`: Battery pack thermistor
- `pm5100_msm_therm`: Qualcomm SoC thermistor
- `pm5100_chg_temp`: Charger IC temperature
- `pm5100_vbat_sns`: Battery voltage sense line

---

## 7. Sensors & Sensor Hub Architecture

- **Sensor Hub:** `oplus,sensor-hub` (driven by `oplus_snshub.ko` in `vendor_boot`)
- **Qualcomm Sensors Core:** `qcom,qmi-sensors` (driven by `qti_qmi_sensor.ko`)
- **Health PPG / AFE:** `pmw5100-spmi_dlkm.ko` (PixArt / SPMI optical heart rate & SpO2 front-end)
- **Haptics:** `haptic.ko` (LRA motor driver)
