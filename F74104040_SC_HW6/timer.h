// timer.h

#include "systemc.h"

SC_MODULE(timer) {
    sc_in<bool> start;
    sc_out<bool> timeout;
    sc_in<bool> clock;

    // int count;
    sc_uint<3> count;
    void runtimer();

    SC_CTOR(timer) {
        SC_CTHREAD(runtimer, clock.pos());
	reset_signal_is(start, true);
    }
};
