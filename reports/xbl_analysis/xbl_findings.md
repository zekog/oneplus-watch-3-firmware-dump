# Reverse Engineering Report: Qualcomm XBL Bootloader EDL & Failsafe Mechanisms

**Target Binary:** `/home/zek/Pobrane/opw3 firmware/firmware-update/xbl.elf`  
**Platform:** Qualcomm Snapdragon W5+ Gen 1 (SW5100 / SDA5100, codename *monaco*)  
**Device:** OnePlus Watch 3 (OPWWE251 / Project ID 24965)  
**Architecture:** AArch64 (ARM64, Little-Endian, ELF64 Executable)  
**Analysis Tools:** Ghidra 12.1.2 via REA / Headless Decompiler & GNU AArch64 Toolchain  

---

## 1. Executive Summary

This report documents the reverse engineering of the Qualcomm eXtensible Bootloader (`xbl.elf`, SBL1 stage) from the OnePlus Watch 3 firmware dump. The primary objective was to investigate the Emergency Download (EDL / Sahara 9008) failsafe triggers, specifically focusing on:
1. The `dload_entry_count` threshold and state machine that transitions the bootloader from RamDump mode into forced EDL mode.
2. Hardware Forced EDL (FEDL) triggers managed by the USB and PMIC charger detection subsystem (`qusb_pmi_charger_detect_forced_edl`).
3. Memory addresses, storage locations, disassembly, and decompiled pseudo-code for all relevant procedures and registers.

---

## 2. Analysis of `sbl1_dload_entry`

### 2.1 Function Identification & Provenance
* **Function Address:** `0x0c282738` - `0x0c282930`
* **Size:** 504 bytes (126 instructions)
* **Source Code Provenance:** Qualcomm CodeAurora / QCOM Core BSP `sbl1_target.c` (confirmed by embedded string at `0x0c2b20d5` and assertion line `0x125` / 293).

### 2.2 Assembly Walkthrough (AArch64)

```arm64
// Function Prologue
0x0c282738:  sub   sp, sp, #0x40
0x0c28273c:  stp   x29, x30, [sp, #16]
0x0c282740:  add   x29, sp, #0x10
0x0c282744:  str   x21, [sp, #32]
0x0c282748:  stp   x20, x19, [sp, #48]

// Load & Increment dload_entry_count
0x0c28274c:  adrp  x19, 0xc29b000
0x0c282750:  ldr   w9, [x19, #2992]        // Load counter from DAT_0c29bbb0
0x0c282754:  add   w8, w9, #0x1            // Increment counter (w8 = w9 + 1)
0x0c282758:  str   w8, [x19, #2992]        // Store updated counter back to DAT_0c29bbb0
0x0c28275c:  cbnz  w9, 0xc282778           // If previous count was != 0, skip initial setup

// First-time setup (count was 0)
0x0c282760:  adrp  x0, 0xc285000
0x0c282764:  adrp  x1, 0xc28e000
0x0c282768:  add   x0, x0, #0xfd8          // &DAT_0c285fd8 (DLOAD context)
0x0c28276c:  add   x1, x1, #0x5e0          // &PTR_LAB_0c28e5e0
0x0c282770:  bl    0xc2622d0               // Initialize DLOAD context structures
0x0c282774:  ldr   w8, [x19, #2992]        // Re-read counter

// Threshold Comparison
0x0c282778:  cmp   w8, #0x2                // EXACT THRESHOLD: compare counter with immediate 2
0x0c28277c:  b.cc  0xc282790               // If counter < 2 (i.e. count == 1), branch to normal RamDump flow

// Threshold Reached: Force EDL
0x0c282780:  adrp  x0, 0xc2b2000
0x0c282784:  add   x0, x0, #0xa8           // Pointer to string: "EDL: sbl1_dload_entry: dload_entry_count > 1"
0x0c282788:  bl    0xc2562b4               // Call boot_log()
0x0c28278c:  bl    0xc260df8               // Call sbl1_enter_forced_edl_target()

// Normal RamDump Flow (count == 1)
0x0c282790:  adrp  x19, 0xc29b000
0x0c282794:  adrp  x20, 0xc285000
0x0c282798:  add   x19, x19, #0xaf0
0x0c28279c:  add   x20, x20, #0xfd8
0x0c2827a0:  add   x1, x19, #0x38
0x0c2827a4:  mov   x0, x20
0x0c2827a8:  bl    0xc261208               // Initialize RamDump context
...
```

