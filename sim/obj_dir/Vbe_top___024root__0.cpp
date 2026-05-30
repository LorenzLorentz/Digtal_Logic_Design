// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbe_top.h for the primary calling header

#include "Vbe_top__pch.h"

void Vbe_top___024root___eval_triggers_vec__ico(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_triggers_vec__ico\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vbe_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlWide<32>/*1023:0*/ Vbe_top__ConstPool__CONST_hd6b7ba52_0;

void Vbe_top___024root___ico_sequent__TOP__0(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___ico_sequent__TOP__0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_1;
    __VdfgRegularize_hebeb780c_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_3;
    __VdfgRegularize_hebeb780c_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_4;
    __VdfgRegularize_hebeb780c_0_4 = 0;
    // Body
    vlSelfRef.store_rd_valid = (1U & (vlSelfRef.be_top__DOT__u_store__DOT__store
                                      [vlSelfRef.store_rd_idx][32U] 
                                      >> 0x0000001cU));
    vlSelfRef.store_rd_msg_id = (0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store
                                                [vlSelfRef.store_rd_idx][32U] 
                                                >> 0x00000014U));
    vlSelfRef.store_rd_side = (3U & (vlSelfRef.be_top__DOT__u_store__DOT__store
                                     [vlSelfRef.store_rd_idx][32U] 
                                     >> 0x00000012U));
    vlSelfRef.store_rd_status = (3U & (vlSelfRef.be_top__DOT__u_store__DOT__store
                                       [vlSelfRef.store_rd_idx][32U] 
                                       >> 0x00000010U));
    vlSelfRef.store_rd_len = (0x0000ffffU & vlSelfRef.be_top__DOT__u_store__DOT__store
                              [vlSelfRef.store_rd_idx][32U]);
    vlSelfRef.store_rd_payload[0U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][0U];
    vlSelfRef.store_rd_payload[1U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][1U];
    vlSelfRef.store_rd_payload[2U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][2U];
    vlSelfRef.store_rd_payload[3U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][3U];
    vlSelfRef.store_rd_payload[4U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][4U];
    vlSelfRef.store_rd_payload[5U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][5U];
    vlSelfRef.store_rd_payload[6U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][6U];
    vlSelfRef.store_rd_payload[7U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][7U];
    vlSelfRef.store_rd_payload[8U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][8U];
    vlSelfRef.store_rd_payload[9U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][9U];
    vlSelfRef.store_rd_payload[10U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][10U];
    vlSelfRef.store_rd_payload[11U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][11U];
    vlSelfRef.store_rd_payload[12U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][12U];
    vlSelfRef.store_rd_payload[13U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][13U];
    vlSelfRef.store_rd_payload[14U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][14U];
    vlSelfRef.store_rd_payload[15U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][15U];
    vlSelfRef.store_rd_payload[16U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][16U];
    vlSelfRef.store_rd_payload[17U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][17U];
    vlSelfRef.store_rd_payload[18U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][18U];
    vlSelfRef.store_rd_payload[19U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][19U];
    vlSelfRef.store_rd_payload[20U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][20U];
    vlSelfRef.store_rd_payload[21U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][21U];
    vlSelfRef.store_rd_payload[22U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][22U];
    vlSelfRef.store_rd_payload[23U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][23U];
    vlSelfRef.store_rd_payload[24U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][24U];
    vlSelfRef.store_rd_payload[25U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][25U];
    vlSelfRef.store_rd_payload[26U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][26U];
    vlSelfRef.store_rd_payload[27U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][27U];
    vlSelfRef.store_rd_payload[28U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][28U];
    vlSelfRef.store_rd_payload[29U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][29U];
    vlSelfRef.store_rd_payload[30U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][30U];
    vlSelfRef.store_rd_payload[31U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][31U];
    vlSelfRef.line_rd_data = vlSelfRef.be_top__DOT__line_buf
        [vlSelfRef.line_rd_idx];
    vlSelfRef.be_top__DOT__rx_len_clamped = ((0x0080U 
                                              < (IData)(vlSelfRef.cm_rx_len))
                                              ? 0x0080U
                                              : (IData)(vlSelfRef.cm_rx_len));
    vlSelfRef.be_top__DOT__rx_name_len_clamped = ((0x0010U 
                                                   < (IData)(vlSelfRef.cm_rx_len))
                                                   ? 0x0010U
                                                   : (IData)(vlSelfRef.cm_rx_len));
    vlSelfRef.be_top__DOT__click_hist_slot = (0x0000003fU 
                                              & ((((IData)(0x23U) 
                                                   + (IData)(vlSelfRef.fe_hist_wr_row)) 
                                                  - (IData)(vlSelfRef.fe_hist_scroll_offset)) 
                                                 + 
                                                 ((IData)(vlSelfRef.be_top__DOT__click_screen_row_q) 
                                                  - (IData)(2U))));
    vlSelfRef.be_top__DOT__accept_status = ((IData)(vlSelfRef.cm_status_valid) 
                                            & (IData)(vlSelfRef.cm_status_ready));
    vlSelfRef.be_top__DOT__key_char_insert_allowed 
        = ((0x0080U > (IData)(vlSelfRef.be_top__DOT__len_q)) 
           & ((0x0aU != (IData)(vlSelfRef.io_key_ascii)) 
              | ((~ (IData)(vlSelfRef.fe_input_at_limit)) 
                 & (0x0fU > (IData)(vlSelfRef.be_top__DOT__input_newline_count_q)))));
    __VdfgRegularize_hebeb780c_0_4 = ((~ (IData)(vlSelfRef.cm_status_valid)) 
                                      & (IData)(vlSelfRef.cm_status_ready));
    vlSelfRef.be_top__DOT__peer_name_changed = ((IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped) 
                                                != (IData)(vlSelfRef.be_top__DOT__peer_name_len_q));
    if ((VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & vlSelfRef.cm_rx_payload[0U]) 
            != (0x000000ffU & vlSelfRef.be_top__DOT__peer_name_q[0U])))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[0U] 
                            >> 8U)) != (0x000000ffU 
                                        & (vlSelfRef.be_top__DOT__peer_name_q[0U] 
                                           >> 8U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[0U] 
                            >> 0x00000010U)) != (0x000000ffU 
                                                 & (vlSelfRef.be_top__DOT__peer_name_q[0U] 
                                                    >> 0x00000010U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((vlSelfRef.cm_rx_payload[0U] >> 0x00000018U) 
            != (vlSelfRef.be_top__DOT__peer_name_q[0U] 
                >> 0x00000018U)))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & vlSelfRef.cm_rx_payload[1U]) 
            != (0x000000ffU & vlSelfRef.be_top__DOT__peer_name_q[1U])))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[1U] 
                            >> 8U)) != (0x000000ffU 
                                        & (vlSelfRef.be_top__DOT__peer_name_q[1U] 
                                           >> 8U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[1U] 
                            >> 0x00000010U)) != (0x000000ffU 
                                                 & (vlSelfRef.be_top__DOT__peer_name_q[1U] 
                                                    >> 0x00000010U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 7U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((vlSelfRef.cm_rx_payload[1U] >> 0x00000018U) 
            != (vlSelfRef.be_top__DOT__peer_name_q[1U] 
                >> 0x00000018U)))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 8U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & vlSelfRef.cm_rx_payload[2U]) 
            != (0x000000ffU & vlSelfRef.be_top__DOT__peer_name_q[2U])))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 9U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[2U] 
                            >> 8U)) != (0x000000ffU 
                                        & (vlSelfRef.be_top__DOT__peer_name_q[2U] 
                                           >> 8U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000aU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[2U] 
                            >> 0x00000010U)) != (0x000000ffU 
                                                 & (vlSelfRef.be_top__DOT__peer_name_q[2U] 
                                                    >> 0x00000010U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000bU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((vlSelfRef.cm_rx_payload[2U] >> 0x00000018U) 
            != (vlSelfRef.be_top__DOT__peer_name_q[2U] 
                >> 0x00000018U)))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000cU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & vlSelfRef.cm_rx_payload[3U]) 
            != (0x000000ffU & vlSelfRef.be_top__DOT__peer_name_q[3U])))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000dU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[3U] 
                            >> 8U)) != (0x000000ffU 
                                        & (vlSelfRef.be_top__DOT__peer_name_q[3U] 
                                           >> 8U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000eU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[3U] 
                            >> 0x00000010U)) != (0x000000ffU 
                                                 & (vlSelfRef.be_top__DOT__peer_name_q[3U] 
                                                    >> 0x00000010U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000fU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((vlSelfRef.cm_rx_payload[3U] >> 0x00000018U) 
            != (vlSelfRef.be_top__DOT__peer_name_q[3U] 
                >> 0x00000018U)))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    vlSelfRef.be_top__DOT__click_hist_owner_side = 
        (3U & (((0U == (0x0000001fU & ((IData)(vlSelfRef.be_top__DOT__click_hist_slot) 
                                       << 1U))) ? 0U
                 : (vlSelfRef.fe_hist_owner_side[(((IData)(1U) 
                                                   + 
                                                   ((IData)(vlSelfRef.be_top__DOT__click_hist_slot) 
                                                    << 1U)) 
                                                  >> 5U)] 
                    << ((IData)(0x00000020U) - (0x0000001fU 
                                                & ((IData)(vlSelfRef.be_top__DOT__click_hist_slot) 
                                                   << 1U))))) 
               | (vlSelfRef.fe_hist_owner_side[(0x07ffffffU 
                                                & ((IData)(vlSelfRef.be_top__DOT__click_hist_slot) 
                                                   >> 4U))] 
                  >> (0x0000001fU & ((IData)(vlSelfRef.be_top__DOT__click_hist_slot) 
                                     << 1U)))));
    vlSelfRef.be_top__DOT__click_hist_owner_width = 
        (0x0000007fU & ((((0U == (0x0000001fU & ((IData)(7U) 
                                                 * (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))
                           ? 0U : (vlSelfRef.fe_hist_owner_width
                                   [(((IData)(6U) + 
                                      (0x000001ffU 
                                       & ((IData)(7U) 
                                          * (IData)(vlSelfRef.be_top__DOT__click_hist_slot)))) 
                                     >> 5U)] << ((IData)(0x00000020U) 
                                                 - 
                                                 (0x0000001fU 
                                                  & ((IData)(7U) 
                                                     * (IData)(vlSelfRef.be_top__DOT__click_hist_slot)))))) 
                         | (vlSelfRef.fe_hist_owner_width
                            [(0x0000000fU & (((IData)(7U) 
                                              * (IData)(vlSelfRef.be_top__DOT__click_hist_slot)) 
                                             >> 5U))] 
                            >> (0x0000001fU & ((IData)(7U) 
                                               * (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))) 
                        & (- (IData)((0x01bfU >= (0x000001ffU 
                                                  & ((IData)(7U) 
                                                     * (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))))));
    __VdfgRegularize_hebeb780c_0_3 = ((~ (IData)(vlSelfRef.cm_rx_valid)) 
                                      & (IData)(__VdfgRegularize_hebeb780c_0_4));
    vlSelfRef.cm_rx_ready = ((IData)(__VdfgRegularize_hebeb780c_0_4) 
                             | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2));
    vlSelfRef.be_top__DOT__click_in_hist_bubble = (
                                                   ((2U 
                                                     <= (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)) 
                                                    & (0x1fU 
                                                       > (IData)(vlSelfRef.be_top__DOT__click_screen_row_q))) 
                                                   & ((IData)(
                                                              (vlSelfRef.fe_hist_owner_valid 
                                                               >> (IData)(vlSelfRef.be_top__DOT__click_hist_slot))) 
                                                      & (((IData)(vlSelfRef.be_top__DOT__click_raw_col_q) 
                                                          >= 
                                                          ((1U 
                                                            == (IData)(vlSelfRef.be_top__DOT__click_hist_owner_side))
                                                            ? 2U
                                                            : 
                                                           (0x0000007fU 
                                                            & (((IData)(0x61U) 
                                                                - (IData)(vlSelfRef.be_top__DOT__click_hist_owner_width)) 
                                                               - (IData)(1U))))) 
                                                         & ((IData)(vlSelfRef.be_top__DOT__click_raw_col_q) 
                                                            <= 
                                                            ((1U 
                                                              == (IData)(vlSelfRef.be_top__DOT__click_hist_owner_side))
                                                              ? 
                                                             (0x0000007fU 
                                                              & ((IData)(3U) 
                                                                 + (IData)(vlSelfRef.be_top__DOT__click_hist_owner_width)))
                                                              : 0x00000061U)))));
    vlSelfRef.io_mouse_click_ready = ((~ (IData)(vlSelfRef.io_key_valid)) 
                                      & (IData)(__VdfgRegularize_hebeb780c_0_3));
    vlSelfRef.io_key_ready = (((~ (IData)(vlSelfRef.cm_rx_valid)) 
                               & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                              | (IData)(__VdfgRegularize_hebeb780c_0_3));
    vlSelfRef.be_top__DOT__accept_rx = ((IData)(vlSelfRef.cm_rx_valid) 
                                        & (IData)(vlSelfRef.cm_rx_ready));
    vlSelfRef.be_top__DOT__accept_mouse_click = ((IData)(vlSelfRef.be_top__DOT__click_pending_q) 
                                                 & (IData)(vlSelfRef.io_mouse_click_ready));
    vlSelfRef.be_top__DOT__accept_io = ((IData)(vlSelfRef.io_key_valid) 
                                        & (IData)(vlSelfRef.io_key_ready));
    vlSelfRef.be_top__DOT__store_wr_en = 0U;
    vlSelfRef.be_top__DOT__store_wr_side = 0U;
    vlSelfRef.be_top__DOT__store_wr_status = 0U;
    vlSelfRef.be_top__DOT__store_wr_msg_id = 0U;
    VL_ASSIGN_W(1024, vlSelfRef.be_top__DOT__store_wr_payload, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
    vlSelfRef.be_top__DOT__accept_username_frame = 
        (((3U == (IData)(vlSelfRef.cm_rx_frame_type)) 
          | ((4U == (IData)(vlSelfRef.cm_rx_frame_type)) 
             | (5U == (IData)(vlSelfRef.cm_rx_frame_type)))) 
         & (IData)(vlSelfRef.be_top__DOT__accept_rx));
    vlSelfRef.be_top__DOT__store_wr_len = 0U;
    if ((5U == (IData)(vlSelfRef.be_top__DOT__state_q))) {
        if (((IData)(vlSelfRef.be_top__DOT__accept_rx) 
             & (0U == (IData)(vlSelfRef.cm_rx_frame_type)))) {
            vlSelfRef.be_top__DOT__store_wr_en = 1U;
            vlSelfRef.be_top__DOT__store_wr_side = 1U;
            vlSelfRef.be_top__DOT__store_wr_status = 1U;
            vlSelfRef.be_top__DOT__store_wr_msg_id 
                = vlSelfRef.cm_rx_seq;
            vlSelfRef.be_top__DOT__store_wr_payload[0U] 
                = vlSelfRef.cm_rx_payload[0U];
            vlSelfRef.be_top__DOT__store_wr_payload[1U] 
                = vlSelfRef.cm_rx_payload[1U];
            vlSelfRef.be_top__DOT__store_wr_payload[2U] 
                = vlSelfRef.cm_rx_payload[2U];
            vlSelfRef.be_top__DOT__store_wr_payload[3U] 
                = vlSelfRef.cm_rx_payload[3U];
            vlSelfRef.be_top__DOT__store_wr_payload[4U] 
                = vlSelfRef.cm_rx_payload[4U];
            vlSelfRef.be_top__DOT__store_wr_payload[5U] 
                = vlSelfRef.cm_rx_payload[5U];
            vlSelfRef.be_top__DOT__store_wr_payload[6U] 
                = vlSelfRef.cm_rx_payload[6U];
            vlSelfRef.be_top__DOT__store_wr_payload[7U] 
                = vlSelfRef.cm_rx_payload[7U];
            vlSelfRef.be_top__DOT__store_wr_payload[8U] 
                = vlSelfRef.cm_rx_payload[8U];
            vlSelfRef.be_top__DOT__store_wr_payload[9U] 
                = vlSelfRef.cm_rx_payload[9U];
            vlSelfRef.be_top__DOT__store_wr_payload[10U] 
                = vlSelfRef.cm_rx_payload[10U];
            vlSelfRef.be_top__DOT__store_wr_payload[11U] 
                = vlSelfRef.cm_rx_payload[11U];
            vlSelfRef.be_top__DOT__store_wr_payload[12U] 
                = vlSelfRef.cm_rx_payload[12U];
            vlSelfRef.be_top__DOT__store_wr_payload[13U] 
                = vlSelfRef.cm_rx_payload[13U];
            vlSelfRef.be_top__DOT__store_wr_payload[14U] 
                = vlSelfRef.cm_rx_payload[14U];
            vlSelfRef.be_top__DOT__store_wr_payload[15U] 
                = vlSelfRef.cm_rx_payload[15U];
            vlSelfRef.be_top__DOT__store_wr_payload[16U] 
                = vlSelfRef.cm_rx_payload[16U];
            vlSelfRef.be_top__DOT__store_wr_payload[17U] 
                = vlSelfRef.cm_rx_payload[17U];
            vlSelfRef.be_top__DOT__store_wr_payload[18U] 
                = vlSelfRef.cm_rx_payload[18U];
            vlSelfRef.be_top__DOT__store_wr_payload[19U] 
                = vlSelfRef.cm_rx_payload[19U];
            vlSelfRef.be_top__DOT__store_wr_payload[20U] 
                = vlSelfRef.cm_rx_payload[20U];
            vlSelfRef.be_top__DOT__store_wr_payload[21U] 
                = vlSelfRef.cm_rx_payload[21U];
            vlSelfRef.be_top__DOT__store_wr_payload[22U] 
                = vlSelfRef.cm_rx_payload[22U];
            vlSelfRef.be_top__DOT__store_wr_payload[23U] 
                = vlSelfRef.cm_rx_payload[23U];
            vlSelfRef.be_top__DOT__store_wr_payload[24U] 
                = vlSelfRef.cm_rx_payload[24U];
            vlSelfRef.be_top__DOT__store_wr_payload[25U] 
                = vlSelfRef.cm_rx_payload[25U];
            vlSelfRef.be_top__DOT__store_wr_payload[26U] 
                = vlSelfRef.cm_rx_payload[26U];
            vlSelfRef.be_top__DOT__store_wr_payload[27U] 
                = vlSelfRef.cm_rx_payload[27U];
            vlSelfRef.be_top__DOT__store_wr_payload[28U] 
                = vlSelfRef.cm_rx_payload[28U];
            vlSelfRef.be_top__DOT__store_wr_payload[29U] 
                = vlSelfRef.cm_rx_payload[29U];
            vlSelfRef.be_top__DOT__store_wr_payload[30U] 
                = vlSelfRef.cm_rx_payload[30U];
            vlSelfRef.be_top__DOT__store_wr_payload[31U] 
                = vlSelfRef.cm_rx_payload[31U];
            vlSelfRef.be_top__DOT__store_wr_len = vlSelfRef.be_top__DOT__rx_len_clamped;
        }
    } else if (vlSelfRef.be_top__DOT__enc_done) {
        vlSelfRef.be_top__DOT__store_wr_en = 1U;
        vlSelfRef.be_top__DOT__store_wr_side = 0U;
        vlSelfRef.be_top__DOT__store_wr_status = 0U;
        vlSelfRef.be_top__DOT__store_wr_msg_id = vlSelfRef.be_top__DOT__pending_msg_id_q;
        vlSelfRef.be_top__DOT__store_wr_payload[0U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[0U];
        vlSelfRef.be_top__DOT__store_wr_payload[1U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[1U];
        vlSelfRef.be_top__DOT__store_wr_payload[2U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[2U];
        vlSelfRef.be_top__DOT__store_wr_payload[3U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[3U];
        vlSelfRef.be_top__DOT__store_wr_payload[4U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[4U];
        vlSelfRef.be_top__DOT__store_wr_payload[5U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[5U];
        vlSelfRef.be_top__DOT__store_wr_payload[6U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[6U];
        vlSelfRef.be_top__DOT__store_wr_payload[7U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[7U];
        vlSelfRef.be_top__DOT__store_wr_payload[8U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[8U];
        vlSelfRef.be_top__DOT__store_wr_payload[9U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[9U];
        vlSelfRef.be_top__DOT__store_wr_payload[10U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[10U];
        vlSelfRef.be_top__DOT__store_wr_payload[11U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[11U];
        vlSelfRef.be_top__DOT__store_wr_payload[12U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[12U];
        vlSelfRef.be_top__DOT__store_wr_payload[13U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[13U];
        vlSelfRef.be_top__DOT__store_wr_payload[14U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[14U];
        vlSelfRef.be_top__DOT__store_wr_payload[15U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[15U];
        vlSelfRef.be_top__DOT__store_wr_payload[16U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[16U];
        vlSelfRef.be_top__DOT__store_wr_payload[17U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[17U];
        vlSelfRef.be_top__DOT__store_wr_payload[18U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[18U];
        vlSelfRef.be_top__DOT__store_wr_payload[19U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[19U];
        vlSelfRef.be_top__DOT__store_wr_payload[20U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[20U];
        vlSelfRef.be_top__DOT__store_wr_payload[21U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[21U];
        vlSelfRef.be_top__DOT__store_wr_payload[22U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[22U];
        vlSelfRef.be_top__DOT__store_wr_payload[23U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[23U];
        vlSelfRef.be_top__DOT__store_wr_payload[24U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[24U];
        vlSelfRef.be_top__DOT__store_wr_payload[25U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[25U];
        vlSelfRef.be_top__DOT__store_wr_payload[26U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[26U];
        vlSelfRef.be_top__DOT__store_wr_payload[27U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[27U];
        vlSelfRef.be_top__DOT__store_wr_payload[28U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[28U];
        vlSelfRef.be_top__DOT__store_wr_payload[29U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[29U];
        vlSelfRef.be_top__DOT__store_wr_payload[30U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[30U];
        vlSelfRef.be_top__DOT__store_wr_payload[31U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[31U];
        vlSelfRef.be_top__DOT__store_wr_len = vlSelfRef.be_top__DOT__enc_dst_q;
    } else if ((0x1aU == (IData)(vlSelfRef.be_top__DOT__state_q))) {
        vlSelfRef.be_top__DOT__store_wr_en = 1U;
        vlSelfRef.be_top__DOT__store_wr_side = 0U;
        vlSelfRef.be_top__DOT__store_wr_status = 0U;
        vlSelfRef.be_top__DOT__store_wr_msg_id = vlSelfRef.be_top__DOT__pending_msg_id_q;
        vlSelfRef.be_top__DOT__store_wr_payload[0U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[0U];
        vlSelfRef.be_top__DOT__store_wr_payload[1U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[1U];
        vlSelfRef.be_top__DOT__store_wr_payload[2U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[2U];
        vlSelfRef.be_top__DOT__store_wr_payload[3U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[3U];
        vlSelfRef.be_top__DOT__store_wr_payload[4U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[4U];
        vlSelfRef.be_top__DOT__store_wr_payload[5U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[5U];
        vlSelfRef.be_top__DOT__store_wr_payload[6U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[6U];
        vlSelfRef.be_top__DOT__store_wr_payload[7U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[7U];
        vlSelfRef.be_top__DOT__store_wr_payload[8U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[8U];
        vlSelfRef.be_top__DOT__store_wr_payload[9U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[9U];
        vlSelfRef.be_top__DOT__store_wr_payload[10U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[10U];
        vlSelfRef.be_top__DOT__store_wr_payload[11U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[11U];
        vlSelfRef.be_top__DOT__store_wr_payload[12U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[12U];
        vlSelfRef.be_top__DOT__store_wr_payload[13U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[13U];
        vlSelfRef.be_top__DOT__store_wr_payload[14U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[14U];
        vlSelfRef.be_top__DOT__store_wr_payload[15U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[15U];
        vlSelfRef.be_top__DOT__store_wr_payload[16U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[16U];
        vlSelfRef.be_top__DOT__store_wr_payload[17U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[17U];
        vlSelfRef.be_top__DOT__store_wr_payload[18U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[18U];
        vlSelfRef.be_top__DOT__store_wr_payload[19U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[19U];
        vlSelfRef.be_top__DOT__store_wr_payload[20U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[20U];
        vlSelfRef.be_top__DOT__store_wr_payload[21U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[21U];
        vlSelfRef.be_top__DOT__store_wr_payload[22U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[22U];
        vlSelfRef.be_top__DOT__store_wr_payload[23U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[23U];
        vlSelfRef.be_top__DOT__store_wr_payload[24U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[24U];
        vlSelfRef.be_top__DOT__store_wr_payload[25U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[25U];
        vlSelfRef.be_top__DOT__store_wr_payload[26U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[26U];
        vlSelfRef.be_top__DOT__store_wr_payload[27U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[27U];
        vlSelfRef.be_top__DOT__store_wr_payload[28U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[28U];
        vlSelfRef.be_top__DOT__store_wr_payload[29U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[29U];
        vlSelfRef.be_top__DOT__store_wr_payload[30U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[30U];
        vlSelfRef.be_top__DOT__store_wr_payload[31U] 
            = vlSelfRef.be_top__DOT__pending_payload_q[31U];
        vlSelfRef.be_top__DOT__store_wr_len = vlSelfRef.be_top__DOT__pending_len_q;
    }
    __VdfgRegularize_hebeb780c_0_1 = ((7U == (IData)(vlSelfRef.cm_rx_frame_type)) 
                                      & (IData)(vlSelfRef.be_top__DOT__accept_rx));
    vlSelfRef.be_top__DOT__rx_quote_entry = ((IData)(vlSelfRef.be_top__DOT__accept_rx) 
                                             & ((0U 
                                                 == (IData)(vlSelfRef.cm_rx_frame_type)) 
                                                & (1U 
                                                   == 
                                                   (0x000000ffU 
                                                    & vlSelfRef.cm_rx_payload[0U]))));
    vlSelfRef.be_top__DOT__u_store__DOT__clear_en = 
        ((IData)(vlSelfRef.be_top__DOT__peer_name_changed) 
         & (IData)(vlSelfRef.be_top__DOT__accept_username_frame));
    vlSelfRef.be_top__DOT__use_quote_lkup = ((0x1eU 
                                              == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                             | (((IData)(vlSelfRef.be_top__DOT__has_quote_q) 
                                                 & (IData)(vlSelfRef.be_top__DOT__enc_done)) 
                                                | (IData)(vlSelfRef.be_top__DOT__rx_quote_entry)));
    if (vlSelfRef.be_top__DOT__use_quote_lkup) {
        vlSelfRef.be_top__DOT__u_store__DOT__lookup_side 
            = ((IData)(vlSelfRef.be_top__DOT__quoted_side_q) 
               & (- (IData)((1U & (~ (IData)(vlSelfRef.be_top__DOT__rx_quote_entry))))));
        vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id 
            = (0x000000ffU & ((IData)(vlSelfRef.be_top__DOT__rx_quote_entry)
                               ? ((vlSelfRef.cm_rx_payload[0U] 
                                   << 0x00000018U) 
                                  | (vlSelfRef.cm_rx_payload[0U] 
                                     >> 8U)) : (IData)(vlSelfRef.be_top__DOT__quoted_msg_id_q)));
    } else {
        vlSelfRef.be_top__DOT__u_store__DOT__lookup_side 
            = (1U & (- (IData)((IData)(__VdfgRegularize_hebeb780c_0_1))));
        vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id 
            = (0x000000ffU & ((IData)(__VdfgRegularize_hebeb780c_0_1)
                               ? (IData)(vlSelfRef.cm_rx_seq)
                               : (IData)(vlSelfRef.cm_status_msg_id)));
    }
    vlSelfRef.be_top__DOT__store_lookup_hit = 0U;
    vlSelfRef.be_top__DOT__store_lookup_idx = 0U;
    if ((((vlSelfRef.be_top__DOT__u_store__DOT__store[0U][32U] 
           >> 0x0000001cU) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[0U][32U] 
                                     >> 0x00000012U)) 
                              == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[0U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[1U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[1U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[1U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 1U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[2U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[2U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[2U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 2U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[3U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[3U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[3U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 3U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[4U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[4U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[4U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 4U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[5U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[5U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[5U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 5U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[6U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[6U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[6U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 6U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[7U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[7U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[7U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 7U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[8U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[8U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[8U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 8U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[9U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[9U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[9U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 9U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[10U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[10U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[10U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x0aU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[11U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[11U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[11U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x0bU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[12U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[12U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[12U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x0cU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[13U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[13U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[13U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x0dU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[14U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[14U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[14U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x0eU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[15U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[15U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[15U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x0fU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[16U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[16U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[16U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x10U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[17U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[17U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[17U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x11U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[18U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[18U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[18U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x12U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[19U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[19U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[19U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x13U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[20U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[20U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[20U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x14U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[21U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[21U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[21U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x15U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[22U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[22U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[22U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x16U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[23U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[23U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[23U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x17U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[24U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[24U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[24U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x18U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[25U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[25U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[25U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x19U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[26U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[26U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[26U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x1aU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[27U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[27U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[27U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x1bU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[28U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[28U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[28U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x1cU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[29U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[29U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[29U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x1dU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[30U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[30U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[30U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x1eU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[31U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[31U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[31U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x1fU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[32U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[32U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[32U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x20U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[33U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[33U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[33U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x21U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[34U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[34U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[34U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x22U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[35U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[35U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[35U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x23U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[36U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[36U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[36U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x24U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[37U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[37U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[37U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x25U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[38U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[38U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[38U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x26U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[39U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[39U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[39U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x27U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[40U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[40U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[40U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x28U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[41U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[41U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[41U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x29U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[42U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[42U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[42U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x2aU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[43U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[43U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[43U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x2bU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[44U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[44U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[44U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x2cU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[45U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[45U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[45U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x2dU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[46U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[46U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[46U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x2eU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[47U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[47U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[47U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x2fU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[48U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[48U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[48U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x30U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[49U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[49U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[49U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x31U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[50U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[50U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[50U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x32U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[51U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[51U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[51U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x33U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[52U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[52U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[52U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x34U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[53U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[53U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[53U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x35U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[54U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[54U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[54U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x36U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[55U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[55U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[55U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x37U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[56U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[56U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[56U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x38U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[57U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[57U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[57U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x39U;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[58U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[58U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[58U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x3aU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[59U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[59U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[59U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x3bU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[60U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[60U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[60U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x3cU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[61U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[61U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[61U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x3dU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[62U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[62U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[62U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x3eU;
    }
    if (((((~ (IData)(vlSelfRef.be_top__DOT__store_lookup_hit)) 
           & (vlSelfRef.be_top__DOT__u_store__DOT__store[63U][32U] 
              >> 0x0000001cU)) & ((3U & (vlSelfRef.be_top__DOT__u_store__DOT__store[63U][32U] 
                                         >> 0x00000012U)) 
                                  == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_side))) 
         & ((0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store[63U][32U] 
                            >> 0x00000014U)) == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__lookup_msg_id)))) {
        vlSelfRef.be_top__DOT__store_lookup_hit = 1U;
        vlSelfRef.be_top__DOT__store_lookup_idx = 0x3fU;
    }
    vlSelfRef.be_top__DOT__u_store__DOT__upd_idx = 
        ((0x22U == (IData)(vlSelfRef.be_top__DOT__state_q))
          ? (IData)(vlSelfRef.be_top__DOT__recall_store_idx_q)
          : (IData)(vlSelfRef.be_top__DOT__store_lookup_idx));
    vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx = 
        ((0x1eU == (IData)(vlSelfRef.be_top__DOT__state_q))
          ? ((IData)(vlSelfRef.be_top__DOT__store_lookup_idx) 
             & (- (IData)((IData)(vlSelfRef.be_top__DOT__use_quote_lkup))))
          : (IData)(vlSelfRef.be_top__DOT__menu_store_idx_q));
    vlSelfRef.be_top__DOT__u_store__DOT__rd2_msg_id 
        = (0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store
                          [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][32U] 
                          >> 0x00000014U));
    vlSelfRef.be_top__DOT__u_store__DOT__rd2_len = 
        (0x0000ffffU & vlSelfRef.be_top__DOT__u_store__DOT__store
         [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][32U]);
    vlSelfRef.be_top__DOT__u_store__DOT__rd2_side = 
        (3U & (vlSelfRef.be_top__DOT__u_store__DOT__store
               [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][32U] 
               >> 0x00000012U));
    vlSelfRef.be_top__DOT__u_store__DOT__rd2_status 
        = (3U & (vlSelfRef.be_top__DOT__u_store__DOT__store
                 [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][32U] 
                 >> 0x00000010U));
    vlSelfRef.be_top__DOT__u_store__DOT__rd2_valid 
        = (1U & (vlSelfRef.be_top__DOT__u_store__DOT__store
                 [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx][32U] 
                 >> 0x0000001cU));
    vlSelfRef.be_top__DOT__quoted_store_valid = ((IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_valid) 
                                                 & ((IData)(vlSelfRef.be_top__DOT__store_lookup_hit) 
                                                    & (IData)(vlSelfRef.be_top__DOT__use_quote_lkup)));
    vlSelfRef.be_top__DOT__state_d = vlSelfRef.be_top__DOT__state_q;
    if ((0x00000020U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
        if ((0x00000010U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            vlSelfRef.be_top__DOT__state_d = 0U;
        } else if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            vlSelfRef.be_top__DOT__state_d = 0U;
        } else if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            vlSelfRef.be_top__DOT__state_d = 0U;
        } else if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if (vlSelfRef.be_tx_ready) {
                    vlSelfRef.be_top__DOT__state_d = 5U;
                }
            } else if (vlSelfRef.be_render_ready) {
                vlSelfRef.be_top__DOT__state_d = ((IData)(vlSelfRef.be_top__DOT__recall_send_q)
                                                   ? 0x23U
                                                   : 5U);
            }
        } else {
            vlSelfRef.be_top__DOT__state_d = 0U;
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
        if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        vlSelfRef.be_top__DOT__state_d = 0U;
                    } else if (((0x0000ffffU & ((IData)(1U) 
                                                + (IData)(vlSelfRef.be_top__DOT__disp_build_idx_q))) 
                                >= (IData)(vlSelfRef.be_top__DOT__disp_len_q))) {
                        vlSelfRef.be_top__DOT__state_d 
                            = ((IData)(vlSelfRef.be_top__DOT__disp_for_remote_q)
                                ? 0x0cU : 9U);
                    }
                } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if (vlSelfRef.be_render_ready) {
                        vlSelfRef.be_top__DOT__state_d = 5U;
                    }
                } else if (((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                            >= (IData)(vlSelfRef.be_top__DOT__len_q))) {
                    vlSelfRef.be_top__DOT__state_d = 0x1dU;
                }
            } else if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                          == (IData)(vlSelfRef.be_top__DOT__cursor_pos_q)) 
                         & ((0x0000ffffU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.be_top__DOT__emoji_complete_char_idx_q))) 
                            >= (IData)(vlSelfRef.be_top__DOT__emoji_complete_token_len_q)))) {
                        vlSelfRef.be_top__DOT__state_d = 0x1cU;
                    }
                } else {
                    vlSelfRef.be_top__DOT__state_d = 9U;
                }
            } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if (((IData)(vlSelfRef.be_top__DOT__click_walk_done_q) 
                     & (IData)(vlSelfRef.be_render_ready))) {
                    vlSelfRef.be_top__DOT__state_d = 5U;
                }
            } else if (((IData)(vlSelfRef.be_top__DOT__enc_src_q) 
                        >= (IData)(vlSelfRef.be_top__DOT__len_q))) {
                vlSelfRef.be_top__DOT__state_d = ((IData)(vlSelfRef.be_top__DOT__has_quote_q)
                                                   ? 0x1eU
                                                   : 9U);
            }
        } else if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if (((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                         >= (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__len_q) 
                                            - (IData)(1U))))) {
                        vlSelfRef.be_top__DOT__state_d = 8U;
                    }
                } else if (((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                            == (IData)(vlSelfRef.be_top__DOT__cursor_pos_q))) {
                    vlSelfRef.be_top__DOT__state_d = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if (vlSelfRef.be_render_ready) {
                    vlSelfRef.be_top__DOT__state_d = 5U;
                }
            } else if (vlSelfRef.be_render_ready) {
                vlSelfRef.be_top__DOT__state_d = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if (vlSelfRef.be_render_ready) {
                    vlSelfRef.be_top__DOT__state_d = 5U;
                }
            } else if (vlSelfRef.be_render_ready) {
                vlSelfRef.be_top__DOT__state_d = 5U;
            }
        } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (vlSelfRef.be_top__DOT__accept_rx) {
                if (((3U == (IData)(vlSelfRef.cm_rx_frame_type)) 
                     | (4U == (IData)(vlSelfRef.cm_rx_frame_type)))) {
                    vlSelfRef.be_top__DOT__state_d = 3U;
                }
            } else if (vlSelfRef.be_top__DOT__accept_io) {
                if (((0U == (IData)(vlSelfRef.io_key_type)) 
                     & (0x20U == (IData)(vlSelfRef.io_key_ascii)))) {
                    vlSelfRef.be_top__DOT__state_d = 1U;
                }
            }
        } else if (vlSelfRef.be_render_ready) {
            vlSelfRef.be_top__DOT__state_d = 0x11U;
        }
    } else if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if (vlSelfRef.be_tx_ready) {
                        vlSelfRef.be_top__DOT__state_d = 0x10U;
                    }
                } else if (vlSelfRef.be_tx_ready) {
                    vlSelfRef.be_top__DOT__state_d = 4U;
                }
            } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if (vlSelfRef.be_render_ready) {
                    vlSelfRef.be_top__DOT__state_d = 5U;
                }
            } else if (vlSelfRef.be_render_ready) {
                vlSelfRef.be_top__DOT__state_d = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if (vlSelfRef.be_render_ready) {
                    vlSelfRef.be_top__DOT__state_d = 5U;
                }
            } else if (vlSelfRef.be_tx_ready) {
                vlSelfRef.be_top__DOT__state_d = 0x0bU;
            }
        } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (vlSelfRef.be_render_ready) {
                vlSelfRef.be_top__DOT__state_d = 0x0aU;
            }
        } else if (vlSelfRef.be_render_ready) {
            vlSelfRef.be_top__DOT__state_d = 5U;
        }
    } else if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if (vlSelfRef.be_render_ready) {
                    vlSelfRef.be_top__DOT__state_d = 5U;
                }
            } else if (vlSelfRef.be_render_ready) {
                vlSelfRef.be_top__DOT__state_d = 5U;
            }
        } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (vlSelfRef.be_top__DOT__accept_status) {
                vlSelfRef.be_top__DOT__state_d = 0x0dU;
            } else if (vlSelfRef.be_top__DOT__accept_rx) {
                if ((0U == (IData)(vlSelfRef.cm_rx_frame_type))) {
                    vlSelfRef.be_top__DOT__state_d 
                        = ((1U == (0x000000ffU & vlSelfRef.cm_rx_payload[0U]))
                            ? 0x1eU : 0x0cU);
                } else if ((7U == (IData)(vlSelfRef.cm_rx_frame_type))) {
                    vlSelfRef.be_top__DOT__state_d 
                        = ((IData)(vlSelfRef.be_top__DOT__store_lookup_hit)
                            ? 0x22U : 5U);
                } else if ((3U == (IData)(vlSelfRef.cm_rx_frame_type))) {
                    vlSelfRef.be_top__DOT__state_d = 0x0eU;
                } else if ((4U == (IData)(vlSelfRef.cm_rx_frame_type))) {
                    vlSelfRef.be_top__DOT__state_d = 3U;
                } else if ((5U == (IData)(vlSelfRef.cm_rx_frame_type))) {
                    vlSelfRef.be_top__DOT__state_d = 4U;
                } else if ((6U == (IData)(vlSelfRef.cm_rx_frame_type))) {
                    vlSelfRef.be_top__DOT__state_d = 0x10U;
                }
            } else if (vlSelfRef.be_top__DOT__accept_io) {
                vlSelfRef.be_top__DOT__state_d = ((4U 
                                                   & (IData)(vlSelfRef.io_key_type))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.io_key_type))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.io_key_type))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.io_key_ascii))
                                                      ? 0x15U
                                                      : 0x13U)
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.io_key_ascii))
                                                      ? 0x14U
                                                      : 0x12U))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.io_key_type))
                                                     ? 
                                                    ((IData)(vlSelfRef.be_top__DOT__popup_active_q)
                                                      ? 5U
                                                      : 
                                                     ((IData)(vlSelfRef.be_top__DOT__has_quote_q)
                                                       ? 6U
                                                       : 0x0fU))
                                                     : 
                                                    (((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                                                      < (IData)(vlSelfRef.be_top__DOT__len_q))
                                                      ? 6U
                                                      : 5U)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelfRef.io_key_type))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.io_key_type))
                                                     ? 
                                                    ((0U 
                                                      != (IData)(vlSelfRef.be_top__DOT__cursor_pos_q))
                                                      ? 6U
                                                      : 5U)
                                                     : 
                                                    ((0U 
                                                      != (IData)(vlSelfRef.be_top__DOT__cursor_pos_q))
                                                      ? 0x17U
                                                      : 5U))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.io_key_type))
                                                     ? 
                                                    ((0U 
                                                      != (IData)(vlSelfRef.be_top__DOT__len_q))
                                                      ? 0x18U
                                                      : 5U)
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlSelfRef.io_key_ascii))
                                                      ? 5U
                                                      : 
                                                     ((IData)(vlSelfRef.be_top__DOT__key_char_insert_allowed)
                                                       ? 0x16U
                                                       : 5U)))));
            } else if (vlSelfRef.be_top__DOT__accept_mouse_click) {
                if (vlSelfRef.be_top__DOT__click_is_right_q) {
                    vlSelfRef.be_top__DOT__state_d = 5U;
                } else if (vlSelfRef.be_top__DOT__popup_active_q) {
                    if ((((IData)(vlSelfRef.be_top__DOT__click_in_msg_menu) 
                          & (IData)(vlSelfRef.be_top__DOT__click_msg_menu_quote)) 
                         & (IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_valid))) {
                        vlSelfRef.be_top__DOT__state_d = 6U;
                    } else if ((((((IData)(vlSelfRef.be_top__DOT__click_in_msg_menu) 
                                   & (IData)(vlSelfRef.be_top__DOT__click_msg_menu_recall)) 
                                  & (IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_valid)) 
                                 & (0U == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_side))) 
                                & (3U != (IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_status)))) {
                        vlSelfRef.be_top__DOT__state_d = 0x22U;
                    } else if (vlSelfRef.be_top__DOT__click_in_sticker_picker) {
                        vlSelfRef.be_top__DOT__state_d = 0x1aU;
                    }
                } else if (vlSelfRef.be_top__DOT__emoji_suggest_active_q) {
                    if (((IData)(vlSelfRef.be_top__DOT__click_in_emoji_suggest) 
                         & (IData)(vlSelfRef.be_top__DOT__click_emoji_fits))) {
                        vlSelfRef.be_top__DOT__state_d 
                            = (((IData)(vlSelfRef.be_top__DOT__click_emoji_prefix_len) 
                                >= (IData)(vlSelfRef.be_top__DOT__click_emoji_token_len))
                                ? 0x1cU : 0x1bU);
                    }
                } else if (((0x20U <= (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)) 
                            & (0x24U >= (IData)(vlSelfRef.be_top__DOT__click_screen_row_q)))) {
                    vlSelfRef.be_top__DOT__state_d = 0x19U;
                }
            }
        } else if (vlSelfRef.be_render_ready) {
            vlSelfRef.be_top__DOT__state_d = 5U;
        }
    } else if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (vlSelfRef.be_tx_ready) {
                vlSelfRef.be_top__DOT__state_d = 4U;
            }
        } else if (vlSelfRef.be_top__DOT__accept_rx) {
            if (((3U == (IData)(vlSelfRef.cm_rx_frame_type)) 
                 | (4U == (IData)(vlSelfRef.cm_rx_frame_type)))) {
                vlSelfRef.be_top__DOT__state_d = 3U;
            } else if ((5U == (IData)(vlSelfRef.cm_rx_frame_type))) {
                vlSelfRef.be_top__DOT__state_d = 4U;
            }
        }
    } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
        if (vlSelfRef.be_tx_ready) {
            vlSelfRef.be_top__DOT__state_d = 2U;
        }
    } else if (vlSelfRef.be_render_ready) {
        vlSelfRef.be_top__DOT__state_d = 1U;
    }
}

void Vbe_top___024root___eval_ico(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_ico\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vbe_top___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbe_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vbe_top___024root___eval_phase__ico(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_phase__ico\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vbe_top___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbe_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vbe_top___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vbe_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vbe_top___024root___eval_triggers_vec__act(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_triggers_vec__act\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

bool Vbe_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlWide<32>/*1023:0*/ Vbe_top__ConstPool__CONST_h62f3a808_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vbe_top__ConstPool__TABLE_h729b8958_0;

void Vbe_top___024root___nba_sequent__TOP__0(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___nba_sequent__TOP__0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ be_top__DOT____VlemLogAnd_2;
    CData/*3:0*/ __Vfunc_emoji_token_char__5__token_id;
    __Vfunc_emoji_token_char__5__token_id = 0;
    CData/*3:0*/ __Vfunc_emoji_token_char__5__char_idx;
    __Vfunc_emoji_token_char__5__char_idx = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*15:0*/ __Vdly__be_top__DOT__shift_idx_q;
    __Vdly__be_top__DOT__shift_idx_q = 0;
    SData/*15:0*/ __Vdly__be_top__DOT__len_q;
    __Vdly__be_top__DOT__len_q = 0;
    SData/*15:0*/ __Vdly__be_top__DOT__cursor_pos_q;
    __Vdly__be_top__DOT__cursor_pos_q = 0;
    CData/*4:0*/ __Vdly__be_top__DOT__input_newline_count_q;
    __Vdly__be_top__DOT__input_newline_count_q = 0;
    VlWide<32>/*1023:0*/ __Vdly__be_top__DOT__pending_payload_q;
    VL_ZERO_W(1024, __Vdly__be_top__DOT__pending_payload_q);
    SData/*15:0*/ __Vdly__be_top__DOT__enc_dst_q;
    __Vdly__be_top__DOT__enc_dst_q = 0;
    CData/*5:0*/ __Vdly__be_top__DOT__wr_ptr_q;
    __Vdly__be_top__DOT__wr_ptr_q = 0;
    CData/*7:0*/ __Vdly__be_top__DOT__next_msg_id_q;
    __Vdly__be_top__DOT__next_msg_id_q = 0;
    SData/*15:0*/ __Vdly__be_top__DOT__pending_len_q;
    __Vdly__be_top__DOT__pending_len_q = 0;
    CData/*3:0*/ __Vdly__be_top__DOT__click_target_row_q;
    __Vdly__be_top__DOT__click_target_row_q = 0;
    CData/*3:0*/ __Vdly__be_top__DOT__click_vis_row_q;
    __Vdly__be_top__DOT__click_vis_row_q = 0;
    CData/*6:0*/ __Vdly__be_top__DOT__click_vis_col_q;
    __Vdly__be_top__DOT__click_vis_col_q = 0;
    CData/*0:0*/ __Vdly__be_top__DOT__click_walk_done_q;
    __Vdly__be_top__DOT__click_walk_done_q = 0;
    CData/*6:0*/ __Vdly__be_top__DOT__click_target_col_q;
    __Vdly__be_top__DOT__click_target_col_q = 0;
    CData/*7:0*/ __Vdly__be_top__DOT__quoted_msg_id_q;
    __Vdly__be_top__DOT__quoted_msg_id_q = 0;
    SData/*15:0*/ __Vdly__be_top__DOT__disp_len_q;
    __Vdly__be_top__DOT__disp_len_q = 0;
    CData/*0:0*/ __Vdly__be_top__DOT__popup_active_q;
    __Vdly__be_top__DOT__popup_active_q = 0;
    CData/*0:0*/ __Vdly__be_top__DOT__has_quote_q;
    __Vdly__be_top__DOT__has_quote_q = 0;
    CData/*5:0*/ __Vdly__be_top__DOT__menu_store_idx_q;
    __Vdly__be_top__DOT__menu_store_idx_q = 0;
    CData/*0:0*/ __Vdly__be_top__DOT__emoji_suggest_active_q;
    __Vdly__be_top__DOT__emoji_suggest_active_q = 0;
    CData/*3:0*/ __Vdly__be_top__DOT__emoji_complete_token_q;
    __Vdly__be_top__DOT__emoji_complete_token_q = 0;
    SData/*15:0*/ __Vdly__be_top__DOT__emoji_complete_char_idx_q;
    __Vdly__be_top__DOT__emoji_complete_char_idx_q = 0;
    SData/*15:0*/ __Vdly__be_top__DOT__emoji_complete_token_len_q;
    __Vdly__be_top__DOT__emoji_complete_token_len_q = 0;
    SData/*15:0*/ __Vdly__be_top__DOT__disp_build_idx_q;
    __Vdly__be_top__DOT__disp_build_idx_q = 0;
    CData/*7:0*/ __VdlyVal__be_top__DOT__line_buf__v0;
    __VdlyVal__be_top__DOT__line_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__be_top__DOT__line_buf__v0;
    __VdlyDim0__be_top__DOT__line_buf__v0 = 0;
    CData/*7:0*/ __VdlyVal__be_top__DOT__line_buf__v1;
    __VdlyVal__be_top__DOT__line_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__be_top__DOT__line_buf__v1;
    __VdlyDim0__be_top__DOT__line_buf__v1 = 0;
    CData/*7:0*/ __VdlyVal__be_top__DOT__line_buf__v2;
    __VdlyVal__be_top__DOT__line_buf__v2 = 0;
    CData/*6:0*/ __VdlyDim0__be_top__DOT__line_buf__v2;
    __VdlyDim0__be_top__DOT__line_buf__v2 = 0;
    CData/*7:0*/ __VdlyVal__be_top__DOT__line_buf__v3;
    __VdlyVal__be_top__DOT__line_buf__v3 = 0;
    CData/*6:0*/ __VdlyDim0__be_top__DOT__line_buf__v3;
    __VdlyDim0__be_top__DOT__line_buf__v3 = 0;
    CData/*7:0*/ __VdlyVal__be_top__DOT__line_buf__v4;
    __VdlyVal__be_top__DOT__line_buf__v4 = 0;
    CData/*6:0*/ __VdlyDim0__be_top__DOT__line_buf__v4;
    __VdlyDim0__be_top__DOT__line_buf__v4 = 0;
    CData/*6:0*/ __VdlyDim0__be_top__DOT__line_buf__v5;
    __VdlyDim0__be_top__DOT__line_buf__v5 = 0;
    CData/*0:0*/ __VdlySet__be_top__DOT__u_store__DOT__store__v0;
    __VdlySet__be_top__DOT__u_store__DOT__store__v0 = 0;
    CData/*5:0*/ __VdlyDim0__be_top__DOT__u_store__DOT__store__v64;
    __VdlyDim0__be_top__DOT__u_store__DOT__store__v64 = 0;
    CData/*0:0*/ __VdlySet__be_top__DOT__u_store__DOT__store__v64;
    __VdlySet__be_top__DOT__u_store__DOT__store__v64 = 0;
    CData/*7:0*/ __VdlyVal__be_top__DOT__u_store__DOT__store__v65;
    __VdlyVal__be_top__DOT__u_store__DOT__store__v65 = 0;
    CData/*5:0*/ __VdlyDim0__be_top__DOT__u_store__DOT__store__v65;
    __VdlyDim0__be_top__DOT__u_store__DOT__store__v65 = 0;
    CData/*1:0*/ __VdlyVal__be_top__DOT__u_store__DOT__store__v66;
    __VdlyVal__be_top__DOT__u_store__DOT__store__v66 = 0;
    CData/*5:0*/ __VdlyDim0__be_top__DOT__u_store__DOT__store__v66;
    __VdlyDim0__be_top__DOT__u_store__DOT__store__v66 = 0;
    CData/*1:0*/ __VdlyVal__be_top__DOT__u_store__DOT__store__v67;
    __VdlyVal__be_top__DOT__u_store__DOT__store__v67 = 0;
    CData/*5:0*/ __VdlyDim0__be_top__DOT__u_store__DOT__store__v67;
    __VdlyDim0__be_top__DOT__u_store__DOT__store__v67 = 0;
    SData/*15:0*/ __VdlyVal__be_top__DOT__u_store__DOT__store__v68;
    __VdlyVal__be_top__DOT__u_store__DOT__store__v68 = 0;
    CData/*5:0*/ __VdlyDim0__be_top__DOT__u_store__DOT__store__v68;
    __VdlyDim0__be_top__DOT__u_store__DOT__store__v68 = 0;
    VlWide<32>/*1023:0*/ __VdlyVal__be_top__DOT__u_store__DOT__store__v69;
    VL_ZERO_W(1024, __VdlyVal__be_top__DOT__u_store__DOT__store__v69);
    CData/*5:0*/ __VdlyDim0__be_top__DOT__u_store__DOT__store__v69;
    __VdlyDim0__be_top__DOT__u_store__DOT__store__v69 = 0;
    CData/*1:0*/ __VdlyVal__be_top__DOT__u_store__DOT__store__v70;
    __VdlyVal__be_top__DOT__u_store__DOT__store__v70 = 0;
    CData/*5:0*/ __VdlyDim0__be_top__DOT__u_store__DOT__store__v70;
    __VdlyDim0__be_top__DOT__u_store__DOT__store__v70 = 0;
    CData/*0:0*/ __VdlySet__be_top__DOT__u_store__DOT__store__v70;
    __VdlySet__be_top__DOT__u_store__DOT__store__v70 = 0;
    CData/*0:0*/ __VdlySet__be_top__DOT__u_store__DOT__store__v71;
    __VdlySet__be_top__DOT__u_store__DOT__store__v71 = 0;
    // Body
    __VdlySet__be_top__DOT__u_store__DOT__store__v0 = 0U;
    __VdlySet__be_top__DOT__u_store__DOT__store__v64 = 0U;
    __VdlySet__be_top__DOT__u_store__DOT__store__v70 = 0U;
    __VdlySet__be_top__DOT__u_store__DOT__store__v71 = 0U;
    __Vdly__be_top__DOT__wr_ptr_q = vlSelfRef.be_top__DOT__wr_ptr_q;
    __Vdly__be_top__DOT__next_msg_id_q = vlSelfRef.be_top__DOT__next_msg_id_q;
    __Vdly__be_top__DOT__click_target_row_q = vlSelfRef.be_top__DOT__click_target_row_q;
    __Vdly__be_top__DOT__click_vis_row_q = vlSelfRef.be_top__DOT__click_vis_row_q;
    __Vdly__be_top__DOT__click_vis_col_q = vlSelfRef.be_top__DOT__click_vis_col_q;
    __Vdly__be_top__DOT__click_target_col_q = vlSelfRef.be_top__DOT__click_target_col_q;
    __Vdly__be_top__DOT__emoji_complete_token_q = vlSelfRef.be_top__DOT__emoji_complete_token_q;
    __Vdly__be_top__DOT__enc_dst_q = vlSelfRef.be_top__DOT__enc_dst_q;
    __Vdly__be_top__DOT__pending_payload_q[0U] = vlSelfRef.be_top__DOT__pending_payload_q[0U];
    __Vdly__be_top__DOT__pending_payload_q[1U] = vlSelfRef.be_top__DOT__pending_payload_q[1U];
    __Vdly__be_top__DOT__pending_payload_q[2U] = vlSelfRef.be_top__DOT__pending_payload_q[2U];
    __Vdly__be_top__DOT__pending_payload_q[3U] = vlSelfRef.be_top__DOT__pending_payload_q[3U];
    __Vdly__be_top__DOT__pending_payload_q[4U] = vlSelfRef.be_top__DOT__pending_payload_q[4U];
    __Vdly__be_top__DOT__pending_payload_q[5U] = vlSelfRef.be_top__DOT__pending_payload_q[5U];
    __Vdly__be_top__DOT__pending_payload_q[6U] = vlSelfRef.be_top__DOT__pending_payload_q[6U];
    __Vdly__be_top__DOT__pending_payload_q[7U] = vlSelfRef.be_top__DOT__pending_payload_q[7U];
    __Vdly__be_top__DOT__pending_payload_q[8U] = vlSelfRef.be_top__DOT__pending_payload_q[8U];
    __Vdly__be_top__DOT__pending_payload_q[9U] = vlSelfRef.be_top__DOT__pending_payload_q[9U];
    __Vdly__be_top__DOT__pending_payload_q[10U] = vlSelfRef.be_top__DOT__pending_payload_q[10U];
    __Vdly__be_top__DOT__pending_payload_q[11U] = vlSelfRef.be_top__DOT__pending_payload_q[11U];
    __Vdly__be_top__DOT__pending_payload_q[12U] = vlSelfRef.be_top__DOT__pending_payload_q[12U];
    __Vdly__be_top__DOT__pending_payload_q[13U] = vlSelfRef.be_top__DOT__pending_payload_q[13U];
    __Vdly__be_top__DOT__pending_payload_q[14U] = vlSelfRef.be_top__DOT__pending_payload_q[14U];
    __Vdly__be_top__DOT__pending_payload_q[15U] = vlSelfRef.be_top__DOT__pending_payload_q[15U];
    __Vdly__be_top__DOT__pending_payload_q[16U] = vlSelfRef.be_top__DOT__pending_payload_q[16U];
    __Vdly__be_top__DOT__pending_payload_q[17U] = vlSelfRef.be_top__DOT__pending_payload_q[17U];
    __Vdly__be_top__DOT__pending_payload_q[18U] = vlSelfRef.be_top__DOT__pending_payload_q[18U];
    __Vdly__be_top__DOT__pending_payload_q[19U] = vlSelfRef.be_top__DOT__pending_payload_q[19U];
    __Vdly__be_top__DOT__pending_payload_q[20U] = vlSelfRef.be_top__DOT__pending_payload_q[20U];
    __Vdly__be_top__DOT__pending_payload_q[21U] = vlSelfRef.be_top__DOT__pending_payload_q[21U];
    __Vdly__be_top__DOT__pending_payload_q[22U] = vlSelfRef.be_top__DOT__pending_payload_q[22U];
    __Vdly__be_top__DOT__pending_payload_q[23U] = vlSelfRef.be_top__DOT__pending_payload_q[23U];
    __Vdly__be_top__DOT__pending_payload_q[24U] = vlSelfRef.be_top__DOT__pending_payload_q[24U];
    __Vdly__be_top__DOT__pending_payload_q[25U] = vlSelfRef.be_top__DOT__pending_payload_q[25U];
    __Vdly__be_top__DOT__pending_payload_q[26U] = vlSelfRef.be_top__DOT__pending_payload_q[26U];
    __Vdly__be_top__DOT__pending_payload_q[27U] = vlSelfRef.be_top__DOT__pending_payload_q[27U];
    __Vdly__be_top__DOT__pending_payload_q[28U] = vlSelfRef.be_top__DOT__pending_payload_q[28U];
    __Vdly__be_top__DOT__pending_payload_q[29U] = vlSelfRef.be_top__DOT__pending_payload_q[29U];
    __Vdly__be_top__DOT__pending_payload_q[30U] = vlSelfRef.be_top__DOT__pending_payload_q[30U];
    __Vdly__be_top__DOT__pending_payload_q[31U] = vlSelfRef.be_top__DOT__pending_payload_q[31U];
    __Vdly__be_top__DOT__pending_len_q = vlSelfRef.be_top__DOT__pending_len_q;
    __Vdly__be_top__DOT__shift_idx_q = vlSelfRef.be_top__DOT__shift_idx_q;
    __Vdly__be_top__DOT__emoji_complete_char_idx_q 
        = vlSelfRef.be_top__DOT__emoji_complete_char_idx_q;
    __Vdly__be_top__DOT__emoji_complete_token_len_q 
        = vlSelfRef.be_top__DOT__emoji_complete_token_len_q;
    __Vdly__be_top__DOT__disp_build_idx_q = vlSelfRef.be_top__DOT__disp_build_idx_q;
    __Vdly__be_top__DOT__input_newline_count_q = vlSelfRef.be_top__DOT__input_newline_count_q;
    __Vdly__be_top__DOT__click_walk_done_q = vlSelfRef.be_top__DOT__click_walk_done_q;
    __Vdly__be_top__DOT__disp_len_q = vlSelfRef.be_top__DOT__disp_len_q;
    __Vdly__be_top__DOT__emoji_suggest_active_q = vlSelfRef.be_top__DOT__emoji_suggest_active_q;
    __Vdly__be_top__DOT__menu_store_idx_q = vlSelfRef.be_top__DOT__menu_store_idx_q;
    __Vdly__be_top__DOT__cursor_pos_q = vlSelfRef.be_top__DOT__cursor_pos_q;
    __Vdly__be_top__DOT__quoted_msg_id_q = vlSelfRef.be_top__DOT__quoted_msg_id_q;
    __Vdly__be_top__DOT__popup_active_q = vlSelfRef.be_top__DOT__popup_active_q;
    __Vdly__be_top__DOT__has_quote_q = vlSelfRef.be_top__DOT__has_quote_q;
    __Vdly__be_top__DOT__len_q = vlSelfRef.be_top__DOT__len_q;
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.be_top__DOT__u_store__DOT__clear_en) {
            __VdlySet__be_top__DOT__u_store__DOT__store__v0 = 1U;
        } else {
            if (vlSelfRef.be_top__DOT__store_wr_en) {
                __VdlyDim0__be_top__DOT__u_store__DOT__store__v64 
                    = vlSelfRef.be_top__DOT__wr_ptr_q;
                __VdlySet__be_top__DOT__u_store__DOT__store__v64 = 1U;
                __VdlyVal__be_top__DOT__u_store__DOT__store__v65 
                    = vlSelfRef.be_top__DOT__store_wr_msg_id;
                __VdlyDim0__be_top__DOT__u_store__DOT__store__v65 
                    = vlSelfRef.be_top__DOT__wr_ptr_q;
                __VdlyVal__be_top__DOT__u_store__DOT__store__v66 
                    = vlSelfRef.be_top__DOT__store_wr_side;
                __VdlyDim0__be_top__DOT__u_store__DOT__store__v66 
                    = vlSelfRef.be_top__DOT__wr_ptr_q;
                __VdlyVal__be_top__DOT__u_store__DOT__store__v67 
                    = vlSelfRef.be_top__DOT__store_wr_status;
                __VdlyDim0__be_top__DOT__u_store__DOT__store__v67 
                    = vlSelfRef.be_top__DOT__wr_ptr_q;
                __VdlyVal__be_top__DOT__u_store__DOT__store__v68 
                    = vlSelfRef.be_top__DOT__store_wr_len;
                __VdlyDim0__be_top__DOT__u_store__DOT__store__v68 
                    = vlSelfRef.be_top__DOT__wr_ptr_q;
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[0U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[0U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[1U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[1U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[2U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[2U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[3U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[3U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[4U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[4U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[5U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[5U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[6U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[6U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[7U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[7U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[8U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[8U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[9U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[9U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[10U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[10U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[11U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[11U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[12U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[12U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[13U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[13U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[14U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[14U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[15U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[15U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[16U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[16U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[17U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[17U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[18U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[18U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[19U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[19U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[20U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[20U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[21U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[21U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[22U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[22U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[23U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[23U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[24U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[24U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[25U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[25U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[26U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[26U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[27U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[27U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[28U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[28U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[29U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[29U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[30U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[30U];
                __VdlyVal__be_top__DOT__u_store__DOT__store__v69[31U] 
                    = vlSelfRef.be_top__DOT__store_wr_payload[31U];
                __VdlyDim0__be_top__DOT__u_store__DOT__store__v69 
                    = vlSelfRef.be_top__DOT__wr_ptr_q;
            }
            if ((((0x22U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                  | ((IData)(vlSelfRef.cm_status_ready) 
                     & ((IData)(vlSelfRef.be_top__DOT__store_lookup_hit) 
                        & (IData)(vlSelfRef.be_top__DOT__accept_status)))) 
                 & (~ ((IData)(vlSelfRef.be_top__DOT__store_wr_en) 
                       & ((IData)(vlSelfRef.be_top__DOT__wr_ptr_q) 
                          == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__upd_idx)))))) {
                __VdlyVal__be_top__DOT__u_store__DOT__store__v70 
                    = (3U & (((0U == (IData)(vlSelfRef.cm_status_code))
                               ? 1U : 2U) | (- (IData)(
                                                       (0x22U 
                                                        == (IData)(vlSelfRef.be_top__DOT__state_q))))));
                __VdlyDim0__be_top__DOT__u_store__DOT__store__v70 
                    = vlSelfRef.be_top__DOT__u_store__DOT__upd_idx;
                __VdlySet__be_top__DOT__u_store__DOT__store__v70 = 1U;
            }
        }
    } else {
        __VdlySet__be_top__DOT__u_store__DOT__store__v71 = 1U;
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.be_top__DOT__enter_pulse_q = 0U;
        if (((5U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (0x16U == (IData)(vlSelfRef.be_top__DOT__state_d)))) {
            __Vdly__be_top__DOT__shift_idx_q = vlSelfRef.be_top__DOT__len_q;
        }
        if (((5U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (0x17U == (IData)(vlSelfRef.be_top__DOT__state_d)))) {
            __Vdly__be_top__DOT__shift_idx_q = (0x0000ffffU 
                                                & ((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                                                   - (IData)(1U)));
        }
        if ((0x16U == (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                 == (IData)(vlSelfRef.be_top__DOT__cursor_pos_q))) {
                __Vdly__be_top__DOT__len_q = (0x0000ffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.be_top__DOT__len_q)));
                __Vdly__be_top__DOT__cursor_pos_q = 
                    (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__cursor_pos_q)));
                if ((0x0aU == (IData)(vlSelfRef.be_top__DOT__last_event_ascii_q))) {
                    __Vdly__be_top__DOT__input_newline_count_q 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.be_top__DOT__input_newline_count_q)));
                }
                __VdlyVal__be_top__DOT__line_buf__v0 
                    = vlSelfRef.be_top__DOT__last_event_ascii_q;
                __VdlyDim0__be_top__DOT__line_buf__v0 
                    = (0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q));
                vlSelfRef.__VdlyCommitQueuebe_top__DOT__line_buf.enqueue(__VdlyVal__be_top__DOT__line_buf__v0, (IData)(__VdlyDim0__be_top__DOT__line_buf__v0));
            } else {
                __VdlyVal__be_top__DOT__line_buf__v1 
                    = vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                                     - (IData)(1U)))];
                __VdlyDim0__be_top__DOT__line_buf__v1 
                    = (0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q));
                vlSelfRef.__VdlyCommitQueuebe_top__DOT__line_buf.enqueue(__VdlyVal__be_top__DOT__line_buf__v1, (IData)(__VdlyDim0__be_top__DOT__line_buf__v1));
                __Vdly__be_top__DOT__shift_idx_q = 
                    (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                                    - (IData)(1U)));
            }
        }
        if ((0x17U == (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                 >= (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__len_q) 
                                    - (IData)(1U))))) {
                __Vdly__be_top__DOT__len_q = (0x0000ffffU 
                                              & ((IData)(vlSelfRef.be_top__DOT__len_q) 
                                                 - (IData)(1U)));
                __Vdly__be_top__DOT__cursor_pos_q = 
                    (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                                    - (IData)(1U)));
                if (((IData)(vlSelfRef.be_top__DOT__delete_was_newline_q) 
                     & (0U != (IData)(vlSelfRef.be_top__DOT__input_newline_count_q)))) {
                    __Vdly__be_top__DOT__input_newline_count_q 
                        = (0x0000001fU & ((IData)(vlSelfRef.be_top__DOT__input_newline_count_q) 
                                          - (IData)(1U)));
                }
            } else {
                __VdlyVal__be_top__DOT__line_buf__v2 
                    = vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__shift_idx_q)))];
                __VdlyDim0__be_top__DOT__line_buf__v2 
                    = (0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q));
                vlSelfRef.__VdlyCommitQueuebe_top__DOT__line_buf.enqueue(__VdlyVal__be_top__DOT__line_buf__v2, (IData)(__VdlyDim0__be_top__DOT__line_buf__v2));
                __Vdly__be_top__DOT__shift_idx_q = 
                    (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__shift_idx_q)));
            }
        }
        if ((0x18U == (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (((IData)(vlSelfRef.be_top__DOT__enc_src_q) 
                 < (IData)(vlSelfRef.be_top__DOT__len_q))) {
                vlSelfRef.be_top__DOT__enc_src_q = 
                    (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__enc_src_q) 
                                    + (IData)(vlSelfRef.be_top__DOT__enc_src_delta)));
                VL_ASSIGNSEL_WI(1024, 8, (0x000003ffU 
                                          & VL_SHIFTL_III(10,32,32, (IData)(vlSelfRef.be_top__DOT__enc_dst_q), 3U)), __Vdly__be_top__DOT__pending_payload_q, vlSelfRef.be_top__DOT__enc_emit_byte);
                __Vdly__be_top__DOT__enc_dst_q = (0x0000ffffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.be_top__DOT__enc_dst_q)));
            } else {
                __Vdly__be_top__DOT__len_q = 0U;
                __Vdly__be_top__DOT__cursor_pos_q = 0U;
                __Vdly__be_top__DOT__input_newline_count_q = 0U;
                __Vdly__be_top__DOT__wr_ptr_q = (0x0000003fU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.be_top__DOT__wr_ptr_q)));
                __Vdly__be_top__DOT__next_msg_id_q 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__next_msg_id_q)));
                __Vdly__be_top__DOT__pending_len_q 
                    = vlSelfRef.be_top__DOT__enc_dst_q;
            }
        }
        if (((5U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (0x19U == (IData)(vlSelfRef.be_top__DOT__state_d)))) {
            vlSelfRef.be_top__DOT__unnamedblk8__DOT__raw_col 
                = vlSelfRef.be_top__DOT__click_raw_col_q;
            vlSelfRef.be_top__DOT__unnamedblk8__DOT__buf_row 
                = (0x0000003fU & (((IData)(vlSelfRef.be_top__DOT__click_screen_row_q) 
                                   - (IData)(0x20U)) 
                                  + (IData)(vlSelfRef.fe_input_scroll_offset)));
            __Vdly__be_top__DOT__click_target_row_q 
                = (0x0000000fU & (IData)(vlSelfRef.be_top__DOT__unnamedblk8__DOT__buf_row));
            __Vdly__be_top__DOT__shift_idx_q = 0U;
            __Vdly__be_top__DOT__click_vis_row_q = 0U;
            __Vdly__be_top__DOT__click_vis_col_q = 0U;
            __Vdly__be_top__DOT__click_walk_done_q = 0U;
            __Vdly__be_top__DOT__click_target_col_q 
                = (0x0000007fU & ((0U == (IData)(vlSelfRef.be_top__DOT__unnamedblk8__DOT__buf_row))
                                   ? ((2U < (IData)(vlSelfRef.be_top__DOT__unnamedblk8__DOT__raw_col))
                                       ? ((IData)(vlSelfRef.be_top__DOT__unnamedblk8__DOT__raw_col) 
                                          - (IData)(2U))
                                       : 0U) : (IData)(vlSelfRef.be_top__DOT__unnamedblk8__DOT__raw_col)));
        }
        if (((0x19U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (~ (IData)(vlSelfRef.be_top__DOT__click_walk_done_q)))) {
            if (((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                 >= (IData)(vlSelfRef.be_top__DOT__len_q))) {
                __Vdly__be_top__DOT__cursor_pos_q = vlSelfRef.be_top__DOT__len_q;
                __Vdly__be_top__DOT__click_walk_done_q = 1U;
            } else {
                vlSelfRef.be_top__DOT__unnamedblk9__DOT__cur_byte 
                    = vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q))];
                if ((((IData)(vlSelfRef.be_top__DOT__click_vis_row_q) 
                      == (IData)(vlSelfRef.be_top__DOT__click_target_row_q)) 
                     & ((IData)(vlSelfRef.be_top__DOT__click_vis_col_q) 
                        >= (IData)(vlSelfRef.be_top__DOT__click_target_col_q)))) {
                    __Vdly__be_top__DOT__cursor_pos_q 
                        = vlSelfRef.be_top__DOT__shift_idx_q;
                    __Vdly__be_top__DOT__click_walk_done_q = 1U;
                } else {
                    if ((0x0aU == (IData)(vlSelfRef.be_top__DOT__unnamedblk9__DOT__cur_byte))) {
                        __Vdly__be_top__DOT__click_vis_row_q 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.be_top__DOT__click_vis_row_q)));
                        __Vdly__be_top__DOT__click_vis_col_q = 0U;
                    } else {
                        __Vdly__be_top__DOT__click_vis_col_q 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.be_top__DOT__click_vis_col_q)));
                        if ((0x5fU == (IData)(vlSelfRef.be_top__DOT__click_vis_col_q))) {
                            __Vdly__be_top__DOT__click_vis_row_q 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.be_top__DOT__click_vis_row_q)));
                            __Vdly__be_top__DOT__click_vis_col_q = 0U;
                        }
                    }
                    __Vdly__be_top__DOT__shift_idx_q 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.be_top__DOT__shift_idx_q)));
                }
            }
        }
        if (vlSelfRef.be_top__DOT__accept_username_frame) {
            if (vlSelfRef.be_top__DOT__peer_name_changed) {
                __Vdly__be_top__DOT__wr_ptr_q = 0U;
                __Vdly__be_top__DOT__next_msg_id_q = 0U;
            }
            vlSelfRef.be_top__DOT__peer_name_len_q 
                = vlSelfRef.be_top__DOT__rx_name_len_clamped;
            vlSelfRef.be_top__DOT__peer_name_q[0U] 
                = ((0xffffff00U & vlSelfRef.be_top__DOT__peer_name_q[0U]) 
                   | (VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                       ? (0x000000ffU & vlSelfRef.cm_rx_payload[0U])
                       : 0U));
            vlSelfRef.be_top__DOT__peer_name_q[0U] 
                = ((0xffff00ffU & vlSelfRef.be_top__DOT__peer_name_q[0U]) 
                   | ((VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (0x000000ffU & (vlSelfRef.cm_rx_payload[0U] 
                                          >> 8U)) : 0U) 
                      << 8U));
            vlSelfRef.be_top__DOT__peer_name_q[0U] 
                = ((0xff00ffffU & vlSelfRef.be_top__DOT__peer_name_q[0U]) 
                   | ((VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (0x000000ffU & (vlSelfRef.cm_rx_payload[0U] 
                                          >> 0x00000010U))
                        : 0U) << 0x00000010U));
            vlSelfRef.be_top__DOT__peer_name_q[0U] 
                = ((0x00ffffffU & vlSelfRef.be_top__DOT__peer_name_q[0U]) 
                   | ((VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (vlSelfRef.cm_rx_payload[0U] 
                           >> 0x00000018U) : 0U) << 0x00000018U));
            vlSelfRef.be_top__DOT__peer_name_q[1U] 
                = ((0xffffff00U & vlSelfRef.be_top__DOT__peer_name_q[1U]) 
                   | (VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                       ? (0x000000ffU & vlSelfRef.cm_rx_payload[1U])
                       : 0U));
            vlSelfRef.be_top__DOT__peer_name_q[1U] 
                = ((0xffff00ffU & vlSelfRef.be_top__DOT__peer_name_q[1U]) 
                   | ((VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (0x000000ffU & (vlSelfRef.cm_rx_payload[1U] 
                                          >> 8U)) : 0U) 
                      << 8U));
            vlSelfRef.be_top__DOT__peer_name_q[1U] 
                = ((0xff00ffffU & vlSelfRef.be_top__DOT__peer_name_q[1U]) 
                   | ((VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (0x000000ffU & (vlSelfRef.cm_rx_payload[1U] 
                                          >> 0x00000010U))
                        : 0U) << 0x00000010U));
            vlSelfRef.be_top__DOT__peer_name_q[1U] 
                = ((0x00ffffffU & vlSelfRef.be_top__DOT__peer_name_q[1U]) 
                   | ((VL_LTS_III(32, 7U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (vlSelfRef.cm_rx_payload[1U] 
                           >> 0x00000018U) : 0U) << 0x00000018U));
            vlSelfRef.be_top__DOT__peer_name_q[2U] 
                = ((0xffffff00U & vlSelfRef.be_top__DOT__peer_name_q[2U]) 
                   | (VL_LTS_III(32, 8U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                       ? (0x000000ffU & vlSelfRef.cm_rx_payload[2U])
                       : 0U));
            vlSelfRef.be_top__DOT__peer_name_q[2U] 
                = ((0xffff00ffU & vlSelfRef.be_top__DOT__peer_name_q[2U]) 
                   | ((VL_LTS_III(32, 9U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (0x000000ffU & (vlSelfRef.cm_rx_payload[2U] 
                                          >> 8U)) : 0U) 
                      << 8U));
            vlSelfRef.be_top__DOT__peer_name_q[2U] 
                = ((0xff00ffffU & vlSelfRef.be_top__DOT__peer_name_q[2U]) 
                   | ((VL_LTS_III(32, 0x0000000aU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (0x000000ffU & (vlSelfRef.cm_rx_payload[2U] 
                                          >> 0x00000010U))
                        : 0U) << 0x00000010U));
            vlSelfRef.be_top__DOT__peer_name_q[2U] 
                = ((0x00ffffffU & vlSelfRef.be_top__DOT__peer_name_q[2U]) 
                   | ((VL_LTS_III(32, 0x0000000bU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (vlSelfRef.cm_rx_payload[2U] 
                           >> 0x00000018U) : 0U) << 0x00000018U));
            vlSelfRef.be_top__DOT__peer_name_q[3U] 
                = ((0xffffff00U & vlSelfRef.be_top__DOT__peer_name_q[3U]) 
                   | (VL_LTS_III(32, 0x0000000cU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                       ? (0x000000ffU & vlSelfRef.cm_rx_payload[3U])
                       : 0U));
            vlSelfRef.be_top__DOT__peer_name_q[3U] 
                = ((0xffff00ffU & vlSelfRef.be_top__DOT__peer_name_q[3U]) 
                   | ((VL_LTS_III(32, 0x0000000dU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (0x000000ffU & (vlSelfRef.cm_rx_payload[3U] 
                                          >> 8U)) : 0U) 
                      << 8U));
            vlSelfRef.be_top__DOT__peer_name_q[3U] 
                = ((0xff00ffffU & vlSelfRef.be_top__DOT__peer_name_q[3U]) 
                   | ((VL_LTS_III(32, 0x0000000eU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (0x000000ffU & (vlSelfRef.cm_rx_payload[3U] 
                                          >> 0x00000010U))
                        : 0U) << 0x00000010U));
            vlSelfRef.be_top__DOT__peer_name_q[3U] 
                = ((0x00ffffffU & vlSelfRef.be_top__DOT__peer_name_q[3U]) 
                   | ((VL_LTS_III(32, 0x0000000fU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped))
                        ? (vlSelfRef.cm_rx_payload[3U] 
                           >> 0x00000018U) : 0U) << 0x00000018U));
        }
        if ((5U == (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (vlSelfRef.be_top__DOT__accept_status) {
                vlSelfRef.be_top__DOT__status_msg_id_q 
                    = vlSelfRef.cm_status_msg_id;
                vlSelfRef.be_top__DOT__status_status_q 
                    = ((0U == (IData)(vlSelfRef.cm_status_code))
                        ? 1U : 2U);
            } else if (((IData)(vlSelfRef.be_top__DOT__accept_rx) 
                        & (0U == (IData)(vlSelfRef.cm_rx_frame_type)))) {
                vlSelfRef.be_top__DOT__rx_seq_q = vlSelfRef.cm_rx_seq;
                vlSelfRef.be_top__DOT__rx_store_idx_q 
                    = vlSelfRef.be_top__DOT__wr_ptr_q;
                vlSelfRef.be_top__DOT__rx_len_q = vlSelfRef.be_top__DOT__rx_len_clamped;
                vlSelfRef.be_top__DOT__rx_payload_q[0U] 
                    = vlSelfRef.cm_rx_payload[0U];
                vlSelfRef.be_top__DOT__rx_payload_q[1U] 
                    = vlSelfRef.cm_rx_payload[1U];
                vlSelfRef.be_top__DOT__rx_payload_q[2U] 
                    = vlSelfRef.cm_rx_payload[2U];
                vlSelfRef.be_top__DOT__rx_payload_q[3U] 
                    = vlSelfRef.cm_rx_payload[3U];
                vlSelfRef.be_top__DOT__rx_payload_q[4U] 
                    = vlSelfRef.cm_rx_payload[4U];
                vlSelfRef.be_top__DOT__rx_payload_q[5U] 
                    = vlSelfRef.cm_rx_payload[5U];
                vlSelfRef.be_top__DOT__rx_payload_q[6U] 
                    = vlSelfRef.cm_rx_payload[6U];
                vlSelfRef.be_top__DOT__rx_payload_q[7U] 
                    = vlSelfRef.cm_rx_payload[7U];
                vlSelfRef.be_top__DOT__rx_payload_q[8U] 
                    = vlSelfRef.cm_rx_payload[8U];
                vlSelfRef.be_top__DOT__rx_payload_q[9U] 
                    = vlSelfRef.cm_rx_payload[9U];
                vlSelfRef.be_top__DOT__rx_payload_q[10U] 
                    = vlSelfRef.cm_rx_payload[10U];
                vlSelfRef.be_top__DOT__rx_payload_q[11U] 
                    = vlSelfRef.cm_rx_payload[11U];
                vlSelfRef.be_top__DOT__rx_payload_q[12U] 
                    = vlSelfRef.cm_rx_payload[12U];
                vlSelfRef.be_top__DOT__rx_payload_q[13U] 
                    = vlSelfRef.cm_rx_payload[13U];
                vlSelfRef.be_top__DOT__rx_payload_q[14U] 
                    = vlSelfRef.cm_rx_payload[14U];
                vlSelfRef.be_top__DOT__rx_payload_q[15U] 
                    = vlSelfRef.cm_rx_payload[15U];
                vlSelfRef.be_top__DOT__rx_payload_q[16U] 
                    = vlSelfRef.cm_rx_payload[16U];
                vlSelfRef.be_top__DOT__rx_payload_q[17U] 
                    = vlSelfRef.cm_rx_payload[17U];
                vlSelfRef.be_top__DOT__rx_payload_q[18U] 
                    = vlSelfRef.cm_rx_payload[18U];
                vlSelfRef.be_top__DOT__rx_payload_q[19U] 
                    = vlSelfRef.cm_rx_payload[19U];
                vlSelfRef.be_top__DOT__rx_payload_q[20U] 
                    = vlSelfRef.cm_rx_payload[20U];
                vlSelfRef.be_top__DOT__rx_payload_q[21U] 
                    = vlSelfRef.cm_rx_payload[21U];
                vlSelfRef.be_top__DOT__rx_payload_q[22U] 
                    = vlSelfRef.cm_rx_payload[22U];
                vlSelfRef.be_top__DOT__rx_payload_q[23U] 
                    = vlSelfRef.cm_rx_payload[23U];
                vlSelfRef.be_top__DOT__rx_payload_q[24U] 
                    = vlSelfRef.cm_rx_payload[24U];
                vlSelfRef.be_top__DOT__rx_payload_q[25U] 
                    = vlSelfRef.cm_rx_payload[25U];
                vlSelfRef.be_top__DOT__rx_payload_q[26U] 
                    = vlSelfRef.cm_rx_payload[26U];
                vlSelfRef.be_top__DOT__rx_payload_q[27U] 
                    = vlSelfRef.cm_rx_payload[27U];
                vlSelfRef.be_top__DOT__rx_payload_q[28U] 
                    = vlSelfRef.cm_rx_payload[28U];
                vlSelfRef.be_top__DOT__rx_payload_q[29U] 
                    = vlSelfRef.cm_rx_payload[29U];
                vlSelfRef.be_top__DOT__rx_payload_q[30U] 
                    = vlSelfRef.cm_rx_payload[30U];
                vlSelfRef.be_top__DOT__rx_payload_q[31U] 
                    = vlSelfRef.cm_rx_payload[31U];
                if ((1U == (0x000000ffU & vlSelfRef.cm_rx_payload[0U]))) {
                    __Vdly__be_top__DOT__pending_payload_q[0U] 
                        = vlSelfRef.cm_rx_payload[0U];
                    __Vdly__be_top__DOT__pending_payload_q[1U] 
                        = vlSelfRef.cm_rx_payload[1U];
                    __Vdly__be_top__DOT__pending_payload_q[2U] 
                        = vlSelfRef.cm_rx_payload[2U];
                    __Vdly__be_top__DOT__pending_payload_q[3U] 
                        = vlSelfRef.cm_rx_payload[3U];
                    __Vdly__be_top__DOT__pending_payload_q[4U] 
                        = vlSelfRef.cm_rx_payload[4U];
                    __Vdly__be_top__DOT__pending_payload_q[5U] 
                        = vlSelfRef.cm_rx_payload[5U];
                    __Vdly__be_top__DOT__pending_payload_q[6U] 
                        = vlSelfRef.cm_rx_payload[6U];
                    __Vdly__be_top__DOT__pending_payload_q[7U] 
                        = vlSelfRef.cm_rx_payload[7U];
                    __Vdly__be_top__DOT__pending_payload_q[8U] 
                        = vlSelfRef.cm_rx_payload[8U];
                    __Vdly__be_top__DOT__pending_payload_q[9U] 
                        = vlSelfRef.cm_rx_payload[9U];
                    __Vdly__be_top__DOT__pending_payload_q[10U] 
                        = vlSelfRef.cm_rx_payload[10U];
                    __Vdly__be_top__DOT__pending_payload_q[11U] 
                        = vlSelfRef.cm_rx_payload[11U];
                    __Vdly__be_top__DOT__pending_payload_q[12U] 
                        = vlSelfRef.cm_rx_payload[12U];
                    __Vdly__be_top__DOT__pending_payload_q[13U] 
                        = vlSelfRef.cm_rx_payload[13U];
                    __Vdly__be_top__DOT__pending_payload_q[14U] 
                        = vlSelfRef.cm_rx_payload[14U];
                    __Vdly__be_top__DOT__pending_payload_q[15U] 
                        = vlSelfRef.cm_rx_payload[15U];
                    __Vdly__be_top__DOT__pending_payload_q[16U] 
                        = vlSelfRef.cm_rx_payload[16U];
                    __Vdly__be_top__DOT__pending_payload_q[17U] 
                        = vlSelfRef.cm_rx_payload[17U];
                    __Vdly__be_top__DOT__pending_payload_q[18U] 
                        = vlSelfRef.cm_rx_payload[18U];
                    __Vdly__be_top__DOT__pending_payload_q[19U] 
                        = vlSelfRef.cm_rx_payload[19U];
                    __Vdly__be_top__DOT__pending_payload_q[20U] 
                        = vlSelfRef.cm_rx_payload[20U];
                    __Vdly__be_top__DOT__pending_payload_q[21U] 
                        = vlSelfRef.cm_rx_payload[21U];
                    __Vdly__be_top__DOT__pending_payload_q[22U] 
                        = vlSelfRef.cm_rx_payload[22U];
                    __Vdly__be_top__DOT__pending_payload_q[23U] 
                        = vlSelfRef.cm_rx_payload[23U];
                    __Vdly__be_top__DOT__pending_payload_q[24U] 
                        = vlSelfRef.cm_rx_payload[24U];
                    __Vdly__be_top__DOT__pending_payload_q[25U] 
                        = vlSelfRef.cm_rx_payload[25U];
                    __Vdly__be_top__DOT__pending_payload_q[26U] 
                        = vlSelfRef.cm_rx_payload[26U];
                    __Vdly__be_top__DOT__pending_payload_q[27U] 
                        = vlSelfRef.cm_rx_payload[27U];
                    __Vdly__be_top__DOT__pending_payload_q[28U] 
                        = vlSelfRef.cm_rx_payload[28U];
                    __Vdly__be_top__DOT__pending_payload_q[29U] 
                        = vlSelfRef.cm_rx_payload[29U];
                    __Vdly__be_top__DOT__pending_payload_q[30U] 
                        = vlSelfRef.cm_rx_payload[30U];
                    __Vdly__be_top__DOT__pending_payload_q[31U] 
                        = vlSelfRef.cm_rx_payload[31U];
                    __Vdly__be_top__DOT__pending_len_q 
                        = vlSelfRef.be_top__DOT__rx_len_clamped;
                    __Vdly__be_top__DOT__quoted_msg_id_q 
                        = (0x000000ffU & (vlSelfRef.cm_rx_payload[0U] 
                                          >> 8U));
                    vlSelfRef.be_top__DOT__quoted_side_q = 0U;
                    vlSelfRef.be_top__DOT__disp_for_remote_q = 1U;
                    __Vdly__be_top__DOT__disp_len_q = 0U;
                } else {
                    __Vdly__be_top__DOT__disp_len_q = 0U;
                    vlSelfRef.be_top__DOT__disp_for_remote_q = 0U;
                }
                __Vdly__be_top__DOT__wr_ptr_q = (0x0000003fU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.be_top__DOT__wr_ptr_q)));
            } else if ((((IData)(vlSelfRef.be_top__DOT__accept_rx) 
                         & (7U == (IData)(vlSelfRef.cm_rx_frame_type))) 
                        & (IData)(vlSelfRef.be_top__DOT__store_lookup_hit))) {
                vlSelfRef.be_top__DOT__recall_msg_id_q 
                    = vlSelfRef.cm_rx_seq;
                vlSelfRef.be_top__DOT__recall_store_idx_q 
                    = vlSelfRef.be_top__DOT__store_lookup_idx;
                vlSelfRef.be_top__DOT__recall_side_q = 1U;
                vlSelfRef.be_top__DOT__recall_send_q = 0U;
            } else if (vlSelfRef.be_top__DOT__accept_io) {
                if ((4U & (IData)(vlSelfRef.io_key_type))) {
                    if ((1U & (~ ((IData)(vlSelfRef.io_key_type) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.io_key_type))) {
                            if (vlSelfRef.be_top__DOT__popup_active_q) {
                                __Vdly__be_top__DOT__popup_active_q = 0U;
                                vlSelfRef.be_top__DOT__popup_type_q = 0U;
                            } else if (vlSelfRef.be_top__DOT__has_quote_q) {
                                __Vdly__be_top__DOT__has_quote_q = 0U;
                                __Vdly__be_top__DOT__quoted_msg_id_q = 0U;
                                vlSelfRef.be_top__DOT__quoted_side_q = 0U;
                            }
                        } else if (((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                                    < (IData)(vlSelfRef.be_top__DOT__len_q))) {
                            __Vdly__be_top__DOT__cursor_pos_q 
                                = (0x0000ffffU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.be_top__DOT__cursor_pos_q)));
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.io_key_type))) {
                    if ((1U & (IData)(vlSelfRef.io_key_type))) {
                        if ((0U != (IData)(vlSelfRef.be_top__DOT__cursor_pos_q))) {
                            __Vdly__be_top__DOT__cursor_pos_q 
                                = (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                                                  - (IData)(1U)));
                        }
                    } else if ((0U != (IData)(vlSelfRef.be_top__DOT__cursor_pos_q))) {
                        vlSelfRef.be_top__DOT__delete_was_newline_q 
                            = (0x0aU == vlSelfRef.be_top__DOT__line_buf
                               [(0x0000007fU & ((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                                                - (IData)(1U)))]);
                    }
                } else if ((1U & (IData)(vlSelfRef.io_key_type))) {
                    if ((0U != (IData)(vlSelfRef.be_top__DOT__len_q))) {
                        vlSelfRef.be_top__DOT__enc_src_q = 0U;
                        vlSelfRef.be_top__DOT__pending_msg_id_q 
                            = vlSelfRef.be_top__DOT__next_msg_id_q;
                        vlSelfRef.be_top__DOT__pending_store_idx_q 
                            = vlSelfRef.be_top__DOT__wr_ptr_q;
                        VL_ASSIGN_W(1024, __Vdly__be_top__DOT__pending_payload_q, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
                        vlSelfRef.be_top__DOT__enter_pulse_q = 1U;
                        if (vlSelfRef.be_top__DOT__has_quote_q) {
                            __Vdly__be_top__DOT__enc_dst_q = 2U;
                            __Vdly__be_top__DOT__pending_payload_q[0U] 
                                = (1U | ((0xffff0000U 
                                          & __Vdly__be_top__DOT__pending_payload_q[0U]) 
                                         | ((IData)(vlSelfRef.be_top__DOT__quoted_msg_id_q) 
                                            << 8U)));
                        } else {
                            __Vdly__be_top__DOT__enc_dst_q = 0U;
                        }
                    }
                } else if ((5U == (IData)(vlSelfRef.io_key_ascii))) {
                    __Vdly__be_top__DOT__popup_active_q = 1U;
                    vlSelfRef.be_top__DOT__popup_type_q = 2U;
                    vlSelfRef.be_top__DOT__popup_x_q = 0x00f0U;
                    vlSelfRef.be_top__DOT__popup_y_q = 0x01a8U;
                } else if (vlSelfRef.be_top__DOT__key_char_insert_allowed) {
                    vlSelfRef.be_top__DOT__last_event_ascii_q 
                        = vlSelfRef.io_key_ascii;
                }
            } else if (vlSelfRef.be_top__DOT__accept_mouse_click) {
                if (vlSelfRef.be_top__DOT__click_is_right_q) {
                    __Vdly__be_top__DOT__popup_active_q = 0U;
                    vlSelfRef.be_top__DOT__popup_type_q = 0U;
                    if (vlSelfRef.be_top__DOT__click_in_hist_bubble) {
                        __Vdly__be_top__DOT__popup_active_q = 1U;
                        vlSelfRef.be_top__DOT__popup_type_q = 1U;
                        vlSelfRef.be_top__DOT__popup_x_q 
                            = vlSelfRef.be_top__DOT__click_x_q;
                        vlSelfRef.be_top__DOT__popup_y_q 
                            = vlSelfRef.be_top__DOT__click_y_q;
                        __Vdly__be_top__DOT__menu_store_idx_q 
                            = (0x0000003fU & ((((0U 
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
                                                                * (IData)(vlSelfRef.be_top__DOT__click_hist_slot))))))));
                        vlSelfRef.be_top__DOT__emoji_suggest_tracking_q = 0U;
                        __Vdly__be_top__DOT__emoji_suggest_active_q = 0U;
                        vlSelfRef.be_top__DOT__emoji_suggest_count_q = 0U;
                        vlSelfRef.be_top__DOT__emoji_suggest_ids_q = 0ULL;
                        vlSelfRef.be_top__DOT__emoji_suggest_anchor_q = 0U;
                    }
                } else if (vlSelfRef.be_top__DOT__popup_active_q) {
                    if ((((IData)(vlSelfRef.be_top__DOT__click_in_msg_menu) 
                          & (IData)(vlSelfRef.be_top__DOT__click_msg_menu_quote)) 
                         & (IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_valid))) {
                        __Vdly__be_top__DOT__has_quote_q = 1U;
                        __Vdly__be_top__DOT__quoted_msg_id_q 
                            = vlSelfRef.be_top__DOT__u_store__DOT__rd2_msg_id;
                        vlSelfRef.be_top__DOT__quoted_side_q 
                            = vlSelfRef.be_top__DOT__u_store__DOT__rd2_side;
                    } else if ((((((IData)(vlSelfRef.be_top__DOT__click_in_msg_menu) 
                                   & (IData)(vlSelfRef.be_top__DOT__click_msg_menu_recall)) 
                                  & (IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_valid)) 
                                 & (0U == (IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_side))) 
                                & (3U != (IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_status)))) {
                        vlSelfRef.be_top__DOT__recall_msg_id_q 
                            = vlSelfRef.be_top__DOT__u_store__DOT__rd2_msg_id;
                        vlSelfRef.be_top__DOT__recall_store_idx_q 
                            = vlSelfRef.be_top__DOT__menu_store_idx_q;
                        vlSelfRef.be_top__DOT__recall_side_q = 0U;
                        vlSelfRef.be_top__DOT__recall_send_q = 1U;
                    } else if (vlSelfRef.be_top__DOT__click_in_sticker_picker) {
                        vlSelfRef.be_top__DOT__pending_msg_id_q 
                            = vlSelfRef.be_top__DOT__next_msg_id_q;
                        vlSelfRef.be_top__DOT__pending_store_idx_q 
                            = vlSelfRef.be_top__DOT__wr_ptr_q;
                        __Vdly__be_top__DOT__pending_len_q = 1U;
                        VL_ASSIGN_W(1024, __Vdly__be_top__DOT__pending_payload_q, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
                        __Vdly__be_top__DOT__pending_payload_q[0U] 
                            = ((0xffffff00U & __Vdly__be_top__DOT__pending_payload_q[0U]) 
                               | ((0x00000200U & (IData)(vlSelfRef.be_top__DOT__click_popup_dx))
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
                                                    : 0x80U)))));
                    }
                    __Vdly__be_top__DOT__popup_active_q = 0U;
                    vlSelfRef.be_top__DOT__popup_type_q = 0U;
                } else if (vlSelfRef.be_top__DOT__emoji_suggest_active_q) {
                    if (((IData)(vlSelfRef.be_top__DOT__click_in_emoji_suggest) 
                         & (IData)(vlSelfRef.be_top__DOT__click_emoji_fits))) {
                        __Vdly__be_top__DOT__emoji_complete_token_q 
                            = vlSelfRef.be_top__DOT__click_emoji_token_id;
                        __Vdly__be_top__DOT__emoji_complete_char_idx_q 
                            = vlSelfRef.be_top__DOT__click_emoji_prefix_len;
                        __Vdly__be_top__DOT__emoji_complete_token_len_q 
                            = vlSelfRef.be_top__DOT__click_emoji_token_len;
                        __Vdly__be_top__DOT__shift_idx_q 
                            = vlSelfRef.be_top__DOT__len_q;
                    }
                    vlSelfRef.be_top__DOT__emoji_suggest_tracking_q = 0U;
                    __Vdly__be_top__DOT__emoji_suggest_active_q = 0U;
                    vlSelfRef.be_top__DOT__emoji_suggest_count_q = 0U;
                    vlSelfRef.be_top__DOT__emoji_suggest_ids_q = 0ULL;
                    vlSelfRef.be_top__DOT__emoji_suggest_anchor_q = 0U;
                }
            }
        }
        if ((0x1bU == (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                 == (IData)(vlSelfRef.be_top__DOT__cursor_pos_q))) {
                __Vfunc_emoji_token_char__5__char_idx 
                    = (0x0000000fU & (IData)(vlSelfRef.be_top__DOT__emoji_complete_char_idx_q));
                __Vfunc_emoji_token_char__5__token_id 
                    = vlSelfRef.be_top__DOT__emoji_complete_token_q;
                __Vdly__be_top__DOT__cursor_pos_q = 
                    (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__cursor_pos_q)));
                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x20U;
                if ((8U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                    if ((4U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                        if ((2U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                            if ((1U & (~ (IData)(__Vfunc_emoji_token_char__5__token_id)))) {
                                if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                              >> 3U)))) {
                                    if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                        if ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                            if ((1U 
                                                 & (~ (IData)(__Vfunc_emoji_token_char__5__char_idx)))) {
                                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x6fU;
                                            }
                                        } else {
                                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                                = (
                                                   (1U 
                                                    & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                                    ? 0x75U
                                                    : 0x72U);
                                        }
                                    } else {
                                        vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                            = ((2U 
                                                & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                                    ? 0x69U
                                                    : 0x61U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                                    ? 0x6dU
                                                    : 0x5cU));
                                    }
                                }
                            }
                        } else if ((1U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                            if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                          >> 3U)))) {
                                if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                    if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(__Vfunc_emoji_token_char__5__char_idx)))) {
                                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x65U;
                                        }
                                    }
                                } else {
                                    vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                        = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? ((1U 
                                                & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                                ? 0x67U
                                                : 0x6fU)
                                            : ((1U 
                                                & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                                ? 0x64U
                                                : 0x5cU));
                                }
                            }
                        } else if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                             >> 3U)))) {
                            if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(__Vfunc_emoji_token_char__5__char_idx)))) {
                                        vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x6eU;
                                    }
                                }
                            } else {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                    = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x77U
                                            : 0x6fU)
                                        : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x64U
                                            : 0x5cU));
                            }
                        }
                    } else if ((2U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                        if ((1U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                            if ((0U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x5cU;
                            } else if ((1U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x75U;
                            } else if ((2U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x70U;
                            }
                            if ((1U & (~ VL_ONEHOT_I(
                                                     (((2U 
                                                        == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                       << 2U) 
                                                      | (((1U 
                                                           == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                          << 1U) 
                                                         | (0U 
                                                            == (IData)(__Vfunc_emoji_token_char__5__char_idx)))))))) {
                                if ((0U != (((2U == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                             << 2U) 
                                            | (((1U 
                                                 == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                << 1U) 
                                               | (0U 
                                                  == (IData)(__Vfunc_emoji_token_char__5__char_idx)))))) {
                                    if (VL_UNLIKELY((
                                                     vlSymsp->_vm_contextp__->assertOn()))) {
                                        VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                                     , '#',64,VL_TIME_UNITED_Q(1)
                                                     , '#',4,(IData)(__Vfunc_emoji_token_char__5__char_idx));
                                        VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                                    }
                                }
                            }
                        } else {
                            if ((0U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x5cU;
                            } else if ((1U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x6eU;
                            } else if ((2U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x6fU;
                            }
                            if ((1U & (~ VL_ONEHOT_I(
                                                     (((2U 
                                                        == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                       << 2U) 
                                                      | (((1U 
                                                           == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                          << 1U) 
                                                         | (0U 
                                                            == (IData)(__Vfunc_emoji_token_char__5__char_idx)))))))) {
                                if ((0U != (((2U == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                             << 2U) 
                                            | (((1U 
                                                 == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                << 1U) 
                                               | (0U 
                                                  == (IData)(__Vfunc_emoji_token_char__5__char_idx)))))) {
                                    if (VL_UNLIKELY((
                                                     vlSymsp->_vm_contextp__->assertOn()))) {
                                        VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                                     , '#',64,VL_TIME_UNITED_Q(1)
                                                     , '#',4,(IData)(__Vfunc_emoji_token_char__5__char_idx));
                                        VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                        if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                          >> 2U)))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                    = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x73U
                                            : 0x65U)
                                        : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x79U
                                            : 0x5cU));
                            }
                        }
                    } else if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                         >> 3U)))) {
                        if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                            if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(__Vfunc_emoji_token_char__5__char_idx)))) {
                                    vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x65U;
                                }
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                    ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x72U : 0x69U)
                                    : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x66U : 0x5cU));
                        }
                    }
                } else if ((4U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                    if ((2U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                        if ((1U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                            if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                          >> 3U)))) {
                                if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                    if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(__Vfunc_emoji_token_char__5__char_idx)))) {
                                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x72U;
                                        }
                                    }
                                } else {
                                    vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                        = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? ((1U 
                                                & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                                ? 0x61U
                                                : 0x74U)
                                            : ((1U 
                                                & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                                ? 0x73U
                                                : 0x5cU));
                                }
                            }
                        } else if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                             >> 3U)))) {
                            if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                              >> 1U)))) {
                                    vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                        = ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x79U
                                            : 0x72U);
                                }
                            } else {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                    = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x67U
                                            : 0x6eU)
                                        : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x61U
                                            : 0x5cU));
                            }
                        }
                    } else if ((1U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                        if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                      >> 3U)))) {
                            if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                                if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(__Vfunc_emoji_token_char__5__char_idx)))) {
                                        vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x6bU;
                                    }
                                }
                            } else {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                    = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x6eU
                                            : 0x69U)
                                        : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                            ? 0x77U
                                            : 0x5cU));
                            }
                        }
                    } else if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                         >> 3U)))) {
                        if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                            if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                          >> 1U)))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                    = ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x68U : 0x67U);
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                    ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x75U : 0x61U)
                                    : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x6cU : 0x5cU));
                        }
                    }
                } else if ((2U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                    if ((1U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                        if ((0U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x5cU;
                        } else if ((1U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x6fU;
                        } else if ((2U == (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char = 0x6bU;
                        }
                        if ((1U & (~ VL_ONEHOT_I(((
                                                   (2U 
                                                    == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                   << 2U) 
                                                  | (((1U 
                                                       == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                      << 1U) 
                                                     | (0U 
                                                        == (IData)(__Vfunc_emoji_token_char__5__char_idx)))))))) {
                            if ((0U != (((2U == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                         << 2U) | (
                                                   ((1U 
                                                     == (IData)(__Vfunc_emoji_token_char__5__char_idx)) 
                                                    << 1U) 
                                                   | (0U 
                                                      == (IData)(__Vfunc_emoji_token_char__5__char_idx)))))) {
                                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                                    VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                                 , '#',64,VL_TIME_UNITED_Q(1)
                                                 , '#',4,(IData)(__Vfunc_emoji_token_char__5__char_idx));
                                    VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                         >> 3U)))) {
                        if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                            if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                          >> 1U)))) {
                                vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                    = ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x74U : 0x72U);
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                    ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x61U : 0x65U)
                                    : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x68U : 0x5cU));
                        }
                    }
                } else if ((1U & (IData)(__Vfunc_emoji_token_char__5__token_id))) {
                    if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                      >> 2U)))) {
                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                    ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x64U : 0x61U)
                                    : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                        ? 0x73U : 0x5cU));
                        }
                    }
                } else if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                     >> 3U)))) {
                    if ((4U & (IData)(__Vfunc_emoji_token_char__5__char_idx))) {
                        if ((1U & (~ ((IData)(__Vfunc_emoji_token_char__5__char_idx) 
                                      >> 1U)))) {
                            vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                                = ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                    ? 0x79U : 0x70U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char 
                            = ((2U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                ? ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                    ? 0x70U : 0x61U)
                                : ((1U & (IData)(__Vfunc_emoji_token_char__5__char_idx))
                                    ? 0x68U : 0x5cU));
                    }
                }
                __VdlyVal__be_top__DOT__line_buf__v3 
                    = vlSelfRef.be_top__DOT____VlemCall_5__emoji_token_char;
                __VdlyDim0__be_top__DOT__line_buf__v3 
                    = (0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q));
                vlSelfRef.__VdlyCommitQueuebe_top__DOT__line_buf.enqueue(__VdlyVal__be_top__DOT__line_buf__v3, (IData)(__VdlyDim0__be_top__DOT__line_buf__v3));
                __Vdly__be_top__DOT__len_q = (0x0000ffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.be_top__DOT__len_q)));
                __Vdly__be_top__DOT__emoji_complete_char_idx_q 
                    = (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__emoji_complete_char_idx_q)));
                if (((0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__emoji_complete_char_idx_q))) 
                     < (IData)(vlSelfRef.be_top__DOT__emoji_complete_token_len_q))) {
                    __Vdly__be_top__DOT__shift_idx_q 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.be_top__DOT__len_q)));
                }
            } else {
                __VdlyVal__be_top__DOT__line_buf__v4 
                    = vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                                     - (IData)(1U)))];
                __VdlyDim0__be_top__DOT__line_buf__v4 
                    = (0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q));
                vlSelfRef.__VdlyCommitQueuebe_top__DOT__line_buf.enqueue(__VdlyVal__be_top__DOT__line_buf__v4, (IData)(__VdlyDim0__be_top__DOT__line_buf__v4));
                __Vdly__be_top__DOT__shift_idx_q = 
                    (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                                    - (IData)(1U)));
            }
        }
        if (((0x1cU != (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (0x1cU == (IData)(vlSelfRef.be_top__DOT__state_d)))) {
            VL_ASSIGN_W(1024, __Vdly__be_top__DOT__pending_payload_q, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
            __Vdly__be_top__DOT__shift_idx_q = 0U;
        }
        if (vlSelfRef.io_mouse_click_valid) {
            vlSelfRef.be_top__DOT__click_x_q = vlSelfRef.io_mouse_click_x;
            vlSelfRef.be_top__DOT__click_y_q = vlSelfRef.io_mouse_click_y;
            vlSelfRef.be_top__DOT__click_raw_col_q 
                = (0x0000007fU & ((IData)(vlSelfRef.io_mouse_click_x) 
                                  >> 3U));
            vlSelfRef.be_top__DOT__click_screen_row_q 
                = (0x0000003fU & ((IData)(vlSelfRef.io_mouse_click_y) 
                                  >> 4U));
            vlSelfRef.be_top__DOT__click_is_right_q = 0U;
            vlSelfRef.be_top__DOT__click_pending_q = 1U;
        } else if (vlSelfRef.io_mouse_right_click_valid) {
            vlSelfRef.be_top__DOT__click_x_q = vlSelfRef.io_mouse_click_x;
            vlSelfRef.be_top__DOT__click_y_q = vlSelfRef.io_mouse_click_y;
            vlSelfRef.be_top__DOT__click_raw_col_q 
                = (0x0000007fU & ((IData)(vlSelfRef.io_mouse_click_x) 
                                  >> 3U));
            vlSelfRef.be_top__DOT__click_screen_row_q 
                = (0x0000003fU & ((IData)(vlSelfRef.io_mouse_click_y) 
                                  >> 4U));
            vlSelfRef.be_top__DOT__click_is_right_q = 1U;
            vlSelfRef.be_top__DOT__click_pending_q = 1U;
        } else if (vlSelfRef.be_top__DOT__accept_mouse_click) {
            vlSelfRef.be_top__DOT__click_pending_q = 0U;
        }
        if ((0x1cU == (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if (((IData)(vlSelfRef.be_top__DOT__shift_idx_q) 
                 < (IData)(vlSelfRef.be_top__DOT__len_q))) {
                VL_ASSIGNSEL_WI(1024, 8, (0x000003ffU 
                                          & VL_SHIFTL_III(10,32,32, (IData)(vlSelfRef.be_top__DOT__shift_idx_q), 3U)), __Vdly__be_top__DOT__pending_payload_q, vlSelfRef.be_top__DOT__line_buf
                                [(0x0000007fU & (IData)(vlSelfRef.be_top__DOT__shift_idx_q))]);
                __Vdly__be_top__DOT__shift_idx_q = 
                    (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__shift_idx_q)));
            }
        }
        if (((0x1eU != (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (0x1eU == (IData)(vlSelfRef.be_top__DOT__state_d)))) {
            vlSelfRef.be_top__DOT__unnamedblk11__DOT__src_len 
                = vlSelfRef.be_top__DOT__pending_len_q;
            vlSelfRef.be_top__DOT__unnamedblk11__DOT__user_len 
                = ((2U < (IData)(vlSelfRef.be_top__DOT__unnamedblk11__DOT__src_len))
                    ? (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__unnamedblk11__DOT__src_len) 
                                      - (IData)(2U)))
                    : 0U);
            vlSelfRef.be_top__DOT__unnamedblk11__DOT__copy_max 
                = ((IData)(vlSelfRef.be_top__DOT__quoted_store_valid)
                    ? 0x003cU : 0U);
            __Vdly__be_top__DOT__disp_build_idx_q = 0U;
            if (((IData)(vlSelfRef.be_top__DOT__quoted_store_valid) 
                 & (0x0080U < (0x0000ffffU & ((IData)(2U) 
                                              + ((IData)(vlSelfRef.be_top__DOT__unnamedblk11__DOT__copy_max) 
                                                 + (IData)(vlSelfRef.be_top__DOT__unnamedblk11__DOT__user_len))))))) {
                vlSelfRef.be_top__DOT__unnamedblk11__DOT__copy_max 
                    = (0x0000ffffU & ((IData)(0x007eU) 
                                      - (IData)(vlSelfRef.be_top__DOT__unnamedblk11__DOT__user_len)));
            }
            if (((IData)(vlSelfRef.be_top__DOT__quoted_store_valid) 
                 & ((IData)(vlSelfRef.be_top__DOT__u_store__DOT__rd2_len) 
                    < (IData)(vlSelfRef.be_top__DOT__unnamedblk11__DOT__copy_max)))) {
                vlSelfRef.be_top__DOT__unnamedblk11__DOT__copy_max 
                    = vlSelfRef.be_top__DOT__u_store__DOT__rd2_len;
            }
            __Vdly__be_top__DOT__disp_len_q = (0x0000ffffU 
                                               & ((IData)(2U) 
                                                  + 
                                                  ((IData)(vlSelfRef.be_top__DOT__unnamedblk11__DOT__copy_max) 
                                                   + (IData)(vlSelfRef.be_top__DOT__unnamedblk11__DOT__user_len))));
        }
        if ((0x1eU == (IData)(vlSelfRef.be_top__DOT__state_q))) {
            vlSelfRef.be_top__DOT__unnamedblk12__DOT__src_len 
                = vlSelfRef.be_top__DOT__pending_len_q;
            vlSelfRef.be_top__DOT__unnamedblk12__DOT__user_start = 2U;
            vlSelfRef.be_top__DOT__unnamedblk12__DOT__user_len 
                = ((2U < (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__src_len))
                    ? (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__src_len) 
                                      - (IData)(2U)))
                    : 0U);
            vlSelfRef.be_top__DOT__unnamedblk12__DOT__copy_len 
                = (0x0000ffffU & (((IData)(vlSelfRef.be_top__DOT__disp_len_q) 
                                   - (IData)(2U)) - (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__user_len)));
            vlSelfRef.be_top__DOT__unnamedblk12__DOT__wr_byte = 0x20U;
            if ((0U == (IData)(vlSelfRef.be_top__DOT__disp_build_idx_q))) {
                vlSelfRef.be_top__DOT__unnamedblk12__DOT__wr_byte = 0x3eU;
            } else if (((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                        <= (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__copy_len))) {
                vlSelfRef.be_top__DOT__unnamedblk12__DOT__wr_byte 
                    = (0x000000ffU & (((0U == (0x0000001fU 
                                               & VL_SHIFTL_III(10,32,32, 
                                                               ((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                                - (IData)(1U)), 3U)))
                                        ? 0U : (vlSelfRef.be_top__DOT__u_store__DOT__store
                                                [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx]
                                                [(((IData)(7U) 
                                                   + 
                                                   (0x000003ffU 
                                                    & VL_SHIFTL_III(10,32,32, 
                                                                    ((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                                     - (IData)(1U)), 3U))) 
                                                  >> 5U)] 
                                                << 
                                                ((IData)(0x00000020U) 
                                                 - 
                                                 (0x0000001fU 
                                                  & VL_SHIFTL_III(10,32,32, 
                                                                  ((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                                   - (IData)(1U)), 3U))))) 
                                      | (vlSelfRef.be_top__DOT__u_store__DOT__store
                                         [vlSelfRef.be_top__DOT__u_store__DOT__rd2_idx]
                                         [(0x0000001fU 
                                           & (VL_SHIFTL_III(10,32,32, 
                                                            ((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                             - (IData)(1U)), 3U) 
                                              >> 5U))] 
                                         >> (0x0000001fU 
                                             & VL_SHIFTL_III(10,32,32, 
                                                             ((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                              - (IData)(1U)), 3U)))));
                if ((0x0aU == (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__wr_byte))) {
                    vlSelfRef.be_top__DOT__unnamedblk12__DOT__wr_byte = 0x20U;
                }
            } else {
                vlSelfRef.be_top__DOT__unnamedblk12__DOT__wr_byte 
                    = (((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                        == (0x0000ffffU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__copy_len))))
                        ? 0x0000000aU : (0x000000ffU 
                                         & (((0U == 
                                              (0x0000001fU 
                                               & VL_SHIFTL_III(10,32,32, 
                                                               ((((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                                  - (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__copy_len)) 
                                                                 - (IData)(2U)) 
                                                                + (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__user_start)), 3U)))
                                              ? 0U : 
                                             (vlSelfRef.be_top__DOT__pending_payload_q
                                              [(((IData)(7U) 
                                                 + 
                                                 (0x000003ffU 
                                                  & VL_SHIFTL_III(10,32,32, 
                                                                  ((((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                                     - (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__copy_len)) 
                                                                    - (IData)(2U)) 
                                                                   + (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__user_start)), 3U))) 
                                                >> 5U)] 
                                              << ((IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & VL_SHIFTL_III(10,32,32, 
                                                                   ((((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                                      - (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__copy_len)) 
                                                                     - (IData)(2U)) 
                                                                    + (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__user_start)), 3U))))) 
                                            | (vlSelfRef.be_top__DOT__pending_payload_q
                                               [(0x0000001fU 
                                                 & (VL_SHIFTL_III(10,32,32, 
                                                                  ((((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                                     - (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__copy_len)) 
                                                                    - (IData)(2U)) 
                                                                   + (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__user_start)), 3U) 
                                                    >> 5U))] 
                                               >> (0x0000001fU 
                                                   & VL_SHIFTL_III(10,32,32, 
                                                                   ((((IData)(vlSelfRef.be_top__DOT__disp_build_idx_q) 
                                                                      - (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__copy_len)) 
                                                                     - (IData)(2U)) 
                                                                    + (IData)(vlSelfRef.be_top__DOT__unnamedblk12__DOT__user_start)), 3U))))));
            }
            VL_ASSIGNSEL_WI(1024, 8, (0x000003ffU & 
                                      VL_SHIFTL_III(10,32,32, (IData)(vlSelfRef.be_top__DOT__disp_build_idx_q), 3U)), vlSelfRef.be_top__DOT__disp_payload_q, vlSelfRef.be_top__DOT__unnamedblk12__DOT__wr_byte);
            __Vdly__be_top__DOT__disp_build_idx_q = 
                (0x0000ffffU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__disp_build_idx_q)));
        }
        if (vlSelfRef.be_top__DOT__suggest_recompute) {
            if (vlSelfRef.be_top__DOT__suggest_active_calc) {
                __Vdly__be_top__DOT__emoji_suggest_active_q = 1U;
                vlSelfRef.be_top__DOT__emoji_suggest_count_q 
                    = vlSelfRef.be_top__DOT__suggest_count_calc;
                vlSelfRef.be_top__DOT__emoji_suggest_ids_q 
                    = vlSelfRef.be_top__DOT__suggest_ids_calc;
                vlSelfRef.be_top__DOT__emoji_suggest_tracking_q = 1U;
                vlSelfRef.be_top__DOT__emoji_suggest_anchor_q 
                    = vlSelfRef.be_top__DOT__suggest_anchor_base;
            } else {
                __Vdly__be_top__DOT__emoji_suggest_active_q = 0U;
                vlSelfRef.be_top__DOT__emoji_suggest_count_q 
                    = vlSelfRef.be_top__DOT__suggest_count_calc;
                vlSelfRef.be_top__DOT__emoji_suggest_ids_q 
                    = vlSelfRef.be_top__DOT__suggest_ids_calc;
                vlSelfRef.be_top__DOT__emoji_suggest_tracking_q = 0U;
                vlSelfRef.be_top__DOT__emoji_suggest_anchor_q = 0U;
            }
        }
        if (((5U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (IData)(vlSelfRef.be_top__DOT__accept_io))) {
            if ((((1U == (IData)(vlSelfRef.io_key_type)) 
                  | (5U == (IData)(vlSelfRef.io_key_type))) 
                 | ((0U == (IData)(vlSelfRef.io_key_type)) 
                    & (5U == (IData)(vlSelfRef.io_key_ascii))))) {
                vlSelfRef.be_top__DOT__emoji_suggest_tracking_q = 0U;
                __Vdly__be_top__DOT__emoji_suggest_active_q = 0U;
                vlSelfRef.be_top__DOT__emoji_suggest_count_q = 0U;
                vlSelfRef.be_top__DOT__emoji_suggest_ids_q = 0ULL;
                vlSelfRef.be_top__DOT__emoji_suggest_anchor_q = 0U;
            }
        }
        if ((0x1aU == (IData)(vlSelfRef.be_top__DOT__state_q))) {
            __Vdly__be_top__DOT__wr_ptr_q = (0x0000003fU 
                                             & ((IData)(1U) 
                                                + (IData)(vlSelfRef.be_top__DOT__wr_ptr_q)));
            __Vdly__be_top__DOT__next_msg_id_q = (0x000000ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.be_top__DOT__next_msg_id_q)));
            vlSelfRef.be_top__DOT__emoji_suggest_tracking_q = 0U;
            __Vdly__be_top__DOT__emoji_suggest_active_q = 0U;
            vlSelfRef.be_top__DOT__emoji_suggest_count_q = 0U;
            vlSelfRef.be_top__DOT__emoji_suggest_ids_q = 0ULL;
            vlSelfRef.be_top__DOT__emoji_suggest_anchor_q = 0U;
        }
        if ((((IData)(vlSelfRef.be_top__DOT__state_d) 
              != (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (0x0bU == (IData)(vlSelfRef.be_top__DOT__state_d)))) {
            __Vdly__be_top__DOT__has_quote_q = 0U;
            __Vdly__be_top__DOT__quoted_msg_id_q = 0U;
            vlSelfRef.be_top__DOT__quoted_side_q = 0U;
            __Vdly__be_top__DOT__disp_len_q = 0U;
            vlSelfRef.be_top__DOT__disp_for_remote_q = 0U;
        }
        if ((((IData)(vlSelfRef.be_top__DOT__state_d) 
              != (IData)(vlSelfRef.be_top__DOT__state_q)) 
             & (0x0cU == (IData)(vlSelfRef.be_top__DOT__state_q)))) {
            __Vdly__be_top__DOT__disp_len_q = 0U;
            vlSelfRef.be_top__DOT__disp_for_remote_q = 0U;
        }
        if ((((((5U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                & (IData)(vlSelfRef.be_top__DOT__accept_io)) 
               & (5U == (IData)(vlSelfRef.io_key_type))) 
              & (~ (IData)(vlSelfRef.be_top__DOT__popup_active_q))) 
             & (~ (IData)(vlSelfRef.be_top__DOT__has_quote_q)))) {
            __Vdly__be_top__DOT__len_q = 0U;
            __Vdly__be_top__DOT__cursor_pos_q = 0U;
            __Vdly__be_top__DOT__input_newline_count_q = 0U;
            __Vdly__be_top__DOT__has_quote_q = 0U;
            __Vdly__be_top__DOT__quoted_msg_id_q = 0U;
            vlSelfRef.be_top__DOT__quoted_side_q = 0U;
            __Vdly__be_top__DOT__disp_len_q = 0U;
            vlSelfRef.be_top__DOT__disp_for_remote_q = 0U;
            vlSelfRef.be_top__DOT__emoji_suggest_tracking_q = 0U;
            __Vdly__be_top__DOT__emoji_suggest_active_q = 0U;
            vlSelfRef.be_top__DOT__emoji_suggest_count_q = 0U;
            vlSelfRef.be_top__DOT__emoji_suggest_ids_q = 0ULL;
            vlSelfRef.be_top__DOT__emoji_suggest_anchor_q = 0U;
        }
        vlSelfRef.be_top__DOT__state_q = vlSelfRef.be_top__DOT__state_d;
    } else {
        __Vdly__be_top__DOT__len_q = 0U;
        __Vdly__be_top__DOT__cursor_pos_q = 0U;
        __Vdly__be_top__DOT__wr_ptr_q = 0U;
        __Vdly__be_top__DOT__next_msg_id_q = 0U;
        VL_ASSIGN_W(1024, __Vdly__be_top__DOT__pending_payload_q, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
        __Vdly__be_top__DOT__input_newline_count_q = 0U;
        vlSelfRef.be_top__DOT__enc_src_q = 0U;
        __Vdly__be_top__DOT__enc_dst_q = 0U;
        __Vdly__be_top__DOT__click_vis_row_q = 0U;
        __Vdly__be_top__DOT__click_vis_col_q = 0U;
        __Vdly__be_top__DOT__click_walk_done_q = 0U;
        __Vdly__be_top__DOT__disp_len_q = 0U;
        __Vdly__be_top__DOT__disp_build_idx_q = 0U;
        __Vdly__be_top__DOT__emoji_complete_char_idx_q = 0U;
        vlSelfRef.be_top__DOT__unnamedblk7__DOT__i = 0U;
        vlSelfRef.be_top__DOT__state_q = 0U;
        vlSelfRef.be_top__DOT__enter_pulse_q = 0U;
        vlSelfRef.be_top__DOT__pending_msg_id_q = 0U;
        vlSelfRef.be_top__DOT__pending_store_idx_q = 0U;
        __Vdly__be_top__DOT__pending_len_q = 0U;
        vlSelfRef.be_top__DOT__rx_seq_q = 0U;
        vlSelfRef.be_top__DOT__rx_store_idx_q = 0U;
        vlSelfRef.be_top__DOT__rx_len_q = 0U;
        VL_ASSIGN_W(1024, vlSelfRef.be_top__DOT__rx_payload_q, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
        vlSelfRef.be_top__DOT__status_msg_id_q = 0U;
        vlSelfRef.be_top__DOT__status_status_q = 0U;
        vlSelfRef.be_top__DOT__last_event_ascii_q = 0U;
        vlSelfRef.be_top__DOT__delete_was_newline_q = 0U;
        __Vdly__be_top__DOT__shift_idx_q = 0U;
        vlSelfRef.be_top__DOT__peer_name_len_q = 0U;
        vlSelfRef.be_top__DOT__peer_name_q[0U] = 0U;
        vlSelfRef.be_top__DOT__peer_name_q[1U] = 0U;
        vlSelfRef.be_top__DOT__peer_name_q[2U] = 0U;
        vlSelfRef.be_top__DOT__peer_name_q[3U] = 0U;
        vlSelfRef.be_top__DOT__click_pending_q = 0U;
        vlSelfRef.be_top__DOT__click_is_right_q = 0U;
        vlSelfRef.be_top__DOT__click_x_q = 0U;
        vlSelfRef.be_top__DOT__click_y_q = 0U;
        vlSelfRef.be_top__DOT__click_raw_col_q = 0U;
        vlSelfRef.be_top__DOT__click_screen_row_q = 0U;
        __Vdly__be_top__DOT__click_target_row_q = 0U;
        __Vdly__be_top__DOT__click_target_col_q = 0U;
        __Vdly__be_top__DOT__popup_active_q = 0U;
        vlSelfRef.be_top__DOT__popup_type_q = 0U;
        vlSelfRef.be_top__DOT__popup_x_q = 0U;
        vlSelfRef.be_top__DOT__popup_y_q = 0U;
        __Vdly__be_top__DOT__menu_store_idx_q = 0U;
        __Vdly__be_top__DOT__has_quote_q = 0U;
        __Vdly__be_top__DOT__quoted_msg_id_q = 0U;
        vlSelfRef.be_top__DOT__quoted_side_q = 0U;
        VL_ASSIGN_W(1024, vlSelfRef.be_top__DOT__disp_payload_q, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
        vlSelfRef.be_top__DOT__disp_for_remote_q = 0U;
        vlSelfRef.be_top__DOT__recall_msg_id_q = 0U;
        vlSelfRef.be_top__DOT__recall_store_idx_q = 0U;
        vlSelfRef.be_top__DOT__recall_side_q = 0U;
        vlSelfRef.be_top__DOT__recall_send_q = 0U;
        vlSelfRef.be_top__DOT__emoji_suggest_tracking_q = 0U;
        __Vdly__be_top__DOT__emoji_suggest_active_q = 0U;
        vlSelfRef.be_top__DOT__emoji_suggest_count_q = 0U;
        vlSelfRef.be_top__DOT__emoji_suggest_ids_q = 0ULL;
        vlSelfRef.be_top__DOT__emoji_suggest_anchor_q = 0U;
        __Vdly__be_top__DOT__emoji_complete_token_q = 0U;
        __Vdly__be_top__DOT__emoji_complete_token_len_q = 0U;
        while (VL_GTS_III(32, 0x00000080U, vlSelfRef.be_top__DOT__unnamedblk7__DOT__i)) {
            __VdlyDim0__be_top__DOT__line_buf__v5 = 
                (0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk7__DOT__i);
            vlSelfRef.__VdlyCommitQueuebe_top__DOT__line_buf.enqueue(0U, (IData)(__VdlyDim0__be_top__DOT__line_buf__v5));
            vlSelfRef.be_top__DOT__unnamedblk7__DOT__i 
                = ((IData)(1U) + vlSelfRef.be_top__DOT__unnamedblk7__DOT__i);
        }
    }
    vlSelfRef.be_top__DOT__wr_ptr_q = __Vdly__be_top__DOT__wr_ptr_q;
    vlSelfRef.be_top__DOT__next_msg_id_q = __Vdly__be_top__DOT__next_msg_id_q;
    vlSelfRef.be_top__DOT__click_target_row_q = __Vdly__be_top__DOT__click_target_row_q;
    vlSelfRef.be_top__DOT__click_vis_row_q = __Vdly__be_top__DOT__click_vis_row_q;
    vlSelfRef.be_top__DOT__click_vis_col_q = __Vdly__be_top__DOT__click_vis_col_q;
    vlSelfRef.be_top__DOT__click_target_col_q = __Vdly__be_top__DOT__click_target_col_q;
    vlSelfRef.be_top__DOT__emoji_complete_token_q = __Vdly__be_top__DOT__emoji_complete_token_q;
    vlSelfRef.be_top__DOT__enc_dst_q = __Vdly__be_top__DOT__enc_dst_q;
    vlSelfRef.be_top__DOT__pending_payload_q[0U] = __Vdly__be_top__DOT__pending_payload_q[0U];
    vlSelfRef.be_top__DOT__pending_payload_q[1U] = __Vdly__be_top__DOT__pending_payload_q[1U];
    vlSelfRef.be_top__DOT__pending_payload_q[2U] = __Vdly__be_top__DOT__pending_payload_q[2U];
    vlSelfRef.be_top__DOT__pending_payload_q[3U] = __Vdly__be_top__DOT__pending_payload_q[3U];
    vlSelfRef.be_top__DOT__pending_payload_q[4U] = __Vdly__be_top__DOT__pending_payload_q[4U];
    vlSelfRef.be_top__DOT__pending_payload_q[5U] = __Vdly__be_top__DOT__pending_payload_q[5U];
    vlSelfRef.be_top__DOT__pending_payload_q[6U] = __Vdly__be_top__DOT__pending_payload_q[6U];
    vlSelfRef.be_top__DOT__pending_payload_q[7U] = __Vdly__be_top__DOT__pending_payload_q[7U];
    vlSelfRef.be_top__DOT__pending_payload_q[8U] = __Vdly__be_top__DOT__pending_payload_q[8U];
    vlSelfRef.be_top__DOT__pending_payload_q[9U] = __Vdly__be_top__DOT__pending_payload_q[9U];
    vlSelfRef.be_top__DOT__pending_payload_q[10U] = __Vdly__be_top__DOT__pending_payload_q[10U];
    vlSelfRef.be_top__DOT__pending_payload_q[11U] = __Vdly__be_top__DOT__pending_payload_q[11U];
    vlSelfRef.be_top__DOT__pending_payload_q[12U] = __Vdly__be_top__DOT__pending_payload_q[12U];
    vlSelfRef.be_top__DOT__pending_payload_q[13U] = __Vdly__be_top__DOT__pending_payload_q[13U];
    vlSelfRef.be_top__DOT__pending_payload_q[14U] = __Vdly__be_top__DOT__pending_payload_q[14U];
    vlSelfRef.be_top__DOT__pending_payload_q[15U] = __Vdly__be_top__DOT__pending_payload_q[15U];
    vlSelfRef.be_top__DOT__pending_payload_q[16U] = __Vdly__be_top__DOT__pending_payload_q[16U];
    vlSelfRef.be_top__DOT__pending_payload_q[17U] = __Vdly__be_top__DOT__pending_payload_q[17U];
    vlSelfRef.be_top__DOT__pending_payload_q[18U] = __Vdly__be_top__DOT__pending_payload_q[18U];
    vlSelfRef.be_top__DOT__pending_payload_q[19U] = __Vdly__be_top__DOT__pending_payload_q[19U];
    vlSelfRef.be_top__DOT__pending_payload_q[20U] = __Vdly__be_top__DOT__pending_payload_q[20U];
    vlSelfRef.be_top__DOT__pending_payload_q[21U] = __Vdly__be_top__DOT__pending_payload_q[21U];
    vlSelfRef.be_top__DOT__pending_payload_q[22U] = __Vdly__be_top__DOT__pending_payload_q[22U];
    vlSelfRef.be_top__DOT__pending_payload_q[23U] = __Vdly__be_top__DOT__pending_payload_q[23U];
    vlSelfRef.be_top__DOT__pending_payload_q[24U] = __Vdly__be_top__DOT__pending_payload_q[24U];
    vlSelfRef.be_top__DOT__pending_payload_q[25U] = __Vdly__be_top__DOT__pending_payload_q[25U];
    vlSelfRef.be_top__DOT__pending_payload_q[26U] = __Vdly__be_top__DOT__pending_payload_q[26U];
    vlSelfRef.be_top__DOT__pending_payload_q[27U] = __Vdly__be_top__DOT__pending_payload_q[27U];
    vlSelfRef.be_top__DOT__pending_payload_q[28U] = __Vdly__be_top__DOT__pending_payload_q[28U];
    vlSelfRef.be_top__DOT__pending_payload_q[29U] = __Vdly__be_top__DOT__pending_payload_q[29U];
    vlSelfRef.be_top__DOT__pending_payload_q[30U] = __Vdly__be_top__DOT__pending_payload_q[30U];
    vlSelfRef.be_top__DOT__pending_payload_q[31U] = __Vdly__be_top__DOT__pending_payload_q[31U];
    vlSelfRef.be_top__DOT__pending_len_q = __Vdly__be_top__DOT__pending_len_q;
    vlSelfRef.be_top__DOT__shift_idx_q = __Vdly__be_top__DOT__shift_idx_q;
    vlSelfRef.be_top__DOT__emoji_complete_char_idx_q 
        = __Vdly__be_top__DOT__emoji_complete_char_idx_q;
    vlSelfRef.be_top__DOT__emoji_complete_token_len_q 
        = __Vdly__be_top__DOT__emoji_complete_token_len_q;
    vlSelfRef.be_top__DOT__disp_build_idx_q = __Vdly__be_top__DOT__disp_build_idx_q;
    vlSelfRef.be_top__DOT__input_newline_count_q = __Vdly__be_top__DOT__input_newline_count_q;
    vlSelfRef.be_top__DOT__click_walk_done_q = __Vdly__be_top__DOT__click_walk_done_q;
    vlSelfRef.__VdlyCommitQueuebe_top__DOT__line_buf.commit(vlSelfRef.be_top__DOT__line_buf);
    vlSelfRef.be_top__DOT__disp_len_q = __Vdly__be_top__DOT__disp_len_q;
    vlSelfRef.be_top__DOT__emoji_suggest_active_q = __Vdly__be_top__DOT__emoji_suggest_active_q;
    vlSelfRef.be_top__DOT__menu_store_idx_q = __Vdly__be_top__DOT__menu_store_idx_q;
    vlSelfRef.be_top__DOT__cursor_pos_q = __Vdly__be_top__DOT__cursor_pos_q;
    vlSelfRef.be_top__DOT__quoted_msg_id_q = __Vdly__be_top__DOT__quoted_msg_id_q;
    vlSelfRef.be_top__DOT__popup_active_q = __Vdly__be_top__DOT__popup_active_q;
    if (__VdlySet__be_top__DOT__u_store__DOT__store__v0) {
        vlSelfRef.be_top__DOT__u_store__DOT__store[0U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[0U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[1U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[1U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[2U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[2U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[3U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[3U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[4U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[4U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[5U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[5U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[6U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[6U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[7U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[7U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[8U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[8U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[9U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[9U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[10U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[10U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[11U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[11U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[12U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[12U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[13U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[13U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[14U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[14U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[15U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[15U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[16U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[16U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[17U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[17U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[18U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[18U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[19U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[19U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[20U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[20U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[21U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[21U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[22U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[22U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[23U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[23U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[24U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[24U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[25U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[25U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[26U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[26U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[27U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[27U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[28U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[28U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[29U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[29U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[30U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[30U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[31U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[31U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[32U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[32U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[33U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[33U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[34U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[34U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[35U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[35U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[36U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[36U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[37U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[37U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[38U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[38U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[39U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[39U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[40U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[40U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[41U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[41U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[42U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[42U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[43U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[43U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[44U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[44U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[45U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[45U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[46U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[46U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[47U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[47U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[48U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[48U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[49U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[49U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[50U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[50U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[51U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[51U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[52U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[52U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[53U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[53U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[54U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[54U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[55U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[55U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[56U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[56U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[57U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[57U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[58U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[58U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[59U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[59U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[60U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[60U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[61U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[61U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[62U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[62U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[63U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[63U][32U]);
    }
    if (__VdlySet__be_top__DOT__u_store__DOT__store__v64) {
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v64][32U] 
            = (0x10000000U | vlSelfRef.be_top__DOT__u_store__DOT__store
               [__VdlyDim0__be_top__DOT__u_store__DOT__store__v64][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v65][32U] 
            = ((0x100fffffU & vlSelfRef.be_top__DOT__u_store__DOT__store
                [__VdlyDim0__be_top__DOT__u_store__DOT__store__v65][32U]) 
               | (0x1fffffffU & ((IData)(__VdlyVal__be_top__DOT__u_store__DOT__store__v65) 
                                 << 0x00000014U)));
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v66][32U] 
            = ((0x1ff3ffffU & vlSelfRef.be_top__DOT__u_store__DOT__store
                [__VdlyDim0__be_top__DOT__u_store__DOT__store__v66][32U]) 
               | (0x1fffffffU & ((IData)(__VdlyVal__be_top__DOT__u_store__DOT__store__v66) 
                                 << 0x00000012U)));
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v67][32U] 
            = ((0x1ffcffffU & vlSelfRef.be_top__DOT__u_store__DOT__store
                [__VdlyDim0__be_top__DOT__u_store__DOT__store__v67][32U]) 
               | (0x1fffffffU & ((IData)(__VdlyVal__be_top__DOT__u_store__DOT__store__v67) 
                                 << 0x00000010U)));
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v68][32U] 
            = ((0x1fff0000U & vlSelfRef.be_top__DOT__u_store__DOT__store
                [__VdlyDim0__be_top__DOT__u_store__DOT__store__v68][32U]) 
               | (0x1fffffffU & (IData)(__VdlyVal__be_top__DOT__u_store__DOT__store__v68)));
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][0U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[0U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][1U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[1U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][2U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[2U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][3U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[3U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][4U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[4U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][5U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[5U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][6U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[6U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][7U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[7U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][8U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[8U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][9U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[9U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][10U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[10U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][11U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[11U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][12U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[12U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][13U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[13U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][14U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[14U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][15U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[15U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][16U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[16U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][17U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[17U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][18U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[18U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][19U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[19U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][20U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[20U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][21U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[21U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][22U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[22U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][23U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[23U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][24U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[24U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][25U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[25U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][26U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[26U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][27U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[27U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][28U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[28U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][29U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[29U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][30U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[30U];
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v69][31U] 
            = __VdlyVal__be_top__DOT__u_store__DOT__store__v69[31U];
    }
    if (__VdlySet__be_top__DOT__u_store__DOT__store__v70) {
        vlSelfRef.be_top__DOT__u_store__DOT__store[__VdlyDim0__be_top__DOT__u_store__DOT__store__v70][32U] 
            = ((0x1ffcffffU & vlSelfRef.be_top__DOT__u_store__DOT__store
                [__VdlyDim0__be_top__DOT__u_store__DOT__store__v70][32U]) 
               | (0x1fffffffU & ((IData)(__VdlyVal__be_top__DOT__u_store__DOT__store__v70) 
                                 << 0x00000010U)));
    }
    if (__VdlySet__be_top__DOT__u_store__DOT__store__v71) {
        vlSelfRef.be_top__DOT__u_store__DOT__store[0U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[0U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[1U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[1U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[2U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[2U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[3U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[3U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[4U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[4U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[5U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[5U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[6U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[6U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[7U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[7U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[8U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[8U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[9U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[9U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[10U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[10U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[11U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[11U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[12U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[12U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[13U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[13U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[14U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[14U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[15U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[15U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[16U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[16U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[17U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[17U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[18U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[18U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[19U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[19U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[20U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[20U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[21U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[21U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[22U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[22U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[23U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[23U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[24U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[24U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[25U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[25U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[26U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[26U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[27U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[27U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[28U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[28U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[29U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[29U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[30U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[30U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[31U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[31U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[32U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[32U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[33U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[33U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[34U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[34U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[35U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[35U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[36U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[36U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[37U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[37U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[38U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[38U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[39U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[39U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[40U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[40U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[41U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[41U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[42U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[42U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[43U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[43U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[44U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[44U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[45U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[45U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[46U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[46U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[47U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[47U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[48U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[48U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[49U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[49U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[50U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[50U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[51U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[51U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[52U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[52U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[53U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[53U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[54U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[54U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[55U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[55U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[56U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[56U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[57U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[57U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[58U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[58U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[59U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[59U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[60U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[60U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[61U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[61U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[62U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[62U][32U]);
        vlSelfRef.be_top__DOT__u_store__DOT__store[63U][32U] 
            = (0x0fffffffU & vlSelfRef.be_top__DOT__u_store__DOT__store[63U][32U]);
    }
    vlSelfRef.be_top__DOT__has_quote_q = __Vdly__be_top__DOT__has_quote_q;
    vlSelfRef.be_top__DOT__len_q = __Vdly__be_top__DOT__len_q;
    vlSelfRef.enter_committed = vlSelfRef.be_top__DOT__enter_pulse_q;
    vlSelfRef.be_render_peer_name_len = vlSelfRef.be_top__DOT__peer_name_len_q;
    vlSelfRef.be_render_peer_name[0U] = vlSelfRef.be_top__DOT__peer_name_q[0U];
    vlSelfRef.be_render_peer_name[1U] = vlSelfRef.be_top__DOT__peer_name_q[1U];
    vlSelfRef.be_render_peer_name[2U] = vlSelfRef.be_top__DOT__peer_name_q[2U];
    vlSelfRef.be_render_peer_name[3U] = vlSelfRef.be_top__DOT__peer_name_q[3U];
    vlSelfRef.be_top__DOT__peer_name_changed = ((IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped) 
                                                != (IData)(vlSelfRef.be_top__DOT__peer_name_len_q));
    if ((VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & vlSelfRef.cm_rx_payload[0U]) 
            != (0x000000ffU & vlSelfRef.be_top__DOT__peer_name_q[0U])))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[0U] 
                            >> 8U)) != (0x000000ffU 
                                        & (vlSelfRef.be_top__DOT__peer_name_q[0U] 
                                           >> 8U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[0U] 
                            >> 0x00000010U)) != (0x000000ffU 
                                                 & (vlSelfRef.be_top__DOT__peer_name_q[0U] 
                                                    >> 0x00000010U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((vlSelfRef.cm_rx_payload[0U] >> 0x00000018U) 
            != (vlSelfRef.be_top__DOT__peer_name_q[0U] 
                >> 0x00000018U)))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & vlSelfRef.cm_rx_payload[1U]) 
            != (0x000000ffU & vlSelfRef.be_top__DOT__peer_name_q[1U])))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[1U] 
                            >> 8U)) != (0x000000ffU 
                                        & (vlSelfRef.be_top__DOT__peer_name_q[1U] 
                                           >> 8U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[1U] 
                            >> 0x00000010U)) != (0x000000ffU 
                                                 & (vlSelfRef.be_top__DOT__peer_name_q[1U] 
                                                    >> 0x00000010U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 7U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((vlSelfRef.cm_rx_payload[1U] >> 0x00000018U) 
            != (vlSelfRef.be_top__DOT__peer_name_q[1U] 
                >> 0x00000018U)))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 8U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & vlSelfRef.cm_rx_payload[2U]) 
            != (0x000000ffU & vlSelfRef.be_top__DOT__peer_name_q[2U])))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 9U, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[2U] 
                            >> 8U)) != (0x000000ffU 
                                        & (vlSelfRef.be_top__DOT__peer_name_q[2U] 
                                           >> 8U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000aU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[2U] 
                            >> 0x00000010U)) != (0x000000ffU 
                                                 & (vlSelfRef.be_top__DOT__peer_name_q[2U] 
                                                    >> 0x00000010U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000bU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((vlSelfRef.cm_rx_payload[2U] >> 0x00000018U) 
            != (vlSelfRef.be_top__DOT__peer_name_q[2U] 
                >> 0x00000018U)))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000cU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & vlSelfRef.cm_rx_payload[3U]) 
            != (0x000000ffU & vlSelfRef.be_top__DOT__peer_name_q[3U])))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000dU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[3U] 
                            >> 8U)) != (0x000000ffU 
                                        & (vlSelfRef.be_top__DOT__peer_name_q[3U] 
                                           >> 8U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000eU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((0x000000ffU & (vlSelfRef.cm_rx_payload[3U] 
                            >> 0x00000010U)) != (0x000000ffU 
                                                 & (vlSelfRef.be_top__DOT__peer_name_q[3U] 
                                                    >> 0x00000010U))))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    if ((VL_LTS_III(32, 0x0000000fU, (IData)(vlSelfRef.be_top__DOT__rx_name_len_clamped)) 
         & ((vlSelfRef.cm_rx_payload[3U] >> 0x00000018U) 
            != (vlSelfRef.be_top__DOT__peer_name_q[3U] 
                >> 0x00000018U)))) {
        vlSelfRef.be_top__DOT__peer_name_changed = 1U;
    }
    vlSelfRef.emoji_suggest_count = vlSelfRef.be_top__DOT__emoji_suggest_count_q;
    vlSelfRef.line_rd_data = vlSelfRef.be_top__DOT__line_buf
        [vlSelfRef.line_rd_idx];
    vlSelfRef.be_top__DOT__click_hist_slot = (0x0000003fU 
                                              & ((((IData)(0x23U) 
                                                   + (IData)(vlSelfRef.fe_hist_wr_row)) 
                                                  - (IData)(vlSelfRef.fe_hist_scroll_offset)) 
                                                 + 
                                                 ((IData)(vlSelfRef.be_top__DOT__click_screen_row_q) 
                                                  - (IData)(2U))));
    vlSelfRef.emoji_suggest_active = vlSelfRef.be_top__DOT__emoji_suggest_active_q;
    vlSelfRef.emoji_suggest_ids = vlSelfRef.be_top__DOT__emoji_suggest_ids_q;
    vlSelfRef.emoji_suggest_anchor_pos = vlSelfRef.be_top__DOT__emoji_suggest_anchor_q;
    vlSelfRef.cursor_pos = vlSelfRef.be_top__DOT__cursor_pos_q;
    vlSelfRef.be_top__DOT__click_emoji_prefix_len = 
        (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                        - (IData)(vlSelfRef.be_top__DOT__emoji_suggest_anchor_q)));
    vlSelfRef.ui_popup_type = vlSelfRef.be_top__DOT__popup_type_q;
    vlSelfRef.ui_popup_x = vlSelfRef.be_top__DOT__popup_x_q;
    vlSelfRef.ui_popup_active = vlSelfRef.be_top__DOT__popup_active_q;
    vlSelfRef.be_top__DOT__click_popup_dx = (0x000003ffU 
                                             & ((IData)(vlSelfRef.be_top__DOT__click_x_q) 
                                                - (IData)(vlSelfRef.be_top__DOT__popup_x_q)));
    vlSelfRef.ui_popup_y = vlSelfRef.be_top__DOT__popup_y_q;
    vlSelfRef.store_rd_valid = (1U & (vlSelfRef.be_top__DOT__u_store__DOT__store
                                      [vlSelfRef.store_rd_idx][32U] 
                                      >> 0x0000001cU));
    vlSelfRef.store_rd_msg_id = (0x000000ffU & (vlSelfRef.be_top__DOT__u_store__DOT__store
                                                [vlSelfRef.store_rd_idx][32U] 
                                                >> 0x00000014U));
    vlSelfRef.store_rd_side = (3U & (vlSelfRef.be_top__DOT__u_store__DOT__store
                                     [vlSelfRef.store_rd_idx][32U] 
                                     >> 0x00000012U));
    vlSelfRef.store_rd_status = (3U & (vlSelfRef.be_top__DOT__u_store__DOT__store
                                       [vlSelfRef.store_rd_idx][32U] 
                                       >> 0x00000010U));
    vlSelfRef.store_rd_len = (0x0000ffffU & vlSelfRef.be_top__DOT__u_store__DOT__store
                              [vlSelfRef.store_rd_idx][32U]);
    vlSelfRef.store_rd_payload[0U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][0U];
    vlSelfRef.store_rd_payload[1U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][1U];
    vlSelfRef.store_rd_payload[2U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][2U];
    vlSelfRef.store_rd_payload[3U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][3U];
    vlSelfRef.store_rd_payload[4U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][4U];
    vlSelfRef.store_rd_payload[5U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][5U];
    vlSelfRef.store_rd_payload[6U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][6U];
    vlSelfRef.store_rd_payload[7U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][7U];
    vlSelfRef.store_rd_payload[8U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][8U];
    vlSelfRef.store_rd_payload[9U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][9U];
    vlSelfRef.store_rd_payload[10U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][10U];
    vlSelfRef.store_rd_payload[11U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][11U];
    vlSelfRef.store_rd_payload[12U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][12U];
    vlSelfRef.store_rd_payload[13U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][13U];
    vlSelfRef.store_rd_payload[14U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][14U];
    vlSelfRef.store_rd_payload[15U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][15U];
    vlSelfRef.store_rd_payload[16U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][16U];
    vlSelfRef.store_rd_payload[17U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][17U];
    vlSelfRef.store_rd_payload[18U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][18U];
    vlSelfRef.store_rd_payload[19U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][19U];
    vlSelfRef.store_rd_payload[20U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][20U];
    vlSelfRef.store_rd_payload[21U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][21U];
    vlSelfRef.store_rd_payload[22U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][22U];
    vlSelfRef.store_rd_payload[23U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][23U];
    vlSelfRef.store_rd_payload[24U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][24U];
    vlSelfRef.store_rd_payload[25U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][25U];
    vlSelfRef.store_rd_payload[26U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][26U];
    vlSelfRef.store_rd_payload[27U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][27U];
    vlSelfRef.store_rd_payload[28U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][28U];
    vlSelfRef.store_rd_payload[29U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][29U];
    vlSelfRef.store_rd_payload[30U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][30U];
    vlSelfRef.store_rd_payload[31U] = vlSelfRef.be_top__DOT__u_store__DOT__store
        [vlSelfRef.store_rd_idx][31U];
    vlSelfRef.be_top__DOT__click_in_emoji_suggest = 
        ((IData)(vlSelfRef.be_top__DOT__emoji_suggest_active_q) 
         & ((0x0070U > (0x000003ffU & ((IData)(vlSelfRef.be_top__DOT__click_x_q) 
                                       - (IData)(0x0010U)))) 
            & ((2U <= (0x000003ffU & ((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                      - (IData)(0x0104U)))) 
               & (((0x000003ffU & ((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                   - (IData)(0x0104U))) 
                   < (0x000003ffU & ((IData)(2U) + 
                                     ((IData)(vlSelfRef.be_top__DOT__emoji_suggest_count_q) 
                                      << 4U)))) & (
                                                   (0x0000000fU 
                                                    & ((((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                         - (IData)(0x0104U)) 
                                                        - (IData)(2U)) 
                                                       >> 4U)) 
                                                   < (IData)(vlSelfRef.be_top__DOT__emoji_suggest_count_q))))));
    vlSelfRef.be_top__DOT__click_emoji_token_id = (0x0000000fU 
                                                   & ((IData)(
                                                              (vlSelfRef.be_top__DOT__emoji_suggest_ids_q 
                                                               >> 
                                                               (0x0000003cU 
                                                                & ((((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                                     - (IData)(0x0104U)) 
                                                                    - (IData)(2U)) 
                                                                   >> 2U)))) 
                                                      & (- (IData)(
                                                                   ((0x0fU 
                                                                     > 
                                                                     (0x0000000fU 
                                                                      & ((((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                                           - (IData)(0x0104U)) 
                                                                          - (IData)(2U)) 
                                                                         >> 4U))) 
                                                                    & (0x3bU 
                                                                       >= 
                                                                       (0x0000003cU 
                                                                        & ((((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                                             - (IData)(0x0104U)) 
                                                                            - (IData)(2U)) 
                                                                           >> 2U))))))));
    vlSelfRef.be_top__DOT__click_popup_dy = (0x000003ffU 
                                             & ((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                - (IData)(vlSelfRef.be_top__DOT__popup_y_q)));
    vlSelfRef.be_has_quote = vlSelfRef.be_top__DOT__has_quote_q;
    vlSelfRef.line_len = vlSelfRef.be_top__DOT__len_q;
    vlSelfRef.be_top__DOT__enc_emit_byte = 0U;
    vlSelfRef.be_top__DOT__enc_src_delta = 0U;
    vlSelfRef.be_top__DOT__unnamedblk5__DOT__src = vlSelfRef.be_top__DOT__enc_src_q;
    if (((((((VL_LTS_III(32, ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
              & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                 [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
             & (0x68U == vlSelfRef.be_top__DOT__line_buf
                [(0x0000007fU & ((IData)(1U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
            & (0x61U == vlSelfRef.be_top__DOT__line_buf
               [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
           & (0x70U == vlSelfRef.be_top__DOT__line_buf
              [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
          & (0x70U == vlSelfRef.be_top__DOT__line_buf
             [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
         & (0x79U == vlSelfRef.be_top__DOT__line_buf
            [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe0U;
        vlSelfRef.be_top__DOT__enc_src_delta = 6U;
    } else if (((((((VL_LTS_III(32, ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                     & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                    & (0x6cU == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(1U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x61U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(2U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x75U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x67U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x68U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe4U;
        vlSelfRef.be_top__DOT__enc_src_delta = 6U;
    } else if ((((((VL_LTS_III(32, ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                    & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                   & (0x77U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(1U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x69U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x6eU == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x6bU == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe5U;
        vlSelfRef.be_top__DOT__enc_src_delta = 5U;
    } else if (((((((VL_LTS_III(32, ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                     & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                    & (0x61U == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(1U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x6eU == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(2U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x67U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x72U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x79U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe6U;
        vlSelfRef.be_top__DOT__enc_src_delta = 6U;
    } else if ((((((VL_LTS_III(32, ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                    & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                   & (0x73U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(1U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x74U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x61U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x72U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe7U;
        vlSelfRef.be_top__DOT__enc_src_delta = 5U;
    } else if ((((((VL_LTS_III(32, ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                    & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                   & (0x66U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(1U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x69U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x72U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x65U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe8U;
        vlSelfRef.be_top__DOT__enc_src_delta = 5U;
    } else if (((((VL_LTS_III(32, ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                   & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                  & (0x79U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(1U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x65U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x73U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe9U;
        vlSelfRef.be_top__DOT__enc_src_delta = 4U;
    } else if ((((VL_LTS_III(32, ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                  & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                 & (0x6eU == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(1U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x6fU == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xeaU;
        vlSelfRef.be_top__DOT__enc_src_delta = 3U;
    } else if ((((VL_LTS_III(32, ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                  & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                 & (0x75U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(1U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x70U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xebU;
        vlSelfRef.be_top__DOT__enc_src_delta = 3U;
    } else if ((((((VL_LTS_III(32, ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                    & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                   & (0x64U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(1U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x6fU == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x77U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x6eU == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xecU;
        vlSelfRef.be_top__DOT__enc_src_delta = 5U;
    } else if ((((((VL_LTS_III(32, ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                    & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                   & (0x64U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(1U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x6fU == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x67U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x65U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xedU;
        vlSelfRef.be_top__DOT__enc_src_delta = 5U;
    } else if ((((((((VL_LTS_III(32, ((IData)(6U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                      & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                         [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                     & (0x6dU == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & ((IData)(1U) 
                                         + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                    & (0x61U == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(2U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x69U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(3U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x72U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x75U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x6fU == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(6U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xeeU;
        vlSelfRef.be_top__DOT__enc_src_delta = 7U;
    } else if (((((((VL_LTS_III(32, ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                     & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                    & (0x68U == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(1U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x65U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(2U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x61U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x72U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x74U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe2U;
        vlSelfRef.be_top__DOT__enc_src_delta = 6U;
    } else if (((((VL_LTS_III(32, ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                   & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                  & (0x73U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(1U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x61U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x64U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe1U;
        vlSelfRef.be_top__DOT__enc_src_delta = 4U;
    } else if ((((VL_LTS_III(32, ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q)) 
                  & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                 & (0x6fU == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(1U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x6bU == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(2U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xe3U;
        vlSelfRef.be_top__DOT__enc_src_delta = 3U;
    } else if ((((((((((((((((0U == vlSelfRef.be_top__DOT__unnamedblk5__DOT__src) 
                             & (0x000cU == (IData)(vlSelfRef.be_top__DOT__len_q))) 
                            & VL_LTS_III(32, ((IData)(0x0000000bU) 
                                              + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q))) 
                           & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                              [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                          & (0x48U == vlSelfRef.be_top__DOT__line_buf
                             [(0x0000007fU & ((IData)(1U) 
                                              + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                         & (0x65U == vlSelfRef.be_top__DOT__line_buf
                            [(0x0000007fU & ((IData)(2U) 
                                             + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                        & (0x61U == vlSelfRef.be_top__DOT__line_buf
                           [(0x0000007fU & ((IData)(3U) 
                                            + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                       & (0x72U == vlSelfRef.be_top__DOT__line_buf
                          [(0x0000007fU & ((IData)(4U) 
                                           + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                      & (0x74U == vlSelfRef.be_top__DOT__line_buf
                         [(0x0000007fU & ((IData)(5U) 
                                          + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                     & (0x62U == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & ((IData)(6U) 
                                         + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                    & (0x72U == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(7U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x6fU == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(8U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x6bU == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(9U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x65U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(0x0aU) 
                                     + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x6eU == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(0x0bU) 
                                    + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0x80U;
        vlSelfRef.be_top__DOT__enc_src_delta = 0x0cU;
    } else if ((((((((((((0U == vlSelfRef.be_top__DOT__unnamedblk5__DOT__src) 
                         & (8U == (IData)(vlSelfRef.be_top__DOT__len_q))) 
                        & VL_LTS_III(32, ((IData)(7U) 
                                          + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q))) 
                       & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                          [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                      & (0x48U == vlSelfRef.be_top__DOT__line_buf
                         [(0x0000007fU & ((IData)(1U) 
                                          + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                     & (0x69U == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & ((IData)(2U) 
                                         + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                    & (0x73U == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(3U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x73U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(4U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x69U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x6eU == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(6U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x67U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(7U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0x92U;
        vlSelfRef.be_top__DOT__enc_src_delta = 8U;
    } else if ((((((((((0U == vlSelfRef.be_top__DOT__unnamedblk5__DOT__src) 
                       & (6U == (IData)(vlSelfRef.be_top__DOT__len_q))) 
                      & VL_LTS_III(32, ((IData)(5U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q))) 
                     & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                    & (0x53U == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(1U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x68U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(2U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x72U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x75U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x67U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xa4U;
        vlSelfRef.be_top__DOT__enc_src_delta = 6U;
    } else if ((((((((((0U == vlSelfRef.be_top__DOT__unnamedblk5__DOT__src) 
                       & (6U == (IData)(vlSelfRef.be_top__DOT__len_q))) 
                      & VL_LTS_III(32, ((IData)(5U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q))) 
                     & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                    & (0x53U == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(1U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x77U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(2U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x65U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(3U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x61U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x74U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xb6U;
        vlSelfRef.be_top__DOT__enc_src_delta = 6U;
    } else if (((((((((((0U == vlSelfRef.be_top__DOT__unnamedblk5__DOT__src) 
                        & (7U == (IData)(vlSelfRef.be_top__DOT__len_q))) 
                       & VL_LTS_III(32, ((IData)(6U) 
                                         + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src), (IData)(vlSelfRef.be_top__DOT__len_q))) 
                      & (0x5cU == vlSelfRef.be_top__DOT__line_buf
                         [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)])) 
                     & (0x58U == vlSelfRef.be_top__DOT__line_buf
                        [(0x0000007fU & ((IData)(1U) 
                                         + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                    & (0x69U == vlSelfRef.be_top__DOT__line_buf
                       [(0x0000007fU & ((IData)(2U) 
                                        + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                   & (0x75U == vlSelfRef.be_top__DOT__line_buf
                      [(0x0000007fU & ((IData)(3U) 
                                       + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                  & (0x63U == vlSelfRef.be_top__DOT__line_buf
                     [(0x0000007fU & ((IData)(4U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                 & (0x61U == vlSelfRef.be_top__DOT__line_buf
                    [(0x0000007fU & ((IData)(5U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))])) 
                & (0x69U == vlSelfRef.be_top__DOT__line_buf
                   [(0x0000007fU & ((IData)(6U) + vlSelfRef.be_top__DOT__unnamedblk5__DOT__src))]))) {
        vlSelfRef.be_top__DOT__enc_emit_byte = 0xc8U;
        vlSelfRef.be_top__DOT__enc_src_delta = 7U;
    } else {
        vlSelfRef.be_top__DOT__enc_emit_byte = vlSelfRef.be_top__DOT__line_buf
            [(0x0000007fU & vlSelfRef.be_top__DOT__unnamedblk5__DOT__src)];
        vlSelfRef.be_top__DOT__enc_src_delta = 1U;
    }
    vlSelfRef.be_top__DOT__key_char_insert_allowed 
        = ((0x0080U > (IData)(vlSelfRef.be_top__DOT__len_q)) 
           & ((0x0aU != (IData)(vlSelfRef.io_key_ascii)) 
              | ((~ (IData)(vlSelfRef.fe_input_at_limit)) 
                 & (0x0fU > (IData)(vlSelfRef.be_top__DOT__input_newline_count_q)))));
    vlSelfRef.be_tx_valid = 0U;
    vlSelfRef.be_tx_frame_type = 0U;
    vlSelfRef.be_render_cmd = 0U;
    vlSelfRef.be_tx_len = 0U;
    VL_ASSIGN_W(1024, vlSelfRef.be_tx_payload, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
    vlSelfRef.be_render_valid = 0U;
    vlSelfRef.be_render_side = 0U;
    vlSelfRef.be_render_status = 0U;
    vlSelfRef.be_render_cursor_pos = 0U;
    vlSelfRef.be_render_ascii = 0U;
    vlSelfRef.be_top__DOT__suggest_recompute = ((7U 
                                                 == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                                | ((8U 
                                                    == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                                   | ((6U 
                                                       == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                                      | ((IData)(vlSelfRef.be_top__DOT__click_walk_done_q) 
                                                         & (0x19U 
                                                            == (IData)(vlSelfRef.be_top__DOT__state_q))))));
    vlSelfRef.be_tx_msg_id = 0U;
    vlSelfRef.be_render_store_idx = 0U;
    vlSelfRef.be_render_len = 0U;
    VL_ASSIGN_W(1024, vlSelfRef.be_render_payload, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
    if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                  >> 5U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                      >> 4U)))) {
            if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                            vlSelfRef.be_tx_len = 4U;
                            VL_ASSIGN_W(1024, vlSelfRef.be_tx_payload, Vbe_top__ConstPool__CONST_h62f3a808_0);
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                            vlSelfRef.be_render_store_idx 
                                = vlSelfRef.be_top__DOT__rx_store_idx_q;
                        }
                    }
                } else {
                    if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                            vlSelfRef.be_tx_len = vlSelfRef.be_top__DOT__pending_len_q;
                            vlSelfRef.be_tx_payload[0U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[0U];
                            vlSelfRef.be_tx_payload[1U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[1U];
                            vlSelfRef.be_tx_payload[2U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[2U];
                            vlSelfRef.be_tx_payload[3U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[3U];
                            vlSelfRef.be_tx_payload[4U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[4U];
                            vlSelfRef.be_tx_payload[5U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[5U];
                            vlSelfRef.be_tx_payload[6U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[6U];
                            vlSelfRef.be_tx_payload[7U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[7U];
                            vlSelfRef.be_tx_payload[8U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[8U];
                            vlSelfRef.be_tx_payload[9U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[9U];
                            vlSelfRef.be_tx_payload[10U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[10U];
                            vlSelfRef.be_tx_payload[11U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[11U];
                            vlSelfRef.be_tx_payload[12U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[12U];
                            vlSelfRef.be_tx_payload[13U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[13U];
                            vlSelfRef.be_tx_payload[14U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[14U];
                            vlSelfRef.be_tx_payload[15U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[15U];
                            vlSelfRef.be_tx_payload[16U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[16U];
                            vlSelfRef.be_tx_payload[17U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[17U];
                            vlSelfRef.be_tx_payload[18U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[18U];
                            vlSelfRef.be_tx_payload[19U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[19U];
                            vlSelfRef.be_tx_payload[20U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[20U];
                            vlSelfRef.be_tx_payload[21U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[21U];
                            vlSelfRef.be_tx_payload[22U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[22U];
                            vlSelfRef.be_tx_payload[23U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[23U];
                            vlSelfRef.be_tx_payload[24U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[24U];
                            vlSelfRef.be_tx_payload[25U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[25U];
                            vlSelfRef.be_tx_payload[26U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[26U];
                            vlSelfRef.be_tx_payload[27U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[27U];
                            vlSelfRef.be_tx_payload[28U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[28U];
                            vlSelfRef.be_tx_payload[29U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[29U];
                            vlSelfRef.be_tx_payload[30U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[30U];
                            vlSelfRef.be_tx_payload[31U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[31U];
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                            vlSelfRef.be_render_store_idx 
                                = vlSelfRef.be_top__DOT__pending_store_idx_q;
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                 >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        vlSelfRef.be_tx_len = 4U;
                        VL_ASSIGN_W(1024, vlSelfRef.be_tx_payload, Vbe_top__ConstPool__CONST_h62f3a808_0);
                    }
                } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    vlSelfRef.be_tx_len = 4U;
                    VL_ASSIGN_W(1024, vlSelfRef.be_tx_payload, Vbe_top__ConstPool__CONST_h62f3a808_0);
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                            vlSelfRef.be_render_ascii 
                                = vlSelfRef.be_top__DOT__last_event_ascii_q;
                        }
                    }
                }
            }
        }
        if ((0x00000010U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                            vlSelfRef.be_render_cursor_pos 
                                = vlSelfRef.be_top__DOT__cursor_pos_q;
                            vlSelfRef.be_render_payload[0U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[0U];
                            vlSelfRef.be_render_payload[1U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[1U];
                            vlSelfRef.be_render_payload[2U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[2U];
                            vlSelfRef.be_render_payload[3U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[3U];
                            vlSelfRef.be_render_payload[4U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[4U];
                            vlSelfRef.be_render_payload[5U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[5U];
                            vlSelfRef.be_render_payload[6U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[6U];
                            vlSelfRef.be_render_payload[7U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[7U];
                            vlSelfRef.be_render_payload[8U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[8U];
                            vlSelfRef.be_render_payload[9U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[9U];
                            vlSelfRef.be_render_payload[10U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[10U];
                            vlSelfRef.be_render_payload[11U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[11U];
                            vlSelfRef.be_render_payload[12U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[12U];
                            vlSelfRef.be_render_payload[13U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[13U];
                            vlSelfRef.be_render_payload[14U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[14U];
                            vlSelfRef.be_render_payload[15U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[15U];
                            vlSelfRef.be_render_payload[16U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[16U];
                            vlSelfRef.be_render_payload[17U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[17U];
                            vlSelfRef.be_render_payload[18U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[18U];
                            vlSelfRef.be_render_payload[19U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[19U];
                            vlSelfRef.be_render_payload[20U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[20U];
                            vlSelfRef.be_render_payload[21U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[21U];
                            vlSelfRef.be_render_payload[22U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[22U];
                            vlSelfRef.be_render_payload[23U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[23U];
                            vlSelfRef.be_render_payload[24U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[24U];
                            vlSelfRef.be_render_payload[25U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[25U];
                            vlSelfRef.be_render_payload[26U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[26U];
                            vlSelfRef.be_render_payload[27U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[27U];
                            vlSelfRef.be_render_payload[28U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[28U];
                            vlSelfRef.be_render_payload[29U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[29U];
                            vlSelfRef.be_render_payload[30U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[30U];
                            vlSelfRef.be_render_payload[31U] 
                                = vlSelfRef.be_top__DOT__pending_payload_q[31U];
                        }
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        vlSelfRef.be_render_cursor_pos 
                            = vlSelfRef.be_top__DOT__cursor_pos_q;
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        vlSelfRef.be_render_cursor_pos = 0U;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                    vlSelfRef.be_render_cursor_pos 
                        = vlSelfRef.be_top__DOT__cursor_pos_q;
                }
            }
            if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                        if ((0U != (IData)(vlSelfRef.be_top__DOT__disp_len_q))) {
                            vlSelfRef.be_render_payload[0U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[0U];
                            vlSelfRef.be_render_payload[1U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[1U];
                            vlSelfRef.be_render_payload[2U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[2U];
                            vlSelfRef.be_render_payload[3U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[3U];
                            vlSelfRef.be_render_payload[4U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[4U];
                            vlSelfRef.be_render_payload[5U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[5U];
                            vlSelfRef.be_render_payload[6U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[6U];
                            vlSelfRef.be_render_payload[7U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[7U];
                            vlSelfRef.be_render_payload[8U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[8U];
                            vlSelfRef.be_render_payload[9U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[9U];
                            vlSelfRef.be_render_payload[10U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[10U];
                            vlSelfRef.be_render_payload[11U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[11U];
                            vlSelfRef.be_render_payload[12U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[12U];
                            vlSelfRef.be_render_payload[13U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[13U];
                            vlSelfRef.be_render_payload[14U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[14U];
                            vlSelfRef.be_render_payload[15U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[15U];
                            vlSelfRef.be_render_payload[16U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[16U];
                            vlSelfRef.be_render_payload[17U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[17U];
                            vlSelfRef.be_render_payload[18U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[18U];
                            vlSelfRef.be_render_payload[19U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[19U];
                            vlSelfRef.be_render_payload[20U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[20U];
                            vlSelfRef.be_render_payload[21U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[21U];
                            vlSelfRef.be_render_payload[22U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[22U];
                            vlSelfRef.be_render_payload[23U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[23U];
                            vlSelfRef.be_render_payload[24U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[24U];
                            vlSelfRef.be_render_payload[25U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[25U];
                            vlSelfRef.be_render_payload[26U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[26U];
                            vlSelfRef.be_render_payload[27U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[27U];
                            vlSelfRef.be_render_payload[28U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[28U];
                            vlSelfRef.be_render_payload[29U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[29U];
                            vlSelfRef.be_render_payload[30U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[30U];
                            vlSelfRef.be_render_payload[31U] 
                                = vlSelfRef.be_top__DOT__disp_payload_q[31U];
                        } else {
                            vlSelfRef.be_render_payload[0U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[0U];
                            vlSelfRef.be_render_payload[1U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[1U];
                            vlSelfRef.be_render_payload[2U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[2U];
                            vlSelfRef.be_render_payload[3U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[3U];
                            vlSelfRef.be_render_payload[4U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[4U];
                            vlSelfRef.be_render_payload[5U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[5U];
                            vlSelfRef.be_render_payload[6U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[6U];
                            vlSelfRef.be_render_payload[7U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[7U];
                            vlSelfRef.be_render_payload[8U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[8U];
                            vlSelfRef.be_render_payload[9U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[9U];
                            vlSelfRef.be_render_payload[10U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[10U];
                            vlSelfRef.be_render_payload[11U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[11U];
                            vlSelfRef.be_render_payload[12U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[12U];
                            vlSelfRef.be_render_payload[13U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[13U];
                            vlSelfRef.be_render_payload[14U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[14U];
                            vlSelfRef.be_render_payload[15U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[15U];
                            vlSelfRef.be_render_payload[16U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[16U];
                            vlSelfRef.be_render_payload[17U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[17U];
                            vlSelfRef.be_render_payload[18U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[18U];
                            vlSelfRef.be_render_payload[19U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[19U];
                            vlSelfRef.be_render_payload[20U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[20U];
                            vlSelfRef.be_render_payload[21U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[21U];
                            vlSelfRef.be_render_payload[22U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[22U];
                            vlSelfRef.be_render_payload[23U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[23U];
                            vlSelfRef.be_render_payload[24U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[24U];
                            vlSelfRef.be_render_payload[25U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[25U];
                            vlSelfRef.be_render_payload[26U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[26U];
                            vlSelfRef.be_render_payload[27U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[27U];
                            vlSelfRef.be_render_payload[28U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[28U];
                            vlSelfRef.be_render_payload[29U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[29U];
                            vlSelfRef.be_render_payload[30U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[30U];
                            vlSelfRef.be_render_payload[31U] 
                                = vlSelfRef.be_top__DOT__rx_payload_q[31U];
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((0U != (IData)(vlSelfRef.be_top__DOT__disp_len_q))) {
                        vlSelfRef.be_render_payload[0U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[0U];
                        vlSelfRef.be_render_payload[1U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[1U];
                        vlSelfRef.be_render_payload[2U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[2U];
                        vlSelfRef.be_render_payload[3U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[3U];
                        vlSelfRef.be_render_payload[4U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[4U];
                        vlSelfRef.be_render_payload[5U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[5U];
                        vlSelfRef.be_render_payload[6U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[6U];
                        vlSelfRef.be_render_payload[7U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[7U];
                        vlSelfRef.be_render_payload[8U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[8U];
                        vlSelfRef.be_render_payload[9U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[9U];
                        vlSelfRef.be_render_payload[10U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[10U];
                        vlSelfRef.be_render_payload[11U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[11U];
                        vlSelfRef.be_render_payload[12U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[12U];
                        vlSelfRef.be_render_payload[13U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[13U];
                        vlSelfRef.be_render_payload[14U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[14U];
                        vlSelfRef.be_render_payload[15U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[15U];
                        vlSelfRef.be_render_payload[16U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[16U];
                        vlSelfRef.be_render_payload[17U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[17U];
                        vlSelfRef.be_render_payload[18U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[18U];
                        vlSelfRef.be_render_payload[19U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[19U];
                        vlSelfRef.be_render_payload[20U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[20U];
                        vlSelfRef.be_render_payload[21U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[21U];
                        vlSelfRef.be_render_payload[22U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[22U];
                        vlSelfRef.be_render_payload[23U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[23U];
                        vlSelfRef.be_render_payload[24U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[24U];
                        vlSelfRef.be_render_payload[25U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[25U];
                        vlSelfRef.be_render_payload[26U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[26U];
                        vlSelfRef.be_render_payload[27U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[27U];
                        vlSelfRef.be_render_payload[28U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[28U];
                        vlSelfRef.be_render_payload[29U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[29U];
                        vlSelfRef.be_render_payload[30U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[30U];
                        vlSelfRef.be_render_payload[31U] 
                            = vlSelfRef.be_top__DOT__disp_payload_q[31U];
                    } else {
                        vlSelfRef.be_render_payload[0U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[0U];
                        vlSelfRef.be_render_payload[1U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[1U];
                        vlSelfRef.be_render_payload[2U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[2U];
                        vlSelfRef.be_render_payload[3U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[3U];
                        vlSelfRef.be_render_payload[4U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[4U];
                        vlSelfRef.be_render_payload[5U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[5U];
                        vlSelfRef.be_render_payload[6U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[6U];
                        vlSelfRef.be_render_payload[7U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[7U];
                        vlSelfRef.be_render_payload[8U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[8U];
                        vlSelfRef.be_render_payload[9U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[9U];
                        vlSelfRef.be_render_payload[10U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[10U];
                        vlSelfRef.be_render_payload[11U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[11U];
                        vlSelfRef.be_render_payload[12U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[12U];
                        vlSelfRef.be_render_payload[13U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[13U];
                        vlSelfRef.be_render_payload[14U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[14U];
                        vlSelfRef.be_render_payload[15U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[15U];
                        vlSelfRef.be_render_payload[16U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[16U];
                        vlSelfRef.be_render_payload[17U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[17U];
                        vlSelfRef.be_render_payload[18U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[18U];
                        vlSelfRef.be_render_payload[19U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[19U];
                        vlSelfRef.be_render_payload[20U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[20U];
                        vlSelfRef.be_render_payload[21U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[21U];
                        vlSelfRef.be_render_payload[22U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[22U];
                        vlSelfRef.be_render_payload[23U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[23U];
                        vlSelfRef.be_render_payload[24U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[24U];
                        vlSelfRef.be_render_payload[25U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[25U];
                        vlSelfRef.be_render_payload[26U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[26U];
                        vlSelfRef.be_render_payload[27U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[27U];
                        vlSelfRef.be_render_payload[28U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[28U];
                        vlSelfRef.be_render_payload[29U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[29U];
                        vlSelfRef.be_render_payload[30U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[30U];
                        vlSelfRef.be_render_payload[31U] 
                            = vlSelfRef.be_top__DOT__pending_payload_q[31U];
                    }
                }
            }
        } else if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                vlSelfRef.be_render_cursor_pos = vlSelfRef.be_top__DOT__cursor_pos_q;
            }
        }
    }
    vlSelfRef.be_render_msg_id = 0U;
    if ((0x00000020U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                            vlSelfRef.be_tx_valid = 1U;
                            vlSelfRef.be_tx_frame_type = 7U;
                            vlSelfRef.be_tx_msg_id 
                                = vlSelfRef.be_top__DOT__recall_msg_id_q;
                        }
                        if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                            vlSelfRef.be_render_cmd = 2U;
                            vlSelfRef.be_render_valid = 1U;
                            vlSelfRef.be_render_side 
                                = vlSelfRef.be_top__DOT__recall_side_q;
                            vlSelfRef.be_render_status = 3U;
                            vlSelfRef.be_render_len = 0U;
                            vlSelfRef.be_render_msg_id 
                                = vlSelfRef.be_top__DOT__recall_msg_id_q;
                        }
                    }
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                      >> 4U)))) {
            if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        vlSelfRef.be_tx_valid = 1U;
                        vlSelfRef.be_tx_frame_type 
                            = ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))
                                ? 6U : 4U);
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                  >> 1U)))) {
                        vlSelfRef.be_render_msg_id 
                            = ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))
                                ? (IData)(vlSelfRef.be_top__DOT__status_msg_id_q)
                                : (IData)(vlSelfRef.be_top__DOT__rx_seq_q));
                    }
                } else {
                    if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                            vlSelfRef.be_tx_valid = 1U;
                            vlSelfRef.be_tx_frame_type = 0U;
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                            vlSelfRef.be_render_msg_id 
                                = vlSelfRef.be_top__DOT__pending_msg_id_q;
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                            vlSelfRef.be_tx_msg_id 
                                = vlSelfRef.be_top__DOT__pending_msg_id_q;
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                 >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        vlSelfRef.be_tx_valid = 1U;
                        vlSelfRef.be_tx_frame_type = 5U;
                    }
                } else if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    vlSelfRef.be_tx_valid = 1U;
                    vlSelfRef.be_tx_frame_type = 3U;
                }
            }
        }
        if ((0x00000010U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                            vlSelfRef.be_render_cmd = 3U;
                            vlSelfRef.be_render_valid = 1U;
                            vlSelfRef.be_render_side = 0U;
                            vlSelfRef.be_render_status = 0U;
                            vlSelfRef.be_render_len 
                                = vlSelfRef.be_top__DOT__len_q;
                        }
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        vlSelfRef.be_render_cmd = 6U;
                        vlSelfRef.be_render_valid = vlSelfRef.be_top__DOT__click_walk_done_q;
                    }
                }
            } else if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                              >> 1U)))) {
                    vlSelfRef.be_render_cmd = ((1U 
                                                & (IData)(vlSelfRef.be_top__DOT__state_q))
                                                ? 0x0dU
                                                : 0x0cU);
                    vlSelfRef.be_render_valid = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                vlSelfRef.be_render_cmd = ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))
                                            ? 0x0bU
                                            : 0x0aU);
                vlSelfRef.be_render_valid = 1U;
            } else if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                vlSelfRef.be_render_cmd = 9U;
                vlSelfRef.be_render_valid = 1U;
            }
        } else if ((8U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                        vlSelfRef.be_render_cmd = 2U;
                        vlSelfRef.be_render_side = 0U;
                        vlSelfRef.be_render_status 
                            = vlSelfRef.be_top__DOT__status_status_q;
                        vlSelfRef.be_render_len = 0U;
                    } else {
                        vlSelfRef.be_render_cmd = 1U;
                        vlSelfRef.be_render_side = 1U;
                        vlSelfRef.be_render_status = 1U;
                        vlSelfRef.be_render_len = (
                                                   (0U 
                                                    != (IData)(vlSelfRef.be_top__DOT__disp_len_q))
                                                    ? (IData)(vlSelfRef.be_top__DOT__disp_len_q)
                                                    : (IData)(vlSelfRef.be_top__DOT__rx_len_q));
                    }
                    vlSelfRef.be_render_valid = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    vlSelfRef.be_render_cmd = 3U;
                    vlSelfRef.be_render_valid = 1U;
                    vlSelfRef.be_render_side = 0U;
                    vlSelfRef.be_render_status = 0U;
                    vlSelfRef.be_render_len = 0U;
                }
            } else {
                if ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                    vlSelfRef.be_render_cmd = 0U;
                    vlSelfRef.be_render_side = 0U;
                    vlSelfRef.be_render_status = 0U;
                    vlSelfRef.be_render_len = ((0U 
                                                != (IData)(vlSelfRef.be_top__DOT__disp_len_q))
                                                ? (IData)(vlSelfRef.be_top__DOT__disp_len_q)
                                                : (IData)(vlSelfRef.be_top__DOT__pending_len_q));
                } else {
                    vlSelfRef.be_render_cmd = 8U;
                }
                vlSelfRef.be_render_valid = 1U;
            }
        } else if ((4U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.be_top__DOT__state_q))) {
                vlSelfRef.be_render_cmd = ((1U & (IData)(vlSelfRef.be_top__DOT__state_q))
                                            ? 7U : 6U);
                vlSelfRef.be_render_valid = 1U;
            } else if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                vlSelfRef.be_render_cmd = 9U;
                vlSelfRef.be_render_valid = 1U;
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.be_top__DOT__state_q) 
                             >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.be_top__DOT__state_q)))) {
                vlSelfRef.be_render_cmd = 5U;
                vlSelfRef.be_render_valid = 1U;
            }
        }
    }
    __Vtableidx1 = vlSelfRef.be_top__DOT__state_q;
    vlSelfRef.be_render_conn_state = Vbe_top__ConstPool__TABLE_h729b8958_0
        [__Vtableidx1];
    vlSelfRef.be_top__DOT__suggest_tracking_base = vlSelfRef.be_top__DOT__emoji_suggest_tracking_q;
    vlSelfRef.be_top__DOT__suggest_anchor_base = vlSelfRef.be_top__DOT__emoji_suggest_anchor_q;
    vlSelfRef.be_top__DOT__suggest_cursor_base = vlSelfRef.be_top__DOT__cursor_pos_q;
    if ((((7U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
          & (0x5cU == (IData)(vlSelfRef.be_top__DOT__last_event_ascii_q))) 
         & (0U != (IData)(vlSelfRef.be_top__DOT__cursor_pos_q)))) {
        vlSelfRef.be_top__DOT__suggest_tracking_base = 1U;
        vlSelfRef.be_top__DOT__suggest_anchor_base 
            = (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                              - (IData)(1U)));
    }
    vlSelfRef.be_top__DOT__suggest_prefix_len = (0x0000ffffU 
                                                 & ((IData)(vlSelfRef.be_top__DOT__suggest_cursor_base) 
                                                    - (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base)));
    vlSelfRef.be_top__DOT__suggest_prefix_valid = (
                                                   (((IData)(vlSelfRef.be_top__DOT__suggest_tracking_base) 
                                                     & ((IData)(vlSelfRef.be_top__DOT__suggest_cursor_base) 
                                                        > (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base))) 
                                                    & ((IData)(vlSelfRef.be_top__DOT__suggest_cursor_base) 
                                                       <= (IData)(vlSelfRef.be_top__DOT__len_q))) 
                                                   & (7U 
                                                      >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len)));
    if (((IData)(vlSelfRef.be_top__DOT__suggest_prefix_valid) 
         & VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len)))) {
        vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0 
            = vlSelfRef.be_top__DOT__line_buf[(0x0000007fU 
                                               & (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base))];
        vlSelfRef.be_top__DOT__suggest_prefix_byte[0U] 
            = vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0;
    } else {
        vlSelfRef.be_top__DOT__suggest_prefix_byte[0U] = 0U;
    }
    if (((IData)(vlSelfRef.be_top__DOT__suggest_prefix_valid) 
         & VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len)))) {
        vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0 
            = vlSelfRef.be_top__DOT__line_buf[(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base)))];
        vlSelfRef.be_top__DOT__suggest_prefix_byte[1U] 
            = vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0;
    } else {
        vlSelfRef.be_top__DOT__suggest_prefix_byte[1U] = 0U;
    }
    if (((IData)(vlSelfRef.be_top__DOT__suggest_prefix_valid) 
         & VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len)))) {
        vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0 
            = vlSelfRef.be_top__DOT__line_buf[(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base)))];
        vlSelfRef.be_top__DOT__suggest_prefix_byte[2U] 
            = vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0;
    } else {
        vlSelfRef.be_top__DOT__suggest_prefix_byte[2U] = 0U;
    }
    if (((IData)(vlSelfRef.be_top__DOT__suggest_prefix_valid) 
         & VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len)))) {
        vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0 
            = vlSelfRef.be_top__DOT__line_buf[(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base)))];
        vlSelfRef.be_top__DOT__suggest_prefix_byte[3U] 
            = vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0;
    } else {
        vlSelfRef.be_top__DOT__suggest_prefix_byte[3U] = 0U;
    }
    if (((IData)(vlSelfRef.be_top__DOT__suggest_prefix_valid) 
         & VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len)))) {
        vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0 
            = vlSelfRef.be_top__DOT__line_buf[(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base)))];
        vlSelfRef.be_top__DOT__suggest_prefix_byte[4U] 
            = vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0;
    } else {
        vlSelfRef.be_top__DOT__suggest_prefix_byte[4U] = 0U;
    }
    if (((IData)(vlSelfRef.be_top__DOT__suggest_prefix_valid) 
         & VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len)))) {
        vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0 
            = vlSelfRef.be_top__DOT__line_buf[(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base)))];
        vlSelfRef.be_top__DOT__suggest_prefix_byte[5U] 
            = vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0;
    } else {
        vlSelfRef.be_top__DOT__suggest_prefix_byte[5U] = 0U;
    }
    if (((IData)(vlSelfRef.be_top__DOT__suggest_prefix_valid) 
         & VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len)))) {
        vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0 
            = vlSelfRef.be_top__DOT__line_buf[(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + (IData)(vlSelfRef.be_top__DOT__suggest_anchor_base)))];
        vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
            = vlSelfRef.be_top__DOT____Vlvbound_hf6bfe95c__0;
    } else {
        vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] = 0U;
    }
    vlSelfRef.be_top__DOT__suggest_count_calc = 0U;
    vlSelfRef.be_top__DOT__suggest_ids_calc = 0ULL;
    vlSelfRef.be_top__DOT__suggest_active_calc = 0U;
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
    if (be_top__DOT____VlemLogAnd_2) {
        be_top__DOT____VlemLogAnd_2 = (6U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[0U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 1U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[1U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 2U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[2U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 3U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[3U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 4U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[4U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 5U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[5U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 6U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 0U;
        if ((0x3bU >= (0x0000003fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))) {
            vlSelfRef.be_top__DOT__suggest_ids_calc 
                = (((~ (0x000000000000000fULL << (0x0000003fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))) 
                    & vlSelfRef.be_top__DOT__suggest_ids_calc) 
                   | (0x0fffffffffffffffULL & ((QData)((IData)(vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0)) 
                                               << (0x0000003fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))));
        }
        vlSelfRef.be_top__DOT__suggest_active_calc = 1U;
        vlSelfRef.be_top__DOT__suggest_count_calc = 
            (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__suggest_count_calc)));
    }
    if (be_top__DOT____VlemLogAnd_2) {
        be_top__DOT____VlemLogAnd_2 = (4U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 1U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[0U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 1U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 1U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[1U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 2U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 1U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[2U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 3U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 1U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[3U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 4U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 1U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[4U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 5U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 1U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[5U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 6U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 1U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 1U;
        if ((0x3bU >= (0x0000003fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))) {
            vlSelfRef.be_top__DOT__suggest_ids_calc 
                = (((~ (0x000000000000000fULL << (0x0000003fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))) 
                    & vlSelfRef.be_top__DOT__suggest_ids_calc) 
                   | (0x0fffffffffffffffULL & ((QData)((IData)(vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0)) 
                                               << (0x0000003fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))));
        }
        vlSelfRef.be_top__DOT__suggest_active_calc = 1U;
        vlSelfRef.be_top__DOT__suggest_count_calc = 
            (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__suggest_count_calc)));
    }
    if (be_top__DOT____VlemLogAnd_2) {
        be_top__DOT____VlemLogAnd_2 = (6U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 2U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[0U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 1U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 2U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[1U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 2U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 2U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[2U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 3U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 2U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[3U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 4U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 2U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[4U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 5U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 2U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[5U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 6U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 2U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 2U;
        if ((0x3bU >= (0x0000003fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))) {
            vlSelfRef.be_top__DOT__suggest_ids_calc 
                = (((~ (0x000000000000000fULL << (0x0000003fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))) 
                    & vlSelfRef.be_top__DOT__suggest_ids_calc) 
                   | (0x0fffffffffffffffULL & ((QData)((IData)(vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0)) 
                                               << (0x0000003fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))));
        }
        vlSelfRef.be_top__DOT__suggest_active_calc = 1U;
        vlSelfRef.be_top__DOT__suggest_count_calc = 
            (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__suggest_count_calc)));
    }
    if (be_top__DOT____VlemLogAnd_2) {
        be_top__DOT____VlemLogAnd_2 = (3U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 3U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[0U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 1U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 3U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[1U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 2U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 3U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[2U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 3U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 3U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[3U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 4U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 3U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[4U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 5U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 3U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[5U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 6U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 3U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                }
                if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                           << 2U) | 
                                          (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))))) {
                    if ((0U != (((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                 << 2U) | (((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)) 
                                            << 1U) 
                                           | (0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:277: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 277, "");
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x74U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x61U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x68U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 2U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x64U : 0x61U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x73U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x79U : 0x70U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x70U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x68U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 3U;
        if ((0x3bU >= (0x0000003fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))) {
            vlSelfRef.be_top__DOT__suggest_ids_calc 
                = (((~ (0x000000000000000fULL << (0x0000003fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))) 
                    & vlSelfRef.be_top__DOT__suggest_ids_calc) 
                   | (0x0fffffffffffffffULL & ((QData)((IData)(vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0)) 
                                               << (0x0000003fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.be_top__DOT__suggest_count_calc), 2U)))));
        }
        vlSelfRef.be_top__DOT__suggest_active_calc = 1U;
        vlSelfRef.be_top__DOT__suggest_count_calc = 
            (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.be_top__DOT__suggest_count_calc)));
    }
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
    if (be_top__DOT____VlemLogAnd_2) {
        be_top__DOT____VlemLogAnd_2 = (6U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 4U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x72U;
                            }
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x61U : 0x74U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x73U : 0x5cU));
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x79U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6eU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x61U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x6eU : 0x69U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x77U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x68U : 0x67U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x75U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x6cU
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[0U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 1U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 1U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 4U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x72U;
                            }
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x61U : 0x74U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x73U : 0x5cU));
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x79U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6eU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x61U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x6eU : 0x69U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x77U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x68U : 0x67U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x75U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x6cU
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[1U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 2U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 4U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x72U;
                            }
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x61U : 0x74U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x73U : 0x5cU));
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x79U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6eU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x61U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x6eU : 0x69U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x77U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x68U : 0x67U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x75U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x6cU
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[2U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 3U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 3U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 4U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x72U;
                            }
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x61U : 0x74U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x73U : 0x5cU));
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x79U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6eU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x61U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x6eU : 0x69U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x77U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x68U : 0x67U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x75U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x6cU
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[3U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 4U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 4U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 4U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x72U;
                            }
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x61U : 0x74U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x73U : 0x5cU));
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                 >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x79U : 0x72U);
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6eU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x61U : 0x5cU));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6bU;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x6eU : 0x69U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x77U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x68U : 0x67U);
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x75U : 0x61U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x6cU
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[4U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
}
