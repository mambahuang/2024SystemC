// File name: FIR.h

#ifndef FIR_H
#define FIR_H

#include "systemc.h"
#include <sysc/datatypes/fx/sc_fixed.h>

#include <iostream>

using namespace sc_dt;

SC_MODULE(FIR) {
    sc_in<sc_uint<32> > x;
    sc_out<sc_uint<32> > y;

    sc_in<bool> clk;
    sc_in<bool> rst;
    
    sc_signal<sc_uint<32> > *shifts;
    sc_fixed<32, 16> fb;
    sc_uint<32> b;
    sc_uint<32> acc;
    unsigned int num_taps;

    void fir_proc();

    FIR(sc_module_name name_, unsigned int taps = 16) :
        sc_module(name_), num_taps(taps) {
        SC_CTHREAD(fir_proc, clk.pos());
        reset_signal_is(rst, false);
	
        shifts = new sc_signal<sc_uint<32> > [num_taps];
    }

};

#endif
