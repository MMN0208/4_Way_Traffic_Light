/*
 * global.c
 *
 *  Created on: Dec 14, 2022
 *      Author: ADMIN
 */


#include "global.h"

systemState sysStatus = INIT;

pedestrianState pedestrianStatus = WAIT;

int redTime = 5;
int yelTime = 2;
int grnTime = 3;

int countdown = 0;

int auto_mode = 1;
