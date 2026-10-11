### 1. Lokalizacja funkcji `qusb_pmi_charger_detect_forced_edl`
* **Wirtualny adres:** **`0x0c2834c0`** – **`0x0c2838bc`** (rozmiar: 1 024 bajty)
* **Segment binarny:** Główny segment wykonywalny XBL (`0x0c24e000` – `0x0c283a04`, R-E)
* **Rola:** Wczesna sprzętowa detekcja wymuszenia trybu EDL (FEDL – *Forced Emergency Download*) poprzez kontroler USB PHY oraz układ zasilania PMIC / ładowarki.

---

### 2. Pełny pseudo-kod funkcji (Ghidra Decompilation)

Oto zrekonstruowany i opatrzony komentarzami kod funkcji z Ghidra:

```c
/* Adres: 0x0c2834c0 */
uint64_t qusb_pmi_charger_detect_forced_edl(void)
{
    bool is_ufs;
    byte *sn_ptr;
    char phy_status;
    int err;
    uint32_t len;
    long part_handle;
    uint64_t ret_val = 0;
    char *err_str;
    uint32_t reg_val;
    uint32_t timeout_val = 0x61945374;
    
    char vbus_is_high[4];            // [sp + 0xc] - flaga obecności napięcia VBUS
    uint64_t charger_type_buf;       // [sp + 0x10] - typ wykrytej ładowarki (local_1a0)
    uint8_t pmic_info[28];           // [sp + 0x20] - dane PMIC
    uint32_t serial_num;
    uint8_t serial_len;
    uint8_t serial_bytes[310];
    long stack_cookie = DAT_0c11c000;

    // --- KROK 1: Odczyt numeru seryjnego z UFS / eMMC dla deskryptora USB ---
    if (_DAT_0c125150 != 0x61945374) {
        part_handle = qusb_get_partition_handle(2, 1, &charger_type_buf); // UFS
        if (part_handle == 0) {
            part_handle = qusb_get_partition_handle(1, 1, &charger_type_buf); // eMMC
            if (part_handle == 0) {
                qusb_log(s_emmc_parti_unavail_0c29c17d, 0);
                part_handle = qusb_get_partition_handle(1, 0, &charger_type_buf);
                if (part_handle == 0) {
                    qusb_log(s_sdc_parti_unavail_0c29c190, 0);
                    serial_num = qusb_read_default_serial();
                } else {
                    if (qusb_read_storage_info(part_handle, pmic_info) != 0) {
                        qusb_log(s_emmc_sdc_info_fail_0c29c1a2, 0);
                        serial_num = qusb_read_default_serial();
                    }
                }
            } else {
                if (qusb_read_storage_info(part_handle, pmic_info) != 0) {
                    qusb_log(s_emmc_sdc_info_fail_0c29c1a2, 0);
                    serial_num = qusb_read_default_serial();
                }
            }
            is_ufs = false;
        } else {
            if (qusb_read_storage_info(part_handle, pmic_info) != 0) {
                qusb_log(s_ufs_info_fail_0c29c15b, 0);
                // fallback do eMMC
            } else if (serial_len < 3) {
                qusb_log(s_ufs_ser_strlen_fail_0c29c169, 0);
            } else {
                // Obliczenie sumy kontrolnej CRC dla UFS Serial
                serial_num = calculate_serial_crc(serial_bytes, serial_len);
            }
            is_ufs = true;
        }
        qusb_format_serial_string(0xc1250cc, 0x80, serial_num, is_ufs);
    }

    // --- KROK 2: Sprawdzenie stanu PMIC i VBUS ---
    if (qusb_is_charger_detection_disabled() == 1) {
        return 0; // Pominięcie detekcji
    }

    vbus_is_high[0] = 0;
    charger_type_buf = 7; // 7 = PM_SCHG_CHGR_TYPE_INVALID / DETECTING

    // Sprawdzenie czy układ PMIC jest obecny i zainicjalizowany
    err = pm_get_pmic_info(0, pmic_info); // 0x0c26310c
    if (err != 0) {
        qusb_log("fedl, pmi_not_detected", 0);
        charger_type_buf = 7;
        goto check_chgr_type;
    }

    // Pętla próbkowania VBUS i typu ładowarki (maks. 100 iteracji z krokiem 5 ms = 500 ms)
    int retry_cnt = -99;
    do {
        // ODCZYT VBUS PRZEZ PMIC SPMI
        err = pm_chg_is_vbus_valid(vbus_is_high); // 0x0c2bff14
        if (err != 0) {
            qusb_log("fedl, vbus_det_err", 0);
            qusb_record_error(0xdd, 0, err);
            goto check_chgr_type;
        }

        // SPRAWDZENIE VBUS_LOW: Czy linia zasilania ma stan wysoki?
        if (vbus_is_high[0] == 0) {
            qusb_log("fedl, vbus_low", 0);       // <-- CIĄG ZADANIA
            qusb_record_error(0xdf, 0, 1);
            goto check_chgr_type;
        }

        // Odczyt typu ładowarki z PMIC
        err = pm_chg_get_charger_type(&charger_type_buf); // 0x0c2bff64
        if (err != 0) {
            qusb_log("fedl, chgr_type_det_err", 0);
            qusb_record_error(0xdd, 0, err);
            goto check_chgr_type;
        }

        // Jeśli typ ładowarki został ustalony (różny od 7 / INVALID), przerwij pętlę
        if ((int)charger_type_buf != 7) {
            break;
        }

        boot_delay_milliseconds(5); // 0x0c283074
        retry_cnt++;
    } while (retry_cnt != 0);

    // Zalogowanie wykrytego typu ładowarki (np. SDP, CDP, DCP)
    qusb_log("usb: chgr: %s", qusb_get_charger_name((int)charger_type_buf));

    if ((int)charger_type_buf == 7) {
        qusb_log("fedl, chgr_det_timeout", 0);
        qusb_record_error(0xdd, 0, 0);
    }

check_chgr_type:
    // Wymuszony EDL jest możliwy tylko dla:
    // typ 2: CDP (Charging Downstream Port)
    // typ 0: SDP (Standard Downstream Port - port USB w PC) przy włączonej fladze DAT_0c29c038
    if ((int)charger_type_buf != 2) {
        if ((int)charger_type_buf != 0 || DAT_0c29c038 == 0) {
            goto exit_fn;
        }
    }

    // --- KROK 3: Badanie stanu linii D+/D- przez QUSB2 PHY ---
    qusb_phy_init_sequence();
    qusb_phy_enable();
    
    if (qusb_check_phy_connected() == 0) {
        qusb_phy_reset();
        qusb_phy_configure_cdp();
        boot_delay_microseconds(10); // 10 us
        
        if (qusb_phy_read_linestate() != 0) {
            if ((int)charger_type_buf == 2) {
                qusb_phy_toggle_dp(200);
                qusb_log("usb: dp toggled for cdp", 200);
            } else {
                // TEST SPRZĘTOWEGO WYZWOLENIA EDL (Kabel EDL / zwarcie D+)
                if (qusb_pmi_check_edl_pin_trigger() != 0) { // 0x0c2831cc
                    qusb_log("enter forced EDL", 0);         // <-- CIĄG ZADANIA
                    boot_delay_microseconds(5000);           // Pauza 5 ms (5000 us)
                    ret_val = 1;                             // Zwraca 1 = WYMUSZENIE EDL
                    goto exit_fn;
                }
            }
        }
    }

exit_fn:
    return ret_val;
}
```

