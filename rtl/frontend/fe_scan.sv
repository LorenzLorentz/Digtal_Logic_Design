// =====================================================================
// fe_scan.sv  --  Pixel-domain scan pipeline
// ---------------------------------------------------------------------
// For every pixel:
//   1. Decode (hdata, vdata) into (screen_row, screen_col, gx, gy).
//   2. Map screen_row -> text_ram physical row, applying the history
//      ring + scroll-offset window for history rows.
//   3. Drive text_ram read port; receive cell code 1 cycle later.
//   4. Drive glyph_rom (combinational) with (cell, gy) -> bitmap row.
//   5. Pick the gx bit; mix per-row foreground/background colors;
//      XOR the cursor cell at blink rate.
//   6. For non-CONNECTED conn_state, overlay a centered splash text
//      from a small built-in ROM on top of a solid splash background.
//
// Pipeline depth = 1 (text_ram is the registered stage). All sync /
// de / coordinate signals are delayed by one clk_pix to align with
// rd_code's output.
//
// Display layout on screen (37 rows of 16 pixels):
//   screen 0       title (text_ram row TITLE_ROW)
//   screen 1       separator (always blank)
//   screen 2..30   29 history rows (ring window, 64-deep ring)
//   screen 31      separator (always blank)
//   screen 32..36  5 input rows (text_ram rows INPUT_ROW_START..+4 +
//                  input_scroll_offset). Multi-row input + scroll
//                  added in P3.
//
// Splash text region (used when conn_state != CONNECTED):
//   - 32 chars wide, centered horizontally (256 pixels)
//   - 2 lines tall (32 pixels), centered vertically
//   - For BOOT / HANDSHAKE only line 0 has text; line 1 is blank
// =====================================================================

`ifndef FE_SCAN_SV
`define FE_SCAN_SV

module fe_scan
    import chat_pkg::*;
    import fe_pkg::*;
