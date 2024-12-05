// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
#include "Vtb___024root.h"


class Vtb__Syms;
struct Vtb_tb__DOT__cam__DOT__i2c_subsystem__struct__0 {
    CData/*0:0*/ __PVT__rst_n;
    CData/*0:0*/ __PVT__start;
    CData/*0:0*/ __PVT__halt;
    CData/*0:0*/ __PVT__rw;
    CData/*2:0*/ __PVT__ind;
    CData/*7:0*/ __PVT__mosi;

    bool operator==(const Vtb_tb__DOT__cam__DOT__i2c_subsystem__struct__0& rhs) const {
        return __PVT__rst_n == rhs.__PVT__rst_n
            && __PVT__start == rhs.__PVT__start
            && __PVT__halt == rhs.__PVT__halt
            && __PVT__rw == rhs.__PVT__rw
            && __PVT__ind == rhs.__PVT__ind
            && __PVT__mosi == rhs.__PVT__mosi;
    }
    bool operator!=(const Vtb_tb__DOT__cam__DOT__i2c_subsystem__struct__0& rhs) const {
        return !(*this == rhs);
    }
};
struct Vtb_tb__DOT__cam__DOT__i2c_master__DOT__system_state__struct__0 {
    CData/*2:0*/ __PVT__state;
    CData/*0:0*/ __PVT__scl;
    CData/*0:0*/ __PVT__sda;
    CData/*3:0*/ __PVT__ind;

    bool operator==(const Vtb_tb__DOT__cam__DOT__i2c_master__DOT__system_state__struct__0& rhs) const {
        return __PVT__state == rhs.__PVT__state
            && __PVT__scl == rhs.__PVT__scl
            && __PVT__sda == rhs.__PVT__sda
            && __PVT__ind == rhs.__PVT__ind;
    }
    bool operator!=(const Vtb_tb__DOT__cam__DOT__i2c_master__DOT__system_state__struct__0& rhs) const {
        return !(*this == rhs);
    }
};

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb__DOT__clk;
    CData/*0:0*/ tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n;
    CData/*7:0*/ tb__DOT__JB;
    CData/*7:0*/ tb__DOT__JC;
    CData/*0:0*/ tb__DOT__start;
    CData/*0:0*/ tb__DOT____Vcellout__cam__rst;
    CData/*0:0*/ tb__DOT____Vcellout__cam__pwdn;
    CData/*0:0*/ tb__DOT____Vcellout__cam__xclk;
    CData/*7:0*/ tb__DOT__JC__strong__out2;
    CData/*7:0*/ tb__DOT__JC__strong__out3;
    CData/*7:0*/ tb__DOT__JC__strong__out4;
    CData/*7:0*/ tb__DOT__JC__strong__out5;
    CData/*7:0*/ tb__DOT__JC__strong__out6;
    CData/*1:0*/ tb__DOT__cam__DOT__sys_state;
    CData/*0:0*/ tb__DOT__cam__DOT__start_timer;
    CData/*0:0*/ tb__DOT__cam__DOT__timer_done;
    CData/*2:0*/ tb__DOT__cam__DOT__state;
    CData/*1:0*/ tb__DOT__cam__DOT__dstate;
    CData/*7:0*/ tb__DOT__cam__DOT__miso;
    CData/*0:0*/ tb__DOT__cam__DOT__rw_done;
    CData/*1:0*/ tb__DOT__cam__DOT__ack;
    CData/*0:0*/ tb__DOT__cam__DOT__rw_reg;
    CData/*0:0*/ tb__DOT__cam__DOT__i2c_op;
    CData/*6:0*/ tb__DOT__cam__DOT__command_ind;
    CData/*1:0*/ tb__DOT__cam__DOT__delay__DOT__counts_internal;
    CData/*0:0*/ tb__DOT__cam__DOT__i2c_master__DOT__scl_hm;
    CData/*0:0*/ tb__DOT__cam__DOT__i2c_master__DOT__scl_lm;
    CData/*4:0*/ tb__DOT__cam__DOT__i2c_master__DOT__counter;
    CData/*4:0*/ __Vdly__tb__DOT__cam__DOT__i2c_master__DOT__counter;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb__DOT__cam__DOT__command_buffer;
    IData/*20:0*/ tb__DOT__cam__DOT__delay__DOT__counter;
    IData/*31:0*/ tb__DOT__cam__DOT__delay__DOT__state;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 77> tb__DOT__cam__DOT__buffer_rom__DOT__irom;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    Vtb_tb__DOT__cam__DOT__i2c_subsystem__struct__0 tb__DOT__cam__DOT__im;
    Vtb_tb__DOT__cam__DOT__i2c_master__DOT__system_state__struct__0 tb__DOT__cam__DOT__i2c_master__DOT__ss;
    Vtb_tb__DOT__cam__DOT__i2c_master__DOT__system_state__struct__0 tb__DOT__cam__DOT__i2c_master__DOT__nss;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* v__name);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtb_tb__DOT__cam__DOT__i2c_master__DOT__system_state__struct__0& obj);
std::string VL_TO_STRING(const Vtb_tb__DOT__cam__DOT__i2c_subsystem__struct__0& obj);

#endif  // guard
