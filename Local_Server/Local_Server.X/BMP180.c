#include <math.h>
#include "BMP180.h"
#include <stdbool.h>
//#include "MyUart.h"

char BMP180_begin()
// Initialize library for subsequent pressure measurements
{
    double c3, c4, b1;


    // The BMP180 includes factory calibration data stored on the device.
    // Each device has different numbers, these must be retrieved and
    // used in the calculations when taking pressure measurements.

    // Retrieve calibration data from device
    //          BMP180_startTemperature();
    if (readInt(0xAA, &AC1) &&
            readInt(0xAC, &AC2) &&
            readInt(0xAE, &AC3) &&
            readUInt(0xB0, &AC4) &&
            readUInt(0xB2, &AC5) &&
            readUInt(0xB4, &AC6) &&
            readInt(0xB6, &VB1) &&
            readInt(0xB8, &VB2) &&
            readInt(0xBA, &MB) &&
            readInt(0xBC, &MC) &&
            readInt(0xBE, &MD)) {

        // All reads completed successfully!

        // If you need to check your math using known numbers,
        // you can uncomment one of these examples.
        // (The correct results are commented in the below functions.)

        // Example from Bosch datasheet
        // AC1 = 408; AC2 = -72; AC3 = -14383; AC4 = 32741; AC5 = 32757; AC6 = 23153;
        // B1 = 6190; B2 = 4; MB = -32768; MC = -8711; MD = 2868;

        // Example from http://wmrx00.sourceforge.net/Arduino/BMP180-Calcs.pdf
        // AC1 = 7911; AC2 = -934; AC3 = -14306; AC4 = 31567; AC5 = 25671; AC6 = 18974;
        // VB1 = 5498; VB2 = 46; MB = -32768; MC = -11075; MD = 2432;       


        // Compute floating-point polynominals:

        c3 = 160.0 * pow(2, -15) * AC3;
        c4 = pow(10, -3) * pow(2, -15) * AC4;
        b1 = pow(160, 2) * pow(2, -30) * VB1;
        c5 = (pow(2, -15) / 160) * AC5;
        c6 = AC6;
        mc = (pow(2, 11) / pow(160, 2)) * MC;
        md = MD / 160.0;
        x0 = AC1;
        x1 = 160.0 * pow(2, -13) * AC2;
        x2 = pow(160, 2) * pow(2, -25) * VB2;
        y0 = c4 * pow(2, 15);
        y1 = c4 * c3;
        y2 = c4 * b1;
        p0 = (3791.0 - 8.0) / 1600.0;
        p1 = 1.0 - 7357.0 * pow(2, -20);
        p2 = 3038.0 * 100.0 * pow(2, -36);

        // Success!
        return (1);
    } else {
        // Error reading calibration data; bad component or connection?
        return (0);
    }
}

char readInt(char address, int16_t *value)
// Read a signed integer (two bytes) from device
// address: register to start reading (plus subsequent register)
// value: external variable to store data (function modifies value)
{
    unsigned char data[2];
    int8_t value1;
    data[0] = address;
    if (readBytes(data, 2)) {
        value1 = data[0];
        data[0] = data[1];
        data[1] = value1;
        memcpy(value, data, 2);
        //if (*value & 0x8000) *value |= 0xFFFF0000; // sign extend if negative

        return (1);
    }
    value = 0;
    return (0);
}

char readUInt(char address, uint16_t *value)
// Read an unsigned integer (two bytes) from device
// address: register to start reading (plus subsequent register)
// value: external variable to store data (function modifies value)
{
    unsigned char data[2];
    int8_t value1;
    data[0] = address;
    if (readBytes(data, 2)) {
        value1 = data[0];
        data[0] = data[1];
        data[1] = value1;
        memcpy(value, data, 2);
        //if (*value & 0x8000) *value |= 0xFFFF0000; // sign extend if negative

        return (1);
    }
    value = 0;
    return (0);

}

char readBytes(unsigned char *values, char length)
// Read an array of bytes from device
// values: external array to hold data. Put starting register in values[0].
// length: number of bytes to read
{
    I2C_start();
    I2C_write(BMP180_ADDR, _ack);
    I2C_write(values[0], _ack);
    I2C_stop();
    if(I2C_error)	{
       I2C_start();
    I2C_write(BMP180_ADDR_READ, _nack);
    //		I2C_write(length, _nack);
    uint8_t x = 0;
    while (x < (length - 1)) {
        //values[x]
        values[x] = I2C_read(_ack);
        x++;
    }
    values[x] = I2C_read(_nack);
    I2C_stop(); /* Send stop condition */
    if ((values == 0xffff) || (values == 0x0000))
        return (0);
    return (1);
    	}
    my_uart_println_str("R_e");
        return (0);

}

char writeBytes(unsigned char *values, char length)
// Write an array of bytes to device
// values: external array of data to write. Put starting register in values[0].
// length: number of bytes to write
{
    I2C_start(); /* Send start condition */

    I2C_write(BMP180_ADDR, _ack);
    uint8_t buf[length];
    memcpy(buf, values, length);
    uint8_t x = 0;
    do {
        I2C_write(buf[x], _nack);
        x++;
    } while (x < length);
    //_error = 
    I2C_stop(); /* Send stop condition */
    if (I2C_error)
        return (1);
    else
        return (0);
}

