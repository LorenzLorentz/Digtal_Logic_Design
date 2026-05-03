// =====================================================================
// sim_main.cpp  --  Tests for rtl/comm/comm_tx_fsm.sv
// ---------------------------------------------------------------------
// TIMEOUT_CYCLES is overridden to 20 in params.txt to keep the TX_FAIL
// path short (~ 5 retries x 20 timeout = 100 cycles).
//
// Coverage:
//   1. Single DATA send + matching ACK -> SUCCESS reported, seq toggled.
//   2. Wrong-seq ACKs ignored: still times out & retries.
//   3. No ACK at all: times out and FAILs after MAX_RETRY+1 attempts.
//   4. Control frame (HELLO) follows ARQ but cm_status NOT reported.
//   5. seq alternates 0,1,0,1 across multiple successful sends.
//   6. Two DATAs back-to-back (second uses next seq).
// =====================================================================

#include "Vcomm_tx_fsm.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <vector>

static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vcomm_tx_fsm*    dut        = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

static constexpr int TIMEOUT_CYCLES = 20;
static constexpr int MAX_RETRY      = 4;     // matches chat_pkg::MAX_RETRY
static constexpr int MAX_MSG_LEN    = 64;
static constexpr int PAYLOAD_W      = MAX_MSG_LEN * 8 / 32;

enum : uint8_t {
    FRAME_DATA     = 0, FRAME_ACK      = 1, FRAME_NAK      = 2,
    FRAME_HELLO    = 3, FRAME_REHELLO  = 4, FRAME_USERNAME = 5,
    FRAME_GOODBYE  = 6,
};
enum : uint8_t { TX_SUCCESS = 0, TX_FAIL = 1 };

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
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

static void reset() {
    dut->rst_n            = 0;
    dut->be_tx_valid      = 0;
    dut->be_tx_frame_type = 0;
    dut->be_tx_msg_id     = 0;
    dut->be_tx_len        = 0;
    payload_clear(dut->be_tx_payload);
    dut->frame_req_ready  = 1;
    dut->ack_valid        = 0;
    dut->ack_seq          = 0;
    dut->cm_status_ready  = 1;
    dut->clk              = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    tick();
}

