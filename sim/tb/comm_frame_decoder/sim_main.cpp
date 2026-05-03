// =====================================================================
// sim_main.cpp  --  Tests for rtl/comm/comm_frame_decoder.sv
// ---------------------------------------------------------------------
// Feeds canned byte streams (good frames, bad CRC, malformed LEN, junk
// before SOF, SOF inside payload) and verifies what the decoder
// delivers to the rx-fsm side.
//
// Coverage:
//   1. Single good DATA frame: delivered with correct fields.
//   2. Frame with empty payload (ACK / GOODBYE): no payload bytes.
//   3. Frame with payload containing 0x7E: no false re-sync.
//   4. Junk leading bytes: ignored, decoder syncs on real SOF.
//   5. Bad CRC: drop_pulse fires, no delivery, recovers on next frame.
//   6. Malformed LEN > MAX_MSG_LEN: drop_pulse fires, recovers.
//   7. Back-to-back frames.
//   8. rx_fsm back-pressure: held in DELIVER until ready.
// =====================================================================

#include "Vcomm_frame_decoder.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <vector>

static vluint64_t              g_time_ns  = 0;
static int                     g_failures = 0;
static Vcomm_frame_decoder*    dut        = nullptr;
static VerilatedVcdC*          tfp        = nullptr;

