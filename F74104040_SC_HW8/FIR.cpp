// File name: FIR.cpp

#include "FIR.h"

void FIR::fir_proc() {
    
    /* Reset */
    // Reset summation
    acc = 0;
    // Reset bi generation
    fb = (float)1/(num_taps + 1);
    for (int i=0; i<32; i++)
        b[i] = fb[i];
    cout << "b of tap " << dec << num_taps << " is 0x" << hex << b << endl;
    // Reset all delays (Initialization)
    for (int i = 0; i < num_taps; i++)
        shifts[i].write(0);
    while(1) {
	wait();
	shifts[0].write(x.read());

	for (int i = num_taps - 1; i > 0; i--) {
	    shifts[i] = shifts[i - 1];
	}

	acc = x.read() * b;
        for (int i = 0; i < num_taps; i++) {
	    acc += shifts[i].read() * b;
	}
	y.write(acc);
    }

}

