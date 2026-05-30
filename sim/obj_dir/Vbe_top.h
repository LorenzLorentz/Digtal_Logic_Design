// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VBE_TOP_H_
#define VERILATED_VBE_TOP_H_  // guard

#include "verilated.h"

class Vbe_top__Syms;
class Vbe_top___024root;
class VerilatedVcdC;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vbe_top VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vbe_top__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rst_n,0,0);
    VL_IN8(&io_key_valid,0,0);
    VL_OUT8(&io_key_ready,0,0);
    VL_IN8(&io_key_type,2,0);
    VL_IN8(&io_key_ascii,7,0);
    VL_IN8(&io_mouse_click_valid,0,0);
    VL_IN8(&io_mouse_right_click_valid,0,0);
    VL_OUT8(&io_mouse_click_ready,0,0);
    VL_IN8(&fe_input_scroll_offset,3,0);
    VL_IN8(&fe_input_at_limit,0,0);
    VL_IN8(&fe_hist_wr_row,5,0);
    VL_IN8(&fe_hist_scroll_offset,5,0);
    VL_OUT8(&ui_popup_active,0,0);
    VL_OUT8(&ui_popup_type,1,0);
    VL_OUT8(&emoji_suggest_active,0,0);
    VL_OUT8(&emoji_suggest_count,3,0);
    VL_IN8(&cm_rx_valid,0,0);
    VL_OUT8(&cm_rx_ready,0,0);
    VL_IN8(&cm_rx_frame_type,2,0);
    VL_IN8(&cm_rx_seq,7,0);
    VL_IN8(&cm_status_valid,0,0);
    VL_OUT8(&cm_status_ready,0,0);
    VL_IN8(&cm_status_msg_id,7,0);
    VL_IN8(&cm_status_code,1,0);
    VL_OUT8(&be_tx_valid,0,0);
    VL_IN8(&be_tx_ready,0,0);
    VL_OUT8(&be_tx_frame_type,2,0);
    VL_OUT8(&be_tx_msg_id,7,0);
    VL_OUT8(&be_render_valid,0,0);
    VL_IN8(&be_render_ready,0,0);
    VL_OUT8(&be_render_cmd,3,0);
    VL_OUT8(&be_render_msg_id,7,0);
    VL_OUT8(&be_render_store_idx,5,0);
    VL_OUT8(&be_render_side,1,0);
    VL_OUT8(&be_render_status,1,0);
    VL_OUT8(&be_render_ascii,7,0);
    VL_OUT8(&be_render_conn_state,1,0);
    VL_OUT8(&be_has_quote,0,0);
    VL_IN8(&line_rd_idx,6,0);
    VL_OUT8(&line_rd_data,7,0);
    VL_OUT8(&enter_committed,0,0);
    VL_IN8(&store_rd_idx,5,0);
    VL_OUT8(&store_rd_valid,0,0);
    VL_OUT8(&store_rd_msg_id,7,0);
    VL_OUT8(&store_rd_side,1,0);
    VL_OUT8(&store_rd_status,1,0);
    VL_OUT8(&conn_state_obs,1,0);
    VL_IN16(&io_mouse_click_x,9,0);
    VL_IN16(&io_mouse_click_y,9,0);
    VL_OUT16(&ui_popup_x,9,0);
    VL_OUT16(&ui_popup_y,9,0);
    VL_OUT16(&emoji_suggest_anchor_pos,15,0);
    VL_IN16(&cm_rx_len,15,0);
    VL_OUT16(&be_tx_len,15,0);
    VL_OUT16(&be_render_len,15,0);
    VL_OUT16(&be_render_cursor_pos,15,0);
    VL_OUT16(&be_render_peer_name_len,15,0);
    VL_OUT16(&line_len,15,0);
    VL_OUT16(&cursor_pos,15,0);
    VL_OUT16(&store_rd_len,15,0);
    VL_INW(&fe_hist_owner_store_idx,383,0,12);
    VL_INW(&fe_hist_owner_side,127,0,4);
    VL_INW(&fe_hist_owner_width,447,0,14);
    VL_INW(&cm_rx_payload,1023,0,32);
    VL_OUTW(&be_tx_payload,1023,0,32);
    VL_OUTW(&be_render_payload,1023,0,32);
    VL_OUTW(&be_render_peer_name,127,0,4);
    VL_OUTW(&store_rd_payload,1023,0,32);
    VL_IN64(&fe_hist_owner_valid,63,0);
    VL_OUT64(&emoji_suggest_ids,59,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vbe_top___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vbe_top(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vbe_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vbe_top();
  private:
    VL_UNCOPYABLE(Vbe_top);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
