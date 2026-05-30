// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbe_top.h for the primary calling header

#ifndef VERILATED_VBE_TOP___024ROOT_H_
#define VERILATED_VBE_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vbe_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbe_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(io_key_valid,0,0);
        VL_OUT8(io_key_ready,0,0);
        VL_IN8(io_key_type,2,0);
        VL_IN8(io_key_ascii,7,0);
        VL_IN8(io_mouse_click_valid,0,0);
        VL_IN8(io_mouse_right_click_valid,0,0);
        VL_OUT8(io_mouse_click_ready,0,0);
        VL_IN8(fe_input_scroll_offset,3,0);
        VL_IN8(fe_input_at_limit,0,0);
        VL_IN8(fe_hist_wr_row,5,0);
        VL_IN8(fe_hist_scroll_offset,5,0);
        VL_OUT8(ui_popup_active,0,0);
        VL_OUT8(ui_popup_type,1,0);
        VL_OUT8(emoji_suggest_active,0,0);
        VL_OUT8(emoji_suggest_count,3,0);
        VL_IN8(cm_rx_valid,0,0);
        VL_OUT8(cm_rx_ready,0,0);
        VL_IN8(cm_rx_frame_type,2,0);
        VL_IN8(cm_rx_seq,7,0);
        VL_IN8(cm_status_valid,0,0);
        VL_OUT8(cm_status_ready,0,0);
        VL_IN8(cm_status_msg_id,7,0);
        VL_IN8(cm_status_code,1,0);
        VL_OUT8(be_tx_valid,0,0);
        VL_IN8(be_tx_ready,0,0);
        VL_OUT8(be_tx_frame_type,2,0);
        VL_OUT8(be_tx_msg_id,7,0);
        VL_OUT8(be_render_valid,0,0);
        VL_IN8(be_render_ready,0,0);
        VL_OUT8(be_render_cmd,3,0);
        VL_OUT8(be_render_msg_id,7,0);
        VL_OUT8(be_render_store_idx,5,0);
        VL_OUT8(be_render_side,1,0);
        VL_OUT8(be_render_status,1,0);
        VL_OUT8(be_render_ascii,7,0);
        VL_OUT8(be_render_conn_state,1,0);
        VL_OUT8(be_has_quote,0,0);
        VL_IN8(line_rd_idx,6,0);
        VL_OUT8(line_rd_data,7,0);
        VL_OUT8(enter_committed,0,0);
        VL_IN8(store_rd_idx,5,0);
        VL_OUT8(store_rd_valid,0,0);
        VL_OUT8(store_rd_msg_id,7,0);
        VL_OUT8(store_rd_side,1,0);
        VL_OUT8(store_rd_status,1,0);
        VL_OUT8(conn_state_obs,1,0);
        CData/*3:0*/ be_top__DOT____Vlvbound_h86e6e933__0;
        CData/*7:0*/ be_top__DOT____Vlvbound_hf6bfe95c__0;
        CData/*7:0*/ be_top__DOT____VlemCall_5__emoji_token_char;
        CData/*0:0*/ be_top__DOT____VlemLogAnd_4;
        CData/*7:0*/ be_top__DOT____VlemCall_3__emoji_token_char;
        CData/*5:0*/ be_top__DOT__state_q;
        CData/*5:0*/ be_top__DOT__state_d;
        CData/*0:0*/ be_top__DOT__enter_pulse_q;
        CData/*4:0*/ be_top__DOT__input_newline_count_q;
        CData/*7:0*/ be_top__DOT__last_event_ascii_q;
        CData/*0:0*/ be_top__DOT__delete_was_newline_q;
        CData/*5:0*/ be_top__DOT__wr_ptr_q;
        CData/*7:0*/ be_top__DOT__next_msg_id_q;
        CData/*7:0*/ be_top__DOT__pending_msg_id_q;
        CData/*5:0*/ be_top__DOT__pending_store_idx_q;
        CData/*7:0*/ be_top__DOT__rx_seq_q;
    };
    struct {
        CData/*5:0*/ be_top__DOT__rx_store_idx_q;
        CData/*7:0*/ be_top__DOT__status_msg_id_q;
        CData/*1:0*/ be_top__DOT__status_status_q;
        CData/*0:0*/ be_top__DOT__click_pending_q;
        CData/*0:0*/ be_top__DOT__click_is_right_q;
        CData/*6:0*/ be_top__DOT__click_raw_col_q;
        CData/*5:0*/ be_top__DOT__click_screen_row_q;
        CData/*3:0*/ be_top__DOT__click_target_row_q;
        CData/*6:0*/ be_top__DOT__click_target_col_q;
        CData/*3:0*/ be_top__DOT__click_vis_row_q;
        CData/*6:0*/ be_top__DOT__click_vis_col_q;
        CData/*0:0*/ be_top__DOT__click_walk_done_q;
        CData/*0:0*/ be_top__DOT__popup_active_q;
        CData/*1:0*/ be_top__DOT__popup_type_q;
        CData/*5:0*/ be_top__DOT__menu_store_idx_q;
        CData/*0:0*/ be_top__DOT__has_quote_q;
        CData/*7:0*/ be_top__DOT__quoted_msg_id_q;
        CData/*1:0*/ be_top__DOT__quoted_side_q;
        CData/*0:0*/ be_top__DOT__disp_for_remote_q;
        CData/*0:0*/ be_top__DOT__quoted_store_valid;
        CData/*7:0*/ be_top__DOT__recall_msg_id_q;
        CData/*5:0*/ be_top__DOT__recall_store_idx_q;
        CData/*1:0*/ be_top__DOT__recall_side_q;
        CData/*0:0*/ be_top__DOT__recall_send_q;
        CData/*0:0*/ be_top__DOT__emoji_suggest_tracking_q;
        CData/*0:0*/ be_top__DOT__emoji_suggest_active_q;
        CData/*3:0*/ be_top__DOT__emoji_suggest_count_q;
        CData/*3:0*/ be_top__DOT__emoji_complete_token_q;
        CData/*0:0*/ be_top__DOT__key_char_insert_allowed;
        CData/*0:0*/ be_top__DOT__click_in_sticker_picker;
        CData/*0:0*/ be_top__DOT__click_in_msg_menu;
        CData/*0:0*/ be_top__DOT__click_msg_menu_quote;
        CData/*0:0*/ be_top__DOT__click_msg_menu_recall;
        CData/*0:0*/ be_top__DOT__click_in_emoji_suggest;
        CData/*3:0*/ be_top__DOT__click_emoji_token_id;
        CData/*0:0*/ be_top__DOT__click_emoji_fits;
        CData/*5:0*/ be_top__DOT__click_hist_slot;
        CData/*1:0*/ be_top__DOT__click_hist_owner_side;
        CData/*6:0*/ be_top__DOT__click_hist_owner_width;
        CData/*0:0*/ be_top__DOT__click_in_hist_bubble;
        CData/*0:0*/ be_top__DOT__suggest_recompute;
        CData/*0:0*/ be_top__DOT__suggest_tracking_base;
        CData/*0:0*/ be_top__DOT__suggest_prefix_valid;
        CData/*3:0*/ be_top__DOT__suggest_count_calc;
        CData/*0:0*/ be_top__DOT__suggest_active_calc;
        CData/*7:0*/ be_top__DOT__enc_emit_byte;
        CData/*3:0*/ be_top__DOT__enc_src_delta;
        CData/*0:0*/ be_top__DOT__enc_done;
        CData/*0:0*/ be_top__DOT__peer_name_changed;
        CData/*0:0*/ be_top__DOT__accept_io;
        CData/*0:0*/ be_top__DOT__accept_rx;
        CData/*0:0*/ be_top__DOT__accept_status;
        CData/*0:0*/ be_top__DOT__accept_mouse_click;
        CData/*0:0*/ be_top__DOT__accept_username_frame;
        CData/*0:0*/ be_top__DOT__store_wr_en;
        CData/*7:0*/ be_top__DOT__store_wr_msg_id;
        CData/*1:0*/ be_top__DOT__store_wr_side;
        CData/*1:0*/ be_top__DOT__store_wr_status;
        CData/*0:0*/ be_top__DOT__store_lookup_hit;
        CData/*5:0*/ be_top__DOT__store_lookup_idx;
        CData/*0:0*/ be_top__DOT__use_quote_lkup;
        CData/*0:0*/ be_top__DOT__rx_quote_entry;
        CData/*0:0*/ be_top__DOT__unnamedblk2__DOT__unnamedblk3__DOT__token_match;
        CData/*6:0*/ be_top__DOT__unnamedblk8__DOT__raw_col;
    };
    struct {
        CData/*5:0*/ be_top__DOT__unnamedblk8__DOT__buf_row;
        CData/*7:0*/ be_top__DOT__unnamedblk9__DOT__cur_byte;
        CData/*7:0*/ be_top__DOT__unnamedblk12__DOT__wr_byte;
        CData/*5:0*/ be_top__DOT__u_store__DOT__upd_idx;
        CData/*0:0*/ be_top__DOT__u_store__DOT__clear_en;
        CData/*5:0*/ be_top__DOT__u_store__DOT__rd2_idx;
        CData/*0:0*/ be_top__DOT__u_store__DOT__rd2_valid;
        CData/*7:0*/ be_top__DOT__u_store__DOT__rd2_msg_id;
        CData/*1:0*/ be_top__DOT__u_store__DOT__rd2_side;
        CData/*1:0*/ be_top__DOT__u_store__DOT__rd2_status;
        CData/*1:0*/ be_top__DOT__u_store__DOT__lookup_side;
        CData/*7:0*/ be_top__DOT__u_store__DOT__lookup_msg_id;
        CData/*3:0*/ __Vfunc_emoji_token_char__4__token_id;
        CData/*3:0*/ __Vfunc_emoji_token_char__4__char_idx;
        CData/*0:0*/ __VdfgRegularize_hebeb780c_0_2;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_IN16(io_mouse_click_x,9,0);
        VL_IN16(io_mouse_click_y,9,0);
        VL_OUT16(ui_popup_x,9,0);
        VL_OUT16(ui_popup_y,9,0);
        VL_OUT16(emoji_suggest_anchor_pos,15,0);
        VL_IN16(cm_rx_len,15,0);
        VL_OUT16(be_tx_len,15,0);
        VL_OUT16(be_render_len,15,0);
        VL_OUT16(be_render_cursor_pos,15,0);
        VL_OUT16(be_render_peer_name_len,15,0);
        VL_OUT16(line_len,15,0);
        VL_OUT16(cursor_pos,15,0);
        VL_OUT16(store_rd_len,15,0);
        SData/*15:0*/ be_top__DOT__len_q;
        SData/*15:0*/ be_top__DOT__cursor_pos_q;
        SData/*15:0*/ be_top__DOT__shift_idx_q;
        SData/*15:0*/ be_top__DOT__enc_src_q;
        SData/*15:0*/ be_top__DOT__enc_dst_q;
        SData/*15:0*/ be_top__DOT__pending_len_q;
        SData/*15:0*/ be_top__DOT__rx_len_q;
        SData/*15:0*/ be_top__DOT__peer_name_len_q;
        SData/*9:0*/ be_top__DOT__click_x_q;
        SData/*9:0*/ be_top__DOT__click_y_q;
        SData/*9:0*/ be_top__DOT__popup_x_q;
        SData/*9:0*/ be_top__DOT__popup_y_q;
        SData/*15:0*/ be_top__DOT__disp_len_q;
        SData/*15:0*/ be_top__DOT__disp_build_idx_q;
        SData/*15:0*/ be_top__DOT__emoji_suggest_anchor_q;
        SData/*15:0*/ be_top__DOT__emoji_complete_char_idx_q;
        SData/*15:0*/ be_top__DOT__emoji_complete_token_len_q;
        SData/*9:0*/ be_top__DOT__click_popup_dx;
        SData/*9:0*/ be_top__DOT__click_popup_dy;
        SData/*15:0*/ be_top__DOT__click_emoji_token_len;
        SData/*15:0*/ be_top__DOT__click_emoji_prefix_len;
        SData/*15:0*/ be_top__DOT__suggest_anchor_base;
        SData/*15:0*/ be_top__DOT__suggest_cursor_base;
        SData/*15:0*/ be_top__DOT__suggest_prefix_len;
        SData/*15:0*/ be_top__DOT__rx_len_clamped;
        SData/*15:0*/ be_top__DOT__rx_name_len_clamped;
        SData/*15:0*/ be_top__DOT__store_wr_len;
        SData/*15:0*/ be_top__DOT__unnamedblk11__DOT__src_len;
    };
    struct {
        SData/*15:0*/ be_top__DOT__unnamedblk11__DOT__copy_max;
        SData/*15:0*/ be_top__DOT__unnamedblk11__DOT__user_len;
        SData/*15:0*/ be_top__DOT__unnamedblk12__DOT__src_len;
        SData/*15:0*/ be_top__DOT__unnamedblk12__DOT__copy_len;
        SData/*15:0*/ be_top__DOT__unnamedblk12__DOT__user_start;
        SData/*15:0*/ be_top__DOT__unnamedblk12__DOT__user_len;
        SData/*15:0*/ be_top__DOT__u_store__DOT__rd2_len;
        VL_INW(fe_hist_owner_store_idx,383,0,12);
        VL_INW(fe_hist_owner_side,127,0,4);
        VL_INW(fe_hist_owner_width,447,0,14);
        VL_INW(cm_rx_payload,1023,0,32);
        VL_OUTW(be_tx_payload,1023,0,32);
        VL_OUTW(be_render_payload,1023,0,32);
        VL_OUTW(be_render_peer_name,127,0,4);
        VL_OUTW(store_rd_payload,1023,0,32);
        VlWide<32>/*1023:0*/ be_top__DOT__pending_payload_q;
        VlWide<32>/*1023:0*/ be_top__DOT__rx_payload_q;
        VlWide<4>/*127:0*/ be_top__DOT__peer_name_q;
        VlWide<32>/*1023:0*/ be_top__DOT__disp_payload_q;
        VlWide<32>/*1023:0*/ be_top__DOT__store_wr_payload;
        IData/*31:0*/ be_top__DOT__unnamedblk5__DOT__src;
        IData/*31:0*/ be_top__DOT__unnamedblk7__DOT__i;
        IData/*31:0*/ __VactIterCount;
        VL_IN64(fe_hist_owner_valid,63,0);
        VL_OUT64(emoji_suggest_ids,59,0);
        QData/*59:0*/ be_top__DOT__emoji_suggest_ids_q;
        QData/*59:0*/ be_top__DOT__suggest_ids_calc;
        VlUnpacked<CData/*7:0*/, 128> be_top__DOT__line_buf;
        VlUnpacked<CData/*7:0*/, 7> be_top__DOT__suggest_prefix_byte;
        VlUnpacked<VlWide<33>/*1052:0*/, 64> be_top__DOT__u_store__DOT__store;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 128>, false, CData/*7:0*/, 1> __VdlyCommitQueuebe_top__DOT__line_buf;

    // INTERNAL VARIABLES
    Vbe_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vbe_top___024root(Vbe_top__Syms* symsp, const char* namep);
    ~Vbe_top___024root();
    VL_UNCOPYABLE(Vbe_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
