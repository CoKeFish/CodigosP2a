
#include "mcc_generated_files/uart/uart1.h"
#include "Practica2a.h"

void UART_TX_int(void)
{
    
}

void UART_RX_int(void)
{
    static unsigned char status = 0;
    static uint8_t opcode = 0;
    static uint16_t mesage = 0;
    
    if(status == 0)
    {
        status++;
        opcode = UART_Read();
    }
    else if(status == 1)
    {
        status++;
        mesage = UART_Read();
    }
    else if(status == 2)
    {
        status = 0;
        mesage = (mesage << 8) + UART_Read();
        if(opcode == 1)
        {
            PERIOD = mesage;
        }
    }
     
}