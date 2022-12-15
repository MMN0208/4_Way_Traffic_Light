/*
 * global.h
 *
 *  Created on: Dec 13, 2022
 *      Author: nhatmai
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "input_reading.h"
#include "uart_communication.h"
#include "traffic_light_processing.h"
#include "pedestrian_light_processing.h"
#include "buzzer_interfacing.h"

#define SYSTEM_DELAY 	10
#define SECOND			1000 // 1s = 1000ms
#define TIMER_INIT 		10 // 10ms
#define LED_BLINK		100 // 2Hz = 0.5s

typedef enum  {
	INIT,
	RED__GRN,
	RED__YEL,
	GRN__RED,
	YEL__RED,
	SET_YEL,
	SET_GRN
} systemState;

extern systemState sysStatus;

typedef enum {
	WAIT,
	GRN,
	RED
} pedestrianState;

extern pedestrianState pedestrianStatus;

extern int redTime;
extern int yelTime;
extern int grnTime;

extern int countdown;

extern int auto_mode;

#endif /* INC_GLOBAL_H_ */
