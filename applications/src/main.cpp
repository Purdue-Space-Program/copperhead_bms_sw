// freeRTOS includes
#include "FreeRTOS.h"
#include "task.h"
// task includes
#include "bms.h"
#include "portmacro.h"
#include "uart.h"

// #include <chrono>

#define BOARD_ID 0 // valid ids: 0-3

/* Stack sized for the STM32C031's 12 KB SRAM */
#define TASK_STACK_SIZE 512

uint8_t commandBuff[64] = {0};
uint8_t telemBuff[64] = {0};

commandPacket currentCommand;
telemPacket currentTelem;

int main(void)
{
    StackType_t task_stack[TASK_STACK_SIZE] = {0};
    StaticTask_t idk_bruh = {0};

    vTaskStartScheduler(); // starts scheduler

    while (true)
    {
    }
}
