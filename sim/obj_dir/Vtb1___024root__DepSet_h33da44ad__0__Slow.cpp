// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb1.h for the primary calling header

#include "Vtb1__pch.h"
#include "Vtb1__Syms.h"
#include "Vtb1___024root.h"

VL_ATTR_COLD void Vtb1___024root___eval_initial__TOP(Vtb1___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x666f726dU;
    __Vtemp_1[2U] = 0x77617665U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.tb1__DOT__character_addr = 0x68U;
    __Vtemp_2[0U] = 0x2e726f6dU;
    __Vtemp_2[1U] = 0x73636969U;
    __Vtemp_2[2U] = 0x61U;
    VL_READMEM_N(true, 64, 128, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_2)
                 ,  &(vlSelfRef.tb1__DOT__ascii__DOT__irom)
                 , 0, ~0ULL);
}
