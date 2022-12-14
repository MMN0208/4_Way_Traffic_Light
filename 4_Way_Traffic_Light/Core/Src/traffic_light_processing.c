/*
 * traffic_light_processing.c
 *
 *  Created on: Dec 13, 2022
 *      Author: nhatmai
 */


#include "traffic_light_processing.h"

GPIO_TypeDef * trafficLightPort[NUM_OF_TRAFFIC_LIGHTS][NUM_OF_PORTS] = {
		{D2_GPIO_Port, D3_GPIO_Port},
		{D4_GPIO_Port, D5_GPIO_Port}
};

uint16_t trafficLightPin[NUM_OF_TRAFFIC_LIGHTS][NUM_OF_PORTS] = {
		{D2_Pin, D3_Pin},
		{D4_Pin, D5_Pin}
};

void trafficLightBlinkGrn(int index) {
	HAL_GPIO_TogglePin(trafficLightPort[index][GRN_LIGHT], trafficLightPin[index][GRN_LIGHT]);
	HAL_GPIO_WritePin(trafficLightPort[index][RED_LIGHT], trafficLightPin[index][RED_LIGHT], OFF);
}

void trafficLightBlinkYel(int index) {
	HAL_GPIO_TogglePin(trafficLightPort[index][GRN_LIGHT], trafficLightPin[index][GRN_LIGHT]);
	HAL_GPIO_TogglePin(trafficLightPort[index][RED_LIGHT], trafficLightPin[index][RED_LIGHT]);
}

void trafficLightBlinkRed(int index) {
	HAL_GPIO_TogglePin(trafficLightPort[index][RED_LIGHT], trafficLightPin[index][RED_LIGHT]);
	HAL_GPIO_WritePin(trafficLightPort[index][GRN_LIGHT], trafficLightPin[index][GRN_LIGHT], OFF);
}

void trafficLightGrn(int index) {
	HAL_GPIO_WritePin(trafficLightPort[index][GRN_LIGHT], trafficLightPin[index][GRN_LIGHT], ON);
	HAL_GPIO_WritePin(trafficLightPort[index][RED_LIGHT], trafficLightPin[index][RED_LIGHT], OFF);
}

void trafficLightYel(int index) {
	HAL_GPIO_WritePin(trafficLightPort[index][GRN_LIGHT], trafficLightPin[index][GRN_LIGHT], ON);
	HAL_GPIO_WritePin(trafficLightPort[index][RED_LIGHT], trafficLightPin[index][RED_LIGHT], ON);
}

void trafficLightRed(int index) {
	HAL_GPIO_WritePin(trafficLightPort[index][RED_LIGHT], trafficLightPin[index][RED_LIGHT], ON);
	HAL_GPIO_WritePin(trafficLightPort[index][GRN_LIGHT], trafficLightPin[index][GRN_LIGHT], OFF);
}

void trafficLightOff(int index) {
	HAL_GPIO_WritePin(trafficLightPort[index][RED_LIGHT], trafficLightPin[index][RED_LIGHT], OFF);
	HAL_GPIO_WritePin(trafficLightPort[index][GRN_LIGHT], trafficLightPin[index][GRN_LIGHT], OFF);
}
