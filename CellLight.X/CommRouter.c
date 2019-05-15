#include "CommRouter.h"

#include <xc.h>

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
}COLOR_CHANGE_MSG;

enum
{
    WAITING_FOR_STX = 0,
    WAITING_FOR_DEPTH,
    WAITING_FOR_PATH_LSB,
    WAITING_FOR_PATH_MSB,
    WAITING_FOR_CMD,
    WAITING_FOR_LENGTH,
    WAITING_FOR_PAYLOAD,
    WAITING_FOR_ETX
};

uint8_t parseState[NUM_UART_PORTS] = {WAITING_FOR_STX, 
                                      WAITING_FOR_STX, 
                                      WAITING_FOR_STX};

static volatile unsigned char txBuffer[NUM_UART_PORTS][COMM_TX_BUFFER_SIZE];
static volatile unsigned char rxBuffer[NUM_UART_PORTS][COMM_RX_BUFFER_SIZE];

#if COMM_TX_BUFFER_SIZE < 256
volatile unsigned char txBufferIn[NUM_UART_PORTS] = {0,0,0};
volatile unsigned char txBufferOut[NUM_UART_PORTS] = {0,0,0};
volatile unsigned char txCount[NUM_UART_PORTS] = {0,0,0};
#else
static volatile unsigned int txBufferIn[NUM_UART_PORTS] = {0,0,0};
static volatile unsigned int txBufferOut[NUM_UART_PORTS] = {0,0,0};
static volatile unsigned int txCount[NUM_UART_PORTS] = {0,0,0};
#endif

#if COMM_RX_BUFFER_SIZE < 256
volatile unsigned char rxBufferIn[NUM_UART_PORTS] = {0,0,0};
volatile unsigned char rxBufferOut[NUM_UART_PORTS] = {0,0,0};
volatile unsigned char rxCount[NUM_UART_PORTS] = {0,0,0};
#else
static volatile unsigned int rxBufferIn[NUM_UART_PORTS] = {0,0,0};
static volatile unsigned int rxBufferOut[NUM_UART_PORTS] = {0,0,0};
static volatile unsigned int rxCount[NUM_UART_PORTS] = {0,0,0};
#endif

volatile uint16_t* TXREG[] = {&U1TXREG, &U2TXREG, &U3TXREG};
volatile uint16_t* RXREG[] = {&U1RXREG, &U2RXREG, &U3RXREG};

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

unsigned int l_Available(unsigned char uart)
{
    if(uart < NUM_UART_PORTS)
        return rxCount[uart];
    
    return 0;
}

void l_Write(unsigned char uart, unsigned char c)
{
    if(uart < NUM_UART_PORTS)
        *TXREG[uart] = c;
}

void l_CycMemCpy(void* dst, void* src, unsigned int srcStart,
                 unsigned int srcLen, unsigned int cpyLen)
{
    unsigned int count = 0;
    
    while(count < cpyLen)
    {
        *((uint8_t*)dst) = *((uint8_t*)src + srcStart);
        
        dst++;
        srcStart++;
        if(srcStart >= srcLen)
            srcStart = 0;
        
        count++;
    }
}

void l_ParseByte(unsigned char uart, unsigned char b)
{
    switch(parseState[uart])
    {
        case WAITING_FOR_STX:
            if(b == MSG_STX)
            {
                parseState[uart] = WAITING_FOR_DEPTH;
            }
            break;
            
        case WAITING_FOR_DEPTH:
            parseState[uart] = WAITING_FOR_PATH_LSB;
            break;
            
        case WAITING_FOR_PATH_LSB:
            break;            
            
        case WAITING_FOR_PATH_MSB:
            break;
            
        case WAITING_FOR_CMD:
            break;
            
        case WAITING_FOR_LENGTH:
            break;
            
        case WAITING_FOR_PAYLOAD:
            break;
            
        case WAITING_FOR_ETX:
            if(b == MSG_ETX)
                parseState[uart] = WAITING_FOR_STX;
            break;
    }
}

void CommRouter_Background()
{
}

inline void l_TXUpdate(unsigned char uart)
{    
    txCount[uart]--;
    if(txCount[uart])
    {
        U1TXREG = txBuffer[uart][txBufferOut[uart]];
        txBufferOut[uart]++;
        
        if(txBufferOut[uart] >= COMM_TX_BUFFER_SIZE)
            txBufferOut[uart] = 0;
    }
}

inline void l_RXUpdate(unsigned char uart)
{
    rxCount[uart]++;
    
    rxBuffer[uart][rxBufferIn[uart]] = *RXREG[uart];
    rxBufferIn[uart]++;
    
    if(rxBufferIn[uart] >= COMM_RX_BUFFER_SIZE)
        rxBufferIn[uart] = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U1TXInterrupt(void)
{
    l_TXUpdate(0);
    _U1TXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U1RXInterrupt(void)
{
    l_RXUpdate(0);
    _U1RXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U2TXInterrupt(void)
{
    l_TXUpdate(1);
    _U2TXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U2RXInterrupt(void)
{
    l_RXUpdate(1);
    _U2RXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U3TXInterrupt(void)
{
    l_TXUpdate(2);
    _U3TXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U3RXInterrupt(void)
{
    l_RXUpdate(2);
    _U3RXIF = 0;
}