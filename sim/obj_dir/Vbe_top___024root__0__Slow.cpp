// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbe_top.h for the primary calling header

#include "Vbe_top__pch.h"

VL_ATTR_COLD void Vbe_top___024root___eval_static__TOP(Vbe_top___024root* vlSelf);
VL_ATTR_COLD void Vbe_top___024root____Vm_traceActivitySetAll(Vbe_top___024root* vlSelf);

VL_ATTR_COLD void Vbe_top___024root___eval_static(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_static\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbe_top___024root___eval_static__TOP(vlSelf);
    Vbe_top___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vbe_top___024root___eval_static__TOP(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_static__TOP\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.be_top__DOT__unnamedblk5__DOT__src = 0U;
}

VL_ATTR_COLD void Vbe_top___024root___eval_initial(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_initial\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vbe_top___024root___eval_final(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_final\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbe_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vbe_top___024root___eval_phase__stl(Vbe_top___024root* vlSelf);

VL_ATTR_COLD void Vbe_top___024root___eval_settle(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_settle\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vbe_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("rtl/backend/be_top.sv", 81, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vbe_top___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vbe_top___024root___eval_triggers_vec__stl(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_triggers_vec__stl\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vbe_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbe_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vbe_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vbe_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___trigger_anySet__stl\n"); );
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
extern const VlWide<32>/*1023:0*/ Vbe_top__ConstPool__CONST_h62f3a808_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vbe_top__ConstPool__TABLE_h729b8958_0;

VL_ATTR_COLD void Vbe_top___024root___stl_sequent__TOP__0(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___stl_sequent__TOP__0\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ be_top__DOT____VlemLogAnd_2;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.be_tx_valid = 0U;
    vlSelfRef.be_tx_frame_type = 0U;
    vlSelfRef.be_render_cmd = 0U;
    vlSelfRef.ui_popup_active = vlSelfRef.be_top__DOT__popup_active_q;
    vlSelfRef.ui_popup_type = vlSelfRef.be_top__DOT__popup_type_q;
    vlSelfRef.ui_popup_x = vlSelfRef.be_top__DOT__popup_x_q;
    vlSelfRef.ui_popup_y = vlSelfRef.be_top__DOT__popup_y_q;
    vlSelfRef.emoji_suggest_active = vlSelfRef.be_top__DOT__emoji_suggest_active_q;
    vlSelfRef.emoji_suggest_count = vlSelfRef.be_top__DOT__emoji_suggest_count_q;
    vlSelfRef.emoji_suggest_ids = vlSelfRef.be_top__DOT__emoji_suggest_ids_q;
    vlSelfRef.emoji_suggest_anchor_pos = vlSelfRef.be_top__DOT__emoji_suggest_anchor_q;
    vlSelfRef.be_has_quote = vlSelfRef.be_top__DOT__has_quote_q;
    vlSelfRef.line_len = vlSelfRef.be_top__DOT__len_q;
    vlSelfRef.cursor_pos = vlSelfRef.be_top__DOT__cursor_pos_q;
    vlSelfRef.be_render_peer_name_len = vlSelfRef.be_top__DOT__peer_name_len_q;
    vlSelfRef.be_render_peer_name[0U] = vlSelfRef.be_top__DOT__peer_name_q[0U];
    vlSelfRef.be_render_peer_name[1U] = vlSelfRef.be_top__DOT__peer_name_q[1U];
    vlSelfRef.be_render_peer_name[2U] = vlSelfRef.be_top__DOT__peer_name_q[2U];
    vlSelfRef.be_render_peer_name[3U] = vlSelfRef.be_top__DOT__peer_name_q[3U];
    vlSelfRef.enter_committed = vlSelfRef.be_top__DOT__enter_pulse_q;
    vlSelfRef.be_tx_len = 0U;
    VL_ASSIGN_W(1024, vlSelfRef.be_tx_payload, Vbe_top__ConstPool__CONST_hd6b7ba52_0);
    vlSelfRef.be_render_valid = 0U;
    vlSelfRef.be_render_side = 0U;
    vlSelfRef.be_render_status = 0U;
    vlSelfRef.be_render_cursor_pos = 0U;
    vlSelfRef.be_render_ascii = 0U;
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
    vlSelfRef.be_top__DOT__suggest_recompute = ((7U 
                                                 == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                                | ((8U 
                                                    == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                                   | ((6U 
                                                       == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                                      | ((IData)(vlSelfRef.be_top__DOT__click_walk_done_q) 
                                                         & (0x19U 
                                                            == (IData)(vlSelfRef.be_top__DOT__state_q))))));
    vlSelfRef.line_rd_data = vlSelfRef.be_top__DOT__line_buf
        [vlSelfRef.line_rd_idx];
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
    __Vtableidx1 = vlSelfRef.be_top__DOT__state_q;
    vlSelfRef.be_render_conn_state = Vbe_top__ConstPool__TABLE_h729b8958_0
        [__Vtableidx1];
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
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
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
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 5U;
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
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 4U;
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
        be_top__DOT____VlemLogAnd_2 = (5U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 5U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 5U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 5U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 5U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 5U;
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
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 5U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 5U;
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
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[5U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 6U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 5U;
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
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 5U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 6U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 6U;
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
}

VL_ATTR_COLD void Vbe_top___024root___stl_sequent__TOP__1(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___stl_sequent__TOP__1\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ be_top__DOT____VlemLogAnd_2;
    // Body
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 2U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 2U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 6U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 6U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 6U;
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
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 5U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 6U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 6U;
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
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 6U;
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
        be_top__DOT____VlemLogAnd_2 = (5U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 7U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 7U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 7U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 7U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 7U;
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
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 5U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 5U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 7U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 7U;
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
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 7U;
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
        be_top__DOT____VlemLogAnd_2 = (5U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 8U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 8U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 8U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 8U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 8U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 8U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 8U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 8U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 9U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 9U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 9U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 9U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 9U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 9U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 9U;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 9U;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0aU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0aU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0aU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0aU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0aU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0aU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0aU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 0x0aU;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0bU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0bU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0bU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0bU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0bU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0bU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0bU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x75U;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x70U;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:354: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 354, "");
                        }
                    }
                }
            } else {
                if ((0U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x5cU;
                } else if ((1U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                } else if ((2U == (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
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
                            VL_WRITEF_NX("[%0t] %%Error: chat_pkg.sv:346: Assertion failed in %m: unique case, but multiple matches found for '4'h%X'\n",4, 'M',vlSymsp->name(),"chat_pkg.emoji_token_char", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',4,(IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx));
                            VL_STOP_MT("rtl/pkg/chat_pkg.sv", 346, "");
                        }
                    }
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
                                ? 0x73U : 0x65U) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x79U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x72U : 0x69U) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x66U
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
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 0x0bU;
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
        be_top__DOT____VlemLogAnd_2 = (5U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0cU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0cU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0cU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0cU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0cU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0cU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0cU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 0x0cU;
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
        be_top__DOT____VlemLogAnd_2 = (5U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0dU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0dU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0dU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0dU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0dU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0dU;
        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x20U;
        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                            if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6fU;
                            }
                        } else {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x75U : 0x72U);
                        }
                    } else {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                            = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x69U : 0x61U)
                                : ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                    ? 0x6dU : 0x5cU));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__token_id))) {
            if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                            vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x65U;
                        }
                    }
                } else {
                    vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                        = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                ? 0x67U : 0x6fU) : 
                           ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                             ? 0x64U : 0x5cU));
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                             >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))) {
                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx)))) {
                        vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char = 0x6eU;
                    }
                }
            } else {
                vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char 
                    = ((2U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                        ? ((1U & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                            ? 0x77U : 0x6fU) : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_emoji_token_char__4__char_idx))
                                                 ? 0x64U
                                                 : 0x5cU));
            }
        }
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[5U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
}
