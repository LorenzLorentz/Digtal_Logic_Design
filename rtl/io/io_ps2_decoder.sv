// =====================================================================
// io_ps2_decoder.sv  --  PS/2 set-2 byte stream -> key event
// ---------------------------------------------------------------------
// Consumes a one-byte-per-pulse stream from io_ps2_phy and produces
// io-style key events: a 1-cycle ev_valid pulse with ev_type
// (key_type_e) and ev_ascii (only meaningful for KEY_CHAR).
//
// State maintained:
//   lshift_held_q  :  set by Left Shift make (0x12), cleared by its
//                     matching release (F0 12).
//   rshift_held_q  :  set by Right Shift make (0x59 plain or E0 59),
//                     cleared by the matching release. Tracked
//                     independently from lshift_held_q so releasing one
//                     while the other is still held does not drop the
//                     modifier. The effective shift used for ASCII
//                     translation is lshift_held_q | rshift_held_q.
//   caps_locked_q  :  toggled on each CapsLock make (0x58); release of
//                     CapsLock is ignored (LED is host-managed in real
//                     PS/2; we don't drive the LED -- agreed up-front
//                     to keep the decoder receive-only).
//                     Reset value is 0 by design. The keyboard's actual
//                     CapsLock LED state on power-up is not observable
//                     from a receive-only host, so if it boots with
//                     CapsLock ON the user re-syncs by pressing Caps
//                     once. This is the same behavior most PCs exhibit.
//   seen_e0_q      :  1 for the cycle AFTER receiving 0xE0; tells the
//                     next byte to be interpreted as an extended-key
//                     make (or, with seen_f0_q, an extended release).
//                     Cleared by every other byte, or by the prefix
//                     watchdog if no follow-up byte arrives in time.
//   seen_f0_q      :  similar; means "the next byte is a release".
//
// Prefix watchdog:
//   If seen_e0_q / seen_f0_q stay asserted for PREFIX_TIMEOUT_CYCLES
//   local-clock cycles without a follow-up byte, both flags clear. This
//   keeps a lost byte after E0/F0 (e.g. a phy frame error swallowed
//   the release scancode) from poisoning subsequent decoding.
//
// ASCII mapping:
//   * For LETTERS, effective_shift = shift_held_q XOR caps_locked_q.
//   * For everything else, effective_shift = shift_held_q only.
//   * `scancode_to_ascii` returns 8'h00 for unmapped codes; the FSM
//     uses that as a "drop this byte" signal.
//
// Bytes that do NOT produce a key event:
//   - 0xE0 / 0xF0 prefix bytes
//   - Shift make/release (only updates shift_held_q)
//   - CapsLock make (toggles caps_locked_q); CapsLock release dropped
//   - 0xAA (Basic Assurance Test result) and any unmapped scancode
//   - Releases of non-Shift keys
//
// Bytes that DO produce a key event:
//   - 0x5A make           -> KEY_ENTER
//   - 0x66 make           -> KEY_BACKSPACE
//   - 0x76 make           -> KEY_ESC
//   - 0xE0 0x6B make      -> KEY_LEFT
//   - 0xE0 0x74 make      -> KEY_RIGHT
//   - 0xE0 0x75 make      -> KEY_UP
//   - 0xE0 0x72 make      -> KEY_DOWN
//   - any letter / digit / mapped symbol make -> KEY_CHAR with ASCII
// =====================================================================

`ifndef IO_PS2_DECODER_SV
`define IO_PS2_DECODER_SV

module io_ps2_decoder
    import chat_pkg::*;
