/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.0
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

#include "../pins.h"


void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x6;
    LATC = 0x0;
    LATD = 0x0;
    LATE = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xC3;
    TRISB = 0x0;
    TRISC = 0x98;
    TRISD = 0x0;
    TRISE = 0x0;

    /**
    ANSELx registers
    */
    ANSELA = 0xC3;
    ANSELB = 0x0;
    ANSELC = 0x0;
    ANSELD = 0x0;
    ANSELE = 0x0;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;

    /**
    RxyI2C registers
    */
    RB1I2C = 0x0;
    RB2I2C = 0x0;
    RC3I2C = 0x0;
    RC4I2C = 0x0;
    RD0I2C = 0x0;
    RD1I2C = 0x0;

    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x6;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;
    /**
    PPS registers
    */
    U1RXPPS = 0x17; //RC7->UART1:RX1;
    SPI1SDIPPS = 0x14; //RC4->SPI1:SDI1;
    RC6PPS = 0x13;  //RC6->UART1:TX1;
    RC5PPS = 0x1F;  //RC5->SPI1:SDO1;
    I2C2SCLPPS = 0x9;  //RB1->I2C2:SCL2;
    RB1PPS = 0x23;  //RB1->I2C2:SCL2;
    I2C2SDAPPS = 0xA;  //RB2->I2C2:SDA2;
    RB2PPS = 0x24;  //RB2->I2C2:SDA2;
    SPI1SCKPPS = 0x13;  //RC3->SPI1:SCK1;
    RC3PPS = 0x1E;  //RC3->SPI1:SCK1;

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;


}
  
void PIN_MANAGER_IOC(void)
{
}
/**
 End of File
*/