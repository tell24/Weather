/* 
 * File:   HTU21D.h
 * Author: terry
 *
 * Created on 23 July 2019, 17:36
 */

#include <stdbool.h>

#ifndef HTU21D_H
#define	HTU21D_H


#define HTU21DF_I2CADDR       0x80
#define HTU21DF_READADDR      0x81
#define HTU21DF_READTEMP      0xE3
#define HTU21DF_READHUM       0xE5
#define HTU21DF_WRITEREG      0xE6
#define HTU21DF_READREG       0xE7
#define HTU21DF_RESET         0xFE

bool HTU21DF_begin(void);
double HTU21DF_readTemperature(void);
double HTU21DF_readHumidity(void);
void HTU21DF_reset(void);
bool HTU21DF_readData(void);
double hum, temp;

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* HTU21D_H */

