// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb1__Syms.h"


void Vtb1___024root__trace_chg_0_sub_0(Vtb1___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb1___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root__trace_chg_0\n"); );
    // Init
    Vtb1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb1___024root*>(voidSelf);
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb1___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb1___024root__trace_chg_0_sub_0(Vtb1___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelfRef.tb1__DOT__scale_cntr_x),2);
        bufp->chgCData(oldp+1,(vlSelfRef.tb1__DOT__scale_cntr_y),2);
        bufp->chgCData(oldp+2,(vlSelfRef.tb1__DOT__x_cntr),3);
        bufp->chgCData(oldp+3,(vlSelfRef.tb1__DOT__y_cntr),3);
        bufp->chgCData(oldp+4,(vlSelfRef.tb1__DOT__c_x),6);
        bufp->chgCData(oldp+5,(vlSelfRef.tb1__DOT__c_y),5);
        bufp->chgCData(oldp+6,(vlSelfRef.tb1__DOT__r),4);
        bufp->chgCData(oldp+7,(vlSelfRef.tb1__DOT__g),4);
        bufp->chgCData(oldp+8,(vlSelfRef.tb1__DOT__b),4);
    }
    bufp->chgBit(oldp+9,(vlSelfRef.tb1__DOT__clk));
    bufp->chgCData(oldp+10,(vlSelfRef.tb1__DOT__character_addr),7);
    bufp->chgSData(oldp+11,(vlSelfRef.tb1__DOT__x),12);
    bufp->chgSData(oldp+12,(vlSelfRef.tb1__DOT__y),12);
}

void Vtb1___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb1___024root__trace_cleanup\n"); );
    // Init
    Vtb1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb1___024root*>(voidSelf);
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
