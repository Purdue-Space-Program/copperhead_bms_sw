#include "task-fsm.hpp" //this is where states are defined
#include "FreeRTOS.h"
#include "constants.hpp"
#include "queue.h"
#include "stm32c0xx_hal_exti.h"
#include "task-telem.hpp"
#include "task.h"

int redlineCheck(QueueHandle_t* voltageQueue, QueueHandle_t* currentQueue);

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
		if (redlineCheck(redlineVoltageQueue, redlineVoltageQueue))
		{
			nextState = FAULT;
		}
	}
}

int redlineCheck(QueueHandle_t* voltageQueue, QueueHandle_t* currentQueue)
{
	double voltAvg = 0.0;
	double currentAvg = 0.0;

	for (int i = 0; i < REDLINE_VOLTAGE_QUEUE_SIZE; i++)
	{
		currentAvg += currentQueue[i];
		voltAvg += voltageQueue[i];
	}

	if (voltAvg > REDLINE_VOLTAGE_LIMIT || currentAvg > REDLINE_CURRENT_LIMIT)
	{
		return 1;
	}
	return 0;
}
