# OplusFlashTool Analysis

## Endpoints
- OCSM: `api.myoas.com` (`/asymes/service/secLoginExt.json`)
- WCSM: `service-{sg,eu,in-wcsm}.myoppo.com`
- CRMNA: `crmna.oneplus.com`
- RCSM: `rcsm-*.realmeservice.com`
- SSO: `sso.myoas.com/sis/retrieve/main.do`
- Self-update: `diagnostic-tool.*`
- JFrog: `dfs-server-gl.allawntech.com`

## Keys
- `nv_ecdsa.pub`: ECDSA P-384 (PEM/DER)
- `auth.pub`: JSON with 57 platforms × RSA-2048 (`key`/`key_c`/`key_w`)
- `auth.pub` has NO entry for W5+ / monaco

## Packet Flow
- Packet 4 = `execGetSignData` (`FTLibOplusQCom.dll`)
- Packet 8 = `execWriteCdtData` (`FTLibOplusQCom.dll`)
- Signing: `auth_exec_flash_sign`, `auth_exec_cdt_sign`, `auth_exec_root_sign` (`FTLibBase.dll`)

## Obfuscation
- `FTLibBase.dll`: VMProtect (`.vmp0`/`.vmp1`, entropy 7.97, `.text` raw=0)
- Statically undecodable without unpacking

## Certificate Pinning
- NONE found
- MITM possible with trusted CA
- BUT login required before any packet generation

## Leaked Account
- `userconfig.ini`: `PST57HJNLZPZW9I0PXX` (service `RCSM:Other`)
- Status: unknown, likely blocked

## Conclusion
Signing is server-side. Without WCSM/OCSM access, no packets can be generated.
