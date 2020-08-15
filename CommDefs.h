#ifndef COMMDEFS_H
#define	COMMDEFS_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define SERIAL_STX  0xAA
#define SERIAL_ETX  0x55

typedef struct CommHeader
{
    uint8_t dst;
    uint8_t src;
    uint8_t command;
    uint8_t len;
};

#ifdef	__cplusplus
}
#endif

#endif	/* COMMDEFS_H */

