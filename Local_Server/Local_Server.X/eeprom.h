/* 
 * File:   eeprom.h
 * Author: terry
 *
 * Created on 01 May 2019, 17:28
 */


//#include "main.h"
#include "I2C.h"

#define ATMLH_ADDRESS 0x50
//#define ANALIZER_ON

#ifndef EEPROM_H
#define	EEPROM_H
 
   
#if defined(ANALIZER_ON)    
#define TRIGGER_CONTROL         (TRISFbits.TRISF3)	// Ref LED1
#define TRIGGER_IO				(LATFbits.LATF3)
#endif
    
   
    void write_EEPROM(uint16_t eeAddress, uint8_t data[], uint8_t numBytes);
    void read_EEPROM(uint16_t eeAddress, uint8_t data[], uint8_t numBytes);


#endif	/* EEPROM_H */

