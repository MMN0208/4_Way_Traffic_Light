/*
 * software_timer.c
 *
 *  Created on: Dec 14, 2022
 *      Author: ADMIN
 */


#include "software_timer.h"

struct timer_count timer1;
struct timer_count timer2;
struct timer_count timer3;

// Blame Nguyen Tran
/* DEPENDENCY INJECTION */
void setTimer(struct timer_count* timer, int duration) {
    int tick = SYSTEM_DELAY;
    if (tick <= 0) {
        tick = 1;
    }
    timer->counter = duration / tick;
    timer->flag = 0;
}

void timerBreath(struct timer_count* timer) {
    if (timer->counter > 0) {
        timer->counter -= 1;
        if (timer->counter <= 0) {
            timer->flag = 1;
        }
    }
}

