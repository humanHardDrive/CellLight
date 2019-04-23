#ifndef LEDCONTROL_H
#define	LEDCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    
typedef union
{
    struct
    {
        uint8_t b;
        uint8_t r;
        uint8_t g;
    };
    uint32_t combined;
}_GRB;
    
void LEDControl_Setup();

void LEDCOntrol_WriteColor(_GRB color);

#ifdef	__cplusplus
}
#endif

#endif	/* LEDCONTROL_H */

