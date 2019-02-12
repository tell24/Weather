/* 
 * File:   utils.h
 * Author: te
 *
 * Created on 12 December 2018, 14:58
 */

#include <stdint.h>

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

void delay_uS( int delay);
void delay_mS( int delay);
uint8_t Sum(uint8_t *message, int nBytes);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

