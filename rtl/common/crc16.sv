// =====================================================================
// crc16.sv  --  Streaming CRC16-CCITT (a.k.a. CCITT-FALSE)
// ---------------------------------------------------------------------
// Polynomial: 0x1021, init: 0xFFFF, RefIn=false, RefOut=false, XorOut=0.
// Test vector: bytes "123456789" -> 0x29B1.
//
// Streaming interface:
//   - `init` pulse: load CRC state with CRC16_INIT.
//   - `en` pulse with `byte_in` valid: feed one byte into the CRC.
//   - `crc_out` is the CURRENT state (combinational tap of crc_q),
//     so the result of feeding N bytes is visible on the cycle AFTER
//     the last `en` pulse.
//
// If both `init` and `en` fire in the same cycle, `init` wins (we
// reload, then the next cycle's `en` is the first byte). The encoder
// pipeline never does this in practice.
//
// The byte step is unrolled into a combinational function. That keeps
// throughput at 1 byte / clock; the encoder feeds bytes at uart-tx
// rate (slow), so timing is trivial.
// =====================================================================

`ifndef CRC16_SV
`define CRC16_SV

module crc16
    import chat_pkg::*;
(
    input  logic     clk,
    input  logic     rst_n,

    input  logic     init,        // pulse: reload state to CRC16_INIT
    input  logic     en,          // pulse: process byte_in this cycle
    input  byte_t    byte_in,
    output crc16_t   crc_out
);

    crc16_t crc_q;

    function automatic crc16_t crc16_step(input crc16_t crc_in,
                                          input byte_t b);
        crc16_t c;
        c = crc_in ^ {b, 8'h00};
        for (int i = 0; i < 8; i++) begin
            c = c[15] ? ((c << 1) ^ CRC16_POLY) : (c << 1);
        end
        return c;
    endfunction

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)        crc_q <= CRC16_INIT;
        else if (init)     crc_q <= CRC16_INIT;
        else if (en)       crc_q <= crc16_step(crc_q, byte_in);
    end

    assign crc_out = crc_q;

endmodule

`endif  // CRC16_SV
