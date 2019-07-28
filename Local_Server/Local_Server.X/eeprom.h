/* 
 * File:   eeprom.h
 * Author: terry
 *
 * Created on 01 May 2019, 17:28
 */


//#include "main.h"
#include "I2C.h"



#ifndef EEPROM_H
#define	EEPROM_H

   
    
   
    void write_EEPROM(uint16_t eeAddress, uint8_t *data, uint8_t numBytes);
    void read_EEPROM(uint16_t eeAddress, uint8_t *data, uint8_t numBytes);


#endif	/* EEPROM_H */

