/*
 * fsm_for_pedestrian.c
 *
 *  Created on: Dec 15, 2022
 *      Author: ADMIN
 */


#include "fsm_for_pedestrian.h"

int timeOut;

void fsm_for_pedestrian(void) {
	switch(pedestrianStatus) {
	case WAIT:
		if(isButtonPressed(PEDESTRIAN_BUTTON)) {
			timeOut = (redTime + yelTime + grnTime) * SECOND;
			setTimer(&timer2, timeOut);
			setTimer(&timer3, TIMER_INIT);
			if(sysStatus == RED__GRN || sysStatus == RED__YEL) {
				pedestrianStatus = GRN;
				pedestrianLightGrn();
				grnBuzzer();
			}
			else if(sysStatus == GRN__RED || sysStatus == YEL__RED) {
				pedestrianStatus = RED;
				pedestrianLightRed();
				redBuzzer();
			}
		}
		break;

	case GRN:
		if(isButtonPressed(PEDESTRIAN_BUTTON)) {
			timeOut = (redTime + yelTime + grnTime) * SECOND;
			setTimer(&timer2, timeOut);
		}

		if(sysStatus == SET_GRN || sysStatus == SET_YEL) {
			setTimer(&timer2, 0);
			pedestrianStatus = WAIT;
			pedestrianLightOff();
			stopBuzzer();
		}

		if(timer2.flag == 1) {
			setTimer(&timer2, 0);
			pedestrianStatus = WAIT;
			pedestrianLightOff();
			stopBuzzer();
		}

		if(sysStatus == GRN__RED) {
			pedestrianStatus = RED;
			pedestrianLightRed();
			redBuzzer();
		}

		if(timer3.flag == 1) {
			if(sysStatus == RED__YEL) {
				setTimer(&timer3, LED_BLINK);
				pedestrianLightBlinkGrn();
				grnBuzzer();
			}
			else {
				setTimer(&timer3, 200);
				grnBuzzer();
			}
		}

		break;

	case RED:
		if(isButtonPressed(PEDESTRIAN_BUTTON)) {
			timeOut = (redTime + yelTime + grnTime) * SECOND;
			setTimer(&timer2, timeOut);
		}

		if(sysStatus == SET_GRN || sysStatus == SET_YEL) {
			setTimer(&timer2, 0);
			pedestrianStatus = WAIT;
			pedestrianLightOff();
			stopBuzzer();
		}

		if(timer2.flag == 1) {
			setTimer(&timer2, 0);
			pedestrianStatus = WAIT;
			pedestrianLightOff();
			stopBuzzer();
		}

		if(sysStatus == RED__GRN) {
			pedestrianStatus = GRN;
			pedestrianLightGrn();
			grnBuzzer();
		}

		if(timer3.flag == 1) {
			if(sysStatus == YEL__RED) {
				setTimer(&timer3, LED_BLINK);
				pedestrianLightBlinkRed();
				redBuzzer();
			}
			else {
				setTimer(&timer3, 200);
				redBuzzer();
			}
		}

		break;
	}
}
