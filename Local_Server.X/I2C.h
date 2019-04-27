/* 
 * File:   I2C.h
 * Author: terry
 *
 * Created on 27 April 2019, 17:54
 */

#ifndef I2C_H
#define	I2C_H
class I2C {
public:
    I2C();
    I2C(const I2C& orig);
    virtual ~I2C();
    void I2C_init(double frequency);
    void I2C_write(unsigned char address, char wait_ack);
    void I2C_read(unsigned char *value, char ack_nack);
    void I2C_start();
    void I2C_stop();
    void I2C_restart();

private:
    void I2C_wait_for_idle(void);
    void I2C_ack(void);
    void I2C_nack(void); // Acknowledge Data bit
};

#endif	/* I2C_H */

