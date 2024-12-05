// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_initial__TOP(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelfRef.tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n__0 
        = vlSelfRef.tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n;
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                             nullptr, 
                                             "../src/tb/tb.sv", 
                                             8);
        vlSelfRef.tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb__DOT__clk)));
    }
}

void Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf);
void Vtb___024root___nba_sequent__TOP__1(Vtb___024root* vlSelf);
void Vtb___024root___nba_sequent__TOP__2(Vtb___024root* vlSelf);
void Vtb___024root___nba_sequent__TOP__3(Vtb___024root* vlSelf);
void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf);

void Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__tb__DOT__cam__DOT__i2c_master__DOT__counter 
        = vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__counter;
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__1(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__tb__DOT__cam__DOT__sys_state;
    __Vdly__tb__DOT__cam__DOT__sys_state = 0;
    CData/*6:0*/ __Vdly__tb__DOT__cam__DOT__command_ind;
    __Vdly__tb__DOT__cam__DOT__command_ind = 0;
    CData/*0:0*/ __Vdly__tb__DOT__cam__DOT__timer_done;
    __Vdly__tb__DOT__cam__DOT__timer_done = 0;
    IData/*31:0*/ __Vdly__tb__DOT__cam__DOT__delay__DOT__state;
    __Vdly__tb__DOT__cam__DOT__delay__DOT__state = 0;
    IData/*20:0*/ __Vdly__tb__DOT__cam__DOT__delay__DOT__counter;
    __Vdly__tb__DOT__cam__DOT__delay__DOT__counter = 0;
    CData/*1:0*/ __Vdly__tb__DOT__cam__DOT__delay__DOT__counts_internal;
    __Vdly__tb__DOT__cam__DOT__delay__DOT__counts_internal = 0;
    // Body
    __Vdly__tb__DOT__cam__DOT__command_ind = vlSelfRef.tb__DOT__cam__DOT__command_ind;
    __Vdly__tb__DOT__cam__DOT__sys_state = vlSelfRef.tb__DOT__cam__DOT__sys_state;
    __Vdly__tb__DOT__cam__DOT__delay__DOT__counts_internal 
        = vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counts_internal;
    __Vdly__tb__DOT__cam__DOT__delay__DOT__counter 
        = vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counter;
    __Vdly__tb__DOT__cam__DOT__delay__DOT__state = vlSelfRef.tb__DOT__cam__DOT__delay__DOT__state;
    __Vdly__tb__DOT__cam__DOT__timer_done = vlSelfRef.tb__DOT__cam__DOT__timer_done;
    __Vdly__tb__DOT__cam__DOT__timer_done = 0U;
    if ((0U == vlSelfRef.tb__DOT__cam__DOT__delay__DOT__state)) {
        if (vlSelfRef.tb__DOT__cam__DOT__start_timer) {
            __Vdly__tb__DOT__cam__DOT__delay__DOT__state = 1U;
        }
    } else if ((1U == vlSelfRef.tb__DOT__cam__DOT__delay__DOT__state)) {
        __Vdly__tb__DOT__cam__DOT__delay__DOT__counter 
            = (0x1fffffU & (vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counter 
                            - (IData)(1U)));
        if ((0U == vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counter)) {
            __Vdly__tb__DOT__cam__DOT__delay__DOT__counts_internal 
                = (3U & ((IData)(vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counts_internal) 
                         - (IData)(1U)));
            __Vdly__tb__DOT__cam__DOT__delay__DOT__counter = 0xf4240U;
            if ((0U == (IData)(vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counts_internal))) {
                __Vdly__tb__DOT__cam__DOT__delay__DOT__counts_internal = 1U;
                __Vdly__tb__DOT__cam__DOT__timer_done = 1U;
                __Vdly__tb__DOT__cam__DOT__delay__DOT__state = 0U;
            }
        }
    }
    vlSelfRef.tb__DOT__cam__DOT__delay__DOT__state 
        = __Vdly__tb__DOT__cam__DOT__delay__DOT__state;
    vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counter 
        = __Vdly__tb__DOT__cam__DOT__delay__DOT__counter;
    vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counts_internal 
        = __Vdly__tb__DOT__cam__DOT__delay__DOT__counts_internal;
    vlSelfRef.tb__DOT__cam__DOT__im.__PVT__start = 0U;
    vlSelfRef.tb__DOT__cam__DOT__start_timer = 0U;
    if ((2U & (IData)(vlSelfRef.tb__DOT__cam__DOT__sys_state))) {
        if ((1U & (~ (IData)(vlSelfRef.tb__DOT__cam__DOT__sys_state)))) {
            if ((2U & (IData)(vlSelfRef.tb__DOT__cam__DOT__dstate))) {
                if ((1U & (IData)(vlSelfRef.tb__DOT__cam__DOT__dstate))) {
                    __Vdly__tb__DOT__cam__DOT__sys_state = 1U;
                } else if (vlSelfRef.tb__DOT__cam__DOT__rw_done) {
                    vlSelfRef.tb__DOT__cam__DOT__im.__PVT__rw = 0U;
                    __Vdly__tb__DOT__cam__DOT__sys_state = 1U;
                    vlSelfRef.tb__DOT__cam__DOT__im.__PVT__halt = 1U;
                    if ((0x4cU == (IData)(vlSelfRef.tb__DOT__cam__DOT__command_ind))) {
                        __Vdly__tb__DOT__cam__DOT__sys_state = 3U;
                    } else {
                        __Vdly__tb__DOT__cam__DOT__command_ind 
                            = (0x7fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.tb__DOT__cam__DOT__command_ind)));
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.tb__DOT__cam__DOT__dstate))) {
                if (vlSelfRef.tb__DOT__cam__DOT__rw_done) {
                    vlSelfRef.tb__DOT__cam__DOT__im.__PVT__halt = 0U;
                    vlSelfRef.tb__DOT__cam__DOT__dstate = 2U;
                    vlSelfRef.tb__DOT__cam__DOT__im.__PVT__rw = 0U;
                    vlSelfRef.tb__DOT__cam__DOT__im.__PVT__mosi 
                        = (0xffU & (IData)(vlSelfRef.tb__DOT__cam__DOT__command_buffer));
                }
            } else if (vlSelfRef.tb__DOT__cam__DOT__rw_done) {
                vlSelfRef.tb__DOT__cam__DOT__im.__PVT__rw = 0U;
                vlSelfRef.tb__DOT__cam__DOT__dstate = 1U;
                vlSelfRef.tb__DOT__cam__DOT__im.__PVT__mosi 
                    = (0xffU & ((IData)(vlSelfRef.tb__DOT__cam__DOT__command_buffer) 
                                >> 8U));
                vlSelfRef.tb__DOT__cam__DOT__im.__PVT__halt = 0U;
            }
        }
    } else if ((1U & (IData)(vlSelfRef.tb__DOT__cam__DOT__sys_state))) {
        if ((0xfff0U == (IData)(vlSelfRef.tb__DOT__cam__DOT__command_buffer))) {
            vlSelfRef.tb__DOT__cam__DOT__start_timer = 1U;
            if (vlSelfRef.tb__DOT__cam__DOT__timer_done) {
                __Vdly__tb__DOT__cam__DOT__command_ind 
                    = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__cam__DOT__command_ind)));
                vlSelfRef.tb__DOT__cam__DOT__start_timer = 0U;
            }
        } else if ((0U == vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                    .__PVT__state)) {
            vlSelfRef.tb__DOT__cam__DOT__im.__PVT__start = 1U;
            vlSelfRef.tb__DOT__cam__DOT__dstate = 0U;
            __Vdly__tb__DOT__cam__DOT__sys_state = 2U;
            vlSelfRef.tb__DOT__cam__DOT__im.__PVT__rw = 0U;
            vlSelfRef.tb__DOT__cam__DOT__im.__PVT__mosi = 0x42U;
        }
    } else if (vlSelfRef.tb__DOT__start) {
        vlSelfRef.tb__DOT__cam__DOT__im.__PVT__rst_n = 1U;
        __Vdly__tb__DOT__cam__DOT__sys_state = 1U;
        vlSelfRef.tb__DOT__cam__DOT__im.__PVT__halt = 0U;
    }
    vlSelfRef.tb__DOT__cam__DOT__timer_done = __Vdly__tb__DOT__cam__DOT__timer_done;
    vlSelfRef.tb__DOT__cam__DOT__sys_state = __Vdly__tb__DOT__cam__DOT__sys_state;
    vlSelfRef.tb__DOT__cam__DOT__command_buffer = (
                                                   (0x4cU 
                                                    >= (IData)(vlSelfRef.tb__DOT__cam__DOT__command_ind))
                                                    ? 
                                                   vlSelfRef.tb__DOT__cam__DOT__buffer_rom__DOT__irom
                                                   [vlSelfRef.tb__DOT__cam__DOT__command_ind]
                                                    : 0U);
    vlSelfRef.tb__DOT__cam__DOT__command_ind = __Vdly__tb__DOT__cam__DOT__command_ind;
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__2(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n) {
        vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss 
            = vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss;
        if ((0xbU == (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__counter))) {
            vlSelfRef.__Vdly__tb__DOT__cam__DOT__i2c_master__DOT__counter = 0U;
            vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss.__PVT__scl 
                = (1U & (~ (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss
                                   .__PVT__scl)));
            if ((8U == vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss
                 .__PVT__ind)) {
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss.__PVT__scl = 0U;
            }
        } else {
            vlSelfRef.__Vdly__tb__DOT__cam__DOT__i2c_master__DOT__counter 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__counter)));
        }
        if (((0U == (IData)(vlSelfRef.tb__DOT__cam__DOT__state)) 
             | (1U == (IData)(vlSelfRef.tb__DOT__cam__DOT__state)))) {
            vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss.__PVT__scl = 1U;
        }
    } else {
        vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss 
            = Vtb_tb__DOT__cam__DOT__i2c_master__DOT__system_state__struct__0{
            .__PVT__state = (CData)(0U), .__PVT__scl = (CData)(1U), 
            .__PVT__sda = (CData)(1U), .__PVT__ind = (CData)(0U)};
    }
    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__counter 
        = vlSelfRef.__Vdly__tb__DOT__cam__DOT__i2c_master__DOT__counter;
    vlSelfRef.tb__DOT__cam__DOT__state = vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
        .__PVT__state;
    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm 
        = ((~ (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                      .__PVT__scl)) & (6U == (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__counter)));
    vlSelfRef.tb__DOT__JC__strong__out5 = ((0xefU & (IData)(vlSelfRef.tb__DOT__JC__strong__out5)) 
                                           | (0x10U 
                                              & ((IData)(
                                                         ((vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                           .__PVT__scl
                                                            ? 0xfffffffeU
                                                            : 0xffffffffU) 
                                                          & ((vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                              .__PVT__scl
                                                               ? 0xfffffffeU
                                                               : 0xffffffffU) 
                                                             & (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                                .__PVT__scl
                                                                 ? 0U
                                                                 : 0U)))) 
                                                 << 4U)));
    vlSelfRef.tb__DOT__JC__strong__out6 = ((0xf7U & (IData)(vlSelfRef.tb__DOT__JC__strong__out6)) 
                                           | (8U & 
                                              ((IData)(
                                                       ((vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                         .__PVT__sda
                                                          ? 0xfffffffeU
                                                          : 0xffffffffU) 
                                                        & ((vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                            .__PVT__sda
                                                             ? 0xfffffffeU
                                                             : 0xffffffffU) 
                                                           & (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                              .__PVT__sda
                                                               ? 0U
                                                               : 0U)))) 
                                               << 3U)));
    vlSelfRef.tb__DOT__JC = ((IData)(vlSelfRef.tb__DOT__JC__strong__out2) 
                             | ((IData)(vlSelfRef.tb__DOT__JC__strong__out3) 
                                | ((IData)(vlSelfRef.tb__DOT__JC__strong__out4) 
                                   | (((IData)(vlSelfRef.tb__DOT__JC__strong__out5) 
                                       & ((IData)((vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                   .__PVT__scl
                                                    ? 0U
                                                    : 1U)) 
                                          << 4U)) | 
                                      ((IData)(vlSelfRef.tb__DOT__JC__strong__out6) 
                                       & ((IData)((vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                   .__PVT__sda
                                                    ? 0U
                                                    : 1U)) 
                                          << 3U))))));
    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_hm 
        = ((vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
            .__PVT__scl & (6U == (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__counter))) 
           & ((IData)(vlSelfRef.tb__DOT__JC) >> 4U));
    vlSelfRef.tb__DOT__cam__DOT__rw_done = 0U;
    if ((4U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
         .__PVT__state)) {
        if ((1U & (~ (IData)((vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                              .__PVT__state >> 1U))))) {
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                 .__PVT__state)))) {
                if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_hm) {
                    if ((0U == vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                         .__PVT__ind)) {
                        vlSelfRef.tb__DOT__cam__DOT__rw_done = 1U;
                    }
                    vlSelfRef.tb__DOT__cam__DOT__miso 
                        = (((~ (IData)(((IData)(1U) 
                                        << (7U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                            .__PVT__ind)))) 
                            & (IData)(vlSelfRef.tb__DOT__cam__DOT__miso)) 
                           | (0xffU & ((1U & ((IData)(vlSelfRef.tb__DOT__JC) 
                                              >> 3U)) 
                                       << (7U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                           .__PVT__ind))));
                }
            }
        }
        if ((2U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
             .__PVT__state)) {
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                 .__PVT__state)))) {
                if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm) {
                    vlSelfRef.tb__DOT__cam__DOT__ack = 0U;
                }
            }
        }
    } else if ((2U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                .__PVT__state)) {
        if ((1U & (~ (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                             .__PVT__state)))) {
            if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm) {
                if ((0U == vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                     .__PVT__ind)) {
                    vlSelfRef.tb__DOT__cam__DOT__rw_done = 1U;
                }
            }
        }
        if ((1U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
             .__PVT__state)) {
            if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_hm) {
                vlSelfRef.tb__DOT__cam__DOT__ack = 
                    (2U | (1U & (~ ((IData)(vlSelfRef.tb__DOT__JC) 
                                    >> 3U))));
            }
        } else if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm) {
            if ((0U == vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                 .__PVT__ind)) {
                vlSelfRef.tb__DOT__cam__DOT__ack = 0U;
            }
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__3(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n 
        = vlSelfRef.tb__DOT__cam__DOT__im.__PVT__rst_n;
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss 
        = vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss;
    if ((4U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
         .__PVT__state)) {
        if ((2U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
             .__PVT__state)) {
            if ((1U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                 .__PVT__state)) {
                if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_hm) {
                    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__sda = 1U;
                    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 0U;
                }
            } else if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm) {
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__sda = 0U;
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 7U;
            }
        } else if ((1U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                    .__PVT__state)) {
            if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm) {
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__sda = 0U;
                if ((1U & (~ (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                     .__PVT__sda)))) {
                    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state 
                        = (vlSelfRef.tb__DOT__cam__DOT__im
                           .__PVT__halt ? 6U : (vlSelfRef.tb__DOT__cam__DOT__im
                                                .__PVT__rw
                                                 ? 4U
                                                 : 2U));
                }
            }
        } else if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_hm) {
            vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__ind 
                = (0xfU & ((IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                   .__PVT__ind) - (IData)(1U)));
            if ((0U == vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                 .__PVT__ind)) {
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 5U;
            }
        }
    } else if ((2U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                .__PVT__state)) {
        if ((1U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
             .__PVT__state)) {
            if ((1U & (~ (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_hm)))) {
                if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm) {
                    if (vlSelfRef.tb__DOT__cam__DOT__im
                        .__PVT__halt) {
                        vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 6U;
                    } else if (vlSelfRef.tb__DOT__cam__DOT__im
                               .__PVT__rw) {
                        vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__ind = 7U;
                        vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 4U;
                    } else {
                        vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__ind = 8U;
                        vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 2U;
                    }
                }
            }
        } else if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm) {
            if ((0U == vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                 .__PVT__ind)) {
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__sda = 1U;
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 3U;
            } else {
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__sda 
                    = (1U & (vlSelfRef.tb__DOT__cam__DOT__im
                             .__PVT__mosi >> (7U & 
                                              ((IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                                       .__PVT__ind) 
                                               - (IData)(1U)))));
                vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__ind 
                    = (0xfU & ((IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                       .__PVT__ind) 
                               - (IData)(1U)));
            }
        }
    } else if ((1U & vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                .__PVT__state)) {
        if (vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_hm) {
            vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__sda = 0U;
            vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__ind = 8U;
            vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 2U;
        }
    } else {
        vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__sda = 1U;
        if (vlSelfRef.tb__DOT__cam__DOT__im.__PVT__start) {
            vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = 1U;
        }
    }
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf);

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb___024root___timing_resume(vlSelf);
        Vtb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
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
            Vtb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../src/tb/tb.sv", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../src/tb/tb.sv", 5, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG

std::string VL_TO_STRING(const Vtb_tb__DOT__cam__DOT__i2c_master__DOT__system_state__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{state:" + VL_TO_STRING(obj.__PVT__state);
        out += ", scl:" + VL_TO_STRING(obj.__PVT__scl);
        out += ", sda:" + VL_TO_STRING(obj.__PVT__sda);
        out += ", ind:" + VL_TO_STRING(obj.__PVT__ind);
        out += "}";
    return out;
}

std::string VL_TO_STRING(const Vtb_tb__DOT__cam__DOT__i2c_subsystem__struct__0& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root::VL_TO_STRING\n"); );
    // Body
    std::string out;
    out += "'{rst_n:" + VL_TO_STRING(obj.__PVT__rst_n);
        out += ", start:" + VL_TO_STRING(obj.__PVT__start);
        out += ", halt:" + VL_TO_STRING(obj.__PVT__halt);
        out += ", rw:" + VL_TO_STRING(obj.__PVT__rw);
        out += ", ind:" + VL_TO_STRING(obj.__PVT__ind);
        out += ", mosi:" + VL_TO_STRING(obj.__PVT__mosi);
        out += "}";
    return out;
}
