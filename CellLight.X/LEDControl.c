#include "LEDControl.h"

#include <xc.h>

uint16_t ColorBuffer[24];
volatile unsigned char isWriting = 0;

void l_Timer2Setup()
{
    _RP5R = 13; //Output compare 1 module
    OC1CON1bits.OCM = 0;
    OC1R = 0;
    OC1RS = 11;
    OC1CON1bits.OCTSEL = 0; //Use timer2 as clock source
    OC1CON1bits.OCM = 6; //Edge aligned PWM
    
    T2CONbits.TON = 0; //Disable timer
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    T2CONbits.TCKPS = 0; //1:1 prescalar
    PR2 = 11;
    TMR2 = 0; //Reset the clock
}

void l_DMASetup()
{
    DMACONbits.DMAEN = 1; //Enable the DMA
    
    DMACH0bits.SAMODE = 0b01; //Source address increments
    DMACH0bits.DAMODE = 0b00; //Destination address is constant
    DMACH0bits.TRMODE = 1; //Repeated one-shot
    DMACH0bits.RELOAD = 1; //Reset counts at end of transfer
    DMACH0bits.SIZE = 0; //Word size
    
    DMAINT0bits.CHSEL = 0b110101; //Timer 2 interrupt
    
    DMAL = (volatile unsigned int)&ColorBuffer[0];
    DMAH = ((volatile unsigned int)&ColorBuffer[0]) + 50;
    
    DMASRC0 = (volatile unsigned int)&ColorBuffer[0];
    DMADST0 = (volatile unsigned int)&OC1R;
    DMACNT0 = 24; //24 word transfer size
    
    _DMA0IF = 0; //Clear flag
    _DMA0IE = 1; //Enable channel 0 interrupt
    DMACH0bits.CHEN = 1; //Enable channel 0
}

void LEDControl_Setup()
{
    l_Timer2Setup();
    l_DMASetup(); 
}

void LEDControl_WriteColor(_GRB color)
{
    unsigned char i;
    uint32_t mask = 0x800000;
    OC1CON1bits.OCM = 0;
    
    if(!isWriting)
    {
        for(i = 0; i < 24; i++)
        {
            uint16_t v;
            if(color.combined & mask)
                v = 7;
            else
                v = 3;
            
            mask >>= 1;
            
            if(i == 0)
                OC1R = v;
            else
                ColorBuffer[i - 1] = v;
        }
        
        ColorBuffer[23] = 0;
        OC1CON1bits.OCM = 6;
        
        isWriting = 1; //Block any additional writes while DMA works
        TMR2 = 0;
        T2CONbits.TON = 1; //Start the timer
    }
}

void __attribute__((__interrupt__, auto_psv)) _DMA0Interrupt(void)
{
    isWriting = 0; //Clear write block flag
    T2CONbits.TON = 0; //Disable the timer
    _DMA0IF = 0; //Clear DMA interrupt the flag
}