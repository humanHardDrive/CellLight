#ifndef COMMROUTER_H
#define	COMMROUTER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MSG_STX     0x55
#define MSG_ETX     0xAA
    
#define BROADCAST_DEPTH     0xFF
    
#define MSG_START   0x00
#define MSG_DEPTH   (MSG_START + 0x00)
#define MSG_PATH    (MSG_START + 0x01)
#define MSG_CMD     (MSG_START + 0x03)
#define MSG_LEN     (MSG_START + 0x04)
#define MSG_PAYLOAD (MSG_START + 0x05)
    
#define CMD_BASE    0x00
#define CMD_COLOR   (CMD_BASE + 0x01)
    
void CommRouter_Setup();

void CommRouter_Background();

#ifdef	__cplusplus
}
#endif

#endif	/* COMMROUTER_H */

