// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb1.h for the primary calling header

#include "Vtb1__pch.h"
#include "Vtb1__Syms.h"
#include "Vtb1___024root.h"

VL_INLINE_OPT VlCoroutine Vtb1___024root___eval_initial__TOP__Vtiming__0(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x666f726dU;
    __Vtemp_1[2U] = 0x77617665U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.tb1__DOT__x = 0U;
    vlSelfRef.tb1__DOT__y = 0U;
    vlSelfRef.tb1__DOT__character_addr = 0x48U;
    co_await vlSelfRef.__VdlySched.delay(0x989680ULL, 
                                         nullptr, "../src/tb/tb1.sv", 
                                         105);
    VL_FINISH_MT("../src/tb/tb1.sv", 105, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb1___024root___dump_triggers__act(Vtb1___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb1___024root___eval_triggers__act(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.tb1__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb1__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb1__DOT__clk__0 
        = vlSelfRef.tb1__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb1___024root___dump_triggers__act(vlSelf);
    }
#endif
}
