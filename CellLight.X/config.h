#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#pragma config PLLDIV = DISABLED
#pragma config POSCMD = HS
#pragma config FNOSC = FRC
#pragma config FCKSM = CSECMD 
#pragma config IESO = ON
    
#pragma config FWDTEN = OFF
    
#pragma config ICS = PGx1
#pragma config JTAGEN = OFF

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

