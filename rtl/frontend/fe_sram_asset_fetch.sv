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

    logic [18:0] bg_pixel_idx;
    logic [8:0]  avatar_pixel_idx;
    logic [19:0] base_word_addr;
    logic [18:0] pixel_idx;

    always_comb begin
        bg_pixel_idx     = 19'(vdata) * 19'(ASSET_BG_W_PX) + 19'(hdata);
        avatar_pixel_idx = {5'b0, vdata[3:0]} * 9'(ASSET_AVATAR_W_PX)
                           + 9'(hdata[3:0]);

        if (avatar_remote_req) begin
            base_word_addr = 20'(ASSET_REMOTE_AVATAR_BASE_BYTES >> 2);
            pixel_idx      = 19'(avatar_pixel_idx);
        end else if (avatar_local_req) begin
            base_word_addr = 20'(ASSET_LOCAL_AVATAR_BASE_BYTES >> 2);
            pixel_idx      = 19'(avatar_pixel_idx);
        end else begin
            base_word_addr = 20'(ASSET_BG_BASE_BYTES >> 2);
            pixel_idx      = bg_pixel_idx;
        end
    end

    assign sram_addr   = base_word_addr + 20'(pixel_idx[18:1]);
    assign use_hi_half = pixel_idx[0];

endmodule

`endif  // FE_SRAM_ASSET_FETCH_SV
