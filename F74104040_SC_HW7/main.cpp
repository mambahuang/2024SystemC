// File name: main.cpp

#include "HalfAdder.h"
#include "FullAdder.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> A1, B1, Sum1, Carry;
    sc_signal<bool> A2, B2, Sum2, Cin, Cout;

    HalfAdder half_adder("HalfAdder");
    half_adder.A(A1);
    half_adder.B(B1);
    half_adder.Sum(Sum1);
    half_adder.Carry(Carry);

    FullAdder full_adder("FullAdder");
    full_adder.A(A2);
    full_adder.B(B2);
    full_adder.Cin(Cin);
    full_adder.S(Sum2);
    full_adder.Cout(Cout);
    
    // Create trace file
    sc_trace_file *tf = 
    sc_create_vcd_trace_file("RESULT");

    // Ports need to check
    // Half adder: A, B, Sum, Carry
    // Full adder: A, B, Cin, S, Cout
    sc_trace(tf, A1, "Half-adder_A");
    sc_trace(tf, B1, "Half-adder_B");
    sc_trace(tf, Sum1, "Half-adder_Sum");
    sc_trace(tf, Carry, "Half-adder_Carry");

    sc_trace(tf, A2, "Full-adder_A");
    sc_trace(tf, B2, "Full-adder_B");
    sc_trace(tf, Cin, "Full-adder_Cin");
    sc_trace(tf, Sum2, "Full-adder_S");
    sc_trace(tf, Cout, "Full-adder_Cout");
    
    for (int i = 0; i<4; i++) {
        A1.write(i & 1);
	B1.write((i >> 1) & 1);
	sc_start(1, SC_NS);
    }

    for (int i = 0; i < 8; i++) {
        A2.write(i & 1);
	B2.write((i >> 1) & 1);
	Cin.write((i >> 2) & 1);
	sc_start(1, SC_NS);
    }

    sc_close_vcd_trace_file(tf);
    return 0;
}


