/**
  * SPI1 Generated Driver File
  *
  * @file spi1.c
  *
  * @ingroup spi1
  *
  * @brief Contains the API Implementations for SPI1 module driver.
  *
  * @version SPI1 Driver Version 2.0.1
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

#include "../spi1.h"
#include <xc.h>

/**
 * @ingroup spi1
 * @struct SPI_INTERFACE SPI
 * @brief Defines an object for SPI_DRIVER_FUNCTIONS.
 */ 
const struct SPI_INTERFACE SPI = {
    .Initialize = SPI_Initialize,
    .Close = SPI_Close,
    .Open = SPI_Open,
    .BufferExchange = SPI_BufferExchange,
    .BufferRead = SPI_BufferRead,
    .BufferWrite = SPI_BufferWrite,	
    .ByteExchange = SPI_ByteExchange,
    .ByteRead = SPI_ByteRead,	
    .ByteWrite = SPI_ByteWrite,
};

typedef struct 
{ 
    uint8_t con0; 
    uint8_t con1; 
    uint8_t con2; 
    uint8_t baud; 
    uint8_t operation;
} spi1_configuration_t;


//con0 == SPIxCON0, con1 == SPIxCON1, con2 == SPIxCON2, baud == SPIxBAUD, operation == Host/Client
static const spi1_configuration_t spi1_configuration[] = 
{   
    { 0x2, 0x40, 0x0, 0xF, 0 }
};

void SPI_Initialize(void)
{
    //SDOP active high; SDIP active high; SSP active high; FST disabled; CKP Idle:Low, Active:High; CKE Active to idle; SMP Middle; 
    SPI1CON1 = 0x40;
    //RXR data is not stored in the FIFO; TXR not required for a transfer; SSET disabled; 
    SPI1CON2 = 0x0;
    //CLKSEL FOSC; 
    SPI1CLK = 0x0;
    //BAUD 15; 
    SPI1BAUD = 0xF;
    TRISCbits.TRISC3 = 0;
    //BMODE last byte; MST bus host; LSBF MSb first; EN disabled; 
    SPI1CON0 = 0x2;
}

bool SPI_Open(uint8_t spiConfigIndex)
{   
    if(!SPI1CON0bits.EN)
    {
        SPI1CON0 = spi1_configuration[spiConfigIndex].con0;
        SPI1CON1 = spi1_configuration[spiConfigIndex].con1;
        SPI1CON2 = spi1_configuration[spiConfigIndex].con2 | (_SPI1CON2_SPI1RXR_MASK | _SPI1CON2_SPI1TXR_MASK);
        SPI1CLK  = 0x00;
        SPI1BAUD = spi1_configuration[spiConfigIndex].baud;        
        TRISCbits.TRISC3 = spi1_configuration[spiConfigIndex].operation;
        SPI1CON0bits.EN = 1;
        return true;
    }
    return false;
}

void SPI_Close(void)
{
    SPI1CON0bits.EN = 0;
}

uint8_t SPI_ByteExchange(uint8_t data)
{
    SPI1TCNTL = 1;
    SPI1TXB = data;
    while(!PIR2bits.SPI1RXIF);
    return SPI1RXB;
}

void SPI_BufferExchange(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SPI1TCNTL = 1;
        SPI1TXB = *data;
        while(!PIR2bits.SPI1RXIF);
        *data++ = SPI1RXB;
    }
}

// Half Duplex SPI Functions
void SPI_BufferWrite(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SPI_ByteExchange(*data++);
    }
}

void SPI_BufferRead(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data++ = SPI_ByteExchange(0);
    }
}

void SPI_ByteWrite(uint8_t byte)
{
    SPI1TXB = byte;
}

uint8_t SPI_ByteRead(void)
{
    return SPI1RXB;
}

uint8_t SPI1_ExchangeByte(uint8_t data)
{
    return SPI_ByteExchange(data);
}

void SPI1_ExchangeBlock(void *block, size_t blockSize)
{
    SPI_BufferExchange(block, blockSize);
}

void SPI1_WriteBlock(void *block, size_t blockSize)
{
    SPI_BufferWrite(block, blockSize);
}

void SPI1_ReadBlock(void *block, size_t blockSize)
{
    SPI_BufferRead(block, blockSize);
}

void SPI1_WriteByte(uint8_t byte)
{
    SPI_ByteWrite(byte);
}

uint8_t SPI1_ReadByte(void)
{
    return SPI_ByteRead();
}
