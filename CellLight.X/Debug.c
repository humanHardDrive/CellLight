#include "Debug.h"
#include "LEDControl.h"

#include <xc.h>
#include <stdlib.h>

volatile unsigned char txBuffer[DEBUG_TX_BUFFER_SIZE];
volatile unsigned char rxBuffer[DEBUG_RX_BUFFER_SIZE];

#if DEBUG_TX_BUFFER_SIZE < 256
volatile unsigned char txBufferIn = 0, txBufferOut = 0, txCount = 0;
#else
volatile unsigned int txBufferIn = 0, txBufferOut = 0, txCount = 0;
#endif

#if DEBUG_RX_BUFFER_SIZE < 256
volatile unsigned char rxBufferIn = 0, rxBufferOut = 0, rxCount = 0;
#else
volatile unsigned int rxBufferIn = 0, rxBufferOut = 0, rxCount = 0;
#endif

void l_Unimplemented();

//Main menu prototypes
void l_ChangeToColorMenu();

//Color menu prototypes
void l_TurnOff();
void l_SetColor();
void l_CycleColor();

typedef struct
{
    char* name;
    char key;
    void (*fn)(void);
}MENU_OPTION;

typedef struct
{
    char* name;
    MENU_OPTION* optionList;
}MENU;

typedef enum
{
    MAIN_MENU = 0,
    COLOR_MENU,
    ALL_MENUS
}MENU_ENUM;

unsigned char l_MenuStack[16];
unsigned char l_MenuStackPointer = 0;

MENU_OPTION l_MainMenuOptions[] = 
{
    {"Color Control", '1', l_ChangeToColorMenu},
    {"\0", '\0', 0}
};

MENU_OPTION l_ColorMenuOptions[] = 
{
    {"Turn Off", '1', l_TurnOff},
    {"Set Color", '2', l_SetColor},
    {"Cycle Color", '3', l_CycleColor},
    {"\0", '\0', 0}
};

MENU l_MainMenu = {"MAIN MENU", l_MainMenuOptions};
MENU l_ColorMenu = {"COLOR CONTROL", l_ColorMenuOptions};

MENU *l_MenuList[] = 
{
    &l_MainMenu,
    &l_ColorMenu
};

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
    //Clear the interrupt flags
    _U4TXIF = 0;
    _U4RXIF = 0;
    //Enable RX interrupt
    //Wait to enable the TX interrupt
    IEC5bits.U4RXIE = 1;
    U4BRG = 0x14; //115200 buad at 20MHz FOSC
    
    U4MODEbits.UARTEN = 1; //Enable UART
    U4STAbits.UTXEN = 1; //Enable TX
}

void l_ClearScreen()
{
    char escSeq[] = {0x1B, '[', '2', 'J', '\0'};
    Debug_PutStr(escSeq);
}

void l_CursorHome()
{
    char escSeq[] = {0x1B, '[', 'H', '\0'};
    Debug_PutStr(escSeq);
}

unsigned char l_GetString(char* str, unsigned char maxLength)
{
    char done = 0;
    unsigned char count = 0;
    
    while(!done && count < (maxLength - 1))
    {
        if(Debug_CharAvailable())
        {
            char c = Debug_GetChar();
            
            if(c == 0x0D)
                done = 1;
            else
            {
                //Echo the character back
                Debug_PutChar(c);
                
                //Append the character
                *str = c;
                str++;
                count++;
            }
        }
    }
    
    //Add the null terminator
    *str = '\0';
    return count;
}

void l_ShowMenu(unsigned char menu)
{
    MENU* m = l_MenuList[menu];
    MENU_OPTION* option = m->optionList;
    
    Debug_PutStr(m->name);
    Debug_PutStr("\r\n\n");
    
    while(option->key)
    {
        Debug_PutChar(option->key);
        Debug_PutStr(". ");
        Debug_PutStr(option->name);
        Debug_PutStr("\r\n");
        option++;
    }
}

void l_ExecOption(unsigned char menu, char key)
{
    MENU* m = l_MenuList[menu];
    MENU_OPTION* option = m->optionList;
    
    while(option->key)
    {
        if(option->key == key)
        {
            if(option->fn)
                option->fn();

            return;
        }
        option++;
    }
}

