# RTOS Firmware Analysis: Wearable Health Service (WHS) & Algorithms

**Target Binary:** `/home/zek/Pobrane/opw3 firmware/mcu_firmware/OPWWE251/OPWWE251_M55C0_2505201801.bin`  
**Architecture:** ARM Cortex-M55 (ARMv8.1-M Mainline, Thumb-2, Little-Endian)  
**Binary Size:** 6,648,680 bytes (~6.65 MB)  
**Header:** Bestechnic Boot Magic `0xBE57EC1C`, Build Tag `OPWWE251_M55C0`, Date `2505201801`  
**Base Address:** `0x10100000`  
**RAM Region:** `0x20100000` – `0x20180000` (Stack MSP: `0x2017ffe0`, MSPLIM: `0x2017dfe0`)

---

## 1. Binary Architecture & Memory Layout

### Base Address Determination (`0x10100000`)
The binary starts with a 256-byte (`0x100`) Bestechnic image header followed by the entry point trampoline at offset `0x100` (`0x10100100`):

```armasm
10100100:  ldr   r0, [pc, #68]   ; loads 0x10100105 from 0x10100148
10100102:  bx    r0              ; jumps to 0x10100104
10100104:  bl    0x10101c30
10100108:  bl    0x1019bd44
1010010c:  ldr   r0, [pc, #60]   ; loads 0x2017ffe0 (MSP Stack Pointer)
1010010e:  msr   MSP, r0
10100112:  ldr   r0, [pc, #60]   ; loads 0x2017dfe0 (Stack Limit MSPLIM)
10100114:  msr   MSPLIM, r0
10100118:  movs  r0, #0
1010011a:  msr   CONTROL, r0
1010011e:  isb   sy
...
1010012e:  ldr   r1, [pc, #36]   ; Data Flash Source: 0x107411d4
10100130:  ldr   r2, [pc, #36]   ; Data RAM Start:    0x2010de48
10100132:  ldr   r3, [pc, #40]   ; Data RAM End:      0x20123db0
10100134:  cmp   r2, r3          ; Copies .data to SRAM
10100142:  bl    0x1013c338      ; Enters RTOS kernel main()
```

---

## 2. Health & Sensor Keywords Search

| Keyword | Matches | Key Identifiers & Findings |
| :--- | :---: | :--- |
| **`heart`** | **57** | `heart_rate_app`, `heart_rate_srv`, `heart_rate_notify_app`, `heart_rate_atrial_fibrillation_app` (`0x105ceb38`), `heart atrial fibrillation` (`0x105df2bc`), `health.heartrate` (`0x1066eecc`), `gh-h value:%d,%d,%d-%d`. |
| **`ppg`** | **258** | `PPG_RAW_G0/G1`, `PPG_IR0..IR4`, `PPG_R0..R4`, `MMI_PPG`, `DRV_PPG`, Goodix/Sensortek PPG AFE control. |
| **`ecg`** | **17** | `MMI_ECG`, `DRV_ECG`, `ecg_control ctrl status = %d` (`0x10615bbc`), `ecg_control avdd_pin / ctrl_pin / amp_pin / pad_apm` (`0x10640ee0`), `ecg_dcc send, status=%d, ts=%lld` (`0x1065e3b0`). |
| **`wrist_temp`**| **34** | `wrist_temperature_app` (`0x105df9a0`), `wrist_temp_srv`, `wrist_temp_impl_read cmd = %d` (`0x1065d27c`), `wrist_temp_main_process input length err:%d` (`0x10668f98`), ID 11 `wrist_temp` in `hisdata_db` (`0x1067cab8`). |
| **`step`** | **64** | `act_step_completed`, `statusChangeStep`, `gh-st%d`, `gh-min-st:%d`, `APP_MCU_SET_STEP_GOAL = %d`. |
| **`whs`** | **49** | Channel name `whs` (`0x10671380`), `services/oplus_whs/src/data_adapter/oplus_whs_sport_adapt.c`, `oplus_whs_service_task start` (`0x10682e74`), `whs_handler` (`0x10682e94`), `oplus_whs_handler` (`0x10682edc`), `oplus_whs_bc_recver` (`0x10682ec8`). |
| **`afib`** | **4** | `health.afib` (`0x1066eee0`), `afib:%d` (`0x1066f3f8`), ID 6 `afib` in `hisdata_db` (`0x1067c9e0`), `HEALTH4 AFIB` (`0x106d8ea9`), `APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW` (`0x1065ff6c`). |

---

## 3. WHS Channel (`channel_id = 0x0b`) Handling & Dispatch Architecture

Channel `0x0b` (`whs` - Wearable Health Service) is the bidirectional inter-core communication conduit between the Snapdragon AP (running Android Wear OS Google Health Services / OPlus Health) and the BES2610 Cortex-M55 RTOS.

