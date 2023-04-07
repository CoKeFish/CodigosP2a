
#include "mcc_generated_files/uart/uart1.h"
#include "Practica2a.h"

void errorMessage();

void WriteMemory(int16_t addres, int8_t value);
int ReadMemory(int16_t Addres);

enum State {
    WaitOpcode_1 = 0, 
    WaitOpcode_2 = 1, 
    WaitAddres_1 = 2, 
    WaitAddres_2 = 3, 
    WaitValue = 4
};

enum Operation {Write = 0, Read = 1};
enum OpType {Byte = 0, String = 1};

void UART_RX_int(void)
{
    static enum State status = WaitOpcode_1;
    static enum Operation OperationV = Write;
    static enum OpType TypeV = Byte;
    
    static uint8_t Addres = 0;
    static uint8_t Value = 0;
    
    if(U1RXB == '\n')
    {
        status = WaitOpcode_1;
        return;
    }

    if(status == WaitOpcode_1)
    {
        if(U1RXB == 'W' || U1RXB == 'w')
        {
            OperationV = Write;     //Almacenamos el valor recibido
            
        }
        else if(U1RXB == 'R' || U1RXB == 'r')
        {
            OperationV = Read;     //Almacenamos el valor recibido
        }
        else
        {
            errorMessage();
            return;
        }
        
        status = WaitOpcode_2;
        return;
        
    }
    if(status == WaitOpcode_2)
    {
        if(U1RXB == 'B' || U1RXB == 'b')
        {
            TypeV = Byte;     //Almacenamos el valor recibido
        }
        else if(U1RXB == 'S' || U1RXB == 's')
        {
            TypeV = String;
        }
        else
        {
            status = WaitOpcode_1;
            errorMessage();
            return;
        }
        
        status = WaitAddres_1;
        return;
    }
    
    if(status == WaitAddres_1)
    {
        Addres = U1RXB << 8;
        status == WaitAddres_2;
        return;
    }
    if(status == WaitAddres_2)
    {
        Addres |= U1RXB;
        status == WaitValue;
        return;
    }
    if(status == WaitValue)
    {
        if(OperationV == Write && TypeV == Byte)
        {
            WriteMemory(Addres, U1RXB);
        }
        else if(OperationV == Write && TypeV == String)
        {
            WriteMemory(Addres++, U1RXB);
        }
        else if(OperationV == Read && TypeV == Byte)
        {
            ReadMemory(Addres);
        }
        else if(OperationV == Read && TypeV == String)
        {
            ReadMemory(Addres++);
        }
        return;
    }
     
    
}