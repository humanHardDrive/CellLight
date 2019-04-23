#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DEBUG_TX_BUFFER_SIZE    128
#define DEBUG_RX_BUFFER_SIZE    128
    
void Debug_Setup();

void Debug_Background();

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

