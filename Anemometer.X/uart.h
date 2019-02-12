/* 
 * File:   uart.h
 * Author: te
 *
 * Created on 13 November 2018, 15:59
 */
#include "Globals.h"
#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

void print_data();
void CfgUart1( void );
void Uart_PrintChr(unsigned char SendDat);
void Uart_PrintStr(const char *str);
void Uart_print_double(double val);
void Uart_println_double(double val);
void Uart_print_int(int val);
void Uart_println_int(int val);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

