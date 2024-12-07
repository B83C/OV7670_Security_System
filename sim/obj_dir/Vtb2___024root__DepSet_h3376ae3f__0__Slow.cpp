// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb2.h for the primary calling header

#include "Vtb2__pch.h"
#include "Vtb2___024root.h"

VL_ATTR_COLD void Vtb2___024root___eval_static__TOP(Vtb2___024root* vlSelf);
VL_ATTR_COLD void Vtb2___024root____Vm_traceActivitySetAll(Vtb2___024root* vlSelf);

VL_ATTR_COLD void Vtb2___024root___eval_static(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb2___024root___eval_static__TOP(vlSelf);
    Vtb2___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vtb2___024root___eval_static__TOP(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_static__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb2__DOT__clk = 0U;
    vlSelfRef.tb2__DOT__ph = 0U;
    vlSelfRef.tb2__DOT__enc_en = 1U;
    vlSelfRef.tb2__DOT__enc_rst_n = 1U;
}

VL_ATTR_COLD void Vtb2___024root___eval_final(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb2___024root___dump_triggers__stl(Vtb2___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb2___024root___eval_phase__stl(Vtb2___024root* vlSelf);

VL_ATTR_COLD void Vtb2___024root___eval_settle(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb2___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../src/tb/tb2.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb2___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb2___024root___dump_triggers__stl(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb2___024root___stl_sequent__TOP__0(Vtb2___024root* vlSelf);

VL_ATTR_COLD void Vtb2___024root___eval_stl(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb2___024root___stl_sequent__TOP__0(vlSelf);
        Vtb2___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vtb2___024root___stl_sequent__TOP__0(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb2__DOT__enc__DOT__drgb = ((0x7c00U 
                                           & (((IData)(2U) 
                                               + ((0xfU 
                                                   & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__last_rgb) 
                                                      >> 8U)) 
                                                  - 
                                                  (0xfU 
                                                   & ((IData)(vlSelfRef.tb2__DOT__rgb) 
                                                      >> 8U)))) 
                                              << 0xaU)) 
                                          | ((0x3e0U 
                                              & (((IData)(2U) 
                                                  + 
                                                  ((0xfU 
                                                    & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__last_rgb) 
                                                       >> 4U)) 
                                                   - 
                                                   (0xfU 
                                                    & ((IData)(vlSelfRef.tb2__DOT__rgb) 
                                                       >> 4U)))) 
                                                 << 5U)) 
                                             | (0x1fU 
                                                & ((IData)(2U) 
                                                   + 
                                                   ((0xfU 
                                                     & (IData)(vlSelfRef.tb2__DOT__enc__DOT__last_rgb)) 
                                                    - 
                                                    (0xfU 
                                                     & (IData)(vlSelfRef.tb2__DOT__rgb)))))));
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb2__DOT__rgbstack[__Vilp1] = vlSelfRef.tb2__DOT__enc__DOT__stack
            [__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x13fU)) {
        vlSelfRef.tb2__DOT__output_stream[__Vilp2] 
            = vlSelfRef.tb2__DOT__enc__DOT__stream[__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
}

VL_ATTR_COLD void Vtb2___024root___eval_triggers__stl(Vtb2___024root* vlSelf);

VL_ATTR_COLD bool Vtb2___024root___eval_phase__stl(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb2___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb2___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb2___024root___dump_triggers__act(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb2.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb2___024root___dump_triggers__nba(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb2.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb2___024root____Vm_traceActivitySetAll(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root____Vm_traceActivitySetAll\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void Vtb2___024root___ctor_var_reset(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb2__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb2__DOT__ph = VL_RAND_RESET_I(1);
    vlSelf->tb2__DOT__rgb = VL_RAND_RESET_I(12);
    vlSelf->tb2__DOT__enc_en = VL_RAND_RESET_I(1);
    vlSelf->tb2__DOT__enc_rst_n = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 320; ++__Vi0) {
        vlSelf->tb2__DOT__output_stream[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb2__DOT__rgbstack[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->tb2__DOT__capped = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 320; ++__Vi0) {
        vlSelf->tb2__DOT__enc__DOT__stream[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb2__DOT__enc__DOT__stream_ind = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb2__DOT__enc__DOT__hashmap[__Vi0] = VL_RAND_RESET_I(6);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb2__DOT__enc__DOT__stack[__Vi0] = VL_RAND_RESET_I(12);
    }
    vlSelf->tb2__DOT__enc__DOT__stack_ind = VL_RAND_RESET_I(6);
    vlSelf->tb2__DOT__enc__DOT__last_rgb = VL_RAND_RESET_I(12);
    vlSelf->tb2__DOT__enc__DOT__drgb = VL_RAND_RESET_I(15);
    vlSelf->tb2__DOT__enc__DOT__rcntr = VL_RAND_RESET_I(6);
    vlSelf->tb2__DOT__enc__DOT____Vlvbound_ha4c9959c__0 = VL_RAND_RESET_I(8);
    vlSelf->tb2__DOT__enc__DOT____Vlvbound_ha5627427__0 = VL_RAND_RESET_I(8);
    vlSelf->tb2__DOT__enc__DOT____Vlvbound_ha5627427__1 = VL_RAND_RESET_I(8);
    vlSelf->tb2__DOT__enc__DOT____Vlvbound_ha5627427__2 = VL_RAND_RESET_I(8);
    vlSelf->tb2__DOT__enc__DOT____Vlvbound_ha5627427__3 = VL_RAND_RESET_I(8);
    vlSelf->tb2__DOT__enc__DOT____Vlvbound_ha5627427__4 = VL_RAND_RESET_I(8);
    vlSelf->tb2__DOT__enc__DOT____Vlvbound_h1b847b5c__0 = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__tb2__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
