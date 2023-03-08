
#include "Practica2a.h"
#include "Timer_int.h"


void Timer_int(void)
{
    static int count = 0;
    count++;
    
    if(count == PERIOD)
    {
        //LATDbits.LATD0 = !LATDbits.LATD0;
        count = 0;
        ADCC_StartConversion(channel_ANA0);
    }
}