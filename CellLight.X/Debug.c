#include "Debug.h"

#include <xc.h>

volatile unsigned char txBuffer[DEBUG_TX_BUFFER_SIZE];
volatile unsigned char rxBuffer[DEBUG_RX_BUFFER_SIZE];

#if DEBUG_TX_BUFFER_SIZE < 256
unsigned char txBufferIn = 0, txBufferOut = 0, txCount = 0;
#else
unsigned int txBufferIn = 0, txBufferOut = 0, txCount = 0;
#endif

#if DEBUG_RX_BUFFER_SIZE < 256
unsigned char rxBufferIn = 0, rxBufferOut = 0, rxCount = 0;
#else
unsigned int rxBufferIn = 0, rxBufferOut = 0, rxCount = 0;
#endif

void l_UARTSetup()
{
    U1BRG = 23; //RECALCULATE
    
    U4STAbits.UTXISEL0 = 0;
    U4STAbits.UTXISEL1 = 1;
    IEC5bits.U4TXIE = 1;
    IEC5bits.U4RXIE = 1;
    
    U4MODEbits.UARTEN = 1; //Enable UART
    U4STAbits.UTXEN = 1; //Enable TX
}

void Debug_Setup()
{
    l_UARTSetup();
}

void Debug_Background()
{
}

void __attribute__((__interrupt__, auto_psv)) _U4TXInterrupt(void)
{
}

void __attribute__((__interrupt__, auto_psv)) _U4RXInterrupt(void)
{
}