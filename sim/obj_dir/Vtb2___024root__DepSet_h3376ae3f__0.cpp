// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb2.h for the primary calling header

#include "Vtb2__pch.h"
#include "Vtb2___024root.h"

VlCoroutine Vtb2___024root___eval_initial__TOP__Vtiming__0(Vtb2___024root* vlSelf);
VlCoroutine Vtb2___024root___eval_initial__TOP__Vtiming__1(Vtb2___024root* vlSelf);

void Vtb2___024root___eval_initial(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb2___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb2___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb2__DOT__clk__0 
        = vlSelfRef.tb2__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vtb2___024root___eval_initial__TOP__Vtiming__1(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "../src/tb/tb2.sv", 
                                             7);
        vlSelfRef.tb2__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb2__DOT__clk)));
    }
}

void Vtb2___024root___act_sequent__TOP__0(Vtb2___024root* vlSelf);

void Vtb2___024root___eval_act(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb2___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb2___024root___act_sequent__TOP__0(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___act_sequent__TOP__0\n"); );
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
}

void Vtb2___024root___nba_sequent__TOP__0(Vtb2___024root* vlSelf);

void Vtb2___024root___eval_nba(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb2___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb2___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb2___024root___nba_sequent__TOP__0(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__tb2__DOT__ph;
    __Vdly__tb2__DOT__ph = 0;
    SData/*8:0*/ __Vdly__tb2__DOT__enc__DOT__stream_ind;
    __Vdly__tb2__DOT__enc__DOT__stream_ind = 0;
    CData/*5:0*/ __Vdly__tb2__DOT__enc__DOT__rcntr;
    __Vdly__tb2__DOT__enc__DOT__rcntr = 0;
    CData/*5:0*/ __Vdly__tb2__DOT__enc__DOT__stack_ind;
    __Vdly__tb2__DOT__enc__DOT__stack_ind = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__stream__v0;
    __VdlyVal__tb2__DOT__enc__DOT__stream__v0 = 0;
    SData/*8:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stream__v0;
    __VdlyDim0__tb2__DOT__enc__DOT__stream__v0 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v0;
    __VdlySet__tb2__DOT__enc__DOT__stream__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__stream__v1;
    __VdlyVal__tb2__DOT__enc__DOT__stream__v1 = 0;
    SData/*8:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stream__v1;
    __VdlyDim0__tb2__DOT__enc__DOT__stream__v1 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v1;
    __VdlySet__tb2__DOT__enc__DOT__stream__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__stream__v2;
    __VdlyVal__tb2__DOT__enc__DOT__stream__v2 = 0;
    SData/*8:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stream__v2;
    __VdlyDim0__tb2__DOT__enc__DOT__stream__v2 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v2;
    __VdlySet__tb2__DOT__enc__DOT__stream__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__stream__v3;
    __VdlyVal__tb2__DOT__enc__DOT__stream__v3 = 0;
    SData/*8:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stream__v3;
    __VdlyDim0__tb2__DOT__enc__DOT__stream__v3 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v3;
    __VdlySet__tb2__DOT__enc__DOT__stream__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__stream__v4;
    __VdlyVal__tb2__DOT__enc__DOT__stream__v4 = 0;
    SData/*8:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stream__v4;
    __VdlyDim0__tb2__DOT__enc__DOT__stream__v4 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v4;
    __VdlySet__tb2__DOT__enc__DOT__stream__v4 = 0;
    SData/*11:0*/ __VdlyVal__tb2__DOT__enc__DOT__stack__v0;
    __VdlyVal__tb2__DOT__enc__DOT__stack__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stack__v0;
    __VdlyDim0__tb2__DOT__enc__DOT__stack__v0 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stack__v0;
    __VdlySet__tb2__DOT__enc__DOT__stack__v0 = 0;
    CData/*5:0*/ __VdlyVal__tb2__DOT__enc__DOT__hashmap__v0;
    __VdlyVal__tb2__DOT__enc__DOT__hashmap__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb2__DOT__enc__DOT__hashmap__v0;
    __VdlyDim0__tb2__DOT__enc__DOT__hashmap__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__stream__v5;
    __VdlyVal__tb2__DOT__enc__DOT__stream__v5 = 0;
    SData/*8:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stream__v5;
    __VdlyDim0__tb2__DOT__enc__DOT__stream__v5 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v5;
    __VdlySet__tb2__DOT__enc__DOT__stream__v5 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__stream__v6;
    __VdlyVal__tb2__DOT__enc__DOT__stream__v6 = 0;
    SData/*8:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stream__v6;
    __VdlyDim0__tb2__DOT__enc__DOT__stream__v6 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v6;
    __VdlySet__tb2__DOT__enc__DOT__stream__v6 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v7;
    __VdlySet__tb2__DOT__enc__DOT__stream__v7 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stream__v8;
    __VdlySet__tb2__DOT__enc__DOT__stream__v8 = 0;
    // Body
    __Vdly__tb2__DOT__ph = vlSelfRef.tb2__DOT__ph;
    __Vdly__tb2__DOT__enc__DOT__stream_ind = vlSelfRef.tb2__DOT__enc__DOT__stream_ind;
    __Vdly__tb2__DOT__enc__DOT__rcntr = vlSelfRef.tb2__DOT__enc__DOT__rcntr;
    __Vdly__tb2__DOT__enc__DOT__stack_ind = vlSelfRef.tb2__DOT__enc__DOT__stack_ind;
    __VdlySet__tb2__DOT__enc__DOT__stack__v0 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v0 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v1 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v2 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v3 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v4 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v5 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v6 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v7 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stream__v8 = 0U;
    if (vlSelfRef.tb2__DOT__enc_rst_n) {
        if (((IData)(vlSelfRef.tb2__DOT__enc_en) & 
             (~ (IData)(vlSelfRef.tb2__DOT__capped)))) {
            if ((0x13fU == (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind))) {
                vlSelfRef.tb2__DOT__capped = 1U;
            } else {
                __Vdly__tb2__DOT__enc__DOT__stream_ind 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind)));
            }
            __Vdly__tb2__DOT__enc__DOT__rcntr = 1U;
            if (((IData)(vlSelfRef.tb2__DOT__enc__DOT__last_rgb) 
                 == (IData)(vlSelfRef.tb2__DOT__rgb))) {
                if ((1U < (IData)(vlSelfRef.tb2__DOT__enc__DOT__rcntr))) {
                    __Vdly__tb2__DOT__enc__DOT__stream_ind 
                        = vlSelfRef.tb2__DOT__enc__DOT__stream_ind;
                    vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha4c9959c__0 
                        = (0xc0U | (IData)(vlSelfRef.tb2__DOT__enc__DOT__rcntr));
                    if ((0x13fU >= ((0U == ((IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind) 
                                            - (IData)(1U)))
                                     ? 0U : (0x1ffU 
                                             & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind) 
                                                - (IData)(1U)))))) {
                        __VdlyVal__tb2__DOT__enc__DOT__stream__v0 
                            = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha4c9959c__0;
                        __VdlyDim0__tb2__DOT__enc__DOT__stream__v0 
                            = ((0U == ((IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind) 
                                       - (IData)(1U)))
                                ? 0U : (0x1ffU & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind) 
                                                  - (IData)(1U))));
                        __VdlySet__tb2__DOT__enc__DOT__stream__v0 = 1U;
                    }
                } else {
                    vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__0 
                        = (0xc0U | (IData)(vlSelfRef.tb2__DOT__enc__DOT__rcntr));
                    if ((0x13fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind))) {
                        __VdlyVal__tb2__DOT__enc__DOT__stream__v1 
                            = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__0;
                        __VdlyDim0__tb2__DOT__enc__DOT__stream__v1 
                            = vlSelfRef.tb2__DOT__enc__DOT__stream_ind;
                        __VdlySet__tb2__DOT__enc__DOT__stream__v1 = 1U;
                    }
                }
                if ((0x3fU != (IData)(vlSelfRef.tb2__DOT__enc__DOT__rcntr))) {
                    __Vdly__tb2__DOT__enc__DOT__rcntr 
                        = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__rcntr)));
                }
            } else if ((vlSelfRef.tb2__DOT__enc__DOT__stack
                        [vlSelfRef.tb2__DOT__enc__DOT__hashmap
                        [vlSelfRef.tb2__DOT__rgb]] 
                        == (IData)(vlSelfRef.tb2__DOT__rgb))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__1 
                    = vlSelfRef.tb2__DOT__enc__DOT__hashmap
                    [vlSelfRef.tb2__DOT__rgb];
                if ((0x13fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__stream__v2 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__1;
                    __VdlyDim0__tb2__DOT__enc__DOT__stream__v2 
                        = vlSelfRef.tb2__DOT__enc__DOT__stream_ind;
                    __VdlySet__tb2__DOT__enc__DOT__stream__v2 = 1U;
                }
            } else if ((0U == ((0x1c0U & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb) 
                                          >> 6U)) | 
                               ((0x38U & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb) 
                                          >> 4U)) | 
                                (7U & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb) 
                                       >> 2U)))))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__2 
                    = (0x40U | ((0x30U & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb) 
                                          >> 6U)) | 
                                ((0xcU & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb) 
                                          >> 3U)) | 
                                 (3U & (IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb)))));
                if ((0x13fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__stream__v3 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__2;
                    __VdlyDim0__tb2__DOT__enc__DOT__stream__v3 
                        = vlSelfRef.tb2__DOT__enc__DOT__stream_ind;
                    __VdlySet__tb2__DOT__enc__DOT__stream__v3 = 1U;
                }
            } else if (((vlSelfRef.tb2__DOT__enc__DOT__stack
                         [vlSelfRef.tb2__DOT__enc__DOT__hashmap
                         [vlSelfRef.tb2__DOT__rgb]] 
                         != (IData)(vlSelfRef.tb2__DOT__rgb)) 
                        & (0x3fU > (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__3 
                    = vlSelfRef.tb2__DOT__enc__DOT__stack_ind;
                if ((0x13fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__stream__v4 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__3;
                    __VdlyDim0__tb2__DOT__enc__DOT__stream__v4 
                        = vlSelfRef.tb2__DOT__enc__DOT__stream_ind;
                    __VdlySet__tb2__DOT__enc__DOT__stream__v4 = 1U;
                }
                __Vdly__tb2__DOT__enc__DOT__stack_ind 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)));
                __VdlyVal__tb2__DOT__enc__DOT__stack__v0 
                    = vlSelfRef.tb2__DOT__rgb;
                __VdlyDim0__tb2__DOT__enc__DOT__stack__v0 
                    = vlSelfRef.tb2__DOT__enc__DOT__stack_ind;
                __VdlySet__tb2__DOT__enc__DOT__stack__v0 = 1U;
                __VdlyVal__tb2__DOT__enc__DOT__hashmap__v0 
                    = vlSelfRef.tb2__DOT__enc__DOT__stack_ind;
                __VdlyDim0__tb2__DOT__enc__DOT__hashmap__v0 
                    = vlSelfRef.tb2__DOT__rgb;
            } else if ((0x13fU != (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__4 
                    = (0x80U | (0xfU & ((IData)(vlSelfRef.tb2__DOT__rgb) 
                                        >> 8U)));
                if ((0x13fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__stream__v5 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_ha5627427__4;
                    __VdlyDim0__tb2__DOT__enc__DOT__stream__v5 
                        = vlSelfRef.tb2__DOT__enc__DOT__stream_ind;
                    __VdlySet__tb2__DOT__enc__DOT__stream__v5 = 1U;
                }
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h1b847b5c__0 
                    = (0xffU & (IData)(vlSelfRef.tb2__DOT__rgb));
                if ((0x13fU >= (0x1ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind))))) {
                    __VdlyVal__tb2__DOT__enc__DOT__stream__v6 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h1b847b5c__0;
                    __VdlyDim0__tb2__DOT__enc__DOT__stream__v6 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind)));
                    __VdlySet__tb2__DOT__enc__DOT__stream__v6 = 1U;
                }
                __Vdly__tb2__DOT__enc__DOT__stream_ind 
                    = (0x1ffU & ((IData)(2U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stream_ind)));
            }
            vlSelfRef.tb2__DOT__enc__DOT__last_rgb 
                = vlSelfRef.tb2__DOT__rgb;
        }
    } else {
        __Vdly__tb2__DOT__enc__DOT__rcntr = 1U;
        __Vdly__tb2__DOT__enc__DOT__stream_ind = 0U;
        __VdlySet__tb2__DOT__enc__DOT__stream__v7 = 1U;
        vlSelfRef.tb2__DOT__enc__DOT__last_rgb = 0U;
        vlSelfRef.tb2__DOT__capped = 0U;
        __VdlySet__tb2__DOT__enc__DOT__stream__v8 = 1U;
    }
    vlSelfRef.tb2__DOT__enc__DOT__stream_ind = __Vdly__tb2__DOT__enc__DOT__stream_ind;
    vlSelfRef.tb2__DOT__enc__DOT__rcntr = __Vdly__tb2__DOT__enc__DOT__rcntr;
    vlSelfRef.tb2__DOT__enc__DOT__stack_ind = __Vdly__tb2__DOT__enc__DOT__stack_ind;
    if (__VdlySet__tb2__DOT__enc__DOT__stack__v0) {
        vlSelfRef.tb2__DOT__enc__DOT__stack[__VdlyDim0__tb2__DOT__enc__DOT__stack__v0] 
            = __VdlyVal__tb2__DOT__enc__DOT__stack__v0;
        vlSelfRef.tb2__DOT__enc__DOT__hashmap[__VdlyDim0__tb2__DOT__enc__DOT__hashmap__v0] 
            = __VdlyVal__tb2__DOT__enc__DOT__hashmap__v0;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v0) {
        vlSelfRef.tb2__DOT__enc__DOT__stream[__VdlyDim0__tb2__DOT__enc__DOT__stream__v0] 
            = __VdlyVal__tb2__DOT__enc__DOT__stream__v0;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v1) {
        vlSelfRef.tb2__DOT__enc__DOT__stream[__VdlyDim0__tb2__DOT__enc__DOT__stream__v1] 
            = __VdlyVal__tb2__DOT__enc__DOT__stream__v1;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v2) {
        vlSelfRef.tb2__DOT__enc__DOT__stream[__VdlyDim0__tb2__DOT__enc__DOT__stream__v2] 
            = __VdlyVal__tb2__DOT__enc__DOT__stream__v2;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v3) {
        vlSelfRef.tb2__DOT__enc__DOT__stream[__VdlyDim0__tb2__DOT__enc__DOT__stream__v3] 
            = __VdlyVal__tb2__DOT__enc__DOT__stream__v3;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v4) {
        vlSelfRef.tb2__DOT__enc__DOT__stream[__VdlyDim0__tb2__DOT__enc__DOT__stream__v4] 
            = __VdlyVal__tb2__DOT__enc__DOT__stream__v4;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v5) {
        vlSelfRef.tb2__DOT__enc__DOT__stream[__VdlyDim0__tb2__DOT__enc__DOT__stream__v5] 
            = __VdlyVal__tb2__DOT__enc__DOT__stream__v5;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v6) {
        vlSelfRef.tb2__DOT__enc__DOT__stream[__VdlyDim0__tb2__DOT__enc__DOT__stream__v6] 
            = __VdlyVal__tb2__DOT__enc__DOT__stream__v6;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v7) {
        vlSelfRef.tb2__DOT__enc__DOT__stream[0x13fU] = 0U;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stream__v8) {
        IData/*31:0*/ __Vilp1;
        __Vilp1 = 0U;
        while ((__Vilp1 <= 0x13eU)) {
            vlSelfRef.tb2__DOT__enc__DOT__stream[__Vilp1] = 0U;
            __Vilp1 = ((IData)(1U) + __Vilp1);
        }
    }
    __Vdly__tb2__DOT__ph = (1U & (~ (IData)(vlSelfRef.tb2__DOT__ph)));
    vlSelfRef.tb2__DOT__enc_en = vlSelfRef.tb2__DOT__ph;
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        vlSelfRef.tb2__DOT__rgbstack[__Vilp2] = vlSelfRef.tb2__DOT__enc__DOT__stack
            [__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x13fU)) {
        vlSelfRef.tb2__DOT__output_stream[__Vilp3] 
            = vlSelfRef.tb2__DOT__enc__DOT__stream[__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    vlSelfRef.tb2__DOT__ph = __Vdly__tb2__DOT__ph;
}

void Vtb2___024root___timing_resume(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb2___024root___eval_triggers__act(Vtb2___024root* vlSelf);

bool Vtb2___024root___eval_phase__act(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb2___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb2___024root___timing_resume(vlSelf);
        Vtb2___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb2___024root___eval_phase__nba(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb2___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb2___024root___dump_triggers__nba(Vtb2___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb2___024root___dump_triggers__act(Vtb2___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb2___024root___eval(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval\n"); );
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
            Vtb2___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../src/tb/tb2.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb2___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../src/tb/tb2.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb2___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb2___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb2___024root___eval_debug_assertions(Vtb2___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb2___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