char BMP180_startTemperature(void)
// Begin a temperature reading.
// Will return delay in ms to wait, or 0 if I2C error
{
    unsigned char data[2], result;

    data[0] = BMP180_REG_CONTROL;
    data[1] = BMP180_COMMAND_TEMPERATURE;
    result = writeBytes(data, 2);
    if (result) // good write?
        return (5); // return the delay in ms (rounded up) to wait before retrieving data
    else
        return (0); // or return 0 if there was a problem communicating with the BMP
}

char BMP180_getTemperature(double *T)
// Retrieve a previously-started temperature reading.
// Requires begin() to be called once prior to retrieve calibration parameters.
// Requires startTemperature() to have been called prior and sufficient time elapsed.
// T: external variable to hold result.
// Returns 1 if successful, 0 if I2C error.
{
    unsigned char data[2];
    char result;
    double tu, a;

    data[0] = BMP180_REG_RESULT;

    result = readBytes(data, 2);
    if (result) // good read, calculate temperature
    {
        tu = (data[0] * 256.0) + data[1];

        //example from Bosch datasheet
        //tu = 27898;

        //example from http://wmrx00.sourceforge.net/Arduino/BMP085-Calcs.pdf
        //tu = 0x69EC;

        a = c5 * (tu - c6);
        *T = a + (mc / (a + md));

    }
    return (result);
}

char BMP180_startPressure(char oversampling)
// Begin a pressure reading.
// Oversampling: 0 to 3, higher numbers are slower, higher-res outputs.
// Will return delay in ms to wait, or 0 if I2C error.
{
    unsigned char data[2], result, delay;

    data[0] = BMP180_REG_CONTROL;

    switch (oversampling) {
        case 0:
            data[1] = BMP180_COMMAND_PRESSURE0;
            delay = 5;
            break;
        case 1:
            data[1] = BMP180_COMMAND_PRESSURE1;
            delay = 8;
            break;
        case 2:
            data[1] = BMP180_COMMAND_PRESSURE2;
            delay = 14;
            break;
        case 3:
            data[1] = BMP180_COMMAND_PRESSURE3;
            delay = 26;
            break;
        default:
            data[1] = BMP180_COMMAND_PRESSURE0;
            delay = 5;
            break;
    }
    result = writeBytes(data, 2);
    if (result) // good write?
        return (delay); // return the delay in ms (rounded up) to wait before retrieving data
    else
        return (0); // or return 0 if there was a problem communicating with the BMP
}

char BMP180_getPressure(double *P, double *T)
// Retrieve a previously started pressure reading, calculate abolute pressure in mbars.
// Requires begin() to be called once prior to retrieve calibration parameters.
// Requires startPressure() to have been called prior and sufficient time elapsed.
// Requires recent temperature reading to accurately calculate pressure.

// P: external variable to hold pressure.
// T: previously-calculated temperature.
// Returns 1 for success, 0 for I2C error.

// Note that calculated pressure value is absolute mbars, to compensate for altitude call sealevel().
{
    unsigned char data[3];
    char result;
    double pu, s, x, y, z;

    data[0] = BMP180_REG_RESULT;

    result = readBytes(data, 3);
    if (result) // good read, calculate pressure
    {
        pu = ((data[0] << 16) + (data[1] << 8) + data[2]) >> 8;

        //example from Bosch datasheet
        //pu = 23843;

        //example from http://wmrx00.sourceforge.net/Arduino/BMP085-Calcs.pdf, pu = 0x982FC0;	
        //pu = (0x98 * 256.0) + 0x2F + (0xC0/256.0);

        s = *T - 25.0;
        x = (x2 * pow(s, 2)) + (x1 * s) + x0;
        y = (y2 * pow(s, 2)) + (y1 * s) + y0;
        z = (pu - x) / y;
        *P = (p2 * pow(z, 2)) + (p1 * z) + p0;        
    }
    return (result);
}

double BMP180_sealevel(double P, double A)
// Given a pressure P (mb) taken at a specific altitude (meters),
// return the equivalent pressure (mb) at sea level.
// This produces pressure readings that can be used for weather measurements.
{
    return (P / pow(1 - (A / 44330.0), 5.255));
}

double BMP180_altitude(double P, double P0)
// Given a pressure measurement P (mb) and the pressure at a baseline P0 (mb),
// return altitude (meters) above baseline.
{
    return (44330.0 * (1 - pow(P / P0, 1 / 5.255)));
}

char BMP180_getError(void)
// If any library command fails, you can retrieve an extended
// error code using this command. Errors are from the wire library: 
// 0 = Success
// 1 = Data too long to fit in transmit buffer
// 2 = Received NACK on transmit of address
// 3 = Received NACK on transmit of data
// 4 = Other error
{
    return (_error);
}

