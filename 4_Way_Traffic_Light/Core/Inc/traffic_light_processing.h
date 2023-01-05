/*
 * traffic_light_processing.h
 *
 *  Created on: Dec 13, 2022
 *      Author: nhatmai
 */

#ifndef INC_TRAFFIC_LIGHT_PROCESSING_H_
#define INC_TRAFFIC_LIGHT_PROCESSING_H_

#include "main.h"
#include "global.h"

#define ON			GPIO_PIN_SET
#define OFF			GPIO_PIN_RESET

#define NUM_OF_TRAFFIC_LIGHTS		2
#define NUM_OF_PORTS 				2

#define RED_LIGHT	0
#define GRN_LIGHT 	1

#define TRAFFIC_LIGHT_1 	0
#define TRAFFIC_LIGHT_2		1

#define MAX_VALUE			100

void trafficLightBlinkGrn(int index);
void trafficLightBlinkYel(int index);
void trafficLightBlinkRed(int index);

void trafficLightGrn(int index);
void trafficLightYel(int index);
void trafficLightRed(int index);

void trafficLightOff(int index);

#endif /* INC_TRAFFIC_LIGHT_PROCESSING_H_ */
