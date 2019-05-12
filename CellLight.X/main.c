#include "xc.h"
#include "config.h"

#include "Debug.h"
#include "LEDControl.h"
#include "CommRouter.h"

void ClockSetup()
{
    REFOCONLbits.ROEN = 1;
    REFOCONLbits.ROOUT = 1;
    
    __builtin_write_OSCCONH(0x02);
    __builtin_write_OSCCONL(OSCCON | 0x01);
    
    while(OSCCONbits.COSC != 0x02);
}

int main(void) 
{
    ClockSetup();
    
    __builtin_write_OSCCONL(OSCCON & 0xBF);
    CommRouter_Setup();
    Debug_Setup();
    //LEDControl_Setup();
    __builtin_write_OSCCONL(OSCCON | 0x40);
    
    while(1)
    {
        CommRouter_Background();
        Debug_Background();
    }
    
    return 0;
}