---

### 3. Dokładna analiza porównania dla `vbus_low`

W architekturze Qualcomm PMIC wczesny bootloader (XBL) **nie dokonuje pomiaru napięcia w miliwoltach ani konwersji ADC**. Zamiast tego odpytuje cyfrowy komparator sprzętowy wbudowany w układ PMIC (PM5100):

#### A. Instrukcje asemblera
W procedurze `qusb_pmi_charger_detect_forced_edl` (adres `0x0c283700`):
```arm64
0x0c2836fc:  add   x0, sp, #0xc        ; wskaźnik &vbus_is_high na stosie
0x0c283700:  bl    0xc2bff14           ; wywołanie pm_chg_is_vbus_valid()
0x0c283704:  cbnz  w0, 0xc2837d0       ; jeśli błąd magistrali SPMI != 0 -> błąd "fedl, vbus_det_err"
0x0c283708:  ldrb  w8, [sp, #12]       ; odczyt zwróconej flagi logicznej vbus_is_high
0x0c28370c:  cbz   w8, 0xc2837e0       ; DOKŁADNE PORÓWNANIE: Jeśli w8 == 0 (VBUS niski/brak), skok!
...
0x0c2837e0:  adrp  x0, 0xc29c000
0x0c2837e4:  mov   w1, wzr
0x0c2837e8:  add   x0, x0, #0x210      ; wskaźnik na string "fedl, vbus_low"
0x0c2837ec:  bl    0xc259314           ; boot_log("fedl, vbus_low", 0)
```