### A. Channel Registration Table (`0x107462ec`)
Registered in the RTOS Data Communication Channel (DCC) descriptor array:
- `+0x00` (`0x1039d975`): `oplus_whs_bc_recver` (Broadcast receiver handler)
- `+0x04` (`0x10682ec8`): String `"oplus_whs_bc_recver"`
- `+0x0c` (`0x1039da75`): `oplus_whs_handler` (Direct command packet handler)
- `+0x10` (`0x10682edc`): String `"oplus_whs_handler"`
- `+0x1c` (`0x1039f62d`): `transmit_handler` / `oplus_whs_dcc_transmit_data_put`

### B. Packet Header Structure
When a packet arrives over channel `0x0b`:
```
+0x00               +0x04               +0x08               +0x0c               +0x10
+-------------------+-------------------+-------------------+-------------------+-------------------------+
| Channel ID (2B)   | Sub-type / Seq    | Message ID (4B)   | Payload Size (4B) | Payload Data Pointer    |
+-------------------+-------------------+-------------------+-------------------+-------------------------+
```

### C. Packet Dispatch Mechanism (`oplus_whs_handler` @ `0x1039da74`)
```armasm
1039da74:  cbz    r0, 0x1039dac0         ; NULL packet check
1039da7c:  ldr    r4, [r0, #8]           ; Load Message ID
1039da80:  ldrd   r1, r5, [r0, #12]      ; r1 = payload size, r5 = payload data pointer
1039da84:  ubfx   r4, r4, #0, #30        ; Mask msgid to lower 30 bits
; Logging: "whs_handler: msgid:%d, data:%p, size:%d"
1039da9a:  cmp    r4, #1                 ; MSGID 1: Health Tracking / Sampling Control
1039da9c:  beq.n  0x1039dab4             ; -> calls 0x1039e6a0(data)
1039da9e:  cmp    r4, #2                 ; MSGID 2: Sport / Session Control
1039daa0:  beq.n  0x1039daa8             ; -> calls 0x1039bff8(data)
```

#### Message ID 1: Health Tracking Subcommand Dispatch (`0x1039e6a0`)
Executes a 27-case branch table (`tbh [pc, r3, lsl #1]` at `0x1039e6f4`):
- `Subcommand 0`: Heart rate continuous track start / stop (`p_s%u %u %u %u %u`)
- `Subcommand 1`: Step counting & activity monitoring
- `Subcommand 2`: Calorie expenditure estimation
- `Subcommand 3`: Distance calculation
- `Subcommand 4`: Elevation gain & floor climbing
- `Subcommand 5`: SpO2 continuous sample / spot check
- `Subcommand 6`: Stress / HRV sampling
- `Subcommand 7`: Skin/Wrist temperature stream
- Subcommands `8`–`26`: Custom tracking types, historical batch flush (`gh flush`), sensor configuration (`reset data_type`).

#### Broadcast Message Dispatch (`oplus_whs_bc_recver` @ `0x1039d974`)
- Log: `"whs_dc: msgid:%d, data:%p, size:%d"`
- `msgid == 1003` (`0x3eb`): Power/thermal event notification (`0x1039e0c8(data)`)
- `msgid == 1092` (`0x444`): Activity transition / sport status notification (`0x1039a644(data)`)

---

## 4. Available Health Algorithms & Engine Table

Health algorithms are registered centrally in the `hisdata_db` engine by `hisdata_config_init` (`0x1038e8fc`).

### The 15 Algorithm Descriptors (`0x1067c950`)
Each entry is 36 bytes (`0x24` stride):
`struct hisdata_algo { uint32_t id; char name[16]; uint32_t interval; uint32_t flags; uint32_t buf_count; uint32_t status; };`

| ID | String Name | Subsystem / Algorithm Purpose | Interval / Flags |
| :---: | :--- | :--- | :---: |
| **0** | `sleep` | Nocturnal sleep staging (Light, Deep, REM, Awake) | `0x01` / `0x1f` |
| **1** | `heartrate` | Optical PPG Heart Rate monitoring (BPM) | `0x06` / `0x1f` |
| **2** | `activity` | Pedometer, cadence, motion recognition (walk/run/cycle) | `0x0c` / `0x1f` |
| **3** | `sleep_spo2` | Nocturnal SpO2 sampling | `0x3c` (60s) / `0x1f` |
| **4** | `stress` | HRV (Heart Rate Variability) & Mental Stress | `0x0c` / `0x1f` |
| **5** | `sensor_osa` | Obstructive Sleep Apnea monitoring (Oxygen drops) | `0x04` / `0x1f` |
| **6** | `afib` | **Atrial Fibrillation / Irregular Heart Rhythm Detection** | `0x02` / `0x1f` |
| **7** | `allday_spo2` | 24/7 background Blood Oxygen monitoring | `0x78` (120s) / `0x1f` |
| **8** | `breathrate` | Sleep respiratory rate estimation from PPG respiratory sinus | `0x04` / `0x1f` |
| **9** | `altitude` | Barometric relative elevation gain | `0x04` / `0x02` |
| **10**| `baro` | Raw atmospheric pressure filtering | `0x04` / `0x02` |
| **11**| `wrist_temp` | Skin / wrist temperature sensor reading with ambient comp | `0x04` / `0x1f` |
| **12**| `run_data` | Running dynamics (ground contact time, vertical oscillation) | `0x04` / `0x3c` |
| **13**| `test_kv` | Diagnostic NVRAM test entry | `0x04` / `0x1e` |
| **14**| `test_array` | Diagnostic array buffer entry | `0x04` / `0x1e` |

