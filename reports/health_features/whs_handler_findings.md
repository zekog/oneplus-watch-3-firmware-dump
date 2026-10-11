### Summary of Findings: Bestechnic BES2610 RTOS Firmware Analysis

**Binary:** [`OPWWE251_M55C0_2505201801.bin`](file:///home/zek/Pobrane/opw3%20firmware/mcu_firmware/OPWWE251/OPWWE251_M55C0_2505201801.bin)  
**Architecture:** ARM Cortex-M55 (ARMv8.1-M Mainline, Thumb-2, Little-Endian)  
**Base Address:** **`0x10100000`** *(Verified: Header is 256 bytes `0x00`–`0xff`; reset trampoline at `0x10100100` loads MSP `0x2017ffe0`, MSPLIM `0x2017dfe0`, and copies Flash data `0x107411d4` $\to$ SRAM `0x2010de48`)*.  
**Report File:** Saved to [`/home/zek/Pobrane/opw3-re/rtos_whs_findings.md`](file:///home/zek/Pobrane/opw3-re/rtos_whs_findings.md).

---

### 1. Keyword String Search Results

* **`"heart"` (57 matches):** `heart_rate_app`, `heart_rate_srv`, `heart_rate_notify_app`, `heart_rate_atrial_fibrillation_app` (`0x105ceb38`), `heart atrial fibrillation` (`0x105df2bc`), `health.heartrate` (`0x1066eecc`), `gh-h value:%d,%d,%d-%d`.
* **`"ppg"` (258 matches):** `PPG_RAW_G0/G1`, `PPG_IR0..IR4`, `PPG_R0..R4`, `MMI_PPG`, `DRV_PPG`, Goodix / Sensortek optical AFE drivers.
* **`"ecg"` (17 matches):** `MMI_ECG`, `DRV_ECG`, `ecg_control ctrl status = %d` (`0x10615bbc`), `ecg_control avdd_pin / ctrl_pin / amp_pin / pad_apm` (`0x10640ee0`), `ecg_dcc send, status=%d, ts=%lld` (`0x1065e3b0`).
* **`"wrist_temp"` (34 matches):** `wrist_temperature_app` (`0x105df9a0`), `wrist_temp_srv`, `wrist_temp_impl_read cmd = %d` (`0x1065d27c`), `wrist_temp_main_process input length err:%d` (`0x10668f98`), ID 11 `wrist_temp` in `hisdata_db` (`0x1067cab8`).
* **`"step"` (64 matches):** `act_step_completed`, `statusChangeStep`, `gh-st%d`, `gh-min-st:%d`, `APP_MCU_SET_STEP_GOAL = %d`.
* **`"whs"` (49 matches):** Channel name `whs` (`0x10671380`), `oplus_whs_service_task start` (`0x10682e74`), `whs_handler` (`0x10682e94`), `oplus_whs_handler` (`0x10682edc`), `oplus_whs_bc_recver` (`0x10682ec8`).

---

### 2. WHS Channel (`channel_id = 0x0b`) Handling & Dispatch

The Wearable Health Service channel `0x0b` (`whs`) is registered in the DCC communication table at `0x107462ec`:
* **Direct Handler:** `oplus_whs_handler` (`0x1039da74`)
* **Broadcast Receiver:** `oplus_whs_bc_recver` (`0x1039d974`)
* **Task Entry:** `oplus_whs_service_task` (`0x1039d9ec`)
* **Transmit Output:** `oplus_whs_dcc_transmit_data_put` (`0x1039f884`)

#### Packet Dispatch Flow:
1. `oplus_whs_handler` (`0x1039da74`) unpacks the packet header:
   * `msgid = (pkt[8] & 0x3fffffff)`
   * `size = pkt[12]`
   * `data = pkt[16]`
2. **`msgid == 1`:** Calls `0x1039e6a0` (Google Health / WHS tracking control). It uses a 27-way jump table (`tbh [pc, r3, lsl #1]` at `0x1039e6f4`) to dispatch:
   * DataType `0x00040001` $\to$ `DataType.HEART_RATE_BPM`
   * DataType `0x00000001` $\to$ `DataType.STEPS_TOTAL`
   * DataType `0x00005010` $\to$ `DataType.CALORIES_TOTAL`
   * DataType `0x00000003` $\to$ `DataType.DISTANCE_TOTAL`
   * DataType `0x00000002` $\to$ `DataType.ELEVATION_GAIN_TOTAL`
   * DataType `0x00000006` $\to$ `DataType.FLOORS_TOTAL`
   * DataType `0x00040003` $\to$ `DataType.HEART_RATE_ACCURACY`
3. **`msgid == 2`:** Calls `0x1039bff8` (Sport & session state tracker).
4. `oplus_whs_bc_recver` (`0x1039d974`) routes broadcast events:
   * `msgid == 1003` (`0x3eb`) $\to$ power/thermal event (`0x1039e0c8`)
   * `msgid == 1092` (`0x444`) $\to$ activity transition (`0x1039a644`)

---

### 3. Available Health Algorithms

Registered centrally in `hisdata_db` via `hisdata_config_init` (`0x1038e8fc`) with 36-byte descriptors at `0x1067c950`:

| ID | Name | Function / Purpose |
| :---: | :--- | :--- |
| **0** | `sleep` | Nocturnal sleep stage classification (Light, Deep, REM, Awake) |
| **1** | `heartrate` | Continuous PPG optical heart rate monitoring |
| **2** | `activity` | 3D accelerometer step counting, cadence, and activity recognition |
| **3** | `sleep_spo2` | Nocturnal SpO2 pulse oximetry |
| **4** | `stress` | HRV (Heart Rate Variability) spectral mental stress estimation |
| **5** | `sensor_osa` | Obstructive Sleep Apnea monitoring (SpO2 drops + respiratory dips) |
| **6** | `afib` | **Atrial Fibrillation / Irregular Heart Rhythm Detection** |
| **7** | `allday_spo2` | 24/7 background blood oxygen monitoring |
| **8** | `breathrate` | Sleep respiratory rate from PPG respiratory sinus arrhythmia |
| **9** | `altitude` | Barometric relative elevation gain |
| **10**| `baro` | Atmospheric pressure filtering |
| **11**| `wrist_temp` | Contact skin/wrist temperature sensor reading with ambient compensation |
| **12**| `run_data` | Advanced running dynamics (ground contact, vertical oscillation) |
| **—** | `DRV_ECG` | **Hardware Single-Lead ECG** (`ecg_control`, `ecg_dcc`) |

---

### 4. Region Locking & Certificate Checks

* **Result: NO cryptographic certificates, signatures, or regional locks exist in the RTOS binary.**
* **Mechanism:**
  * The MCU RTOS exposes raw feature flags stored in Key-Value (KV) Flash storage (`health.afib`, `health.spo2`, `health.osa`, `health.heartrate`).
  * The Android host (Snapdragon W5 AP) handles all regulatory / geographical restrictions in user-space (`com.heytap.wearable.health` / Android framework) based on SIM country code or geo-location.
  * When allowed by Android, the host simply sends an IPC command (`APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW`) or sets the KV flag over DCC to enable the feature on the MCU.

---

### 5. AFib (Atrial Fibrillation) Detection Code

* **Host IPC Switch:** Handled at `0x1031fbe0` by command `APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW = %d` (Command ID `21` at `0x1065ff6c`).
* **Feature Flag:** Stored in persistent KV memory as `"health.afib"` (`0x1066eee0`, referenced at `0x1035ac14`).
* **Algorithm Registration:** Engine descriptor `6` (`"afib"`, `0x1067c9e0` in `hisdata_db`) operates on a 2-second sliding window (`0x02` interval, `0x1f` flags).
* **Beat-to-Beat Interval Analysis:** `health_rr_algo` (`0x1051e3f0`, string `0x1070dcf5`) processes PPG Pulse Peak Intervals (PPI / RR) from the Beat Period engine (`from BP algo: [%d,%d,%d] [%d,%d]`). It tracks rhythm entropy and interval dispersion to detect irregular rhythms indicative of AFib.
* **Notification & UI Surface:** Registered as `heart_rate_atrial_fibrillation_app` (`0x105ceb38`) with display label `"heart atrial fibrillation"` (`0x105df2bc`) at `0x101d71b0`. Exceeding the irregular window threshold generates an alert packet to wake the host.