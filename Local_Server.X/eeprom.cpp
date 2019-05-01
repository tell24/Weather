/* 
 * File:   eeprom.cpp
 * Author: terry
 * 
 * Created on 01 May 2019, 17:28
 */
#include "eeprom.h"

I2C i2c;

eeprom::eeprom() {
}

eeprom::eeprom(const eeprom& orig) {
}

eeprom::~eeprom() {
}

// I2C_init() initialises I2C2 at at frequency of [frequency]Hz  

void eeprom::init_EEPROM(double frequency) {
    double BRG;
    I2C2CON = 0; // Turn off I2C2 module
    I2C2CONbits.DISSLW = 1; // Disable slew rate for 100kHz

    BRG = (1 / (2 * frequency)) - 0.000000104;
    BRG *= (SYS_FREQ / 2) - 2;

    I2C2BRG = (int) BRG; // Set baud rate
    I2C2CONbits.ON = 1; // Turn on I2C2 module
}

void eeprom::write_EEPROM(uint16_t eeAddress, uint8_t *data, uint8_t numBytes) {
    i2c.I2C_start(); /* Send start condition */
    i2c.I2C_write(0xA0 | (ATMLH_ADDRESS << 1), _ack); /* Send MPU9250's address, read/write bit not set (AD + R) */
    i2c.I2C_write((int) (eeAddress >> 8), _ack); /* Send the register address (RA) */
    i2c.I2C_write((int) (eeAddress & 0xFF), _ack); /* Send the value to set it to */
    uint8_t buf[numBytes];
    memcpy(buf, data, numBytes);
    for (uint8_t x = 0; x < numBytes; x++)
        i2c.I2C_write(buf[x], _nack); //Write the data
    i2c.I2C_stop(); /* Send stop condition */
}

void eeprom::read_EEPROM(uint16_t eeAddress, uint8_t *data, uint8_t numBytes) {
    i2c.I2C_start();
    i2c.I2C_write(0xA0 | (ATMLH_ADDRESS << 1), _ack); /* Send MPU9250's address, read/write bit not set (AD + R) */
    i2c.I2C_write((int) (eeAddress >> 8), _ack); /* Send the register address (RA) */
    i2c.I2C_write((int) (eeAddress & 0xFF), _ack); /* Send the value to set it to */
    i2c.I2C_start();
    i2c.I2C_write(0xA1 | (ATMLH_ADDRESS << 1), _ack); /* Send MPU9250's address, read/write bit not set (AD + R) */
    uint8_t buf[numBytes];
    uint8_t x = 0;
    while (x < (numBytes - 1)) {
        *data++ = i2c.I2C_read(_ack); //Write the data
        x++;
    }
    *data = i2c.I2C_read(_nack); //Read the data
    i2c.I2C_stop(); /* Send stop condition */
}