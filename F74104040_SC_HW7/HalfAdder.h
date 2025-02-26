// HalfAdder.h

#ifndef HALFADDER_H
#define HALFADDER_H

#include "systemc.h"

SC_MODULE(HalfAdder) {
    sc_in<bool> A, B;
    sc_out<bool> Sum, Carry;

    void prc_half_adder();

    SC_CTOR(HalfAdder) {
        SC_METHOD(prc_half_adder);
	sensitive << A << B;
    }
};

#endif // HALFADDER_H
