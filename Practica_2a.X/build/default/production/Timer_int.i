# 1 "Timer_int.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Program Files/packs/Microchip/PIC18F-K_DFP/1.7.134/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Timer_int.c" 2

# 1 "./Practica2a.h" 1

# 1 "./ADC_int.h" 1





void ADC_int(void);
# 2 "./Practica2a.h" 2

# 1 "./UART_int.h" 1

void UART_TX_int(void);
void UART_RX_int(void);
# 3 "./Practica2a.h" 2

# 1 "./Timer_int.h" 1


# 1 "./mcc_generated_files/adc/adcc.h" 1
# 40 "./mcc_generated_files/adc/adcc.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdint.h" 2 3
# 40 "./mcc_generated_files/adc/adcc.h" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.40\\pic\\include\\c99\\stdbool.h" 1 3
# 41 "./mcc_generated_files/adc/adcc.h" 2







typedef uint16_t adc_result_t;

typedef __uint24 uint24_t;







typedef enum
{
    channel_VSS = 0x3b,
    channel_Temp = 0x3c,
    channel_DAC1 = 0x3d,
    channel_FVR_Buffer1 = 0x3e,
    channel_FVR_Buffer2 = 0x3f,
    channel_ANA0 = 0x0,
    channel_ANA1 = 0x1
} adcc_channel_t;
# 79 "./mcc_generated_files/adc/adcc.h"
void ADCC_Initialize(void);
# 89 "./mcc_generated_files/adc/adcc.h"
void ADCC_StartConversion(adcc_channel_t channel);
# 99 "./mcc_generated_files/adc/adcc.h"
_Bool ADCC_IsConversionDone(void);
# 109 "./mcc_generated_files/adc/adcc.h"
adc_result_t ADCC_GetConversionResult(void);
# 119 "./mcc_generated_files/adc/adcc.h"
adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel);
# 128 "./mcc_generated_files/adc/adcc.h"
__attribute__((inline)) void ADCC_StopConversion(void);
# 137 "./mcc_generated_files/adc/adcc.h"
__attribute__((inline)) void ADCC_SetStopOnInterrupt(void);







__attribute__((inline)) void ADCC_DischargeSampleCapacitor(void);







void ADCC_LoadAcquisitionRegister(uint16_t acquisitionValue);







void ADCC_SetPrechargeTime(uint16_t prechargeTime);







void ADCC_SetRepeatCount(uint8_t repeatCount);
# 178 "./mcc_generated_files/adc/adcc.h"
uint8_t ADCC_GetCurrentCountofConversions(void);







__attribute__((inline)) void ADCC_ClearAccumulator(void);







uint24_t ADCC_GetAccumulatorValue(void);
# 204 "./mcc_generated_files/adc/adcc.h"
_Bool ADCC_HasAccumulatorOverflowed(void);







uint16_t ADCC_GetFilterValue(void);
# 221 "./mcc_generated_files/adc/adcc.h"
uint16_t ADCC_GetPreviousResult(void);







void ADCC_DefineSetPoint(uint16_t setPoint);







void ADCC_SetUpperThreshold(uint16_t upperThreshold);







void ADCC_SetLowerThreshold(uint16_t lowerThreshold);
# 254 "./mcc_generated_files/adc/adcc.h"
uint16_t ADCC_GetErrorCalculation(void);







__attribute__((inline)) void ADCC_EnableDoubleSampling(void);







__attribute__((inline)) void ADCC_EnableContinuousConversion(void);







__attribute__((inline)) void ADCC_DisableContinuousConversion(void);
# 288 "./mcc_generated_files/adc/adcc.h"
_Bool ADCC_HasErrorCrossedUpperThreshold(void);
# 298 "./mcc_generated_files/adc/adcc.h"
_Bool ADCC_HasErrorCrossedLowerThreshold(void);
# 307 "./mcc_generated_files/adc/adcc.h"
uint8_t ADCC_GetConversionStageStatus(void);







void ADCC_SetADIInterruptHandler(void (* InterruptHandler)(void));
# 3 "./Timer_int.h" 2


void Timer_int(void);
# 4 "./Practica2a.h" 2






uint16_t PERIOD = 1;
# 2 "Timer_int.c" 2

# 1 "./Timer_int.h" 1




void Timer_int(void);
# 3 "Timer_int.c" 2



void Timer_int(void)
{
    static int count = 0;
    count++;

    if(count == PERIOD)
    {
        count = 0;
        ADCC_StartConversion(channel_ANA0);
    }
}
