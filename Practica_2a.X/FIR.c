
#include <stdio.h>
#include <stdlib.h>

#define N_COEFFS 5  // número de coeficientes del filtro FIR
#define N_BUFFER 8
#define MASK_Bufer 7

unsigned long FIR(int* coeffs, int input) 
{
    static int buffer[N_BUFFER] = {0}; // buffer de entrada
    static int index = 0; // índice del buffer
    static int inpar = N_COEFFS & 1;
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
    
// buffer de entrada// buffer de entrada
int* buffer = (int*)calloc(N_BUFFER, sizeof(int));
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

unsigned long FIR_pE(int *coeffs, int input) {
    // buffer de entrada
    static int buffer[N_BUFFER] = {0};

    static int *startBuffer = buffer;    //Puntero de la cabeza
    static int *endBuffer = buffer + MASK_Bufer;    //Puntero de la cola

    static int *head = buffer;    //Puntero iterante de la cabeza
    static int *tail = buffer + ((-N_COEFFS) & MASK_Bufer) ;    //Puntero iterante de la cabeza


    static int *head_i = buffer;    //Puntero iterante de la cabeza
    static int *tail_i = buffer + ((-N_COEFFS + 1) & MASK_Bufer);    //Puntero iterante de la cola


    static int indexHead = 0; // índice del buffer de la cabeza
    static int indexTail = ((-N_COEFFS + 1) & MASK_Bufer); // índice del buffer de la cabeza

    unsigned long output = 0; // valor de salida


    // agregar nuevo valor de entrada al buffer y actualizar el índice
    *(head) = input;

    // calcular la salida del filtro
    for (int i = 0; i < 2; i++) {

        output += (unsigned long) *(coeffs++) * ((unsigned long) * (head_i) + (unsigned long) * (tail_i));
        if(head_i == startBuffer)
        {
            head_i = endBuffer;
        } else
        {
            head_i--;
        }
        if(tail_i == endBuffer)
        {
            tail_i = startBuffer;
        } else
        {
            tail_i++;
        }
        if(head_i == tail_i)
        {
            output += (unsigned long) *(coeffs) * ((unsigned long) * (head_i));
        }
    }


    indexHead = (indexHead + 1) & MASK_Bufer;
    indexTail = (indexTail + 1) & MASK_Bufer;

    head = (buffer + indexHead);
    tail = (buffer + indexTail);

    head_i = head;
    tail_i = tail;

    return output;
}