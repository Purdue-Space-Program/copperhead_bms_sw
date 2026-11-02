#include "FreeRTOS.h"
#include "constants.hpp"
#include "queue.h"
#include "task-telem.hpp"
#include "task.h"

void vTaskFSM(void* parameters)
{
	// create and schedule helper tasks
	StaticTask_t telemSenderTCB;
	StackType_t telemSenderStack[TASK_STACK_SIZE];
	xTaskCreateStatic((TaskFunction_t)vTaskTelemSender, "this guy sends telemetry", TASK_STACK_SIZE, (void*)1,
	                  vTaskTelemSenderPriority, telemSenderStack, &telemSenderTCB);

	/*
	StaticTask_t commandListenerTCB;
	StackType_t commandListenerStack[TASK_STACK_SIZE];
	xTaskCreateStatic((TaskFunction_t)vTaskFSM, "FSM Manager", TASK_STACK_SIZE, (void*)1, vTaskTelemSenderPriority,
	telemSenderStack, &telemSenderTCB);
	*/

	static state currentState = SAFE; // init to safe
	static state nextState;

	for (;;) // FOR... EVER!
	{

		// output based on state
		switch (currentState)
		{
		case (FAULT): {

			break;
		}

		case (SAFE): {
			break;
		}

		case (ARM): {
			break;
		}

		case (CHARGE): {
			break;
		}

		case (DISCHARGE): {
			break;
		}

		default: {
			// oh no
			nextState = currentState;
		}
		}

		// === compute next state ===
	}
}
