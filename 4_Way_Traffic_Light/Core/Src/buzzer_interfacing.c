/*
 * buzzer_interfacing.c
 *
 *  Created on: Dec 15, 2022
 *      Author: nhatmai
 */



#include "buzzer_interfacing.h"
#include "note.h"

int grnBuzzerCounter = 0;
int redBuzzerCounter = 0;


int music1 [] = {
	NOTE_E7, NOTE_E7, 0, NOTE_E7,
	0, NOTE_C7, NOTE_E7, 0,
	NOTE_G7, 0, 0,  0,
	NOTE_G6, 0, 0, 0,

	NOTE_C7, 0, 0, NOTE_G6,
	0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6,
	0, NOTE_AS6, NOTE_A6, 0,

	NOTE_G6, NOTE_E7, NOTE_G7,
	NOTE_A7, 0, NOTE_F7, NOTE_G7,
	0, NOTE_E7, 0, NOTE_C7,
	NOTE_D7, NOTE_B6, 0, 0,

	NOTE_C7, 0, 0, NOTE_G6,
	0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6,
	0, NOTE_AS6, NOTE_A6, 0,

	NOTE_G6, NOTE_E7, NOTE_G7,
	NOTE_A7, 0, NOTE_F7, NOTE_G7,
	0, NOTE_E7, 0, NOTE_C7,
	NOTE_D7, NOTE_B6, 0, 0
};

int music2[] = {
	NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
	NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,
	NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
	NOTE_C4, NOTE_D4,0,

	NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
	NOTE_G4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,      //29               //8
	NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
	NOTE_C4, NOTE_D4,0,

	NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
	NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
	NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_D5, NOTE_C5,
	NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4,             //58

	NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
	NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_G4,
	NOTE_A4, 0, NOTE_AS4, NOTE_A4, 0, NOTE_G4,
	NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, 0,

	NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
	NOTE_C4, NOTE_D4, 0,
	NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
	NOTE_C4, NOTE_D4
};


const int music1Duration[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12
};

const int music2Duration[] = {
  8,4,8,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,16,4,

  8,4,8,4,
  4,2,1,1,2,1,1,12,
  4,4,4,4,4,4,
  4,16,4,

  4,4,4,4,4,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,4,4,12,

  4,4,4,4,4,4,
  2,1,1,2,1,1,4,8,4,
  2,6,4,2,6,4,
  2,1,1,16,4,

  4,8,4,4,4,
  4,16,4,
  4,8,4,4,4,
  4,20,
};

void grnBuzzer(void) {
	int counter = sizeof(music1)/sizeof(music1[0]);
//	if(grnBuzzerCounter == 0) grnBuzzerCounter = 10;
//	if(grnBuzzerCounter < 20) {
//		__HAL_TIM_SET_AUTORELOAD(&htim3, music[grnBuzzerCounter]);
//		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 10);
//		grnBuzzerCounter++;
//	}
//	else {
//		grnBuzzerCounter = 10;
//	}
	if (grnBuzzerCounter < counter){
		__HAL_TIM_SET_AUTORELOAD(&htim3, 1000000/music1[grnBuzzerCounter]);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 15);
		grnBuzzerCounter++;
	} else {
		grnBuzzerCounter = 0;
	}
}

void redBuzzer(void) {
	int counter = sizeof(music2)/sizeof(music2[0]);
	if(redBuzzerCounter < counter) {
		__HAL_TIM_SET_AUTORELOAD(&htim3, music2[redBuzzerCounter]);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 15);
//		__HAL_TIM_SET_PRESCALER(&htim3,music2[redBuzzerCounter]);
		redBuzzerCounter ++;
	}
	else {
		redBuzzerCounter  = 0;
	}
}

void stopBuzzer(void) {
	__HAL_TIM_SET_AUTORELOAD(&htim3, 0);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
}
