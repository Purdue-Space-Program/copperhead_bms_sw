#include "FreeRTOS.h"
#include "portmacro.h"
#include "task.h"

#include <stdbool.h>
#include <stdio.h>

// #include <chrono>

#define BOARD_ID 0 // valid ids: 0-3

typedef struct
{
    int destID;
    int connect_bus;
    int disconnect_bus;
} commandPacket;

typedef struct
{
    float SOC[18];
    float bus_voltage; // actually just coming from the BMS ic
    float bus_current;
    int bus_connected;
    int internal_state; // state machine telemetry?
} telemPacket;

// removed to see ram change idk void PrintTask(void *argument);
void readUartTask(void *argument);

/* Stack sized for the STM32C031's 12 KB SRAM */
#define TASK_STACK_SIZE 512

int main(void)
{
    StackType_t task_stack[TASK_STACK_SIZE] = {0};
    StaticTask_t idk_bruh = {0};
    //    xTaskCreateStatic(PrintTask, "Print", TASK_STACK_SIZE, NULL, 1, task_stack, &idk_bruh);
    xTaskCreateStatic(readUartTask, "read UART", TASK_STACK_SIZE, NULL, 1, task_stack, &idk_bruh);

    vTaskStartScheduler(); // starts scheduler

    while (true)
    {
    }
}

void readUartTask(void *argument)
{
}

/* PrintTask: prints a message every 1000 ms */

/*
void PrintTask(void *argument)
{
    (void)argument;
    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000));

        auto time = static_cast<long long>(std::chrono::system_clock::now().time_since_epoch().count());
        printf("[%lld] Hello world!\n", time);
    }
}
*/
