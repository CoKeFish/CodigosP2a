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

#include <xc.h>
#include "../tmr0.h"
#include "../../system/interrupt.h"

volatile uint16_t timerTMR0ReloadVal16bit;

const struct TMR_INTERFACE Timer = {
    .Initialize = Timer_Initialize,
    .Start = Timer_Start,
    .Stop = Timer_Stop,
    .PeriodCountSet = Timer_PeriodCountSet,
    .TimeoutCallbackRegister = Timer_OverflowCallbackRegister,
    .Tasks = NULL
};

static void (*Timer_OverflowCallback)(void);
static void Timer_DefaultOverflowCallback(void);

void Timer_Initialize(void)
{
    //TMR0H 231; 
    TMR0H = 0xE7;

    //TMR0L 90; 
    TMR0L = 0x5F;

    //T0CS HFINTOSC; T0CKPS 1:1; T0ASYNC not_synchronised; 
    T0CON1 = 0x70;

    //Load TMRTMR0 value to the 16-bit reload variable
    timerTMR0ReloadVal16bit = ((uint16_t)TMR0H << 8) | TMR0L;

    //Set default callback for TMR0 overflow interrupt
    Timer_OverflowCallbackRegister(Timer_DefaultOverflowCallback);

    //Clear Interrupt flag before enabling the interrupt
    PIR3bits.TMR0IF = 0;
	
    //Enable TMR0 interrupt.
    PIE3bits.TMR0IE = 1;
	
    //T0OUTPS 1:1; T0EN enabled; T016BIT 16-bit; 
    T0CON0 = 0x90;
}

void Timer_Start(void)
{
    T0CON0bits.T0EN = 1;
}

void Timer_Stop(void)
{
    T0CON0bits.T0EN = 0;
}

uint16_t Timer_Read(void)
{
    uint16_t readVal;
    uint8_t readValLow;
    uint8_t readValHigh;

    readValLow  = TMR0L;
    readValHigh = TMR0H;
    readVal  = ((uint16_t)readValHigh << 8) + readValLow;

    return readVal;
}

void Timer_Write(size_t timerVal)
{
    TMR0H = timerVal >> 8;
    TMR0L = (uint8_t) timerVal;
}

void Timer_Reload(void)
{
    TMR0H = timerTMR0ReloadVal16bit >> 8;
    TMR0L = (uint8_t) timerTMR0ReloadVal16bit;
}

void Timer_PeriodCountSet(size_t periodVal)
{
   timerTMR0ReloadVal16bit = (uint16_t) periodVal;
}

void __interrupt(irq(TMR0),base(8)) Timer_OverflowISR()
{
    //Clear the TMR0 interrupt flag
    PIR3bits.TMR0IF = 0;
    //Write to the TimerTMR0 register
    TMR0H = timerTMR0ReloadVal16bit >> 8;
    TMR0L = (uint8_t) timerTMR0ReloadVal16bit;

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

