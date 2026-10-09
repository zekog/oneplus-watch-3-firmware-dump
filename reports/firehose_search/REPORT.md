# Firehose Loader Search - OnePlus Watch 3 (OPWWE251)

## Podsumowanie
- **Platforma:** Qualcomm Snapdragon W5+ Gen 1 (`monaco`, SW5100 / SDA5100)
- **Cel:** Znalezienie loadera Firehose (EDL flash programmer, np. `prog_firehose_ddr.elf` lub `xbl_s_devprg_ns.melf`) dla trybu Emergency Download (EDL 9008)
- **Status:** **NOT FOUND** (Brak samodzielnego pliku loadera Firehose w publicznym obrazie OTA)

---

## Przeszukane pliki

| Nazwa pliku | Rozmiar | Wynik skanowania sygnatur (binwalk / unblob) | Znalezione sygnatury EDL / Sahara |
|---|---|---|---|
| `xbl.elf` | 2.83 MB | ELF 64-bit; UEFI FV (0x6C000); GZIP (0xA9368); Osadzony ELF64 (0x279000) | `Sahara: Hello pkt sent`, `pmic DevPrg init`, `Entering DeviceProg lite`, `sbl1_sahara.c`, `dload_entry` |
| `NON-HLOS.bin` | 33.05 MB | FAT16 / MBN baseband modem subsystem | `qdlDg*b` (losowy ciąg / brak protokołu) |
| `xbl_config.elf` | 23.47 KB | ELF 64-bit LSB (konfiguracja XBL / PMIC) | Brak sygnatur Firehose/Sahara |
| `dspso.bin` | 64.00 MB | Obraz bibliotek współdzielonych Hexagon DSP | Brak sygnatur Firehose/Sahara |
| `static_nvbk.bin`| 10.00 MB | Kopia zapasowa pamięci trwałej NVRAM | Brak sygnatur Firehose/Sahara |
| `qupv3fw.elf` | 58.01 KB | ELF 64-bit LSB (firmware silnika QUP v3) | Brak sygnatur Firehose/Sahara |
| `rpm.mbn` | 243.47 KB | MBN Cortex-M3 (Resource Power Manager) | Brak sygnatur Firehose/Sahara |
| `abl.elf` | 263.42 KB | UEFI FV (`_FVH`), LinuxLoader PE32 | `WriteRecoveryMessageEdl`, `fastboot` |
| `imagefv.elf` | 16.00 KB | UEFI FV (`_FVH`), zasoby ikon graficznych BMP | Brak sygnatur Firehose/Sahara |
| `hyp.mbn` | 354.51 KB | MBN EL2 (Qualcomm Hypervisor) | Brak sygnatur Firehose/Sahara |
| `tz.mbn` | 2.94 MB | MBN EL3 (Qualcomm TrustZone OS) | Brak sygnatur Firehose/Sahara |

---

## Znalezione sygnatury

Wyniki analizy ciągów znaków zapisane w `reports/firehose_search/signatures_found.txt`:

```text
=== xbl.elf ===
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
EMERGENCY_DLOAD_TIMEOUT_COOKIE_SET: Reset
ERROR: Failed to set DLOAD cookie
pmic DevPrg init
Sahara: Hello pkt sent
Sahara: Hello Response Received
Sahara: Reset request received
sbl1_hw_dload_init
sbl1_sahara.c
=== NON-HLOS.bin ===
qdlDg*b
=== xbl_config.elf ===
=== dspso.bin ===
=== static_nvbk.bin ===
=== qupv3fw.elf ===
=== rpm.mbn ===
=== abl.elf ===
=== imagefv.elf ===
=== hyp.mbn ===
=== tz.mbn ===
```

Dodatkowo w `xbl.elf` (offset binarny `0x3e510` - `0x3e530`) zidentyfikowano:
- `pmic DevPrg init`
- `Entering DeviceProg lite`
- `/dev/icbcfg/boot`
- `sbl1_save_ddr_training_data`

---

## Znalezione pliki (melf, devprg, firehose)

Wyniki przeszukiwania całego drzewa roboczego (`reports/firehose_search/file_search.txt`):

```text
./extracted_images/vendor_dump/firmware/mcufirmware/OPWWE251/programmer.bin
./extracted_images/vendor_dump/firmware/mcufirmware/OWWE251/programmer.bin
./mcu_firmware/OPWWE251/programmer.bin
```

*Uwaga:* Pliki `programmer.bin` należą do mikrokontrolera Bestechnic BES2610 (koprocesor RTOS), a nie do platformy Qualcomm Snapdragon W5+.

---

## Wnioski

- **Czy znaleziono loader Firehose?** **NIE**.
  Oryginalny pakiet aktualizacji OTA nie zawiera samodzielnego pliku loadera Firehose (`prog_firehose_ddr.elf` lub `prog_firehose_lite.elf`), co jest typową praktyką producentów (Qualcomm / OnePlus dostarcza programatory Firehose wyłącznie w wewnętrznych narzędziach serwisowych typu MSM Download Tool / Oppo Flash Tool).
- **Kluczowe odkrycie wewnętrzne:**
  1. W `xbl.elf` zintegrowano procedury rozruchowe `DevPrg lite` (`Entering DeviceProg lite`, `pmic DevPrg init`).
  2. Pod adresem offsetu `0x279000` (2 592 768 B) wewnątrz `xbl.elf` wykryto i wyodrębniono autonomiczny plik binarny ELF64 (**`reports/firehose_search/xbl_melf_candidate.bin`**, 376 832 bajtów).
  3. Wyodrębniony obraz to **`XBLRamDump`** (`XBLRamDump.dll`), implementujący protokół Qualcomm Sahara (`sbl1_sahara.c`), obsługę resetu QPST oraz procedury awaryjnego zrzutu pamięci przez USB (`QUSB_BULK`).

---

## Następne kroki

- [ ] Pogłębiona deasemblacja w Ghidra dla `xbl.elf` i wyodrębnionego `xbl_melf_candidate.bin` pod kątem obsługi poleceń Sahara i wejścia w DeviceProg.
- [ ] Zbadanie pakietów oprogramowania dla **Mobvoi TicWatch Pro 5 / TicWatch Pro 5 Enduro** (ten sam procesor Qualcomm Snapdragon W5+ Gen 1 / SW5100), aby sprawdzić, czy społeczność nie uzyskała kompatybilnego pliku Firehose MELF/ELF.
- [ ] Poszukiwanie wycieków fabrycznych narzędzi OnePlus/Oppo (Oppo Flash Tool dla OPWWE251).
- [ ] Konsultacja ze społecznością badaczy EDL na forum XDA Developers.
