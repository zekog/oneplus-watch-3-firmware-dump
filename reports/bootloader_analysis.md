# Bootloader Analysis - OnePlus Watch 3 (OPWWE251)

## Overview
Bootloader files extracted from `firmware-update/` directory.
Platform: Qualcomm Snapdragon W5+ Gen 1 (monaco, SW5100)
Bootloader stage: XBL (eXtended Boot Loader) + ABL (Application Boot Loader, UEFI-based)

---

## Files Inventory

| File | Size | Format | Description |
|---|---|---|---|
| `xbl.elf` | 2.9 MB | ELF 64-bit | eXtended Boot Loader (SBL/XBL core) - contains forced EDL logic & PMIC init |
| `abl.elf` | 264 KB | UEFI FV (`_FVH`) | Application Boot Loader (LinuxLoader PE32, Fastboot protocol) |
| `xbl_config.elf` | 24 KB | ELF 64-bit | XBL configuration descriptors and PMIC settings (`/pmic_settings.bin`) |
| `devcfg_msm_ddr.mbn` | 38 KB | ELF 64-bit | Qualcomm DAL Device Configuration (TLMM/GPIO properties) |
| `qupv3fw.elf` | 59 KB | ELF 64-bit | Qualcomm Universal Peripheral (QUP v3) serial engine firmware |
| `rpm.mbn` | 244 KB | MBN | Resource Power Manager Cortex-M3 firmware |
| `hyp.mbn` | 355 KB | MBN | Qualcomm Hypervisor (EL2) firmware |
| `tz.mbn` | 3.0 MB | MBN | Qualcomm TrustZone OS (QSEE / EL3 Secure Monitor) |
| `keymint.mbn` | 327 KB | MBN | Android Hardware KeyMint / Keymaster trustlet |
| `imagefv.elf` | 16 KB | UEFI FV (`_FVH`) | Image Firmware Verification & boot splash icons |
| `uefi_sec.mbn` | 118 KB | MBN | UEFI Security verification module |
| `apdp.mbn` | 12 KB | MBN | Application Primary Debug Policy |
| `storsec.mbn` | 16 KB | MBN | Storage Security engine |
| `multi_image.mbn` | 12 KB | MBN | Multi-image bootloader descriptor |
| `vbmeta.img` | 12 KB | Android VBMETA | Android Verified Boot 2.0 metadata |
| `vbmeta_system.img` | 4.0 KB | Android VBMETA | System partition AVB 2.0 metadata |
| `dtbo.img` | 10 MB | Android DTBO | Device Tree Overlays partition |
| `NON-HLOS.bin` | 34 MB | FAT16 / MBN | Qualcomm baseband / modem subsystem firmware |
| `dspso.bin` | 64 MB | Binary | Hexagon DSP shared libraries image |
| `static_nvbk.bin` | 10 MB | Binary | Static NVRAM backup storage |

---

## Forced EDL Logic (from `xbl.elf`)

XBL contains a built-in hardware/software failsafe that automatically enters Emergency Download Mode (EDL / Qualcomm 9008) when:
- PMIC is not detected (`fedl, pmi_not_detected`)
- USB VBUS detection error (`fedl, vbus_det_err`)
- USB VBUS voltage is too low (`fedl, vbus_low`)
- Charger type detection error (`fedl, chgr_type_det_err`)
- Charger detection timeout (`fedl, chgr_det_timeout`)
- Failed boot counter exceeds threshold (`EDL: sbl1_dload_entry: dload_entry_count > 1`)

Critical memory addresses and cookies identified in `xbl.elf`:
- **DloadCookieAddr:** `0x003D3000`
- **DloadCookieValue:** `0x10`
- **EDL Mode Cookie:** `EDLCookieAddr`, `EMERGENCY_DLOAD_TIMEOUT_COOKIE_SET: Reset`
- **TLMM Register Base:** `0x00500000`, size `0x00300000` ("TLMM_REG")
- **PMIC ARB SPMI Base:** `0x01C00000`, size `0x02800000` ("PMIC ARB SPMI")

