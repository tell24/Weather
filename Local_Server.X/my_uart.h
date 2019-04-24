/* 
 * File:   my_uart.h
 * Author: te
 *
 * Created on 22 December 2018, 15:34
 */

#ifndef MY_UART_H
#define	MY_UART_H

class my_uart {
public:
    my_uart();
    my_uart(const my_uart& orig);
    virtual ~my_uart();
    void begin(uint16_t baud);
    void print(char data);
    void print(char *str);
    void println(char *str);
    void print(int num);
    void println(int num);

private:

};
extern my_uart Serial;

#endif	/* MY_UART_H */

