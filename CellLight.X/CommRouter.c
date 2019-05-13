#include "CommRouter.h"

#include <xc.h>

void l_UART1Setup()
{
    //Setup RP ports
    _RP6R = 3;  //UART 1 TX
    _U1RXR = 7; //UART 1 RX
    
    //Setup UART1
    //Generate interrupt when TX buffer is empty
    U1STAbits.UTXISEL0 = 0;
    U1STAbits.UTXISEL1 = 1;
    U1MODEbits.BRGH = 1;
    //Clear the interrupt flags
    _U1TXIF = 0;
    _U1RXIF = 0;
    //Enable RX interrupt
    //Wait to enable the TX interrupt
    _U1RXIE = 1;
    U1BRG = 0x14; //115200 buad at 20MHz FOSC
    
    U1MODEbits.UARTEN = 1; //Enable UART
    U1STAbits.UTXEN = 1; //Enable TX
}

void l_UART2Setup()
{
    //Setup RP ports
    _RP8R = 5;  //UART 2 TX
    _U2RXR = 9; //UART 2 RX
    
    //Setup UART1
    //Generate interrupt when TX buffer is empty
    U2STAbits.UTXISEL0 = 0;
    U2STAbits.UTXISEL1 = 1;
    U2MODEbits.BRGH = 1;
    //Clear the interrupt flags
    _U2TXIF = 0;
    _U2RXIF = 0;
    //Enable RX interrupt
    //Wait to enable the TX interrupt
    _U2RXIE = 1;
    U2BRG = 0x14; //115200 buad at 20MHz FOSC
    
    U2MODEbits.UARTEN = 1; //Enable UART
    U2STAbits.UTXEN = 1; //Enable TX
}

void l_UART3Setup()
{
    //Setup RP ports
    _RP13R = 19; //UART 3 TX
    _U3RXR = 14; //UART 3 RX
    
    //Setup UART1
    //Generate interrupt when TX buffer is empty
    U3STAbits.UTXISEL0 = 0;
    U3STAbits.UTXISEL1 = 1;
    U3MODEbits.BRGH = 1;
    //Clear the interrupt flags
    _U3TXIF = 0;
    _U3RXIF = 0;
    //Enable RX interrupt
    //Wait to enable the TX interrupt
    _U3RXIE = 1;
    U3BRG = 0x14; //115200 buad at 20MHz FOSC
    
    U3MODEbits.UARTEN = 1; //Enable UART
    U3STAbits.UTXEN = 1; //Enable TX    
}

void CommRouter_Setup()
{
    l_UART1Setup();
    l_UART2Setup();
    l_UART3Setup();
}

void CommRouter_Background()
{
}

void __attribute__((__interrupt__, auto_psv)) _U1TXInterrupt(void)
{
    _U1TXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U1RXInterrupt(void)
{
    _U1RXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U2TXInterrupt(void)
{
    _U2TXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U2RXInterrupt(void)
{
    _U2RXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U3TXInterrupt(void)
{
    _U3TXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U3RXInterrupt(void)
{
    _U3RXIF = 0;
}