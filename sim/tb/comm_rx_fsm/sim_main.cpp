// =====================================================================
// sim_main.cpp  --  Tests for rtl/comm/comm_rx_fsm.sv
// ---------------------------------------------------------------------
// Coverage:
//   1. ACK frame -> tx_ack pulse, no cm_rx, no ack_q.
//   2. DATA seq=0 (matches expected) -> cm_rx, ack_q seq=0,
//      expected toggles.
//   3. Same DATA seq=0 again (duplicate) -> ack_q only, no cm_rx.
//   4. DATA seq=1 (now matches) -> cm_rx, ack_q seq=1, toggles back.
//   5. HELLO with arbitrary seq -> cm_rx + ack_q, expected NOT changed.
//   6. cm_rx back-pressure: rx_fsm holds DELIVER_BE state.
//   7. ack_q back-pressure: rx_fsm holds QUEUE_ACK state.
// =====================================================================

#include "Vcomm_rx_fsm.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <vector>

static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vcomm_rx_fsm*    dut        = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

static constexpr int MAX_MSG_LEN = 64;
static constexpr int PAYLOAD_W   = MAX_MSG_LEN * 8 / 32;

enum : uint8_t {
    FRAME_DATA     = 0, FRAME_ACK      = 1, FRAME_NAK      = 2,
    FRAME_HELLO    = 3, FRAME_REHELLO  = 4, FRAME_USERNAME = 5,
    FRAME_GOODBYE  = 6,
};

// Captured events.
struct Events {
    bool    cm_rx;
    uint8_t cm_rx_type;
    uint8_t cm_rx_seq;
    uint8_t cm_rx_len;
    uint8_t cm_rx_payload[MAX_MSG_LEN];

    bool    ack_q;
    uint8_t ack_q_seq;

    bool    tx_ack;
    uint8_t tx_ack_seq;
};
static Events ev;

static void clear_events() { ev = Events{}; }

static void payload_clear(uint32_t* sig) {
    for (int w = 0; w < PAYLOAD_W; w++) sig[w] = 0;
}
static void payload_set_byte(uint32_t* sig, int i, uint8_t b) {
    int w = i >> 2, sh = (i & 3) * 8;
    sig[w] = (sig[w] & ~(0xFFu << sh)) | (((uint32_t)b) << sh);
}
static void payload_load(uint32_t* sig, const std::vector<uint8_t>& v) {
    payload_clear(sig);
    for (size_t i = 0; i < v.size() && i < (size_t)MAX_MSG_LEN; i++)
        payload_set_byte(sig, (int)i, v[i]);
}
static uint8_t payload_get_byte(const uint32_t* sig, int i) {
    int w = i >> 2, sh = (i & 3) * 8;
    return (sig[w] >> sh) & 0xFF;
}

// Sample any output handshake / pulse that just fired.
static void sample_outputs() {
    if (dut->tx_ack_valid && !ev.tx_ack) {
        ev.tx_ack     = true;
        ev.tx_ack_seq = (uint8_t)dut->tx_ack_seq;
    }
    if (dut->cm_rx_valid && dut->cm_rx_ready && !ev.cm_rx) {
        ev.cm_rx       = true;
        ev.cm_rx_type  = (uint8_t)dut->cm_rx_frame_type;
        ev.cm_rx_seq   = (uint8_t)dut->cm_rx_seq;
        ev.cm_rx_len   = (uint8_t)dut->cm_rx_len;
        for (int i = 0; i < MAX_MSG_LEN; i++)
            ev.cm_rx_payload[i] = payload_get_byte(dut->cm_rx_payload, i);
    }
    if (dut->ack_q_valid && dut->ack_q_ready && !ev.ack_q) {
        ev.ack_q     = true;
        ev.ack_q_seq = (uint8_t)dut->ack_q_seq;
    }
}

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    sample_outputs();              // pre-edge: handshakes "fire" here
    dut->clk = 1; tick_half();
}

static void reset() {
    dut->rst_n          = 0;
    dut->frame_in_valid = 0;
    dut->frame_in_type  = 0;
    dut->frame_in_seq   = 0;
    dut->frame_in_len   = 0;
    payload_clear(dut->frame_in_payload);
    dut->cm_rx_ready    = 1;
    dut->ack_q_ready    = 1;
    dut->clk            = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    tick();
    clear_events();
}

