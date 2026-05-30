// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbe_top.h for the primary calling header

#include "Vbe_top__pch.h"

void Vbe_top___024root___ctor_var_reset(Vbe_top___024root* vlSelf);

Vbe_top___024root::Vbe_top___024root(Vbe_top__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vbe_top___024root___ctor_var_reset(this);
}

void Vbe_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vbe_top___024root::~Vbe_top___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
