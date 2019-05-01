/* 
 * File:   I2C.cpp
 * Author: terry
 * 
 * Created on 27 April 2019, 17:54
 */


#include <xc.h>
#include "I2C.h"
#include "Globals.h"


I2C::I2C() {
}

I2C::I2C(const I2C& orig) {
}

I2C::~I2C() {
}

// I2C_wait_for_idle() waits until the I2C peripheral is no longer doing anything  

void I2C::I2C_wait_for_idle(void) {
    while (I2C2CON & 0x1F); // Acknowledge sequence not in progress
    // Receive sequence not in progress
    // Stop condition not in progress
    // Repeated Start condition not in progress
    // Start condition not in progress
    while (I2C2STATbits.TRSTAT); // Bit = 0 ? Master transmit is not in progress
}

// I2C_start() sends a start condition  

void I2C::I2C_start() {
    I2C_wait_for_idle();
    I2C2CONbits.SEN = 1;
    while (I2C2CONbits.SEN == 1);
}

// I2C_stop() sends a stop condition  

void I2C::I2C_stop() {
    I2C_wait_for_idle();
    I2C2CONbits.PEN = 1;
}

// I2C_restart() sends a repeated start/restart condition

void I2C::I2C_restart() {
    I2C_wait_for_idle();
    I2C2CONbits.RSEN = 1;
    while (I2C2CONbits.RSEN == 1);
}

// I2C_ack() sends an ACK condition

void I2C::I2C_ack(void) {
    I2C_wait_for_idle();
    I2C2CONbits.ACKDT = 0; // Set hardware to send ACK bit
    I2C2CONbits.ACKEN = 1; // Send ACK bit, will be automatically cleared by hardware when sent  
    while (I2C2CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning ACK bit has been sent
}

// I2C_nack() sends a NACK condition

void I2C::I2C_nack(void) // Acknowledge Data bit
{
    I2C_wait_for_idle();
    I2C2CONbits.ACKDT = 1; // Set hardware to send NACK bit
    I2C2CONbits.ACKEN = 1; // Send NACK bit, will be automatically cleared by hardware when sent  
    while (I2C2CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning NACK bit has been sent
}

// address is I2C slave address, set wait_ack to 1 to wait for ACK bit or anything else to skip ACK checking  

void I2C::I2C_write(uint8_t address, char wait_ack) {
    I2C2TRN = address | 0; // Send slave address with Read/Write bit cleared
    while (I2C2STATbits.TBF == 1); // Wait until transmit buffer is empty
    I2C_wait_for_idle(); // Wait until I2C bus is idle
    if (wait_ack) while (I2C2STATbits.ACKSTAT == 1); // Wait until ACK is received  
}

uint8_t I2C::I2C_read(char ack_nack) {
    I2C2CONbits.RCEN = 1; // Receive enable
    while (I2C2CONbits.RCEN); // Wait until RCEN is cleared (automatic)  
    while (!I2C2STATbits.RBF); // Wait until Receive Buffer is Full (RBF flag)  
    uint8_t value = I2C2RCV; // Retrieve value from I2C2RCV

    if (ack_nack) // Do we need to send an ACK or a NACK?  
        I2C_ack(); // Send ACK  
    else
        I2C_nack(); // Send NACK  
    return I2C2RCV;
}
