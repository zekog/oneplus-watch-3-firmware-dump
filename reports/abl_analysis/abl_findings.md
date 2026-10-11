### 1. Struktura `abl.elf` (UEFI Firmware Volume)

`abl.elf` to plik wykonywalny ELF 32-bit będący kontenerem dla **UEFI Firmware Volume (FV)**:
* **Punkt wejścia:** `0x9fa00000`
* **Nagłówek Firmware Volume:** offset `0x1000` (magiczny ciąg `_FVH` pod offsetem `0x1028`, rozmiar wolumenu: 256 KB / `0x40000`).
* **Format wewnętrzny:** 
  Wewnątrz wolumenu znajduje się sekcja skompresowana algorytmem EDK2 LZMA (GUID `ee4e5898-3914-4259-9d6e-dc7bd79403cf`), która zawiera wewnętrzny wolumen z właściwą aplikacją rozruchową:
  * **Nazwa UI:** `LinuxLoader`
  * **Typ:** Aplikacja EFI **PE32+ (ARM64 / AArch64)**
  * **GUID pliku:** `f536d559-459f-48fa-8bbc-43b554ecae8d`
  * **Rozmiar po dekompresji:** **593 920 bajtów (~580 KB)**
  * **Wyodrębniony plik binarny:** `/home/zek/Pobrane/opw3-re/LinuxLoader.efi` (baza RVA: `.text` pod `0x1000`, File Offset = RVA).

---

### 2. Wyniki wyszukiwania ciągów znaków

| Szukany ciąg | Adres (VMA/Offset w `LinuxLoader.efi`) | Wystąpienia | Status |
| :--- | :--- | :--- | :--- |
| **`boot-fastboot`** | `0x05bb65` | 1 (oraz `reboot-fastboot` pod `0x06acd1`) | **Znaleziono** |
| **`boot-recovery`** | `0x05c464` | 1 (oraz `reboot-recovery` pod `0x069251`) | **Znaleziono** |
| **`boot-bootloader`** | — | 0 (występuje tylko `reboot-bootloader` pod `0x0603ce`) | **Brak w BCB** |
| **`misc`** | `0x05911b`, `0x059197`, `0x06137d`, `0x068eba`, `0x06aa26` | 6 ciągów diagnostycznych | **Znaleziono** |
| **`BCB`** | — | 0 (brak skrótu literalnego; ABL operuje na strukturze `struct bootloader_message`) | **Brak literału** |
| **`androidboot.mode`** | `0x05cdbe`, `0x05ec38`, `0x06250e`, `0x062de5`, `0x062f4b`, `0x064ec3`, `0x066c94`, `0x0676b9`, `0x069641`, `0x069dec` | 10 wariantów w linii poleceń jądra | **Znaleziono** |

---

### 3. Lista odwołań (Cross-References) i powiązane funkcje

#### A. `boot-fastboot` (`0x05bb65`)
1. **`0x02b4cc` & `0x02b4e4` w funkcji `RecoveryInit()` (`0x02b35c`):**  
   Porównanie zawartości pola `command` ze struktury BCB odczytanej z partycji `misc`.
2. **`0x057818` w funkcji `FastbootRebootFastbootHandler()` (`0x05780c`):**  
   Obsługa komendy `fastboot reboot fastboot` – zapisuje ciąg `boot-fastboot` do partycji `misc` i restartuje zegarek.
3. *(Powiązany ciąg)* **`reboot-fastboot` (`0x06acd1`):**  
   Xref pod `0x053d64` w tabeli rejestracji komend Fastboot.

#### B. `boot-recovery` (`0x05c464`)
1. **`0x02b28c`, `0x02b4a4`, `0x02b918`, `0x02bad0` w funkcji `RecoveryInit()` (`0x02b35c`):**  
   Sprawdzenie w BCB polecenia rozruchu do trybu odzyskiwania (`*BootIntoRecovery = TRUE`).