### Dedicated Hardware Sensor Subsystems:
* **ECG Hardware Subsystem (`DRV_ECG`):**
  - Drivers: `flex_spi_init`, `ecg_control` (`0x10615bbc`), `oplus_afe_pin_t`.
  - Communication: `ecg_dcc` exchange channel (`ecg_dcc recv, get ecg status`, `ecg_dcc send, status=%d, ts=%lld`).
* **Pulse Transit & Blood Pressure Period (`health_rr_algo` @ `0x1051e3f0`):**
  - Logs: `from BP algo: [%d,%d,%d] [%d,%d]`, `BP nst: %d`.

---

## 5. Region Locking & Certificate Verification Analysis

### A. Binary Examination for Restrictions
A deep string and symbol inspection was conducted for compliance, DRM, and regional restrictions:
- `certificate`: **0 matches** (only external `akm_err certification denied` in 3rd party AKM compass library).
- `license`: **0 matches**.
- `region` / `country`: **0 regulatory checks** inside the RTOS binary.
- `fda` / `ce_cert` / `mdr` (medical device regulations): **0 occurrences**.

### B. Architectural Finding: Zero RTOS-Level Gating
1. **No cryptographic signatures, region tokens, or license certificates are verified on the BES2610 MCU.**
2. Health features are exposed as raw hardware algorithms and switches to the host Snapdragon W5 AP.
3. Feature gating (e.g., FDA/CE approval for ECG and AFib notifications based on SIM country or geofence) is implemented **exclusively in Android userspace** (`com.google.android.wearable.healthservices` and `com.heytap.wearable.health`).
4. When the Android layer determines that a feature is permitted, it simply writes a 1-byte enable flag over IPC/KV or dispatches the `start tracking` message on WHS channel `0x0b`.

---

## 6. AFib (Atrial Fibrillation) Detection Code

### A. Control Switch & IPC Command
The AP turns AFib / Irregular Heart Rhythm detection on or off via command ID `21`:
- **Command:** `APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW` (`0x1065ff6c`)
- **Handler (`0x1031fbde`):**
```armasm
1031fbde:  movs   r2, #8
1031fbe0:  movs   r0, #21                ; Command ID 21 (Irregular HR Warning Switch)
1031fbe2:  add    r1, sp, #232
1031fbe4:  bl     0x1031f6b4             ; Reads current setting from KV storage
1031fbe8:  ldr    r3, [sp, #28]          ; r3 = incoming switch value (0 or 1)
1031fbea:  ldr    r2, [sp, #232]
1031fbec:  cmp    r3, r2                 ; Has switch state changed?
1031fbee:  beq.w   0x1031ff06
1031fbf2:  str    r3, [sp, #232]         ; Store updated state in memory
1031fbf4:  bl     0x102dd2e4             ; Commit updated state to Flash KV
; Log: "APP_MCU_SET_FC_IRREGULARY_HEART_WARN_SW = %d"
```

### B. Persistent Feature Flag in KV NVRAM
- Identified at `0x1035ac14`: Pointer `0x1066eee0` -> `"health.afib"`.
- Associated flags in the capability manager: `"health.heartrate"`, `"health.afib"`, `"health.spo2"`, `"health.osa"`.

### C. Detection Engine & RR Interval Processing
1. **Beat-to-Beat Interval Generation (`health_rr_algo` @ `0x1051e3f0`):**
   - Optical PPG pulses are filtered to produce high-precision R-R peak intervals (Pulse Peak Intervals / PPI) via the Beat Period (`BP`) algorithm.
   - Evaluates consecutive interval variations (`from BP algo: [%d,%d,%d] [%d,%d]`).
2. **Historical Data Recording (`hisdata_db` Descriptor 6):**
   - Record name: `"afib"` (`0x1067c9e0`).
   - Flags: `0x1f` (active monitoring window).
   - Interval: `0x02` (processes two-second sliding windows of pulse intervals to compute Shannon rhythm entropy and Poincaré scatter).
3. **Notification & UI Surface:**
   - App registration: `heart_rate_atrial_fibrillation_app` (`0x105ceb38`) with display label `"heart atrial fibrillation"` (`0x105df2bc`), registered into launcher via `0x101d71b0`.
   - When irregular rhythm episodes exceed the threshold window, the MCU transmits an alert packet back over channel `0x0b` to wake the host and alert the user.
