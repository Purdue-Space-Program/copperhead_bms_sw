#include "FreeRTOS.h"
#include "queue.h"

struct telemPacket
{
	double busCurrent;
	double busVoltage;
	double cellVoltage[18];
};

void vTaskTelemSender(QueueHandle_t* telemQueue);
