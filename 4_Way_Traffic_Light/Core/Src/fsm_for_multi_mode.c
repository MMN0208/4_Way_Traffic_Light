/*
 * fsm_for_mode_switching.c
 *
 *  Created on: Oct 30, 2022
 *      Author: ADMIN
 */

#include "fsm_for_multi_mode.h"

int newGrnTime = 0;
int newYelTime = 0;

void fsm_multi_mode_run(void) {
	switch(sysStatus) {
	case INIT:
		//init timer 1 for countdown updating
		setTimer1(SECOND);

		//init countdown
		countdown = redTime;

		auto_mode = 1;

		sysStatus = RED__GRN;
		trafficLightRed(TRAFFIC_LIGHT_1);
		trafficLightGrn(TRAFFIC_LIGHT_2);
		displayCountdown(countdown);
		break;

	case RED__GRN:
		if(auto_mode == 1) {
			if(timer1_flag == 1) {
				setTimer1(SECOND);
				countdown--;
				if(countdown == yelTime) {
					sysStatus = RED__YEL;
					trafficLightRed(TRAFFIC_LIGHT_1);
					trafficLightYel(TRAFFIC_LIGHT_2);
				}
				displayCountdown(countdown);
			}

			if(isButtonPressed(BUTTON_1)) {
				auto_mode = 0;
			}
		}
		else {
			if(isButtonPressed(BUTTON_1)) {
				setTimer1(LED_BLINK);
				newGrnTime = grnTime;
				sysStatus = SET_GRN;
				trafficLightGrn(TRAFFIC_LIGHT_1);
				trafficLightGrn(TRAFFIC_LIGHT_2);
				displayCountdown(newGrnTime);
			}
			else if(isButtonPressed(BUTTON_2)) {
				sysStatus = RED__YEL;
				trafficLightRed(TRAFFIC_LIGHT_1);
				trafficLightYel(TRAFFIC_LIGHT_2);
			}
		}

		break;

	case RED__YEL:
		if(auto_mode == 1) {
			if(timer1_flag == 1) {
				setTimer1(SECOND);
				countdown--;
				if(countdown == 0) {
					countdown = grnTime;
					sysStatus = GRN__RED;
					trafficLightGrn(TRAFFIC_LIGHT_1);
					trafficLightRed(TRAFFIC_LIGHT_2);
				}
				displayCountdown(countdown);
			}

			if(isButtonPressed(BUTTON_1)) {
				auto_mode = 0;
			}
		}
		else {
			if(isButtonPressed(BUTTON_1)) {
				setTimer1(LED_BLINK);
				newGrnTime = grnTime;
				sysStatus = SET_GRN;
				trafficLightGrn(TRAFFIC_LIGHT_1);
				trafficLightGrn(TRAFFIC_LIGHT_2);
				displayCountdown(newGrnTime);
			}
			else if(isButtonPressed(BUTTON_2)) {
				sysStatus = GRN__RED;
				trafficLightGrn(TRAFFIC_LIGHT_1);
				trafficLightRed(TRAFFIC_LIGHT_2);
			}
		}
		break;

	case GRN__RED:
		if(auto_mode == 1) {
			if(timer1_flag == 1) {
				setTimer1(SECOND);
				countdown--;
				if(countdown == 0) {
					countdown = yelTime;
					sysStatus = YEL__RED;
					trafficLightYel(TRAFFIC_LIGHT_1);
					trafficLightRed(TRAFFIC_LIGHT_2);
				}
				displayCountdown(countdown);
			}

			if(isButtonPressed(BUTTON_1)) {
				auto_mode = 0;
			}
		}
		else {
			if(isButtonPressed(BUTTON_1)) {
				setTimer1(LED_BLINK);
				newGrnTime = grnTime;
				sysStatus = SET_GRN;
				trafficLightGrn(TRAFFIC_LIGHT_1);
				trafficLightGrn(TRAFFIC_LIGHT_2);
				displayCountdown(newGrnTime);
			}
			else if(isButtonPressed(BUTTON_2)) {
				sysStatus = YEL__RED;
				trafficLightYel(TRAFFIC_LIGHT_1);
				trafficLightRed(TRAFFIC_LIGHT_2);
			}
		}
		break;

	case YEL__RED:
		if(auto_mode == 1) {
			if(timer1_flag == 1) {
				setTimer1(SECOND);
				countdown--;
				if(countdown == 0) {
					countdown = redTime;
					sysStatus = RED__GRN;
					trafficLightRed(TRAFFIC_LIGHT_1);
					trafficLightGrn(TRAFFIC_LIGHT_2);
				}
				displayCountdown(countdown);
			}

			if(isButtonPressed(BUTTON_1)) {
				auto_mode = 0;
			}
		}
		else {
			if(isButtonPressed(BUTTON_1)) {
				setTimer1(LED_BLINK);
				newGrnTime = grnTime;
				sysStatus = SET_GRN;
				trafficLightGrn(TRAFFIC_LIGHT_1);
				trafficLightGrn(TRAFFIC_LIGHT_2);
				displayCountdown(newGrnTime);
			}
			else if(isButtonPressed(BUTTON_2)) {
				sysStatus = RED__GRN;
				trafficLightRed(TRAFFIC_LIGHT_1);
				trafficLightGrn(TRAFFIC_LIGHT_2);
			}
		}
		break;

	case SET_GRN:
		if(isButtonPressed(BUTTON_1)) {
			setTimer1(LED_BLINK);
			newYelTime = yelTime;
			sysStatus = SET_YEL;
			trafficLightYel(TRAFFIC_LIGHT_1);
			trafficLightYel(TRAFFIC_LIGHT_2);
			displayCountdown(newYelTime);
		}
		else if(isButtonPressed(BUTTON_2)) {
			newGrnTime++;
			if(newGrnTime == MAX_VALUE) newGrnTime = 1;
			displayCountdown(newGrnTime);
		}
		else if(isButtonDoublePressed(BUTTON_2)) {
			newGrnTime--;
			if(newGrnTime == 0) newGrnTime = MAX_VALUE - 1;
			displayCountdown(newGrnTime);
		}
		else if(isButtonPressed(BUTTON_3)) {
			grnTime = newGrnTime;
			redTime = grnTime + yelTime;
		}

		if(timer1_flag == 1) {
			setTimer1(LED_BLINK);
			trafficLightBlinkGrn(TRAFFIC_LIGHT_1);
			trafficLightBlinkGrn(TRAFFIC_LIGHT_2);
		}
		break;

	case SET_YEL:
		if(isButtonPressed(BUTTON_1)) {
			sysStatus = INIT;
		}
		else if(isButtonPressed(BUTTON_2)) {
			newYelTime++;
			if(newYelTime == MAX_VALUE) newYelTime = 1;
			displayCountdown(newYelTime);
		}
		else if(isButtonDoublePressed(BUTTON_2)) {
			newYelTime--;
			if(newYelTime == 0) newYelTime = MAX_VALUE - 1;
			displayCountdown(newYelTime);
		}
		else if(isButtonPressed(BUTTON_3)) {
			yelTime = newYelTime;
			redTime = grnTime + yelTime;
		}

		if(timer1_flag == 1) {
			setTimer1(LED_BLINK);
			trafficLightBlinkYel(TRAFFIC_LIGHT_1);
			trafficLightBlinkYel(TRAFFIC_LIGHT_2);
		}
		break;

	default: break;
	}
}
