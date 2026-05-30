// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vbe_top__Syms.h"


VL_ATTR_COLD void Vbe_top___024root__trace_init_sub__TOP__chat_pkg__0(Vbe_top___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vbe_top___024root__trace_init_sub__TOP__fe_pkg__0(Vbe_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbe_top___024root__trace_init_sub__TOP__0(Vbe_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_init_sub__TOP__0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+299,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+300,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+301,0,"io_key_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"io_key_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"io_key_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+304,0,"io_key_ascii",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"io_mouse_click_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"io_mouse_right_click_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"io_mouse_click_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"io_mouse_click_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"io_mouse_click_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"fe_input_scroll_offset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+311,0,"fe_input_at_limit",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+312,0,"fe_hist_wr_row",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+313,0,"fe_hist_scroll_offset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_QUAD(tracep,c+314,0,"fe_hist_owner_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_WIDE(tracep,c+316,0,"fe_hist_owner_store_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 383,0);
    VL_TRACE_DECL_WIDE(tracep,c+328,0,"fe_hist_owner_side",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_WIDE(tracep,c+332,0,"fe_hist_owner_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 447,0);
    VL_TRACE_DECL_BIT(tracep,c+100,0,"ui_popup_active",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+101,0,"ui_popup_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+102,0,"ui_popup_x",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+103,0,"ui_popup_y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BIT(tracep,c+104,0,"emoji_suggest_active",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"emoji_suggest_count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+106,0,"emoji_suggest_ids",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 59,0);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"emoji_suggest_anchor_pos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+346,0,"cm_rx_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+347,0,"cm_rx_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+348,0,"cm_rx_frame_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+349,0,"cm_rx_seq",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+350,0,"cm_rx_len",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+351,0,"cm_rx_payload",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BIT(tracep,c+383,0,"cm_status_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+384,0,"cm_status_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+385,0,"cm_status_msg_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+386,0,"cm_status_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+387,0,"be_tx_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+388,0,"be_tx_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+389,0,"be_tx_frame_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+390,0,"be_tx_msg_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+391,0,"be_tx_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+392,0,"be_tx_payload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BIT(tracep,c+424,0,"be_render_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+425,0,"be_render_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+426,0,"be_render_cmd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+427,0,"be_render_msg_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+428,0,"be_render_store_idx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+429,0,"be_render_side",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+430,0,"be_render_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+431,0,"be_render_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+432,0,"be_render_payload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"be_render_cursor_pos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+465,0,"be_render_ascii",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+466,0,"be_render_conn_state",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+109,0,"be_render_peer_name_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+110,0,"be_render_peer_name",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BIT(tracep,c+114,0,"be_has_quote",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+467,0,"line_rd_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+468,0,"line_rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"line_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"cursor_pos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+117,0,"enter_committed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+469,0,"store_rd_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+470,0,"store_rd_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+471,0,"store_rd_msg_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+472,0,"store_rd_side",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+473,0,"store_rd_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+474,0,"store_rd_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+475,0,"store_rd_payload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+466,0,"conn_state_obs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "be_top", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"LINE_IDX_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+522,0,"STORE_IDX_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"MY_NAME_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+524,0,"MY_NAME_PACKED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BIT(tracep,c+299,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+300,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+301,0,"io_key_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"io_key_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"io_key_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+304,0,"io_key_ascii",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"io_mouse_click_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"io_mouse_right_click_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"io_mouse_click_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"io_mouse_click_x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"io_mouse_click_y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"fe_input_scroll_offset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+311,0,"fe_input_at_limit",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+312,0,"fe_hist_wr_row",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+313,0,"fe_hist_scroll_offset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_QUAD(tracep,c+314,0,"fe_hist_owner_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_WIDE(tracep,c+316,0,"fe_hist_owner_store_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 383,0);
    VL_TRACE_DECL_WIDE(tracep,c+328,0,"fe_hist_owner_side",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_WIDE(tracep,c+332,0,"fe_hist_owner_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 447,0);
    VL_TRACE_DECL_BIT(tracep,c+100,0,"ui_popup_active",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+101,0,"ui_popup_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+102,0,"ui_popup_x",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+103,0,"ui_popup_y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BIT(tracep,c+104,0,"emoji_suggest_active",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"emoji_suggest_count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+106,0,"emoji_suggest_ids",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 59,0);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"emoji_suggest_anchor_pos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+346,0,"cm_rx_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+347,0,"cm_rx_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+348,0,"cm_rx_frame_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+349,0,"cm_rx_seq",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+350,0,"cm_rx_len",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+351,0,"cm_rx_payload",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BIT(tracep,c+383,0,"cm_status_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+384,0,"cm_status_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+385,0,"cm_status_msg_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+386,0,"cm_status_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+387,0,"be_tx_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+388,0,"be_tx_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+389,0,"be_tx_frame_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+390,0,"be_tx_msg_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+391,0,"be_tx_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+392,0,"be_tx_payload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BIT(tracep,c+424,0,"be_render_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+425,0,"be_render_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+426,0,"be_render_cmd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+427,0,"be_render_msg_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+428,0,"be_render_store_idx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+429,0,"be_render_side",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+430,0,"be_render_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+431,0,"be_render_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+432,0,"be_render_payload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"be_render_cursor_pos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+465,0,"be_render_ascii",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+466,0,"be_render_conn_state",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+109,0,"be_render_peer_name_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+110,0,"be_render_peer_name",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BIT(tracep,c+114,0,"be_has_quote",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+467,0,"line_rd_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+468,0,"line_rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"line_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"cursor_pos",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+117,0,"enter_committed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+469,0,"store_rd_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+470,0,"store_rd_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+471,0,"store_rd_msg_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+472,0,"store_rd_side",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+473,0,"store_rd_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+474,0,"store_rd_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+475,0,"store_rd_payload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+466,0,"conn_state_obs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+118,0,"state_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"state_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"len_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"cursor_pos_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+117,0,"enter_pulse_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"MAX_INPUT_VIS_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+529,0,"INPUT_NEWLINE_LIMIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"INPUT_NL_COUNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+119,0,"input_newline_count_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+120,0,"last_event_ascii_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+121,0,"delete_was_newline_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+122,0,"shift_idx_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+123,0,"shift_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+124,0,"enc_src_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+125,0,"enc_dst_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"wr_ptr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+127,0,"next_msg_id_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+128,0,"pending_msg_id_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+129,0,"pending_store_idx_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+130,0,"pending_len_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+131,0,"pending_payload_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"rx_seq_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"rx_store_idx_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+165,0,"rx_len_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+166,0,"rx_payload_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+198,0,"status_msg_id_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+199,0,"status_status_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_WIDE(tracep,c+110,0,"peer_name_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+109,0,"peer_name_len_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+200,0,"click_pending_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+201,0,"click_is_right_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+202,0,"click_x_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+203,0,"click_y_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+204,0,"click_raw_col_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+205,0,"click_screen_row_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+206,0,"click_target_row_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+207,0,"click_target_col_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+208,0,"click_vis_row_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+209,0,"click_vis_col_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BIT(tracep,c+210,0,"click_walk_done_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+100,0,"popup_active_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+101,0,"popup_type_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+102,0,"popup_x_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+103,0,"popup_y_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+211,0,"menu_store_idx_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+114,0,"has_quote_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+212,0,"quoted_msg_id_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+213,0,"quoted_side_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_WIDE(tracep,c+214,0,"disp_payload_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+246,0,"disp_len_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+247,0,"disp_build_idx_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+248,0,"disp_for_remote_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"quoted_store_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"quoted_store_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"quoted_store_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+4,0,"quoted_store_payload",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+249,0,"recall_msg_id_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+250,0,"recall_store_idx_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+251,0,"recall_side_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+252,0,"recall_send_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"store_ui_rd_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"store_ui_rd_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"store_ui_rd_msg_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"store_ui_rd_side",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"store_ui_rd_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"store_ui_rd_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+4,0,"store_ui_rd_payload",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BIT(tracep,c+253,0,"emoji_suggest_tracking_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+104,0,"emoji_suggest_active_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"emoji_suggest_count_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+106,0,"emoji_suggest_ids_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 59,0);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"emoji_suggest_anchor_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+254,0,"emoji_complete_token_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+255,0,"emoji_complete_char_idx_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+256,0,"emoji_complete_token_len_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"STICKER_PICKER_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"STICKER_PICKER_Y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BIT(tracep,c+41,0,"key_char_insert_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+257,0,"click_popup_dx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+258,0,"click_popup_dy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+259,0,"click_sticker_col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+260,0,"click_in_sticker_picker",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+261,0,"click_sticker_anchor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+262,0,"click_in_msg_menu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+263,0,"click_msg_menu_quote",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+264,0,"click_msg_menu_recall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+265,0,"click_emoji_dx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+266,0,"click_emoji_dy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+267,0,"click_emoji_row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+268,0,"click_in_emoji_suggest",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+269,0,"click_emoji_token_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+270,0,"click_emoji_token_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+271,0,"click_emoji_prefix_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+272,0,"click_emoji_suffix_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+273,0,"click_emoji_fits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+274,0,"click_in_hist_window",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"click_hist_slot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+204,0,"click_hist_col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BIT(tracep,c+507,0,"click_hist_owner_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+508,0,"click_hist_owner_store_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"click_hist_owner_side",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"click_hist_owner_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"click_hist_bubble_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"click_hist_bubble_right",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BIT(tracep,c+509,0,"click_in_hist_bubble",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+213,0,"quote_lkup_side",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+212,0,"quote_lkup_msg_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+47,0,"quote_lkup_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"quote_lkup_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+275,0,"suggest_recompute",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+276,0,"suggest_tracking_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+277,0,"suggest_anchor_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+278,0,"suggest_cursor_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+279,0,"suggest_prefix_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+280,0,"suggest_prefix_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "suggest_prefix_byte", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 6);
    for (int i = 0; i < 7; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+281+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+288,0,"suggest_count_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+289,0,"suggest_ids_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 59,0);
    VL_TRACE_DECL_BIT(tracep,c+291,0,"suggest_active_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+292,0,"enc_emit_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+293,0,"enc_src_delta",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+294,0,"enc_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+533,0,"my_name_payload",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+510,0,"rx_len_clamped",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+511,0,"rx_name_len_clamped",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+48,0,"peer_name_changed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+512,0,"rx_is_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+513,0,"rx_is_hello",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+514,0,"rx_is_rehello",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+515,0,"rx_is_username",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+516,0,"rx_is_goodbye",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+517,0,"rx_is_recall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+384,0,"in_chat_idle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+295,0,"in_handshake_idle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+296,0,"in_disc_idle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+49,0,"accept_io",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+50,0,"accept_rx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+51,0,"accept_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+52,0,"accept_mouse_click",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+53,0,"accept_username_frame",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+54,0,"do_store_clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"store_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"store_wr_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"store_wr_msg_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+57,0,"store_wr_side",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+58,0,"store_wr_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+59,0,"store_wr_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+60,0,"store_wr_payload",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BIT(tracep,c+92,0,"store_lookup_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"store_lookup_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+94,0,"store_lookup_side",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"store_lookup_msg_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"store_upd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"store_upd_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+519,0,"store_upd_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+97,0,"use_quote_lkup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+98,0,"rx_quote_entry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+297,0,"local_quote_entry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+99,0,"eff_quote_lkup_side",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+520,0,"eff_quote_lkup_msg_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_store", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+522,0,"IDX_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+299,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+300,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"wr_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"wr_msg_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+57,0,"wr_side",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+58,0,"wr_status",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+59,0,"wr_len",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+60,0,"wr_payload",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"upd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"upd_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+519,0,"upd_status",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+54,0,"clear_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+469,0,"rd_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+470,0,"rd_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+471,0,"rd_msg_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+472,0,"rd_side",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+473,0,"rd_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+474,0,"rd_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+475,0,"rd_payload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"rd2_idx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"rd2_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"rd2_msg_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"rd2_side",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"rd2_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"rd2_len",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_WIDE(tracep,c+4,0,"rd2_payload",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BUS(tracep,c+94,0,"lookup_side",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"lookup_msg_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+92,0,"lookup_hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"lookup_idx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "unnamedblk5", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+298,0,"src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "chat_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vbe_top___024root__trace_init_sub__TOP__chat_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fe_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vbe_top___024root__trace_init_sub__TOP__fe_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vbe_top___024root__trace_init_dtype_sub____0(Vbe_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vbe_top___024root__trace_init_dtype____0(Vbe_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_init_dtype____0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbe_top___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vbe_top___024root__trace_init_dtype_sub____0(Vbe_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_init_dtype_sub____0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 6);
    for (int i = 0; i < 7; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vbe_top___024root__trace_init_sub__TOP__fe_pkg__0(Vbe_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_init_sub__TOP__fe_pkg__0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+565,0,"FE_N_ROWS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"FE_N_COLS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"FE_ROW_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"FE_COL_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+566,0,"TITLE_ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+567,0,"HIST_ROW_START",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+568,0,"HIST_ROW_END",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"MAX_INPUT_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+569,0,"INPUT_ROW_START",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+570,0,"INPUT_ROW_END",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+567,0,"INPUT_PREFIX_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+567,0,"BUBBLE_MARGIN_L",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+567,0,"BUBBLE_MARGIN_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+571,0,"BUBBLE_RIGHT_EDGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+572,0,"N_HIST_STORED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+573,0,"N_HIST_VISIBLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"N_INPUT_VISIBLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+522,0,"HIST_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+574,0,"SCROLL_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+522,0,"SCROLL_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+575,0,"INPUT_SCROLL_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"INPUT_SCROLL_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"INPUT_LINE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"INPUT_N_LINES_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+576,0,"INPUT_SCREEN_START",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+577,0,"INPUT_SCREEN_END",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+578,0,"INPUT_PIXEL_Y_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+579,0,"INPUT_PIXEL_Y_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+580,0,"INPUT_LIMIT_MARK_COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+581,0,"QUOTE_MARK_COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+582,0,"SPRITE_BL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+583,0,"SPRITE_BR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+584,0,"SPRITE_FBL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+585,0,"SPRITE_FBR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+586,0,"SPRITE_BL_TOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+587,0,"SPRITE_BR_TOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+588,0,"SPRITE_BL_BOT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+589,0,"SPRITE_BR_BOT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+590,0,"SPRITE_BL_MID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+591,0,"SPRITE_BR_MID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"BUBBLE_ATTR_NONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"BUBBLE_ATTR_REMOTE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"BUBBLE_ATTR_LOCAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+595,0,"EMOJI_HAPPY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"EMOJI_SAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+597,0,"EMOJI_HEART",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+598,0,"EMOJI_OK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+599,0,"EMOJI_LAUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"EMOJI_WINK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"EMOJI_ANGRY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+602,0,"EMOJI_STAR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+603,0,"EMOJI_FIRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+604,0,"EMOJI_YES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"EMOJI_NO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"EMOJI_UP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+607,0,"EMOJI_DOWN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"EMOJI_DOGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"EMOJI_MAIRUO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SPRITE_FAIL_X",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+611,0,"HWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"HSIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+613,0,"HFP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+614,0,"HSP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+615,0,"HMAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+616,0,"VSIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"VFP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+618,0,"VSP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+619,0,"VMAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+620,0,"HSPP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+620,0,"VSPP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+621,0,"BLINK_FRAMES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+576,0,"SPLASH_COLS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+622,0,"SPLASH_H_LEFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+623,0,"SPLASH_V_TOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+624,0,"COL_FG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+624,0,"COL_FG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+624,0,"COL_FG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+625,0,"COL_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+625,0,"COL_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+625,0,"COL_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+626,0,"COL_TITLE_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+627,0,"COL_TITLE_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+628,0,"COL_TITLE_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+627,0,"COL_INPUT_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+627,0,"COL_INPUT_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+627,0,"COL_INPUT_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+629,0,"COL_REMOTE_BUBBLE_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+630,0,"COL_REMOTE_BUBBLE_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+631,0,"COL_REMOTE_BUBBLE_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+632,0,"COL_LOCAL_BUBBLE_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+633,0,"COL_LOCAL_BUBBLE_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+634,0,"COL_LOCAL_BUBBLE_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"ASSET_BG_W_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+616,0,"ASSET_BG_H_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"ASSET_AVATAR_W_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"ASSET_AVATAR_H_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+566,0,"ASSET_BG_BASE_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+635,0,"ASSET_LOCAL_AVATAR_BASE_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+636,0,"ASSET_REMOTE_AVATAR_BASE_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+637,0,"COL_BOOT_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+626,0,"COL_BOOT_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+638,0,"COL_BOOT_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+637,0,"COL_HS_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+638,0,"COL_HS_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+637,0,"COL_HS_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+638,0,"COL_DISC_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+637,0,"COL_DISC_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+637,0,"COL_DISC_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+639,0,"COL_SPLASH_FG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+639,0,"COL_SPLASH_FG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+639,0,"COL_SPLASH_FG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+567,0,"POPUP_BORDER_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+640,0,"POPUP_MSG_MENU_W_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+641,0,"POPUP_MSG_ITEM_H_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+642,0,"POPUP_MSG_MENU_H_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+611,0,"POPUP_MSG_TEXT_X_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"POPUP_MSG_TEXT_Y_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"POPUP_STICKER_W_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+644,0,"POPUP_STICKER_H_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+645,0,"COL_POPUP_BG_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+646,0,"COL_POPUP_BG_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+647,0,"COL_POPUP_BG_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+648,0,"COL_POPUP_BORDER_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+649,0,"COL_POPUP_BORDER_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+650,0,"COL_POPUP_BORDER_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+651,0,"COL_POPUP_HOVER_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+652,0,"COL_POPUP_HOVER_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+653,0,"COL_POPUP_HOVER_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+654,0,"COL_POPUP_TEXT_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+655,0,"COL_POPUP_TEXT_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+656,0,"COL_POPUP_TEXT_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"BIG_EMOJI_BASE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+657,0,"BIG_EMOJI_N_ROWS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+522,0,"BIG_EMOJI_N_COLS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+658,0,"BIG_EMOJI_N_TILES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"BIG_EMOJI_COUNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+659,0,"BIG_EMOJI_END_EXCL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+660,0,"BIG_EMOJI_HEARTBROKEN_ANCHOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+661,0,"BIG_EMOJI_HISSING_ANCHOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+662,0,"BIG_EMOJI_SHRUG_ANCHOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+663,0,"BIG_EMOJI_SWEAT_ANCHOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+664,0,"BIG_EMOJI_XIUCAI_ANCHOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
}

VL_ATTR_COLD void Vbe_top___024root__trace_init_sub__TOP__chat_pkg__0(Vbe_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_init_sub__TOP__chat_pkg__0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+565,0,"MAX_MSG_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+572,0,"MAX_MSG_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"MAX_LINE_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"MAX_NAME_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"MSG_ID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"SEQ_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"LEN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"RETRY_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"MAX_RETRY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+666,0,"SOF_BYTE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"CRC_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+667,0,"CRC16_POLY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+668,0,"CRC16_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"CLK_FREQ_HZ_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+670,0,"UART_BAUD_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+671,0,"KEY_SHIFT_MASK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+672,0,"KEY_CTRL_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"POPUP_STICKER_COUNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+572,0,"POPUP_STICKER_CELL_W_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"POPUP_STICKER_PICKER_W_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+644,0,"POPUP_STICKER_PICKER_H_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+529,0,"EMOJI_TOKEN_COUNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"EMOJI_TOKEN_ID_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"EMOJI_TOKEN_MAX_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+529,0,"EMOJI_SUGGEST_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"EMOJI_SUGGEST_COUNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"EMOJI_SUGGEST_X_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+673,0,"EMOJI_SUGGEST_Y_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+640,0,"EMOJI_SUGGEST_W_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+567,0,"EMOJI_SUGGEST_BORDER_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"EMOJI_SUGGEST_ITEM_H_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"EMOJI_SUGGEST_TEXT_X_PX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+674,0,"EMOJI_TOKEN_HAPPY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+675,0,"EMOJI_TOKEN_SAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+676,0,"EMOJI_TOKEN_HEART",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+677,0,"EMOJI_TOKEN_OK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+678,0,"EMOJI_TOKEN_LAUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+679,0,"EMOJI_TOKEN_WINK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+680,0,"EMOJI_TOKEN_ANGRY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+681,0,"EMOJI_TOKEN_STAR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+682,0,"EMOJI_TOKEN_FIRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+683,0,"EMOJI_TOKEN_YES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+684,0,"EMOJI_TOKEN_NO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+685,0,"EMOJI_TOKEN_UP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+686,0,"EMOJI_TOKEN_DOWN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+687,0,"EMOJI_TOKEN_DOGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+688,0,"EMOJI_TOKEN_MAIRUO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+671,0,"QUOTE_MARKER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+567,0,"QUOTE_MARKER_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+689,0,"QUOTE_DISP_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vbe_top___024root__trace_init_top(Vbe_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_init_top\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbe_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vbe_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vbe_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vbe_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vbe_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vbe_top___024root__trace_register(Vbe_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_register\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vbe_top___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vbe_top___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vbe_top___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vbe_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vbe_top___024root__trace_const_0_sub_0(Vbe_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vbe_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_const_0\n"); );
    // Body
    Vbe_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbe_top___024root*>(voidSelf);
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vbe_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<32>/*1023:0*/ Vbe_top__ConstPool__CONST_h62f3a808_0;

VL_ATTR_COLD void Vbe_top___024root__trace_const_0_sub_0(Vbe_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_const_0_sub_0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+521,(7U),32);
    bufp->fullIData(oldp+522,(6U),32);
    bufp->fullIData(oldp+523,(4U),32);
    __Vtemp_1[0U] = 0x63696c41U;
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0U;
    bufp->fullWData(oldp+524,(__Vtemp_1),128);
    bufp->fullIData(oldp+528,(0x00000010U),32);
    bufp->fullIData(oldp+529,(0x0000000fU),32);
    bufp->fullIData(oldp+530,(5U),32);
    bufp->fullSData(oldp+531,(0x00f0U),10);
    bufp->fullSData(oldp+532,(0x01a8U),10);
    bufp->fullWData(oldp+533,(Vbe_top__ConstPool__CONST_h62f3a808_0),1024);
    bufp->fullIData(oldp+565,(0x00000080U),32);
    bufp->fullIData(oldp+566,(0U),32);
    bufp->fullIData(oldp+567,(2U),32);
    bufp->fullIData(oldp+568,(0x00000041U),32);
    bufp->fullIData(oldp+569,(0x00000043U),32);
    bufp->fullIData(oldp+570,(0x00000052U),32);
    bufp->fullIData(oldp+571,(0x00000061U),32);
    bufp->fullIData(oldp+572,(0x00000040U),32);
    bufp->fullIData(oldp+573,(0x0000001dU),32);
    bufp->fullIData(oldp+574,(0x00000023U),32);
    bufp->fullIData(oldp+575,(0x0000000bU),32);
    bufp->fullIData(oldp+576,(0x00000020U),32);
    bufp->fullIData(oldp+577,(0x00000024U),32);
    bufp->fullIData(oldp+578,(0x00000200U),32);
    bufp->fullIData(oldp+579,(0x0000024fU),32);
    bufp->fullIData(oldp+580,(0x00000063U),32);
    bufp->fullIData(oldp+581,(0x00000062U),32);
    bufp->fullCData(oldp+582,(0xf3U),8);
    bufp->fullCData(oldp+583,(0xf4U),8);
    bufp->fullCData(oldp+584,(0xf6U),8);
    bufp->fullCData(oldp+585,(0xf7U),8);
    bufp->fullCData(oldp+586,(0xf8U),8);
    bufp->fullCData(oldp+587,(0xf9U),8);
    bufp->fullCData(oldp+588,(0xfaU),8);
    bufp->fullCData(oldp+589,(0xfbU),8);
    bufp->fullCData(oldp+590,(0xfcU),8);
    bufp->fullCData(oldp+591,(0xfdU),8);
    bufp->fullCData(oldp+592,(0U),2);
    bufp->fullCData(oldp+593,(1U),2);
    bufp->fullCData(oldp+594,(2U),2);
    bufp->fullCData(oldp+595,(0xe0U),8);
    bufp->fullCData(oldp+596,(0xe1U),8);
    bufp->fullCData(oldp+597,(0xe2U),8);
    bufp->fullCData(oldp+598,(0xe3U),8);
    bufp->fullCData(oldp+599,(0xe4U),8);
    bufp->fullCData(oldp+600,(0xe5U),8);
    bufp->fullCData(oldp+601,(0xe6U),8);
    bufp->fullCData(oldp+602,(0xe7U),8);
    bufp->fullCData(oldp+603,(0xe8U),8);
    bufp->fullCData(oldp+604,(0xe9U),8);
    bufp->fullCData(oldp+605,(0xeaU),8);
    bufp->fullCData(oldp+606,(0xebU),8);
    bufp->fullCData(oldp+607,(0xecU),8);
    bufp->fullCData(oldp+608,(0xedU),8);
    bufp->fullCData(oldp+609,(0xeeU),8);
    bufp->fullCData(oldp+610,(0xf2U),8);
    bufp->fullIData(oldp+611,(0x0000000cU),32);
    bufp->fullIData(oldp+612,(0x00000320U),32);
    bufp->fullIData(oldp+613,(0x00000348U),32);
    bufp->fullIData(oldp+614,(0x000003c8U),32);
    bufp->fullIData(oldp+615,(0x00000420U),32);
    bufp->fullIData(oldp+616,(0x00000258U),32);
    bufp->fullIData(oldp+617,(0x00000259U),32);
    bufp->fullIData(oldp+618,(0x0000025dU),32);
    bufp->fullIData(oldp+619,(0x00000274U),32);
    bufp->fullBit(oldp+620,(1U));
    bufp->fullIData(oldp+621,(0x0000001eU),32);
    bufp->fullIData(oldp+622,(0x00000110U),32);
    bufp->fullIData(oldp+623,(0x0000011cU),32);
    bufp->fullCData(oldp+624,(0xffU),8);
    bufp->fullCData(oldp+625,(0U),8);
    bufp->fullCData(oldp+626,(0x10U),8);
    bufp->fullCData(oldp+627,(0x20U),8);
    bufp->fullCData(oldp+628,(0x60U),8);
    bufp->fullCData(oldp+629,(7U),8);
    bufp->fullCData(oldp+630,(0x5eU),8);
    bufp->fullCData(oldp+631,(0x54U),8);
    bufp->fullCData(oldp+632,(2U),8);
    bufp->fullCData(oldp+633,(0x28U),8);
    bufp->fullCData(oldp+634,(0x23U),8);
    bufp->fullIData(oldp+635,(0x000ea600U),32);
    bufp->fullIData(oldp+636,(0x000ea800U),32);
    bufp->fullCData(oldp+637,(8U),8);
    bufp->fullCData(oldp+638,(0x30U),8);
    bufp->fullCData(oldp+639,(0xf0U),8);
    bufp->fullIData(oldp+640,(0x00000070U),32);
    bufp->fullIData(oldp+641,(0x00000018U),32);
    bufp->fullIData(oldp+642,(0x00000034U),32);
    bufp->fullIData(oldp+643,(0x00000140U),32);
    bufp->fullIData(oldp+644,(0x00000050U),32);
    bufp->fullCData(oldp+645,(0x18U),8);
    bufp->fullCData(oldp+646,(0x1cU),8);
    bufp->fullCData(oldp+647,(0x24U),8);
    bufp->fullCData(oldp+648,(0xc8U),8);
    bufp->fullCData(oldp+649,(0xd0U),8);
    bufp->fullCData(oldp+650,(0xd8U),8);
    bufp->fullCData(oldp+651,(0x2bU),8);
    bufp->fullCData(oldp+652,(0x51U),8);
    bufp->fullCData(oldp+653,(0x7aU),8);
    bufp->fullCData(oldp+654,(0xf4U),8);
    bufp->fullCData(oldp+655,(0xf7U),8);
    bufp->fullCData(oldp+656,(0xfbU),8);
    bufp->fullIData(oldp+657,(3U),32);
    bufp->fullIData(oldp+658,(0x00000012U),32);
    bufp->fullIData(oldp+659,(0x000000daU),32);
    bufp->fullCData(oldp+660,(0x80U),8);
    bufp->fullCData(oldp+661,(0x92U),8);
    bufp->fullCData(oldp+662,(0xa4U),8);
    bufp->fullCData(oldp+663,(0xb6U),8);
    bufp->fullCData(oldp+664,(0xc8U),8);
    bufp->fullIData(oldp+665,(8U),32);
    bufp->fullCData(oldp+666,(0x7eU),8);
    bufp->fullSData(oldp+667,(0x1021U),16);
    bufp->fullSData(oldp+668,(0xffffU),16);
    bufp->fullIData(oldp+669,(0x05f5e100U),32);
    bufp->fullIData(oldp+670,(0x0001c200U),32);
    bufp->fullCData(oldp+671,(1U),8);
    bufp->fullCData(oldp+672,(5U),8);
    bufp->fullIData(oldp+673,(0x00000104U),32);
    bufp->fullCData(oldp+674,(0U),4);
    bufp->fullCData(oldp+675,(1U),4);
    bufp->fullCData(oldp+676,(2U),4);
    bufp->fullCData(oldp+677,(3U),4);
    bufp->fullCData(oldp+678,(4U),4);
    bufp->fullCData(oldp+679,(5U),4);
    bufp->fullCData(oldp+680,(6U),4);
    bufp->fullCData(oldp+681,(7U),4);
    bufp->fullCData(oldp+682,(8U),4);
    bufp->fullCData(oldp+683,(9U),4);
    bufp->fullCData(oldp+684,(0x0aU),4);
    bufp->fullCData(oldp+685,(0x0bU),4);
    bufp->fullCData(oldp+686,(0x0cU),4);
    bufp->fullCData(oldp+687,(0x0dU),4);
    bufp->fullCData(oldp+688,(0x0eU),4);
    bufp->fullIData(oldp+689,(0x0000003cU),32);
}

VL_ATTR_COLD void Vbe_top___024root__trace_full_0_sub_0(Vbe_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vbe_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_full_0\n"); );
    // Body
    Vbe_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbe_top___024root*>(voidSelf);
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vbe_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vbe_top___024root__trace_full_0_sub_0(Vbe_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_full_0_sub_0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<32>/*1023:0*/ __Vtemp_1;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.be_top__DOT__state_d),6);
    bufp->fullCData(oldp+1,(((IData)(vlSelfRef.be_top__DOT__store_lookup_idx) 
                             & (- (IData)((IData)(vlSelfRef.be_top__DOT__use_quote_lkup))))),6);
    bufp->fullBit(oldp+2,(vlSelfRef.be_top__DOT__quoted_store_valid));
    bufp->fullSData(oldp+3,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_len),16);
    __Vtemp_1[0U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][0U];
    __Vtemp_1[1U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][1U];
    __Vtemp_1[2U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][2U];
    __Vtemp_1[3U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][3U];
    __Vtemp_1[4U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][4U];
    __Vtemp_1[5U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][5U];
    __Vtemp_1[6U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][6U];
    __Vtemp_1[7U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][7U];
    __Vtemp_1[8U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][8U];
    __Vtemp_1[9U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][9U];
    __Vtemp_1[10U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][10U];
    __Vtemp_1[11U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][11U];
    __Vtemp_1[12U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][12U];
    __Vtemp_1[13U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][13U];
    __Vtemp_1[14U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][14U];
    __Vtemp_1[15U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][15U];
    __Vtemp_1[16U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][16U];
    __Vtemp_1[17U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][17U];
    __Vtemp_1[18U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][18U];
    __Vtemp_1[19U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][19U];
    __Vtemp_1[20U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][20U];
    __Vtemp_1[21U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][21U];
    __Vtemp_1[22U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][22U];
    __Vtemp_1[23U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][23U];
    __Vtemp_1[24U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][24U];
    __Vtemp_1[25U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][25U];
    __Vtemp_1[26U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][26U];
    __Vtemp_1[27U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][27U];
    __Vtemp_1[28U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][28U];
    __Vtemp_1[29U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][29U];
    __Vtemp_1[30U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][30U];
    __Vtemp_1[31U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][31U];
    bufp->fullWData(oldp+4,(__Vtemp_1),1024);
    bufp->fullCData(oldp+36,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx),6);
    bufp->fullBit(oldp+37,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_valid));
    bufp->fullCData(oldp+38,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_msg_id),8);
    bufp->fullCData(oldp+39,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_side),2);
    bufp->fullCData(oldp+40,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_status),2);
    bufp->fullBit(oldp+41,(vlSelfRef.be_top__DOT__key_char_insert_allowed));
    bufp->fullCData(oldp+42,(vlSelfRef.be_top__DOT__click_hist_slot),6);
    bufp->fullCData(oldp+43,(vlSelfRef.be_top__DOT__click_hist_owner_side),2);
    bufp->fullCData(oldp+44,(vlSelfRef.be_top__DOT__click_hist_owner_width),7);
    bufp->fullCData(oldp+45,(((1U == (IData)(vlSelfRef.be_top__DOT__click_hist_owner_side))
                               ? 2U : (0x0000007fU 
                                       & (((IData)(0x61U) 
                                           - (IData)(vlSelfRef.be_top__DOT__click_hist_owner_width)) 
                                          - (IData)(1U))))),7);
    bufp->fullCData(oldp+46,(((1U == (IData)(vlSelfRef.be_top__DOT__click_hist_owner_side))
                               ? (0x0000007fU & ((IData)(3U) 
                                                 + (IData)(vlSelfRef.be_top__DOT__click_hist_owner_width)))
                               : 0x00000061U)),7);
    bufp->fullBit(oldp+47,(((IData)(vlSelfRef.be_top__DOT__store_lookup_hit) 
                            & (IData)(vlSelfRef.be_top__DOT__use_quote_lkup))));
    bufp->fullBit(oldp+48,(vlSelfRef.be_top__DOT__peer_name_changed));
    bufp->fullBit(oldp+49,(vlSelfRef.be_top__DOT__accept_io));
    bufp->fullBit(oldp+50,(vlSelfRef.be_top__DOT__accept_rx));
    bufp->fullBit(oldp+51,(vlSelfRef.be_top__DOT__accept_status));
    bufp->fullBit(oldp+52,(vlSelfRef.be_top__DOT__accept_mouse_click));
    bufp->fullBit(oldp+53,(vlSelfRef.be_top__DOT__accept_username_frame));
    bufp->fullBit(oldp+54,(vlSelfRef.be_top__DOT__u_store__DOT__clear_en));
    bufp->fullBit(oldp+55,(vlSelfRef.be_top__DOT__store_wr_en));
    bufp->fullCData(oldp+56,(vlSelfRef.be_top__DOT__store_wr_msg_id),8);
    bufp->fullCData(oldp+57,(vlSelfRef.be_top__DOT__store_wr_side),2);
    bufp->fullCData(oldp+58,(vlSelfRef.be_top__DOT__store_wr_status),2);
    bufp->fullSData(oldp+59,(vlSelfRef.be_top__DOT__store_wr_len),16);
    bufp->fullWData(oldp+60,(vlSelfRef.be_top__DOT__store_wr_payload),1024);
    bufp->fullBit(oldp+92,(vlSelfRef.be_top__DOT__store_lookup_hit));
    bufp->fullCData(oldp+93,(vlSelfRef.be_top__DOT__store_lookup_idx),6);
    bufp->fullCData(oldp+94,(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side),2);
    bufp->fullCData(oldp+95,(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id),8);
    bufp->fullCData(oldp+96,(vlSelfRef.be_top__DOT__u_store__DOT__upd_idx),6);
    bufp->fullBit(oldp+97,(vlSelfRef.be_top__DOT__use_quote_lkup));
    bufp->fullBit(oldp+98,(vlSelfRef.be_top__DOT__rx_quote_entry));
    bufp->fullCData(oldp+99,(((IData)(vlSelfRef.be_top__DOT__quoted_side_q) 
                              & (- (IData)((1U & (~ (IData)(vlSelfRef.be_top__DOT__rx_quote_entry))))))),2);
    bufp->fullBit(oldp+100,(vlSelfRef.be_top__DOT__popup_active_q));
    bufp->fullCData(oldp+101,(vlSelfRef.be_top__DOT__popup_type_q),2);
    bufp->fullSData(oldp+102,(vlSelfRef.be_top__DOT__popup_x_q),10);
    bufp->fullSData(oldp+103,(vlSelfRef.be_top__DOT__popup_y_q),10);
    bufp->fullBit(oldp+104,(vlSelfRef.be_top__DOT__emoji_suggest_active_q));
    bufp->fullCData(oldp+105,(vlSelfRef.be_top__DOT__emoji_suggest_count_q),4);
    bufp->fullQData(oldp+106,(vlSelfRef.be_top__DOT__emoji_suggest_ids_q),60);
    bufp->fullSData(oldp+108,(vlSelfRef.be_top__DOT__emoji_suggest_anchor_q),16);
    bufp->fullSData(oldp+109,(vlSelfRef.be_top__DOT__peer_name_len_q),16);
    bufp->fullWData(oldp+110,(vlSelfRef.be_top__DOT__peer_name_q),128);
    bufp->fullBit(oldp+114,(vlSelfRef.be_top__DOT__has_quote_q));
    bufp->fullSData(oldp+115,(vlSelfRef.be_top__DOT__len_q),16);
    bufp->fullSData(oldp+116,(vlSelfRef.be_top__DOT__cursor_pos_q),16);
    bufp->fullBit(oldp+117,(vlSelfRef.be_top__DOT__enter_pulse_q));
    bufp->fullCData(oldp+118,(vlSelfRef.be_top__DOT__state_q),6);
    bufp->fullCData(oldp+119,(vlSelfRef.be_top__DOT__input_newline_count_q),5);
    bufp->fullCData(oldp+120,(vlSelfRef.be_top__DOT__last_event_ascii_q),8);
    bufp->fullBit(oldp+121,(vlSelfRef.be_top__DOT__delete_was_newline_q));
    bufp->fullSData(oldp+122,(vlSelfRef.be_top__DOT__shift_idx_q),16);
    bufp->fullCData(oldp+123,((0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q))),7);
    bufp->fullSData(oldp+124,(vlSelfRef.be_top__DOT__enc_src_q),16);
    bufp->fullSData(oldp+125,(vlSelfRef.be_top__DOT__enc_dst_q),16);
    bufp->fullCData(oldp+126,(vlSelfRef.be_top__DOT__wr_ptr_q),6);
    bufp->fullCData(oldp+127,(vlSelfRef.be_top__DOT__next_msg_id_q),8);
    bufp->fullCData(oldp+128,(vlSelfRef.be_top__DOT__pending_msg_id_q),8);
    bufp->fullCData(oldp+129,(vlSelfRef.be_top__DOT__pending_store_idx_q),6);
    bufp->fullSData(oldp+130,(vlSelfRef.be_top__DOT__pending_len_q),16);
    bufp->fullWData(oldp+131,(vlSelfRef.be_top__DOT__pending_payload_q),1024);
    bufp->fullCData(oldp+163,(vlSelfRef.be_top__DOT__rx_seq_q),8);
    bufp->fullCData(oldp+164,(vlSelfRef.be_top__DOT__rx_store_idx_q),6);
    bufp->fullSData(oldp+165,(vlSelfRef.be_top__DOT__rx_len_q),16);
    bufp->fullWData(oldp+166,(vlSelfRef.be_top__DOT__rx_payload_q),1024);
    bufp->fullCData(oldp+198,(vlSelfRef.be_top__DOT__status_msg_id_q),8);
    bufp->fullCData(oldp+199,(vlSelfRef.be_top__DOT__status_status_q),2);
    bufp->fullBit(oldp+200,(vlSelfRef.be_top__DOT__click_pending_q));
    bufp->fullBit(oldp+201,(vlSelfRef.be_top__DOT__click_is_right_q));
    bufp->fullSData(oldp+202,(vlSelfRef.be_top__DOT__click_x_q),10);
    bufp->fullSData(oldp+203,(vlSelfRef.be_top__DOT__click_y_q),10);
    bufp->fullCData(oldp+204,(vlSelfRef.be_top__DOT__click_raw_col_q),7);
    bufp->fullCData(oldp+205,(vlSelfRef.be_top__DOT__click_screen_row_q),6);
    bufp->fullCData(oldp+206,(vlSelfRef.be_top__DOT__click_target_row_q),4);
    bufp->fullCData(oldp+207,(vlSelfRef.be_top__DOT__click_target_col_q),7);
    bufp->fullCData(oldp+208,(vlSelfRef.be_top__DOT__click_vis_row_q),4);
    bufp->fullCData(oldp+209,(vlSelfRef.be_top__DOT__click_vis_col_q),7);
    bufp->fullBit(oldp+210,(vlSelfRef.be_top__DOT__click_walk_done_q));
    bufp->fullCData(oldp+211,(vlSelfRef.be_top__DOT__menu_store_idx_q),6);
    bufp->fullCData(oldp+212,(vlSelfRef.be_top__DOT__quoted_msg_id_q),8);
    bufp->fullCData(oldp+213,(vlSelfRef.be_top__DOT__quoted_side_q),2);
    bufp->fullWData(oldp+214,(vlSelfRef.be_top__DOT__disp_payload_q),1024);
    bufp->fullSData(oldp+246,(vlSelfRef.be_top__DOT__disp_len_q),16);
    bufp->fullSData(oldp+247,(vlSelfRef.be_top__DOT__disp_build_idx_q),16);
    bufp->fullBit(oldp+248,(vlSelfRef.be_top__DOT__disp_for_remote_q));
    bufp->fullCData(oldp+249,(vlSelfRef.be_top__DOT__recall_msg_id_q),8);
    bufp->fullCData(oldp+250,(vlSelfRef.be_top__DOT__recall_store_idx_q),6);
    bufp->fullCData(oldp+251,(vlSelfRef.be_top__DOT__recall_side_q),2);
    bufp->fullBit(oldp+252,(vlSelfRef.be_top__DOT__recall_send_q));
    bufp->fullBit(oldp+253,(vlSelfRef.be_top__DOT__emoji_suggest_tracking_q));
    bufp->fullCData(oldp+254,(vlSelfRef.be_top__DOT__emoji_complete_token_q),4);
    bufp->fullSData(oldp+255,(vlSelfRef.be_top__DOT__emoji_complete_char_idx_q),16);
    bufp->fullSData(oldp+256,(vlSelfRef.be_top__DOT__emoji_complete_token_len_q),16);
    bufp->fullSData(oldp+257,(vlSelfRef.be_top__DOT__click_popup_dx),10);
    bufp->fullSData(oldp+258,(vlSelfRef.be_top__DOT__click_popup_dy),10);
    bufp->fullCData(oldp+259,((0x0000000fU & ((IData)(vlSelfRef.be_top__DOT__click_popup_dx) 
                                              >> 6U))),4);
    bufp->fullBit(oldp+260,(vlSelfRef.be_top__DOT__click_in_sticker_picker));
    bufp->fullCData(oldp+261,(((0x00000200U & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                ? 0x80U : ((0x00000100U 
                                            & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                            ? ((0x00000080U 
                                                & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                ? 0x80U
                                                : (
                                                   (0x00000040U 
                                                    & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                    ? 0x80U
                                                    : 0xc8U))
                                            : ((0x00000080U 
                                                & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                ? (
                                                   (0x00000040U 
                                                    & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                    ? 0xb6U
                                                    : 0xa4U)
                                                : (
                                                   (0x00000040U 
                                                    & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                    ? 0x92U
                                                    : 0x80U))))),8);
    bufp->fullBit(oldp+262,(vlSelfRef.be_top__DOT__click_in_msg_menu));
    bufp->fullBit(oldp+263,(vlSelfRef.be_top__DOT__click_msg_menu_quote));
    bufp->fullBit(oldp+264,(vlSelfRef.be_top__DOT__click_msg_menu_recall));
    bufp->fullSData(oldp+265,((0x000003ffU & ((IData)(vlSelfRef.be_top__DOT__click_x_q) 
                                              - (IData)(0x0010U)))),10);
    bufp->fullSData(oldp+266,((0x000003ffU & ((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                              - (IData)(0x0104U)))),10);
    bufp->fullCData(oldp+267,((0x0000000fU & ((((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                - (IData)(0x0104U)) 
                                               - (IData)(2U)) 
                                              >> 4U))),4);
    bufp->fullBit(oldp+268,(vlSelfRef.be_top__DOT__click_in_emoji_suggest));
    bufp->fullCData(oldp+269,(vlSelfRef.be_top__DOT__click_emoji_token_id),4);
    bufp->fullSData(oldp+270,(vlSelfRef.be_top__DOT__click_emoji_token_len),16);
    bufp->fullSData(oldp+271,(vlSelfRef.be_top__DOT__click_emoji_prefix_len),16);
    bufp->fullSData(oldp+272,((0x0000ffffU & (((IData)(vlSelfRef.be_top__DOT__click_emoji_token_len) 
                                               - (IData)(vlSelfRef.be_top__DOT__click_emoji_prefix_len)) 
                                              & (- (IData)(
                                                           ((IData)(vlSelfRef.be_top__DOT__click_emoji_token_len) 
                                                            > (IData)(vlSelfRef.be_top__DOT__click_emoji_prefix_len))))))),16);
    bufp->fullBit(oldp+273,(vlSelfRef.be_top__DOT__click_emoji_fits));
    bufp->fullBit(oldp+274,(((2U <= (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)) 
                             & (0x1fU > (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)))));
    bufp->fullBit(oldp+275,(((7U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                             | ((8U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                | ((6U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                   | ((IData)(vlSelfRef.be_top__DOT__click_walk_done_q) 
                                      & (0x19U == (IData)(vlSelfRef.be_top__DOT__state_q))))))));
    bufp->fullBit(oldp+276,(vlSelfRef.be_top__DOT__suggest_tracking_base));
    bufp->fullSData(oldp+277,(vlSelfRef.be_top__DOT__suggest_anchor_base),16);
    bufp->fullSData(oldp+278,(vlSelfRef.be_top__DOT__suggest_cursor_base),16);
    bufp->fullSData(oldp+279,(vlSelfRef.be_top__DOT__suggest_prefix_len),16);
    bufp->fullBit(oldp+280,(vlSelfRef.be_top__DOT__suggest_prefix_valid));
    bufp->fullCData(oldp+281,(vlSelfRef.be_top__DOT__suggest_prefix_byte[0]),8);
    bufp->fullCData(oldp+282,(vlSelfRef.be_top__DOT__suggest_prefix_byte[1]),8);
    bufp->fullCData(oldp+283,(vlSelfRef.be_top__DOT__suggest_prefix_byte[2]),8);
    bufp->fullCData(oldp+284,(vlSelfRef.be_top__DOT__suggest_prefix_byte[3]),8);
    bufp->fullCData(oldp+285,(vlSelfRef.be_top__DOT__suggest_prefix_byte[4]),8);
    bufp->fullCData(oldp+286,(vlSelfRef.be_top__DOT__suggest_prefix_byte[5]),8);
    bufp->fullCData(oldp+287,(vlSelfRef.be_top__DOT__suggest_prefix_byte[6]),8);
    bufp->fullCData(oldp+288,(vlSelfRef.be_top__DOT__suggest_count_calc),4);
    bufp->fullQData(oldp+289,(vlSelfRef.be_top__DOT__suggest_ids_calc),60);
    bufp->fullBit(oldp+291,(vlSelfRef.be_top__DOT__suggest_active_calc));
    bufp->fullCData(oldp+292,(vlSelfRef.be_top__DOT__enc_emit_byte),8);
    bufp->fullCData(oldp+293,(vlSelfRef.be_top__DOT__enc_src_delta),4);
    bufp->fullBit(oldp+294,(vlSelfRef.be_top__DOT__enc_done));
    bufp->fullBit(oldp+295,((2U == (IData)(vlSelfRef.be_top__DOT__state_q))));
    bufp->fullBit(oldp+296,((0x11U == (IData)(vlSelfRef.be_top__DOT__state_q))));
    bufp->fullBit(oldp+297,(((IData)(vlSelfRef.be_top__DOT__has_quote_q) 
                             & (IData)(vlSelfRef.be_top__DOT__enc_done))));
    bufp->fullIData(oldp+298,(vlSelfRef.be_top__DOT__unnamedblk5__DOT__src),32);
    bufp->fullBit(oldp+299,(vlSelfRef.clk));
    bufp->fullBit(oldp+300,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+301,(vlSelfRef.io_key_valid));
    bufp->fullBit(oldp+302,(vlSelfRef.io_key_ready));
    bufp->fullCData(oldp+303,(vlSelfRef.io_key_type),3);
    bufp->fullCData(oldp+304,(vlSelfRef.io_key_ascii),8);
    bufp->fullBit(oldp+305,(vlSelfRef.io_mouse_click_valid));
    bufp->fullBit(oldp+306,(vlSelfRef.io_mouse_right_click_valid));
    bufp->fullBit(oldp+307,(vlSelfRef.io_mouse_click_ready));
    bufp->fullSData(oldp+308,(vlSelfRef.io_mouse_click_x),10);
    bufp->fullSData(oldp+309,(vlSelfRef.io_mouse_click_y),10);
    bufp->fullCData(oldp+310,(vlSelfRef.fe_input_scroll_offset),4);
    bufp->fullBit(oldp+311,(vlSelfRef.fe_input_at_limit));
    bufp->fullCData(oldp+312,(vlSelfRef.fe_hist_wr_row),6);
    bufp->fullCData(oldp+313,(vlSelfRef.fe_hist_scroll_offset),6);
    bufp->fullQData(oldp+314,(vlSelfRef.fe_hist_owner_valid),64);
    bufp->fullWData(oldp+316,(vlSelfRef.fe_hist_owner_store_idx),384);
    bufp->fullWData(oldp+328,(vlSelfRef.fe_hist_owner_side),128);
    bufp->fullWData(oldp+332,(vlSelfRef.fe_hist_owner_width),448);
    bufp->fullBit(oldp+346,(vlSelfRef.cm_rx_valid));
    bufp->fullBit(oldp+347,(vlSelfRef.cm_rx_ready));
    bufp->fullCData(oldp+348,(vlSelfRef.cm_rx_frame_type),3);
    bufp->fullCData(oldp+349,(vlSelfRef.cm_rx_seq),8);
    bufp->fullSData(oldp+350,(vlSelfRef.cm_rx_len),16);
    bufp->fullWData(oldp+351,(vlSelfRef.cm_rx_payload),1024);
    bufp->fullBit(oldp+383,(vlSelfRef.cm_status_valid));
    bufp->fullBit(oldp+384,(vlSelfRef.cm_status_ready));
    bufp->fullCData(oldp+385,(vlSelfRef.cm_status_msg_id),8);
    bufp->fullCData(oldp+386,(vlSelfRef.cm_status_code),2);
    bufp->fullBit(oldp+387,(vlSelfRef.be_tx_valid));
    bufp->fullBit(oldp+388,(vlSelfRef.be_tx_ready));
    bufp->fullCData(oldp+389,(vlSelfRef.be_tx_frame_type),3);
    bufp->fullCData(oldp+390,(vlSelfRef.be_tx_msg_id),8);
    bufp->fullSData(oldp+391,(vlSelfRef.be_tx_len),16);
    bufp->fullWData(oldp+392,(vlSelfRef.be_tx_payload),1024);
    bufp->fullBit(oldp+424,(vlSelfRef.be_render_valid));
    bufp->fullBit(oldp+425,(vlSelfRef.be_render_ready));
    bufp->fullCData(oldp+426,(vlSelfRef.be_render_cmd),4);
    bufp->fullCData(oldp+427,(vlSelfRef.be_render_msg_id),8);
    bufp->fullCData(oldp+428,(vlSelfRef.be_render_store_idx),6);
    bufp->fullCData(oldp+429,(vlSelfRef.be_render_side),2);
    bufp->fullCData(oldp+430,(vlSelfRef.be_render_status),2);
    bufp->fullSData(oldp+431,(vlSelfRef.be_render_len),16);
    bufp->fullWData(oldp+432,(vlSelfRef.be_render_payload),1024);
    bufp->fullSData(oldp+464,(vlSelfRef.be_render_cursor_pos),16);
    bufp->fullCData(oldp+465,(vlSelfRef.be_render_ascii),8);
    bufp->fullCData(oldp+466,(vlSelfRef.be_render_conn_state),2);
    bufp->fullCData(oldp+467,(vlSelfRef.line_rd_idx),7);
    bufp->fullCData(oldp+468,(vlSelfRef.line_rd_data),8);
    bufp->fullCData(oldp+469,(vlSelfRef.store_rd_idx),6);
    bufp->fullBit(oldp+470,(vlSelfRef.store_rd_valid));
    bufp->fullCData(oldp+471,(vlSelfRef.store_rd_msg_id),8);
    bufp->fullCData(oldp+472,(vlSelfRef.store_rd_side),2);
    bufp->fullCData(oldp+473,(vlSelfRef.store_rd_status),2);
    bufp->fullSData(oldp+474,(vlSelfRef.store_rd_len),16);
    bufp->fullWData(oldp+475,(vlSelfRef.store_rd_payload),1024);
    bufp->fullBit(oldp+507,((1U & (IData)((vlSelfRef.fe_hist_owner_valid 
                                           >> (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))));
    bufp->fullCData(oldp+508,((0x0000003fU & ((((0U 
                                                 == 
                                                 (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))
                                                 ? 0U
                                                 : 
                                                (vlSelfRef.fe_hist_owner_store_idx
                                                 [(
                                                   ((IData)(5U) 
                                                    + 
                                                    (0x000001ffU 
                                                     & ((IData)(6U) 
                                                        * (IData)(vlSelfRef.be_top__DOT__click_hist_slot)))) 
                                                   >> 5U)] 
                                                 << 
                                                 ((IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & ((IData)(6U) 
                                                      * (IData)(vlSelfRef.be_top__DOT__click_hist_slot)))))) 
                                               | (vlSelfRef.fe_hist_owner_store_idx
                                                  [
                                                  (0x0000000fU 
                                                   & (((IData)(6U) 
                                                       * (IData)(vlSelfRef.be_top__DOT__click_hist_slot)) 
                                                      >> 5U))] 
                                                  >> 
                                                  (0x0000001fU 
                                                   & ((IData)(6U) 
                                                      * (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))) 
                                              & (- (IData)(
                                                           (0x017fU 
                                                            >= 
                                                            (0x000001ffU 
                                                             & ((IData)(6U) 
                                                                * (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))))))),6);
    bufp->fullBit(oldp+509,((((2U <= (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)) 
                              & (0x1fU > (IData)(vlSelfRef.be_top__DOT__click_screen_row_q))) 
                             & ((IData)((vlSelfRef.fe_hist_owner_valid 
                                         >> (IData)(vlSelfRef.be_top__DOT__click_hist_slot))) 
                                & (((IData)(vlSelfRef.be_top__DOT__click_raw_col_q) 
                                    >= ((1U == (IData)(vlSelfRef.be_top__DOT__click_hist_owner_side))
                                         ? 2U : (0x0000007fU 
                                                 & (((IData)(0x61U) 
                                                     - (IData)(vlSelfRef.be_top__DOT__click_hist_owner_width)) 
                                                    - (IData)(1U))))) 
                                   & ((IData)(vlSelfRef.be_top__DOT__click_raw_col_q) 
                                      <= ((1U == (IData)(vlSelfRef.be_top__DOT__click_hist_owner_side))
                                           ? (0x0000007fU 
                                              & ((IData)(3U) 
                                                 + (IData)(vlSelfRef.be_top__DOT__click_hist_owner_width)))
                                           : 0x00000061U)))))));
    bufp->fullSData(oldp+510,(vlSelfRef.be_top__DOT__rx_len_clamped),16);
    bufp->fullSData(oldp+511,(vlSelfRef.be_top__DOT__rx_name_len_clamped),16);
    bufp->fullBit(oldp+512,((0U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->fullBit(oldp+513,((3U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->fullBit(oldp+514,((4U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->fullBit(oldp+515,((5U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->fullBit(oldp+516,((6U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->fullBit(oldp+517,((7U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->fullBit(oldp+518,(((0x22U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                             | ((IData)(vlSelfRef.cm_status_ready) 
                                & ((IData)(vlSelfRef.be_top__DOT__store_lookup_hit) 
                                   & (IData)(vlSelfRef.be_top__DOT__accept_status))))));
    bufp->fullCData(oldp+519,((3U & (((0U == (IData)(vlSelfRef.cm_status_code))
                                       ? 1U : 2U) | 
                                     (- (IData)((0x22U 
                                                 == (IData)(vlSelfRef.be_top__DOT__state_q))))))),2);
    bufp->fullCData(oldp+520,((0x000000ffU & ((IData)(vlSelfRef.be_top__DOT__rx_quote_entry)
                                               ? ((vlSelfRef.cm_rx_payload[0U] 
                                                   << 0x00000018U) 
                                                  | (vlSelfRef.cm_rx_payload[0U] 
                                                     >> 8U))
                                               : (IData)(vlSelfRef.be_top__DOT__quoted_msg_id_q)))),8);
}