2. **`0x057780` w funkcji `FastbootRebootRecoveryHandler()` (`0x057774`):**  
   Obsługa komendy `fastboot reboot recovery` – zapisuje ciąg `boot-recovery` do BCB w `misc`.
3. *(Powiązany ciąg)* **`reboot-recovery` (`0x069251`):**  
   Xref pod `0x053d50` w tabeli rejestracji komend Fastboot.

#### C. `boot-bootloader` vs `reboot-bootloader` (`0x0603ce`)
* Ciąg `boot-bootloader` **nie istnieje** w ABL (ABL nie sprawdza takiego polecenia w partycji `misc`).
* Występuje komenda Fastboot **`reboot-bootloader`** (`0x0603ce`):
  * Xref pod **`0x056974`** (`FastbootRebootBootloaderHandler`):
    Wywołuje usługę UEFI Runtime `ResetSystem()` z parametrem `ResetType = 2` (`FASTBOOT_MODE`), ustawiając rejestr cookie PMIC/TCSR przed restartem.

#### D. Komunikaty partycji `misc`
* **`0x068eba`** (`"Error in loading Data from misc partition\n"`):
  * Xrefy pod `0x02b1bc`, `0x02b544`, `0x02b9d0` w `RecoveryInit()` (`0x02b35c`).
* **`0x05911b`** (`"Read misc partition failed: %r\n"`):
  * Xref pod `0x028e74` w procedurze głównej wyboru trybu startowego (`BootLinux`).
* **`0x06137d`** (`"Failed to get devinfo from misc: %r\n"`):
  * Xref pod `0x02ab64` (odczyt struktury blokady `devinfo`).

#### E. Ciągi `androidboot.mode` (argumenty jądra Linux)
Generowane w procedurze budowania linii poleceń jądra (`0x019550` – `0x019800`):
* `" androidboot.mode=normal"` (`0x05cdbe`) -> Xref pod `0x0195e0`, `0x01964c`
* `" androidboot.mode=recovery"` (`0x069dec`) -> Xref pod `0x019658`
* `" androidboot.mode=charger"` (`0x062de5`) -> Xref pod `0x0110d0`, `0x012230`, `0x0197d8`
* `" androidboot.mode=reboot"` (`0x05ec38`) -> Xref pod `0x0195b8`
* `" androidboot.mode=rtc"` (`0x06250e`) -> Xref pod `0x019664`
* `" androidboot.mode=kernel"` (`0x066c94`) -> Xref pod `0x01957c`
* `" androidboot.mode=modem"` (`0x069641`) -> Xref pod `0x019594`
* `" androidboot.mode=smpl"` (`0x062f4b`) -> Xref pod `0x0197bc`
* `" androidboot.mode=android"` (`0x064ec3`) -> Xref pod `0x019670`

---

### 4. Dekompilacja funkcji obsługujących `boot-fastboot`

W kodzie Qualcomm ABL (`QcomModulePkg`) znajdują się dwie funkcje obsługujące `boot-fastboot`:

#### 1. Odczyt z `misc` BCB: `RecoveryInit()` (`0x02b35c` – `0x02b550`)
```c
EFI_STATUS RecoveryInit(BOOLEAN *BootIntoRecovery, BOOLEAN *BootIntoFastboot)
{
    EFI_STATUS Status;
    struct bootloader_message Msg; // bufor 2048 bajtów (0x800)

    // Odczyt struktury BCB z partycji misc
    Status = ReadFromPartition(&Msg, sizeof(Msg), "misc");
    if (EFI_ERROR(Status)) {
        DEBUG((EFI_D_ERROR, "Error in loading Data from misc partition\n"));
        return Status;
    }

    // Wymuszenie zakończenia null-terminatorem na 31. bajcie
    Msg.command[31] = '\0';

    if (Msg.command[0] != '\0') {
        // Sprawdzenie "boot-recovery"
        if (AsciiStrnCmp(Msg.command, "boot-recovery", AsciiStrLen("boot-recovery")) == 0) {
            *BootIntoRecovery = TRUE;
        }
        // Sprawdzenie "boot-fastboot" (wymaga wsparcia partycji dynamicznych / fastbootd)
        else if (IsDynamicPartitionSupported()) {
            if (AsciiStrnCmp(Msg.command, "boot-fastboot", AsciiStrLen("boot-fastboot")) == 0) {
                *BootIntoFastboot = TRUE; // Przejście do fastbootd
            }
        }
    }

    return Status;
}
```

