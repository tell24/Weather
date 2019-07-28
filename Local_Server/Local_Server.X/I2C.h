/* 
 * File:   I2C.h
 * Author: terry
 *
 * Created on 27 April 2019, 17:54
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <plib.h>



#ifndef I2C_H
#define	I2C_H


#define SYS_FREQ  80000000


#define ATMLH_ADDRESS 0x00
#define _ack 1
#define _nack 0

void init_I2C(double frequency);

void I2C_wait_for_idle(void); 

// I2C_start() sends a start condition  

void I2C_start();
// I2C_stop() sends a stop condition  

void I2C_stop();

// I2C_restart() sends a repeated start/restart condition

void I2C_restart();
// I2C_ack() sends an ACK condition

void I2C_ack(void) ;

// I2C_nack() sends a NACK condition

void I2C_nack(void); // Acknowledge Data bit

// address is I2C slave address, set wait_ack to 1 to wait for ACK bit or anything else to skip ACK checking  

void I2C_write(uint8_t address, char wait_ack);

uint8_t I2C_read(char ack_nack);

bool I2C_error();

#endif	/* I2C_H */

