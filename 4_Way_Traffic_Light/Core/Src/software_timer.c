/*
 * software_timer.c
 *
 *  Created on: Dec 14, 2022
 *      Author: ADMIN
 */


#include "software_timer.h"

// int timer1_counter = 0;
// int timer1_flag = 0;

// int timer2_counter = 0;
// int timer2_flag = 0;

// int timer3_counter = 0;
// int timer3_flag = 0;

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

// void setTimer1(int duration) {
// 	if(SYSTEM_DELAY > 0) {
// 		timer1_counter = duration / SYSTEM_DELAY;
// 	} else timer1_counter = duration;
// 	timer1_flag = 0;
// }

// void setTimer2(int duration) {
// 	if(SYSTEM_DELAY > 0) {
// 		timer2_counter = duration / SYSTEM_DELAY;
// 	} else timer2_counter = duration;
// 	timer2_flag = 0;
// }


// void setTimer3(int duration) {
// 	if(SYSTEM_DELAY > 0) {
// 		timer3_counter = duration / SYSTEM_DELAY;
// 	} else timer3_counter = duration;
// 	timer3_flag = 0;
// }

// void timerRun(void) {
// 	if(timer1_counter > 0) {
// 		timer1_counter--;
// 		if(timer1_counter <= 0) {
// 			timer1_flag = 1;
// 		}
// 	}

// 	if(timer2_counter > 0) {
// 		timer2_counter--;
// 		if(timer2_counter <= 0) {
// 			timer2_flag = 1;
// 		}
// 	}

// 	if(timer3_counter > 0) {
// 		timer3_counter--;
// 		if(timer3_counter <= 0) {
// 			timer3_flag = 1;
// 		}
// 	}
// }
