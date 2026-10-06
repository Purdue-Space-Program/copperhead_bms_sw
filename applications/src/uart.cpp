#include "stm32c0xx_hal_dma.h"
#include "stm32c0xx_hal_uart.h"

UART_HandleTypeDef huart1;
DMA_HandleTypeDef dma_uart_rx;

// start listening
void readUartTask(void *argument)
{

    HAL_UART_Receive_DMA(&huart1, commandBuff, 64);
}

// start processing commandBuff --> commandPacket
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
}