### Strings found in `xbl.elf`:
```text
 CDP_CHARGER
 DCP_CHARGER
## Default app to boot in platform BDS init
## Dynamic UART Log Buffer Size
 Failed to configure ATH_A2S_GPIO 
 FLOAT_CHARGER
# Force booting to shell whilst in pre-silicon phase
# Initialize Display panel in its own thread to run in parallel to booting
# Keep the following number of cores active, including the boot core
 OCP_CHARGER
# Required for DDRInfoTest
## SDHC Mode 0:Legacy Mode, Non-zero: SDHC Mode ##
 SDP_CHARGER
# SecBootEnableFlag = 0x1               i.e. 0b00000001
$+2@Nicbcfg_info
0x00500000, 0x00300000, "TLMM_REG",           AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x01B50000, 0x00010000, "PRNG_CFG_PRNG",      AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x01C00000, 0x02800000, "PMIC ARB SPMI",      AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x45E00000, 0x00100000, "Boot Info",         AddMem, MEM_RES, SYS_MEM_CAP, BsData, WRITE_BACK_XN
0x5FA00000, 0x00200000, "ABOOT FV",          AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK
1@XTesting DDR Read/Write.
ABCDEFGHIJKLMNPMIC
allnetcmcctest
allnetcttest
allnetcutest
AuxBootStrap_%d
BGCOM Err: DAL_DeviceAttach with DALDEVICEID_TLMM failed with err=%d.
BGCOM Err: DalTlmm_ConfigGpio failed with err=%d.
BGCOM Err: DalTlmm_GpioOut failed with err=%d.
BGCOM Err: h_bgcom_tlmm_handle is NULL
BGCOM Err: This client didnt enable secmode to disable. handle: 0x%x
BGCOM Fatal: bgcom_gpio_init failed! err=%d
BGCOM Fatal: bgcom_gpio_init(TZ_NS) failed! err=%d
BGCOM Fatal: bgcom_gpio_out failed! err=%d
BGCOM Fatal: bgcom_gpio_out failed while deinit! err=%d
Boot Config
Boot Device : eMMC
Boot Device : NVME
Boot Device : SDC
Boot Device : SPI
boot_dload.c
boot_dload_check
boot_dload_debug_target.c
boot_dload_dump.c
boot_dload_dump_security_regions
boot_dload_handle_forced_dload_timeout
boot_error_handler: Ramdump allowed. Trying to enter DLOAD
boot_init_for_dload
DloadCookieAddr
DloadCookieAddr = 0x003D3000 
DloadCookieAddr not found in uefiplat.cfg
DloadCookieValue
DloadCookieValue = 0x10
DloadCookieValue not found in uefiplat.cfg
EDL: sbl1_dload_entry: dload_entry_count > 1
EDLCookieAddr
EMERGENCY_DLOAD_TIMEOUT_COOKIE_SET: Reset
enter forced EDL
ERROR: Failed to set DLOAD cookie
fedl, chgr_det_timeout
fedl, chgr_type_det_err
fedl, pmi_not_detected
fedl, vbus_det_err
fedl, vbus_low
InitSharedLibs failed
sbl1_hw_dload_init
sbl1_tlmm_init End
sbl1_tlmm_init Start
```

---

## TLMM GPIO Configuration (from `devcfg_msm_ddr.mbn`)

Device Config contains TLMM (GPIO controller) configuration:
- `tlmm_gpio_test_pin` - test pin number (Qualcomm hardware EDL force pin)
- `tlmm_total_gpio`
- `tlmm_base`, `tlmm_offset`
- `tlmm_tiles`, `tlmm_num_tiles`
- `/tlmm/configs`
- Property definitions located at binary offset `0x5a6b`.

---

## Implications for Unbricking

1. **Forced EDL via `vbus_low` (software-hardware threshold, safest):**
   * XBL checks VBUS during USB/charger power negotiation. If VBUS falls below minimum threshold without dropping entirely, XBL branch triggers `enter forced EDL`.
2. **Failed boot counter (`dload_entry_count > 1`):**
   * Power cycling or interrupting boot repeatedly triggers DLOAD/EDL fallback.
3. **TLMM test pin short (hardware-based, DESTROYS WATER RESISTANCE):**
   * Grounding `tlmm_gpio_test_pin` forces Qualcomm Primary Boot ROM into EDL mode (Qualcomm HS-USB QDLoader 9008).

---

## WARNING: Water Resistance

The OnePlus Watch 3 is rated **5ATM (50 meters water resistance)**. Opening the casing to access physical PCB test points permanently destroys the factory seal and water resistance. No official consumer method exists to restore it. This makes hardware-based test-point grounding practically unviable for real-world devices.

---

## Next Steps

1. Analyze `xbl.elf` in Ghidra/IDA Pro to pinpoint the exact function branching to `enter forced EDL`.
2. Parse DAL property offsets in `devcfg_msm_ddr.mbn` to identify the numeric pin index of `tlmm_gpio_test_pin`.
3. Determine exact millivolt threshold for the `fedl, vbus_low` condition.
4. Reverse engineer `section1.pe` (`LinuxLoader`) from `abl.elf` around `WriteRecoveryMessageEdl`.

---

## UEFI Extraction Results

Both `abl.elf` and `imagefv.elf` contain valid UEFI Firmware Volumes (signature `_FVH` / `FFS2`):

1. **`abl.elf` Extracted Structure:**
   * Outer Volume: `volume-4096.fv` (262,144 bytes, FFS2)
   * Encapsulated Application: `LinuxLoader` (`f536d559-459f-48fa-8bbc-43b554ecae8d`)
   * Extracted Binary: `section1.pe` (593,924 bytes, PE32 image)
   * Contains Fastboot engine, slot switching logic, and `WriteRecoveryMessageEdl`.

2. **`imagefv.elf` Extracted Structure:**
   * Volume: `volume-8192.fv` (FFS2)
   * Encapsulated BMP UI resources:
     * `tsens_thermal_symbol.bmp`
     * `tsens_thermal_err_symbol.bmp`
     * `battery_symbol_DebugBoot.bmp`
     * `battery_symbol_DebugStay.bmp`

All unpacked UEFI objects are saved in `reports/uefi_extracted/`.

---

## References

- Qualcomm Snapdragon W5+ Gen 1 (monaco / SW5100)
- XBL (eXtended Boot Loader), ABL (Application Boot Loader)
- TLMM (Top Level Mode Multiplexer), PMIC (Qualcomm PM5100)
- EDL Mode = Qualcomm Emergency Download Mode (USB VID:PID 05C6:9008)
