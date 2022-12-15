/*
 * buzzer_interfacing.c
 *
 *  Created on: Dec 15, 2022
 *      Author: nhatmai
 */



#include "buzzer_interfacing.h"

int x = 0;

void grnBuzzer(void) {
	if(x == 0) x = 10;
	if(x < 20) {
		__HAL_TIM_SET_AUTORELOAD(&htim3, x * 2);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, x);
		x++;
	}
	else {
		x = 10;
	}
}

void redBuzzer(void) {
	if(x == 0) x = 19;
	if(x > 9) {
		__HAL_TIM_SET_AUTORELOAD(&htim3, x * 2);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, x);
		x--;
	}
	else {
		x = 19;
	}
}

void stopBuzzer(void) {
	x = 0;
	__HAL_TIM_SET_AUTORELOAD(&htim3, x);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, x);
}
