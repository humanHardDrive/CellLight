#ifndef _MSGS_H_
#define _MSGS_H_

#define MAX_PAYLOAD_SIZE  128

typedef struct
{
  uint8_t msgType;
  uint8_t msgLen;
  uint8_t msgID;
  uint8_t checksum;

  uint8_t payload[MAX_PAYLOAD_SIZE];
}MSG_t;

enum
{
  NO_MSG = 0,
  CONFIGURE_PORT_MSG,
  ADDRESS_CELL_MSG
};

enum
{
  PORT_DISCONNECTED = 0,
  PORT_INPUT,
  PORT_OUTPUT,
  ALL_PORT_STATUS
};

typedef struct
{
  uint8_t offset;
  uint8_t portStatus;
}CONFIGURE_PORT_MSG_t;

typedef struct
{
  uint8_t address;
}ADDRESS_CELL_MSG_t;

#endif
