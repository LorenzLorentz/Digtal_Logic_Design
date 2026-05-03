// =====================================================================
// sim_main.cpp  --  Tests for rtl/common/handshake_fifo.sv
// ---------------------------------------------------------------------
// Default instantiation: WIDTH=8, DEPTH=16. We exercise the standard
// valid/ready handshake from both sides.
//
// What we cover:
//   1.  test_reset_state          empty=>out_valid=0, in_ready=1
//   2.  test_single_write_read    push 1 byte, pop 1 byte, value matches
//   3.  test_fifo_order           push 3 bytes, pop in same order
//   4.  test_fill_to_capacity     push DEPTH bytes; in_ready drops to 0
//   5.  test_empty_after_drain    after popping all, out_valid drops to 0
//   6.  test_simultaneous_rw      full FIFO, push+pop same cycle: count
//                                 stays full but data flows through
//   7.  test_back_to_back_steady  producer / consumer both 1 entry/cycle:
//                                 occupancy oscillates at 0/1
//   8.  test_blocked_write_drops  with in_valid pulsing while full,
//                                 byte is silently lost (matches the
//                                 "decoder-style" producer that doesn't
//                                 hold valid until ready)
// =====================================================================

#include "Vhandshake_fifo.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>

static vluint64_t           g_time_ns  = 0;
static int                  g_failures = 0;
static Vhandshake_fifo*     dut        = nullptr;
static VerilatedVcdC*       tfp        = nullptr;

static constexpr int FIFO_DEPTH = 16;

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
}