### 2.3 Decompiled C Pseudo-Code

```c
// Decompiled from 0x0c282738 using Ghidra
void sbl1_dload_entry(undefined8 param_1, undefined8 param_2, uint param_3)
{
    uint uVar1;
    bool bVar2;
    undefined8 uVar3;
    int iVar4;
    undefined4 uVar5;
    undefined8 uVar6;
    
    // 1. Counter increment
    uVar1 = DAT_0c29bbb0 + 1;
    bVar2 = DAT_0c29bbb0 == 0;
    DAT_0c29bbb0 = uVar1;
    
    if (bVar2) {
        FUN_0c2622d0(&DAT_0c285fd8, &PTR_LAB_0c28e5e0);
    }
    
    // 2. Threshold evaluation (Threshold = 2, i.e., count > 1)
    if (1 < DAT_0c29bbb0) {
        FUN_0c2562b4("EDL: sbl1_dload_entry: dload_entry_count > 1");
        sbl1_enter_forced_edl_target(); // 0x0c260df8
    }
    
    // 3. Normal RamDump initialization (executed on first entry)
    FUN_0c261208(&DAT_0c285fd8, &DAT_0c29bb28);
    iVar4 = FUN_0c251fe0(*(undefined8 *)(DAT_0c285fd8 + 0x40), &PTR_LAB_0c29baf0);
    uVar3 = _UNK_0c2b2078;
    uVar6 = _DAT_0c2b2070;
    if (iVar4 == 0) {
        uVar6 = FUN_0c282940();
        FUN_0c282934(uVar6, 0xfa, param_3 & 0xffff | 0x1000000);
        do {} while(true);
    }
    
    // Register RamDump security regions (0x45e97000, size 0x10000)
    DAT_0c29bb00 = 0x10000;
    DAT_0c29bb20 = 0x60000000000000;
    PTR_LAB_0c29baf8 = (undefined *)&DAT_45e97000;
    PTR_LAB_0c29baf0 = (undefined *)&DAT_45e97000;
    uRam000000000c29bb18 = _UNK_0c2b2078;
    _DAT_0c29bb10 = _DAT_0c2b2070;
    iVar4 = FUN_0c251fe0(*(undefined8 *)(DAT_0c285fd8 + 0x40), &PTR_LAB_0c29baf0);
    if (iVar4 == 0) {
        uVar6 = FUN_0c282940();
        FUN_0c282934(uVar6, 0x10c, param_3 & 0xffff | 0x1000000);
        do {} while(true);
    }
    
    // Register RamDump system buffer (0x5c000000, size 0x1000000)
    DAT_0c29bb20 = 0x60000000000000;
    DAT_0c29bb00 = 0x1000000;
    DAT_0c29bb08 = 2;
    PTR_LAB_0c29baf8 = (undefined *)0x5c000000;
    PTR_LAB_0c29baf0 = (undefined *)0x5c000000;
    uRam000000000c29bb18 = uVar3;
    _DAT_0c29bb10 = uVar6;
    iVar4 = FUN_0c251fe0(*(undefined8 *)(DAT_0c285fd8 + 0x40), &PTR_LAB_0c29baf0);
    if (iVar4 != 0) {
        FUN_0c24eb48();
        FUN_0c2562b4("External heap deinit, Start");
        FUN_0c250478();
        iVar4 = thunk_FUN_0c25bec4();
        if (iVar4 != 0) {
            (*(code *)PTR_FUN_0c289e00)("sbl1_target.c", 0x125, 0x46000090);
            do {} while(true);
        }
        FUN_0c282950();
        FUN_0c2562b4("External heap init, Start");
        uVar6 = FUN_0c250478();
        uVar5 = FUN_0c250484();
        iVar4 = thunk_FUN_0c25be40(uVar6, uVar5, 1);
        if (iVar4 != 0) {
            FUN_0c282934(&DAT_0c289000, FUN_0c2b2000, 300, 0x46000089);
            do {} while(true);
        }
        FUN_0c282950();
        FUN_0c2b50b8();
        // Jump to RamDump / Sahara payload in DDR
        (*(code *)0x45e35000)();
        return;
    }
    uVar6 = FUN_0c282940();
    FUN_0c282934(uVar6, 0x11f, param_3 & 0xffff | 0x1000000);
    do {} while(true);
}
```

