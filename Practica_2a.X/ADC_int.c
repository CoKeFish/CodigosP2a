
#include <xc.h>
#include "ADC_int.h"
#include "mcc_generated_files/adc/adcc.h"
#include "mcc_generated_files/uart/uart1.h"
#include "Practica2a.h"
#include "FIR.h"
#include "IIR.h"

static uint8_t char_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void ADC_int(void)
{
    
    if(ADPCH == 0)  //Si hicimos la convercion de la primera muestra
    {

        LATEbits.LATE0 = 0;     // CS
        
        ADCC_StartConversion(channel_ANA0); //Iniciamos la segunda
        // y Cargamos la lectura a los buffers de transmicion(UART, SPI)
        
        Timer2_Start(); //Maneja el tiempo de CS
        SPI1_ByteWrite(0b00110000 | ADRESH);
        SPI1_ByteWrite(ADRESL);

        //Transmicion UART
        UART_Write(char_hex[ADRESH  & 0b1111]);
        UART_Write(char_hex[(ADRESL >> 4)  & 0b1111]);
        UART_Write(char_hex[ADRESL  & 0b1111]);
        UART_Write(',');    // y separamos por ","
        
    }
    else            //Si es la segunda convercion
    {
        // Cargamos la lectura al buffer de transmicion
        
        int result = FilterFIR((ADRESH << 8) + ADRESL);
        LATEbits.LATE0 = 0;     // CS
        
        Timer2_Start(); //Maneja el tiempo de CS
        
        SPI1_ByteWrite(0b10110000 | (result >> 8));
        SPI1_ByteWrite(result & 0b11111111);
        
        //Transmicion UART
        UART_Write(char_hex[(result >> 8)  & 0b1111]);
        UART_Write(char_hex[(result >> 4)  & 0b1111]);
        UART_Write(char_hex[result  & 0b1111]);

        UART_Write('\n');   // y separamos por un salto de linea
    }
}