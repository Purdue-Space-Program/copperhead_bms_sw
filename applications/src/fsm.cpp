#include "fsm.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

void vTaskFSM(QueueHandle_t* commandQueue, QueueHandle_t* redlineQueue)
{
	static state currentState;
	static state nextState;

	for (;;) // FOR... EVER!
	{

		// output based on state
		switch (currentState)
		{

		case (FAULT): {
		}

		case (SAFE): {
		}

		case (ARMED): {
		}

		case (CHARGING): {
		}

		case (DISCHARGING): {
		}

		default: {
			// oh no
			currentState = currentState;
		}
		}

		// compute next state
	}
}

void startFaultRoutine()
{
}

void safeRoutine()
{
}

void armedRoutine()
{
}
