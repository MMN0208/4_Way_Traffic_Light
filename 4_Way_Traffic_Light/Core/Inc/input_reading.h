/*
 * button_processing.h
 *
 *  Created on: Dec 13, 2022
 *      Author: nhatmai
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#include "global.h"

//we aim to work with more than one buttons
#define NO_OF_BUTTONS 				       4
//time to register hold
#define DURATION_FOR_BUTTON_HOLD		   1000
//time to wait for double press
#define WAIT_FOR_DOUBLE_PRESS			   500

#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET

#define PEDESTRIAN_BUTTON		0
#define BUTTON_1 				1
#define BUTTON_2				2
#define BUTTON_3				3

void buttonRead(void);
int isButtonPressed(int index);
int isButtonHold(int index);
int isButtonDoublePressed(int index);

#endif /* INC_INPUT_READING_H_ */