static void clear_inputs() {
    dut->in_valid  = 0;
    dut->in_data   = 0;
    dut->out_ready = 0;
}
static void reset(int cycles = 4) {
    dut->rst_n = 0;
    clear_inputs();
    dut->clk = 0;
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

// Drive a write for one rising edge if ready is high; returns whether
// the handshake actually completed.
static bool push(uint8_t v) {
    dut->in_valid = 1;
    dut->in_data  = v;
    dut->eval();
    bool ok = dut->in_ready;
    tick();
    dut->in_valid = 0;
    dut->in_data  = 0;
    return ok;
}

// Drive a read for one rising edge if valid is high; returns whether
// the handshake actually completed and (via *out) the captured byte.
static bool pop(uint8_t* out) {
    dut->out_ready = 1;
    dut->eval();
    bool ok = dut->out_valid;
    if (ok && out) *out = dut->out_data;
    tick();
    dut->out_ready = 0;
    return ok;
}

// =====================================================================
// Tests
// =====================================================================

static void test_reset_state() {
    printf("== test_reset_state\n");
    reset();
    dut->eval();
    CHECK_EQ(dut->out_valid, 0, "out_valid low (empty)");
    CHECK_EQ(dut->in_ready,  1, "in_ready high (not full)");
}

static void test_single_write_read() {
    printf("== test_single_write_read\n");
    reset();
    CHECK_EQ(push(0x42), true, "push succeeded");
    dut->eval();
    CHECK_EQ(dut->out_valid, 1, "out_valid high after push");
    uint8_t v = 0;
    CHECK_EQ(pop(&v), true, "pop succeeded");
    CHECK_EQ(v,           0x42, "value round-trip");
    dut->eval();
    CHECK_EQ(dut->out_valid, 0, "out_valid low after drain");
}

static void test_fifo_order() {
    printf("== test_fifo_order\n");
    reset();
    push(0xAA); push(0xBB); push(0xCC);
    uint8_t a, b, c;
    pop(&a); pop(&b); pop(&c);
    CHECK_EQ(a, 0xAA, "FIFO[0]");
    CHECK_EQ(b, 0xBB, "FIFO[1]");
    CHECK_EQ(c, 0xCC, "FIFO[2]");
}

// Fill exactly DEPTH entries -> in_ready drops; one more push fails.
static void test_fill_to_capacity() {
    printf("== test_fill_to_capacity\n");
    reset();
    for (int i = 0; i < FIFO_DEPTH; i++) {
        bool ok = push((uint8_t)(i + 1));
        char lbl[40]; snprintf(lbl, sizeof(lbl), "push %d/%d", i+1, FIFO_DEPTH);
        CHECK_EQ(ok, true, lbl);
    }
    dut->eval();
    CHECK_EQ(dut->in_ready, 0, "in_ready drops at full");
    // One more push: in_ready=0, push should fail.
    bool ok = push(0xFF);
    CHECK_EQ(ok, false, "push at full reports !ready");
    // FIFO is still well-formed: drain everything in order.
    for (int i = 0; i < FIFO_DEPTH; i++) {
        uint8_t v = 0;
        pop(&v);
        char lbl[40]; snprintf(lbl, sizeof(lbl), "drained byte %d", i);
        CHECK_EQ(v, (uint8_t)(i + 1), lbl);
    }
}

static void test_empty_after_drain() {
    printf("== test_empty_after_drain\n");
    reset();
    push(0x55); push(0x66);
    pop(nullptr); pop(nullptr);
    dut->eval();
    CHECK_EQ(dut->out_valid, 0, "out_valid low");
    CHECK_EQ(dut->in_ready,  1, "in_ready high (refilled-able)");
}

// FIFO is full; push and pop fire on the same cycle. Net occupancy
// unchanged (still full). The popped value should be the head; the
// pushed value should land at the new tail.
static void test_simultaneous_rw_at_full() {
    printf("== test_simultaneous_rw_at_full\n");
    reset();
    for (int i = 0; i < FIFO_DEPTH; i++) push((uint8_t)i);
    // Sanity: head is 0.
    dut->eval();
    CHECK_EQ(dut->out_data, 0, "head = 0");

    // Concurrent push(0xAA) + pop. Both should succeed.
    dut->in_valid  = 1;
    dut->in_data   = 0xAA;
    dut->out_ready = 1;
    dut->eval();
    bool in_ready_seen  = dut->in_ready;
    bool out_valid_seen = dut->out_valid;
    uint8_t popped       = dut->out_data;
    tick();
    dut->in_valid  = 0;
    dut->in_data   = 0;
    dut->out_ready = 0;

    CHECK_EQ(in_ready_seen,  1,    "in_ready high (slot freed)");
    CHECK_EQ(out_valid_seen, 1,    "out_valid high");
    CHECK_EQ(popped,         0,    "popped value = old head");
    dut->eval();
    CHECK_EQ(dut->in_ready,  0,    "back to full after the swap");

    // Drain: expect 1, 2, ... 15, then 0xAA.
    for (int i = 1; i < FIFO_DEPTH; i++) {
        uint8_t v = 0; pop(&v);
        char lbl[40]; snprintf(lbl, sizeof(lbl), "drain entry %d", i);
        CHECK_EQ(v, (uint8_t)i, lbl);
    }
    uint8_t last = 0; pop(&last);
    CHECK_EQ(last, 0xAA, "last entry is the inserted one");
}

// Producer + consumer both ready every cycle; FIFO sees a steady
// 0-or-1 occupancy. Verify 4 bytes flow through end-to-end.
static void test_back_to_back_steady() {
    printf("== test_back_to_back_steady\n");
    reset();
    uint8_t in[]  = {0x11, 0x22, 0x33, 0x44};
    uint8_t out[4] = {0, 0, 0, 0};
    int popped = 0, pushed = 0;
    while (popped < 4 && g_time_ns < 1'000'000) {
        dut->in_valid  = (pushed < 4) ? 1 : 0;
        dut->in_data   = (pushed < 4) ? in[pushed] : 0;
        dut->out_ready = 1;
        dut->eval();
        bool wr = dut->in_valid  && dut->in_ready;
        bool rd = dut->out_valid && dut->out_ready;
        uint8_t got = dut->out_data;
        tick();
        if (wr) pushed++;
        if (rd) { out[popped++] = got; }
    }
    dut->in_valid  = 0;
    dut->out_ready = 0;
    for (int i = 0; i < 4; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "out[%d] = in[%d]", i, i);
        CHECK_EQ(out[i], in[i], lbl);
    }
}

// Convention pin: if a producer pulses in_valid for one cycle WHILE
// the FIFO is full (in_ready==0), the byte is silently dropped (no
// write happens). This matches the io_ps2_decoder pattern that fires
// 1-cycle ev_valid pulses with no back-pressure.
static void test_blocked_write_drops() {
    printf("== test_blocked_write_drops\n");
    reset();
    for (int i = 0; i < FIFO_DEPTH; i++) push((uint8_t)i);
    dut->eval();
    CHECK_EQ(dut->in_ready, 0, "FIFO full");

    // Pulse in_valid for one cycle with a value that should NOT land.
    dut->in_valid = 1;
    dut->in_data  = 0xEE;
    tick();
    dut->in_valid = 0;
    dut->in_data  = 0;

    // Drain everything; final entry must NOT be 0xEE.
    uint8_t last = 0;
    for (int i = 0; i < FIFO_DEPTH; i++) {
        uint8_t v = 0; pop(&v);
        last = v;
    }
    CHECK_EQ(last, (uint8_t)(FIFO_DEPTH - 1), "last entry is original tail, not the dropped pulse");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vhandshake_fifo;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/handshake_fifo.vcd");

    test_reset_state();
    test_single_write_read();
    test_fifo_order();
    test_fill_to_capacity();
    test_empty_after_drain();
    test_simultaneous_rw_at_full();
    test_back_to_back_steady();
    test_blocked_write_drops();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
