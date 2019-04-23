#include "LEDControl.h"

#include <xc.h>

uint16_t ColorBuffer[24];
volatile unsigned char isWriting = 0;

void l_Timer2Setup()
{
}

void l_DMASetup()
{
}

void LEDControl_Setup()
{
    l_Timer2Setup();
    l_DMASetup();
}

void LEDControl_WriteColor(_GRB color)
{
    if(!isWriting)
    {
        isWriting = 1;
    }
}

void __attribute__((__interrupt__, auto_psv)) _DMA0Interrupt(void)
{
    isWriting = 0;
}