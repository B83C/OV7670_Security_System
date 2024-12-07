// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb2.h for the primary calling header

#ifndef VERILATED_VTB2___024ROOT_H_
#define VERILATED_VTB2___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb2___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb2__DOT__clk;
    CData/*0:0*/ tb2__DOT__ph;
    CData/*0:0*/ tb2__DOT__enc_en;
    CData/*0:0*/ tb2__DOT__enc_rst_n;
    CData/*0:0*/ tb2__DOT__capped;
    CData/*5:0*/ tb2__DOT__enc__DOT__stack_ind;
    CData/*5:0*/ tb2__DOT__enc__DOT__rcntr;
    CData/*7:0*/ tb2__DOT__enc__DOT____Vlvbound_ha4c9959c__0;
    CData/*7:0*/ tb2__DOT__enc__DOT____Vlvbound_ha5627427__0;
    CData/*7:0*/ tb2__DOT__enc__DOT____Vlvbound_ha5627427__1;
    CData/*7:0*/ tb2__DOT__enc__DOT____Vlvbound_ha5627427__2;
    CData/*7:0*/ tb2__DOT__enc__DOT____Vlvbound_ha5627427__3;
    CData/*7:0*/ tb2__DOT__enc__DOT____Vlvbound_ha5627427__4;
    CData/*7:0*/ tb2__DOT__enc__DOT____Vlvbound_h1b847b5c__0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb2__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*11:0*/ tb2__DOT__rgb;
    SData/*8:0*/ tb2__DOT__enc__DOT__stream_ind;
    SData/*11:0*/ tb2__DOT__enc__DOT__last_rgb;
    SData/*14:0*/ tb2__DOT__enc__DOT__drgb;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 320> tb2__DOT__output_stream;
    VlUnpacked<SData/*11:0*/, 64> tb2__DOT__rgbstack;
    VlUnpacked<CData/*7:0*/, 320> tb2__DOT__enc__DOT__stream;
    VlUnpacked<CData/*5:0*/, 4096> tb2__DOT__enc__DOT__hashmap;
    VlUnpacked<SData/*11:0*/, 64> tb2__DOT__enc__DOT__stack;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb2___024root(Vtb2__Syms* symsp, const char* v__name);
    ~Vtb2___024root();
    VL_UNCOPYABLE(Vtb2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
