/**
 * TMR0 Generated Driver File
 * 
 * @file tmr0.c
 * 
 * @ingroup tmr0
 * 
 * @brief  Driver implementation for the TMR0 driver
 *
 * @version TMR0 Driver Version 2.1.0
*/
/*
� [2023] Microchip Technology Inc. and its subsidiaries.

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

#include <xc.h>
#include "../tmr0.h"
#include "../../system/interrupt.h"


const struct TMR_INTERFACE Timer = {
    .Initialize = Timer_Initialize,
    .Start = Timer_Start,
    .Stop = Timer_Stop,
    .PeriodCountSet = Timer_Reload,
    .TimeoutCallbackRegister = Timer_OverflowCallbackRegister,
    .Tasks = NULL
};

static void (*Timer_OverflowCallback)(void);
static void Timer_DefaultOverflowCallback(void);

void Timer_Initialize(void)
{
    //TMR0H 199; 
    TMR0H = 0xC7;

    //TMR0L 0; 
    TMR0L = 0x0;

    //T0CS FOSC/4; T0CKPS 1:2; T0ASYNC synchronised; 
    T0CON1 = 0x41;


    //Set default callback for TMR0 overflow interrupt
    Timer_OverflowCallbackRegister(Timer_DefaultOverflowCallback);

    //Clear Interrupt flag before enabling the interrupt
    PIR3bits.TMR0IF = 0;
	
    //Enable TMR0 interrupt.
    PIE3bits.TMR0IE = 1;
	
    //T0OUTPS 1:1; T0EN enabled; T016BIT 8-bit; 
    T0CON0 = 0x80;
}

void Timer_Start(void)
{
    T0CON0bits.T0EN = 1;
}

void Timer_Stop(void)
{
    T0CON0bits.T0EN = 0;
}

uint8_t Timer_Read(void)
{
    uint8_t readVal;

    //Read TMR0 register, low byte only
    readVal = TMR0L;

    return readVal;
}

void Timer_Write(uint8_t timerVal)
{
    //Write to TMR0 register, low byte only
    TMR0L = timerVal;
 }

void Timer_Reload(size_t periodVal)
{
   //Write to TMR0 register, high byte only
   TMR0H = (uint8_t)periodVal;
}

void __interrupt(irq(TMR0),base(8)) Timer_OverflowISR()
{
    //Clear the TMR0 interrupt flag
    PIR3bits.TMR0IF = 0;
    if(Timer_OverflowCallback)
    {
        Timer_OverflowCallback();
    }
}

void Timer_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer_OverflowCallback = CallbackHandler;
}

static void Timer_DefaultOverflowCallback(void)
{
    //Add your interrupt code here or
    //Use Timer_OverflowCallbackRegister function to use Custom ISR
}

