### 1. Potwierdzenie załadowania pliku (Binary Load Confirmation)

Plik został pomyślnie zbadany i załadowany przez **REA**:
* **Ścieżka:** `/home/zek/Pobrane/opw3 firmware/firmware-update/devcfg_msm_ddr.mbn`
* **Format:** ELF 64-bit LSB Executable (ARM64 / AArch64, little-endian, bez nagłówków sekcji)
* **Evidence ID REA:** `ev_24a16fc8a19abcccf9eb75eb285fc9b7118f8b4e2d8a24a656caefd6d1a2067d`
* **Adres bazowy / Segmenty pamięci:**
  * **Segment 1 (główny DALPROP / konfiguracja):** `0x10003000` – `0x10009dc8` (Offset pliku: `0x2000`, długość: 28 104 bajty)
  * **Segment 2:** `0x45dfd000` – `0x45dfd6b4` (Offset pliku: `0x9000`, długość: 1 716 bajtów)

---

### 2. Wyszukanie ciągu `tlmm_gpio_test_pin`

* **REA Search Evidence ID:** `ev_9e952c7d2606d17fbc31ea87eb322314b433bcd56473ac0d6702b2f50de9c074`
* **Wirtualny adres ciągu (Virtual Address):** **`0x10006a6b`**
  *(Jeśli liczony względem bazy `0x0`: offset pliku **`0x5a6b`**; jeśli względem bazy `0x80000000`: **`0x80005a6b`**)*

---

### 3. Odczyt bajtów po terminatorze null oraz wartości pola

Ciąg znaków to `"tlmm_gpio_test_pin\0"` (18 znaków + bajt null pod adresem `0x10006a7d` / offset `0x5a7d`):

1. **4 bajty bezpośrednio po terminatorze null (adres `0x10006a7e` / offset `0x5a7e`):**
   * Bajty hex: `74 6c 6d 6d`
   * Reprezentacja ASCII: `"tlmm"` (początek kolejnego ciągu w tablicy: `"tlmm_xpu_protection"`)

2. **Wartość pola, na które wskazuje deskryptor właściwości DALPROP (`/tlmm/configs`):**
   * W tablicy właściwości sterownika TLMM (offset pliku `0x6ec8`, adres wirtualny `0x10007ec8`):
     * Nagłówek właściwości: `a3 03 80 12` (offset ciągu w tabeli `0x03a3` = `"tlmm_gpio_test_pin"`, typ: uint32)
     * Wartość pola (4 bajty pod offsetem `0x6ecc` / adres `0x10007ecc`): **`40 00 00 00`**

---

### 4. Wyszukanie `tlmm_total_gpio` i odczyt wartości

* **REA Search Evidence ID:** `ev_132808c5c04bdf78b88a9f2ae7a179a17c74e0f23936c3983597b9a7ec1baf9c`
* **Wirtualny adres ciągu:** **`0x10006acb`** *(offset pliku `0x5acb`)*
* **Wpis w tablicy właściwości TLMM (offset pliku `0x6f00`, adres `0x10007f00`):**
  * Nagłówek właściwości: `03 04 80 02` (offset ciągu `0x0403` = `"tlmm_total_gpio"`, typ: uint32)
  * Wartość pola (4 bajty pod offsetem `0x6f04` / adres `0x10007f04`): **`70 00 00 00`**

---

### 5. Numery pinów GPIO

| Parametr konfiguracji TLMM | Wartość dziesiętna (Decimal) | Wartość szesnastkowa (Hex) | Znaczenie sprzętowe |
| :--- | :--- | :--- | :--- |
| **`tlmm_gpio_test_pin`** | **64** | **`0x40`** | Pin GPIO 64 (sprzętowy test pin / force download / FEDL) |
| **`tlmm_total_gpio`** | **112** | **`0x70`** | Łączna liczba linii GPIO w Snapdragon W5+ (GPIO 0 – 111) |

---

### 6. Zrzuty pamięci Hex Dump

#### A. Otoczenie ciągu `tlmm_gpio_test_pin` (adresy `0x10006a50` – `0x10006a90`):
```text
0x10006a50 (0x5a50):  30 5f 4c 33 5f 37 5f 4d 49 52 41 00 51 55 50 30   |0_L3_7_MIRA.QUP0|
0x10006a60 (0x5a60):  5f 4c 31 5f 37 5f 4d 49 52 42 00 74 6c 6d 6d 5f   |_L1_7_MIRB.tlmm_|
0x10006a70 (0x5a70):  67 70 69 6f 5f 74 65 73 74 5f 70 69 6e 00 74 6c   |gpio_test_pin.tl|
0x10006a80 (0x5a80):  6d 6d 5f 78 70 75 5f 70 72 6f 74 65 63 74 69 6f   |mm_xpu_protectio|
```

#### B. Otoczenie ciągu `tlmm_total_gpio` (adresy `0x10006ab0` – `0x10006af0`):
```text
0x10006ab0 (0x5ab0):  69 6c 65 73 00 74 6c 6d 6d 5f 62 61 73 65 00 74   |iles.tlmm_base.t|
0x10006ac0 (0x5ac0):  6c 6d 6d 5f 6f 66 66 73 65 74 00 74 6c 6d 6d 5f   |lmm_offset.tlmm_|
0x10006ad0 (0x5ad0):  74 6f 74 61 6c 5f 67 70 69 6f 00 74 7a 5f 61 63   |total_gpio.tz_ac|
0x10006ae0 (0x5ae0):  5f 68 65 61 70 5f 73 69 7a 65 00 64 69 73 61 62   |_heap_size.disab|
```

#### C. Tablica właściwości DAL (`/tlmm/configs`, adresy `0x10007ec0` – `0x10007f10`):
```text
0x10007ec0 (0x6ec0):  94 03 80 12 3f 00 00 00 a3 03 80 12 40 00 00 00   |....?.......@...|
0x10007ed0 (0x6ed0):  b6 03 80 14 0c 00 00 00 ca 03 80 14 14 00 00 00   |................|
0x10007ee0 (0x6ee0):  d3 03 80 14 1c 00 00 00 de 03 80 02 01 00 00 00   |................|
0x10007ef0 (0x6ef0):  ed 03 80 02 00 00 40 00 f7 03 80 02 00 00 10 00   |......@.........|
0x10007f00 (0x6f00):  03 04 80 02 70 00 00 00 00 ff 00 ff 13 04 80 02   |....p...........|
```
* Offset `0x6ec8`: `a3 03 80 12` (`tlmm_gpio_test_pin`), wartość pod `0x6ecc`: **`40 00 00 00`** (`0x40` = 64)
* Offset `0x6f00`: `03 04 80 02` (`tlmm_total_gpio`), wartość pod `0x6f04`: **`70 00 00 00`** (`0x70` = 112)