#define CHECK_EQ(actual, expected, label) do {                            \
    auto _a = (actual); auto _e = (expected);                             \
    if (_a != _e) {                                                       \
        ++g_failures;                                                     \
        printf("  [FAIL @ %lluns] %-44s got=0x%llX expected=0x%llX\n",    \
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

// Inject one frame; loop ticks until the FSM returns to IDLE.
static void inject_and_drain(uint8_t ftype, uint8_t seq,
                             const std::vector<uint8_t>& payload) {
    while (!dut->frame_in_ready) tick();
    dut->frame_in_type = ftype;
    dut->frame_in_seq  = seq;
    dut->frame_in_len  = (uint8_t)payload.size();
    payload_load(dut->frame_in_payload, payload);
    dut->frame_in_valid = 1;
    tick();                                  // handshake cycle
    dut->frame_in_valid = 0;
    // Walk a few cycles to allow DELIVER_BE / QUEUE_ACK to drain.
    for (int i = 0; i < 32; i++) {
        if (dut->frame_in_ready) break;
        tick();
    }
    // small grace period in case still mid-handshake
    for (int i = 0; i < 4; i++) tick();
}

// 1) ACK -> tx_ack pulse only.
static void test_ack_frame() {
    printf("== test_ack_frame\n");
    reset();
    inject_and_drain(FRAME_ACK, 0x55, {});
    CHECK_EQ(ev.tx_ack ? 1 : 0,    1,    "tx_ack pulsed");
    CHECK_EQ((int)ev.tx_ack_seq,   0x55, "tx_ack seq");
    CHECK_EQ(ev.cm_rx  ? 1 : 0,    0,    "no cm_rx");
    CHECK_EQ(ev.ack_q  ? 1 : 0,    0,    "no ack_q");
}

// 2) DATA seq=0 -> cm_rx + ack_q, expected toggles.
static void test_data_match_first() {
    printf("== test_data_match_first\n");
    reset();
    inject_and_drain(FRAME_DATA, 0x00, {'h','i'});
    CHECK_EQ(ev.cm_rx  ? 1 : 0,    1,        "cm_rx delivered");
    CHECK_EQ((int)ev.cm_rx_type,   FRAME_DATA, "cm_rx type");
    CHECK_EQ((int)ev.cm_rx_seq,    0x00,     "cm_rx seq");
    CHECK_EQ((int)ev.cm_rx_len,    2,        "cm_rx len");
    CHECK_EQ((int)ev.cm_rx_payload[0], 'h',  "payload[0]");
    CHECK_EQ((int)ev.cm_rx_payload[1], 'i',  "payload[1]");
    CHECK_EQ(ev.ack_q  ? 1 : 0,    1,        "ack_q enqueued");
    CHECK_EQ((int)ev.ack_q_seq,    0x00,     "ack_q seq");
    CHECK_EQ(ev.tx_ack ? 1 : 0,    0,        "no tx_ack pulse");
}

// 3) Duplicate DATA -> ack_q only.
static void test_data_duplicate() {
    printf("== test_data_duplicate\n");
    reset();
    // First, deliver DATA seq=0 to advance expected.
    inject_and_drain(FRAME_DATA, 0x00, {'a'});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 1, "first DATA delivered");
    clear_events();
    // Now resend DATA seq=0 -- duplicate (expected is now 1).
    inject_and_drain(FRAME_DATA, 0x00, {'a'});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 0, "dup not delivered");
    CHECK_EQ(ev.ack_q ? 1 : 0, 1, "dup still ACKs");
    CHECK_EQ((int)ev.ack_q_seq, 0x00, "ack_q echoes seq");
}

// 4) After delivering seq=0, seq=1 should match next.
static void test_data_alternating() {
    printf("== test_data_alternating\n");
    reset();
    inject_and_drain(FRAME_DATA, 0x00, {'a'});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 1, "seq=0 delivered");
    clear_events();
    inject_and_drain(FRAME_DATA, 0x01, {'b'});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 1, "seq=1 delivered");
    CHECK_EQ((int)ev.cm_rx_payload[0], 'b', "payload");
    clear_events();
    inject_and_drain(FRAME_DATA, 0x01, {'b'});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 0, "second seq=1 dup");
    CHECK_EQ(ev.ack_q ? 1 : 0, 1, "still ACKs");
    clear_events();
    inject_and_drain(FRAME_DATA, 0x00, {'c'});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 1, "seq=0 again delivered");
    CHECK_EQ((int)ev.cm_rx_payload[0], 'c', "payload");
}

