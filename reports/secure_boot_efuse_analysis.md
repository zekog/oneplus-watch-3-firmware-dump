# Secure Boot eFuse Analysis - Snapdragon W5+

## Summary
Status: UNKNOWN (statically undecidable). Evidence leans toward unblown.

## Evidence for UNBLOWN
- `SEC_BOOT_EN` bit0 = 0 (`SecurityFlag` = `0xC4`)
- devcfg `OEM_rot_enable_transfer_APPS` = 0
- devcfg `OEM_rot_enable_transfer_MODEM` = 0
- devcfg `OEM_rot_pk_hash1_fuse_values` = 0
- BES2610 `SEC_BOOT_EN` is unblown (separate chip)

## Evidence for BLOWN
- OTA has full signing stack (PKCS7/X509 + `qcom.tz.uefisecapp`)
- OnePlus 13/13T already fuse new devices
- New devices usually ship with blown PK_HASH

## TrustZone Reads at Runtime
- XBL queries TZ via SMC `0x82000119`
- CallSecureMonitor (`FUN_0c24ea00`)
- SecFuseLib (`FUN_5fc21050`)
- Cannot be verified statically

## Verdict
MEDIUM chance (~50-60%) for "免授权" bypass working on Watch 3.
Requires hardware test on sacrificial unit.
