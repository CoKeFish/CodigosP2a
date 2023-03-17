 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "Practica2a.h"

#include <stdbool.h>

/*
    Main application
*/

int main(void)
{
    //Inicializamos pines, perifericos y interrupciones
    SYSTEM_Initialize();
    SPI1_Open();
    
    //Usamos punteros a funciones para manejar algunos procesos
    //Las siguientes interfaces almacenan el valor
    ADCC_SetADIInterruptHandler(ADC_int);
    Timer_OverflowCallbackRegister(Timer_int);
    
    LATBbits.LATB4 = 1;     //LDAC
    LATEbits.LATE0 = 1;     //CS
    
    // Habilitamos las interrupciones globales de alta prioridad
    INTERRUPT_GlobalInterruptHighEnable(); 

    // Habilitamos las interrupciones globales de baja prioridad
    INTERRUPT_GlobalInterruptLowEnable(); 

    //Solo se manejan interrupciones, loop vacio
    while(1)
    {
    }    
}