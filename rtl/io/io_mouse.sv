// =====================================================================
// io_mouse.sv  --  PS/2 mouse driver (Intellimouse compatible)
// ---------------------------------------------------------------------
// Handles:
//   - Host-to-device initialisation (Intellimouse magic sequence
//     for scroll wheel, then 0xF4 Enable Data Reporting).
//   - Decodes 3-byte (standard) or 4-byte (Intellimouse) packets.
//   - Tracks absolute X/Y position (clamped to screen bounds).
//   - Detects scroll wheel and left/right-button click events.
//
// Init sequence (table-driven):
//   Index 0..5 : 0xF3 0xC8  0xF3 0x64  0xF3 0x50  (Intellimouse detect)
//   Index 6    : 0xF2                         (Read Device ID)
//   Index 7    : 0xF4                         (Enable Data Reporting)
//   After index 6, the device ID is read to determine 3/4-byte mode.
//
// Packet format (3 bytes, or 4 with Intellimouse extension):
//   Byte 0: [Y ovf][X ovf][Y sign][X sign][1][M btn][R btn][L btn]
//   Byte 1: X movement delta (8-bit, sign-extended from byte 0 bit 4)
//   Byte 2: Y movement delta (8-bit, sign-extended from byte 0 bit 5)
//   Byte 3: Z movement (scroll wheel, typically -1/0/+1)
//
// Output signals are all synchronous to clk. scroll_up / scroll_down
// and *_click are single-cycle pulses. mouse_x / mouse_y are
// persistent position registers.
// =====================================================================

`ifndef IO_MOUSE_SV
`define IO_MOUSE_SV

module io_mouse
    import chat_pkg::*;
