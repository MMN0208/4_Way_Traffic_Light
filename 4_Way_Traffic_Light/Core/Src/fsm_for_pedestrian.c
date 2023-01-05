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
			setTimer2(timeOut);
			setTimer3(TIMER_INIT);
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
			setTimer2(timeOut);
		}
		else if(sysStatus == SET_GRN || sysStatus == SET_YEL) {
			setTimer2(0);
			pedestrianStatus = WAIT;
			pedestrianLightOff();
			stopBuzzer();
		}
		else if(timer2_flag == 1) {
			setTimer2(0);
			pedestrianStatus = WAIT;
			pedestrianLightOff();
			stopBuzzer();
		}
		else if(sysStatus == GRN__RED) {
			pedestrianStatus = RED;
			pedestrianLightRed();
			redBuzzer();
		}
		else if(timer3_flag == 1) {
			if(sysStatus == RED__YEL) {
				setTimer3(LED_BLINK);
				pedestrianLightBlinkGrn();
				grnBuzzer();
			}
			else {
				setTimer3(200);
				grnBuzzer();
			}
		}

		break;

	case RED:
		if(isButtonPressed(PEDESTRIAN_BUTTON)) {
			timeOut = (redTime + yelTime + grnTime) * SECOND;
			setTimer2(timeOut);
		}
		else if(sysStatus == SET_GRN || sysStatus == SET_YEL) {
			setTimer2(0);
			pedestrianStatus = WAIT;
			pedestrianLightOff();
			stopBuzzer();
		}
		else if(timer2_flag == 1) {
			setTimer2(0);
			pedestrianStatus = WAIT;
			pedestrianLightOff();
			stopBuzzer();
		}
		else if(sysStatus == RED__GRN) {
			pedestrianStatus = GRN;
			pedestrianLightGrn();
			grnBuzzer();
		}
		else if(timer3_flag == 1) {
			if(sysStatus == YEL__RED) {
				setTimer3(LED_BLINK);
				pedestrianLightBlinkRed();
				redBuzzer();
			}
			else {
				setTimer3(200);
				redBuzzer();
			}
		}

		break;
	}
}
