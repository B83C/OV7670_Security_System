// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb1.h for the primary calling header

#ifndef VERILATED_VTB1___024ROOT_H_
#define VERILATED_VTB1___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb1__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb1___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb1__DOT__clk;
    CData/*1:0*/ tb1__DOT__scale_cntr_x;
    CData/*1:0*/ tb1__DOT__scale_cntr_y;
    CData/*2:0*/ tb1__DOT__x_cntr;
    CData/*2:0*/ tb1__DOT__y_cntr;
    CData/*5:0*/ tb1__DOT__c_x;
    CData/*4:0*/ tb1__DOT__c_y;
    CData/*6:0*/ tb1__DOT__character_addr;
    CData/*3:0*/ tb1__DOT__r;
    CData/*3:0*/ tb1__DOT__g;
    CData/*3:0*/ tb1__DOT__b;
    CData/*0:0*/ __VdlyVal__tb1__DOT__clk__v0;
    CData/*0:0*/ __VdlySet__tb1__DOT__clk__v0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb1__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*11:0*/ tb1__DOT__x;
    SData/*11:0*/ tb1__DOT__y;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ tb1__DOT__char_buf;
    VlUnpacked<VlUnpacked<CData/*6:0*/, 32>, 40> tb1__DOT__text_buffer;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb1__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb1___024root(Vtb1__Syms* symsp, const char* v__name);
    ~Vtb1___024root();
    VL_UNCOPYABLE(Vtb1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
