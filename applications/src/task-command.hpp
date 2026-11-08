#include "FreeRTOS.h"
#include "queue.h"
#pragma once

// each command is a commanded transition (orange arrows) on the state diagram
enum command
{
	GOTO_ARMED,
	GOTO_RUNNING, // ARM -> DISCHARGE
	GOTO_CHARGING,
	GOTO_SHUTDOWN
};

// what goes on the command queue
struct commandPacket
{
	command cmd;
};

void vTaskCommandRead(QueueHandle_t* commandQueue);

void sendToCommandListener(command);
