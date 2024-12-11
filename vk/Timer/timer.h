#ifndef TIMER_H
#define TIMER_H
#include <sys/time.h>

typedef struct {
    struct timeval start;
    struct timeval end;
} Timer;

void start_timer(Timer *timer);

void stop_timer(Timer *timer);

double elapsed_time(const Timer *timer);

#endif
