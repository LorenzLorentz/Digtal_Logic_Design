// =====================================================================
// sim_main.cpp  --  Tests for rtl/io/io_top.sv
// ---------------------------------------------------------------------
// End-to-end integration: drive raw PS/2 waveforms on (ps2_clk, ps2_data),
// observe the io_key_* handshake on the backend-facing port.
//
// Test surface:
//   1.  test_reset                       quiet on the backend port
//   2.  test_single_letter_a             0x1C -> KEY_CHAR 'a'
//   3.  test_uppercase_via_shift         shift+0x1C -> KEY_CHAR 'A'
//   4.  test_special_enter               0x5A -> KEY_ENTER
//   5.  test_arrow_left                  0xE0,0x6B -> KEY_LEFT
//   6.  test_buffered_keys_in_order      type 'h','i' before backend
//                                        consumes -> drains in order
//   7.  test_backpressure_buffers_event  hold io_key_ready=0 while a key
//                                        arrives, then release: still
//                                        receives the key
// =====================================================================

#include "Vio_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>

static vluint64_t   g_time_ns  = 0;
static int          g_failures = 0;
static Vio_top*     dut        = nullptr;
static VerilatedVcdC* tfp      = nullptr;

// PS/2 timing for tests: small but >= 2-FF synchroniser depth.
static constexpr int BIT_HALF_CYCLES = 10;

// key_type_e mirror.
enum : uint8_t { KEY_CHAR = 0, KEY_ENTER = 1, KEY_BACKSPACE = 2,
                 KEY_LEFT = 3, KEY_RIGHT = 4, KEY_ESC = 5 };

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
    dut->rst_n        = 0;
    dut->ps2_clk      = 1;            // idle high
    dut->ps2_data     = 1;
    dut->io_key_ready = 0;            // default: don't drain
    dut->clk          = 0;
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

// ---- PS/2 bit driver ----------------------------------------------------
static void ps2_send_bit(uint8_t b) {
    dut->ps2_data = b;
    for (int i = 0; i < 4; i++) tick();
    dut->ps2_clk = 0;
    for (int i = 0; i < BIT_HALF_CYCLES; i++) tick();
    dut->ps2_clk = 1;
    for (int i = 0; i < BIT_HALF_CYCLES; i++) tick();
}

static uint8_t odd_parity(uint8_t b) {
    uint8_t p = 1;
    for (int i = 0; i < 8; i++) p ^= (b >> i) & 1;
    return p;
}

static void ps2_send_byte(uint8_t b) {
    ps2_send_bit(0);
    for (int i = 0; i < 8; i++) ps2_send_bit((b >> i) & 1);
    ps2_send_bit(odd_parity(b));
    ps2_send_bit(1);
    // Trailing idle so the decoder & FIFO settle before the next byte.
    for (int i = 0; i < 30; i++) tick();
}

// ---- io_key receive helpers --------------------------------------------
//
// Consume one io_key event via the standard valid/ready handshake.
// Returns whether an event was captured within the timeout.
struct IoEvent { uint8_t type, ascii; };

static bool recv_io_key(IoEvent* out, int timeout_cycles = 2000) {
    dut->io_key_ready = 1;
    for (int i = 0; i < timeout_cycles; i++) {
        dut->eval();
        if (dut->io_key_valid) {
            out->type  = dut->io_key_type;
            out->ascii = dut->io_key_ascii;
            tick();   // complete handshake
            dut->io_key_ready = 0;
            return true;
        }
        tick();
    }
    dut->io_key_ready = 0;
    return false;
}

// =====================================================================
// Tests
// =====================================================================

static void test_reset() {
    printf("== test_reset\n");
    reset();
    dut->eval();
    CHECK_EQ(dut->io_key_valid, 0, "io_key_valid low after reset");
    // Hold for a while, no spurious activity.
    for (int i = 0; i < 200; i++) tick();
    dut->eval();
    CHECK_EQ(dut->io_key_valid, 0, "still low without PS/2 traffic");
}

