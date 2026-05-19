// =====================================================================
// fe_sram_asset_fetch.sv  --  SRAM asset address + RGB565 decode
// ---------------------------------------------------------------------
// Pixel-domain helper for read-only visual assets stored in the lab
// board's 4 MiB BaseRAM. The SRAM address is driven combinationally from
// the current pixel coordinate so the async SRAM has a full pixel clock
// period to settle; the returned 32-bit word is consumed one pipeline
// stage later by fe_scan.
//
// Asset format:
//   - raw RGB565, little-endian bytes
//   - two pixels per 32-bit SRAM word:
//       data[15:0]  = lower-address pixel
//       data[31:16] = next pixel
// =====================================================================

`ifndef FE_SRAM_ASSET_FETCH_SV
`define FE_SRAM_ASSET_FETCH_SV

module fe_sram_asset_fetch
    import fe_pkg::*;
(
    input  logic              avatar_remote_req,
    input  logic              avatar_local_req,
    input  logic [HWIDTH-1:0] hdata,
    input  logic [HWIDTH-1:0] vdata,

    output logic [19:0]       sram_addr,
    output logic              use_hi_half
);

    logic [19:0] base_word_addr;
    logic [19:0] bg_word_offset;
    logic [8:0]  avatar_word_offset;
    logic [19:0] word_offset;

    always_comb begin
        // HSIZE=800 -> 400 32-bit words per row.
        bg_word_offset     = (20'(vdata) << 8)
                           + (20'(vdata) << 7)
                           + (20'(vdata) << 4)
                           + 20'(hdata[HWIDTH-1:1]);
        // Avatar width=16 -> 8 32-bit words per row.
        avatar_word_offset = {2'b00, vdata[3:0], 3'b000}
                           + 9'(hdata[3:1]);

        if (avatar_remote_req) begin
            base_word_addr = 20'(ASSET_REMOTE_AVATAR_BASE_BYTES >> 2);
            word_offset    = 20'(avatar_word_offset);
        end else if (avatar_local_req) begin
            base_word_addr = 20'(ASSET_LOCAL_AVATAR_BASE_BYTES >> 2);
            word_offset    = 20'(avatar_word_offset);
        end else begin
            base_word_addr = 20'(ASSET_BG_BASE_BYTES >> 2);
            word_offset    = bg_word_offset;
        end
    end

    assign sram_addr   = base_word_addr + word_offset;
    assign use_hi_half = hdata[0];

endmodule

`endif  // FE_SRAM_ASSET_FETCH_SV
