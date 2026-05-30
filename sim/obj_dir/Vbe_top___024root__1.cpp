// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbe_top.h for the primary calling header

#include "Vbe_top__pch.h"

void Vbe_top___024root___nba_sequent__TOP__1(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___nba_sequent__TOP__1\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ be_top__DOT____VlemLogAnd_2;
    // Body
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
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
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
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
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
}

extern const VlWide<32>/*1023:0*/ Vbe_top__ConstPool__CONST_hd6b7ba52_0;

void Vbe_top___024root___nba_sequent__TOP__2(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___nba_sequent__TOP__2\n"); );
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
    be_top__DOT____VlemLogAnd_2 = vlSelfRef.be_top__DOT__suggest_prefix_valid;
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
    if (be_top__DOT____VlemLogAnd_2) {
        be_top__DOT____VlemLogAnd_2 = (5U >= (IData)(vlSelfRef.be_top__DOT__suggest_prefix_len));
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
    vlSelfRef.be_top__DOT__enc_done = ((0x18U == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                       & ((IData)(vlSelfRef.be_top__DOT__enc_src_q) 
                                          >= (IData)(vlSelfRef.be_top__DOT__len_q)));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_2 = ((2U 
                                                 == (IData)(vlSelfRef.be_top__DOT__state_q)) 
                                                | (0x11U 
                                                   == (IData)(vlSelfRef.be_top__DOT__state_q)));
    vlSelfRef.cm_status_ready = (5U == (IData)(vlSelfRef.be_top__DOT__state_q));
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
    vlSelfRef.conn_state_obs = vlSelfRef.be_render_conn_state;
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