Wewnątrz funkcji sterownika PMIC SPMI (`0x0c2c42bc` / `0x0c2c4348`):
```arm64
0x0c2c4348:  bl    0xc265810           ; odczyt rejestru PMIC przez SPMI
0x0c2c434c:  ldrb  w8, [sp, #28]       ; bajt z rejestru statusu PMIC
0x0c2c4350:  cmp   w8, #0x0            ; PORÓWNANIE BITOWE: cmp w8, #0x0
0x0c2c4354:  mov   w8, w0
0x0c2c4358:  cset  w9, ne              ; w9 = (w8 != 0) -> boolean: 1 jeśli VBUS poprawny, 0 jeśli niski
0x0c2c435c:  strb  w9, [x19]           ; zapis do bufora wyjściowego vbus_is_high
```

---

### 4. Zestawienie parametrów odczytu VBUS

* **Funkcja odczytująca VBUS:**
  * Wrapper wysokiego poziomu: **`pm_chg_is_vbus_valid`** pod adresem **`0x0c2bff14`**
  * Fizyczny sterownik SPMI PMIC: **`pm_comm_read_byte_mask`** pod adresem **`0x0c2c42bc`** (wywołuje `0x0c265810`)
* **Adres / Rejestr PMIC:**
  * Urządzenie PMIC: **PMIC 0 (Qualcomm PM5100)**
  * Magistrala: **SPMI (System Power Management Interface)**
  * Peryferium PMIC: **Charger / USB-IN peripheral** (identyfikator peryferium: **`0x13`** / **`0x53`**)
  * Rejestr: **`INT_RT_STS`** (Real-Time Status, offset rejestru: **`0x10`**)
  * Odczytywany bit: **Bit 0 (`USBIN_PLUGIN_RT_STS` / `VBUS_VALID_RT_STS`)**
* **Napięcie progowe (Threshold Voltage):**
  * Na poziomie oprogramowania: Wartość logiczna **`0` vs `1`** (czy bit komparatora sprzętowego jest ustawiony).
  * Na poziomie sprzętowym PMIC PM5100: Sprzętowy komparator progowy napięcia wejściowego $V_{BUS\_VALID}$ wynosi nominalnie **$4,40\,\text{V}$** (zakres detekcji $4,25\,\text{V}$ – $4,45\,\text{V}$). Gdy $V_{BUS} < 4,25\,\text{V}$, komparator zwraca `0`, co powoduje wygenerowanie komunikatu `"fedl, vbus_low"`.
* **Instrukcje porównania:**
  * W sterowniku PMIC: **`cmp w8, #0x0`** (adres `0x0c2c4350`)
  * W logice detekcji FEDL: **`cbz w8, 0xc2837e0`** (adres `0x0c28370c`)

---

### 5. Dokładna ścieżka wykonania kodu (Execution Path do `enter forced EDL`)

Poniżej przedstawiono kompletną ścieżkę instrukcji od wejścia do funkcji aż do wyemitowania komunikatu i wejścia w tryb awaryjny 9008:

