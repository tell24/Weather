/* 
 * File:   MyUart.h
 * Author: terry
 *
 * Created on 07 July 2019, 15:00
 */

#ifndef MYUART_H
#define	MYUART_H

#ifdef	__cplusplus
extern "C" {
#endif

void my_uart_begin();
void my_uart_print_str(char *str);
void my_uart_println_str(char *str);
void my_uart_println_int(int i);
void my_uart_print_int(int i);
void my_uart_println_double(int i);
void my_uart_print_double(int i);
void my_uart_print(char data);
void my_uart_print_HEX(uint32_t hex);


#ifdef	__cplusplus
}
#endif

#endif	/* MYUART_H */

