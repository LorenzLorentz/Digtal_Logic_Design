// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vbe_top__Syms.h"


void Vbe_top___024root__trace_chg_0_sub_0(Vbe_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vbe_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_chg_0\n"); );
    // Body
    Vbe_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbe_top___024root*>(voidSelf);
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vbe_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vbe_top___024root__trace_chg_0_sub_0(Vbe_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_chg_0_sub_0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<32>/*1023:0*/ __Vtemp_1;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgCData(oldp+0,(vlSelfRef.be_top__DOT__state_d),6);
        bufp->chgCData(oldp+1,(((IData)(vlSelfRef.be_top__DOT__store_lookup_idx) 
                                & (- (IData)((IData)(vlSelfRef.be_top__DOT__use_quote_lkup))))),6);
        bufp->chgBit(oldp+2,(vlSelfRef.be_top__DOT__quoted_store_valid));
        bufp->chgSData(oldp+3,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_len),16);
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
        bufp->chgWData(oldp+4,(__Vtemp_1),1024);
        bufp->chgCData(oldp+36,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx),6);
        bufp->chgBit(oldp+37,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_valid));
        bufp->chgCData(oldp+38,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_msg_id),8);
        bufp->chgCData(oldp+39,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_side),2);
        bufp->chgCData(oldp+40,(vlSelfRef.be_top__DOT__u_store__DOT__rd2_status),2);
        bufp->chgBit(oldp+41,(vlSelfRef.be_top__DOT__key_char_insert_allowed));
        bufp->chgCData(oldp+42,(vlSelfRef.be_top__DOT__click_hist_slot),6);
        bufp->chgCData(oldp+43,(vlSelfRef.be_top__DOT__click_hist_owner_side),2);
        bufp->chgCData(oldp+44,(vlSelfRef.be_top__DOT__click_hist_owner_width),7);
        bufp->chgCData(oldp+45,(((1U == (IData)(vlSelfRef.be_top__DOT__click_hist_owner_side))
                                  ? 2U : (0x0000007fU 
                                          & (((IData)(0x61U) 
                                              - (IData)(vlSelfRef.be_top__DOT__click_hist_owner_width)) 
                                             - (IData)(1U))))),7);
        bufp->chgCData(oldp+46,(((1U == (IData)(vlSelfRef.be_top__DOT__click_hist_owner_side))
                                  ? (0x0000007fU & 
                                     ((IData)(3U) + (IData)(vlSelfRef.be_top__DOT__click_hist_owner_width)))
                                  : 0x00000061U)),7);
        bufp->chgBit(oldp+47,(((IData)(vlSelfRef.be_top__DOT__store_lookup_hit) 
                               & (IData)(vlSelfRef.be_top__DOT__use_quote_lkup))));
        bufp->chgBit(oldp+48,(vlSelfRef.be_top__DOT__peer_name_changed));
        bufp->chgBit(oldp+49,(vlSelfRef.be_top__DOT__accept_io));
        bufp->chgBit(oldp+50,(vlSelfRef.be_top__DOT__accept_rx));
        bufp->chgBit(oldp+51,(vlSelfRef.be_top__DOT__accept_status));
        bufp->chgBit(oldp+52,(vlSelfRef.be_top__DOT__accept_mouse_click));
        bufp->chgBit(oldp+53,(vlSelfRef.be_top__DOT__accept_username_frame));
        bufp->chgBit(oldp+54,(vlSelfRef.be_top__DOT__u_store__DOT__clear_en));
        bufp->chgBit(oldp+55,(vlSelfRef.be_top__DOT__store_wr_en));
        bufp->chgCData(oldp+56,(vlSelfRef.be_top__DOT__store_wr_msg_id),8);
        bufp->chgCData(oldp+57,(vlSelfRef.be_top__DOT__store_wr_side),2);
        bufp->chgCData(oldp+58,(vlSelfRef.be_top__DOT__store_wr_status),2);
        bufp->chgSData(oldp+59,(vlSelfRef.be_top__DOT__store_wr_len),16);
        bufp->chgWData(oldp+60,(vlSelfRef.be_top__DOT__store_wr_payload),1024);
        bufp->chgBit(oldp+92,(vlSelfRef.be_top__DOT__store_lookup_hit));
        bufp->chgCData(oldp+93,(vlSelfRef.be_top__DOT__store_lookup_idx),6);
        bufp->chgCData(oldp+94,(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side),2);
        bufp->chgCData(oldp+95,(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id),8);
        bufp->chgCData(oldp+96,(vlSelfRef.be_top__DOT__u_store__DOT__upd_idx),6);
        bufp->chgBit(oldp+97,(vlSelfRef.be_top__DOT__use_quote_lkup));
        bufp->chgBit(oldp+98,(vlSelfRef.be_top__DOT__rx_quote_entry));
        bufp->chgCData(oldp+99,(((IData)(vlSelfRef.be_top__DOT__quoted_side_q) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.be_top__DOT__rx_quote_entry))))))),2);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+100,(vlSelfRef.be_top__DOT__popup_active_q));
        bufp->chgCData(oldp+101,(vlSelfRef.be_top__DOT__popup_type_q),2);
        bufp->chgSData(oldp+102,(vlSelfRef.be_top__DOT__popup_x_q),10);
        bufp->chgSData(oldp+103,(vlSelfRef.be_top__DOT__popup_y_q),10);
        bufp->chgBit(oldp+104,(vlSelfRef.be_top__DOT__emoji_suggest_active_q));
        bufp->chgCData(oldp+105,(vlSelfRef.be_top__DOT__emoji_suggest_count_q),4);
        bufp->chgQData(oldp+106,(vlSelfRef.be_top__DOT__emoji_suggest_ids_q),60);
        bufp->chgSData(oldp+108,(vlSelfRef.be_top__DOT__emoji_suggest_anchor_q),16);
        bufp->chgSData(oldp+109,(vlSelfRef.be_top__DOT__peer_name_len_q),16);
        bufp->chgWData(oldp+110,(vlSelfRef.be_top__DOT__peer_name_q),128);
        bufp->chgBit(oldp+114,(vlSelfRef.be_top__DOT__has_quote_q));
        bufp->chgSData(oldp+115,(vlSelfRef.be_top__DOT__len_q),16);
        bufp->chgSData(oldp+116,(vlSelfRef.be_top__DOT__cursor_pos_q),16);
        bufp->chgBit(oldp+117,(vlSelfRef.be_top__DOT__enter_pulse_q));
        bufp->chgCData(oldp+118,(vlSelfRef.be_top__DOT__state_q),6);
        bufp->chgCData(oldp+119,(vlSelfRef.be_top__DOT__input_newline_count_q),5);
        bufp->chgCData(oldp+120,(vlSelfRef.be_top__DOT__last_event_ascii_q),8);
        bufp->chgBit(oldp+121,(vlSelfRef.be_top__DOT__delete_was_newline_q));
        bufp->chgSData(oldp+122,(vlSelfRef.be_top__DOT__shift_idx_q),16);
        bufp->chgCData(oldp+123,((0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q))),7);
        bufp->chgSData(oldp+124,(vlSelfRef.be_top__DOT__enc_src_q),16);
        bufp->chgSData(oldp+125,(vlSelfRef.be_top__DOT__enc_dst_q),16);
        bufp->chgCData(oldp+126,(vlSelfRef.be_top__DOT__wr_ptr_q),6);
        bufp->chgCData(oldp+127,(vlSelfRef.be_top__DOT__next_msg_id_q),8);
        bufp->chgCData(oldp+128,(vlSelfRef.be_top__DOT__pending_msg_id_q),8);
        bufp->chgCData(oldp+129,(vlSelfRef.be_top__DOT__pending_store_idx_q),6);
        bufp->chgSData(oldp+130,(vlSelfRef.be_top__DOT__pending_len_q),16);
        bufp->chgWData(oldp+131,(vlSelfRef.be_top__DOT__pending_payload_q),1024);
        bufp->chgCData(oldp+163,(vlSelfRef.be_top__DOT__rx_seq_q),8);
        bufp->chgCData(oldp+164,(vlSelfRef.be_top__DOT__rx_store_idx_q),6);
        bufp->chgSData(oldp+165,(vlSelfRef.be_top__DOT__rx_len_q),16);
        bufp->chgWData(oldp+166,(vlSelfRef.be_top__DOT__rx_payload_q),1024);
        bufp->chgCData(oldp+198,(vlSelfRef.be_top__DOT__status_msg_id_q),8);
        bufp->chgCData(oldp+199,(vlSelfRef.be_top__DOT__status_status_q),2);
        bufp->chgBit(oldp+200,(vlSelfRef.be_top__DOT__click_pending_q));
        bufp->chgBit(oldp+201,(vlSelfRef.be_top__DOT__click_is_right_q));
        bufp->chgSData(oldp+202,(vlSelfRef.be_top__DOT__click_x_q),10);
        bufp->chgSData(oldp+203,(vlSelfRef.be_top__DOT__click_y_q),10);
        bufp->chgCData(oldp+204,(vlSelfRef.be_top__DOT__click_raw_col_q),7);
        bufp->chgCData(oldp+205,(vlSelfRef.be_top__DOT__click_screen_row_q),6);
        bufp->chgCData(oldp+206,(vlSelfRef.be_top__DOT__click_target_row_q),4);
        bufp->chgCData(oldp+207,(vlSelfRef.be_top__DOT__click_target_col_q),7);
        bufp->chgCData(oldp+208,(vlSelfRef.be_top__DOT__click_vis_row_q),4);
        bufp->chgCData(oldp+209,(vlSelfRef.be_top__DOT__click_vis_col_q),7);
        bufp->chgBit(oldp+210,(vlSelfRef.be_top__DOT__click_walk_done_q));
        bufp->chgCData(oldp+211,(vlSelfRef.be_top__DOT__menu_store_idx_q),6);
        bufp->chgCData(oldp+212,(vlSelfRef.be_top__DOT__quoted_msg_id_q),8);
        bufp->chgCData(oldp+213,(vlSelfRef.be_top__DOT__quoted_side_q),2);
        bufp->chgWData(oldp+214,(vlSelfRef.be_top__DOT__disp_payload_q),1024);
        bufp->chgSData(oldp+246,(vlSelfRef.be_top__DOT__disp_len_q),16);
        bufp->chgSData(oldp+247,(vlSelfRef.be_top__DOT__disp_build_idx_q),16);
        bufp->chgBit(oldp+248,(vlSelfRef.be_top__DOT__disp_for_remote_q));
        bufp->chgCData(oldp+249,(vlSelfRef.be_top__DOT__recall_msg_id_q),8);
        bufp->chgCData(oldp+250,(vlSelfRef.be_top__DOT__recall_store_idx_q),6);
        bufp->chgCData(oldp+251,(vlSelfRef.be_top__DOT__recall_side_q),2);
        bufp->chgBit(oldp+252,(vlSelfRef.be_top__DOT__recall_send_q));
        bufp->chgBit(oldp+253,(vlSelfRef.be_top__DOT__emoji_suggest_tracking_q));
        bufp->chgCData(oldp+254,(vlSelfRef.be_top__DOT__emoji_complete_token_q),4);
        bufp->chgSData(oldp+255,(vlSelfRef.be_top__DOT__emoji_complete_char_idx_q),16);
        bufp->chgSData(oldp+256,(vlSelfRef.be_top__DOT__emoji_complete_token_len_q),16);
        bufp->chgSData(oldp+257,(vlSelfRef.be_top__DOT__click_popup_dx),10);
        bufp->chgSData(oldp+258,(vlSelfRef.be_top__DOT__click_popup_dy),10);
        bufp->chgCData(oldp+259,((0x0000000fU & ((IData)(vlSelfRef.be_top__DOT__click_popup_dx) 
                                                 >> 6U))),4);
        bufp->chgBit(oldp+260,(vlSelfRef.be_top__DOT__click_in_sticker_picker));
        bufp->chgCData(oldp+261,(((0x00000200U & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                   ? 0x80U : ((0x00000100U 
                                               & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                               ? ((0x00000080U 
                                                   & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                   ? 0x80U
                                                   : 
                                                  ((0x00000040U 
                                                    & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                    ? 0x80U
                                                    : 0xc8U))
                                               : ((0x00000080U 
                                                   & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                   ? 
                                                  ((0x00000040U 
                                                    & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                    ? 0xb6U
                                                    : 0xa4U)
                                                   : 
                                                  ((0x00000040U 
                                                    & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
                                                    ? 0x92U
                                                    : 0x80U))))),8);
        bufp->chgBit(oldp+262,(vlSelfRef.be_top__DOT__click_in_msg_menu));
        bufp->chgBit(oldp+263,(vlSelfRef.be_top__DOT__click_msg_menu_quote));
        bufp->chgBit(oldp+264,(vlSelfRef.be_top__DOT__click_msg_menu_recall));
        bufp->chgSData(oldp+265,((0x000003ffU & ((IData)(vlSelfRef.be_top__DOT__click_x_q) 
                                                 - (IData)(0x0010U)))),10);
        bufp->chgSData(oldp+266,((0x000003ffU & ((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                 - (IData)(0x0104U)))),10);
        bufp->chgCData(oldp+267,((0x0000000fU & ((((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                   - (IData)(0x0104U)) 
                                                  - (IData)(2U)) 
                                                 >> 4U))),4);
        bufp->chgBit(oldp+268,(vlSelfRef.be_top__DOT__click_in_emoji_suggest));
        bufp->chgCData(oldp+269,(vlSelfRef.be_top__DOT__click_emoji_token_id),4);
        bufp->chgSData(oldp+270,(vlSelfRef.be_top__DOT__click_emoji_token_len),16);
        bufp->chgSData(oldp+271,(vlSelfRef.be_top__DOT__click_emoji_prefix_len),16);
        bufp->chgSData(oldp+272,((0x0000ffffU & (((IData)(vlSelfRef.be_top__DOT__click_emoji_token_len) 
                                                  - (IData)(vlSelfRef.be_top__DOT__click_emoji_prefix_len)) 
                                                 & (- (IData)(
                                                              ((IData)(vlSelfRef.be_top__DOT__click_emoji_token_len) 
                                                               > (IData)(vlSelfRef.be_top__DOT__click_emoji_prefix_len))))))),16);
        bufp->chgBit(oldp+273,(vlSelfRef.be_top__DOT__click_emoji_fits));
        bufp->chgBit(oldp+274,(((2U <= (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)) 
                                & (0x1fU > (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)))));
        bufp->chgBit(oldp+275,(((7U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                | ((8U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                   | ((6U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                      | ((IData)(vlSelfRef.be_top__DOT__click_walk_done_q) 
                                         & (0x19U == (IData)(vlSelfRef.be_top__DOT__state_q))))))));
        bufp->chgBit(oldp+276,(vlSelfRef.be_top__DOT__suggest_tracking_base));
        bufp->chgSData(oldp+277,(vlSelfRef.be_top__DOT__suggest_anchor_base),16);
        bufp->chgSData(oldp+278,(vlSelfRef.be_top__DOT__suggest_cursor_base),16);
        bufp->chgSData(oldp+279,(vlSelfRef.be_top__DOT__suggest_prefix_len),16);
        bufp->chgBit(oldp+280,(vlSelfRef.be_top__DOT__suggest_prefix_valid));
        bufp->chgCData(oldp+281,(vlSelfRef.be_top__DOT__suggest_prefix_byte[0]),8);
        bufp->chgCData(oldp+282,(vlSelfRef.be_top__DOT__suggest_prefix_byte[1]),8);
        bufp->chgCData(oldp+283,(vlSelfRef.be_top__DOT__suggest_prefix_byte[2]),8);
        bufp->chgCData(oldp+284,(vlSelfRef.be_top__DOT__suggest_prefix_byte[3]),8);
        bufp->chgCData(oldp+285,(vlSelfRef.be_top__DOT__suggest_prefix_byte[4]),8);
        bufp->chgCData(oldp+286,(vlSelfRef.be_top__DOT__suggest_prefix_byte[5]),8);
        bufp->chgCData(oldp+287,(vlSelfRef.be_top__DOT__suggest_prefix_byte[6]),8);
        bufp->chgCData(oldp+288,(vlSelfRef.be_top__DOT__suggest_count_calc),4);
        bufp->chgQData(oldp+289,(vlSelfRef.be_top__DOT__suggest_ids_calc),60);
        bufp->chgBit(oldp+291,(vlSelfRef.be_top__DOT__suggest_active_calc));
        bufp->chgCData(oldp+292,(vlSelfRef.be_top__DOT__enc_emit_byte),8);
        bufp->chgCData(oldp+293,(vlSelfRef.be_top__DOT__enc_src_delta),4);
        bufp->chgBit(oldp+294,(vlSelfRef.be_top__DOT__enc_done));
        bufp->chgBit(oldp+295,((2U == (IData)(vlSelfRef.be_top__DOT__state_q))));
        bufp->chgBit(oldp+296,((0x11U == (IData)(vlSelfRef.be_top__DOT__state_q))));
        bufp->chgBit(oldp+297,(((IData)(vlSelfRef.be_top__DOT__has_quote_q) 
                                & (IData)(vlSelfRef.be_top__DOT__enc_done))));
        bufp->chgIData(oldp+298,(vlSelfRef.be_top__DOT__unnamedblk5__DOT__src),32);
    }
    bufp->chgBit(oldp+299,(vlSelfRef.clk));
    bufp->chgBit(oldp+300,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+301,(vlSelfRef.io_key_valid));
    bufp->chgBit(oldp+302,(vlSelfRef.io_key_ready));
    bufp->chgCData(oldp+303,(vlSelfRef.io_key_type),3);
    bufp->chgCData(oldp+304,(vlSelfRef.io_key_ascii),8);
    bufp->chgBit(oldp+305,(vlSelfRef.io_mouse_click_valid));
    bufp->chgBit(oldp+306,(vlSelfRef.io_mouse_right_click_valid));
    bufp->chgBit(oldp+307,(vlSelfRef.io_mouse_click_ready));
    bufp->chgSData(oldp+308,(vlSelfRef.io_mouse_click_x),10);
    bufp->chgSData(oldp+309,(vlSelfRef.io_mouse_click_y),10);
    bufp->chgCData(oldp+310,(vlSelfRef.fe_input_scroll_offset),4);
    bufp->chgBit(oldp+311,(vlSelfRef.fe_input_at_limit));
    bufp->chgCData(oldp+312,(vlSelfRef.fe_hist_wr_row),6);
    bufp->chgCData(oldp+313,(vlSelfRef.fe_hist_scroll_offset),6);
    bufp->chgQData(oldp+314,(vlSelfRef.fe_hist_owner_valid),64);
    bufp->chgWData(oldp+316,(vlSelfRef.fe_hist_owner_store_idx),384);
    bufp->chgWData(oldp+328,(vlSelfRef.fe_hist_owner_side),128);
    bufp->chgWData(oldp+332,(vlSelfRef.fe_hist_owner_width),448);
    bufp->chgBit(oldp+346,(vlSelfRef.cm_rx_valid));
    bufp->chgBit(oldp+347,(vlSelfRef.cm_rx_ready));
    bufp->chgCData(oldp+348,(vlSelfRef.cm_rx_frame_type),3);
    bufp->chgCData(oldp+349,(vlSelfRef.cm_rx_seq),8);
    bufp->chgSData(oldp+350,(vlSelfRef.cm_rx_len),16);
    bufp->chgWData(oldp+351,(vlSelfRef.cm_rx_payload),1024);
    bufp->chgBit(oldp+383,(vlSelfRef.cm_status_valid));
    bufp->chgBit(oldp+384,(vlSelfRef.cm_status_ready));
    bufp->chgCData(oldp+385,(vlSelfRef.cm_status_msg_id),8);
    bufp->chgCData(oldp+386,(vlSelfRef.cm_status_code),2);
    bufp->chgBit(oldp+387,(vlSelfRef.be_tx_valid));
    bufp->chgBit(oldp+388,(vlSelfRef.be_tx_ready));
    bufp->chgCData(oldp+389,(vlSelfRef.be_tx_frame_type),3);
    bufp->chgCData(oldp+390,(vlSelfRef.be_tx_msg_id),8);
    bufp->chgSData(oldp+391,(vlSelfRef.be_tx_len),16);
    bufp->chgWData(oldp+392,(vlSelfRef.be_tx_payload),1024);
    bufp->chgBit(oldp+424,(vlSelfRef.be_render_valid));
    bufp->chgBit(oldp+425,(vlSelfRef.be_render_ready));
    bufp->chgCData(oldp+426,(vlSelfRef.be_render_cmd),4);
    bufp->chgCData(oldp+427,(vlSelfRef.be_render_msg_id),8);
    bufp->chgCData(oldp+428,(vlSelfRef.be_render_store_idx),6);
    bufp->chgCData(oldp+429,(vlSelfRef.be_render_side),2);
    bufp->chgCData(oldp+430,(vlSelfRef.be_render_status),2);
    bufp->chgSData(oldp+431,(vlSelfRef.be_render_len),16);
    bufp->chgWData(oldp+432,(vlSelfRef.be_render_payload),1024);
    bufp->chgSData(oldp+464,(vlSelfRef.be_render_cursor_pos),16);
    bufp->chgCData(oldp+465,(vlSelfRef.be_render_ascii),8);
    bufp->chgCData(oldp+466,(vlSelfRef.be_render_conn_state),2);
    bufp->chgCData(oldp+467,(vlSelfRef.line_rd_idx),7);
    bufp->chgCData(oldp+468,(vlSelfRef.line_rd_data),8);
    bufp->chgCData(oldp+469,(vlSelfRef.store_rd_idx),6);
    bufp->chgBit(oldp+470,(vlSelfRef.store_rd_valid));
    bufp->chgCData(oldp+471,(vlSelfRef.store_rd_msg_id),8);
    bufp->chgCData(oldp+472,(vlSelfRef.store_rd_side),2);
    bufp->chgCData(oldp+473,(vlSelfRef.store_rd_status),2);
    bufp->chgSData(oldp+474,(vlSelfRef.store_rd_len),16);
    bufp->chgWData(oldp+475,(vlSelfRef.store_rd_payload),1024);
    bufp->chgBit(oldp+507,((1U & (IData)((vlSelfRef.fe_hist_owner_valid 
                                          >> (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))));
    bufp->chgCData(oldp+508,((0x0000003fU & ((((0U 
                                                == 
                                                (0x0000001fU 
                                                 & ((IData)(6U) 
                                                    * (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))
                                                ? 0U
                                                : (vlSelfRef.fe_hist_owner_store_idx
                                                   [
                                                   (((IData)(5U) 
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
                                                 [(0x0000000fU 
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
    bufp->chgBit(oldp+509,((((2U <= (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)) 
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
    bufp->chgSData(oldp+510,(vlSelfRef.be_top__DOT__rx_len_clamped),16);
    bufp->chgSData(oldp+511,(vlSelfRef.be_top__DOT__rx_name_len_clamped),16);
    bufp->chgBit(oldp+512,((0U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->chgBit(oldp+513,((3U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->chgBit(oldp+514,((4U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->chgBit(oldp+515,((5U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->chgBit(oldp+516,((6U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->chgBit(oldp+517,((7U == (IData)(vlSelfRef.cm_rx_frame_type))));
    bufp->chgBit(oldp+518,(((0x22U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                            | ((IData)(vlSelfRef.cm_status_ready) 
                               & ((IData)(vlSelfRef.be_top__DOT__store_lookup_hit) 
                                  & (IData)(vlSelfRef.be_top__DOT__accept_status))))));
    bufp->chgCData(oldp+519,((3U & (((0U == (IData)(vlSelfRef.cm_status_code))
                                      ? 1U : 2U) | 
                                    (- (IData)((0x22U 
                                                == (IData)(vlSelfRef.be_top__DOT__state_q))))))),2);
    bufp->chgCData(oldp+520,((0x000000ffU & ((IData)(vlSelfRef.be_top__DOT__rx_quote_entry)
                                              ? ((vlSelfRef.cm_rx_payload[0U] 
                                                  << 0x00000018U) 
                                                 | (vlSelfRef.cm_rx_payload[0U] 
                                                    >> 8U))
                                              : (IData)(vlSelfRef.be_top__DOT__quoted_msg_id_q)))),8);
}

void Vbe_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root__trace_cleanup\n"); );
    // Body
    Vbe_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbe_top___024root*>(voidSelf);
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
