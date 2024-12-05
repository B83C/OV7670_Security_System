// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb1.h for the primary calling header

#include "Vtb1__pch.h"
#include "Vtb1___024root.h"

VlCoroutine Vtb1___024root___eval_initial__TOP__Vtiming__0(Vtb1___024root* vlSelf);
VlCoroutine Vtb1___024root___eval_initial__TOP__Vtiming__1(Vtb1___024root* vlSelf);

void Vtb1___024root___eval_initial(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb1___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb1___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb1__DOT__clk__0 
        = vlSelfRef.tb1__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vtb1___024root___eval_initial__TOP__Vtiming__1(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "../src/tb/tb1.sv", 
                                             6);
        vlSelfRef.__VdlyVal__tb1__DOT__clk__v0 = (1U 
                                                  & (~ (IData)(vlSelfRef.tb1__DOT__clk)));
        vlSelfRef.__VdlySet__tb1__DOT__clk__v0 = 1U;
    }
}

void Vtb1___024root___eval_act(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb1___024root___nba_sequent__TOP__0(Vtb1___024root* vlSelf);
void Vtb1___024root___nba_sequent__TOP__1(Vtb1___024root* vlSelf);

void Vtb1___024root___eval_nba(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb1___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb1___024root___nba_sequent__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vtb1___024root___nba_sequent__TOP__0(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__tb1__DOT__scale_cntr_x;
    __Vdly__tb1__DOT__scale_cntr_x = 0;
    CData/*2:0*/ __Vdly__tb1__DOT__x_cntr;
    __Vdly__tb1__DOT__x_cntr = 0;
    CData/*5:0*/ __Vdly__tb1__DOT__c_x;
    __Vdly__tb1__DOT__c_x = 0;
    CData/*1:0*/ __Vdly__tb1__DOT__scale_cntr_y;
    __Vdly__tb1__DOT__scale_cntr_y = 0;
    CData/*2:0*/ __Vdly__tb1__DOT__y_cntr;
    __Vdly__tb1__DOT__y_cntr = 0;
    CData/*4:0*/ __Vdly__tb1__DOT__c_y;
    __Vdly__tb1__DOT__c_y = 0;
    SData/*11:0*/ __Vdly__tb1__DOT__x;
    __Vdly__tb1__DOT__x = 0;
    SData/*11:0*/ __Vdly__tb1__DOT__y;
    __Vdly__tb1__DOT__y = 0;
    // Body
    __Vdly__tb1__DOT__y = vlSelfRef.tb1__DOT__y;
    __Vdly__tb1__DOT__x = vlSelfRef.tb1__DOT__x;
    __Vdly__tb1__DOT__c_y = vlSelfRef.tb1__DOT__c_y;
    __Vdly__tb1__DOT__y_cntr = vlSelfRef.tb1__DOT__y_cntr;
    __Vdly__tb1__DOT__scale_cntr_y = vlSelfRef.tb1__DOT__scale_cntr_y;
    __Vdly__tb1__DOT__c_x = vlSelfRef.tb1__DOT__c_x;
    __Vdly__tb1__DOT__x_cntr = vlSelfRef.tb1__DOT__x_cntr;
    __Vdly__tb1__DOT__scale_cntr_x = vlSelfRef.tb1__DOT__scale_cntr_x;
    __Vdly__tb1__DOT__x = (0xfffU & ((IData)(1U) + (IData)(vlSelfRef.tb1__DOT__x)));
    if ((0x697U == (IData)(vlSelfRef.tb1__DOT__x))) {
        __Vdly__tb1__DOT__y = (0xfffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tb1__DOT__y)));
        __Vdly__tb1__DOT__x = 0U;
        if ((0x429U == (IData)(vlSelfRef.tb1__DOT__y))) {
            __Vdly__tb1__DOT__y = 0U;
        }
    }
    if (((0x500U > (IData)(vlSelfRef.tb1__DOT__x)) 
         & (0x400U > (IData)(vlSelfRef.tb1__DOT__y)))) {
        __Vdly__tb1__DOT__scale_cntr_x = (3U & ((IData)(1U) 
                                                + (IData)(vlSelfRef.tb1__DOT__scale_cntr_x)));
        if ((3U == (IData)(vlSelfRef.tb1__DOT__scale_cntr_x))) {
            __Vdly__tb1__DOT__x_cntr = (7U & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb1__DOT__x_cntr)));
            __Vdly__tb1__DOT__scale_cntr_x = 0U;
            if ((7U == (IData)(vlSelfRef.tb1__DOT__x_cntr))) {
                __Vdly__tb1__DOT__c_x = (0x3fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb1__DOT__c_x)));
                __Vdly__tb1__DOT__x_cntr = 0U;
                if ((0x27U == (IData)(vlSelfRef.tb1__DOT__c_x))) {
                    __Vdly__tb1__DOT__scale_cntr_y 
                        = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb1__DOT__scale_cntr_y)));
                    __Vdly__tb1__DOT__c_x = 0U;
                    if ((3U == (IData)(vlSelfRef.tb1__DOT__scale_cntr_y))) {
                        __Vdly__tb1__DOT__y_cntr = 
                            (7U & ((IData)(1U) + (IData)(vlSelfRef.tb1__DOT__y_cntr)));
                        __Vdly__tb1__DOT__scale_cntr_y = 0U;
                        if ((7U == (IData)(vlSelfRef.tb1__DOT__y_cntr))) {
                            __Vdly__tb1__DOT__c_y = 
                                (0x1fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb1__DOT__c_y)));
                            __Vdly__tb1__DOT__y_cntr = 0U;
                            if ((0x1fU == (IData)(vlSelfRef.tb1__DOT__c_y))) {
                                __Vdly__tb1__DOT__c_y = 0U;
                                vlSelfRef.tb1__DOT__character_addr 
                                    = vlSelfRef.tb1__DOT__text_buffer
                                    [0U][0U];
                            } else {
                                vlSelfRef.tb1__DOT__character_addr 
                                    = vlSelfRef.tb1__DOT__text_buffer
                                    [0U][(0x1fU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.tb1__DOT__c_y)))];
                            }
                        }
                    } else {
                        vlSelfRef.tb1__DOT__character_addr 
                            = vlSelfRef.tb1__DOT__text_buffer
                            [0U][vlSelfRef.tb1__DOT__c_y];
                    }
                } else {
                    vlSelfRef.tb1__DOT__character_addr 
                        = vlSelfRef.tb1__DOT__text_buffer
                        [((0x27U >= (0x3fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb1__DOT__c_x))))
                           ? (0x3fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.tb1__DOT__c_x)))
                           : 0U)][vlSelfRef.tb1__DOT__c_y];
                }
            }
        }
        if ((0U == (IData)(vlSelfRef.tb1__DOT__x_cntr))) {
            vlSelfRef.tb1__DOT__r = 0xdU;
            vlSelfRef.tb1__DOT__g = 0xdU;
            vlSelfRef.tb1__DOT__b = 0xdU;
        }
        if ((0U == (IData)(vlSelfRef.tb1__DOT__y_cntr))) {
            vlSelfRef.tb1__DOT__r = 2U;
            vlSelfRef.tb1__DOT__g = 2U;
            vlSelfRef.tb1__DOT__b = 2U;
        }
    }
    vlSelfRef.tb1__DOT__x = __Vdly__tb1__DOT__x;
    vlSelfRef.tb1__DOT__y = __Vdly__tb1__DOT__y;
    vlSelfRef.tb1__DOT__scale_cntr_x = __Vdly__tb1__DOT__scale_cntr_x;
    vlSelfRef.tb1__DOT__x_cntr = __Vdly__tb1__DOT__x_cntr;
    vlSelfRef.tb1__DOT__c_x = __Vdly__tb1__DOT__c_x;
    vlSelfRef.tb1__DOT__scale_cntr_y = __Vdly__tb1__DOT__scale_cntr_y;
    vlSelfRef.tb1__DOT__y_cntr = __Vdly__tb1__DOT__y_cntr;
    vlSelfRef.tb1__DOT__c_y = __Vdly__tb1__DOT__c_y;
}

VL_INLINE_OPT void Vtb1___024root___nba_sequent__TOP__1(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb1__DOT__clk__v0) {
        vlSelfRef.__VdlySet__tb1__DOT__clk__v0 = 0U;
        vlSelfRef.tb1__DOT__clk = vlSelfRef.__VdlyVal__tb1__DOT__clk__v0;
    }
}

void Vtb1___024root___timing_resume(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb1___024root___eval_triggers__act(Vtb1___024root* vlSelf);

bool Vtb1___024root___eval_phase__act(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb1___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb1___024root___timing_resume(vlSelf);
        Vtb1___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb1___024root___eval_phase__nba(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb1___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb1___024root___dump_triggers__nba(Vtb1___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb1___024root___dump_triggers__act(Vtb1___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb1___024root___eval(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb1___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../src/tb/tb1.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb1___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../src/tb/tb1.sv", 2, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb1___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb1___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb1___024root___eval_debug_assertions(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