static constexpr int      MAX_MSG_LEN = 64;
static constexpr int      PAYLOAD_W   = MAX_MSG_LEN * 8 / 32;
static constexpr uint8_t  SOF_BYTE    = 0x7E;

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
        printf("  [FAIL @ %lluns] %-44s got=0x%llX expected=0x%llX\n",    \
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

static uint8_t payload_get_byte(const uint32_t* sig, int i) {
    int w = i >> 2, sh = (i & 3) * 8;
    return (sig[w] >> sh) & 0xFF;
}

// ---- software CRC (mirrors hw) ----
static uint16_t sw_crc16(const std::vector<uint8_t>& v) {
    uint16_t c = 0xFFFF;
    for (uint8_t b : v) {
        c ^= ((uint16_t)b) << 8;
        for (int i = 0; i < 8; i++)
            c = (c & 0x8000) ? (uint16_t)((c << 1) ^ 0x1021) : (uint16_t)(c << 1);
    }
    return c;
}
static std::vector<uint8_t> encode(uint8_t ftype, uint8_t seq,
                                   const std::vector<uint8_t>& payload) {
    std::vector<uint8_t> body;
    body.push_back(ftype & 0x07);
    body.push_back(seq);
    body.push_back((uint8_t)payload.size());
    for (uint8_t b : payload) body.push_back(b);
    uint16_t c = sw_crc16(body);
    std::vector<uint8_t> out;
    out.push_back(SOF_BYTE);
    for (uint8_t b : body) out.push_back(b);
    out.push_back((uint8_t)((c >> 8) & 0xFF));
    out.push_back((uint8_t)(c & 0xFF));
    return out;
}

// Captured event from a feed sequence.
struct DeliverEvt {
    uint8_t  ftype;
    uint8_t  seq;
    uint8_t  len;
    uint8_t  payload[MAX_MSG_LEN];
};

static void reset() {
    dut->rst_n           = 0;
    dut->byte_in_valid   = 0;
    dut->byte_in_data    = 0;
    dut->frame_out_ready = 1;
    dut->clk             = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    tick();
}

// Push a single byte into the decoder over one clock cycle.
static void push_byte(uint8_t b) {
    dut->byte_in_valid = 1;
    dut->byte_in_data  = b;
    tick();
    dut->byte_in_valid = 0;
    dut->byte_in_data  = 0;
}

// Capture frame_out if asserted (current state). Caller asserts ready
// to consume.
static bool capture_frame(DeliverEvt& evt) {
    if (!dut->frame_out_valid) return false;
    evt.ftype = (uint8_t)dut->frame_out_type;
    evt.seq   = (uint8_t)dut->frame_out_seq;
    evt.len   = (uint8_t)dut->frame_out_len;
    for (int i = 0; i < MAX_MSG_LEN; i++)
        evt.payload[i] = payload_get_byte(dut->frame_out_payload, i);
    return true;
}

// Drive the byte stream and accumulate delivered frames + drop count.
static void feed_stream(const std::vector<uint8_t>& bytes,
                        std::vector<DeliverEvt>& events,
                        int& drop_count,
                        int idle_after = 64,
                        bool keep_ready = true) {
    drop_count = 0;
    dut->frame_out_ready = keep_ready ? 1 : 0;
    bool prev_drop = false;
    auto sample_drop = [&]() {
        bool now = (bool)dut->drop_pulse;
        if (now && !prev_drop) drop_count++;
        prev_drop = now;
    };
    for (uint8_t b : bytes) {
        push_byte(b);
        sample_drop();
        if (keep_ready && dut->frame_out_valid) {
            DeliverEvt e;
            capture_frame(e);
            events.push_back(e);
            tick();   // consume (frame_out_ready==1 -> back to WAIT_SOF)
            sample_drop();
        }
    }
    for (int i = 0; i < idle_after; i++) {
        sample_drop();
        if (keep_ready && dut->frame_out_valid) {
            DeliverEvt e;
            capture_frame(e);
            events.push_back(e);
        }
        tick();
    }
    sample_drop();
}

// ---- Tests ----

static void test_one_data_frame() {
    printf("== test_one_data_frame\n");
    reset();
    std::vector<uint8_t> p = {'h','i','!','!'};
    auto stream = encode(FRAME_DATA, 0x12, p);
    std::vector<DeliverEvt> events;
    int drops = 0;
    feed_stream(stream, events, drops);
    CHECK_EQ((int)events.size(), 1, "one delivery");
    if (events.size() == 1) {
        CHECK_EQ((int)events[0].ftype, FRAME_DATA, "ftype");
        CHECK_EQ((int)events[0].seq,   0x12,       "seq");
        CHECK_EQ((int)events[0].len,   (int)p.size(), "len");
        for (size_t i = 0; i < p.size(); i++) {
            char lbl[64];
            std::snprintf(lbl, sizeof(lbl), "payload[%zu]", i);
            CHECK_EQ((int)events[0].payload[i], (int)p[i], lbl);
        }
    }
    CHECK_EQ(drops, 0, "no drops");
}

static void test_zero_payload() {
    printf("== test_zero_payload\n");
    reset();
    auto stream = encode(FRAME_ACK, 7, {});
    std::vector<DeliverEvt> events;
    int drops = 0;
    feed_stream(stream, events, drops);
    CHECK_EQ((int)events.size(), 1, "one delivery");
    CHECK_EQ((int)events[0].ftype, FRAME_ACK, "ftype");
    CHECK_EQ((int)events[0].len,   0,         "len=0");
    CHECK_EQ(drops, 0, "no drops");
}

static void test_payload_with_sof() {
    printf("== test_payload_with_sof\n");
    reset();
    std::vector<uint8_t> p = {0x7E, 0x01, 0x7E, 0x7E, 0x42};
    auto stream = encode(FRAME_DATA, 1, p);
    std::vector<DeliverEvt> events;
    int drops = 0;
    feed_stream(stream, events, drops);
    CHECK_EQ((int)events.size(), 1, "one delivery (no false sync)");
    if (events.size() == 1) {
        for (size_t i = 0; i < p.size(); i++) {
            char lbl[40];
            std::snprintf(lbl, sizeof(lbl), "byte[%zu]", i);
            CHECK_EQ((int)events[0].payload[i], (int)p[i], lbl);
        }
    }
}

static void test_junk_before_sof() {
    printf("== test_junk_before_sof\n");
    reset();
    std::vector<uint8_t> stream = {0x00, 0xFF, 0xA5, 0x12};
    auto frame = encode(FRAME_HELLO, 3, {'A','l','i','c'});
    for (uint8_t b : frame) stream.push_back(b);
    std::vector<DeliverEvt> events;
    int drops = 0;
    feed_stream(stream, events, drops);
    CHECK_EQ((int)events.size(), 1, "delivered after junk");
    CHECK_EQ((int)events[0].ftype, FRAME_HELLO, "ftype");
    CHECK_EQ((int)events[0].seq,   3,           "seq");
}

static void test_bad_crc() {
    printf("== test_bad_crc\n");
    reset();
    auto stream = encode(FRAME_DATA, 5, {'a','b'});
    stream.back() ^= 0xFF;          // corrupt CRC LO
    std::vector<DeliverEvt> events;
    int drops = 0;
    feed_stream(stream, events, drops);
    CHECK_EQ((int)events.size(), 0, "no delivery on bad CRC");
    CHECK_EQ(drops, 1, "one drop pulse");

    // Now follow with a valid frame; should sync and deliver.
    auto stream2 = encode(FRAME_DATA, 6, {'o','k'});
    feed_stream(stream2, events, drops);
    CHECK_EQ((int)events.size(), 1, "recovers on next valid frame");
    CHECK_EQ((int)events[0].ftype, FRAME_DATA, "ftype");
    CHECK_EQ((int)events[0].seq,   6,          "seq");
}

static void test_malformed_len() {
    printf("== test_malformed_len\n");
    reset();
    // Hand-crafted: SOF, type=DATA, seq=0, len=200 (out of range).
    // Decoder should drop on the LEN byte, then look for next SOF.
    std::vector<uint8_t> stream = {SOF_BYTE, FRAME_DATA, 0, 200};
    std::vector<DeliverEvt> events;
    int drops = 0;
    feed_stream(stream, events, drops);
    CHECK_EQ((int)events.size(), 0, "no delivery");
    CHECK_EQ(drops, 1, "one drop pulse on malformed LEN");

    // Valid frame after.
    auto good = encode(FRAME_GOODBYE, 1, {});
    feed_stream(good, events, drops);
    CHECK_EQ((int)events.size(), 1, "recovers");
    CHECK_EQ((int)events[0].ftype, FRAME_GOODBYE, "ftype");
}

static void test_back_to_back() {
    printf("== test_back_to_back\n");
    reset();
    std::vector<uint8_t> stream;
    auto a = encode(FRAME_DATA, 0, {'A'});
    auto b = encode(FRAME_DATA, 1, {'B','B'});
    auto c = encode(FRAME_HELLO, 2, {'h','i'});
    for (uint8_t x : a) stream.push_back(x);
    for (uint8_t x : b) stream.push_back(x);
    for (uint8_t x : c) stream.push_back(x);
    std::vector<DeliverEvt> events;
    int drops = 0;
    feed_stream(stream, events, drops);
    CHECK_EQ((int)events.size(), 3, "three deliveries");
    if (events.size() == 3) {
        CHECK_EQ((int)events[0].seq, 0, "seq[0]");
        CHECK_EQ((int)events[1].seq, 1, "seq[1]");
        CHECK_EQ((int)events[2].seq, 2, "seq[2]");
        CHECK_EQ((int)events[0].len, 1, "len[0]");
        CHECK_EQ((int)events[1].len, 2, "len[1]");
        CHECK_EQ((int)events[2].len, 2, "len[2]");
    }
    CHECK_EQ(drops, 0, "no drops");
}

static void test_back_pressure_hold() {
    printf("== test_back_pressure_hold\n");
    reset();
    auto stream = encode(FRAME_DATA, 9, {'X','Y','Z'});
    // Feed without ready, watch for valid held high.
    dut->frame_out_ready = 0;
    for (uint8_t b : stream) push_byte(b);
    // Now the decoder should be in DELIVER, valid asserted.
    CHECK_EQ((int)dut->frame_out_valid, 1, "valid held while !ready");
    // Hold a few cycles -- still valid.
    for (int i = 0; i < 5; i++) tick();
    CHECK_EQ((int)dut->frame_out_valid, 1, "still held");
    CHECK_EQ((int)dut->frame_out_seq,   9, "fields stable");
    // Accept.
    dut->frame_out_ready = 1;
    tick();
    CHECK_EQ((int)dut->frame_out_valid, 0, "valid drops after consume");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vcomm_frame_decoder;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/comm_frame_decoder.vcd");

    test_one_data_frame();
    test_zero_payload();
    test_payload_with_sof();
    test_junk_before_sof();
    test_bad_crc();
    test_malformed_len();
    test_back_to_back();
    test_back_pressure_hold();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
