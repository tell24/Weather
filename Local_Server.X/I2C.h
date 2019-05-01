/* 
 * File:   I2C.h
 * Author: terry
 *
 * Created on 27 April 2019, 17:54
 */

#include <xc.h>

#ifndef I2C_H
#define	I2C_H
class I2C {
#define ATMLH_ADDRESS 0x00
#define _ack 1
#define _nack 0
public:
    I2C();
    I2C(const I2C& orig);
    virtual ~I2C();
    void I2C_write(uint8_t address, char wait_ack);
    uint8_t I2C_read(char ack_nack);
    void I2C_start();
    void I2C_stop();
    void I2C_restart();

private:
    void I2C_wait_for_idle(void);
    void I2C_ack(void);
    void I2C_nack(void); // Acknowledge Data bit
};

#endif	/* I2C_H */

