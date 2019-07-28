#include "HTU21D.h"
#include "I2C.h"

bool HTU21DF_begin(void) {

    HTU21DF_reset();
    I2C_start();
    I2C_write(HTU21DF_I2CADDR, _ack);
    I2C_write(HTU21DF_READREG, _ack);
        I2C_start();
        I2C_write(HTU21DF_READADDR, _ack);
        uint8_t buf = I2C_read(_nack); // after reset should be 0x2

        I2C_stop(); /* Send stop condition */
        if (buf == 2)return true;
    return false;
}

void HTU21DF_reset(void) {
    I2C_start();
    I2C_write(HTU21DF_I2CADDR, _ack);
    I2C_write(HTU21DF_RESET, _ack);
    I2C_stop();
    DelayMs(15);
}

double HTU21DF_readTemperature(void) {

    // OK lets ready!

    I2C_start();
    I2C_write(HTU21DF_I2CADDR, _ack);
    I2C_write(HTU21DF_READTEMP, _ack);
    
        DelayMs(50); // add delay between request and actual read!
I2C_start();
        I2C_write(HTU21DF_READADDR, _nack);
        uint16_t t = I2C_read(_ack);
        t <<= 8;
        t |= I2C_read(_ack);

        uint8_t crc = I2C_read(_nack);
        I2C_stop();

        temp = t;
        temp *= 175.72;
        temp /= 65536;
        temp -= 46.85;

        return temp;
}

double HTU21DF_readHumidity(void) {
    // OK lets ready!

    I2C_start();
    I2C_write(HTU21DF_I2CADDR, _ack);
    I2C_write(HTU21DF_READHUM, _ack);
        DelayMs(50); // add delay between request and actual read!

        I2C_start();
        I2C_write(HTU21DF_READADDR, _nack);
        uint16_t h = I2C_read(_ack);
        h <<= 8;
        h |= I2C_read(_ack);

        uint8_t crc = I2C_read(_nack);
        I2C_stop();

        hum = h;
        hum *= 125;
        hum /= 65536;
        hum -= 6;

        return hum;
}