#### 2. Zapis do `misc` BCB: `FastbootRebootFastbootHandler()` (`0x05780c`)
Procedura wywoływana po otrzymaniu polecenia `fastboot reboot fastboot`:
```c
VOID FastbootRebootFastbootHandler(VOID)
{
    EFI_STATUS Status;

    // Zapisuje "boot-fastboot" do pola Msg.command w partycji misc
    Status = WriteRecoveryMessageToMisc("boot-fastboot");
    if (Status == EFI_SUCCESS) {
        DEBUG((EFI_D_INFO, "rebooting the device to fastbootd\n"));
        RebootDevice(RECOVERY_MODE); // restart do jądra recovery z parametrem fastbootd
    } else {
        DEBUG((EFI_D_ERROR, "Failed to reboot to fastboot mode\n"));
    }
}
```

---

### 5. Raport techniczny i odpowiedzi na pytania

#### A. Czy ABL odczytuje BCB z partycji `misc`?
**TAK.** Funkcja `RecoveryInit()` pod adresem `0x02b35c` odczytuje blok 0 partycji `misc` do struktury `struct bootloader_message` o rozmiarze dokładnie **2048 bajtów (0x800)**:
* `command[32]` (offset 0 – 31)
* `status[32]` (offset 32 – 63)
* `recovery[768]` (offset 64 – 831)

#### B. Jakie polecenia (commands) obsługuje ABL w BCB?
W polu `command` struktury BCB odczytywanej z `misc` ABL interpretuje wyłącznie:
1. **`boot-recovery`** – uruchamia jądro recovery (`androidboot.mode=recovery`).
2. **`boot-fastboot`** – uruchamia jądro recovery w trybie użytkownika **Fastbootd** (Dynamic Partitions userspace fastboot).

*Wszystkie komendy protokołu Fastboot zarejestrowane w ABL (tabela pod `0x76438`):*
1. `flash:`
2. `erase:`
3. `set_active`
4. `flashing get_unlock_ability`
5. `flashing unlock`
6. `flashing lock`
7. `oem enable-charger-screen`
8. `oem disable-charger-screen`
9. `oem off-mode-charge`
10. `oem select-display-panel`
11. `oem set-hw-fence-value`
12. `oem set-gpu-preemption`
13. `oem device-info`
14. `continue`
15. `reboot`
16. `reboot-bootloader`
17. `getvar:`
18. `download:`
19. `oem audio-framework`
20. `reboot-recovery`
21. `reboot-fastboot`
22. `snapshot-update`

#### C. Czy można wymusić Fastboot poprzez zapis do partycji `misc`?
* **Wymuszenie Fastbootd (Userspace Fastboot):**  
  **TAK.** Zapis ciągu `boot-fastboot\0` do pierwszych 32 bajtów partycji `misc` sprawi, że ABL podczas startu ustawi flagę `BootIntoFastboot` i przekaże kontrolę do jądra odzyskiwania z obsługą trybu `fastbootd`.
* **Wymuszenie Bootloader Fastboot (ABL Fastboot, VID:PID `22d9:2024`):**  
  **NIE bezpośrednio przez `misc` BCB.** Polecenie `boot-bootloader` nie jest parsowane w strukturze BCB przez ABL. Wejście do natywnego trybu Fastboot bootloadera opiera się na:
  1. Rejestrze cookie restartu Qualcomm (**TCSR cookie / PMIC PON reset reason = 2**, jak w `reboot-bootloader` lub `adb reboot bootloader`).
  2. Błędzie weryfikacji AVB / uszkodzeniu slotu startowego.