### 2.4 Answers to Key Questions

#### 1. What is the exact threshold value?
* **Exact Assembly Instruction:** `cmp w8, #0x2` followed by `b.cc 0xc282790` (branch carry clear / unsigned less than).
* **Pseudo-Code Condition:** `if (1 < DAT_0c29bbb0)` (equivalent to `if (dload_entry_count >= 2)` or `dload_entry_count > 1`).
* **Behavior:**
  * **1st entry (`count = 1`):** Counter increments from `0` to `1`. The condition `1 < 1` is false. The function proceeds to initialize RamDump capture buffers (`0x45e97000`, `0x5c000000`), reinitializes the heap, and jumps to the RamDump handler at `0x45e35000`.
  * **2nd entry (`count = 2`):** Counter increments from `1` to `2`. The condition `1 < 2` is true (`cmp w8, #0x2` sets carry). The bootloader assumes the previous RamDump or boot attempt crashed recursively. It prints `"EDL: sbl1_dload_entry: dload_entry_count > 1"` and immediately executes `sbl1_enter_forced_edl_target()`.

#### 2. Where is the counter stored?
* **Address:** Virtual Address `0x0c29bbb0` (`DAT_0c29bbb0`).
* **Segment / Region:** Internal SRAM / IMEM (System IMEM) data section.
  * In the ELF header, this resides in segment:
    `LOAD Offset: 0x00037000, VirtAddr: 0x0c285000 - 0x0c29c6a8 (RW)`.
* **Nature:** Global static variable (`static uint32 dload_entry_count` in Qualcomm BSP). Because IMEM retains state across warm resets / watchdog resets, this counter survives a crash during the dump handling flow.

#### 3. What does the function do when the threshold is reached?
1. Emits a debug log message:
   `FUN_0c2562b4("EDL: sbl1_dload_entry: dload_entry_count > 1");`
2. Invokes `sbl1_enter_forced_edl_target` (`0x0c260df8`), which:
   * Sets the Qualcomm TCSR boot cookie register at `0x003D3000` (`DloadCookieAddr`) to `0x1` (Forced DLOAD / Emergency Download flag).
   * Executes a hardware warm reset via `FUN_0c25df84(1)`.
   * On reboot, Qualcomm PBL (Primary Bootloader in ROM) reads cookie `0x003D3000 == 0x1` and immediately drops into EDL mode (USB VID:PID `05c6:9008`, Qualcomm Sahara protocol).

#### 4. List of all function calls made in `sbl1_dload_entry`

| Address | Function Symbol / Name | Description |
| :--- | :--- | :--- |
| `0x0c2622d0` | `FUN_0c2622d0` | Initial DLOAD context initialization (called only when `count == 0`) |
| `0x0c2562b4` | `boot_log` / `FUN_0c2562b4` | Formatted debug logging over UART/trace buffer |
| `0x0c260df8` | `sbl1_enter_forced_edl_target` | Writes EDL cookie (`0x1`) to `0x003D3000` and executes warm reset |
| `0x0c261208` | `FUN_0c261208` | RamDump context registration routine |
| `0x0c251fe0` | `FUN_0c251fe0` | Memory region registration for RamDump buffers |
| `0x0c282940` | `FUN_0c282940` | Error retrieval helper |
| `0x0c282934` | `FUN_0c282934` | Assertion / boot panic handler with error codes (`0xfa`, `0x10c`, `0x11f`) |
| `0x0c24eb48` | `FUN_0c24eb48` | External heap pre-deinitialization routine |
| `0x0c250478` | `FUN_0c250478` | Heap base pointer accessor |
| `0x0c25bec4` | `thunk_FUN_0c25bec4` | Heap deinit implementation |
| `0x0c289e00` | `PTR_FUN_0c289e00` (`boot_error_handler`) | Fatal assertion handler (`"sbl1_target.c"`, line `0x125`) |
| `0x0c282950` | `FUN_0c282950` | Memory barrier / cache transition helper |
| `0x0c250484` | `FUN_0c250484` | Heap size accessor |
| `0x0c25be40` | `thunk_FUN_0c25be40` | Heap init implementation |
| `0x0c2b50b8` | `FUN_0c2b50b8` | Final preparation before DDR payload handover |
| `0x45e35000` | `(*(code *)0x45e35000)()` | Indirect call to loaded RamDump / Sahara agent in DDR |

