// =====================================================================
// fe_video_timing.sv  --  HSYNC/VSYNC/data_enable timing generator
// ---------------------------------------------------------------------
// Default geometry: 800x600 @ 72 Hz, pixel clock 50 MHz. This matches
// the parameters used in example/project-template-xilinx for the same
// HDMI IP (rgb2dvi). Override via parameters if a different mode is
// wired up.
//
// Outputs:
//   hdata, vdata          current pixel coordinate (0..H/VMAX-1)
//   hsync, vsync          sync pulses, polarity per HSPP / VSPP
//   data_enable           1 inside the visible (HSIZE x VSIZE) region
//
// Style note: the example file uses Verilog `always @(posedge clk)`
// without reset; we add an active-low rst_n so it fits this project's
// reset convention (matches every other module).
// =====================================================================

`ifndef FE_VIDEO_TIMING_SV
`define FE_VIDEO_TIMING_SV

module fe_video_timing
    import fe_pkg::*;
(
    input  logic                clk,
    input  logic                rst_n,
    output logic [HWIDTH-1:0]   hdata,
    output logic [HWIDTH-1:0]   vdata,
    output logic                hsync,
    output logic                vsync,
    output logic                data_enable
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            hdata <= '0;
        else if (hdata == HWIDTH'(HMAX - 1))
            hdata <= '0;
        else
            hdata <= hdata + 1'b1;
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            vdata <= '0;
        end else if (hdata == HWIDTH'(HMAX - 1)) begin
            if (vdata == HWIDTH'(VMAX - 1))
                vdata <= '0;
            else
                vdata <= vdata + 1'b1;
        end
    end

    assign hsync       = ((hdata >= HWIDTH'(HFP)) && (hdata < HWIDTH'(HSP)))
                         ? HSPP : ~HSPP;
    assign vsync       = ((vdata >= HWIDTH'(VFP)) && (vdata < HWIDTH'(VSP)))
                         ? VSPP : ~VSPP;
    assign data_enable = (hdata < HWIDTH'(HSIZE)) && (vdata < HWIDTH'(VSIZE));

endmodule

`endif  // FE_VIDEO_TIMING_SV
