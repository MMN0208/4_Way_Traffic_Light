/*
 * uart_communication.c
 *
 *  Created on: Dec 14, 2022
 *      Author: ADMIN
 */


#include "uart_communication.h"

void displayCountdown(int value) {
	char str[50];
	HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "!7SEG=%d#\r\n", value), 1000);
}
