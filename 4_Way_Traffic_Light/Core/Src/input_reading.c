/*
 * input_reading.c
 *
 *  Created on: Dec 13, 2022
 *      Author: ADMIN
 */


#include "input_reading.h"

//button ports and pins array
GPIO_TypeDef * buttonPort[NO_OF_BUTTONS] = {
	A0_GPIO_Port,
	A1_GPIO_Port,
	A2_GPIO_Port,
	A3_GPIO_Port
};

uint16_t buttonPin[NO_OF_BUTTONS] = {
	A0_Pin,
	A1_Pin,
	A2_Pin,
	A3_Pin
};

//debouncing
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
//we define three buffers for debouncing
static GPIO_PinState debounceButtonBuffer0[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPressed[NO_OF_BUTTONS];
static uint8_t flagForButtonHold[NO_OF_BUTTONS];
static uint8_t flagForButtonDoublePressed[NO_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonHold[NO_OF_BUTTONS] = {0, 0, 0, 0};
static uint16_t counterForButtonDoublePressed[NO_OF_BUTTONS] = {0, 0, 0, 0};

void buttonRead(void){
	for(int i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = debounceButtonBuffer0[i];
		debounceButtonBuffer0[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
		if((debounceButtonBuffer2[i] == debounceButtonBuffer1[i]) && (debounceButtonBuffer1[i] == debounceButtonBuffer0[i])) {
			if(buttonBuffer[i] != debounceButtonBuffer0[i]) {
				buttonBuffer[i] = debounceButtonBuffer0[i];
				if(buttonBuffer[i] == BUTTON_IS_PRESSED) {
					counterForButtonHold[i] = DURATION_FOR_BUTTON_HOLD;

					if(counterForButtonDoublePressed[i] > 0 && counterForButtonDoublePressed[i] < WAIT_FOR_DOUBLE_PRESS / SYSTEM_DELAY) {
						flagForButtonDoublePressed[i] = 1;
						counterForButtonDoublePressed[i] = 0;
					}
					else {
						counterForButtonDoublePressed[i] = WAIT_FOR_DOUBLE_PRESS;
					}

					if(SYSTEM_DELAY > 0) {
						counterForButtonHold[i] /= SYSTEM_DELAY;
						counterForButtonDoublePressed[i] /= SYSTEM_DELAY;
					}
				}
				else {
					flagForButtonHold[i] = 0;
					counterForButtonDoublePressed[i]--;
				}
			}
			else {
				if(buttonBuffer[i] == BUTTON_IS_PRESSED) {
					counterForButtonHold[i]--;
					if(counterForButtonHold[i] == 0) {
						flagForButtonHold[i] = 1;
						counterForButtonDoublePressed[i] = 0;
					}
				}
				else {
					if(counterForButtonDoublePressed[i] > 0) {
						counterForButtonDoublePressed[i]--;
						if(counterForButtonDoublePressed[i] == 0) {
							flagForButtonPressed[i] = 1;
						}
					}
				}
			}
		}
	}
}

int isButtonPressed(int index) {
	if(index < 0 || index > NO_OF_BUTTONS) return 0;
	if(flagForButtonPressed[index] == 1) {
		flagForButtonPressed[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonHold(int index) {
	if(index < 0 || index > NO_OF_BUTTONS) return 0;
	if(flagForButtonHold[index] == 1) {
		return 1;
	}
	return 0;
}

int isButtonDoublePressed(int index) {
	if(index < 0 || index > NO_OF_BUTTONS) return 0;
	if(flagForButtonDoublePressed[index] == 1) {
		flagForButtonDoublePressed[index] = 0;
		return 1;
	}
	return 0;
}
