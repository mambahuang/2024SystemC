// File name: HalfAdder.cpp

#include "HalfAdder.h"

void HalfAdder :: prc_half_adder() { 
    Sum.write(A.read() ^ B.read());
    Carry.write(A.read() & B.read());
}
