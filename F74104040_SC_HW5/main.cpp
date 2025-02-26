// main.cpp

#include "timer.h"
#include "systemc.h"

int sc_main(int argc, char* argv[]) {
    sc_clock CLOCK("clock", 10, SC_NS); // 100MHZ
    sc_signal<bool> timeout, start;

    timer tm1("timer"); // timer instantiation
    tm1.start(start);
    tm1.timeout(timeout);
    tm1.clock(CLOCK);

    // tracing:
    // trace file creation, with VCD type output
    sc_trace_file *tf = 
    sc_create_vcd_trace_file("RESULT");
    // External signals
    sc_trace(tf, CLOCK, "clock");
    sc_trace(tf, start, "start");
    sc_trace(tf, timeout, "timeout");
    sc_trace(tf, tm1.count, "count");
    
    //Simulation
    //Scenario 1: Reset for 3 cycles
    start.write(1);
    sc_start(30, SC_NS); // 30ns = 3 cycles
    
    // Scenario 2: During counting reset
    // the timer before count reaches 0 and
    // Scenario 3: During counting reset
    // timer after count reaches 0
    sc_start(10, SC_NS);
    for (int i=1; i<6; i++) {
	start.write(0); // Start counting
        sc_start(i*10, SC_NS);
	start.write(1);
	sc_start(10, SC_NS); // Quick reset
    }
    start.write(0); // timeout

    // Until Now use 240 cycles
    // Keep count == 5 to 30th-cycle
    sc_start(60, SC_NS);    
    
    // Close the VCD file
    sc_close_vcd_trace_file(tf);

    return(0);

}
