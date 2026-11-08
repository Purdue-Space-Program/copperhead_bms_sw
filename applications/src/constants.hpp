// SOFTWARE CONSTANTS
#define TASK_STACK_SIZE 512

#define COMMAND_QUEUE_SIZE 64
#define TELEM_QUEUE_SIZE 64

#define REDLINE_QUEUE_SIZE 32

#define REDLINE_VOLTAGE_LIMIT 80
#define REDLINE_CURRENT_LIMIT 80

#define vTaskFSMPriority 10
#define vTaskTelemSenderPriority 10
#define vTaskCommandListenerPriority 10

// HARDWARE CONSTANTS

// uart
#define MCU_UART_DE 27
#define MCU_UART_TX 30
#define MCU_UART_RX 31

// mcu-bmu spi lines
#define MCU_BMS_SCK 12
#define MCU_BMS_MISO 13
#define MSU_BMS_MOSI 14

// switch io
#define BUS_SWITCH_INPUT_1 19
#define BUS_SWITCH_INPUT_2 21
#define BUS_SWITCH_CURRENT 18
