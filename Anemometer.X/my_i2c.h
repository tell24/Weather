/* 
 * File:   my_i2c.h
 * Author: te
 *
 * Created on 12 December 2018, 14:39
 */


#ifndef MY_I2C_H
#define	MY_I2C_H

#ifdef	__cplusplus
extern "C" {
#endif


void i2c_init();

void __attribute__((interrupt, no_auto_psv)) _SI2C2Interrupt(void);



#ifdef	__cplusplus
}
#endif

#endif	/* MY_I2C_H */

