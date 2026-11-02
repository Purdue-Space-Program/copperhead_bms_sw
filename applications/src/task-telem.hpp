#include "FreeRTOS.h"
#include "queue.h"
#include <stm32c0xx_hal_uart.h>

class uartComms
{
  private:
	UART_HandleTypeDef handle;
	QueueHandle_t commandQueue;
	QueueHandle_t telemQueue;
	int linkUp = 0;

  public:
	// clang-format off
	void setHandle(UART_HandleTypeDef _handle){handle = _handle;}
  UART_HandleTypeDef getHandle(void){return this->handle;}

	// clang-format on

	int sendTelem(void);
	int readCommand(void);
};

void vTaskTelemSender(void*);