// Submit a request to the TX FSM. Caller pre-sets parameters.
static void submit_request(uint8_t ftype, uint8_t msg_id,
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

// Wait for frame_req_valid handshake to complete (we always assert ready).
// Returns the seq seen on the bus.
static uint8_t wait_send(uint8_t expected_type, int max_cycles = 4 * TIMEOUT_CYCLES) {
    for (int i = 0; i < max_cycles; i++) {
        if (dut->frame_req_valid) {
            uint8_t got_type = (uint8_t)dut->frame_req_type;
            uint8_t got_seq  = (uint8_t)dut->frame_req_seq;
            CHECK_EQ((int)got_type, (int)expected_type, "frame_req type");
            tick();      // accept the handshake (ready=1)
            return got_seq;
        }
        tick();
    }
    ++g_failures;
    printf("  [FAIL] wait_send timed out\n");
    return 0xFF;
}

// Pulse ACK with given seq for one cycle.
static void pulse_ack(uint8_t seq) {
    dut->ack_valid = 1;
    dut->ack_seq   = seq;
    tick();
    dut->ack_valid = 0;
    dut->ack_seq   = 0;
}

// Wait until cm_status_valid is asserted (with cm_status_ready already 1
// so it self-consumes the next cycle). Returns code.
static int wait_status(uint8_t expected_msg_id, int max_cycles = 4 * TIMEOUT_CYCLES) {
    for (int i = 0; i < max_cycles; i++) {
        if (dut->cm_status_valid) {
            uint8_t mid  = (uint8_t)dut->cm_status_msg_id;
            int     code = (int)dut->cm_status_code;
            CHECK_EQ((int)mid, (int)expected_msg_id, "cm_status msg_id");
            tick();
            return code;
        }
        tick();
    }
    ++g_failures;
    printf("  [FAIL] wait_status timed out\n");
    return -1;
}

// Wait `cycles` ticks while ensuring cm_status_valid never asserts.
static void wait_no_status(int cycles) {
    for (int i = 0; i < cycles; i++) {
        if (dut->cm_status_valid) {
            ++g_failures;
            printf("  [FAIL] unexpected cm_status_valid\n");
            return;
        }
        tick();
    }
}

// 1) DATA + matching ACK -> SUCCESS, seq toggled.
static void test_basic_data_success() {
    printf("== test_basic_data_success\n");
    reset();
    submit_request(FRAME_DATA, 0x42, {'h','i'});
    uint8_t s0 = wait_send(FRAME_DATA);
    CHECK_EQ(s0 & 1, 0, "first send seq[0]=0");
    pulse_ack(s0);
    int code = wait_status(0x42);
    CHECK_EQ(code, TX_SUCCESS, "code = TX_SUCCESS");

    // Second send should use seq=1.
    submit_request(FRAME_DATA, 0x43, {'!'});
    uint8_t s1 = wait_send(FRAME_DATA);
    CHECK_EQ(s1 & 1, 1, "second send seq[0]=1 (toggled)");
    pulse_ack(s1);
    wait_status(0x43);
}

// 2) Wrong-seq ACK ignored; eventually timeout retry; then good ACK -> SUCCESS.
static void test_wrong_seq_ack_then_good() {
    printf("== test_wrong_seq_ack_then_good\n");
    reset();
    submit_request(FRAME_DATA, 0x10, {'a','b'});
    uint8_t s0 = wait_send(FRAME_DATA);
    pulse_ack(s0 ^ 1);                    // wrong seq
    // We should still be waiting; let it time out and retry.
    uint8_t s1 = wait_send(FRAME_DATA);   // retry uses same seq (s0)
    CHECK_EQ((int)s1, (int)s0, "retry uses same seq");
    pulse_ack(s1);
    int code = wait_status(0x10);
    CHECK_EQ(code, TX_SUCCESS, "eventually SUCCESS");
}

// 3) No ACK -> FAIL after MAX_RETRY+1 attempts.
static void test_no_ack_fail() {
    printf("== test_no_ack_fail\n");
    reset();
    submit_request(FRAME_DATA, 0x77, {'x'});
    int sends = 0;
    for (int i = 0; i < MAX_RETRY + 1; i++) {
        bool seen = false;
        for (int t = 0; t < TIMEOUT_CYCLES + 4; t++) {
            if (dut->frame_req_valid) {
                tick();
                seen = true;
                break;
            }
            tick();
        }
        if (!seen) {
            ++g_failures;
            printf("  [FAIL] expected send #%d never appeared\n", i + 1);
            return;
        }
        sends++;
    }
    CHECK_EQ(sends, MAX_RETRY + 1, "total attempts = MAX_RETRY+1");
    int code = wait_status(0x77);
    CHECK_EQ(code, TX_FAIL, "code = TX_FAIL");
}

// 4) Control frame: ARQ but no cm_status.
static void test_control_frame_no_status() {
    printf("== test_control_frame_no_status\n");
    reset();
    submit_request(FRAME_HELLO, 0xAB, {'A','l','i','c'});
    uint8_t s0 = wait_send(FRAME_HELLO);
    pulse_ack(s0);
    // Should NOT report. Return to IDLE.
    wait_no_status(8);
    CHECK_EQ((int)dut->be_tx_ready, 1, "back to IDLE after control success");
}

// 5) seq alternates 0,1,0,1 across multiple successes.
static void test_seq_alternation() {
    printf("== test_seq_alternation\n");
    reset();
    int expected_seq[] = {0, 1, 0, 1};
    for (int i = 0; i < 4; i++) {
        submit_request(FRAME_DATA, (uint8_t)i, {(uint8_t)('A' + i)});
        uint8_t s = wait_send(FRAME_DATA);
        char lbl[64];
        std::snprintf(lbl, sizeof(lbl), "iter %d seq[0]", i);
        CHECK_EQ(s & 1, expected_seq[i], lbl);
        pulse_ack(s);
        wait_status((uint8_t)i);
    }
}

// 6) Control frame fail: also no status.
static void test_control_frame_fail_silent() {
    printf("== test_control_frame_fail_silent\n");
    reset();
    submit_request(FRAME_GOODBYE, 0, {});
    // Drain through MAX_RETRY+1 attempts without ACKing.
    for (int i = 0; i < MAX_RETRY + 1; i++) {
        for (int t = 0; t < TIMEOUT_CYCLES + 4; t++) {
            if (dut->frame_req_valid) { tick(); break; }
            tick();
        }
    }
    // Wait timeout to expire, FSM should return to IDLE silently.
    for (int i = 0; i < TIMEOUT_CYCLES + 8; i++) {
        if (dut->cm_status_valid) {
            ++g_failures;
            printf("  [FAIL] unexpected cm_status_valid for control fail\n");
        }
        tick();
        if (dut->be_tx_ready) break;
    }
    CHECK_EQ((int)dut->be_tx_ready, 1, "IDLE after control fail (silent)");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vcomm_tx_fsm;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/comm_tx_fsm.vcd");

    test_basic_data_success();
    test_wrong_seq_ack_then_good();
    test_no_ack_fail();
    test_control_frame_no_status();
    test_seq_alternation();
    test_control_frame_fail_silent();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
