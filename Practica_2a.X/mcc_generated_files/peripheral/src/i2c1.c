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
#include "../i2c1.h"

// Set the I2C1 module to the options selected in the user interface.
void I2C1_Initialize(void) {
    // TXB 0x0; 
    I2C1TXB = 0x0;
    // CNT 0x0; 
    I2C1CNT = 0x0;
    // ADB 0x0; 
    I2C1ADB0 = 0x0;
    // ADB 0x0; 
    I2C1ADB1 = 0x0;
    // ADR 0x0; 
    I2C1ADR0 = 0x0;
    // ADR 0x0; 
    I2C1ADR1 = 0x0;
    // ADR 0x0; 
    I2C1ADR2 = 0x0;
    // ADR 0x0; 
    I2C1ADR3 = 0x0;
    // EN disabled; RSEN disabled; S Cleared by hardware after Start; CSTR Enable clocking; MODE four 7-bit address; 
    I2C1CON0 = 0x0;
    // ACKCNT Acknowledge; ACKDT Acknowledge; ACKSTAT ACK received; ACKT No Acknowledge sequence; RXO No overflow; TXU No underflow; CSD Clock Stretching enabled; 
    I2C1CON1 = 0x0;
    // ACNT disabled; GCEN disabled; FME disabled; ABD enabled; SDAHT 300 ns hold time; BFRET 8 I2C Clock pulses; 
    I2C1CON2 = 0x0;
    // BTOIF No bus timeout; BCLIF No bus collision detected; NACKIF No NACK/Error detected; BTOIE disabled; BCLIE disabled; NACKIE disabled; 
    I2C1ERR = 0x0;
    // TXWE No error; RXRE No overflow; CLRBF Does not clear TX and RX Buffers; 
    I2C1STAT1 = 0x0;
    // CNTIF Byte count is not zero; ACKTIF Acknowledge sequence not detected; WRIF Data byte not detected; ADRIF Address not detected; PCIF Stop condition not detected; RSCIF Restart condition not detected; SCIF Start condition not detected; 
    I2C1PIR = 0x0;
    // CNTIE disabled; ACKTIE disabled; WRIE disabled; ADRIE disabled; PCIE disabled; RSCIE disabled; SCIE disabled; 
    I2C1PIE = 0x0;
    // CLK Fosc/4; 
    I2C1CLK = 0x0;
    // BTO TMR2 post scaled output; 
    I2C1BTO = 0x1;
}
