
#include <stdio.h>
#include <stdlib.h>

#define N_COEFFS 5  // número de coeficientes del filtro FIR
#define N_BUFFER 8
#define MASK_Bufer 7

unsigned long FIR(int* coeffs, int input) 
{
    static int buffer[N_BUFFER] = {0}; // buffer de entrada
    static int index = 0; // índice del buffer
    //static int* arr = calloc(N_BUFFER, sizeof(int));


    unsigned long output = 0; // valor de salida

    // agregar nuevo valor de entrada al buffer y actualizar el índice
    buffer[index] = input;

    // calcular la salida del filtro
    for (int i = 0; i < N_COEFFS; i++) {
        output += (unsigned long)coeffs[i] * (unsigned long)buffer[(index - i) & MASK_Bufer];
    }

    index = (index + 1) & MASK_Bufer;
    return output;
}

unsigned long FIR_p(int* coeffs, int input) 
{

    static int index = 0; // índice del buffer
    // buffer de entrada
    static int* buffer = (int*)calloc(N_BUFFER, sizeof(int));


    unsigned long output = 0; // valor de salida

    // agregar nuevo valor de entrada al buffer y actualizar el índice
    *(buffer + index) = input;

    // calcular la salida del filtro
    for (int i = 0; i < N_COEFFS; i++) {
        output += (unsigned long)*(coeffs + i) * ((unsigned long)*(buffer + ((index - i) & MASK_Bufer)));
    }

    index = (index + 1) & MASK_Bufer;
    return output;
}