/* 
 * File:   eeprom.h
 * Author: terry
 *
 * Created on 01 May 2019, 17:28
 */


#include <xc.h>
#include "I2C.h"
#include "Globals.h"

#ifndef EEPROM_H
#define	EEPROM_H

class eeprom {
public:
    eeprom();
    eeprom(const eeprom& orig);
    virtual ~eeprom();
    
    void init_EEPROM(double frequency);
    void write_EEPROM(uint16_t eeAddress, uint8_t *data, uint8_t numBytes);
    void read_EEPROM(uint16_t eeAddress, uint8_t *data, uint8_t numBytes);
private:

};

#endif	/* EEPROM_H */

