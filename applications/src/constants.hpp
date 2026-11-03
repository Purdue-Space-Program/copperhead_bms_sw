#define TASK_STACK_SIZE 512

#define COMMAND_QUEUE_SIZE 64
#define TELEM_QUEUE_SIZE 64

#define REDLINE_VOLTAGE_QUEUE_SIZE 32
#define REDLINE_CURRENT_QUEUE_SIZE 32

#define REDLINE_VOLTAGE_LIMIT 80
#define REDLINE_CURRENT_LIMIT 80

#define vTaskFSMPriority 10
#define vTaskTelemSenderPriority 10
#define vTaskCommandListenerPriority 10
