# EDL Recovery Notes - OnePlus Watch 3 (OPWWE251)

## Problem Statement

The OnePlus Watch 3 (OPWWE251) is water-resistant (5ATM rating). Opening the case to access physical PCB EDL test points permanently destroys the water-tight adhesive gasket seal, with no consumer-accessible method to re-certify or restore water resistance. 

Therefore, finding a **non-destructive, software- or cable-based unbricking entry method** into Qualcomm Emergency Download Mode (EDL / 9008) is critical for recovery and development.

---

## Known Software EDL Vectors

### 1. ADB (Requires Booted Android / Wear OS)
```bash
adb reboot edl
```
* Status: Standard mechanism, but unavailable if boot partitions (`boot`, `init_boot`, `vendor_boot`) are corrupted.

### 2. Fastboot (Requires Functional ABL)
```bash
fastboot oem edl
fastboot oem enter-edl
```
* Analysis of extracted `abl.elf` (`LinuxLoader` PE32) confirms standard Qualcomm recovery handler `WriteRecoveryMessageEdl`, though public OEM command availability is restricted.

### 3. XBL Forced EDL (Early Bootloader Failsafe)
`xbl.elf` automatically invokes `enter forced EDL` when any of the following hardware conditions occur:
- PMIC not detected (`fedl, pmi_not_detected`)
- VBUS detection error (`fedl, vbus_det_err`)
- VBUS voltage too low (`fedl, vbus_low`) – **highly promising vector**
- Charger detection error (`fedl, chgr_type_det_err`)
- Charger detection timeout (`fedl, chgr_det_timeout`)
- Failed boot counter exceeds threshold (`EDL: sbl1_dload_entry: dload_entry_count > 1`)

### 4. Confirmed Empirical Vector (2026-10-09)
- `fastboot oem edl` works directly on OPWWE251 from fastboot mode
- Device enters EDL and enumerates as `05c6:9008` (Qualcomm, Inc. Gobi Wireless Modem QDL mode)
- Auto-timeout: **~10 seconds** without host traffic
- Auto-reboot to system after timeout (failsafe verified)

---

## Exploitation Ideas & Recovery Strategies

### 1. VBUS Low Method (Most Promising Non-Destructive Vector)
* **Concept:** Construct a modified USB charging cable or power delivery jig utilizing a precision potentiometer / voltage divider to drop the 5.0V VBUS line down to the margin where USB is detected but falls under the minimum operational threshold (`fedl, vbus_low`).
* **Requirement:** Reverse-engineer `xbl.elf` in Ghidra to determine the exact millivolt ADC reading that triggers `fedl, vbus_low`.

### 2. Failed Boot Counter (`dload_entry_count > 1`)
* **Concept:** Qualcomm SBL1/XBL tracks failed boot attempts via non-volatile cookies or persistent memory (`DloadCookieAddr = 0x003D3000`, `DloadCookieValue = 0x10`).
* If boot is interrupted or fails `> 1` times, XBL falls back to DLOAD / emergency download mode automatically.

### 3. Hardware Test Point Grounding (DESTRUCTIVE)
* Grounding `tlmm_gpio_test_pin` to GND during early boot forces Qualcomm Primary Boot ROM into EDL mode (Qualcomm HS-USB QDLoader 9008).
* **Warning:** Requires disassembling the chassis and permanently voids 5ATM water ingress protection.

---

## Technical Action Items (TODO)

- [x] Unpack UEFI Firmware Volume from `abl.elf` and extract `LinuxLoader` PE32 binary
- [x] Index and catalog all EDL and bootloader strings in `reports/xbl_interesting_strings.txt`
- [x] Confirm DLOAD cookies (`DloadCookieAddr = 0x003D3000`, `Value = 0x10`)
- [ ] Ghidra analysis of `xbl.elf` - locate exact `enter forced EDL` subroutine
- [ ] Read `tlmm_gpio_test_pin` numeric index from `devcfg_msm_ddr.mbn` binary section
- [ ] Determine exact VBUS voltage threshold triggering `fedl, vbus_low`
- [ ] Verify if `fastboot reboot-edl` or OEM vendor commands trigger `WriteRecoveryMessageEdl`
- [ ] Test VBUS-low resistive divider method on a test device

---

## Empirical Confirmation (2026-10-09)
- EDL entry via `fastboot oem edl`: **CONFIRMED WORKING**
- Auto-timeout: **~10 seconds, CONFIRMED**
- Brick risk from entering EDL: **ZERO**
- Flashing capability: **STILL BLOCKED** (no signed Firehose loader)

