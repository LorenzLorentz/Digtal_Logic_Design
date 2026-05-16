// =====================================================================
// sim_main.cpp  --  Tests for rtl/comm/comm_frame_encoder.sv
// ---------------------------------------------------------------------
// Drives a frame request, captures the byte stream produced on the
// downstream handshake, and compares it byte-for-byte against the
// software model (matches scripts/frame_codec.py).
//
// Coverage:
//   1. DATA with non-empty payload.
//   2. HELLO with username payload.
//   3. ACK / GOODBYE (zero payload, just SOF/TYPE/SEQ/LEN/CRC).
//   4. Payload containing the SOF byte (no escaping required).
//   5. Back-to-back frames.
//   6. byte_out_ready throttling (consumer applies back-pressure).
// =====================================================================

#include "Vcomm_frame_encoder.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

static vluint64_t              g_time_ns  = 0;
static int                     g_failures = 0;
static Vcomm_frame_encoder*    dut        = nullptr;
static VerilatedVcdC*          tfp        = nullptr;

static constexpr int MAX_MSG_LEN = 128;
static constexpr int PAYLOAD_W   = MAX_MSG_LEN * 8 / 32;     // 32 dwords
static constexpr uint8_t SOF_BYTE = 0x7E;

// frame_type_e
enum : uint8_t {
    FRAME_DATA     = 0, FRAME_ACK      = 1, FRAME_NAK      = 2,
    FRAME_HELLO    = 3, FRAME_REHELLO  = 4, FRAME_USERNAME = 5,
    FRAME_GOODBYE  = 6,
};

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
        printf("  [FAIL @ %lluns] %-40s got=0x%llX expected=0x%llX\n",    \
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

// Wide-signal helpers.
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

// ---- Software CRC reference ----
static uint16_t sw_crc16_step(uint16_t c, uint8_t b) {
    c ^= ((uint16_t)b) << 8;
    for (int i = 0; i < 8; i++)
        c = (c & 0x8000) ? (uint16_t)((c << 1) ^ 0x1021) : (uint16_t)(c << 1);
    return c;
}
static uint16_t sw_crc16(const std::vector<uint8_t>& v) {
    uint16_t c = 0xFFFF;
    for (uint8_t b : v) c = sw_crc16_step(c, b);
    return c;
}

// Software-encode: returns the canonical wire byte stream.
// Wire layout: SOF | TYPE | SEQ | LEN_HI | LEN_LO | PAYLOAD[..] | CRC_HI | CRC_LO
static std::vector<uint8_t> sw_encode(uint8_t ftype, uint8_t seq,
                                      const std::vector<uint8_t>& payload) {
    std::vector<uint8_t> body;
    body.push_back(ftype & 0x07);
    body.push_back(seq);
    uint16_t L = (uint16_t)payload.size();
    body.push_back((uint8_t)((L >> 8) & 0xFF));
    body.push_back((uint8_t)(L & 0xFF));
    for (uint8_t b : payload) body.push_back(b);
    uint16_t c = sw_crc16(body);
    std::vector<uint8_t> out;
    out.push_back(SOF_BYTE);
    for (uint8_t b : body) out.push_back(b);
    out.push_back((uint8_t)((c >> 8) & 0xFF));
    out.push_back((uint8_t)(c & 0xFF));
    return out;
}

static void reset() {
    dut->rst_n          = 0;
    dut->frame_in_valid = 0;
    dut->frame_in_type  = 0;
    dut->frame_in_seq   = 0;
    dut->frame_in_len   = 0;
    payload_clear(dut->frame_in_payload);
    dut->byte_out_ready = 1;
    dut->clk            = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    tick();
}

// Drive a frame request; capture the produced byte stream.
// `consumer_pattern` (optional): a vector of 0/1 used to throttle
// byte_out_ready (cycles the consumer is "busy" -> ready=0). When the
// vector runs out we just keep ready=1.
static std::vector<uint8_t> send_frame(uint8_t ftype, uint8_t seq,
                                       const std::vector<uint8_t>& payload,
                                       const std::vector<int>* consumer_pattern = nullptr,
                                       int max_cycles = 4096) {
    // Wait for ready.
    while (!dut->frame_in_ready) tick();
    dut->frame_in_type = ftype;
    dut->frame_in_seq  = seq;
    dut->frame_in_len  = (uint16_t)payload.size();
    payload_load(dut->frame_in_payload, payload);
    dut->frame_in_valid = 1;
    tick();
    dut->frame_in_valid = 0;

    std::vector<uint8_t> out;
    int pi = 0;
    for (int c = 0; c < max_cycles; c++) {
        // Apply ready
        if (consumer_pattern && pi < (int)consumer_pattern->size()) {
            dut->byte_out_ready = (*consumer_pattern)[pi++] ? 1 : 0;
        } else {
            dut->byte_out_ready = 1;
        }
        // Capture if handshake completes.
        if (dut->byte_out_valid && dut->byte_out_ready) {
            out.push_back((uint8_t)dut->byte_out_data);
        }
        tick();
        // Done when we are back in IDLE (frame_in_ready) AND we already
        // captured at least the SOF.
        if (!out.empty() && dut->frame_in_ready) break;
    }
    dut->byte_out_ready = 1;
    return out;
}

static const char* fname(uint8_t t) {
    switch (t) {
        case FRAME_DATA: return "DATA";
        case FRAME_ACK:  return "ACK";
        case FRAME_NAK:  return "NAK";
        case FRAME_HELLO:return "HELLO";
        case FRAME_REHELLO:return "REHELLO";
        case FRAME_USERNAME:return "USERNAME";
        case FRAME_GOODBYE:return "GOODBYE";
        default: return "?";
    }
}

static void check_stream_eq(const std::vector<uint8_t>& got,
                            const std::vector<uint8_t>& want,
                            const char* tag) {
    if (got.size() != want.size()) {
        ++g_failures;
        printf("  [FAIL] %s: length mismatch got=%zu want=%zu\n",
               tag, got.size(), want.size());
        return;
    }
    for (size_t i = 0; i < got.size(); i++) {
        if (got[i] != want[i]) {
            ++g_failures;
            printf("  [FAIL] %s: byte %zu got=0x%02X want=0x%02X\n",
                   tag, i, got[i], want[i]);
            return;
        }
    }
}

static void test_data_frame() {
    printf("== test_data_frame\n");
    reset();
    std::vector<uint8_t> payload = {'h','e','l','l','o'};
    auto got  = send_frame(FRAME_DATA, 0, payload);
    auto want = sw_encode(FRAME_DATA, 0, payload);
    check_stream_eq(got, want, "DATA payload=hello");
}

static void test_hello_frame() {
    printf("== test_hello_frame\n");
    reset();
    std::vector<uint8_t> name = {'A','l','i','c','e'};
    auto got  = send_frame(FRAME_HELLO, 1, name);
    auto want = sw_encode(FRAME_HELLO, 1, name);
    check_stream_eq(got, want, "HELLO Alice");
}

static void test_no_payload_frames() {
    printf("== test_no_payload_frames\n");
    for (uint8_t t : {FRAME_ACK, FRAME_GOODBYE, FRAME_NAK}) {
        reset();
        auto got  = send_frame(t, 7, {});
        auto want = sw_encode(t, 7, {});
        char lbl[64];
        std::snprintf(lbl, sizeof(lbl), "%s seq=7 empty", fname(t));
        check_stream_eq(got, want, lbl);
    }
}

static void test_payload_with_sof() {
    printf("== test_payload_with_sof\n");
    reset();
    std::vector<uint8_t> p = {0x7E, 0x01, 0x7E, 0x7E, 0x42};
    auto got  = send_frame(FRAME_DATA, 1, p);
    auto want = sw_encode(FRAME_DATA, 1, p);
    check_stream_eq(got, want, "DATA payload-with-SOF (no-escape policy)");
    // Verify the SOFs are still inline in the wire bytes -- not escaped.
    int sof_count = 0;
    for (uint8_t b : got) if (b == SOF_BYTE) sof_count++;
    if (sof_count < 4) {
        ++g_failures;
        printf("  [FAIL] expected >= 4 SOFs in stream, got %d\n", sof_count);
    }
}

static void test_back_to_back() {
    printf("== test_back_to_back\n");
    reset();
    auto a_got = send_frame(FRAME_HELLO, 0, {'A','l','i','c'});
    auto b_got = send_frame(FRAME_DATA,  1, {'h','i'});
    auto a_want = sw_encode(FRAME_HELLO, 0, {'A','l','i','c'});
    auto b_want = sw_encode(FRAME_DATA,  1, {'h','i'});
    check_stream_eq(a_got, a_want, "back-to-back A");
    check_stream_eq(b_got, b_want, "back-to-back B");
}

static void test_consumer_throttle() {
    printf("== test_consumer_throttle\n");
    reset();
    // Pattern: ready=0 for 2 cycles, ready=1 for 1, repeat.
    std::vector<int> pattern;
    for (int i = 0; i < 200; i++) pattern.push_back((i % 3) == 2 ? 1 : 0);
    auto got  = send_frame(FRAME_DATA, 5, {0xDE, 0xAD, 0xBE, 0xEF}, &pattern);
    auto want = sw_encode(FRAME_DATA, 5, {0xDE, 0xAD, 0xBE, 0xEF});
    check_stream_eq(got, want, "DATA with throttled consumer");
}

static void test_max_payload() {
    printf("== test_max_payload\n");
    reset();
    std::vector<uint8_t> p(MAX_MSG_LEN);
    for (int i = 0; i < MAX_MSG_LEN; i++) p[i] = (uint8_t)(i ^ 0xA5);
    auto got  = send_frame(FRAME_DATA, 9, p);
    auto want = sw_encode(FRAME_DATA, 9, p);
    char lbl[40]; snprintf(lbl, sizeof(lbl), "DATA len=%d (max)", MAX_MSG_LEN);
    check_stream_eq(got, want, lbl);
}

// Range coverage at the LEN_HI/LEN_LO boundary. With MAX_MSG_LEN=128
// every encoded length has LEN_HI == 0, but the boundaries near 64,
// 127, and 128 still exercise the loop / payload-size path.
static void test_len_range() {
    printf("== test_len_range\n");
    reset();
    for (int L : {1, 64, MAX_MSG_LEN - 1, MAX_MSG_LEN}) {
        std::vector<uint8_t> p(L);
        for (int i = 0; i < L; i++) p[i] = (uint8_t)((i * 31 + 17) & 0xFF);
        auto got  = send_frame(FRAME_DATA, (uint8_t)(L & 0xFF), p);
        auto want = sw_encode(FRAME_DATA, (uint8_t)(L & 0xFF), p);
        char lbl[40]; snprintf(lbl, sizeof(lbl), "DATA len=%d", L);
        check_stream_eq(got, want, lbl);
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vcomm_frame_encoder;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/comm_frame_encoder.vcd");

    test_data_frame();
    test_hello_frame();
    test_no_payload_frames();
    test_payload_with_sof();
    test_back_to_back();
    test_consumer_throttle();
    test_max_payload();
    test_len_range();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