void l_ChangeMenu(unsigned char menu)
{
    l_MenuStackPointer++;
    l_MenuStack[l_MenuStackPointer] = menu;
}

void l_UpMenu()
{
    if(l_MenuStackPointer > 0)
        l_MenuStackPointer--;
}

void Debug_Setup()
{
    l_UARTSetup();
    
    l_ClearScreen();
    l_CursorHome();
    
    Debug_PutStr("RESET\r\n");
}

void Debug_Background()
{
    if(Debug_CharAvailable())
    {
        char c = Debug_GetChar();
        if(c == 0x0D)
        {
            l_ClearScreen();
            l_CursorHome();
            l_ShowMenu(l_MenuStack[l_MenuStackPointer]);
        }
        else if(c == 0x1B)
        {
            l_ClearScreen();
            l_CursorHome();
            l_UpMenu();
            l_ShowMenu(l_MenuStack[l_MenuStackPointer]);
        }
        else
            l_ExecOption(l_MenuStack[l_MenuStackPointer], c);
    }
}

void Debug_PutChar(char c)
{
    if(txCount < DEBUG_TX_BUFFER_SIZE)
    {
        unsigned char intState = _U4TXIE;
        
        _U4TXIE = 0;

        if(txCount)
        {
            txBuffer[txBufferIn] = c;
            txBufferIn++;

            if(txBufferIn >= DEBUG_TX_BUFFER_SIZE)
                txBufferIn = 0;
        }
        else
        {
            U4TXREG = c;
            intState = 1;
        }

        txCount++;

        _U4TXIE = intState;
    }
}

void Debug_PutStr(char* str)
{
    _U4TXIE = 0;
    while(txCount < DEBUG_TX_BUFFER_SIZE && *str)
    {
        Debug_PutChar(*str);
        str++;
    }
     _U4TXIE = 1;
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
        
        if(rxBufferOut >= DEBUG_RX_BUFFER_SIZE)
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
        
        if(txBufferOut >= DEBUG_TX_BUFFER_SIZE)
            txBufferOut = 0;
    }
    _U4TXIF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _U4RXInterrupt(void)
{
    rxCount++;
    
    rxBuffer[rxBufferIn] = U4RXREG;
    rxBufferIn++;
    
    if(rxBufferIn >= DEBUG_RX_BUFFER_SIZE)
        rxBufferIn = 0;
    
    _U4RXIF = 0;
}

//Menu Functions
void l_Unimplemented()
{
    Debug_PutStr("UNIMPLEMENTED\r\n");
}

//Main menu functions
void l_ChangeToColorMenu()
{
    l_ChangeMenu(COLOR_MENU);
    
    l_ClearScreen();
    l_CursorHome();
    l_ShowMenu(l_MenuStack[l_MenuStackPointer]);    
}

//Color menu functions
void l_TurnOff()
{
    _GRB color;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    
    LEDControl_WriteColor(color);
}

void l_SetColor()
{
    char buffer[16];
    int val;
    _GRB color;
    
    Debug_PutStr("Red: ");
    l_GetString(buffer, 16);
    val = atoi(buffer);
    if(val >= 0 && val <= 0xFF)
        color.r = (uint8_t)val;
    else
    {
        Debug_PutStr("Invalid value\r\n");
        return;
    }
    Debug_PutStr("\r\n");
    
    Debug_PutStr("Green: ");
    l_GetString(buffer, 16);
    val = atoi(buffer);
    if(val >= 0 && val <= 0xFF)
        color.g = (uint8_t)val;
    else
    {
        Debug_PutStr("Invalid value\r\n");
        return;
    }
    Debug_PutStr("\r\n");
    
    Debug_PutStr("Blue: ");
    l_GetString(buffer, 16);
    val = atoi(buffer);
    if(val >= 0 && val <= 0xFF)
        color.b = (uint8_t)val;
    else
    {
        Debug_PutStr("Invalid value\r\n");
        return;
    }
    Debug_PutStr("\r\n");
    
    LEDControl_WriteColor(color);
}

void l_CycleColor()
{
    uint64_t count = 0;
    _GRB color;
    color.combined = 0;
    
    while(!Debug_GetChar())
    {
        LEDControl_WriteColor(color);
        
        while(count < 10000)
            count++;
        count = 0;
        
        color.combined++;
        if(color.combined > 0xFFFFFF)
            color.combined = 0;
    }
}