#(
    parameter int CLK_FREQ_HZ = 100_000_000,
    parameter int SCREEN_W    = 800,
    parameter int SCREEN_H    = 600
) (
    input  logic clk,
    input  logic rst_n,

    // PS/2 tri-state pins
    inout  logic ps2_clk,
    inout  logic ps2_data,

    // Position (persistent, clamped to screen)
    output logic [9:0] mouse_x,
    output logic [9:0] mouse_y,

    // Scroll events (1-cycle pulses, debounced)
    output logic       scroll_up,
    output logic       scroll_down,

    // Clicks (1-cycle pulse on press edge)
    output logic       left_click,
    output logic       right_click
);

    // -----------------------------------------------------------------
    // Init command table
    // -----------------------------------------------------------------
    localparam int N_CMDS = 8;
    logic [7:0] cmd_table [N_CMDS];
    assign cmd_table[0] = 8'hF3;
    assign cmd_table[1] = 8'hC8;
    assign cmd_table[2] = 8'hF3;
    assign cmd_table[3] = 8'h64;
    assign cmd_table[4] = 8'hF3;
    assign cmd_table[5] = 8'h50;
    assign cmd_table[6] = 8'hF2;
    assign cmd_table[7] = 8'hF4;

    // -----------------------------------------------------------------
    // Init FSM states
    // -----------------------------------------------------------------
    typedef enum logic [2:0] {
        S_SEND    = 3'd0,  // drive TX with cmd_table[cmd_idx]
        S_WAIT    = 3'd1,  // wait for ACK (0xFA) from PHY
        S_READ_ID = 3'd2,  // wait for device ID (after 0xF2)
        S_READY   = 3'd3   // normal packet reception
    } init_state_e;

    init_state_e init_q;
    logic [2:0]  cmd_idx_q;    // 0..N_CMDS-1
    logic        has_scroll_q;

    // -----------------------------------------------------------------
    // Sub-modules: PHY (receive) + TX (transmit)
    // -----------------------------------------------------------------
    logic       phy_byte_valid;
    byte_t      phy_byte_data;
    logic       tx_cmd_valid, tx_cmd_ready;
    logic [7:0] tx_cmd_data;

    /* verilator lint_off PINCONNECTEMPTY */
    io_ps2_phy u_phy (
        .clk         (clk),
        .rst_n       (rst_n),
        .ps2_clk     (ps2_clk),
        .ps2_data    (ps2_data),
        .byte_valid  (phy_byte_valid),
        .byte_data   (phy_byte_data),
        .frame_error ()
    );
    /* verilator lint_on PINCONNECTEMPTY */

    io_ps2_tx #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ)
    ) u_tx (
        .clk       (clk),
        .rst_n     (rst_n),
        .cmd_valid (tx_cmd_valid),
        .cmd_ready (tx_cmd_ready),
        .cmd_data  (tx_cmd_data),
        .ps2_clk   (ps2_clk),
        .ps2_data  (ps2_data)
    );

    // TX command mux
    assign tx_cmd_valid = (init_q == S_SEND);
    assign tx_cmd_data  = cmd_table[cmd_idx_q];

    // -----------------------------------------------------------------
    // Packet accumulation (S_READY)
    // -----------------------------------------------------------------
    /* verilator lint_off UNUSEDSIGNAL */
    logic [1:0] pkt_cnt_q;
    logic [7:0] pkt_b0_q, pkt_b1_q;
    /* verilator lint_on UNUSEDSIGNAL */

    // -----------------------------------------------------------------
    // Position tracking
    // -----------------------------------------------------------------
    logic [9:0] pos_x_q, pos_y_q;

    // -----------------------------------------------------------------
    // Scroll debounce
    // -----------------------------------------------------------------
    localparam int SCROLL_SUPP = 3;
    logic [1:0] scroll_suppress_q;

    // -----------------------------------------------------------------
    // Button edge detectors
    // -----------------------------------------------------------------
    logic left_btn_prev_q;
    logic right_btn_prev_q;

    // -----------------------------------------------------------------
    // Sequential logic
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            init_q            <= S_SEND;
            cmd_idx_q         <= 3'd0;
            has_scroll_q      <= 1'b0;
            pkt_cnt_q         <= 2'd0;
            pkt_b0_q          <= '0;
            pkt_b1_q          <= '0;
            pos_x_q           <= 10'(SCREEN_W / 2);
            pos_y_q           <= 10'(SCREEN_H / 2);
            mouse_x           <= 10'(SCREEN_W / 2);
            mouse_y           <= 10'(SCREEN_H / 2);
            scroll_up         <= 1'b0;
            scroll_down       <= 1'b0;
            scroll_suppress_q <= '0;
            left_click        <= 1'b0;
            right_click       <= 1'b0;
            left_btn_prev_q   <= 1'b0;
            right_btn_prev_q  <= 1'b0;
        end else begin
            scroll_up   <= 1'b0;
            scroll_down <= 1'b0;
            left_click  <= 1'b0;
            right_click <= 1'b0;

            case (init_q)
                // -------------------------------------------------
                // S_SEND: drive TX with current command.
                // -------------------------------------------------
                S_SEND: begin
                    if (tx_cmd_ready) begin
                        if (cmd_idx_q == 3'd6)
                            init_q <= S_READ_ID;  // after 0xF2: read ID first
                        else
                            init_q <= S_WAIT;     // wait for ACK
                    end
                end

                // -------------------------------------------------
                // S_WAIT: consume PHY bytes until 0xFA (ACK).
                // Skip the echo byte (command itself, also valid).
                // -------------------------------------------------
                S_WAIT: begin
                    if (phy_byte_valid && phy_byte_data == 8'hFA) begin
                        if (cmd_idx_q == 3'(N_CMDS - 1)) begin
                            init_q <= S_READY;
                        end else begin
                            cmd_idx_q <= cmd_idx_q + 3'd1;
                            init_q    <= S_SEND;
                        end
                    end
                end

                // -------------------------------------------------
                // S_READ_ID: after 0xF2's ACK, next byte is ID.
                // The ACK (0xFA) itself is consumed here too.
                // -------------------------------------------------
                S_READ_ID: begin
                    if (phy_byte_valid) begin
                        if (phy_byte_data == 8'hFA) begin
                            // ACK received; next byte is the ID.
                            // Stay in S_READ_ID.
                        end else begin
                            // This is the device ID.
                            has_scroll_q <= (phy_byte_data == 8'h03);
                            cmd_idx_q    <= cmd_idx_q + 3'd1;  // advance to 0xF4
                            init_q       <= S_SEND;
                        end
                    end
                end

                // -------------------------------------------------
                // S_READY: normal packet reception
                // -------------------------------------------------
                S_READY: begin
                    if (phy_byte_valid) begin
                        case (pkt_cnt_q)
                            2'd0: begin
                                if (phy_byte_data[3]) begin
                                    pkt_b0_q  <= phy_byte_data;
                                    pkt_cnt_q <= 2'd1;
                                end
                            end

                            2'd1: begin
                                pkt_b1_q  <= phy_byte_data;
                                pkt_cnt_q <= 2'd2;
                            end

                            2'd2: begin
                                pkt_cnt_q <= 2'd0;

                                // --- Movement ---
                                // X delta: 9-bit signed from byte 0 sign + byte 1
                                // Y delta: 9-bit signed from byte 0 sign + byte 2
                                //   PS/2 Y+ = up, screen Y+ = down → negate.
                                begin
                                    automatic logic signed [8:0] dx, dy;
                                    automatic int signed nx, ny;
                                    dx = signed'({pkt_b0_q[4], pkt_b1_q});
                                    dy = -signed'({pkt_b0_q[5], phy_byte_data});

                                    nx = int'(pos_x_q) + int'(dx);
                                    ny = int'(pos_y_q) + int'(dy);
                                    if (nx < 0)          nx = 0;
                                    if (nx >= SCREEN_W)  nx = SCREEN_W - 1;
                                    if (ny < 0)          ny = 0;
                                    if (ny >= SCREEN_H)  ny = SCREEN_H - 1;
                                    pos_x_q <= 10'(nx);
                                    pos_y_q <= 10'(ny);
                                    mouse_x <= 10'(nx);
                                    mouse_y <= 10'(ny);
                                end

                                // --- Buttons ---
                                left_btn_prev_q <= pkt_b0_q[0];
                                if (!left_btn_prev_q && pkt_b0_q[0])
                                    left_click <= 1'b1;
                                right_btn_prev_q <= pkt_b0_q[1];
                                if (!right_btn_prev_q && pkt_b0_q[1])
                                    right_click <= 1'b1;

                                // --- Scroll: need 4th byte? ---
                                if (has_scroll_q)
                                    pkt_cnt_q <= 2'd3;
                            end

                            2'd3: begin
                                // Scroll wheel byte (Intellimouse)
                                pkt_cnt_q <= 2'd0;

                                if (scroll_suppress_q == '0) begin
                                    if (phy_byte_data == 8'h01)
                                        scroll_up <= 1'b1;
                                    else if (phy_byte_data == 8'hFF)
                                        scroll_down <= 1'b1;
                                    if (phy_byte_data != 8'h00)
                                        scroll_suppress_q <= SCROLL_SUPP[1:0];
                                end else begin
                                    scroll_suppress_q <= scroll_suppress_q - 1'b1;
                                end
                            end
                        endcase
                    end
                end

                default: init_q <= S_SEND;
            endcase
        end
    end

endmodule

`endif  // IO_MOUSE_SV
