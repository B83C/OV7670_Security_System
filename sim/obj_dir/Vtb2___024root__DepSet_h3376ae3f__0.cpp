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
    if (vlSelfRef.tb2__DOT__enc_rst_n) {
        if (vlSelfRef.tb2__DOT__enc_en) {
            vlSelfRef.tb2__DOT__enc__DOT__stack_ind 
                = (0x3fU & (((IData)(3U) * (0xfU & 
                                            ((IData)(vlSelfRef.tb2__DOT__rgb) 
                                             >> 8U))) 
                            + (((IData)(5U) * (0xfU 
                                               & ((IData)(vlSelfRef.tb2__DOT__rgb) 
                                                  >> 4U))) 
                               + ((IData)(7U) * (0xfU 
                                                 & (IData)(vlSelfRef.tb2__DOT__rgb))))));
            vlSelfRef.tb2__DOT__enc__DOT__drgb = ((0xffU 
                                                   & (IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb)) 
                                                  | (0xf00U 
                                                     & (((IData)(2U) 
                                                         + 
                                                         (((IData)(vlSelfRef.tb2__DOT__enc__DOT__last_rgb) 
                                                           >> 8U) 
                                                          - 
                                                          ((IData)(vlSelfRef.tb2__DOT__rgb) 
                                                           >> 8U))) 
                                                        << 8U)));
            vlSelfRef.tb2__DOT__enc__DOT__drgb = ((0xf0fU 
                                                   & (IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb)) 
                                                  | (0xf0U 
                                                     & (((IData)(2U) 
                                                         + 
                                                         (((IData)(vlSelfRef.tb2__DOT__enc__DOT__last_rgb) 
                                                           >> 4U) 
                                                          - 
                                                          ((IData)(vlSelfRef.tb2__DOT__rgb) 
                                                           >> 4U))) 
                                                        << 4U)));
            vlSelfRef.tb2__DOT__enc__DOT__drgb = ((0xff0U 
                                                   & (IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb)) 
                                                  | (0xfU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        ((IData)(vlSelfRef.tb2__DOT__enc__DOT__last_rgb) 
                                                         - (IData)(vlSelfRef.tb2__DOT__rgb)))));
        }
    } else {
        vlSelfRef.tb2__DOT__enc__DOT__stack_ind = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__drgb = 0U;
    }
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
    SData/*9:0*/ __Vdly__tb2__DOT__enc__DOT__output_ind;
    __Vdly__tb2__DOT__enc__DOT__output_ind = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v0;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v0 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v0;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v0 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v0;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v1;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v1 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v1;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v1 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v1;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v2;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v2 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v2;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v2 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v2;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v2 = 0;
    SData/*11:0*/ __VdlyVal__tb2__DOT__enc__DOT__stack__v0;
    __VdlyVal__tb2__DOT__enc__DOT__stack__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stack__v0;
    __VdlyDim0__tb2__DOT__enc__DOT__stack__v0 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stack__v0;
    __VdlySet__tb2__DOT__enc__DOT__stack__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v3;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v3 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v3;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v3 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v3;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v3 = 0;
    SData/*11:0*/ __VdlyVal__tb2__DOT__enc__DOT__stack__v1;
    __VdlyVal__tb2__DOT__enc__DOT__stack__v1 = 0;
    CData/*5:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stack__v1;
    __VdlyDim0__tb2__DOT__enc__DOT__stack__v1 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stack__v1;
    __VdlySet__tb2__DOT__enc__DOT__stack__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v4;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v4 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v4;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v4 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v4;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v4 = 0;
    SData/*11:0*/ __VdlyVal__tb2__DOT__enc__DOT__stack__v2;
    __VdlyVal__tb2__DOT__enc__DOT__stack__v2 = 0;
    CData/*5:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stack__v2;
    __VdlyDim0__tb2__DOT__enc__DOT__stack__v2 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stack__v2;
    __VdlySet__tb2__DOT__enc__DOT__stack__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v5;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v5 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v5;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v5 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v5;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v5 = 0;
    SData/*11:0*/ __VdlyVal__tb2__DOT__enc__DOT__stack__v3;
    __VdlyVal__tb2__DOT__enc__DOT__stack__v3 = 0;
    CData/*5:0*/ __VdlyDim0__tb2__DOT__enc__DOT__stack__v3;
    __VdlyDim0__tb2__DOT__enc__DOT__stack__v3 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stack__v3;
    __VdlySet__tb2__DOT__enc__DOT__stack__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v6;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v6 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v6;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v6 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v6;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v6 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v7;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v7 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v7;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v7 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v7;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v7 = 0;
    CData/*7:0*/ __VdlyVal__tb2__DOT__enc__DOT__output_stream__v8;
    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v8 = 0;
    SData/*9:0*/ __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v8;
    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v8 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v8;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v8 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__output_stream__v9;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v9 = 0;
    CData/*0:0*/ __VdlySet__tb2__DOT__enc__DOT__stack__v4;
    __VdlySet__tb2__DOT__enc__DOT__stack__v4 = 0;
    // Body
    __Vdly__tb2__DOT__ph = vlSelfRef.tb2__DOT__ph;
    __Vdly__tb2__DOT__enc__DOT__output_ind = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
    __VdlySet__tb2__DOT__enc__DOT__stack__v0 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stack__v1 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stack__v2 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stack__v3 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__stack__v4 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v0 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v1 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v2 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v3 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v4 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v5 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v6 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v7 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v8 = 0U;
    __VdlySet__tb2__DOT__enc__DOT__output_stream__v9 = 0U;
    if (vlSelfRef.tb2__DOT__enc_rst_n) {
        if (vlSelfRef.tb2__DOT__enc_en) {
            __Vdly__tb2__DOT__enc__DOT__output_ind 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind)));
            if ((((IData)(vlSelfRef.tb2__DOT__enc__DOT__last_rgb) 
                  == (IData)(vlSelfRef.tb2__DOT__rgb)) 
                 & (0U != (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind)))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__0 = 0xc1U;
                if ((0x27fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v0 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__0;
                    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v0 
                        = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
                    __VdlySet__tb2__DOT__enc__DOT__output_stream__v0 = 1U;
                }
                if ((3U == (3U & (((0x27fU >= (0x3ffU 
                                               & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind) 
                                                  - (IData)(1U))))
                                    ? vlSelfRef.tb2__DOT__enc__DOT__output_stream
                                   [(0x3ffU & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind) 
                                               - (IData)(1U)))]
                                    : 0U) >> 6U)))) {
                    if ((0x3fU != ((0x27fU >= (0x3ffU 
                                               & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind) 
                                                  - (IData)(1U))))
                                    ? (0x3fU & vlSelfRef.tb2__DOT__enc__DOT__output_stream
                                       [(0x3ffU & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind) 
                                                   - (IData)(1U)))])
                                    : 0U))) {
                        vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h0f1374d5__0 
                            = (0xffU & ((IData)(1U) 
                                        + ((0x27fU 
                                            >= (0x3ffU 
                                                & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind) 
                                                   - (IData)(1U))))
                                            ? vlSelfRef.tb2__DOT__enc__DOT__output_stream
                                           [(0x3ffU 
                                             & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind) 
                                                - (IData)(1U)))]
                                            : 0U)));
                        if ((0x27fU >= (0x3ffU & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind) 
                                                  - (IData)(1U))))) {
                            __VdlyVal__tb2__DOT__enc__DOT__output_stream__v1 
                                = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h0f1374d5__0;
                            __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v1 
                                = (0x3ffU & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind) 
                                             - (IData)(1U)));
                            __VdlySet__tb2__DOT__enc__DOT__output_stream__v1 = 1U;
                        }
                        __Vdly__tb2__DOT__enc__DOT__output_ind 
                            = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
                    }
                }
            } else if (((vlSelfRef.tb2__DOT__enc__DOT__stack
                         [vlSelfRef.tb2__DOT__enc__DOT__stack_ind] 
                         == (IData)(vlSelfRef.tb2__DOT__rgb)) 
                        | (0U == vlSelfRef.tb2__DOT__enc__DOT__stack
                           [vlSelfRef.tb2__DOT__enc__DOT__stack_ind]))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__1 
                    = vlSelfRef.tb2__DOT__enc__DOT__stack_ind;
                if ((0x27fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v2 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__1;
                    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v2 
                        = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
                    __VdlySet__tb2__DOT__enc__DOT__output_stream__v2 = 1U;
                }
                __VdlyVal__tb2__DOT__enc__DOT__stack__v0 
                    = vlSelfRef.tb2__DOT__rgb;
                __VdlyDim0__tb2__DOT__enc__DOT__stack__v0 
                    = vlSelfRef.tb2__DOT__enc__DOT__stack_ind;
                __VdlySet__tb2__DOT__enc__DOT__stack__v0 = 1U;
            } else if (((vlSelfRef.tb2__DOT__enc__DOT__stack
                         [(0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)))] 
                         == (IData)(vlSelfRef.tb2__DOT__rgb)) 
                        | (0U == vlSelfRef.tb2__DOT__enc__DOT__stack
                           [(0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)))]))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__2 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)));
                if ((0x27fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v3 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__2;
                    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v3 
                        = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
                    __VdlySet__tb2__DOT__enc__DOT__output_stream__v3 = 1U;
                }
                __VdlyVal__tb2__DOT__enc__DOT__stack__v1 
                    = vlSelfRef.tb2__DOT__rgb;
                __VdlyDim0__tb2__DOT__enc__DOT__stack__v1 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)));
                __VdlySet__tb2__DOT__enc__DOT__stack__v1 = 1U;
            } else if (((vlSelfRef.tb2__DOT__enc__DOT__stack
                         [(0x3fU & ((IData)(2U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)))] 
                         == (IData)(vlSelfRef.tb2__DOT__rgb)) 
                        | (0U == vlSelfRef.tb2__DOT__enc__DOT__stack
                           [(0x3fU & ((IData)(2U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)))]))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__3 
                    = (0x3fU & ((IData)(2U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)));
                if ((0x27fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v4 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__3;
                    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v4 
                        = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
                    __VdlySet__tb2__DOT__enc__DOT__output_stream__v4 = 1U;
                }
                __VdlyVal__tb2__DOT__enc__DOT__stack__v2 
                    = vlSelfRef.tb2__DOT__rgb;
                __VdlyDim0__tb2__DOT__enc__DOT__stack__v2 
                    = (0x3fU & ((IData)(2U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)));
                __VdlySet__tb2__DOT__enc__DOT__stack__v2 = 1U;
            } else if (((vlSelfRef.tb2__DOT__enc__DOT__stack
                         [(0x3fU & ((IData)(3U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)))] 
                         == (IData)(vlSelfRef.tb2__DOT__rgb)) 
                        | (0U == vlSelfRef.tb2__DOT__enc__DOT__stack
                           [(0x3fU & ((IData)(3U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)))]))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__4 
                    = (0x3fU & ((IData)(3U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)));
                if ((0x27fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v5 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__4;
                    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v5 
                        = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
                    __VdlySet__tb2__DOT__enc__DOT__output_stream__v5 = 1U;
                }
                __VdlyVal__tb2__DOT__enc__DOT__stack__v3 
                    = vlSelfRef.tb2__DOT__rgb;
                __VdlyDim0__tb2__DOT__enc__DOT__stack__v3 
                    = (0x3fU & ((IData)(3U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__stack_ind)));
                __VdlySet__tb2__DOT__enc__DOT__stack__v3 = 1U;
            } else if ((IData)((0U == (0xcccU & (IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb))))) {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__5 
                    = (0x40U | ((0x30U & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb) 
                                          >> 4U)) | 
                                ((0xcU & ((IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb) 
                                          >> 2U)) | 
                                 (3U & (IData)(vlSelfRef.tb2__DOT__enc__DOT__drgb)))));
                if ((0x27fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v6 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__5;
                    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v6 
                        = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
                    __VdlySet__tb2__DOT__enc__DOT__output_stream__v6 = 1U;
                }
            } else {
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__6 
                    = (0x80U | (0xfU & ((IData)(vlSelfRef.tb2__DOT__rgb) 
                                        >> 8U)));
                if ((0x27fU >= (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind))) {
                    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v7 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_h4e87f70a__6;
                    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v7 
                        = vlSelfRef.tb2__DOT__enc__DOT__output_ind;
                    __VdlySet__tb2__DOT__enc__DOT__output_stream__v7 = 1U;
                }
                vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_hb4f34b9e__0 
                    = (0xffU & (IData)(vlSelfRef.tb2__DOT__rgb));
                if ((0x27fU >= (0x3ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind))))) {
                    __VdlyVal__tb2__DOT__enc__DOT__output_stream__v8 
                        = vlSelfRef.tb2__DOT__enc__DOT____Vlvbound_hb4f34b9e__0;
                    __VdlyDim0__tb2__DOT__enc__DOT__output_stream__v8 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind)));
                    __VdlySet__tb2__DOT__enc__DOT__output_stream__v8 = 1U;
                }
                __Vdly__tb2__DOT__enc__DOT__output_ind 
                    = (0x3ffU & ((IData)(2U) + (IData)(vlSelfRef.tb2__DOT__enc__DOT__output_ind)));
            }
            vlSelfRef.tb2__DOT__enc__DOT__last_rgb 
                = vlSelfRef.tb2__DOT__rgb;
        }
    } else {
        __VdlySet__tb2__DOT__enc__DOT__output_stream__v9 = 1U;
        __Vdly__tb2__DOT__enc__DOT__output_ind = 0U;
        __VdlySet__tb2__DOT__enc__DOT__stack__v4 = 1U;
        vlSelfRef.tb2__DOT__enc__DOT__last_rgb = 0U;
    }
    vlSelfRef.tb2__DOT__enc__DOT__output_ind = __Vdly__tb2__DOT__enc__DOT__output_ind;
    if (__VdlySet__tb2__DOT__enc__DOT__stack__v0) {
        vlSelfRef.tb2__DOT__enc__DOT__stack[__VdlyDim0__tb2__DOT__enc__DOT__stack__v0] 
            = __VdlyVal__tb2__DOT__enc__DOT__stack__v0;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stack__v1) {
        vlSelfRef.tb2__DOT__enc__DOT__stack[__VdlyDim0__tb2__DOT__enc__DOT__stack__v1] 
            = __VdlyVal__tb2__DOT__enc__DOT__stack__v1;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stack__v2) {
        vlSelfRef.tb2__DOT__enc__DOT__stack[__VdlyDim0__tb2__DOT__enc__DOT__stack__v2] 
            = __VdlyVal__tb2__DOT__enc__DOT__stack__v2;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stack__v3) {
        vlSelfRef.tb2__DOT__enc__DOT__stack[__VdlyDim0__tb2__DOT__enc__DOT__stack__v3] 
            = __VdlyVal__tb2__DOT__enc__DOT__stack__v3;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__stack__v4) {
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x3fU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x27dU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x3eU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x27cU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x3dU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x27bU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x3cU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x27aU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x3bU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x279U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x3aU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x278U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x39U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x277U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x38U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x276U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x37U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x275U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x36U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x274U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x35U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x273U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x34U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x272U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x33U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x271U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x32U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x270U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x31U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x26fU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x30U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x26eU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x2fU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x26dU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x2eU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x26cU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x2dU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x26bU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x2cU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x26aU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x2bU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x269U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x2aU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x268U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x29U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x267U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x28U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x266U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x27U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x265U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x26U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x264U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x25U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x263U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x24U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x262U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x23U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x261U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x22U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x260U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x21U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x25fU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x20U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x25eU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x1fU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x25dU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x1eU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x25cU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x1dU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x25bU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x1cU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x25aU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x1bU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x259U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x1aU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x258U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x19U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x257U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x18U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x256U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x17U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x255U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x16U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x254U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x15U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x253U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x14U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x252U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x13U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x251U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x12U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x250U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x11U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x24fU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0x10U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x24eU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0xfU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x24dU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0xeU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x24cU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0xdU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x24bU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0xcU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x24aU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0xbU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x249U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0xaU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x248U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[9U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x247U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[8U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x246U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[7U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x245U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[6U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x244U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[5U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x243U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[4U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x242U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[3U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x241U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[2U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x240U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[1U] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x23fU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__stack[0U] = 0U;
        IData/*31:0*/ __Vilp1;
        __Vilp1 = 0U;
        while ((__Vilp1 <= 0x23eU)) {
            vlSelfRef.tb2__DOT__enc__DOT__output_stream[__Vilp1] = 0U;
            __Vilp1 = ((IData)(1U) + __Vilp1);
        }
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v0) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v0] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v0;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v1) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v1] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v1;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v2) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v2] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v2;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v3) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v3] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v3;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v4) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v4] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v4;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v5) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v5] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v5;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v6) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v6] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v6;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v7) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v7] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v7;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v8) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[__VdlyDim0__tb2__DOT__enc__DOT__output_stream__v8] 
            = __VdlyVal__tb2__DOT__enc__DOT__output_stream__v8;
    }
    if (__VdlySet__tb2__DOT__enc__DOT__output_stream__v9) {
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x27fU] = 0U;
        vlSelfRef.tb2__DOT__enc__DOT__output_stream[0x27eU] = 0U;
    }
    __Vdly__tb2__DOT__ph = (1U & (~ (IData)(vlSelfRef.tb2__DOT__ph)));
    vlSelfRef.tb2__DOT__enc_en = vlSelfRef.tb2__DOT__ph;
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
