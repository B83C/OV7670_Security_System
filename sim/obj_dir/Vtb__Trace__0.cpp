// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb__Syms.h"


void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0_sub_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelfRef.tb__DOT__cam__DOT__sys_state),2);
        bufp->chgBit(oldp+1,(vlSelfRef.tb__DOT__cam__DOT__start_timer));
        bufp->chgBit(oldp+2,(vlSelfRef.tb__DOT__cam__DOT__timer_done));
        bufp->chgBit(oldp+3,(vlSelfRef.tb__DOT__cam__DOT__im
                             .__PVT__rst_n));
        bufp->chgBit(oldp+4,(vlSelfRef.tb__DOT__cam__DOT__im
                             .__PVT__start));
        bufp->chgBit(oldp+5,(vlSelfRef.tb__DOT__cam__DOT__im
                             .__PVT__halt));
        bufp->chgBit(oldp+6,(vlSelfRef.tb__DOT__cam__DOT__im
                             .__PVT__rw));
        bufp->chgCData(oldp+7,(vlSelfRef.tb__DOT__cam__DOT__im
                               .__PVT__ind),3);
        bufp->chgCData(oldp+8,(vlSelfRef.tb__DOT__cam__DOT__im
                               .__PVT__mosi),8);
        bufp->chgCData(oldp+9,(vlSelfRef.tb__DOT__cam__DOT__dstate),2);
        bufp->chgCData(oldp+10,(vlSelfRef.tb__DOT__cam__DOT__command_ind),7);
        bufp->chgSData(oldp+11,(vlSelfRef.tb__DOT__cam__DOT__command_buffer),16);
        bufp->chgCData(oldp+12,(vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counts_internal),2);
        bufp->chgIData(oldp+13,(vlSelfRef.tb__DOT__cam__DOT__delay__DOT__counter),21);
        bufp->chgIData(oldp+14,(vlSelfRef.tb__DOT__cam__DOT__delay__DOT__state),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+15,(vlSelfRef.tb__DOT__JC),8);
        bufp->chgBit(oldp+16,((1U & (IData)(vlSelfRef.tb__DOT__JC))));
        bufp->chgBit(oldp+17,((1U & ((IData)(vlSelfRef.tb__DOT__JC) 
                                     >> 1U))));
        bufp->chgBit(oldp+18,((1U & ((IData)(vlSelfRef.tb__DOT__JC) 
                                     >> 2U))));
        bufp->chgBit(oldp+19,((1U & ((IData)(vlSelfRef.tb__DOT__JC) 
                                     >> 3U))));
        bufp->chgBit(oldp+20,((1U & ((IData)(vlSelfRef.tb__DOT__JC) 
                                     >> 4U))));
        bufp->chgCData(oldp+21,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                .__PVT__state),3);
        bufp->chgCData(oldp+22,(vlSelfRef.tb__DOT__cam__DOT__miso),8);
        bufp->chgBit(oldp+23,(vlSelfRef.tb__DOT__cam__DOT__rw_done));
        bufp->chgCData(oldp+24,(vlSelfRef.tb__DOT__cam__DOT__ack),2);
        bufp->chgBit(oldp+25,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                              .__PVT__scl));
        bufp->chgBit(oldp+26,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                              .__PVT__sda));
        bufp->chgCData(oldp+27,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__ss
                                .__PVT__ind),4);
        bufp->chgBit(oldp+28,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_hm));
        bufp->chgBit(oldp+29,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__scl_lm));
        bufp->chgCData(oldp+30,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__counter),5);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+31,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss
                                .__PVT__state),3);
        bufp->chgBit(oldp+32,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss
                              .__PVT__scl));
        bufp->chgBit(oldp+33,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss
                              .__PVT__sda));
        bufp->chgCData(oldp+34,(vlSelfRef.tb__DOT__cam__DOT__i2c_master__DOT__nss
                                .__PVT__ind),4);
    }
    bufp->chgBit(oldp+35,(vlSelfRef.tb__DOT__clk));
    bufp->chgBit(oldp+36,(vlSelfRef.tb__DOT__start));
    bufp->chgBit(oldp+37,(vlSelfRef.tb__DOT__cam__DOT____Vcellinp__i2c_master__reset_n));
}

void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_cleanup\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
