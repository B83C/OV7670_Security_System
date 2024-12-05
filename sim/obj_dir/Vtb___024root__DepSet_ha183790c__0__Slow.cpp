// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_static__TOP(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_static(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtb___024root___eval_static__TOP(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__cam__DOT__command_ind = 0U;
    vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counts_internal = 1U;
    vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counter = 0xf4240U;
}

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e726f6dU;
    __Vtemp_1[1U] = 0x66666572U;
    __Vtemp_1[2U] = 0x305f6275U;
    __Vtemp_1[3U] = 0x76373637U;
    __Vtemp_1[4U] = 0x6fU;
    VL_READMEM_N(true, 16, 77, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                 ,  &(vlSelfRef.tb__DOT__cam__DOT__buffer_rom__DOT__irom)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb___024root___eval_final(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_settle(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_settle\n"); );
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
            Vtb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../src/tb/tb.sv", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__stl\n"); );
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

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__0(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_stl(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        vlSelfRef.__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n 
        = vlSelfRef.tb__DOT__cam__DOT__im.__PVT__rst_n;
    vlSelfRef.tb__DOT__cam__DOT__state = vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
        .__PVT__state;
    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm 
        = ((~ (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                      .__PVT__scl)) & (6U == (IData)(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__counter)));
    vlSelfRef.tb__DOT__JC__strong__out2 = ((0x7fU & (IData)(vlSelfRef.tb__DOT__JC__strong__out2)) 
                                           | ((IData)(vlSelfRef.tb__DOT____Vcellout__cam__rst) 
                                              << 7U));
    vlSelfRef.tb__DOT__JC__strong__out3 = ((0xbfU & (IData)(vlSelfRef.tb__DOT__JC__strong__out3)) 
                                           | ((IData)(vlSelfRef.tb__DOT____Vcellout__cam__pwdn) 
                                              << 6U));
    vlSelfRef.tb__DOT__JC__strong__out4 = ((0xdfU & (IData)(vlSelfRef.tb__DOT__JC__strong__out4)) 
                                           | ((IData)(vlSelfRef.tb__DOT____Vcellout__cam__xclk) 
                                              << 5U));
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
    vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss 
        = vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss;
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
                vlSelfRef.tb__DOT__cam__DOT__ack = 0U;
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

VL_ATTR_COLD void Vtb___024root___eval_triggers__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb.cam.__Vcellinp__i2c_master__reset_n or posedge tb.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb.cam.__Vcellinp__i2c_master__reset_n or posedge tb.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb___024root___ctor_var_reset(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__JB = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__JC = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT____Vcellout__cam__rst = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT____Vcellout__cam__pwdn = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT____Vcellout__cam__xclk = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__JC__strong__out2 = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__JC__strong__out3 = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__JC__strong__out4 = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__JC__strong__out5 = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__JC__strong__out6 = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__cam__DOT__sys_state = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__cam__DOT__start_timer = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__timer_done = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__im.__PVT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__im.__PVT__start = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__im.__PVT__halt = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__im.__PVT__rw = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__im.__PVT__ind = VL_RAND_RESET_I(3);
    vlSelf->tb__DOT__cam__DOT__im.__PVT__mosi = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__cam__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->tb__DOT__cam__DOT__dstate = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__cam__DOT__miso = VL_RAND_RESET_I(8);
    vlSelf->tb__DOT__cam__DOT__rw_done = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__ack = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__cam__DOT__rw_reg = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__i2c_op = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__command_ind = VL_RAND_RESET_I(7);
    vlSelf->tb__DOT__cam__DOT__command_buffer = VL_RAND_RESET_I(16);
    vlSelf->tb__DOT__cam__DOT__delay__DOT__counts_internal = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__cam__DOT__delay__DOT__counter = VL_RAND_RESET_I(21);
    vlSelf->tb__DOT__cam__DOT__delay__DOT__state = 0;
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__ss.__PVT__state = VL_RAND_RESET_I(3);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__ss.__PVT__scl = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__ss.__PVT__sda = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__ss.__PVT__ind = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__state = VL_RAND_RESET_I(3);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__scl = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__sda = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__nss.__PVT__ind = VL_RAND_RESET_I(4);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__scl_hm = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__scl_lm = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__cam__DOT__i2c_master__DOT__counter = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 77; ++__Vi0) {
        vlSelf->tb__DOT__cam__DOT__buffer_rom__DOT__irom[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->__Vdly__tb__DOT__cam__DOT__i2c_master__DOT__counter = VL_RAND_RESET_I(5);
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
