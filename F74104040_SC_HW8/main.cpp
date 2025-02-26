// File name: main.cpp

#include "FIR.h"
#include "systemc.h"

int sc_main(int argc, char* argv[]) {
    // Clock rate = 200MHz
    sc_clock clk("clk", 5, SC_NS);
    sc_signal<bool> rst;
    sc_signal<sc_uint<32>> x;
    sc_signal<sc_uint<32>> y32;
    sc_signal<sc_uint<32>> y48;

    FIR *fir32;
    FIR *fir48;

    fir32 = new FIR("fir32", 32);
    fir32->clk(clk);
    fir32->rst(rst);
    fir32->x(x);
    fir32->y(y32);
    
    fir48 = new FIR("fir48", 48);
    fir48->clk(clk);
    fir48->rst(rst);
    fir48->x(x);
    fir48->y(y48);
    
    // tracing:
    sc_trace_file *tf =
    sc_create_vcd_trace_file("RESULT");

    sc_trace(tf, clk, "clk");
    sc_trace(tf, rst, "rst");
    sc_trace(tf, x, "x");
    sc_trace(tf, y32, "y32");
    sc_trace(tf, y48, "y48");

    // Read firData
    sc_uint<32> data_buf [64];

    ifstream input_data("firData", ios::in);

    if(!input_data.is_open()) {
        cout << "Cannot open file." << endl;
        exit(1);
    }

    for(int i=0; i<64; i++) {
        input_data >> data_buf[i];
    }

    // Reset at first
    rst.write(false);
    sc_start(10 ,SC_NS);

    // Begin to process data
    rst.write(true);
    for (int i = 0; i < 64; i++) {
        x.write(data_buf[i]);
        sc_start(5, SC_NS);
    }

    sc_close_vcd_trace_file(tf);
    
    return 0;
}


