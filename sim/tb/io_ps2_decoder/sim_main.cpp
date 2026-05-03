// =====================================================================
// sim_main.cpp  --  Tests for rtl/io/io_ps2_decoder.sv
// ---------------------------------------------------------------------
// We feed scancode bytes into the decoder one per cycle (with byte_valid
// pulsing) and observe the resulting key events.
//
// Helper feed_byte(b) drives byte_valid=1, byte_data=b for one rising
// edge, then drops byte_valid; the post-edge ev_valid / ev_type /
// ev_ascii reflect what the decoder produced for that byte.
//
// Test surface:
//   1.  test_reset_no_event             -- baseline
//   2.  test_letter_lowercase           -- 'a' make -> KEY_CHAR 'a'
//   3.  test_letter_z_lowercase         -- last letter
//   4.  test_uppercase_via_shift        -- Shift make, letter, Shift release
//   5.  test_uppercase_via_caps         -- CapsLock toggle, letter
//   6.  test_caps_xor_shift             -- Caps + Shift held -> lowercase
//   7.  test_caps_lock_two_presses      -- toggle off, second press -> off
//   8.  test_digit_no_shift             -- '1'
//   9.  test_digit_with_shift           -- Shift+'1' -> '!'
//  10.  test_symbol                     -- '-' / '_'
//  11.  test_space                      -- 0x29 -> ' '
//  12.  test_special_keys               -- ENTER / BACKSPACE / ESC
//  13.  test_extended_arrows            -- E0 6B/74 -> KEY_LEFT/KEY_RIGHT
//  14.  test_release_dropped            -- F0 + letter -> no event
//  15.  test_extended_release_dropped   -- E0 F0 6B -> no event
//  16.  test_bat_byte_dropped           -- 0xAA -> no event
//  17.  test_unknown_scancode_dropped   -- unmapped code -> no event
//  18.  test_consecutive_chars          -- multiple letters in sequence
//  19.  test_shift_make_release_cycle   -- shift state correctly toggled
// =====================================================================

#include "Vio_ps2_decoder.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>

static vluint64_t          g_time_ns  = 0;
static int                 g_failures = 0;
static Vio_ps2_decoder*    dut        = nullptr;
static VerilatedVcdC*      tfp        = nullptr;

// key_type_e mirror
enum : uint8_t { KEY_CHAR = 0, KEY_ENTER = 1, KEY_BACKSPACE = 2,
                 KEY_LEFT = 3, KEY_RIGHT = 4, KEY_ESC = 5,
                 KEY_UP   = 6, KEY_DOWN  = 7 };

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
}

static void reset(int cycles = 4) {
    dut->rst_n      = 0;
    dut->byte_valid = 0;
    dut->byte_data  = 0;
    dut->clk        = 0;
    for (int i = 0; i < cycles; i++) tick();
    dut->rst_n = 1;
    tick();
}

