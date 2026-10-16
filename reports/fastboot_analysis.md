# Fastboot Access Analysis - Bricked Unit

## Summary
Fastboot is UNREACHABLE on bricked OnePlus Watch 3.

## ABL Fastboot Menu
- Menu exists: START / Restart bootloader / Recovery / Power off / FFBM / QMMI
- Navigation: bottom button (KPDPWR) = power/pause, crown (RESIN) = navigate
- Entry needs: reboot-reason cookie (only running system or VIP-gated write can set)
- Menu display disabled: "Display menu is not enabled!"

## EDL No Help
- No "reset to fastboot" command
- Poke disabled on secure boot
- Only erase behind unsendable sign packet

## MCU No Help
- BES2800 protocol: normal boot, recovery, power only
- No fastboot command

## Button Combos
- XBL: 0 button reads at boot
- sbl1_tlmm_init: only ATH_A2S_GPIO (GPIO 16)
- Recovery: 5s long-press, but recovery = "No command"
- Dual 12s: PMIC hardware reset only

## Verdict
FASTBOOT = UNREACHABLE ON BRICK. EDL ONLY.
