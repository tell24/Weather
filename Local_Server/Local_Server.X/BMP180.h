/* 
 * File:   SFE_BMP180.h
 * Author: terry
 *
 * Created on 23 July 2019, 17:35
 */
#include <stdint.h>
#include "I2C.h"

#ifndef BMP180_H
#define	MP180_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define ALTITUDE 70    
#define BMP180_ADDR 0xEE // 7-bit address   
#define BMP180_ADDR_READ 0xEF // 7-bit address

#define	BMP180_REG_CONTROL 0xF4
#define	BMP180_REG_RESULT 0xF6

#define	BMP180_COMMAND_TEMPERATURE 0x2E
#define	BMP180_COMMAND_PRESSURE0 0x34
#define	BMP180_COMMAND_PRESSURE1 0x74
#define	BMP180_COMMAND_PRESSURE2 0xB4
#define	BMP180_COMMAND_PRESSURE3 0xF4
    
    

		char BMP180_begin();
			// call pressure.begin() to initialize BMP180 before use
			// returns 1 if success, 0 if failure (bad component or I2C bus shorted?)
				
		char BMP180_startTemperature(void);
			// command BMP180 to start a temperature measurement
			// returns (number of ms to wait) for success, 0 for fail

		char BMP180_getTemperature(double *T);
			// return temperature measurement from previous startTemperature command
			// places returned value in T variable (deg C)
			// returns 1 for success, 0 for fail

		char BMP180_startPressure(char oversampling);
			// command BMP180 to start a pressure measurement
			// oversampling: 0 - 3 for oversampling value
			// returns (number of ms to wait) for success, 0 for fail

		char BMP180_getPressure(double *P, double *T);
			// return absolute pressure measurement from previous startPressure command
			// note: requires previous temperature measurement in variable T
			// places returned value in P variable (mbar)
			// returns 1 for success, 0 for fail

		double BMP180_sealevel(double P, double A);
			// convert absolute pressure to sea-level pressure (as used in weather data)
			// P: absolute pressure (mbar)
			// A: current altitude (meters)
			// returns sealevel pressure in mbar

		double BMP180_altitude(double P, double P0);
			// convert absolute pressure to altitude (given baseline pressure; sea-level, runway, etc.)
			// P: absolute pressure (mbar)
			// P0: fixed baseline pressure (mbar)
			// returns signed altitude in meters

		char BMP180_getError(void);
			// If any library command fails, you can retrieve an extended
			// error code using this command. Errors are from the wire library: 
			// 0 = Success
			// 1 = Data too long to fit in transmit buffer
			// 2 = Received NACK on transmit of address
			// 3 = Received NACK on transmit of data
			// 4 = Other error


	
		char readInt(char address, int16_t *value);
			// read an signed int (16 bits) from a BMP180 register
			// address: BMP180 register address
			// value: external signed int for returned value (16 bits)
			// returns 1 for success, 0 for fail, with result in value

		char readUInt(char address, uint16_t *value);
			// read an unsigned int (16 bits) from a BMP180 register
			// address: BMP180 register address
			// value: external unsigned int for returned value (16 bits)
			// returns 1 for success, 0 for fail, with result in value

		char readBytes(unsigned char *values, char length);
			// read a number of bytes from a BMP180 register
			// values: array of char with register address in first location [0]
			// length: number of bytes to read back
			// returns 1 for success, 0 for fail, with read bytes in values[] array
	
		char writeBytes(unsigned char *values, char length);
			// write a number of bytes to a BMP180 register (and consecutive subsequent registers)
			// values: array of char with register address in first location [0]
			// length: number of bytes to write
			// returns 1 for success, 0 for fail

			
		int16_t AC1,AC2,AC3,VB1,VB2,MB,MC,MD;
		uint16_t AC4,AC5,AC6; 
		double c5,c6,mc,md,x0,x1,x2,y0,y1,y2,p0,p1,p2;
		char _error;

#ifdef	__cplusplus
}
#endif

#endif	/* SFE_BMP180_H */

