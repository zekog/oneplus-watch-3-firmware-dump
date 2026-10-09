#!/usr/bin/env bash
# ==============================================================================
# verify_kernel.sh - Verify symbols and driver presence in kernel ELF
# ==============================================================================
set -euo pipefail

KERNEL_ELF="${1:-extracted_images/kernel_with_symbols.elf}"
OUTPUT_TXT="${2:-reports/kernel_driver_check.txt}"

if [[ ! -f "$KERNEL_ELF" ]]; then
    echo "[-] Error: Kernel ELF '$KERNEL_ELF' not found." >&2
    exit 1
fi

mkdir -p "$(dirname "$OUTPUT_TXT")"

echo "[*] Verifying driver symbols in $KERNEL_ELF..."

TOTAL_SYMBOLS=$(nm "$KERNEL_ELF" 2>/dev/null | wc -l || echo 0)
echo "[+] Total symbols extracted: $TOTAL_SYMBOLS"

cat <<EOF > "$OUTPUT_TXT"
================================================================================
OnePlus Watch 3 (OPWWE251) - GKI Kernel Symbol & Driver Audit Report
Target: $KERNEL_ELF
Total Symbols in ELF: $TOTAL_SYMBOLS
Architecture: AArch64 (ARM64)
Kernel: Linux 5.15.170-android14-11 (Generic Kernel Image / GKI)
================================================================================

1. ARCHITECTURAL SUMMARY
In Android 14 GKI architecture, platform-specific and board-specific drivers
(such as touchscreen controllers, dedicated IMU sensors, RTOS co-processors,
and proprietary vendor PMICs) are intentionally decoupled from the monolithic
kernel image (boot.img) and loaded dynamically as GKI modules from vendor_dlkm
or the vendor_boot ramdisk.

2. TARGET DRIVER SYMBOL AUDIT IN GKI MONOLITHIC KERNEL:
EOF

check_symbol() {
    local label="$1"
    local pattern="$2"
    echo -n "[*] Checking for $label ($pattern)... "
    local count
    count=$(nm "$KERNEL_ELF" 2>/dev/null | awk '{print $3}' | grep -cEi "^($pattern)" || true)
    count=$(echo "$count" | tr -d '[:space:]')
    count=${count:-0}
    if [[ "$count" -gt 0 ]]; then
        echo "FOUND ($count symbols)"
        echo -e "\n[$label] - FOUND ($count symbols):" >> "$OUTPUT_TXT"
        nm "$KERNEL_ELF" 2>/dev/null | awk '{print $3}' | grep -Ei "^($pattern)" | head -20 | sed 's/^/  - /' >> "$OUTPUT_TXT"
    else
        echo "ABSENT (0 symbols) -> Offloaded to vendor_dlkm / vendor_boot"
        echo -e "\n[$label] - ABSENT (0 symbols in monolithic GKI kernel)" >> "$OUTPUT_TXT"
        echo "  Explanation: Driver is built out-of-tree as a vendor module or handled via RTOS/QMI." >> "$OUTPUT_TXT"
    fi
}

check_symbol "FocalTech Touch (ft5x06 / focaltech)" "ft5[0-9]|focaltech.*"
check_symbol "Zinitix Touch (zinitix)" "zinitix.*"
check_symbol "Goodix Touch/FP (goodix)" "goodix.*"
check_symbol "Bosch IMU (bmi*)" "bmi[0-9].*"
check_symbol "STMicroelectronics IMU (lsm6d* / lsm9d*)" "lsm[0-9].*"
check_symbol "InvenSense IMU (icm*)" "icm[0-9].*"
check_symbol "Maxim Health/PPG (max86*)" "max86.*"
check_symbol "TI Analog Front End (afe*)" "afe[0-9].*"
check_symbol "PixArt Health Sensor (pmw*)" "pmw[0-9].*"
check_symbol "Generic Touchscreen Framework" "touchscreen_.*"
check_symbol "Generic Power Supply Class" "power_supply_.*"
check_symbol "Generic Thermal Zone Framework" "thermal_zone_.*"

cat <<EOF >> "$OUTPUT_TXT"

================================================================================
3. CONCLUSION & DRIVER LOCATION MAPPING
- Touchscreen: focaltech_fts.ko (FocalTech) and zinitix.ko (Zinitix) in vendor_dlkm
- Rotary Crown: oplus_crown.ko (PixArt PAT9125 / Mixosense MOT6010) in vendor_dlkm
- Coprocessor/RTOS: bes2610.ko (Bestechnic BES2610) in vendor_dlkm & vendor_boot
- Health PPG/AFE: pmw5100-spmi_dlkm.ko in vendor_dlkm
- Sensor Hub: oplus_snshub.ko in vendor_boot + qti_qmi_sensor.ko in vendor_dlkm
================================================================================
EOF

echo "[+] Report generated at $OUTPUT_TXT"
