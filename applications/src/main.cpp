// freeRTOS includes
#include "FreeRTOS.h"
#include "portmacro.h"
#include "projdefs.h"
#include "task.h"
// task includes
#include "constants.hpp"
#include "task-fsm.hpp"

#define BOARD_ID 0 // valid ids: 0-3

int main(void)
{
	// create FSM task TCB, stack buffer, and then spin up the task itself
	StaticTask_t FSMTaskBuffer;
	StackType_t FSMStackBuffer[TASK_STACK_SIZE];
	xTaskCreateStatic((TaskFunction_t)vTaskFSM, "FSM Manager", TASK_STACK_SIZE, (void*)1, vTaskFSMPriority, FSMStackBuffer,
	                  &FSMTaskBuffer);

	vTaskStartScheduler(); // starts scheduler

	// busy loop, don't put anything in here
	for (;;)
	{
	}
}
