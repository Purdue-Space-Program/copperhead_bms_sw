#include "task-fsm.hpp" //this is where states are defined
#include "FreeRTOS.h"
#include "constants.hpp"
#include "queue.h"
#include "task-telem.hpp"
#include "task.h"

void vTaskFSM(void* parameters)
{
	static state currentState = SAFE; // init to safe
	static state nextState;

	QueueHandle_t redlineVoltageQueue = xQueueCreate(REDLINE_VOLTAGE_QUEUE_SIZE, sizeof(double));
	QueueHandle_t redlineCurrentQueue = xQueueCreate(REDLINE_CURRENT_QUEUE_SIZE, sizeof(double));

	QueueHandle_t telemQueue = xQueueCreate(TELEM_QUEUE_SIZE, sizeof(telemPacket));
	QueueHandle_t commandQueue = xQueueCreate(COMMAND_QUEUE_SIZE, sizeof(commandPacket));

	// create and schedule helper tasks
	StaticTask_t telemSenderTCB;
	StackType_t telemSenderStack[TASK_STACK_SIZE];
	xTaskCreateStatic((TaskFunction_t)vTaskTelemSender, "this guy sends telemetry", TASK_STACK_SIZE, telemQueue,
	                  vTaskTelemSenderPriority, telemSenderStack, &telemSenderTCB);

	StaticTask_t commandListenerTCB;
	StackType_t commandListenerStack[TASK_STACK_SIZE];
	xTaskCreateStatic((TaskFunction_t)vTaskFSM, "FSM Manager", TASK_STACK_SIZE, commandQueue, vTaskTelemSenderPriority,
	                  telemSenderStack, &telemSenderTCB);

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