static void test_single_letter_a() {
    printf("== test_single_letter_a\n");
    reset();
    ps2_send_byte(0x1C);
    IoEvent e;
    CHECK_EQ(recv_io_key(&e), true, "event received");
    CHECK_EQ(e.type,  KEY_CHAR,     "KEY_CHAR");
    CHECK_EQ(e.ascii, (uint8_t)'a', "ascii 'a'");
}

static void test_uppercase_via_shift() {
    printf("== test_uppercase_via_shift\n");
    reset();
    ps2_send_byte(0x12);             // Shift make
    ps2_send_byte(0x1C);             // 'A'
    ps2_send_byte(0xF0);             // release prefix
    ps2_send_byte(0x12);             // Shift release
    ps2_send_byte(0x1C);             // 'a'

    IoEvent e1, e2;
    CHECK_EQ(recv_io_key(&e1), true, "first event");
    CHECK_EQ(e1.ascii, (uint8_t)'A', "uppercase A");
    CHECK_EQ(recv_io_key(&e2), true, "second event");
    CHECK_EQ(e2.ascii, (uint8_t)'a', "lowercase a");
}

static void test_special_enter() {
    printf("== test_special_enter\n");
    reset();
    ps2_send_byte(0x5A);
    IoEvent e;
    CHECK_EQ(recv_io_key(&e), true,  "enter event received");
    CHECK_EQ(e.type, KEY_ENTER,      "KEY_ENTER");
}

static void test_arrow_left() {
    printf("== test_arrow_left\n");
    reset();
    ps2_send_byte(0xE0);
    ps2_send_byte(0x6B);
    IoEvent e;
    CHECK_EQ(recv_io_key(&e), true, "left arrow event received");
    CHECK_EQ(e.type, KEY_LEFT,      "KEY_LEFT");
}

// Type two letters with the backend port idle (io_key_ready=0). Both
// events sit in the FIFO; once we start reading they emerge in order.
static void test_buffered_keys_in_order() {
    printf("== test_buffered_keys_in_order\n");
    reset();
    // Backend is NOT consuming. FIFO holds events.
    ps2_send_byte(0x33);             // 'h'
    ps2_send_byte(0x43);             // 'i'

    IoEvent e1, e2;
    CHECK_EQ(recv_io_key(&e1), true, "first event drains");
    CHECK_EQ(e1.ascii, (uint8_t)'h', "first is 'h'");
    CHECK_EQ(recv_io_key(&e2), true, "second event drains");
    CHECK_EQ(e2.ascii, (uint8_t)'i', "second is 'i'");
}

// Drive a key, then keep io_key_ready=0 for many cycles. Verify the
// FIFO continues to assert valid (event is not lost). Then release and
// receive normally.
static void test_backpressure_buffers_event() {
    printf("== test_backpressure_buffers_event\n");
    reset();
    ps2_send_byte(0x1C);             // 'a'
    // Wait until the FIFO has it.
    int waited = 0;
    while (!dut->io_key_valid && waited < 2000) { tick(); dut->eval(); waited++; }
    CHECK_EQ((bool)dut->io_key_valid, true, "valid asserted");
    // Hold ready=0 for a long stretch.
    for (int i = 0; i < 500; i++) tick();
    dut->eval();
    CHECK_EQ((bool)dut->io_key_valid, true, "valid still asserted under back-pressure");

    // Now release and receive.
    IoEvent e;
    CHECK_EQ(recv_io_key(&e), true,  "event received after release");
    CHECK_EQ(e.ascii, (uint8_t)'a',  "ascii 'a'");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vio_top;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/io_top.vcd");

    test_reset();
    test_single_letter_a();
    test_uppercase_via_shift();
    test_special_enter();
    test_arrow_left();
    test_buffered_keys_in_order();
    test_backpressure_buffers_event();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
