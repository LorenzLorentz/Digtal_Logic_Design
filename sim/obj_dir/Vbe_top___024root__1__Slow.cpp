// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbe_top.h for the primary calling header

#include "Vbe_top__pch.h"

extern const VlWide<32>/*1023:0*/ Vbe_top__ConstPool__CONST_hd6b7ba52_0;

VL_ATTR_COLD void Vbe_top___024root___stl_sequent__TOP__2(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___stl_sequent__TOP__2\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ be_top__DOT____VlemLogAnd_2;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_1;
    __VdfgRegularize_hebeb780c_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_3;
    __VdfgRegularize_hebeb780c_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_4;
    __VdfgRegularize_hebeb780c_0_4 = 0;
    // Body
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 6U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 6U;
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
        vlSelfRef.be_top__DOT____VlemLogAnd_4 = (vlSelfRef.be_top__DOT__suggest_prefix_byte[6U] 
                                                 != (IData)(vlSelfRef.be_top__DOT____VlemCall_3__emoji_token_char));
    }
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match = 0U;
    }
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
    if (be_top__DOT____VlemLogAnd_2) {
        be_top__DOT____VlemLogAnd_2 = (7U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    }
    if (vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match) {
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 0x0dU;
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
    vlSelfRef.be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match 
        = be_top__DOT____VlemLogAnd_2;
    vlSelfRef.be_top__DOT____VlemLogAnd_4 = VL_LTS_III(32, 0U, (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
    if (vlSelfRef.be_top__DOT____VlemLogAnd_4) {
        vlSelfRef.__Vfunc_emoji_token_char__4__char_idx = 0U;
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0eU;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0eU;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0eU;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0eU;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0eU;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0eU;
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
        vlSelfRef.__Vfunc_emoji_token_char__4__token_id = 0x0eU;
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
        vlSelfRef.be_top__DOT____Vlvbound_h86e6e933__0 = 0x0eU;
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
    vlSelfRef.be_top__DOT__key_char_insert_allowed 
        = ((0x0080U > (IData)(vlSelfRef.be_top__DOT__len_q)) 
           & ((0x0aU != (IData)(vlSelfRef.io_key_ascii)) 
              | ((~ (IData)(vlSelfRef.fe_input_at_limit)) 
                 & (0x0fU > (IData)(vlSelfRef.be_top__DOT__input_newline_count_q)))));
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
    vlSelfRef.be_top__DOT__click_emoji_prefix_len = 
        (0x0000ffffU & ((IData)(vlSelfRef.be_top__DOT__cursor_pos_q) 
                        - (IData)(vlSelfRef.be_top__DOT__emoji_suggest_anchor_q)));
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
    vlSelfRef.be_top__DOT__click_popup_dx = (0x000003ffU 
                                             & ((IData)(vlSelfRef.be_top__DOT__click_x_q) 
                                                - (IData)(vlSelfRef.be_top__DOT__popup_x_q)));
    vlSelfRef.be_top__DOT__click_popup_dy = (0x000003ffU 
                                             & ((IData)(vlSelfRef.be_top__DOT__click_y_q) 
                                                - (IData)(vlSelfRef.be_top__DOT__popup_y_q)));
    vlSelfRef.be_top__DOT__enc_done = ((0x18U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                       & ((IData)(vlSelfRef.be_top__DOT__enc_src_q) 
                                          >= (IData)(vlSelfRef.be_top__DOT__len_q)));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_2 = ((2U 
                                                 == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                                | (0x11U 
                                                   == (IData)(vlSelfRef.be_top__DOT__state_q)));
    vlSelfRef.cm_status_ready = (5U == (IData)(vlSelfRef.be_top__DOT__state_q));
    vlSelfRef.conn_state_obs = vlSelfRef.be_render_conn_state;
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
    vlSelfRef.be_top__DOT__click_emoji_token_len = 
        ((8U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
          ? ((4U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
              ? ((2U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
                  ? (7U & (- (IData)((1U & (~ (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))))))
                  : 5U) : ((2U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
                            ? 3U : ((1U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
                                     ? 4U : 5U))) : 
         ((4U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
           ? ((1U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
               ? 5U : 6U) : ((2U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
                              ? ((1U & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
                                  ? 3U : 6U) : ((1U 
                                                 & (IData)(vlSelfRef.be_top__DOT__click_emoji_token_id))
                                                 ? 4U
                                                 : 6U))));
    vlSelfRef.be_top__DOT__click_in_sticker_picker 
        = ((IData)(vlSelfRef.be_top__DOT__popup_active_q) 
           & ((2U == (IData)(vlSelfRef.be_top__DOT__popup_type_q)) 
              & ((0x0140U > (IData)(vlSelfRef.be_top__DOT__click_popup_dx)) 
                 & (0x0050U > (IData)(vlSelfRef.be_top__DOT__click_popup_dy)))));
    vlSelfRef.be_top__DOT__click_in_msg_menu = ((IData)(vlSelfRef.be_top__DOT__popup_active_q) 
                                                & ((1U 
                                                    == (IData)(vlSelfRef.be_top__DOT__popup_type_q)) 
                                                   & ((0x0070U 
                                                       > (IData)(vlSelfRef.be_top__DOT__click_popup_dx)) 
                                                      & (0x0034U 
                                                         > (IData)(vlSelfRef.be_top__DOT__click_popup_dy)))));
    vlSelfRef.be_top__DOT__accept_status = ((IData)(vlSelfRef.cm_status_valid) 
                                            & (IData)(vlSelfRef.cm_status_ready));
    __VdfgRegularize_hebeb780c_0_4 = ((~ (IData)(vlSelfRef.cm_status_valid)) 
                                      & (IData)(vlSelfRef.cm_status_ready));
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
    vlSelfRef.be_top__DOT__click_emoji_fits = (0x0080U 
                                               >= (0x0000ffffU 
                                                   & ((IData)(vlSelfRef.be_top__DOT__len_q) 
                                                      + 
                                                      (((IData)(vlSelfRef.be_top__DOT__click_emoji_token_len) 
                                                        - (IData)(vlSelfRef.be_top__DOT__click_emoji_prefix_len)) 
                                                       & (- (IData)(
                                                                    ((IData)(vlSelfRef.be_top__DOT__click_emoji_token_len) 
                                                                     > (IData)(vlSelfRef.be_top__DOT__click_emoji_prefix_len))))))));
    vlSelfRef.be_top__DOT__click_msg_menu_quote = ((IData)(vlSelfRef.be_top__DOT__click_in_msg_menu) 
                                                   & ((2U 
                                                       <= (IData)(vlSelfRef.be_top__DOT__click_popup_dy)) 
                                                      & (0x001aU 
                                                         > (IData)(vlSelfRef.be_top__DOT__click_popup_dy))));
    vlSelfRef.be_top__DOT__click_msg_menu_recall = 
        ((IData)(vlSelfRef.be_top__DOT__click_in_msg_menu) 
         & ((0x001aU <= (IData)(vlSelfRef.be_top__DOT__click_popup_dy)) 
            & (0x0032U > (IData)(vlSelfRef.be_top__DOT__click_popup_dy))));
    __VdfgRegularize_hebeb780c_0_3 = ((~ (IData)(vlSelfRef.cm_rx_valid)) 
                                      & (IData)(__VdfgRegularize_hebeb780c_0_4));
    vlSelfRef.cm_rx_ready = ((IData)(__VdfgRegularize_hebeb780c_0_4) 
                             | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2));
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

VL_ATTR_COLD void Vbe_top___024root___stl_sequent__TOP__0(Vbe_top___024root* vlSelf);
VL_ATTR_COLD void Vbe_top___024root____Vm_traceActivitySetAll(Vbe_top___024root* vlSelf);
VL_ATTR_COLD void Vbe_top___024root___stl_sequent__TOP__1(Vbe_top___024root* vlSelf);

VL_ATTR_COLD void Vbe_top___024root___eval_stl(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_stl\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vbe_top___024root___stl_sequent__TOP__0(vlSelf);
        Vbe_top___024root____Vm_traceActivitySetAll(vlSelf);
        Vbe_top___024root___stl_sequent__TOP__1(vlSelf);
        Vbe_top___024root___stl_sequent__TOP__2(vlSelf);
    }
}

VL_ATTR_COLD void Vbe_top___024root___eval_triggers_vec__stl(Vbe_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbe_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vbe_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vbe_top___024root___eval_phase__stl(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_phase__stl\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vbe_top___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbe_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vbe_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vbe_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vbe_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbe_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vbe_top___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vbe_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbe_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vbe_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbe_top___024root____Vm_traceActivitySetAll(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root____Vm_traceActivitySetAll\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vbe_top___024root___ctor_var_reset(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___ctor_var_reset\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->io_key_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14468598666592724630ull);
    vlSelf->io_key_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7563600099765370594ull);
    vlSelf->io_key_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7951939048399629318ull);
    vlSelf->io_key_ascii = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10208388207808895786ull);
    vlSelf->io_mouse_click_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11073975203186988160ull);
    vlSelf->io_mouse_right_click_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12542786677020000100ull);
    vlSelf->io_mouse_click_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5101895626509182549ull);
    vlSelf->io_mouse_click_x = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 7658359574549304467ull);
    vlSelf->io_mouse_click_y = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 12604495064803163175ull);
    vlSelf->fe_input_scroll_offset = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11175833546361302208ull);
    vlSelf->fe_input_at_limit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13576857693337438457ull);
    vlSelf->fe_hist_wr_row = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 633443654309573181ull);
    vlSelf->fe_hist_scroll_offset = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10343230007041475699ull);
    vlSelf->fe_hist_owner_valid = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3499295851256957997ull);
    VL_SCOPED_RAND_RESET_W(384, vlSelf->fe_hist_owner_store_idx, __VscopeHash, 1977091735483601071ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->fe_hist_owner_side, __VscopeHash, 12989359890689267126ull);
    VL_SCOPED_RAND_RESET_W(448, vlSelf->fe_hist_owner_width, __VscopeHash, 17657872030791028749ull);
    vlSelf->ui_popup_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11700351050737009470ull);
    vlSelf->ui_popup_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17970796261913555944ull);
    vlSelf->ui_popup_x = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 1064766184153203437ull);
    vlSelf->ui_popup_y = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 2552656102635217814ull);
    vlSelf->emoji_suggest_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8776970172629260986ull);
    vlSelf->emoji_suggest_count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7337783165977595016ull);
    vlSelf->emoji_suggest_ids = VL_SCOPED_RAND_RESET_Q(60, __VscopeHash, 9230476364387508926ull);
    vlSelf->emoji_suggest_anchor_pos = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4356037203699348304ull);
    vlSelf->cm_rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8019230962405199071ull);
    vlSelf->cm_rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7977744384043879102ull);
    vlSelf->cm_rx_frame_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1353827214893587282ull);
    vlSelf->cm_rx_seq = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13419730462759681849ull);
    vlSelf->cm_rx_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18091251118280477229ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->cm_rx_payload, __VscopeHash, 585385175771397160ull);
    vlSelf->cm_status_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8072832978797526727ull);
    vlSelf->cm_status_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8387692364994233153ull);
    vlSelf->cm_status_msg_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1140734897198924229ull);
    vlSelf->cm_status_code = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2117311642163070460ull);
    vlSelf->be_tx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15027193692757326602ull);
    vlSelf->be_tx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7649736232165457202ull);
    vlSelf->be_tx_frame_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5611884344568305139ull);
    vlSelf->be_tx_msg_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14186212345337382463ull);
    vlSelf->be_tx_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14187732015763065254ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->be_tx_payload, __VscopeHash, 11951531860168965573ull);
    vlSelf->be_render_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4631410131096404515ull);
    vlSelf->be_render_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6718700920092992354ull);
    vlSelf->be_render_cmd = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11222593107816340699ull);
    vlSelf->be_render_msg_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17227375274580329067ull);
    vlSelf->be_render_store_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8733004845065327432ull);
    vlSelf->be_render_side = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1997250506001185315ull);
    vlSelf->be_render_status = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14992078147406937280ull);
    vlSelf->be_render_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2362559519729342266ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->be_render_payload, __VscopeHash, 17693376060136172927ull);
    vlSelf->be_render_cursor_pos = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7542311894768515446ull);
    vlSelf->be_render_ascii = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17061054140864781557ull);
    vlSelf->be_render_conn_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10620374978968576016ull);
    vlSelf->be_render_peer_name_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12082303251650312529ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->be_render_peer_name, __VscopeHash, 7014995531737426365ull);
    vlSelf->be_has_quote = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10141204395364038774ull);
    vlSelf->line_rd_idx = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 8949307196076854779ull);
    vlSelf->line_rd_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17463317174746383162ull);
    vlSelf->line_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8813855322153297456ull);
    vlSelf->cursor_pos = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12243903880385782064ull);
    vlSelf->enter_committed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11891113812489561830ull);
    vlSelf->store_rd_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 17064549174954244086ull);
    vlSelf->store_rd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 425629440428010762ull);
    vlSelf->store_rd_msg_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11562283851546827889ull);
    vlSelf->store_rd_side = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16020037329022776958ull);
    vlSelf->store_rd_status = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9485139174532293541ull);
    vlSelf->store_rd_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7893984997712883944ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->store_rd_payload, __VscopeHash, 11584085237544412196ull);
    vlSelf->conn_state_obs = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15205964322071940027ull);
    vlSelf->be_top__DOT____Vlvbound_h86e6e933__0 = 0;
    vlSelf->be_top__DOT____Vlvbound_hf6bfe95c__0 = 0;
    vlSelf->be_top__DOT__state_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11479885449732964899ull);
    vlSelf->be_top__DOT__state_d = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 18319577918865967077ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->be_top__DOT__line_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8744543112459007702ull);
    }
    vlSelf->be_top__DOT__len_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16486498002043329993ull);
    vlSelf->be_top__DOT__cursor_pos_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11029153693363364167ull);
    vlSelf->be_top__DOT__enter_pulse_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13007382673955429998ull);
    vlSelf->be_top__DOT__input_newline_count_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9356451696309292964ull);
    vlSelf->be_top__DOT__last_event_ascii_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7019370925738262017ull);
    vlSelf->be_top__DOT__delete_was_newline_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7310108980886427084ull);
    vlSelf->be_top__DOT__shift_idx_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3090990575449601786ull);
    vlSelf->be_top__DOT__enc_src_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15636824729567435855ull);
    vlSelf->be_top__DOT__enc_dst_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13536188723042273289ull);
    vlSelf->be_top__DOT__wr_ptr_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 3861141964593579987ull);
    vlSelf->be_top__DOT__next_msg_id_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3446651736611933089ull);
    vlSelf->be_top__DOT__pending_msg_id_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4197248625018023695ull);
    vlSelf->be_top__DOT__pending_store_idx_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 2983124031353658430ull);
    vlSelf->be_top__DOT__pending_len_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8935169774986196243ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->be_top__DOT__pending_payload_q, __VscopeHash, 11481055658210573815ull);
    vlSelf->be_top__DOT__rx_seq_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14265964035700886079ull);
    vlSelf->be_top__DOT__rx_store_idx_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14524327009598243554ull);
    vlSelf->be_top__DOT__rx_len_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11604755420078980116ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->be_top__DOT__rx_payload_q, __VscopeHash, 12764001732361018939ull);
    vlSelf->be_top__DOT__status_msg_id_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14166297337482378950ull);
    vlSelf->be_top__DOT__status_status_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 608865054778202150ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->be_top__DOT__peer_name_q, __VscopeHash, 7075140349953345581ull);
    vlSelf->be_top__DOT__peer_name_len_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2579401380715816907ull);
    vlSelf->be_top__DOT__click_pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8602930290968300560ull);
    vlSelf->be_top__DOT__click_is_right_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1082649311009809189ull);
    vlSelf->be_top__DOT__click_x_q = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 12325300760355133897ull);
    vlSelf->be_top__DOT__click_y_q = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 382292048277506858ull);
    vlSelf->be_top__DOT__click_raw_col_q = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 2027678345425389369ull);
    vlSelf->be_top__DOT__click_screen_row_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 2482893464982312990ull);
    vlSelf->be_top__DOT__click_target_row_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9682939743954720652ull);
    vlSelf->be_top__DOT__click_target_col_q = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 11591709410717300474ull);
    vlSelf->be_top__DOT__click_vis_row_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7973269997817620214ull);
    vlSelf->be_top__DOT__click_vis_col_q = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 4430525319714286884ull);
    vlSelf->be_top__DOT__click_walk_done_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6504794223648400755ull);
    vlSelf->be_top__DOT__popup_active_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1224990512836631285ull);
    vlSelf->be_top__DOT__popup_type_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5739758753001127893ull);
    vlSelf->be_top__DOT__popup_x_q = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 11960966630556916849ull);
    vlSelf->be_top__DOT__popup_y_q = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 163782627260298864ull);
    vlSelf->be_top__DOT__menu_store_idx_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 15940990162513911639ull);
    vlSelf->be_top__DOT__has_quote_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11924004065478989455ull);
    vlSelf->be_top__DOT__quoted_msg_id_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18114503969768451548ull);
    vlSelf->be_top__DOT__quoted_side_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5519942704909937870ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->be_top__DOT__disp_payload_q, __VscopeHash, 2067346932395802224ull);
    vlSelf->be_top__DOT__disp_len_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15984014963311062310ull);
    vlSelf->be_top__DOT__disp_build_idx_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16003233174021320231ull);
    vlSelf->be_top__DOT__disp_for_remote_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11600369970826924917ull);
    vlSelf->be_top__DOT__quoted_store_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 731867310921036309ull);
    vlSelf->be_top__DOT__recall_msg_id_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7292000818725407801ull);
    vlSelf->be_top__DOT__recall_store_idx_q = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10995278290920103215ull);
    vlSelf->be_top__DOT__recall_side_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8370849198371707361ull);
    vlSelf->be_top__DOT__recall_send_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11190045873886805295ull);
    vlSelf->be_top__DOT__emoji_suggest_tracking_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12769160913504464957ull);
    vlSelf->be_top__DOT__emoji_suggest_active_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7189974754451908029ull);
    vlSelf->be_top__DOT__emoji_suggest_count_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3357311263056442633ull);
    vlSelf->be_top__DOT__emoji_suggest_ids_q = VL_SCOPED_RAND_RESET_Q(60, __VscopeHash, 14232132682093566033ull);
    vlSelf->be_top__DOT__emoji_suggest_anchor_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7280366038174433049ull);
    vlSelf->be_top__DOT__emoji_complete_token_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15307217656150174417ull);
    vlSelf->be_top__DOT__emoji_complete_char_idx_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1311079369856100135ull);
    vlSelf->be_top__DOT__emoji_complete_token_len_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7232397597099228124ull);
    vlSelf->be_top__DOT__key_char_insert_allowed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17156040172442149085ull);
    vlSelf->be_top__DOT__click_popup_dx = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 8967112510039352084ull);
    vlSelf->be_top__DOT__click_popup_dy = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 6187696311704695933ull);
    vlSelf->be_top__DOT__click_in_sticker_picker = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7147714153575924183ull);
    vlSelf->be_top__DOT__click_in_msg_menu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5628793708533001312ull);
    vlSelf->be_top__DOT__click_msg_menu_quote = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15285069734536244445ull);
    vlSelf->be_top__DOT__click_msg_menu_recall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4719349183774473501ull);
    vlSelf->be_top__DOT__click_in_emoji_suggest = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5880787884799963840ull);
    vlSelf->be_top__DOT__click_emoji_token_id = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8345267948709748776ull);
    vlSelf->be_top__DOT__click_emoji_token_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13287825482852652088ull);
    vlSelf->be_top__DOT__click_emoji_prefix_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14588825074409212123ull);
    vlSelf->be_top__DOT__click_emoji_fits = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15349094185699605169ull);
    vlSelf->be_top__DOT__click_hist_slot = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11011913960788187261ull);
    vlSelf->be_top__DOT__click_hist_owner_side = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4404014063842770799ull);
    vlSelf->be_top__DOT__click_hist_owner_width = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 4336011790237542325ull);
    vlSelf->be_top__DOT__click_in_hist_bubble = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 571284511055980925ull);
    vlSelf->be_top__DOT__suggest_recompute = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10358456208535712524ull);
    vlSelf->be_top__DOT__suggest_tracking_base = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14418169330041261526ull);
    vlSelf->be_top__DOT__suggest_anchor_base = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5304988394935322901ull);
    vlSelf->be_top__DOT__suggest_cursor_base = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3723214637273929320ull);
    vlSelf->be_top__DOT__suggest_prefix_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17295403799865442265ull);
    vlSelf->be_top__DOT__suggest_prefix_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6371655253490920695ull);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->be_top__DOT__suggest_prefix_byte[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10858008987944572206ull);
    }
    vlSelf->be_top__DOT__suggest_count_calc = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16646230321392751751ull);
    vlSelf->be_top__DOT__suggest_ids_calc = VL_SCOPED_RAND_RESET_Q(60, __VscopeHash, 16328803516001721878ull);
    vlSelf->be_top__DOT__suggest_active_calc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3043903446998802400ull);
    vlSelf->be_top__DOT__enc_emit_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15925074944642198429ull);
    vlSelf->be_top__DOT__enc_src_delta = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4716001177691191459ull);
    vlSelf->be_top__DOT__enc_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7300761266949959182ull);
    vlSelf->be_top__DOT__rx_len_clamped = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11150261159960576757ull);
    vlSelf->be_top__DOT__rx_name_len_clamped = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8376395607537428106ull);
    vlSelf->be_top__DOT__peer_name_changed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13803891580630915351ull);
    vlSelf->be_top__DOT__accept_io = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12240795812318589590ull);
    vlSelf->be_top__DOT__accept_rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3779990499116789316ull);
    vlSelf->be_top__DOT__accept_status = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13800327305087675141ull);
    vlSelf->be_top__DOT__accept_mouse_click = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15532244643250207704ull);
    vlSelf->be_top__DOT__accept_username_frame = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11657836143717219754ull);
    vlSelf->be_top__DOT__store_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11919100270022226266ull);
    vlSelf->be_top__DOT__store_wr_msg_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16830740662778456110ull);
    vlSelf->be_top__DOT__store_wr_side = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16036534762549592106ull);
    vlSelf->be_top__DOT__store_wr_status = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16067598077586910364ull);
    vlSelf->be_top__DOT__store_wr_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6490521542522818310ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->be_top__DOT__store_wr_payload, __VscopeHash, 57837198330351863ull);
    vlSelf->be_top__DOT__store_lookup_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5792855155836559802ull);
    vlSelf->be_top__DOT__store_lookup_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6384297440310971480ull);
    vlSelf->be_top__DOT__use_quote_lkup = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5740853213289350736ull);
    vlSelf->be_top__DOT__rx_quote_entry = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5685560416455010525ull);
    vlSelf->be_top__DOT__unnamedblk7__DOT__i = 0;
    vlSelf->be_top__DOT__u_store__DOT__upd_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 15991177751711462066ull);
    vlSelf->be_top__DOT__u_store__DOT__clear_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15660662882842144074ull);
    vlSelf->be_top__DOT__u_store__DOT__rd2_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8221834129846253783ull);
    vlSelf->be_top__DOT__u_store__DOT__rd2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16111975057062962425ull);
    vlSelf->be_top__DOT__u_store__DOT__rd2_msg_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6573577366502813573ull);
    vlSelf->be_top__DOT__u_store__DOT__rd2_side = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10729624226470534408ull);
    vlSelf->be_top__DOT__u_store__DOT__rd2_status = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14885488862294011437ull);
    vlSelf->be_top__DOT__u_store__DOT__rd2_len = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7144575575199291453ull);
    vlSelf->be_top__DOT__u_store__DOT__lookup_side = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11478064398328829361ull);
    vlSelf->be_top__DOT__u_store__DOT__lookup_msg_id = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2617814610527948215ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(1053, vlSelf->be_top__DOT__u_store__DOT__store[__Vi0], __VscopeHash, 18030233302994607912ull);
    }
    vlSelf->__Vfunc_emoji_token_char__4__token_id = 0;
    vlSelf->__Vfunc_emoji_token_char__4__char_idx = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_2 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
