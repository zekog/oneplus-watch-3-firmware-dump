# EDL Access Confirmation - OnePlus Watch 3 (OPWWE251)

## Summary
Empirical confirmation that OnePlus Watch 3 can enter Qualcomm EDL mode
via software-only method (no case opening, no test points required).

## Test Environment
- Date: 2026-10-09
- Device: OnePlus Watch 3 (OPWWE251), working unit
- Host: Linux, USB 3.0
- Tools: adb, fastboot, lsusb

## Test Results

### Test 1: Fastboot Mode
Command: `adb reboot bootloader`
Result:
```text
Bus 003 Device 060: ID 22d9:2024 OPPO Electronics Corp. Android
```

- VID:PID = 22d9:2024 (OPPO/OnePlus fastboot)
- Fastboot commands work
- Auto-timeout: device returns to system after inactivity

### Test 2: EDL Mode
Command: `fastboot oem edl` (from fastboot mode)
Result:
```text
Bus 003 Device 064: ID 05c6:9008 Qualcomm, Inc. Gobi Wireless Modem (QDL mode)
```

- VID:PID = 05c6:9008 (Qualcomm EDL / Sahara mode)
- Device enumerates as Qualcomm Gobi QDL
- Auto-timeout: ~10 seconds, then auto-reboot to system
- No user intervention required

## XBL Analysis (static)
Confirmed strings in `xbl.elf`:
- `Sahara: Hello pkt sent` (offset 0x002cd590)
- `Sahara: Hello Response Received`
- `Sahara: Reset request received`
- `sbl1_sahara.c` (source file reference)
- `Entering DeviceProg lite` (offset 0x0003e510)
- `pmic DevPrg init`
- `QUSB_BULK`, `QUSB_PORT_PRIM`
- `qusb_ldr_utils_enable_eud_dep_qb`

Extracted candidate: `reports/firehose_search/xbl_melf_candidate.bin` (376 832 B)
- Format: ELF64 AArch64
- Type: XBLRamDump (Sahara protocol implementation + memory dump)
- NOT a Firehose loader

## Implications

### What works
- Software-only EDL entry: YES
- Auto-exit via timeout: YES (~10 s)
- No brick risk from entering EDL: CONFIRMED

### What does NOT work (yet)
- Flashing via EDL: NO (requires signed Firehose loader)
- Reading partitions via EDL: UNKNOWN (needs testing with proper loader)

### Safety notes
- Entering EDL does not modify any partitions
- Timeout guarantees return to system
- Manual exit: hold both buttons ~12 s
- Last resort: drain battery to 0

## Next Steps
- [ ] Acquire signed Firehose loader for Snapdragon W5 (SW5100)
- [ ] Test Sahara handshake with proper loader (on sacrificial unit)
- [ ] Analyze XBL in Ghidra for exact EDL trigger conditions
- [ ] Test vbus_low forced EDL method

## Warning
Do NOT attempt to flash anything via EDL without a signed Firehose loader.
Do NOT test on a daily-driver device. Use a sacrificial unit.
