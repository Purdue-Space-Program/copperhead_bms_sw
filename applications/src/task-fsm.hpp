enum
{
	FAULT,
	SAFE,
	ARM,
	CHARGE,
	DISCHARGE
} state;

void vTaskFSM(void*);
