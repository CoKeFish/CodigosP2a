
#include <xc.h>
#include "ADC_int.h"
#include "mcc_generated_files/adc/adcc.h"
#include "mcc_generated_files/uart/uart1.h"
#include "Practica2a.h"

static uint8_t valp[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void ADC_int(void)
{
    LATDbits.LATD1 = !LATDbits.LATD1;
    //LATDbits.LATD0 = !LATDbits.LATD0;
    if(ADPCH == 0)  //Si hicimos la convercion de la primera muestra
    {
//        LATDbits.LATD0 = !LATDbits.LATD0;
        
        LATEbits.LATE0 = 0;
        
        ADCC_StartConversion(channel_ANA1); //Iniciamos la segunda
        // y Cargamos la lectura al buffer de transmicion
        Timer2_Start();
        SPI1_ByteWrite(0b00110000 | ADRESH);
        SPI1_ByteWrite(ADRESL);

        UART_Write(valp[ADRESH  & 0b1111]);
        UART_Write(valp[(ADRESL >> 4)  & 0b1111]);
        UART_Write(valp[ADRESL  & 0b1111]);
        UART_Write(',');    // y separamos por ","
        
//        __delay_us(35);
//        LATBbits.LATB4 = 0;
//        __delay_us(2);
//        LATBbits.LATB4 = 1;
//        LATEbits.LATE0 = 1;
    
        
    }
    else            //Si es la segunda convercion
    {
        // Cargamos la lectura al buffer de transmicion

        SPI1_ByteWrite(0b10110000 | 0b00001111);
        SPI1_ByteWrite(0b11111111);
        UART_Write(valp[ADRESH  & 0b1111]);
        UART_Write(valp[(ADRESL >> 4)  & 0b1111]);
        UART_Write(valp[ADRESL  & 0b1111]);
//        UART_Write(valp[(PERIOD >> 8)  & 0b1111]);
//        UART_Write(valp[(PERIOD >> 4)  & 0b1111]);
//        UART_Write(valp[PERIOD  & 0b1111]);
        UART_Write('\n');   // y separamos por un salto de linea
    }
}


