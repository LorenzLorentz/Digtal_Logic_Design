// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbe_top.h for the primary calling header

#include "Vbe_top__pch.h"

void Vbe_top___024root___nba_sequent__TOP__0(Vbe_top___024root* vlSelf);
void Vbe_top___024root___nba_sequent__TOP__1(Vbe_top___024root* vlSelf);
void Vbe_top___024root___nba_sequent__TOP__2(Vbe_top___024root* vlSelf);

void Vbe_top___024root___eval_nba(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_nba\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vbe_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vbe_top___024root___nba_sequent__TOP__1(vlSelf);
        Vbe_top___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vbe_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vbe_top___024root___eval_triggers_vec__act(Vbe_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbe_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vbe_top___024root___eval_phase__act(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_phase__act\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbe_top___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbe_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vbe_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vbe_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vbe_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vbe_top___024root___eval_phase__nba(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_phase__nba\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vbe_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vbe_top___024root___eval_nba(vlSelf);
        Vbe_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbe_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vbe_top___024root___eval_phase__ico(Vbe_top___024root* vlSelf);

void Vbe_top___024root___eval(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vbe_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("rtl/backend/be_top.sv", 81, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vbe_top___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vbe_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("rtl/backend/be_top.sv", 81, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vbe_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("rtl/backend/be_top.sv", 81, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vbe_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vbe_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vbe_top___024root___eval_debug_assertions(Vbe_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbe_top___024root___eval_debug_assertions\n"); );
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_key_valid & 0xfeU)))) {
        Verilated::overWidthError("io_key_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_key_type & 0xf8U)))) {
        Verilated::overWidthError("io_key_type");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_mouse_click_valid 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_mouse_click_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_mouse_right_click_valid 
                      & 0xfeU)))) {
        Verilated::overWidthError("io_mouse_right_click_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_mouse_click_x & 0xfc00U)))) {
        Verilated::overWidthError("io_mouse_click_x");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_mouse_click_y & 0xfc00U)))) {
        Verilated::overWidthError("io_mouse_click_y");
    }
    if (VL_UNLIKELY(((vlSelfRef.fe_input_scroll_offset 
                      & 0xf0U)))) {
        Verilated::overWidthError("fe_input_scroll_offset");
    }
    if (VL_UNLIKELY(((vlSelfRef.fe_input_at_limit & 0xfeU)))) {
        Verilated::overWidthError("fe_input_at_limit");
    }
    if (VL_UNLIKELY(((vlSelfRef.fe_hist_wr_row & 0xc0U)))) {
        Verilated::overWidthError("fe_hist_wr_row");
    }
    if (VL_UNLIKELY(((vlSelfRef.fe_hist_scroll_offset 
                      & 0xc0U)))) {
        Verilated::overWidthError("fe_hist_scroll_offset");
    }
    if (VL_UNLIKELY(((vlSelfRef.cm_rx_valid & 0xfeU)))) {
        Verilated::overWidthError("cm_rx_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.cm_rx_frame_type & 0xf8U)))) {
        Verilated::overWidthError("cm_rx_frame_type");
    }
    if (VL_UNLIKELY(((vlSelfRef.cm_status_valid & 0xfeU)))) {
        Verilated::overWidthError("cm_status_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.cm_status_code & 0xfcU)))) {
        Verilated::overWidthError("cm_status_code");
    }
    if (VL_UNLIKELY(((vlSelfRef.be_tx_ready & 0xfeU)))) {
        Verilated::overWidthError("be_tx_ready");
    }
    if (VL_UNLIKELY(((vlSelfRef.be_render_ready & 0xfeU)))) {
        Verilated::overWidthError("be_render_ready");
    }
    if (VL_UNLIKELY(((vlSelfRef.line_rd_idx & 0x80U)))) {
        Verilated::overWidthError("line_rd_idx");
    }
    if (VL_UNLIKELY(((vlSelfRef.store_rd_idx & 0xc0U)))) {
        Verilated::overWidthError("store_rd_idx");
    }
}
#endif  // VL_DEBUG
