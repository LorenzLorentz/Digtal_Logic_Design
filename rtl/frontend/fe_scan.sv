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
#(
    parameter bit ENABLE_SRAM_ASSETS = 1'b0
)
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
    input  logic [1:0]             rd_attr,            // aligned with rd_code

    // ---- glyph_rom (combinational) ----
    output byte_t                  glyph_code,
    output logic [3:0]             glyph_gy,
    input  logic [7:0]             glyph_row,

    // ---- SRAM visual assets ----
    output logic [19:0]            asset_sram_addr,
    input  logic [31:0]            asset_sram_data,

    // ---- attributes from decoder ----
    input  logic [1:0]             conn_state,
    input  logic [HIST_W-1:0]      hist_wr_row,         // ring head
    input  logic [SCROLL_W-1:0]    scroll_offset,       // history scroll
    input  logic [N_HIST_STORED*2-1:0] hist_avatar_attr,
    input  logic [INPUT_LINE_W-1:0]   input_cursor_row,   // 2-D cursor (row)
    // Cursor col is narrowed to FE_COL_W -- any column past
    // FE_N_COLS-1 is off-screen and would never match a scan cell.
    input  logic [FE_COL_W-1:0]       input_cursor_col,   // 2-D cursor (col)
    input  logic [INPUT_SCROLL_W-1:0] input_scroll_offset,// input window top

    // ---- Mouse pointer (pixel-clock domain) ----
    // Hotspot is the top-left corner of the sprite.
    input  logic [9:0]                mouse_x,
    input  logic [9:0]                mouse_y,

    // ---- Popup overlay (pixel-clock domain) ----
    input  logic                      popup_active,
    input  logic [1:0]                popup_type,
    input  logic [9:0]                popup_x,
    input  logic [9:0]                popup_y,

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

    function automatic byte_t popup_msg_menu_char(
        input logic       item_sel,
        input logic [3:0] char_idx
    );
        begin
            popup_msg_menu_char = 8'h20;
            if (!item_sel) begin
                unique case (char_idx)
                    4'd0: popup_msg_menu_char = "Q";
                    4'd1: popup_msg_menu_char = "u";
                    4'd2: popup_msg_menu_char = "o";
                    4'd3: popup_msg_menu_char = "t";
                    4'd4: popup_msg_menu_char = "e";
                    default: popup_msg_menu_char = 8'h20;
                endcase
            end else begin
                unique case (char_idx)
                    4'd0: popup_msg_menu_char = "R";
                    4'd1: popup_msg_menu_char = "e";
                    4'd2: popup_msg_menu_char = "c";
                    4'd3: popup_msg_menu_char = "a";
                    4'd4: popup_msg_menu_char = "l";
                    4'd5: popup_msg_menu_char = "l";
                    default: popup_msg_menu_char = 8'h20;
                endcase
            end
        end
    endfunction

    // Map screen row -> text_ram physical row.
    // History rows are mapped through the ring+scroll formula:
    //   slot = hist_wr_row + (N_HIST_STORED - N_HIST_VISIBLE)
    //                      - scroll_offset + (screen_row - HIST_SCREEN_START)
    // arithmetic is mod N_HIST_STORED (= 2^HIST_W when stored=64).
    localparam int HIST_SCREEN_START  = HIST_ROW_START;                                  // = 2
    localparam int HIST_SCREEN_END    = HIST_SCREEN_START + N_HIST_VISIBLE - 1;          // = 30
    localparam int SEP_SCREEN_ROW     = HIST_SCREEN_END + 1;                             // = 31
    /* verilator lint_off VARHIDDEN */
    localparam int INPUT_SCREEN_START = HIST_SCREEN_END + 2;                             // = 32
    localparam int INPUT_SCREEN_END   = INPUT_SCREEN_START + N_INPUT_VISIBLE - 1;        // = 36
    /* verilator lint_on VARHIDDEN */

    localparam int INPUT_WIN_W = (N_INPUT_VISIBLE <= 1)
                                   ? 1 : $clog2(N_INPUT_VISIBLE);

    logic [FE_ROW_W-1:0]      s0_text_ram_row;
    logic [HIST_W-1:0]        hist_slot_offset;
    logic [HIST_W-1:0]        hist_slot;
    logic [INPUT_WIN_W-1:0]   input_row_in_window;
    logic                     s0_in_hist_window;
    logic                     s0_avatar_remote_probe;
    logic                     s0_avatar_local_probe;
    logic [1:0]               s0_avatar_attr;

    always_comb begin
        hist_slot_offset = HIST_W'(s0_screen_row - HWIDTH'(HIST_SCREEN_START));
        // All-modular HIST_W arithmetic so the wrap is automatic.
        hist_slot = hist_wr_row
                    + HIST_W'(N_HIST_STORED - N_HIST_VISIBLE)
                    - HIST_W'(scroll_offset)
                    + hist_slot_offset;

        input_row_in_window = INPUT_WIN_W'(s0_screen_row
                                           - HWIDTH'(INPUT_SCREEN_START));

        s0_in_hist_window = (s0_screen_row >= HWIDTH'(HIST_SCREEN_START))
                         && (s0_screen_row <= HWIDTH'(HIST_SCREEN_END));
        s0_avatar_attr = s0_in_hist_window
                         ? hist_avatar_attr[{hist_slot, 1'b0} +: 2]
                         : BUBBLE_ATTR_NONE;

        if (s0_screen_row == HWIDTH'(0))
            s0_text_ram_row = FE_ROW_W'(TITLE_ROW);
        else if (s0_screen_row == HWIDTH'(1))
            s0_text_ram_row = FE_ROW_W'(TITLE_ROW + 1);
        else if (s0_in_hist_window)
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
            // Bottom 8 px strip (screen_row 37, vdata 592..599): de is
            // actually 1 here. Map to TITLE_ROW so the bg mux paints it
            // titlebar blue; the glyph is forced to a space below.
            s0_text_ram_row = FE_ROW_W'(TITLE_ROW);
    end

    assign s0_avatar_remote_probe = ENABLE_SRAM_ASSETS
                                    && (s0_avatar_attr == BUBBLE_ATTR_REMOTE)
                                    && (hdata < HWIDTH'(ASSET_AVATAR_W_PX));
    assign s0_avatar_local_probe  = ENABLE_SRAM_ASSETS
                                    && (s0_avatar_attr == BUBBLE_ATTR_LOCAL)
                                    && (hdata >= HWIDTH'(HSIZE - ASSET_AVATAR_W_PX))
                                    && (hdata <  HWIDTH'(HSIZE));

    assign rd_row = s0_text_ram_row;
    assign rd_col = FE_COL_W'(s0_screen_col);

    // -----------------------------------------------------------------
    // Popup overlay decode (stage 0)
    // -----------------------------------------------------------------
    logic [HWIDTH-1:0] popup_w_s0;
    logic [HWIDTH-1:0] popup_h_s0;
    logic [HWIDTH-1:0] popup_dx_s0;
    logic [HWIDTH-1:0] popup_dy_s0;
    logic [HWIDTH-1:0] popup_mouse_dx;
    logic [HWIDTH-1:0] popup_mouse_dy;
    logic              popup_is_msg_menu_s0;
    logic              popup_is_sticker_s0;
    logic              popup_in_region_s0;
    logic              popup_border_s0;
    logic              popup_grid_line_s0;
    logic              popup_item0_s0;
    logic              popup_item1_s0;
    logic              popup_hover0;
    logic              popup_hover1;
    logic              popup_item_hover_s0;
    logic              popup_text0_s0;
    logic              popup_text1_s0;
    logic              popup_label_active_s0;
    byte_t             popup_label_char_s0;
    logic [2:0]        popup_label_gx_s0;
    logic [3:0]        popup_label_gy_s0;
    logic [3:0]        popup_label_col_s0;
    logic [HWIDTH-1:0] popup_label_dx_s0;

    always_comb begin
        popup_w_s0 = '0;
        popup_h_s0 = '0;
        unique case (popup_type_e'(popup_type))
            POPUP_MSG_MENU: begin
                popup_w_s0 = HWIDTH'(POPUP_MSG_MENU_W_PX);
                popup_h_s0 = HWIDTH'(POPUP_MSG_MENU_H_PX);
            end
            POPUP_STICKER_PICKER: begin
                popup_w_s0 = HWIDTH'(POPUP_STICKER_W_PX);
                popup_h_s0 = HWIDTH'(POPUP_STICKER_H_PX);
            end
            default: begin
                popup_w_s0 = '0;
                popup_h_s0 = '0;
            end
        endcase
    end

    assign popup_dx_s0 = hdata - HWIDTH'(popup_x);
    assign popup_dy_s0 = vdata - HWIDTH'(popup_y);
    assign popup_mouse_dx = HWIDTH'(mouse_x) - HWIDTH'(popup_x);
    assign popup_mouse_dy = HWIDTH'(mouse_y) - HWIDTH'(popup_y);
    assign popup_is_msg_menu_s0 =
        popup_active && (popup_type == 2'(POPUP_MSG_MENU));
    assign popup_is_sticker_s0 =
        popup_active && (popup_type == 2'(POPUP_STICKER_PICKER));
    assign popup_in_region_s0 =
        popup_active
        && (popup_type != 2'(POPUP_NONE))
        && (popup_dx_s0 < popup_w_s0)
        && (popup_dy_s0 < popup_h_s0);
    assign popup_border_s0 =
        popup_in_region_s0
        && ((popup_dx_s0 < HWIDTH'(POPUP_BORDER_PX))
         || (popup_dy_s0 < HWIDTH'(POPUP_BORDER_PX))
         || (popup_dx_s0 >= popup_w_s0 - HWIDTH'(POPUP_BORDER_PX))
         || (popup_dy_s0 >= popup_h_s0 - HWIDTH'(POPUP_BORDER_PX)));

    assign popup_item0_s0 =
        popup_is_msg_menu_s0
        && (popup_dx_s0 >= HWIDTH'(POPUP_BORDER_PX))
        && (popup_dx_s0 <  HWIDTH'(POPUP_MSG_MENU_W_PX - POPUP_BORDER_PX))
        && (popup_dy_s0 >= HWIDTH'(POPUP_BORDER_PX))
        && (popup_dy_s0 <  HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX));
    assign popup_item1_s0 =
        popup_is_msg_menu_s0
        && (popup_dx_s0 >= HWIDTH'(POPUP_BORDER_PX))
        && (popup_dx_s0 <  HWIDTH'(POPUP_MSG_MENU_W_PX - POPUP_BORDER_PX))
        && (popup_dy_s0 >= HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX))
        && (popup_dy_s0 <  HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX * 2));

    assign popup_hover0 =
        popup_is_msg_menu_s0
        && (popup_mouse_dx >= HWIDTH'(POPUP_BORDER_PX))
        && (popup_mouse_dx <  HWIDTH'(POPUP_MSG_MENU_W_PX - POPUP_BORDER_PX))
        && (popup_mouse_dy >= HWIDTH'(POPUP_BORDER_PX))
        && (popup_mouse_dy <  HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX));
    assign popup_hover1 =
        popup_is_msg_menu_s0
        && (popup_mouse_dx >= HWIDTH'(POPUP_BORDER_PX))
        && (popup_mouse_dx <  HWIDTH'(POPUP_MSG_MENU_W_PX - POPUP_BORDER_PX))
        && (popup_mouse_dy >= HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX))
        && (popup_mouse_dy <  HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX * 2));
    assign popup_item_hover_s0 =
        (popup_item0_s0 && popup_hover0) || (popup_item1_s0 && popup_hover1);

    assign popup_grid_line_s0 =
        popup_is_sticker_s0
        && popup_in_region_s0
        && !popup_border_s0
        && ((popup_dx_s0[5:0] < 6'(POPUP_BORDER_PX))
         || (popup_dy_s0[5:0] < 6'(POPUP_BORDER_PX)));

    assign popup_text0_s0 =
        popup_is_msg_menu_s0
        && (popup_dx_s0 >= HWIDTH'(POPUP_MSG_TEXT_X_PX))
        && (popup_dx_s0 <  HWIDTH'(POPUP_MSG_TEXT_X_PX + 6 * 8))
        && (popup_dy_s0 >= HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_TEXT_Y_PX))
        && (popup_dy_s0 <  HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_TEXT_Y_PX + 16));
    assign popup_text1_s0 =
        popup_is_msg_menu_s0
        && (popup_dx_s0 >= HWIDTH'(POPUP_MSG_TEXT_X_PX))
        && (popup_dx_s0 <  HWIDTH'(POPUP_MSG_TEXT_X_PX + 6 * 8))
        && (popup_dy_s0 >= HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX
                                    + POPUP_MSG_TEXT_Y_PX))
        && (popup_dy_s0 <  HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX
                                    + POPUP_MSG_TEXT_Y_PX + 16));
    assign popup_label_active_s0 = popup_text0_s0 || popup_text1_s0;
    assign popup_label_dx_s0 =
        popup_dx_s0 - HWIDTH'(POPUP_MSG_TEXT_X_PX);
    assign popup_label_col_s0 =
        4'(popup_label_dx_s0 >> 3);
    assign popup_label_char_s0 =
        popup_msg_menu_char(popup_text1_s0, popup_label_col_s0);
    assign popup_label_gx_s0 = popup_label_dx_s0[2:0];
    assign popup_label_gy_s0 = popup_text1_s0
        ? 4'(popup_dy_s0 - HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_ITEM_H_PX
                                    + POPUP_MSG_TEXT_Y_PX))
        : 4'(popup_dy_s0 - HWIDTH'(POPUP_BORDER_PX + POPUP_MSG_TEXT_Y_PX));

    // True for the leftover 8 px past the last input row -- used to blank
    // the glyph so this strip renders as a solid titlebar-blue band.
    logic s0_in_bottom_strip;
    assign s0_in_bottom_strip = (s0_screen_row > HWIDTH'(INPUT_SCREEN_END));

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
    // Mouse pointer overlay  --  small NW arrow centred on (mouse_x,
    // mouse_y). The pointer is rendered by *inverting* the underlying
    // pixel so it stays visible on any background (white text bubbles,
    // SRAM wallpaper, the blue title bar, etc.).
    //
    // Sprite is 8 wide x 12 tall, hotspot at the top-left tip.
    //   row 0:  #.......
    //   row 1:  ##......
    //   row 2:  ###.....
    //   row 3:  ####....
    //   row 4:  #####...
    //   row 5:  ######..
    //   row 6:  #######.
    //   row 7:  ########
    //   row 8:  ###.....
    //   row 9:  .##.....
    //   row 10: ..##....
    //   row 11: ...##...
    //
    // Padded to 16 rows so out-of-range dy doesn't index past the array.
    // -----------------------------------------------------------------
    localparam logic [7:0] MOUSE_CURSOR_ROM [16] = '{
        8'h80, 8'hC0, 8'hE0, 8'hF0, 8'hF8, 8'hFC, 8'hFE, 8'hFF,
        8'hE0, 8'h60, 8'h30, 8'h18, 8'h00, 8'h00, 8'h00, 8'h00
    };

    logic [HWIDTH-1:0] mouse_dx_s0;
    logic [HWIDTH-1:0] mouse_dy_s0;
    logic              mouse_in_sprite_s0;
    logic              mouse_pointer_on_s0;

    // Unsigned subtraction: if hdata < mouse_x (pixel is left of the
    // sprite) the result underflows to a large value and the < 8 / < 12
    // checks reject it, so the sprite naturally clips at screen edges.
    assign mouse_dx_s0 = hdata - HWIDTH'(mouse_x);
    assign mouse_dy_s0 = vdata - HWIDTH'(mouse_y);
    assign mouse_in_sprite_s0 = (mouse_dx_s0 < HWIDTH'(8))
                              && (mouse_dy_s0 < HWIDTH'(12));
    assign mouse_pointer_on_s0 =
        mouse_in_sprite_s0
        && MOUSE_CURSOR_ROM[mouse_dy_s0[3:0]][3'd7 - mouse_dx_s0[2:0]];

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
    logic              s1_in_bottom_strip;
    logic              s1_in_hist_window;
    logic              s1_avatar_remote_probe;
    logic              s1_avatar_local_probe;
    logic              s1_asset_use_hi_half;
    logic [31:0]       s1_asset_sram_data;
    logic [1:0]        s1_rd_attr;
    logic              s1_mouse_pointer_on;
    logic              s1_popup_in_region;
    logic              s1_popup_border;
    logic              s1_popup_grid_line;
    logic              s1_popup_item_hover;
    logic              s1_popup_label_active;
    byte_t             s1_popup_label_char;
    logic [2:0]        s1_popup_label_gx;
    logic [3:0]        s1_popup_label_gy;

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
            s1_in_bottom_strip  <= 1'b0;
            s1_in_hist_window   <= 1'b0;
            s1_avatar_remote_probe <= 1'b0;
            s1_avatar_local_probe  <= 1'b0;
            s1_asset_use_hi_half   <= 1'b0;
            s1_asset_sram_data     <= 32'h0000_0000;
            s1_rd_attr             <= BUBBLE_ATTR_NONE;
            s1_mouse_pointer_on    <= 1'b0;
            s1_popup_in_region     <= 1'b0;
            s1_popup_border        <= 1'b0;
            s1_popup_grid_line     <= 1'b0;
            s1_popup_item_hover    <= 1'b0;
            s1_popup_label_active  <= 1'b0;
            s1_popup_label_char    <= 8'h20;
            s1_popup_label_gx      <= '0;
            s1_popup_label_gy      <= '0;
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
            s1_in_bottom_strip  <= s0_in_bottom_strip;
            s1_in_hist_window   <= s0_in_hist_window;
            s1_avatar_remote_probe <= s0_avatar_remote_probe;
            s1_avatar_local_probe  <= s0_avatar_local_probe;
            s1_asset_use_hi_half   <= asset_use_hi_half;
            s1_asset_sram_data     <= asset_sram_data;
            s1_rd_attr             <= rd_attr;
            s1_mouse_pointer_on    <= mouse_pointer_on_s0;
            s1_popup_in_region     <= popup_in_region_s0;
            s1_popup_border        <= popup_border_s0;
            s1_popup_grid_line     <= popup_grid_line_s0;
            s1_popup_item_hover    <= popup_item_hover_s0;
            s1_popup_label_active  <= popup_label_active_s0;
            s1_popup_label_char    <= popup_label_char_s0;
            s1_popup_label_gx      <= popup_label_gx_s0;
            s1_popup_label_gy      <= popup_label_gy_s0;
        end
    end

    // -----------------------------------------------------------------
    // SRAM-backed background and avatars.
    // -----------------------------------------------------------------
    logic       asset_use_hi_half;

    fe_sram_asset_fetch u_asset_fetch (
        .avatar_remote_req(s0_avatar_remote_probe),
        .avatar_local_req (s0_avatar_local_probe),
        .hdata            (hdata),
        .vdata            (vdata),
        .sram_addr        (asset_sram_addr),
        .use_hi_half      (asset_use_hi_half)
    );

    // -----------------------------------------------------------------
    // Glyph lookup mux: CONNECTED uses text_ram cell; otherwise pull
    // the splash char.
    // -----------------------------------------------------------------
    logic in_connected;
    assign in_connected = (conn_state == 2'(CONN_CONNECTED));

    byte_t      base_glyph_code;
    logic [3:0] base_glyph_gy;
    assign base_glyph_code = in_connected
                              ? (s1_in_bottom_strip ? 8'h20 : rd_code)
                              : (s1_splash_in_region ? s1_splash_char : 8'h20);
    assign base_glyph_gy   = in_connected ? s1_gy : s1_splash_gy;

    assign glyph_code = s1_popup_label_active
                        ? s1_popup_label_char : base_glyph_code;
    assign glyph_gy   = s1_popup_label_active
                        ? s1_popup_label_gy : base_glyph_gy;

    logic pixel_on;
    logic popup_text_pixel_on;
    assign popup_text_pixel_on =
        s1_popup_label_active
        && glyph_row[3'd7 - s1_popup_label_gx];

    always_comb begin
        if (s1_popup_label_active)
            pixel_on = popup_text_pixel_on;
        else if (in_connected)
            pixel_on = glyph_row[3'd7 - s1_gx];
        else if (s1_splash_in_region)
            pixel_on = glyph_row[3'd7 - s1_splash_gx];
        else
            pixel_on = 1'b0;
    end

    // -----------------------------------------------------------------
    // Big-emoji colour path. rd_code in [BIG_EMOJI_BASE, BIG_EMOJI_END_EXCL)
    // means the cell belongs to a big-emoji bubble; the pixel ROM yields
    // a 4 bpp palette index per pixel, and the palette ROM (indexed by
    // emoji_id = tile_off / N_TILES) maps that to RGB. Index 0 is the
    // transparent marker and falls back to the bubble background colour
    // in the final pixel mux. Two cascaded combinational ROMs in stage 1
    // -- fine at 40 MHz pixel clock.
    // -----------------------------------------------------------------
    logic        is_big_emoji;
    logic [6:0]  big_tile_off;
    logic [31:0] big_pixel_row;
    logic [3:0]  big_pix_idx;
    logic [2:0]  big_emoji_id;
    logic [7:0]  big_pal_r, big_pal_g, big_pal_b;

    assign is_big_emoji = in_connected
                          && !s1_in_bottom_strip
                          && (rd_code >= byte_t'(BIG_EMOJI_BASE))
                          && (rd_code <  byte_t'(BIG_EMOJI_END_EXCL));
    assign big_tile_off = rd_code[6:0];
    // Constant-divisor synthesis: Vivado picks the right shift/add or LUT.
    assign big_emoji_id = 3'(big_tile_off / 7'(BIG_EMOJI_N_TILES));

    fe_big_emoji_pixel_rom u_big_pix (
        .tile_off (big_tile_off),
        .gy       (s1_gy),
        .row      (big_pixel_row)
    );

    // Nibble select: gx=0 is the MSB nibble (matches how gen_big_emoji.py
    // packs each row, mirroring the mono font ROM's MSB-first row byte).
    always_comb begin
        unique case (s1_gx)
            3'd0: big_pix_idx = big_pixel_row[31:28];
            3'd1: big_pix_idx = big_pixel_row[27:24];
            3'd2: big_pix_idx = big_pixel_row[23:20];
            3'd3: big_pix_idx = big_pixel_row[19:16];
            3'd4: big_pix_idx = big_pixel_row[15:12];
            3'd5: big_pix_idx = big_pixel_row[11: 8];
            3'd6: big_pix_idx = big_pixel_row[ 7: 4];
            3'd7: big_pix_idx = big_pixel_row[ 3: 0];
        endcase
    end

    fe_big_emoji_palette_rom u_big_pal (
        .emoji_id (big_emoji_id),
        .idx      (big_pix_idx),
        .r        (big_pal_r),
        .g        (big_pal_g),
        .b        (big_pal_b)
    );

    // -----------------------------------------------------------------
    // Bubble fill mask. The text cell sideband tells us whether a cell
    // belongs to a normal message bubble; edge sprite cells still need
    // per-pixel clipping so wallpaper remains visible outside the
    // rounded outline.
    // -----------------------------------------------------------------
    function automatic logic [2:0] glyph_leftmost_x(input logic [7:0] row);
        begin
            glyph_leftmost_x = 3'd7;
            if      (row[7]) glyph_leftmost_x = 3'd0;
            else if (row[6]) glyph_leftmost_x = 3'd1;
            else if (row[5]) glyph_leftmost_x = 3'd2;
            else if (row[4]) glyph_leftmost_x = 3'd3;
            else if (row[3]) glyph_leftmost_x = 3'd4;
            else if (row[2]) glyph_leftmost_x = 3'd5;
            else if (row[1]) glyph_leftmost_x = 3'd6;
            else if (row[0]) glyph_leftmost_x = 3'd7;
        end
    endfunction

    function automatic logic [2:0] glyph_rightmost_x(input logic [7:0] row);
        begin
            glyph_rightmost_x = 3'd0;
            if      (row[0]) glyph_rightmost_x = 3'd7;
            else if (row[1]) glyph_rightmost_x = 3'd6;
            else if (row[2]) glyph_rightmost_x = 3'd5;
            else if (row[3]) glyph_rightmost_x = 3'd4;
            else if (row[4]) glyph_rightmost_x = 3'd3;
            else if (row[5]) glyph_rightmost_x = 3'd2;
            else if (row[6]) glyph_rightmost_x = 3'd1;
            else if (row[7]) glyph_rightmost_x = 3'd0;
        end
    endfunction

    logic bubble_attr_active;
    logic bubble_left_edge;
    logic bubble_right_edge;
    logic bubble_fill_active;

    assign bubble_attr_active = in_connected
                                && (s1_rd_attr != BUBBLE_ATTR_NONE);
    assign bubble_left_edge = (rd_code == byte_t'(SPRITE_BL))
                           || (rd_code == byte_t'(SPRITE_FBL))
                           || (rd_code == byte_t'(SPRITE_BL_TOP))
                           || (rd_code == byte_t'(SPRITE_BL_MID))
                           || (rd_code == byte_t'(SPRITE_BL_BOT));
    assign bubble_right_edge = (rd_code == byte_t'(SPRITE_BR))
                            || (rd_code == byte_t'(SPRITE_FBR))
                            || (rd_code == byte_t'(SPRITE_BR_TOP))
                            || (rd_code == byte_t'(SPRITE_BR_MID))
                            || (rd_code == byte_t'(SPRITE_BR_BOT));

    always_comb begin
        bubble_fill_active = 1'b0;
        if (bubble_attr_active) begin
            if (bubble_left_edge) begin
                bubble_fill_active = (glyph_row != 8'h00)
                                     && (s1_gx >= glyph_leftmost_x(glyph_row));
            end else if (bubble_right_edge) begin
                bubble_fill_active = (glyph_row != 8'h00)
                                     && (s1_gx <= glyph_rightmost_x(glyph_row));
            end else begin
                bubble_fill_active = 1'b1;
            end
        end
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
                              + input_cursor_col;
        else
            cursor_text_col = input_cursor_col;
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
    logic       use_sram_background;
    logic [15:0] asset_rgb565_aligned;
    logic [7:0]  asset_pixel_r, asset_pixel_g, asset_pixel_b;

    assign asset_rgb565_aligned = s1_asset_use_hi_half
                                    ? s1_asset_sram_data[31:16]
                                    : s1_asset_sram_data[15:0];
    assign asset_pixel_r = {asset_rgb565_aligned[15:11], asset_rgb565_aligned[15:13]};
    assign asset_pixel_g = {asset_rgb565_aligned[10:5],  asset_rgb565_aligned[10:9]};
    assign asset_pixel_b = {asset_rgb565_aligned[4:0],   asset_rgb565_aligned[4:2]};

    always_comb begin
        fg_r = COL_FG_R; fg_g = COL_FG_G; fg_b = COL_FG_B;
        bg_r = COL_BG_R; bg_g = COL_BG_G; bg_b = COL_BG_B;
        use_sram_background = ENABLE_SRAM_ASSETS
                              && in_connected
                              && s1_in_hist_window
                              && !s1_avatar_remote_probe
                              && !s1_avatar_local_probe;
        if (use_sram_background) begin
            bg_r = asset_pixel_r;
            bg_g = asset_pixel_g;
            bg_b = asset_pixel_b;
        end else if (s1_text_ram_row == FE_ROW_W'(TITLE_ROW)) begin
            bg_r = COL_TITLE_BG_R;
            bg_g = COL_TITLE_BG_G;
            bg_b = COL_TITLE_BG_B;
        end else if ((s1_text_ram_row >= FE_ROW_W'(INPUT_ROW_START))
                  && (s1_text_ram_row <= FE_ROW_W'(INPUT_ROW_END))) begin
            bg_r = COL_INPUT_BG_R;
            bg_g = COL_INPUT_BG_G;
            bg_b = COL_INPUT_BG_B;
        end

        if (bubble_fill_active && (s1_rd_attr == BUBBLE_ATTR_REMOTE)) begin
            bg_r = COL_REMOTE_BUBBLE_BG_R;
            bg_g = COL_REMOTE_BUBBLE_BG_G;
            bg_b = COL_REMOTE_BUBBLE_BG_B;
        end else if (bubble_fill_active && (s1_rd_attr == BUBBLE_ATTR_LOCAL)) begin
            bg_r = COL_LOCAL_BUBBLE_BG_R;
            bg_g = COL_LOCAL_BUBBLE_BG_G;
            bg_b = COL_LOCAL_BUBBLE_BG_B;
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
    logic remote_avatar_active;
    logic local_avatar_active;
    logic avatar_active;
    assign fg = pixel_on ^ cursor_xor;
    assign remote_avatar_active = s1_avatar_remote_probe;
    assign local_avatar_active  = s1_avatar_local_probe;
    assign avatar_active = ENABLE_SRAM_ASSETS
                           && in_connected
                           && !s1_in_bottom_strip
                           && (remote_avatar_active || local_avatar_active);

    always_comb begin
        if (!s1_de) begin
            video_red   = 8'h00;
            video_green = 8'h00;
            video_blue  = 8'h00;
        end else if (in_connected) begin
            if (avatar_active) begin
                video_red   = asset_pixel_r;
                video_green = asset_pixel_g;
                video_blue  = asset_pixel_b;
            // Big-emoji tile cells displace the mono mux entirely:
            // non-transparent indices output palette RGB, transparent
            // ones fall back to the same bg colour the rest of the
            // bubble's interior uses.
            end else if (is_big_emoji && (big_pix_idx != 4'h0)) begin
                video_red   = big_pal_r;
                video_green = big_pal_g;
                video_blue  = big_pal_b;
            end else if (is_big_emoji) begin
                video_red   = bg_r;
                video_green = bg_g;
                video_blue  = bg_b;
            end else begin
                video_red   = fg ? fg_r : bg_r;
                video_green = fg ? fg_g : bg_g;
                video_blue  = fg ? fg_b : bg_b;
            end
        end else if (s1_splash_in_region && pixel_on) begin
            video_red   = COL_SPLASH_FG_R;
            video_green = COL_SPLASH_FG_G;
            video_blue  = COL_SPLASH_FG_B;
        end else begin
            video_red   = splash_bg_r;
            video_green = splash_bg_g;
            video_blue  = splash_bg_b;
        end

        // Popup overlay sits above the regular UI/splash but below the
        // mouse pointer. The popup state is owned in the chat clock
        // domain and synchronised into this scan pipeline by fe_top.
        if (s1_de && s1_popup_in_region) begin
            if (s1_popup_border || s1_popup_grid_line) begin
                video_red   = COL_POPUP_BORDER_R;
                video_green = COL_POPUP_BORDER_G;
                video_blue  = COL_POPUP_BORDER_B;
            end else if (popup_text_pixel_on) begin
                video_red   = COL_POPUP_TEXT_R;
                video_green = COL_POPUP_TEXT_G;
                video_blue  = COL_POPUP_TEXT_B;
            end else if (s1_popup_item_hover) begin
                video_red   = COL_POPUP_HOVER_R;
                video_green = COL_POPUP_HOVER_G;
                video_blue  = COL_POPUP_HOVER_B;
            end else begin
                video_red   = COL_POPUP_BG_R;
                video_green = COL_POPUP_BG_G;
                video_blue  = COL_POPUP_BG_B;
            end
        end

        // Mouse pointer overlay  --  topmost, applied after all the
        // regular pixel selection so it shows up over text, bubbles,
        // wallpaper, splash, anything. Inverted-color rendering keeps
        // the cursor visible regardless of what's underneath.
        if (s1_de && s1_mouse_pointer_on) begin
            video_red   = ~video_red;
            video_green = ~video_green;
            video_blue  = ~video_blue;
        end
    end

    assign video_hsync = s1_hsync;
    assign video_vsync = s1_vsync;
    assign video_de    = s1_de;

endmodule

`endif  // FE_SCAN_SV
