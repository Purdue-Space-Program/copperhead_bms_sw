#include "task-fsm.hpp" //this is where states are defined
#include "FreeRTOS.h"
#include "bus-driver.hpp" //functions to control bus connection
#include "constants.hpp"
#include "queue.h"
#include "task-telem.hpp"
#include "task.h"
#include <optional>

// the routines we run in each state
void faultRoutine(void);
void safeRoutine(void);
void armRoutine(void);
void chargeRoutine(void);
void dischargeRoutine(void);

// functions to help determine the next state
std::optional dequeueCommand(QueueHandle_t commandQueue);
bool redlineCheck(QueueHandle_t voltageQueue, QueueHandle_t currentQueue);

// the fsm task
void vTaskFSM(void* parameters)
{
	static state currentState = SAFE; // init to safe
	static state nextState;

	QueueHandle_t redlineVoltageQueue = xQueueCreate(REDLINE_QUEUE_SIZE, sizeof(double));
	QueueHandle_t redlineCurrentQueue = xQueueCreate(REDLINE_QUEUE_SIZE, sizeof(double));

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
			faultRoutine();
			break;
		}

		case (SAFE): {
			safeRoutine();
			break;
		}

		case (ARM): {
			armRoutine();
			break;
		}

		case (CHARGE): {
			chargeRoutine();
			break;
		}

		case (DISCHARGE): {
			dischargeRoutine();
			break;
		}

		default: {
			// oh no
			nextState = FAULT;
		}
		}

		// === compute next state ===
		if (redlineCheck(redlineVoltageQueue, redlineVoltageQueue))
		{
			nextState = FAULT;
		}
	}
}

void faultRoutine(void)
{
	disconnectFromBus();
}

void safeRoutine(void)
{
	disconnectFromBus();
}

void armRoutine(void)
{
	disconnectFromBus();
}

void chargeRoutine(void)
{
	connectToBus();
}

void dischargeRoutine(void)
{
	connectToBus();
}

std::optional dequeueCommand(QueueHandle_t commandQueue)
{
	commandPacket newCommand;
	xQueueReceive(commandQueue, &newCommand, 25);

	if (newCommand == nullptr || badthing == true)
	{
		return std::optional<commandPacket>{newCommand};
	}
	return std::nullopt;
}

bool redlineCheck(QueueHandle_t voltageQueue, QueueHandle_t currentQueue)
{
	// feels like there might be a better way to do this?
	double voltAvgBuff;
	double currentAvgBuff;

	double voltAvg = 0.0;
	double currentAvg = 0.0;

	for (int i = 0; i < REDLINE_QUEUE_SIZE; i++)
	{
		xQueuePeek(voltageQueue, &voltAvgBuff, 0);
		xQueuePeek(currentQueue, &currentAvgBuff, 0);

		voltAvg += voltAvgBuff;
		currentAvg += currentAvgBuff;
	}

	voltAvg /= REDLINE_QUEUE_SIZE;
	currentAvg /= REDLINE_QUEUE_SIZE;

	// returns true if either redline has been hit
	return (voltAvg > REDLINE_VOLTAGE_LIMIT || currentAvg > REDLINE_CURRENT_LIMIT);
}
