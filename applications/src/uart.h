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

commandPacket uartWrite();
telemPacket uartRead();
