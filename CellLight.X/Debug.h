#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DEBUG_TX_BUFFER_SIZE    128
#define DEBUG_RX_BUFFER_SIZE    128
    
void Debug_Setup();

void Debug_Background();

void Debug_PutChar(char c);
void Debug_PutStr(char* str, unsigned char length);

unsigned int Debug_CharAvailable();
char Debug_GetChar();

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