---

## 3. Analysis of `sbl1_enter_forced_edl_target`

### 3.1 Disassembly Walkthrough (`0x0c260df8`)

```arm64
0x0c260df8:  sub   sp, sp, #0x20
0x0c260dfc:  stp   x29, x30, [sp, #16]
0x0c260e00:  add   x29, sp, #0x10
0x0c260e04:  adrp  x8, 0xc285000
0x0c260e08:  mov   w0, #0x3000
0x0c260e0c:  add   x8, x8, #0x520
0x0c260e10:  movk  w0, #0xc12, lsl #16
...
0x0c260e40:  bl    0xc256494               // Flush caches / prepare hardware
0x0c260e44:  mov   w8, #0x3000             // Lower 16 bits of 0x003d3000
0x0c260e48:  mov   w0, #0x1
0x0c260e4c:  movk  w8, #0x3d, lsl #16      // w8 = 0x003D3000 (TCSR_BOOT_MISC_DETECT)
0x0c260e50:  ldr   wzr, [x8]               // Dummy read barrier
0x0c260e54:  ldr   w9, [x8]                // Read current register value
0x0c260e58:  and   w9, w9, #0xfffffff0     // Clear lower 4 bits (mask 0xF)
0x0c260e5c:  orr   w9, w9, #0x1            // Set bit 0 (EDL / Forced DLOAD cookie = 1)
0x0c260e60:  str   w9, [x8]                // Store back to 0x003D3000
0x0c260e64:  ldp   x29, x30, [sp, #16]
0x0c260e68:  add   sp, sp, #0x20
0x0c260e6c:  b     0xc25df84               // Warm reset (calls PMIC/PSCI reset)
```

### 3.2 Decompiled C Pseudo-Code

```c
void sbl1_enter_forced_edl_target(void)
{
    FUN_0c256494();
    // Write Forced DLOAD cookie (0x1) to Qualcomm TCSR register 0x003D3000
    _DAT_003d3000 = (_DAT_003d3000 & 0xfffffff0) | 1;
    // Execute reset into Qualcomm EDL (Sahara 9008)
    FUN_0c25df84(1);
    return;
}
```

---

## 4. Hardware Forced EDL (FEDL) String & Cross-Reference Analysis

The requested strings were located in the binary and mapped to their exact cross-references:

| String | Virtual Address | Calling Function | Calling Instruction Address | Disassembly Reference |
| :--- | :--- | :--- | :--- | :--- |
| `"EDL: sbl1_dload_entry: dload_entry_count > 1"` | `0x0c2b20a8` | `sbl1_dload_entry` (`0x0c282738`) | `0x0c282784` | `adrp x0, 0xc2b2000; add x0, x0, #0xa8` |
| `"fedl, pmi_not_detected"` | `0x0c29c1e6` | `qusb_pmi_charger_detect_forced_edl` (`0x0c2834c0`) | `0x0c2836dc` | `adrp x0, 0xc29c000; add x0, x0, #0x1e6` |
| `"fedl, vbus_low"` | `0x0c29c210` | `qusb_pmi_charger_detect_forced_edl` (`0x0c2834c0`) | `0x0c2837e0` | `adrp x0, 0xc29c000; add x0, x0, #0x210` |
| `"enter forced EDL"` | `0x0c29c105` | `qusb_pmi_charger_detect_forced_edl` (`0x0c2834c0`) | `0x0c28391c` | `adrp x0, 0xc29c000; add x0, x0, #0x105` |

---

## 5. Analysis of `qusb_pmi_charger_detect_forced_edl` (`0x0c2834c0`)

### 5.1 Function Purpose
This function implements Qualcomm's hardware FEDL (Forced Emergency Download) detection over USB and the PMIC charger interface. It determines if an EDL cable / test jig or charger pin combination is asserting a forced EDL condition.

### 5.2 Disassembly Walkthrough for Strings

