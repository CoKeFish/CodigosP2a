
#include <xc.h>
#include "ADC_int.h"
#include "mcc_generated_files/adc/adcc.h"
#include "mcc_generated_files/uart/uart1.h"


void ADC_int(void)
{
    //LATDbits.LATD0 = !LATDbits.LATD0;
    if(ADPCH == 0)  //Si hicimos la convercion de la primera muestra
    {
        LATDbits.LATD0 = !LATDbits.LATD0;
        
        LATEbits.LATE0 = 0;
        ADCC_StartConversion(channel_ANA1); //Iniciamos la segunda
        // y Cargamos la lectura al buffer de transmicion
        SPI1_ByteWrite(0b00111111);
        SPI1_ByteWrite(0b11111111);
        
        __delay_us(35);
        LATBbits.LATB4 = 0;
        __delay_us(2);
        LATBbits.LATB4 = 1;
        LATEbits.LATE0 = 1;
    
        UART_Write('A');
        UART_Write('B');
        UART_Write('C');
        UART_Write(',');    // y separamos por ","
    }
    else            //Si es la segunda convercion
    {
        
        LATDbits.LATD1 = !LATDbits.LATD1;
        // Cargamos la lectura al buffer de transmicion
        UART_Write('D');
        UART_Write('E');
        UART_Write('F');
        UART_Write('\n');   // y separamos por un salto de linea
    }
}