#define CHECK_EQ(actual, expected, label) do {                            \
    auto _a = (actual); auto _e = (expected);                             \
    if (_a != _e) {                                                       \
        ++g_failures;                                                     \
        printf("  [FAIL @ %lluns] %-40s got=0x%02llx expected=0x%02llx\n",\
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

// Drive byte_valid=1 with byte_data=b for one rising edge, then drop.
// Returns the captured event (valid/type/ascii) post-edge.
struct Event { uint8_t valid, type, ascii; };
static Event feed_byte(uint8_t b) {
    dut->byte_valid = 1;
    dut->byte_data  = b;
    tick();
    dut->byte_valid = 0;
    dut->byte_data  = 0;
    dut->eval();
    return Event{ (uint8_t)dut->ev_valid,
                  (uint8_t)dut->ev_type,
                  (uint8_t)dut->ev_ascii };
}

// Feed a sequence and return only the LAST byte's event (others
// inspected separately if the test cares).
static Event feed_seq(std::initializer_list<uint8_t> bytes) {
    Event last = {0,0,0};
    for (uint8_t b : bytes) last = feed_byte(b);
    return last;
}

// =====================================================================
// Tests
// =====================================================================

static void test_reset_no_event() {
    printf("== test_reset_no_event\n");
    reset();
    CHECK_EQ(dut->ev_valid, 0, "ev_valid low after reset");
    // Hold idle for a bit; nothing should fire.
    for (int i = 0; i < 20; i++) tick();
    dut->eval();
    CHECK_EQ(dut->ev_valid, 0, "ev_valid still low without byte_valid");
}

// 'a' make = 0x1C, no shift, no caps -> KEY_CHAR 'a'.
static void test_letter_lowercase() {
    printf("== test_letter_lowercase\n");
    reset();
    Event e = feed_byte(0x1C);
    CHECK_EQ(e.valid, 1,         "event fires");
    CHECK_EQ(e.type,  KEY_CHAR,  "KEY_CHAR");
    CHECK_EQ(e.ascii, (uint8_t)'a', "ascii 'a'");
}

// Make sure another letter (z) also works -- catches table errors.
static void test_letter_z_lowercase() {
    printf("== test_letter_z_lowercase\n");
    reset();
    Event e = feed_byte(0x1A);
    CHECK_EQ(e.valid, 1,            "event fires");
    CHECK_EQ(e.ascii, (uint8_t)'z', "ascii 'z'");
}

// Shift make (0x12), 'a' (0x1C), Shift release (F0 12), 'a' again.
// Expect 'A' for the middle press, 'a' after release.
static void test_uppercase_via_shift() {
    printf("== test_uppercase_via_shift\n");
    reset();
    feed_byte(0x12);                 // Shift make - no event
    Event e1 = feed_byte(0x1C);
    CHECK_EQ(e1.valid, 1, "shift-A event fires");
    CHECK_EQ(e1.ascii, (uint8_t)'A', "ascii 'A'");
    feed_byte(0xF0);                 // release prefix - no event
    feed_byte(0x12);                 // Shift release - no event
    Event e2 = feed_byte(0x1C);
    CHECK_EQ(e2.ascii, (uint8_t)'a', "back to lowercase 'a'");
}

// CapsLock toggle (0x58 make), then letter -> uppercase.
static void test_uppercase_via_caps() {
    printf("== test_uppercase_via_caps\n");
    reset();
    feed_byte(0x58);                 // CapsLock make - no event, toggles caps
    feed_byte(0xF0);                 // release prefix
    feed_byte(0x58);                 // CapsLock release - dropped
    Event e = feed_byte(0x1C);
    CHECK_EQ(e.ascii, (uint8_t)'A', "caps-on 'A'");
}

// Caps on AND Shift held -> letter is LOWERCASE (XOR semantics).
static void test_caps_xor_shift() {
    printf("== test_caps_xor_shift\n");
    reset();
    feed_byte(0x58);  feed_byte(0xF0); feed_byte(0x58);  // CapsLock toggled on
    feed_byte(0x12);                                     // Shift make
    Event e = feed_byte(0x1C);
    CHECK_EQ(e.ascii, (uint8_t)'a', "shift+caps -> lowercase");
}

// Two CapsLock makes -> back to off.
static void test_caps_lock_two_presses() {
    printf("== test_caps_lock_two_presses\n");
    reset();
    feed_byte(0x58); feed_byte(0xF0); feed_byte(0x58);   // toggle on
    feed_byte(0x58); feed_byte(0xF0); feed_byte(0x58);   // toggle off
    Event e = feed_byte(0x1C);
    CHECK_EQ(e.ascii, (uint8_t)'a', "back to lowercase after 2nd toggle");
}

// '1' = 0x16. No shift -> '1'.
static void test_digit_no_shift() {
    printf("== test_digit_no_shift\n");
    reset();
    Event e = feed_byte(0x16);
    CHECK_EQ(e.ascii, (uint8_t)'1', "digit '1'");
}

// Shift + '1' = '!'.
static void test_digit_with_shift() {
    printf("== test_digit_with_shift\n");
    reset();
    feed_byte(0x12);                 // Shift make
    Event e = feed_byte(0x16);
    CHECK_EQ(e.ascii, (uint8_t)'!', "shift digit -> '!'");
}

// '-' / '_' (scan code 0x4E). Caps must NOT affect symbols.
static void test_symbol_minus_underscore() {
    printf("== test_symbol_minus_underscore\n");
    reset();
    Event e1 = feed_byte(0x4E);
    CHECK_EQ(e1.ascii, (uint8_t)'-', "no shift -> '-'");
    feed_byte(0x12);
    Event e2 = feed_byte(0x4E);
    CHECK_EQ(e2.ascii, (uint8_t)'_', "shift -> '_'");
    feed_byte(0xF0); feed_byte(0x12);                    // shift release
    feed_byte(0x58); feed_byte(0xF0); feed_byte(0x58);   // caps on
    Event e3 = feed_byte(0x4E);
    CHECK_EQ(e3.ascii, (uint8_t)'-', "caps does not affect symbol");
}

static void test_space() {
    printf("== test_space\n");
    reset();
    Event e = feed_byte(0x29);
    CHECK_EQ(e.valid, 1,            "space event fires");
    CHECK_EQ(e.ascii, (uint8_t)' ', "ascii ' '");
}

static void test_special_keys() {
    printf("== test_special_keys\n");
    reset();
    Event e1 = feed_byte(0x5A);
    CHECK_EQ(e1.type, KEY_ENTER, "ENTER");
    Event e2 = feed_byte(0x66);
    CHECK_EQ(e2.type, KEY_BACKSPACE, "BACKSPACE");
    Event e3 = feed_byte(0x76);
    CHECK_EQ(e3.type, KEY_ESC, "ESC");
}

static void test_extended_arrows() {
    printf("== test_extended_arrows\n");
    reset();
    feed_byte(0xE0);
    Event eL = feed_byte(0x6B);
    CHECK_EQ(eL.type, KEY_LEFT, "KEY_LEFT");

    feed_byte(0xE0);
    Event eR = feed_byte(0x74);
    CHECK_EQ(eR.type, KEY_RIGHT, "KEY_RIGHT");

    feed_byte(0xE0);
    Event eU = feed_byte(0x75);
    CHECK_EQ(eU.type, KEY_UP, "KEY_UP");

    feed_byte(0xE0);
    Event eD = feed_byte(0x72);
    CHECK_EQ(eD.type, KEY_DOWN, "KEY_DOWN");
}

// Release of a non-shift key (e.g. 'a') is dropped.
static void test_release_dropped() {
    printf("== test_release_dropped\n");
    reset();
    feed_byte(0xF0);
    Event e = feed_byte(0x1C);
    CHECK_EQ(e.valid, 0, "release event dropped");
}

// Extended release: E0 F0 6B -> no event (we don't track LEFT-held state).
static void test_extended_release_dropped() {
    printf("== test_extended_release_dropped\n");
    reset();
    feed_byte(0xE0); feed_byte(0xF0);
    Event e = feed_byte(0x6B);
    CHECK_EQ(e.valid, 0, "extended release dropped");
}

static void test_bat_byte_dropped() {
    printf("== test_bat_byte_dropped\n");
    reset();
    Event e = feed_byte(0xAA);
    CHECK_EQ(e.valid, 0, "0xAA dropped");
    // And it doesn't pollute downstream decoding:
    Event e2 = feed_byte(0x1C);
    CHECK_EQ(e2.valid, 1,            "letter still works after BAT");
    CHECK_EQ(e2.ascii, (uint8_t)'a', "ascii correct");
}

static void test_unknown_scancode_dropped() {
    printf("== test_unknown_scancode_dropped\n");
    reset();
    // 0x77 (NumLock) not in our table.
    Event e = feed_byte(0x77);
    CHECK_EQ(e.valid, 0, "unmapped scancode dropped");
}

// Type "ab12" with shift on the digits and caps on the letter b.
static void test_consecutive_chars() {
    printf("== test_consecutive_chars\n");
    reset();
    Event e;
    e = feed_byte(0x1C);  CHECK_EQ(e.ascii, (uint8_t)'a', "a");
    feed_byte(0x58); feed_byte(0xF0); feed_byte(0x58);  // caps on
    e = feed_byte(0x32);  CHECK_EQ(e.ascii, (uint8_t)'B', "B (caps)");
    feed_byte(0x58); feed_byte(0xF0); feed_byte(0x58);  // caps off
    feed_byte(0x12);                                    // shift hold
    e = feed_byte(0x16);  CHECK_EQ(e.ascii, (uint8_t)'!', "!");
    e = feed_byte(0x1E);  CHECK_EQ(e.ascii, (uint8_t)'@', "@");
    feed_byte(0xF0); feed_byte(0x12);                   // shift release
    e = feed_byte(0x16);  CHECK_EQ(e.ascii, (uint8_t)'1', "1");
}

// After release, holding shift again works.
static void test_shift_make_release_cycle() {
    printf("== test_shift_make_release_cycle\n");
    reset();
    feed_byte(0x12);
    Event e1 = feed_byte(0x1C); CHECK_EQ(e1.ascii, (uint8_t)'A', "A while shift held");
    feed_byte(0xF0); feed_byte(0x12);                   // release
    Event e2 = feed_byte(0x1C); CHECK_EQ(e2.ascii, (uint8_t)'a', "a after release");
    feed_byte(0x12);                                     // shift again
    Event e3 = feed_byte(0x1C); CHECK_EQ(e3.ascii, (uint8_t)'A', "A again");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vio_ps2_decoder;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/io_ps2_decoder.vcd");

    test_reset_no_event();
    test_letter_lowercase();
    test_letter_z_lowercase();
    test_uppercase_via_shift();
    test_uppercase_via_caps();
    test_caps_xor_shift();
    test_caps_lock_two_presses();
    test_digit_no_shift();
    test_digit_with_shift();
    test_symbol_minus_underscore();
    test_space();
    test_special_keys();
    test_extended_arrows();
    test_release_dropped();
    test_extended_release_dropped();
    test_bat_byte_dropped();
    test_unknown_scancode_dropped();
    test_consecutive_chars();
    test_shift_make_release_cycle();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
