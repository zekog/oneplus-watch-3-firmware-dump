#!/usr/bin/env bash
# ==============================================================================
# extract_dlkm.sh - Extract kernel modules from vendor_dlkm.img
# ==============================================================================
set -euo pipefail

IMAGE_FILE="${1:-extracted_images/vendor_dlkm.img}"
OUTPUT_DIR="${2:-extracted_images/vendor_dlkm_extracted}"

if [[ ! -f "$IMAGE_FILE" ]]; then
    echo "[-] Error: Image file '$IMAGE_FILE' not found." >&2
    exit 1
fi

echo "[*] Target image: $IMAGE_FILE"
echo "[*] Output directory: $OUTPUT_DIR"
mkdir -p "$OUTPUT_DIR"

echo "[*] Attempting extraction via debugfs rdump / ..."
if debugfs -R "rdump / $OUTPUT_DIR" "$IMAGE_FILE" 2>/dev/null; then
    echo "[+] debugfs extraction completed."
else
    echo "[!] debugfs rdump failed, attempting 7z fallback..."
    if command -v 7z >/dev/null 2>&1; then
        7z x -y -o"$OUTPUT_DIR" "$IMAGE_FILE" >/dev/null 2>&1 || true
    fi
fi

KO_COUNT=$(find "$OUTPUT_DIR" -name "*.ko" 2>/dev/null | wc -l)
echo "[+] Extracted $KO_COUNT kernel modules (.ko)."

if [[ "$KO_COUNT" -eq 0 ]]; then
    echo "[-] Warning: No .ko modules found in $OUTPUT_DIR" >&2
    exit 1
fi

echo "[+] Successfully extracted modules to $OUTPUT_DIR"
