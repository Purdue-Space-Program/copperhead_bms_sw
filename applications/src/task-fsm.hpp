enum state
{
	FAULT,
	SAFE,
	ARM,
	CHARGE,
	DISCHARGE
};

void vTaskFSM(void*);
