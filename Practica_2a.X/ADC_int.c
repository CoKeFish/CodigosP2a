
#include <xc.h>
#include "ADC_int.h"
#include "mcc_generated_files/adc/adcc.h"
#include "mcc_generated_files/uart/uart1.h"


void ADC_int(void)
{
    LATDbits.LATD0 = !LATDbits.LATD0;
    if(ADPCH == 0)  //Si hicimos la convercion de la primera muestra
    {
        ADCC_StartConversion(channel_ANA1); //Iniciamos la segunda
        // y Cargamos la lectura al buffer de transmicion
        UART_Write(9);
        UART_Write(8);
        UART_Write(',');    // y separamos por ","
    }
    else            //Si es la segunda convercion
    {
        // Cargamos la lectura al buffer de transmicion
        UART_Write(7);
        UART_Write(6);
        UART_Write('\n');   // y separamos por un salto de linea
    }
}


