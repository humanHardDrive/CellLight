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
    //Setup RP ports
    _RP10R = 21; //UART 4 TX
    _U4RXR = 11; //UART 4 RX
    
    //Setup UART4
    //Generate interrupt when TX buffer is empty
    U4STAbits.UTXISEL0 = 0;
    U4STAbits.UTXISEL1 = 1;
    U4MODEbits.BRGH = 1;
    _U4TXIF = 0;
    _U4RXIF = 0;
    //Enable RX interrupt
    //Wait to enable the TX interrupt
    IEC5bits.U4RXIE = 1;
    U4BRG = 0x14; //115200 buad at 20MHz FOSC
    
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

void Debug_PutChar(char c)
{
    if(txCount < DEBUG_TX_BUFFER_SIZE)
    {
        _U4TXIE = 0;

        if(txCount)
        {
            txBuffer[txBufferIn] = c;
            txBufferIn++;

            if(txBufferIn > DEBUG_TX_BUFFER_SIZE)
                txBufferIn = 0;
        }
        else
            U4TXREG = c;

        txCount++;

        _U4TXIE = 1;
    }
}

unsigned int Debug_CharAvailable()
{
    return rxCount;
}

char Debug_GetChar()
{
    char retVal = 0;
    
    if(rxCount)
    {
        retVal = rxBuffer[rxBufferOut];
        rxBufferOut++;
        
        if(rxBufferOut > DEBUG_RX_BUFFER_SIZE)
            rxBufferOut = 0;
        
        rxCount--;
    }
    
    return retVal;
}

void __attribute__((__interrupt__, auto_psv)) _U4TXInterrupt(void)
{
    txCount--;
    if(txCount)
    {
        U4TXREG = txBuffer[txBufferOut];
        txBufferOut++;
        
        if(txBufferOut > DEBUG_TX_BUFFER_SIZE)
            txBufferOut = 0;
    }
    _U4TXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U4RXInterrupt(void)
{
    rxCount++;
    
    rxBuffer[rxBufferIn] = U4RXREG;
    rxBufferIn++;
    
    if(rxBufferIn > DEBUG_RX_BUFFER_SIZE)
        rxBufferIn = 0;
    
    _U4RXIF = 0;
}