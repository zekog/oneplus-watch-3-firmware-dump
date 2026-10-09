#!/usr/bin/env bash
# ==============================================================================
# analyze_modules.sh - Extract symbols, metadata, and analyze Linux kernel modules (.ko)
# ==============================================================================
set -euo pipefail

MODULE_DIR="${1:-extracted_images/vendor_dlkm_extracted/lib/modules}"
OUTPUT_CSV="${2:-reports/vendor_dlkm_modules.csv}"

if [[ ! -d "$MODULE_DIR" ]]; then
    echo "[-] Error: Directory '$MODULE_DIR' not found." >&2
    exit 1
fi

mkdir -p "$(dirname "$OUTPUT_CSV")"

echo "nazwa_pliku,rozmiar_bajtow,liczba_symboli,ma_symbole,opis" > "$OUTPUT_CSV"

echo "[*] Analyzing kernel modules in $MODULE_DIR..."
COUNT=0

for mod in "$MODULE_DIR"/*.ko; do
    [[ -f "$mod" ]] || continue
    fname=$(basename "$mod")
    size=$(stat -c%s "$mod" 2>/dev/null || stat -f%z "$mod" 2>/dev/null)
    
    # Check symbols with readelf and nm
    has_symtab=$(readelf -S "$mod" 2>/dev/null | grep -E "symtab|strtab" || true)
    if [[ -n "$has_symtab" ]]; then
        has_symbols="TAK"
    else
        has_symbols="NIE"
    fi
    
    sym_count=$(nm "$mod" 2>/dev/null | wc -l || echo 0)
    
    # Get description from modinfo
    desc=$(modinfo -d "$mod" 2>/dev/null | tr '\n' ' ' | tr ',' ';' | sed 's/"//g' | xargs || true)
    if [[ -z "$desc" ]]; then
        desc="No description provided"
    fi
    
    echo "${fname},${size},${sym_count},${has_symbols},\"${desc}\"" >> "$OUTPUT_CSV"
    COUNT=$((COUNT + 1))
done

echo "[+] Successfully analyzed $COUNT modules. Results written to $OUTPUT_CSV"