// 5) HELLO/USERNAME/GOODBYE always deliver, regardless of seq.
static void test_control_always_delivers() {
    printf("== test_control_always_delivers\n");
    reset();
    // Advance expected by delivering one DATA seq=0.
    inject_and_drain(FRAME_DATA, 0x00, {'x'});
    clear_events();
    // Now HELLO with seq=0 (would be a DATA "duplicate") still delivers.
    inject_and_drain(FRAME_HELLO, 0x00, {'A','l','i','c'});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 1, "HELLO delivered (no dup filter)");
    CHECK_EQ((int)ev.cm_rx_type,   FRAME_HELLO, "type=HELLO");
    CHECK_EQ((int)ev.cm_rx_payload[0], 'A',     "payload[0]");
    CHECK_EQ(ev.ack_q ? 1 : 0, 1, "ACK enqueued");
    clear_events();
    // expected_rx_seq should NOT have toggled by control delivery.
    // Verify by sending DATA seq=1 next -- if expected was 1, this is
    // valid (matches); if HELLO had toggled it to 0, this would dup.
    inject_and_drain(FRAME_DATA, 0x01, {'y'});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 1, "DATA seq=1 still treated as match");

    // GOODBYE always delivers too.
    clear_events();
    inject_and_drain(FRAME_GOODBYE, 0x77, {});
    CHECK_EQ(ev.cm_rx ? 1 : 0, 1, "GOODBYE delivered");
}

// 6) cm_rx back-pressure: held until ready.
static void test_cm_rx_backpressure() {
    printf("== test_cm_rx_backpressure\n");
    reset();
    dut->cm_rx_ready = 0;
    while (!dut->frame_in_ready) tick();
    dut->frame_in_type = FRAME_DATA;
    dut->frame_in_seq  = 0;
    dut->frame_in_len  = 1;
    payload_load(dut->frame_in_payload, {'q'});
    dut->frame_in_valid = 1;
    tick();
    dut->frame_in_valid = 0;
    // Now the FSM should be in DELIVER_BE waiting on cm_rx_ready.
    for (int i = 0; i < 8; i++) tick();
    CHECK_EQ((int)dut->cm_rx_valid, 1, "cm_rx_valid held");
    CHECK_EQ(ev.cm_rx ? 1 : 0,      0, "no completion until ready");
    dut->cm_rx_ready = 1;
    tick();
    CHECK_EQ(ev.cm_rx ? 1 : 0, 1, "cm_rx completes once ready");
    // Drain
    for (int i = 0; i < 8; i++) tick();
}

// 7) ack_q back-pressure: held until ready.
static void test_ack_q_backpressure() {
    printf("== test_ack_q_backpressure\n");
    reset();
    dut->ack_q_ready = 0;
    while (!dut->frame_in_ready) tick();
    dut->frame_in_type = FRAME_DATA;
    dut->frame_in_seq  = 0;
    dut->frame_in_len  = 1;
    payload_load(dut->frame_in_payload, {'r'});
    dut->frame_in_valid = 1;
    tick();
    dut->frame_in_valid = 0;
    // Allow cm_rx to complete (cm_rx_ready=1 from reset). Then stall in QUEUE_ACK.
    for (int i = 0; i < 8; i++) tick();
    CHECK_EQ((int)dut->ack_q_valid, 1, "ack_q_valid held");
    CHECK_EQ(ev.ack_q ? 1 : 0,      0, "no completion until ready");
    dut->ack_q_ready = 1;
    tick();
    CHECK_EQ(ev.ack_q ? 1 : 0, 1, "ack_q completes once ready");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vcomm_rx_fsm;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/comm_rx_fsm.vcd");

    test_ack_frame();
    test_data_match_first();
    test_data_duplicate();
    test_data_alternating();
    test_control_always_delivers();
    test_cm_rx_backpressure();
    test_ack_q_backpressure();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
