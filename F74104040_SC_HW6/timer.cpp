// timer.cpp
#include "timer.h"

void timer::runtimer() {
    count = 5;
    timeout.write(0);
    while(1) {
        wait();
        if (count == 0) {
            timeout.write(1);
        } else {
            count--;
            timeout.write(0);
        }
    }
}


