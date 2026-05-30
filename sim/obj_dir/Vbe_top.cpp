// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbe_top__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vbe_top::Vbe_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbe_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , io_key_valid{vlSymsp->TOP.io_key_valid}
    , io_key_ready{vlSymsp->TOP.io_key_ready}
    , io_key_type{vlSymsp->TOP.io_key_type}
    , io_key_ascii{vlSymsp->TOP.io_key_ascii}
    , io_mouse_click_valid{vlSymsp->TOP.io_mouse_click_valid}
    , io_mouse_right_click_valid{vlSymsp->TOP.io_mouse_right_click_valid}
    , io_mouse_click_ready{vlSymsp->TOP.io_mouse_click_ready}
    , fe_input_scroll_offset{vlSymsp->TOP.fe_input_scroll_offset}
    , fe_input_at_limit{vlSymsp->TOP.fe_input_at_limit}
    , fe_hist_wr_row{vlSymsp->TOP.fe_hist_wr_row}
    , fe_hist_scroll_offset{vlSymsp->TOP.fe_hist_scroll_offset}
    , ui_popup_active{vlSymsp->TOP.ui_popup_active}
    , ui_popup_type{vlSymsp->TOP.ui_popup_type}
    , emoji_suggest_active{vlSymsp->TOP.emoji_suggest_active}
    , emoji_suggest_count{vlSymsp->TOP.emoji_suggest_count}
    , cm_rx_valid{vlSymsp->TOP.cm_rx_valid}
    , cm_rx_ready{vlSymsp->TOP.cm_rx_ready}
    , cm_rx_frame_type{vlSymsp->TOP.cm_rx_frame_type}
    , cm_rx_seq{vlSymsp->TOP.cm_rx_seq}
    , cm_status_valid{vlSymsp->TOP.cm_status_valid}
    , cm_status_ready{vlSymsp->TOP.cm_status_ready}
    , cm_status_msg_id{vlSymsp->TOP.cm_status_msg_id}
    , cm_status_code{vlSymsp->TOP.cm_status_code}
    , be_tx_valid{vlSymsp->TOP.be_tx_valid}
    , be_tx_ready{vlSymsp->TOP.be_tx_ready}
    , be_tx_frame_type{vlSymsp->TOP.be_tx_frame_type}
    , be_tx_msg_id{vlSymsp->TOP.be_tx_msg_id}
    , be_render_valid{vlSymsp->TOP.be_render_valid}
    , be_render_ready{vlSymsp->TOP.be_render_ready}
    , be_render_cmd{vlSymsp->TOP.be_render_cmd}
    , be_render_msg_id{vlSymsp->TOP.be_render_msg_id}
    , be_render_store_idx{vlSymsp->TOP.be_render_store_idx}
    , be_render_side{vlSymsp->TOP.be_render_side}
    , be_render_status{vlSymsp->TOP.be_render_status}
    , be_render_ascii{vlSymsp->TOP.be_render_ascii}
    , be_render_conn_state{vlSymsp->TOP.be_render_conn_state}
    , be_has_quote{vlSymsp->TOP.be_has_quote}
    , line_rd_idx{vlSymsp->TOP.line_rd_idx}
    , line_rd_data{vlSymsp->TOP.line_rd_data}
    , enter_committed{vlSymsp->TOP.enter_committed}
    , store_rd_idx{vlSymsp->TOP.store_rd_idx}
    , store_rd_valid{vlSymsp->TOP.store_rd_valid}
    , store_rd_msg_id{vlSymsp->TOP.store_rd_msg_id}
    , store_rd_side{vlSymsp->TOP.store_rd_side}
    , store_rd_status{vlSymsp->TOP.store_rd_status}
    , conn_state_obs{vlSymsp->TOP.conn_state_obs}
    , io_mouse_click_x{vlSymsp->TOP.io_mouse_click_x}
    , io_mouse_click_y{vlSymsp->TOP.io_mouse_click_y}
    , ui_popup_x{vlSymsp->TOP.ui_popup_x}
    , ui_popup_y{vlSymsp->TOP.ui_popup_y}
    , emoji_suggest_anchor_pos{vlSymsp->TOP.emoji_suggest_anchor_pos}
    , cm_rx_len{vlSymsp->TOP.cm_rx_len}
    , be_tx_len{vlSymsp->TOP.be_tx_len}
    , be_render_len{vlSymsp->TOP.be_render_len}
    , be_render_cursor_pos{vlSymsp->TOP.be_render_cursor_pos}
    , be_render_peer_name_len{vlSymsp->TOP.be_render_peer_name_len}
    , line_len{vlSymsp->TOP.line_len}
    , cursor_pos{vlSymsp->TOP.cursor_pos}
    , store_rd_len{vlSymsp->TOP.store_rd_len}
    , fe_hist_owner_store_idx{vlSymsp->TOP.fe_hist_owner_store_idx}
    , fe_hist_owner_side{vlSymsp->TOP.fe_hist_owner_side}
    , fe_hist_owner_width{vlSymsp->TOP.fe_hist_owner_width}
    , cm_rx_payload{vlSymsp->TOP.cm_rx_payload}
    , be_tx_payload{vlSymsp->TOP.be_tx_payload}
    , be_render_payload{vlSymsp->TOP.be_render_payload}
    , be_render_peer_name{vlSymsp->TOP.be_render_peer_name}
    , store_rd_payload{vlSymsp->TOP.store_rd_payload}
    , fe_hist_owner_valid{vlSymsp->TOP.fe_hist_owner_valid}
    , emoji_suggest_ids{vlSymsp->TOP.emoji_suggest_ids}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vbe_top::Vbe_top(const char* _vcname__)
    : Vbe_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbe_top::~Vbe_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbe_top___024root___eval_debug_assertions(Vbe_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vbe_top___024root___eval_static(Vbe_top___024root* vlSelf);
void Vbe_top___024root___eval_initial(Vbe_top___024root* vlSelf);
void Vbe_top___024root___eval_settle(Vbe_top___024root* vlSelf);
void Vbe_top___024root___eval(Vbe_top___024root* vlSelf);

void Vbe_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbe_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbe_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbe_top___024root___eval_static(&(vlSymsp->TOP));
        Vbe_top___024root___eval_initial(&(vlSymsp->TOP));
        Vbe_top___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbe_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vbe_top::eventsPending() { return false; }

uint64_t Vbe_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vbe_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbe_top___024root___eval_final(Vbe_top___024root* vlSelf);

VL_ATTR_COLD void Vbe_top::final() {
    contextp()->executingFinal(true);
    Vbe_top___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbe_top::hierName() const { return vlSymsp->name(); }
const char* Vbe_top::modelName() const { return "Vbe_top"; }
unsigned Vbe_top::threads() const { return 1; }
void Vbe_top::prepareClone() const { contextp()->prepareClone(); }
void Vbe_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vbe_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vbe_top___024root__trace_decl_types(VerilatedVcd* tracep);

void Vbe_top___024root__trace_init_top(Vbe_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbe_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbe_top___024root*>(voidSelf);
    Vbe_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vbe_top___024root__trace_decl_types(tracep);
    Vbe_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vbe_top___024root__trace_register(Vbe_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbe_top::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vbe_top::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 690);
    Vbe_top___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
