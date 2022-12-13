/*
 * sched.h
 *
 *  Created on: Dec 13, 2022
 *      Author: nhatmai
 */

#ifndef INC_SCHED_H_
#define INC_SCHED_H_

#include "global.h"
#include "task.h"

#define SCH_MAX_TASKS	40

void SCH_Init(void);
uint32_t SCH_Add_Task(void (* pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
void SCH_Delete_Task(uint32_t TASK_INDEX);
void SCH_Dispatch_Tasks(void);
void SCH_Update(void);


#endif /* INC_SCHED_H_ */
