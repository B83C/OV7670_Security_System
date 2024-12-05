// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb1.h for the primary calling header

#include "Vtb1__pch.h"
#include "Vtb1___024root.h"

VL_ATTR_COLD void Vtb1___024root___eval_static__TOP(Vtb1___024root* vlSelf);

VL_ATTR_COLD void Vtb1___024root___eval_static(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb1___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtb1___024root___eval_static__TOP(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_static__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb1__DOT__clk = 0U;
    vlSelfRef.tb1__DOT__scale_cntr_x = 0U;
    vlSelfRef.tb1__DOT__scale_cntr_y = 0U;
    vlSelfRef.tb1__DOT__x_cntr = 0U;
    vlSelfRef.tb1__DOT__y_cntr = 0U;
    vlSelfRef.tb1__DOT__c_x = 0U;
    vlSelfRef.tb1__DOT__c_y = 0U;
}

VL_ATTR_COLD void Vtb1___024root___eval_final(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb1___024root___eval_settle(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb1___024root___dump_triggers__act(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb1.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb1___024root___dump_triggers__nba(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb1.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb1___024root___ctor_var_reset(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb1__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb1__DOT__scale_cntr_x = VL_RAND_RESET_I(2);
    vlSelf->tb1__DOT__scale_cntr_y = VL_RAND_RESET_I(2);
    for (int __Vi0 = 0; __Vi0 < 40; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            vlSelf->tb1__DOT__text_buffer[__Vi0][__Vi1] = VL_RAND_RESET_I(7);
        }
    }
    vlSelf->tb1__DOT__x_cntr = VL_RAND_RESET_I(3);
    vlSelf->tb1__DOT__y_cntr = VL_RAND_RESET_I(3);
    vlSelf->tb1__DOT__c_x = VL_RAND_RESET_I(6);
    vlSelf->tb1__DOT__c_y = VL_RAND_RESET_I(5);
    vlSelf->tb1__DOT__character_addr = VL_RAND_RESET_I(7);
    vlSelf->tb1__DOT__char_buf = VL_RAND_RESET_Q(64);
    vlSelf->tb1__DOT__x = VL_RAND_RESET_I(12);
    vlSelf->tb1__DOT__y = VL_RAND_RESET_I(12);
    vlSelf->tb1__DOT__r = VL_RAND_RESET_I(4);
    vlSelf->tb1__DOT__g = VL_RAND_RESET_I(4);
    vlSelf->tb1__DOT__b = VL_RAND_RESET_I(4);
    vlSelf->__VdlyVal__tb1__DOT__clk__v0 = VL_RAND_RESET_I(1);
    vlSelf->__VdlySet__tb1__DOT__clk__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb1__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
