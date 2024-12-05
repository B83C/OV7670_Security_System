// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb1.h for the primary calling header

#include "Vtb1__pch.h"
#include "Vtb1__Syms.h"
#include "Vtb1___024root.h"

void Vtb1___024root___ctor_var_reset(Vtb1___024root* vlSelf);

Vtb1___024root::Vtb1___024root(Vtb1__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb1___024root___ctor_var_reset(this);
}

void Vtb1___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb1___024root::~Vtb1___024root() {
}
