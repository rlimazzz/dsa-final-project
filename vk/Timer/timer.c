#include "timer.h"
#include <errno.h>
#include <stdio.h>

void start_timer(Timer *timer) {
    if (gettimeofday(&timer->start, NULL) == -1) {
        perror("Error starting timer");
    }
}

void stop_timer(Timer *timer) {
    if (gettimeofday(&timer->end, NULL) == -1) {
        perror("Error stopping timer");
    }
}

double elapsed_time(const Timer *timer) {
    long seconds = timer->end.tv_sec - timer->start.tv_sec;
    long microseconds = timer->end.tv_usec - timer->start.tv_usec;
    
    if (microseconds < 0) {
        seconds -= 1;
        microseconds += 1000000;
    }

    return seconds + microseconds * 1e-6;
}
