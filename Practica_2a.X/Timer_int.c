
#include "Practica2a.h"
#include "Timer_int.h"
#include <xc.h>


void Timer_int(void)
{
    //inicializamos la variable que se encargara de hacer de contador
    static int count = 0;
    //A cada interaccion incrementamos el valor del contador
    count++;
    
    //Si el contador llega al valor de period quiere decir que 
    //llego el momento de iniciar la convercion del ADC
    if(count == PERIOD)
    {
        //Reiniciamos el contador
        count = 0;
        //Iniciamos la convercion
        ADCC_StartConversion(channel_ANA0);
    }
}