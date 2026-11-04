#include "task-command.hpp"

void sendToCommandListener(command cmd)
{
	
	commandPacket packet = {
		cmd
	};
	//send to queue or something
}

void vTaskCommandRead(QueueHandle_t* commandQueue)
{
	listenerQueue = *commandQueue;

	commandPacket packet;

	for (;;)
	{
		//if queue recieves command continue

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
