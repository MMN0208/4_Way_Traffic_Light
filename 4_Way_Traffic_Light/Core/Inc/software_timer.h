/*
 * software_timer.h
 *
 *  Created on: Dec 14, 2022
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

struct timer_count {
    int counter;
    int flag;
};

extern struct timer_count timer1;
extern struct timer_count timer2;
extern struct timer_count timer3;

void setTimer(struct timer_count* timer, int duration);
void timerBreath(struct timer_count* timer);

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
