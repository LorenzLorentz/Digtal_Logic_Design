// =====================================================================
// sim_main.cpp  --  comm_top loopback integration
// ---------------------------------------------------------------------
// uart_txd is looped to uart_rxd of the same comm_top instance, so a
// DATA send round-trips: DATA -> remote (= self) cm_rx -> ACK -> tx
// SUCCESS. Verifies the full link layer end-to-end.
//
// Coverage:
//   1. DATA round trip: cm_rx received same payload, cm_status SUCCESS.
//   2. Multiple back-to-back DATAs: msg_ids tracked, all SUCCESS.
//   3. HELLO/USERNAME (control frames): cm_rx delivered, no cm_status.
// =====================================================================

#include "Vcomm_top_lb.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <queue>
#include <vector>

static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vcomm_top_lb*    dut        = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

static constexpr int MAX_MSG_LEN = 64;
static constexpr int PAYLOAD_W   = MAX_MSG_LEN * 8 / 32;

enum : uint8_t {
    FRAME_DATA     = 0, FRAME_ACK      = 1, FRAME_NAK      = 2,
    FRAME_HELLO    = 3, FRAME_REHELLO  = 4, FRAME_USERNAME = 5,
    FRAME_GOODBYE  = 6,
};
enum : uint8_t { TX_SUCCESS = 0, TX_FAIL = 1 };

struct RxEvt {
    uint8_t  type;
    uint8_t  seq;
    uint8_t  len;
    uint8_t  payload[MAX_MSG_LEN];
};
struct StatusEvt {
    uint8_t  msg_id;
    uint8_t  code;
};

static std::queue<RxEvt>     rx_q;
static std::queue<StatusEvt> status_q;

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

static void sample_outputs() {
    if (dut->cm_rx_valid && dut->cm_rx_ready) {
        RxEvt e;
        e.type = (uint8_t)dut->cm_rx_frame_type;
        e.seq  = (uint8_t)dut->cm_rx_seq;
        e.len  = (uint8_t)dut->cm_rx_len;
        for (int i = 0; i < MAX_MSG_LEN; i++)
            e.payload[i] = payload_get_byte(dut->cm_rx_payload, i);
        rx_q.push(e);
    }
    if (dut->cm_status_valid && dut->cm_status_ready) {
        StatusEvt e;
        e.msg_id = (uint8_t)dut->cm_status_msg_id;
        e.code   = (uint8_t)dut->cm_status_code;
        status_q.push(e);
    }
}

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    sample_outputs();              // pre-edge: handshakes fire here
    dut->clk = 1; tick_half();
}

static void reset() {
    dut->rst_n            = 0;
    dut->be_tx_valid      = 0;
    dut->be_tx_frame_type = 0;
    dut->be_tx_msg_id     = 0;
    dut->be_tx_len        = 0;
    payload_clear(dut->be_tx_payload);
    dut->cm_rx_ready      = 1;
    dut->cm_status_ready  = 1;
    dut->clk              = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    for (int i = 0; i < 16; i++) tick();
    while (!rx_q.empty())     rx_q.pop();
    while (!status_q.empty()) status_q.pop();
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

// Submit a request; do NOT wait. Caller continues ticking.
static void submit(uint8_t ftype, uint8_t msg_id,
                   const std::vector<uint8_t>& payload) {
    while (!dut->be_tx_ready) tick();
    dut->be_tx_frame_type = ftype;
    dut->be_tx_msg_id     = msg_id;
    dut->be_tx_len        = (uint8_t)payload.size();
    payload_load(dut->be_tx_payload, payload);
    dut->be_tx_valid      = 1;
    tick();
    dut->be_tx_valid      = 0;
}

// Run cycles until rx_q has at least one event, or timeout.
static bool wait_rx(RxEvt& out, int max_cycles = 8000) {
    for (int i = 0; i < max_cycles; i++) {
        if (!rx_q.empty()) { out = rx_q.front(); rx_q.pop(); return true; }
        tick();
    }
    return false;
}
static bool wait_status(StatusEvt& out, int max_cycles = 8000) {
    for (int i = 0; i < max_cycles; i++) {
        if (!status_q.empty()) { out = status_q.front(); status_q.pop(); return true; }
        tick();
    }
    return false;
}

// 1) DATA round trip.
static void test_data_roundtrip() {
    printf("== test_data_roundtrip\n");
    reset();
    std::vector<uint8_t> p = {'h','i','!'};
    submit(FRAME_DATA, 0x42, p);
    RxEvt rx;
    CHECK_EQ(wait_rx(rx) ? 1 : 0, 1, "cm_rx received");
    CHECK_EQ((int)rx.type, FRAME_DATA, "rx type=DATA");
    CHECK_EQ((int)rx.len,  (int)p.size(), "rx len");
    for (size_t i = 0; i < p.size(); i++) {
        char lbl[40];
        std::snprintf(lbl, sizeof(lbl), "rx payload[%zu]", i);
        CHECK_EQ((int)rx.payload[i], (int)p[i], lbl);
    }
    StatusEvt s;
    CHECK_EQ(wait_status(s) ? 1 : 0, 1, "cm_status received");
    CHECK_EQ((int)s.msg_id, 0x42, "status msg_id");
    CHECK_EQ((int)s.code,   TX_SUCCESS, "status SUCCESS");
}

// 2) Multiple DATAs back-to-back.
static void test_multiple_data() {
    printf("== test_multiple_data\n");
    reset();
    struct Item { uint8_t mid; std::vector<uint8_t> p; };
    std::vector<Item> items = {
        {0x01, {'A'}},
        {0x02, {'B','C'}},
        {0x03, {'X','Y','Z'}},
    };
    for (auto& it : items) {
        submit(FRAME_DATA, it.mid, it.p);
        RxEvt rx; StatusEvt s;
        CHECK_EQ(wait_rx(rx) ? 1 : 0, 1, "cm_rx received");
        CHECK_EQ((int)rx.len, (int)it.p.size(), "rx len matches");
        for (size_t i = 0; i < it.p.size(); i++)
            CHECK_EQ((int)rx.payload[i], (int)it.p[i], "rx byte");
        CHECK_EQ(wait_status(s) ? 1 : 0, 1, "status");
        CHECK_EQ((int)s.msg_id, (int)it.mid, "status msg_id");
        CHECK_EQ((int)s.code,   TX_SUCCESS, "status SUCCESS");
    }
}

// 3) Control frame: HELLO delivers cm_rx, no cm_status.
static void test_hello_no_status() {
    printf("== test_hello_no_status\n");
    reset();
    submit(FRAME_HELLO, 0xAA, {'A','l','i','c'});
    RxEvt rx;
    CHECK_EQ(wait_rx(rx) ? 1 : 0, 1, "HELLO delivered as cm_rx");
    CHECK_EQ((int)rx.type, FRAME_HELLO, "type=HELLO");
    CHECK_EQ((int)rx.payload[0], 'A', "payload[0]");
    // Drain a generous window; ensure no cm_status.
    for (int i = 0; i < 4000; i++) {
        if (!status_q.empty()) {
            ++g_failures;
            printf("  [FAIL] unexpected cm_status for HELLO\n");
            return;
        }
        tick();
    }
    CHECK_EQ((int)dut->be_tx_ready, 1, "tx_fsm back to IDLE silently");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vcomm_top_lb;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/comm_top.vcd");

    test_data_roundtrip();
    test_multiple_data();
    test_hello_no_status();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