#### A. `"fedl, pmi_not_detected"` (`0x0c2836dc`)
```arm64
0x0c2836d4:  bl    0xc26310c               // Check PMIC charger interface
0x0c2836d8:  cbz   w0, 0xc2836f0           // If return == 0 (PMI detected), branch to normal check
0x0c2836dc:  adrp  x0, 0xc29c000
0x0c2836e0:  mov   w1, wzr
0x0c2836e4:  add   x0, x0, #0x1e6          // "fedl, pmi_not_detected" (0x0c29c1e6)
0x0c2836e8:  bl    0xc259314               // boot_log()
0x0c2836ec:  b     0xc28382c
```

#### B. `"fedl, vbus_low"` (`0x0c2837e0`)
```arm64
0x0c283700:  bl    0xc2bff14               // Read VBUS status from hardware
0x0c283704:  cbnz  w0, 0xc2837d0           // Check for error reading VBUS
0x0c283708:  ldrb  w8, [sp, #12]           // Load VBUS level flag
0x0c28370c:  cbz   w8, 0xc2837e0           // If VBUS is 0 (LOW), branch to log
...
0x0c2837e0:  adrp  x0, 0xc29c000
0x0c2837e4:  mov   w1, wzr
0x0c2837e8:  add   x0, x0, #0x210          // "fedl, vbus_low" (0x0c29c210)
0x0c2837ec:  bl    0xc259314               // boot_log()
```

#### C. `"enter forced EDL"` (`0x0c28391c`)
```arm64
0x0c283910:  bl    0xc2831cc               // Test forced EDL trigger condition
0x0c283914:  tst   w0, #0xff
0x0c283918:  b.eq  0xc283894               // If 0, exit without EDL
0x0c28391c:  adrp  x0, 0xc29c000
0x0c283920:  mov   w1, wzr
0x0c283924:  add   x0, x0, #0x105          // "enter forced EDL" (0x0c29c105)
0x0c283928:  bl    0xc259314               // boot_log()
0x0c28392c:  mov   w0, #0x1388             // 5000 microseconds (5 ms)
0x0c283930:  bl    0xc283024               // boot_delay_microseconds(5000)
0x0c283934:  mov   w0, #0x1                // Return 1 (EDL triggered)
0x0c283938:  b     0xc283898
```

### 5.3 Boot Chain Integration: Caller Thunk & Entry
`qusb_pmi_charger_detect_forced_edl` is invoked during early XBL hardware initialization via a thunk at `0x0c282cec`:

```arm64
// Early Boot Check at 0x0c260e74 (boot_dload_check)
0x0c260e74:  stp   x29, x30, [sp, #-32]!
0x0c260e78:  str   x19, [sp, #16]
0x0c260e7c:  mov   x29, sp
0x0c260e80:  strb  wzr, [x29, #28]
0x0c260e84:  bl    0xc282cec               // Thunk branches directly to 0x0c2834c0
0x0c260e88:  tst   w0, #0xff
0x0c260e8c:  b.eq  0xc260e94               // If 0 (no FEDL requested), continue normal boot
0x0c260e90:  bl    0xc260df8               // If 1 (FEDL requested!), call sbl1_enter_forced_edl_target()
```

---

## 6. Conclusions & Architectural Insights

1. **Dual EDL Trigger Mechanisms Identified:**
   * **Software / Watchdog Failsafe (`dload_entry_count > 1`):**  
     If a system crash or RamDump failure happens twice consecutively without reaching a clean boot reset, `DAT_0c29bbb0` hits `2`. XBL aborts RamDump collection and forces the device into Emergency Download Mode (`05c6:9008`).
   * **Hardware Pin / Cable Failsafe (`qusb_pmi_charger_detect_forced_edl`):**  
     During early boot (`0x0c260e84`), XBL queries the PMIC / USB PHY. If a forced EDL pulse / cable condition is detected, it logs `"enter forced EDL"`, pauses 5 ms (`boot_delay_microseconds(5000)`), and branches into `sbl1_enter_forced_edl_target()`.

2. **Hardware Register Mechanism:**
   * In both cases, the trigger writes `0x1` to physical register `0x003D3000` (`TCSR_BOOT_MISC_DETECT`, Qualcomm `DloadCookieAddr`).
   * This cookie survives the warm reset initiated by `FUN_0c25df84(1)`, directing Qualcomm PBL to boot into Sahara 9008 protocol rather than executing XBL.
