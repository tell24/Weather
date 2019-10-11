/* 
 * File:   eeprom.cpp
 * Author: terry
 * 
 * Created on 01 May 2019, 17:28
 */
#include "eeprom.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

  
// I2C_init() initialises I2C2 at at frequency of [frequency]Hz  


void write_EEPROM(uint16_t eeAddress, uint8_t data[], uint8_t numBytes) {
    I2C_start(); /* Send start condition */
    I2C_write(0xA0 | (ATMLH_ADDRESS << 1), _ack); /* Send MPU9250's address, read/write bit not set (AD + R) */
    I2C_write((int) (eeAddress >> 8), _ack); /* Send the register address (RA) */
    I2C_write((int) (eeAddress & 0xFF), _ack); /* Send the value to set it to */
//    uint8_t buf[numBytes];
//    memcpy(buf, data, numBytes);
    uint8_t x = 0;
    uint8_t so_send = 0;
    do {
        so_send  = data[x];
        I2C_write(data[x], _nack);
        x++;
    }while( x < numBytes );
         //Write the data
    I2C_stop(); /* Send stop condition */
}

void read_EEPROM(uint16_t eeAddress, uint8_t data1[], uint8_t numBytes) {
    I2C_start();
    I2C_write(0xA0 | (ATMLH_ADDRESS << 1), _ack); /* Send MPU9250's address, read/write bit not set (AD + R) */
    I2C_write((int) (eeAddress >> 8), _ack); /* Send the register address (RA) */
    I2C_write((int) (eeAddress & 0xFF), _ack); /* Send the value to set it to */
    I2C_start();
    I2C_write(0xA1 | (ATMLH_ADDRESS << 1), _ack); /* Send MPU9250's address, read/write bit not set (AD + R) */
    uint8_t buf[numBytes];
    uint8_t x = 0;
    while (x < (numBytes - 1)) {
         buf[x] = I2C_read(_ack); //Write the data
        x++;
    }
    buf[x] = I2C_read(_nack); //Read the data
    I2C_stop(); /* Send stop condition */ 
    memcpy(data1, &buf, numBytes);
}
