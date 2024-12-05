// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb2.h for the primary calling header

#include "Vtb2__pch.h"
#include "Vtb2__Syms.h"
#include "Vtb2___024root.h"

void Vtb2___024root___ctor_var_reset(Vtb2___024root* vlSelf);

Vtb2___024root::Vtb2___024root(Vtb2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb2___024root___ctor_var_reset(this);
}

void Vtb2___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb2___024root::~Vtb2___024root() {
}
