#include "timer.h"

void start_timer(Timer *timer) {
    gettimeofday(&timer->start, NULL);
}

void stop_timer(Timer *timer) {
    gettimeofday(&timer->end, NULL);
}

double elapsed_time(const Timer *timer) {
    long seconds = timer->end.tv_sec - timer->start.tv_sec;
    long microseconds = timer->end.tv_usec - timer->start.tv_usec;
    return seconds + microseconds * 1e-6;
}
