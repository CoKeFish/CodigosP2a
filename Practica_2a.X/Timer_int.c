
#include "Practica2a.h"
#include "Timer_int.h"
#include <xc.h>


void Timer_int(void)
{
    //LATDbits.LATD0 = !LATDbits.LATD0;
    static int count = 0;
    count++;
    
    if(count == 2)
    {
        count = 0;
        ADCC_StartConversion(channel_ANA0);
    }
}