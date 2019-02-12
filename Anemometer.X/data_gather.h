/* 
 * File:   data_gather.h
 * Author: terry
 *
 * Created on 14 December 2018, 09:08
 */
#include "Globals.h"


#ifndef DATA_GATHER_H
#define	DATA_GATHER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    void get_wind_data();
    void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void);
    void __attribute__((interrupt, no_auto_psv)) _T4Interrupt(void);
    void __attribute__((interrupt, no_auto_psv)) _DMA0Interrupt(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DATA_GATHER_H */

