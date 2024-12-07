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
    __Vtemp_1[0U] = 0x2e667374U;
    __Vtemp_1[1U] = 0x666f726dU;
    __Vtemp_1[2U] = 0x77617665U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         32);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__enc_rst_n = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x7d0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         33);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__enc_rst_n = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x1b58ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         34);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xfffU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         35);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xff0U;
    co_await vlSelfRef.__VdlySched.delay(0x3e80ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         36);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf0fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         37);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xffU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         38);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf0fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         39);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xff0U;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         40);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf0fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         41);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf0eU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         42);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xe0fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         43);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf0dU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         44);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xd0fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         45);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf0fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         46);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf1fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf0fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         48);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xfefU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         49);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xf0eU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         50);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xd0fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xdafU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xdbfU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         53);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0x302U;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         54);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0x325U;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         55);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0x7ffU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         56);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0x56fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         57);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xd0dU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0x80fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         59);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0x90fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         60);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xd8fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xd7fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         62);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0x60fU;
    co_await vlSelfRef.__VdlySched.delay(0xfa0ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         63);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb2__DOT__rgb = 0xd07U;
    co_await vlSelfRef.__VdlySched.delay(0x231860ULL, 
                                         nullptr, "../src/tb/tb2.sv", 
                                         65);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("../src/tb/tb2.sv", 65, "");
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
