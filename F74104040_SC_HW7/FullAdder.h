// File name: FullAdder.h

#ifndef FULLADDER_H
#define FULLADDER_H

#include "systemc.h"
#include "HalfAdder.h"

SC_MODULE(FullAdder) {
    sc_in <bool> A, B, Cin;
    sc_out <bool> S, Cout;
    sc_signal <bool> s1, c1, c2;

    void prc_or();

    //The Full adder consists of two half adders,
    //one or_gate, and interconnections.
    //Instantiation of 2 half adders
    HalfAdder *ha1_ptr, *ha2_ptr;

    //---------------Constructor----------------
    SC_CTOR(FullAdder) {
        ha1_ptr = new HalfAdder("ha1");
        ha2_ptr = new HalfAdder("ha2");

        ha1_ptr->A(A);
        ha1_ptr->B(B);
        ha1_ptr->Sum(s1);
        ha1_ptr->Carry(c1);
        
        ha2_ptr->A(s1);
        ha2_ptr->B(Cin);
        ha2_ptr->Sum(S);
        ha2_ptr->Carry(c2);	

        SC_METHOD(prc_or);
        sensitive << c1 << c2;
    }

    //----------------Destructor-----------------
    ~FullAdder() {
        delete ha1_ptr;
        delete ha2_ptr;
    }
};

#endif // FULLADDER_H
