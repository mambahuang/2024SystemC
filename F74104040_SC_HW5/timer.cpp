// timer.cpp

#include <timer.h>

void timer::runtimer() {
    while(1) {
        if (start.read()) {
	    cout << "Timer: timer start detected " << endl;
	    count.write(5);
	    timeout.write(0);
        } else {
	    if (count.read() == 0) {
                timeout.write(1);
	    } else {
		count.write(count.read() - 1);
		timeout.write(0);
	    }
        }
	wait();
    }
}
