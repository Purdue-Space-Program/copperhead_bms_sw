#include "task-command.hpp"

static QueueHandle_t listenerQueue;

void sendToCommandListener(command cmd)
{
	if (listenerQueue == nullptr) return;

	commandPacket packet = {
		cmd
	};

	xQueueSend(listenerQueue, &packet);
}

void vTaskCommandRead(QueueHandle_t* commandQueue)
{
	listenerQueue = *commandQueue;

	commandPacket packet;

	for (;;)
	{
		if (xQueueReceive(*commandQueue, &packet, portMAX_DELAY) != pdTRUE) continue;

		switch (packet.cmd)
		{
		case (GOTO_ARMED): {
			// TODO: SAFE -> ARM
			break;
		}

		case (GOTO_RUNNING): {
			// TODO: ARM -> DISCHARGE
			break;
		}

		case (GOTO_CHARGING): {
			// TODO: ARM -> CHARGE
			break;
		}

		case (GOTO_SHUTDOWN): {
			// TODO: FAULT, ARM, CHARGE, DISCHARGE -> SAFE
			break;
		}
		}
	}
}