#(
    parameter int PREFIX_TIMEOUT_CYCLES = 1_000_000  // ~10 ms @ 100 MHz
) (
    input  logic        clk,
    input  logic        rst_n,

    // Byte stream from io_ps2_phy (1-cycle pulse with byte_data).
    input  logic        byte_valid,
    input  byte_t       byte_data,

    // Key event output (1-cycle pulse).
    output logic        ev_valid,
    output logic [2:0]  ev_type,
    output byte_t       ev_ascii
);

    // -----------------------------------------------------------------
    // Sticky modifier state and transient prefix flags.
    // -----------------------------------------------------------------
    logic lshift_held_q;
    logic rshift_held_q;
    logic caps_locked_q;
    logic seen_e0_q;
    logic seen_f0_q;

    logic shift_held;
    assign shift_held = lshift_held_q | rshift_held_q;

    // Prefix watchdog counter.
    localparam int PT_W = $clog2(PREFIX_TIMEOUT_CYCLES + 1);
    logic [PT_W-1:0] prefix_timeout_q;

    // -----------------------------------------------------------------
    // Letter test (letters use shift XOR caps, others use plain shift).
    // -----------------------------------------------------------------
    function automatic logic is_letter_scancode(input byte_t code);
        case (code)
            8'h1C, 8'h32, 8'h21, 8'h23, 8'h24, 8'h2B, 8'h34, 8'h33,
            8'h43, 8'h3B, 8'h42, 8'h4B, 8'h3A, 8'h31, 8'h44, 8'h4D,
            8'h15, 8'h2D, 8'h1B, 8'h2C, 8'h3C, 8'h2A, 8'h1D, 8'h22,
            8'h35, 8'h1A: return 1'b1;
            default:      return 1'b0;
        endcase
    endfunction

    // -----------------------------------------------------------------
    // Scan-code -> ASCII for the US-layout printable keys we care about.
    // Returns 8'h00 for codes not mapped to a printable character.
    // -----------------------------------------------------------------
    function automatic byte_t scancode_to_ascii(
        input byte_t code,
        input logic  shifted
    );
        case (code)
            // Letters
            8'h1C: return shifted ? "A" : "a";
            8'h32: return shifted ? "B" : "b";
            8'h21: return shifted ? "C" : "c";
            8'h23: return shifted ? "D" : "d";
            8'h24: return shifted ? "E" : "e";
            8'h2B: return shifted ? "F" : "f";
            8'h34: return shifted ? "G" : "g";
            8'h33: return shifted ? "H" : "h";
            8'h43: return shifted ? "I" : "i";
            8'h3B: return shifted ? "J" : "j";
            8'h42: return shifted ? "K" : "k";
            8'h4B: return shifted ? "L" : "l";
            8'h3A: return shifted ? "M" : "m";
            8'h31: return shifted ? "N" : "n";
            8'h44: return shifted ? "O" : "o";
            8'h4D: return shifted ? "P" : "p";
            8'h15: return shifted ? "Q" : "q";
            8'h2D: return shifted ? "R" : "r";
            8'h1B: return shifted ? "S" : "s";
            8'h2C: return shifted ? "T" : "t";
            8'h3C: return shifted ? "U" : "u";
            8'h2A: return shifted ? "V" : "v";
            8'h1D: return shifted ? "W" : "w";
            8'h22: return shifted ? "X" : "x";
            8'h35: return shifted ? "Y" : "y";
            8'h1A: return shifted ? "Z" : "z";
            // Digits row (US QWERTY)
            8'h16: return shifted ? "!" : "1";
            8'h1E: return shifted ? "@" : "2";
            8'h26: return shifted ? "#" : "3";
            8'h25: return shifted ? "$" : "4";
            8'h2E: return shifted ? "%" : "5";
            8'h36: return shifted ? "^" : "6";
            8'h3D: return shifted ? "&" : "7";
            8'h3E: return shifted ? "*" : "8";
            8'h46: return shifted ? "(" : "9";
            8'h45: return shifted ? ")" : "0";
            // Common symbols
            8'h4E: return shifted ? "_"  : "-";
            8'h55: return shifted ? "+"  : "=";
            8'h54: return shifted ? "{"  : "[";
            8'h5B: return shifted ? "}"  : "]";
            8'h5D: return shifted ? "|"  : "\\";
            8'h4C: return shifted ? ":"  : ";";
            8'h52: return shifted ? "\"" : "'";
            8'h41: return shifted ? "<"  : ",";
            8'h49: return shifted ? ">"  : ".";
            8'h4A: return shifted ? "?"  : "/";
            8'h0E: return shifted ? "~"  : "`";
            // Space
            8'h29: return " ";
            default: return 8'h00;
        endcase
    endfunction

    // -----------------------------------------------------------------
    // Combinational pre-compute used inside the FSM.
    //   - decoded_ascii is non-zero only for "printable" scancodes that
    //     should produce KEY_CHAR.
    //   - effective_shift mixes in CapsLock for letters only.
    // -----------------------------------------------------------------
    logic   is_letter;
    logic   effective_shift;
    byte_t  decoded_ascii;

    assign is_letter       = is_letter_scancode(byte_data);
    assign effective_shift = is_letter ? (shift_held ^ caps_locked_q)
                                       : shift_held;
    assign decoded_ascii   = scancode_to_ascii(byte_data, effective_shift);

    // -----------------------------------------------------------------
    // Shift release conditions (named for clarity inside the FSM).
    //   - Left Shift release  = plain F0 12   (no E0)
    //   - Right Shift release = F0 59 or E0 F0 59 (treat both identically)
    // -----------------------------------------------------------------
    logic is_lshift_release, is_rshift_release;
    assign is_lshift_release = !seen_e0_q && (byte_data == 8'h12);
    assign is_rshift_release =                (byte_data == 8'h59);

    // -----------------------------------------------------------------
    // Sequential state machine.
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            lshift_held_q    <= 1'b0;
            rshift_held_q    <= 1'b0;
            caps_locked_q    <= 1'b0;
            seen_e0_q        <= 1'b0;
            seen_f0_q        <= 1'b0;
            prefix_timeout_q <= '0;
            ev_valid         <= 1'b0;
            ev_type          <= 3'd0;
            ev_ascii         <= 8'd0;
        end else begin
            // Per-cycle defaults; case branches override these.
            ev_valid <= 1'b0;

            if (byte_valid) begin
                prefix_timeout_q <= '0;

                case (byte_data)
                    8'hE0: begin
                        // Extended-make prefix; consume any stale F0.
                        seen_e0_q <= 1'b1;
                        seen_f0_q <= 1'b0;
                    end
                    8'hF0: begin
                        // Release prefix. seen_e0_q intentionally kept --
                        // an E0 F0 XX sequence is an extended-key release.
                        seen_f0_q <= 1'b1;
                    end
                    8'hAA: begin
                        // BAT result. Drop any pending prefix that was
                        // probably stale across a keyboard reset.
                        seen_e0_q <= 1'b0;
                        seen_f0_q <= 1'b0;
                    end
                    default: begin
                        // Any other byte consumes both prefix flags.
                        seen_e0_q <= 1'b0;
                        seen_f0_q <= 1'b0;

                        // Decode based on PRE-edge prefix state.
                        if (seen_f0_q) begin
                            // Release. Only Shift releases are meaningful;
                            // every other release is dropped.
                            if (is_lshift_release) lshift_held_q <= 1'b0;
                            if (is_rshift_release) rshift_held_q <= 1'b0;
                        end else if (seen_e0_q) begin
                            // Extended make.
                            unique case (byte_data)
                                8'h59: rshift_held_q <= 1'b1;  // Right Shift
                                // Arrow keys piggy-back the Shift-held
                                // state on ev_ascii bit 0 (see chat_pkg
                                // KEY_SHIFT_MASK). Backend uses it to
                                // route Shift+Up/Down -> input scroll.
                                8'h6B: begin
                                    ev_valid <= 1'b1;
                                    ev_type  <= 3'(KEY_LEFT);
                                    ev_ascii <= shift_held ? KEY_SHIFT_MASK : 8'h00;
                                end
                                8'h74: begin
                                    ev_valid <= 1'b1;
                                    ev_type  <= 3'(KEY_RIGHT);
                                    ev_ascii <= shift_held ? KEY_SHIFT_MASK : 8'h00;
                                end
                                8'h75: begin
                                    ev_valid <= 1'b1;
                                    ev_type  <= 3'(KEY_UP);
                                    ev_ascii <= shift_held ? KEY_SHIFT_MASK : 8'h00;
                                end
                                8'h72: begin
                                    ev_valid <= 1'b1;
                                    ev_type  <= 3'(KEY_DOWN);
                                    ev_ascii <= shift_held ? KEY_SHIFT_MASK : 8'h00;
                                end
                                default: ;  // unsupported extended key
                            endcase
                        end else begin
                            // Plain make.
                            unique case (byte_data)
                                8'h12:        lshift_held_q <= 1'b1;
                                8'h59:        rshift_held_q <= 1'b1;
                                8'h58:        caps_locked_q <= ~caps_locked_q;
                                8'h5A: begin
                                    ev_valid <= 1'b1;
                                    if (shift_held) begin
                                        ev_type  <= 3'(KEY_CHAR);
                                        ev_ascii <= 8'h0A;
                                    end else begin
                                        ev_type  <= 3'(KEY_ENTER);
                                        ev_ascii <= 8'h00;
                                    end
                                end
                                8'h66: begin
                                    ev_valid <= 1'b1;
                                    ev_type  <= 3'(KEY_BACKSPACE);
                                    ev_ascii <= 8'h00;
                                end
                                8'h76: begin
                                    ev_valid <= 1'b1;
                                    ev_type  <= 3'(KEY_ESC);
                                    ev_ascii <= 8'h00;
                                end
                                default: begin
                                    if (decoded_ascii != 8'h00) begin
                                        ev_valid <= 1'b1;
                                        ev_type  <= 3'(KEY_CHAR);
                                        ev_ascii <= decoded_ascii;
                                    end
                                end
                            endcase
                        end
                    end
                endcase
            end else if (seen_e0_q || seen_f0_q) begin
                // Prefix watchdog: if no follow-up byte arrives within
                // PREFIX_TIMEOUT_CYCLES, drop the prefix so a lost byte
                // doesn't poison subsequent decoding.
                if (prefix_timeout_q == PT_W'(PREFIX_TIMEOUT_CYCLES - 1)) begin
                    seen_e0_q        <= 1'b0;
                    seen_f0_q        <= 1'b0;
                    prefix_timeout_q <= '0;
                end else begin
                    prefix_timeout_q <= prefix_timeout_q + 1'b1;
                end
            end else begin
                prefix_timeout_q <= '0;
            end
        end
    end

endmodule

`endif  // IO_PS2_DECODER_SV
