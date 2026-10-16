# EDL Complete Analysis - OnePlus Watch 3

## Summary
Complete reverse engineering of EDL flash process for OPWWE251.

## EDL Entry
- Method: D+ shorted to GND, MCU "switch to smart mode"
- VID:PID: 05c6:9008
- Timeout: ~10s before handshake, session stays open after

## Flash Protocol
- firehose + VIP (Validated Image Programming) + secure boot
- ~4235 packets for Android-side restore
- 4233/4235 reproducible from stock OFP

## The Two Missing Packets
### Packet 4 (flash-sign)
- Per-firmware authorization token
- A.94: 445b937d961b24639d3faf8003631b328f45fc7d873875ede69dd1403bd76dbd
- A.108: 6d56a50fcb3f556ff85870532dfa7499af8626cff7cf2302978bf9f5b5dd8057
- A.131: 37fe070e2d91af8ae9b8...
- Sent after `<verify>`, before hardcoded GPT patch

### Packet 8 (signed CDT)
- Firmware-independent, 1024 B, "OSIG"
- SHA-256: 4672bd0f78688267e0e581520f1fcaedf960a41e634287705d776bf5b9ea7b82
- Same for all OPWWE251, all firmware versions

## VIP Replay Pipeline
- qdl (bkerler) handles OPPO VIP table correctly
- fh_loader fails on OPPO 4880-byte table (below 6440 threshold)
- Added directive: `W <path>` sends whole file as next packet
- Pipeline: reconstruct → drop blobs in holes → qdl --replay

## What We Need
- One captured packet 8 (all firmware) and one packet 4 per firmware
- From someone with WCSM/OCSM access
- Device-independent: one capture unlocks every Watch 3 (project 24965)

## References
- See `reports/edl_recovery_notes.md` for older notes
- See `reports/cve_2026_25262_analysis.md` for CVE dead end
