# RTOS Flash Programmer Analysis (`programmer.bin`)

## 1. Executive Summary & Binary Information
- **Binary Target:** `/home/zek/Pobrane/opw3 firmware/mcu_firmware/OPWWE251/programmer.bin`
- **File Size:** 70,604 bytes (~69 KB)
- **Target Platform:** Bestechnic BES2610 / BES2800 Dual Cortex-M55 Subsystem (OnePlus Watch 3 / OPWWE251 RTOS MCU)
- **Architecture:** ARM Cortex-M55 (ARMv8.1-M Mainline Thumb-2, Little-Endian)
- **Execution Environment:** Loaded and executed entirely from internal SRAM at Base Address **`0x04100000`**
- **Entry Point (`_start` / `Reset_Handler`):** `0x04106d24`
- **Main Engine (`programmer_main`):** `0x04104250`
- **Decompiled Source:** [`programmer_decompiled.c`](file:///home/zek/Pobrane/opw3-re/programmer_decompiled.c)

---

## 2. Memory Layout & Lifecycle

### Base Address Determination (`0x04100000`)
The binary starts with a 16-byte Bestechnic image header containing the magic word and metadata, followed by padding up to offset `0x0620`. At offset `0x0620`, the internal vector trampoline points to `0x04106d25` (Thumb mode address).

```armasm
04106d24 <_start>:
 4106d24: push    {r3, lr}
 4106d26: ldr     r3, [pc, #180]    ; Loads MSP = 0x242fffe0 (SRAM Top)
 4106d28: msr     MSP, r3
 4106d2c: ldr     r1, [pc, #176]    ; Loads MSPLIM = 0x242fefe0 (Stack Limit)
 4106d2e: msr     MSPLIM, r1
 4106d32: movs    r0, #0
 4106d34: msr     CONTROL, r0
 4106d38: isb     sy
 ... (Zeroes .bss from 0x242404c0, initializes .data)
 4106d76: bl      0x04107164        ; System clock / bus config
 4106d82: bl      0x0410aa34        ; Read BOOT_MODE register (0x40080038)
 4106dd6: bl      0x04106cbc        ; Enter programmer runtime
```

At `0x04106cbc`:
1. Initializes UART and ISPI (Internal SPI to BEST1700 PMU).
2. Prints `"------ Enter programmer_main ------"`.
3. Calls `programmer_main` (`0x04104250`).
4. Prints `"------ Exit programmer_main ------"`.
5. Enters infinite wait loop: `while (1);`.

---

## 3. String Search & Security Keywords

Inspection of `.rodata` (starting at offset `0x00f000` / address `0x0410f000`) and xref tracing reveals the following:

| Keyword | String / Symbol | Address | Function / Context |
| :--- | :--- | :---: | :--- |
| **`boot`** | `Flash boot` | `0x0410fca8` | Command `0xF2`: reboot into NOR flash firmware |
| **`boot`** | `Reboot` / `reboot` | `0x0410fc88` | Command `0xF1`: system software reset |
| **`boot`** | `Set bootmode` | `0x0410fcb4` | Command `0xE1`: modify `BOOT_MODE` register (`0x40080038`) |
| **`boot`** | `Clear bootmode` | `0x0410fcc4` | Command `0xE2`: clear bits in `0x40080038` |
| **`boot`** | `Get bootmode` | `0x0410fcd4` | Command `0xE3`: query current bootmode |
| **`boot`** | `Failed to open boot norflash: %d` | `0x0411059c` | Flash initialization failure in `0x0410611c` |
| **`verify`** | `[%05u] %s verifying` | `0x04110358` | Status trace during sector verification |
| **`verify`** | `SEC_VERIFY/EXTRA` | `0x0411036c` | Sector verify operation descriptor |
| **`verify`** | `%s verify failed` | `0x04110038` | General verification failure handler |
| **`verify`** | `*** Verify flash data failed: 0x%02X @ 0x%08x != 0x%02X @ %p` | `0x041105f8` | Flash sector post-burn comparison mismatch |
| **`verify`** | `*** Verify sec reg data failed: 0x%02X @ %p != 0x%02X @ %p` | `0x04110698` | Flash Security Register comparison mismatch |
| **`secure`** | `SEC_LOCK` | `0x0410fb54` | Flash security lock packet header |
| **`secure`** | `*** Failed to read sec reg: %d` | `0x04110678` | Failure reading NOR Flash Security Registers |
| **`magic`** | Packet prefix `0xBE` (`cVar32 == -0x42`) | `0x041043aa` | Protocol synchronization byte matching `0xBE57EC1C` |

*Note:* Standard cryptographic verification terms (`RSA`, `SHA256`, `ECDSA`, `X.509`, `signature`, `certificate`) are **entirely absent** from `programmer.bin`.

---

## 4. Flash Security Register vs. Silicon eFuse

### Security Register Read Function (`0x04106c24` & `0x0410a474`)
The `"sec reg"` functions in `programmer.bin` operate on **SPI NOR Flash Security Registers** (OTP security registers on the external/internal flash die, accessed via standard SPI NOR commands `0x48` Read Security Register, `0x42` Program, `0x44` Erase):

```c
// Function: verify_sec_reg at 0x04106c24
int verify_sec_reg(uint flash_addr, byte *expected_buf, uint len) {
    if (flash_addr >= 0x03000000) {
        return -1;
    }
    // Read Security Register via SPI NOR driver
    int ret = read_nor_sec_reg(flash_addr & 0x00FFFFFF, flash_buf, len);
    if (ret != 0) {
        TRACE("*** Failed to read sec reg: %d\n", ret);
        return 1;
    }
    // Verify burned bytes
    for (int i = 0; i < len; i++) {
        if (flash_buf[i] != expected_buf[i]) {
            TRACE("*** Verify sec reg data failed: 0x%02X @ %p != 0x%02X @ %p\n",
                  flash_buf[i], &flash_buf[i], expected_buf[i], &expected_buf[i]);
            return (flash_buf[i] - expected_buf[i]);
        }
    }
    return 0; // Verified OK
}
```

### Silicon eFuse Architecture on BES2610
On-chip silicon eFuses are managed by the analog power management die (**BEST1700 PMU**) connected via **ISPI** (Internal SPI):
1. **eFuse Read Implementation:**
   - In the RTOS firmware and bootloader, eFuses are read via `_amp_pmu_efuse_read_handler` / `pmu_get_efuse(page)`.
   - `programmer.bin` initializes ISPI (`0x0410c120`) to communicate with the BEST1700 PMU, but does not expose an eFuse write/burn interface to the flashing tool.
2. **What eFuse Registers Are Checked During Boot?**
   - **eFuse Page E (`efuse E`):** Read during early PMU initialization to obtain the master crystal / PLL clock divider (`new_div`) and frequency calibration.
   - **Voltage Calibration eFuses (`vcore_l`, `vmin_map`):** Factory trims for Low-Voltage (LV), Mid-Voltage (MV), and High-Voltage (HV) power rail slopes and intercepts.
   - **ADC Calibration (`GPADC Ch1`):** Calibration slope and offset for battery voltage sensing.
   - **Metal Revision (`METAL_ID`):** Silicon fabrication revision tag (`0x04110827`).

---

## 5. Is Secure Boot Enforced by Default?

**NO, Secure Boot is NOT enforced by default.**

### Evidence & Architecture
1. **No Cryptographic Engine in Programmer/Bootloader:**
   Neither `programmer.bin` nor `bootloader.bin` contains RSA, ECDSA, or hash-verification logic. The entire verification process consists of:
   - Packet CRC32 checksums (`%s: Bad CRC`).
   - Byte-for-byte readback verification against the transmitted buffer (`Verify flash data failed`).
   - Checking the `0xBE57EC1C` magic word at flash offset 0.
2. **eFuse `SEC_BOOT_EN` Flag Unblown:**
   In Bestechnic BES26xx architecture, Secure Boot enforcement is gated by a dedicated hardware eFuse bit (`SEC_BOOT_EN`). In this device firmware configuration:
   - Custom RTOS binaries (`OPWWE251_M55C0`, `OPWWE251_M55C1`, `OPWWE251_SSHUB`) contain only a standard image header and raw code/data, without appended RSA signatures or certificates.
   - The flash updater (`libmcuupdater.so`) burns binary blocks and simply writes `0xBE57EC1C` to the flash boot sector before instructing the chip to reboot.

---

## 6. What Is the Magic Header `0xBE57EC1C` For?

`0xBE57EC1C` (`1C EC 57 BE` in Little-Endian) is the **Bestechnic Image Magic Number** (`BES_IMAGE_MAGIC` / `BOOT_MAGIC`):

1. **Hardware Word Structure:**
   - Word: `0xBE57EC1C`
   - Syllabic encoding: `BE-ST-EC-1C` $\rightarrow$ **"BESTECHNIC"**.
2. **Image Header Format (`struct boot_hdr_t`):**
   ```c
   struct bes_boot_hdr {
       uint32_t magic;            // 0x00: 0xBE57EC1C
       uint16_t security_version; // 0x04: 0x0001
       uint16_t image_version;    // 0x06: 0x0005
       uint32_t reserved;         // 0x08: 0x00000000
       uint32_t image_entry_or_sz;// 0x0C: 0x0411139C (points to build timestamp)
       uint8_t  build_info[16];   // 0x10: "W4V1..."
       ...
   };
   ```
3. **Boot Validation Role:**
   - Every bootable binary (`bootloader.bin`, `programmer.bin`, `OPWWE251_M55C0_2505201801.bin`, `OPWWE251_M55C1_2505201801.bin`) has `0xBE57EC1C` at byte offset `0x00`.
   - The on-chip Boot ROM verifies this 32-bit magic word before jumping to the entry point.
   - If the magic word is missing or altered, the Boot ROM halts normal execution and drops into ROM download mode (awaiting `programmer.bin` over UART/USB).
   - In `libmcuupdater.so`, writing `0xBE57EC1C` to offset 0 is the **final commit step**:
     ```c
     // libmcuupdater: run_programmer @ 0x0001b68c
     burn_data(image_payload);
     local_34 = 0xbe57ec1c;
     burn_cmd_burn_data(flash_offset_0, &local_34, 4); // Commit magic header
     sys_cmd_boot_cmd();                               // Trigger boot into RTOS
     ```
