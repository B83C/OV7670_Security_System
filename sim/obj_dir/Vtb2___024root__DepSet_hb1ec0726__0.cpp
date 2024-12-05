// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb2.h for the primary calling header

#include "Vtb2__pch.h"
#include "Vtb2__Syms.h"
#include "Vtb2___024root.h"

VL_INLINE_OPT VlCoroutine Vtb2___024root___eval_initial__TOP__Vtiming__0(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x666f726dU;
    __Vtemp_1[2U] = 0x77617665U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         31);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__enc_rst_n = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         32);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__enc_rst_n = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x1b58ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         33);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xfffU;
    co_await vlSelfRef.__VdlySched.delay(0x2dc6c0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         41);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("../src/tb/tb2.sv", 41, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb2___024root___dump_triggers__act(Vtb2___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb2___024root___eval_triggers__act(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.tb2__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb2__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb2__DOT__clk__0 
        = vlSelfRef.tb2__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb2___024root___dump_triggers__act(vlSelf);
    }
#endif
}