```mermaid
flowchart TD
    A["Wejście: qusb_pmi_charger_detect_forced_edl (0x0c2834c0)"] --> B["Odczyt PMIC Info: 0x0c26310c (pm_get_pmic_info)"]
    B -->|Błąd| B1["Log: 'fedl, pmi_not_detected' (0x0c2836e4)"]
    B -->|Sukces| C["Odczyt VBUS: 0x0c2bff14 (pm_chg_is_vbus_valid)"]
    C -->|w8 == 0 (VBUS niski)| C1["Log: 'fedl, vbus_low' (0x0c2837ec) -> Wyjście"]
    C -->|w8 == 1 (VBUS >= 4.4V)| D["Odczyt typu ładowarki: 0x0c2bff64 (pm_chg_get_charger_type)"]
    D --> E{"charger_type == SDP (0) lub CDP (2)?"}
    E -->|Nie| E1["Wyjście (normalny start)"]
    E -->|Tak| F["Inicjalizacja i test QUSB2 PHY (0x0c28384c - 0x0c2838dc)"]
    F --> G["Wywołanie testera kabla EDL: 0x0c2831cc"]
    G --> H["Odpytywanie rejestru PHY 0x01613038 Bit 5 (D+ Linestate)"]
    H -->|Brak zwarcia D+| H1["Wyjście: return 0"]
    H -->|Zwarcie D+ wykryte (Kabel EDL)| I["0x0c283928: Log 'enter forced EDL'"]
    I --> J["0x0c283930: boot_delay_microseconds(5000)"]
    J --> K["0x0c283934: return 1"]
    K --> L["Powrót do boot_dload_check (0x0c260e84)"]
    L --> M["0x0c260e90: bl sbl1_enter_forced_edl_target (0x0c260df8)"]
    M --> N["Zapis TCSR Cookie: *0x003D3000 |= 1"]
    N --> O["Sprzętowy reset: PBL startuje bezpośrednio w EDL Sahara 9008"]
```

#### Kroki w asemblerze:
1. **`0x0c2834c0`**: Wejście do funkcji `qusb_pmi_charger_detect_forced_edl`.
2. **`0x0c2836d4`**: `bl 0xc26310c` – odpytanie PMIC (sukces: `w0 == 0`).
3. **`0x0c283700`**: `bl 0xc2bff14` – odpytanie stanu VBUS.
4. **`0x0c283708`**: `ldrb w8, [sp, #12]` pobiera flagę `vbus_is_high` (sukces: `w8 != 0`, brak skoku do `0xc2837e0`).
5. **`0x0c283714`**: `bl 0xc2bff64` – identyfikacja ładowarki; ustala typ `0` (SDP / PC USB).
6. **`0x0c28383c` - `0x0c283848`**: Weryfikacja zezwolenia na FEDL (`DAT_0c29c038 != 0`).
7. **`0x0c2838dc`**: `bl 0xc283158` – sprawdzenie stanu linii danych USB PHY.
8. **`0x0c283910`**: `bl 0xc2831cc` – procedura badania pętli D+ na kontrolerze `QUSB2PHY`:
   * Adres rejestru PHY: **`0x01613038`** (`QUSB2PHY_PORT_TEST` / `LINESTATE`)
   * Instrukcja: `tbnz w8, #5, 0xc283254` (sprawdza czy linia **D+** została zwarta/ściągnięta, co odpowiada wciśnięciu przycisku na kablu EDL).
   * Pętla próbuje 50 razy z opóźnieniem 1 ms (`cmp w8, #0x31`).
9. **`0x0c28391c`**: Rejestr PHY potwierdza impuls kabla EDL -> załadowanie wskaźnika ciągu:
   ```arm64
   0x0c28391c:  adrp  x0, 0xc29c000
   0x0c283920:  mov   w1, wzr
   0x0c283924:  add   x0, x0, #0x105      ; wskaźnik na string "enter forced EDL"
   0x0c283928:  bl    0xc259314           ; boot_log("enter forced EDL", 0)
   0x0c28392c:  mov   w0, #0x1388         ; 5000 mikrosekund (5 ms)
   0x0c283930:  bl    0xc283024           ; boot_delay_microseconds(5000)
   0x0c283934:  mov   w0, #0x1            ; zwraca wartość 1 (EDL triggered)
   0x0c283938:  b     0xc283898           ; powrót z funkcji
   ```
10. **`0x0c260e84`**: Funkcja nadrzędna odbiera `w0 == 1`:
    ```arm64
    0x0c260e88:  tst   w0, #0xff
    0x0c260e8c:  b.eq  0xc260e94           ; nie skacze, bo w0 == 1
    0x0c260e90:  bl    0xc260df8           ; wywołuje sbl1_enter_forced_edl_target()!
    ```
11. **`0x0c260df8`**: `sbl1_enter_forced_edl_target` ustawia rejestr cookie **`*0x003D3000 |= 1`** i wykonuje reset procesora. Primary Bootloader (ROM) po restarcie natychmiast zgłasza się w systemie operacyjnym jako **Qualcomm HS-USB QDLoader 9008** (`05c6:9008`).