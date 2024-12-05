// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb1__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtb1::Vtb1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb1__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtb1::Vtb1(const char* _vcname__)
    : Vtb1(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb1::~Vtb1() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb1___024root___eval_debug_assertions(Vtb1___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb1___024root___eval_static(Vtb1___024root* vlSelf);
void Vtb1___024root___eval_initial(Vtb1___024root* vlSelf);
void Vtb1___024root___eval_settle(Vtb1___024root* vlSelf);
void Vtb1___024root___eval(Vtb1___024root* vlSelf);

void Vtb1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb1___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb1___024root___eval_static(&(vlSymsp->TOP));
        Vtb1___024root___eval_initial(&(vlSymsp->TOP));
        Vtb1___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb1___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtb1::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtb1::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vtb1::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb1::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb1___024root___eval_final(Vtb1___024root* vlSelf);

VL_ATTR_COLD void Vtb1::final() {
    Vtb1___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb1::hierName() const { return vlSymsp->name(); }
const char* Vtb1::modelName() const { return "Vtb1"; }
unsigned Vtb1::threads() const { return 1; }
void Vtb1::prepareClone() const { contextp()->prepareClone(); }
void Vtb1::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtb1::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtb1___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtb1___024root__trace_init_top(Vtb1___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb1___024root*>(voidSelf);
    Vtb1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb1___024root__trace_decl_types(tracep);
    Vtb1___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void Vtb1___024root__trace_register(Vtb1___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb1::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb1::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtb1___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