(
    input  logic                   clk_pix,
    input  logic                   rst_n,

    // ---- from video_timing ----
    input  logic [HWIDTH-1:0]      hdata,
    input  logic [HWIDTH-1:0]      vdata,
    input  logic                   hsync,
    input  logic                   vsync,
    input  logic                   data_enable,

    // ---- text_ram ----
    output logic [FE_ROW_W-1:0]    rd_row,
    output logic [FE_COL_W-1:0]    rd_col,
    input  byte_t                  rd_code,            // 1 cycle after addr

    // ---- glyph_rom (combinational) ----
    output byte_t                  glyph_code,
    output logic [3:0]             glyph_gy,
    input  logic [7:0]             glyph_row,

    // ---- attributes from decoder ----
    input  logic [1:0]             conn_state,
    /* verilator lint_off UNUSEDSIGNAL */
    // input_cursor is the legacy 1-D cursor index. Kept for backward
    // compatibility with the existing observer port; cursor highlight
    // now uses (input_cursor_row, input_cursor_col) instead.
    input  msg_len_t               input_cursor,
    /* verilator lint_on UNUSEDSIGNAL */
    input  logic [HIST_W-1:0]      hist_wr_row,         // ring head
    input  logic [SCROLL_W-1:0]    scroll_offset,       // history scroll
    input  logic [INPUT_LINE_W-1:0]   input_cursor_row,   // 2-D cursor (row)
    /* verilator lint_off UNUSEDSIGNAL */
    // Only the low FE_COL_W bits of input_cursor_col are needed (any
    // column past FE_N_COLS-1 is off-screen anyway).
    input  msg_len_t                  input_cursor_col,   // 2-D cursor (col)
    /* verilator lint_on UNUSEDSIGNAL */
    input  logic [INPUT_SCROLL_W-1:0] input_scroll_offset,// input window top

    // ---- RGB / sync out ----
    output logic [7:0]             video_red,
    output logic [7:0]             video_green,
    output logic [7:0]             video_blue,
    output logic                   video_hsync,
    output logic                   video_vsync,
    output logic                   video_de
);

    // -----------------------------------------------------------------
    // Splash text ROMs  (32 chars per line, ASCII)
    // -----------------------------------------------------------------
    /* verilator lint_off LITENDIAN */
    localparam byte_t SPLASH_BOOT_R0 [32] = '{
        " "," "," "," "," "," "," "," ",
        "C","h","a","t"," ","(","b","o",
        "o","t","i","n","g",".",".",".",
        ")"," "," "," "," "," "," "," "
    };
    localparam byte_t SPLASH_HS_R0 [32] = '{
        " "," "," "," "," "," ",
        "C","o","n","n","e","c","t","i","n","g",
        " ","t","o"," ","p","e","e","r",".",".",".",
        " "," "," "," "," "
    };
    localparam byte_t SPLASH_DISC_R0 [32] = '{
        " "," "," "," "," "," "," "," "," ",
        "D","i","s","c","o","n","n","e","c","t","e","d",".",
        " "," "," "," "," "," "," "," "," "," "
    };
    localparam byte_t SPLASH_DISC_R1 [32] = '{
        " "," "," ",
        "P","r","e","s","s"," ","S","P","A","C","E",
        " ","t","o"," ","r","e","c","o","n","n","e","c","t",".",
        " "," "," "," "
    };
    /* verilator lint_on LITENDIAN */

    // -----------------------------------------------------------------
    // Stage 0  --  combinational coordinate decode
    // -----------------------------------------------------------------
    /* verilator lint_off UNUSEDSIGNAL */
    // s0_screen_col upper bits unused (only FE_COL_W bits address text_ram).
    logic [HWIDTH-1:0] s0_screen_row;
    logic [HWIDTH-1:0] s0_screen_col;
    /* verilator lint_on UNUSEDSIGNAL */
    logic [3:0]        s0_gy;
    logic [2:0]        s0_gx;

    assign s0_screen_row = vdata >> 4;
    assign s0_screen_col = hdata >> 3;
    assign s0_gy         = vdata[3:0];
    assign s0_gx         = hdata[2:0];

    // Map screen row -> text_ram physical row.
    // History rows are mapped through the ring+scroll formula:
    //   slot = hist_wr_row + (N_HIST_STORED - N_HIST_VISIBLE)
    //                      - scroll_offset + (screen_row - HIST_SCREEN_START)
    // arithmetic is mod N_HIST_STORED (= 2^HIST_W when stored=64).
    localparam int HIST_SCREEN_START  = HIST_ROW_START;                                  // = 2
    localparam int HIST_SCREEN_END    = HIST_SCREEN_START + N_HIST_VISIBLE - 1;          // = 30
    localparam int SEP_SCREEN_ROW     = HIST_SCREEN_END + 1;                             // = 31
    localparam int INPUT_SCREEN_START = HIST_SCREEN_END + 2;                             // = 32
    localparam int INPUT_SCREEN_END   = INPUT_SCREEN_START + N_INPUT_VISIBLE - 1;        // = 36

    logic [FE_ROW_W-1:0] s0_text_ram_row;
    logic [HIST_W-1:0]   hist_slot_offset;
    logic [HIST_W-1:0]   hist_slot;
    /* verilator lint_off UNUSEDSIGNAL */
    // Only low FE_ROW_W bits used (window is at most N_INPUT_VISIBLE rows).
    logic [HWIDTH-1:0]   input_row_in_window;
    /* verilator lint_on UNUSEDSIGNAL */

    always_comb begin
        hist_slot_offset = HIST_W'(s0_screen_row - HWIDTH'(HIST_SCREEN_START));
        // All-modular HIST_W arithmetic so the wrap is automatic.
        hist_slot = hist_wr_row
                    + HIST_W'(N_HIST_STORED - N_HIST_VISIBLE)
                    - HIST_W'(scroll_offset)
                    + hist_slot_offset;

        input_row_in_window = s0_screen_row - HWIDTH'(INPUT_SCREEN_START);

        if (s0_screen_row == HWIDTH'(0))
            s0_text_ram_row = FE_ROW_W'(TITLE_ROW);
        else if (s0_screen_row == HWIDTH'(1))
            s0_text_ram_row = FE_ROW_W'(TITLE_ROW + 1);
        else if ((s0_screen_row >= HWIDTH'(HIST_SCREEN_START))
              && (s0_screen_row <= HWIDTH'(HIST_SCREEN_END)))
            s0_text_ram_row = FE_ROW_W'(HIST_ROW_START) + FE_ROW_W'(hist_slot);
        else if (s0_screen_row == HWIDTH'(SEP_SCREEN_ROW))
            s0_text_ram_row = FE_ROW_W'(HIST_ROW_END + 1);
        else if ((s0_screen_row >= HWIDTH'(INPUT_SCREEN_START))
              && (s0_screen_row <= HWIDTH'(INPUT_SCREEN_END)))
            // Input window: row r in window maps to text_ram row
            // INPUT_ROW_START + input_scroll_offset + r.
            s0_text_ram_row = FE_ROW_W'(INPUT_ROW_START)
                              + FE_ROW_W'(input_scroll_offset)
                              + FE_ROW_W'(input_row_in_window);
        else
            s0_text_ram_row = FE_ROW_W'(0);  // unused; de=0 here anyway
    end

    assign rd_row = s0_text_ram_row;
    assign rd_col = FE_COL_W'(s0_screen_col);

    // -----------------------------------------------------------------
    // Splash region detection (stage 0)
    // -----------------------------------------------------------------
    logic              s0_splash_in_h;
    logic              s0_splash_in_v;
    logic              s0_splash_in_region;
    /* verilator lint_off UNUSEDSIGNAL */
    // Only the low bits feed splash_subrow/col/gx/gy; upper bits unused.
    logic [HWIDTH-1:0] s0_splash_pix_x;
    logic [HWIDTH-1:0] s0_splash_pix_y;
    /* verilator lint_on UNUSEDSIGNAL */
    logic              s0_splash_subrow;
    logic [4:0]        s0_splash_subcol;
    logic [2:0]        s0_splash_gx;
    logic [3:0]        s0_splash_gy;
    byte_t             s0_splash_char;

    assign s0_splash_in_h = (hdata >= HWIDTH'(SPLASH_H_LEFT))
                         && (hdata <  HWIDTH'(SPLASH_H_LEFT + SPLASH_COLS * 8));
    assign s0_splash_in_v = (vdata >= HWIDTH'(SPLASH_V_TOP))
                         && (vdata <  HWIDTH'(SPLASH_V_TOP + 32));

    assign s0_splash_in_region = s0_splash_in_h && s0_splash_in_v;

    assign s0_splash_pix_x = hdata - HWIDTH'(SPLASH_H_LEFT);
    assign s0_splash_pix_y = vdata - HWIDTH'(SPLASH_V_TOP);
    assign s0_splash_subrow = s0_splash_pix_y[4];           // 0 or 1
    assign s0_splash_subcol = s0_splash_pix_x[7:3];         // 0..31
    assign s0_splash_gx     = s0_splash_pix_x[2:0];
    assign s0_splash_gy     = s0_splash_pix_y[3:0];

    always_comb begin
        // Default: blank (drives a space when out of region or for
        // an unhandled state row).
        s0_splash_char = 8'h20;
        unique case ({conn_state, s0_splash_subrow})
            {2'(CONN_BOOT),         1'b0}:
                s0_splash_char = SPLASH_BOOT_R0[s0_splash_subcol];
            {2'(CONN_HANDSHAKE),    1'b0}:
                s0_splash_char = SPLASH_HS_R0[s0_splash_subcol];
            {2'(CONN_DISCONNECTED), 1'b0}:
                s0_splash_char = SPLASH_DISC_R0[s0_splash_subcol];
            {2'(CONN_DISCONNECTED), 1'b1}:
                s0_splash_char = SPLASH_DISC_R1[s0_splash_subcol];
            default: s0_splash_char = 8'h20;
        endcase
    end

    // -----------------------------------------------------------------
    // Stage 1  --  align everything we registered with rd_code's
    //              one-cycle BRAM read latency.
    // -----------------------------------------------------------------
    logic [3:0]        s1_gy;
    logic [2:0]        s1_gx;
    logic [FE_ROW_W-1:0]  s1_text_ram_row;
    logic [FE_COL_W-1:0]  s1_text_ram_col;
    logic              s1_hsync, s1_vsync, s1_de;

    logic              s1_splash_in_region;
    byte_t             s1_splash_char;
    logic [3:0]        s1_splash_gy;
    logic [2:0]        s1_splash_gx;

    always_ff @(posedge clk_pix or negedge rst_n) begin
        if (!rst_n) begin
            s1_gy               <= '0;
            s1_gx               <= '0;
            s1_text_ram_row     <= '0;
            s1_text_ram_col     <= '0;
            s1_hsync            <= 1'b0;
            s1_vsync            <= 1'b0;
            s1_de               <= 1'b0;
            s1_splash_in_region <= 1'b0;
            s1_splash_char      <= 8'h20;
            s1_splash_gy        <= '0;
            s1_splash_gx        <= '0;
        end else begin
            s1_gy               <= s0_gy;
            s1_gx               <= s0_gx;
            s1_text_ram_row     <= s0_text_ram_row;
            s1_text_ram_col     <= FE_COL_W'(s0_screen_col);
            s1_hsync            <= hsync;
            s1_vsync            <= vsync;
            s1_de               <= data_enable;
            s1_splash_in_region <= s0_splash_in_region;
            s1_splash_char      <= s0_splash_char;
            s1_splash_gy        <= s0_splash_gy;
            s1_splash_gx        <= s0_splash_gx;
        end
    end

    // -----------------------------------------------------------------
    // Glyph lookup mux: CONNECTED uses text_ram cell; otherwise pull
    // the splash char.
    // -----------------------------------------------------------------
    logic in_connected;
    assign in_connected = (conn_state == 2'(CONN_CONNECTED));

    assign glyph_code = in_connected ? rd_code
                                     : (s1_splash_in_region ? s1_splash_char
                                                            : 8'h20);
    assign glyph_gy   = in_connected ? s1_gy : s1_splash_gy;

    logic pixel_on;
    always_comb begin
        if (in_connected)
            pixel_on = glyph_row[3'd7 - s1_gx];
        else if (s1_splash_in_region)
            pixel_on = glyph_row[3'd7 - s1_splash_gx];
        else
            pixel_on = 1'b0;
    end

    // -----------------------------------------------------------------
    // Cursor blink (toggle every BLINK_FRAMES vsync rising edges).
    // -----------------------------------------------------------------
    logic [$clog2(BLINK_FRAMES)-1:0] blink_cnt_q;
    logic                            blink_q;
    logic                            vsync_d;
    always_ff @(posedge clk_pix or negedge rst_n) begin
        if (!rst_n) begin
            blink_cnt_q <= '0;
            blink_q     <= 1'b0;
            vsync_d     <= 1'b0;
        end else begin
            vsync_d <= vsync;
            if (vsync && !vsync_d) begin
                if (blink_cnt_q == ($bits(blink_cnt_q))'(BLINK_FRAMES - 1)) begin
                    blink_cnt_q <= '0;
                    blink_q     <= ~blink_q;
                end else begin
                    blink_cnt_q <= blink_cnt_q + 1'b1;
                end
            end
        end
    end

    // Cursor cell match. The cursor lives at text_ram row
    // INPUT_ROW_START + input_cursor_row, col input_cursor_col (plus
    // the "> " prefix offset on row 0).
    logic [FE_ROW_W-1:0] cursor_text_row;
    logic [FE_COL_W-1:0] cursor_text_col;
    always_comb begin
        cursor_text_row = FE_ROW_W'(INPUT_ROW_START)
                          + FE_ROW_W'(input_cursor_row);
        if (input_cursor_row == '0)
            cursor_text_col = FE_COL_W'(INPUT_PREFIX_LEN)
                              + FE_COL_W'(input_cursor_col);
        else
            cursor_text_col = FE_COL_W'(input_cursor_col);
    end

    logic at_cursor_cell;
    assign at_cursor_cell =
        in_connected
        && (s1_text_ram_row == cursor_text_row)
        && (s1_text_ram_col == cursor_text_col);

    logic cursor_xor;
    assign cursor_xor = at_cursor_cell && blink_q;

    // -----------------------------------------------------------------
    // Per-row colour attribute (CONNECTED screen)
    // -----------------------------------------------------------------
    logic [7:0] fg_r, fg_g, fg_b;
    logic [7:0] bg_r, bg_g, bg_b;

    always_comb begin
        fg_r = COL_FG_R; fg_g = COL_FG_G; fg_b = COL_FG_B;
        bg_r = COL_BG_R; bg_g = COL_BG_G; bg_b = COL_BG_B;
        if (s1_text_ram_row == FE_ROW_W'(TITLE_ROW)) begin
            bg_r = COL_TITLE_BG_R;
            bg_g = COL_TITLE_BG_G;
            bg_b = COL_TITLE_BG_B;
        end else if ((s1_text_ram_row >= FE_ROW_W'(INPUT_ROW_START))
                  && (s1_text_ram_row <= FE_ROW_W'(INPUT_ROW_END))) begin
            bg_r = COL_INPUT_BG_R;
            bg_g = COL_INPUT_BG_G;
            bg_b = COL_INPUT_BG_B;
        end
    end

    // Splash background colour per state.
    logic [7:0] splash_bg_r, splash_bg_g, splash_bg_b;
    always_comb begin
        case (conn_state)
            2'(CONN_BOOT): begin
                splash_bg_r = COL_BOOT_BG_R;
                splash_bg_g = COL_BOOT_BG_G;
                splash_bg_b = COL_BOOT_BG_B;
            end
            2'(CONN_HANDSHAKE): begin
                splash_bg_r = COL_HS_BG_R;
                splash_bg_g = COL_HS_BG_G;
                splash_bg_b = COL_HS_BG_B;
            end
            2'(CONN_DISCONNECTED): begin
                splash_bg_r = COL_DISC_BG_R;
                splash_bg_g = COL_DISC_BG_G;
                splash_bg_b = COL_DISC_BG_B;
            end
            default: begin
                splash_bg_r = COL_BG_R;
                splash_bg_g = COL_BG_G;
                splash_bg_b = COL_BG_B;
            end
        endcase
    end

    // -----------------------------------------------------------------
    // Final pixel mux
    // -----------------------------------------------------------------
    logic fg;
    assign fg = pixel_on ^ cursor_xor;

    always_comb begin
        if (!s1_de) begin
            video_red   = 8'h00;
            video_green = 8'h00;
            video_blue  = 8'h00;
        end else if (in_connected) begin
            video_red   = fg ? fg_r : bg_r;
            video_green = fg ? fg_g : bg_g;
            video_blue  = fg ? fg_b : bg_b;
        end else if (s1_splash_in_region && pixel_on) begin
            video_red   = COL_SPLASH_FG_R;
            video_green = COL_SPLASH_FG_G;
            video_blue  = COL_SPLASH_FG_B;
        end else begin
            video_red   = splash_bg_r;
            video_green = splash_bg_g;
            video_blue  = splash_bg_b;
        end
    end

    assign video_hsync = s1_hsync;
    assign video_vsync = s1_vsync;
    assign video_de    = s1_de;

endmodule

`endif  // FE_SCAN_SV
