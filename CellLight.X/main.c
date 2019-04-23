#include "xc.h"
#include "config.h"

#include "Debug.h"
#include "LEDControl.h"
#include "CommRouter.h"

int main(void) 
{
    __builtin_write_OSCCONL(OSCCON & 0xBF);
    CommRouter_Setup();
    Debug_Setup();
    LEDControl_Setup();
    __builtin_write_OSCCONL(OSCCON | 0x40);
    
    while(1)
    {
        CommRouter_Background();
        Debug_Background();
    }
    
    return 0;
}
