/*********************************************************************
 *
 *  Generic TCP Client Example Application
 *  Module for Microchip TCP/IP Stack
 *   -Implements an example HTTP client and should be used as a basis 
 *	  for creating new TCP client applications
 *	 -Reference: None.  Hopefully AN833 in the future.
 *
 *********************************************************************
 * FileName:        GenericTCPClient.c
 * Dependencies:    TCP, DNS, ARP, Tick
 * Processor:       PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 * Compiler:        Microchip C32 v1.05 or higher
 *					Microchip C30 v3.12 or higher
 *					Microchip C18 v3.30 or higher
 *					HI-TECH PICC-18 PRO 9.63PL2 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2009 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date    Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder     8/01/06	Original
 ********************************************************************/
#define __GENERICTCPCLIENT_C

#include "TCPIPConfig.h"
#include "main.h"
#include <stdbool.h>
#include <peripheral/rtcc.h>

#if defined(STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE)

#include "TCPIP Stack/TCPIP.h"

#if defined(TESTING)
static BYTE ServerName[] = "192.168.0.39";
#else
static BYTE ServerName[] = "192.168.0.27";
#endif

static WORD ServerPort = HTTP_PORT;

// Defines the URL to be requested by this HTTP client

/*****************************************************************************
  Function:
    void GenericTCPClient(void)

  Summary:
    Implements a simple HTTP client (over TCP).

  Description:
    This function implements a simple HTTP client, which operates over TCP.  
    The function is called periodically by the stack, and waits for BUTTON1 
    to be pressed.  When the button is pressed, the application opens a TCP
    connection to an Internet search engine, performs a search for the word
    "Microchip" on "microchip.com", and prints the resulting HTML page to
    the UART.
	
    This example can be used as a model for many TCP and HTTP client
    applications.

  Precondition:
    TCP is initialized.

  Parameters:
    None

  Returns:
    None
 ***************************************************************************/
BYTE TCPClient(BYTE type) {
    BYTE i;
    WORD w;
    BYTE vBuffer[150];
    BYTE data_buf[32];
    BYTE status = 0;
    _Bool completed;
    static DWORD Timer;
    static TCP_SOCKET MySocket = INVALID_SOCKET;

    static enum _GenericTCPExampleState {
        SM_HOME = 0,
        SM_SOCKET_OBTAINED,
#if defined(STACK_USE_SSL_CLIENT)
        SM_START_SSL,
#endif
        SM_PROCESS_RESPONSE,
        SM_DISCONNECT,
        SM_DONE
    } GenericTCPExampleState = SM_DONE;

    switch (GenericTCPExampleState) {
        case SM_HOME:
            completed = false;
            // Connect a socket to the remote TCP server
            MySocket = TCPOpen((DWORD) & ServerName[0], TCP_OPEN_RAM_HOST, ServerPort, TCP_PURPOSE_GENERIC_TCP_CLIENT);

            // Abort operation if no TCP socket of type TCP_PURPOSE_GENERIC_TCP_CLIENT is available
            // If this ever happens, you need to go add one to TCPIPConfig.h
            if (MySocket == INVALID_SOCKET)
                break;


#if defined(STACK_USE_MY_UART)
            putrsUART1((ROM char*) "CLIENT OBTAINED...\r\n");
#endif

            GenericTCPExampleState++;
            Timer = TickGet();
            break;

        case SM_SOCKET_OBTAINED:

            // Wait for the remote server to accept our connection request
            if (!TCPIsConnected(MySocket)) {
                // Time out if too much time is spent in this state
                if (TickGet() - Timer > 5 * TICK_SECOND) {
                    // Close the socket so it can be used by other modules
                    TCPDisconnect(MySocket);
                    MySocket = INVALID_SOCKET;
                    GenericTCPExampleState--;
                    status = 1;
                    return;
                }
                break;
            }

            Timer = TickGet();

            WORD PutReady = TCPIsPutReady(MySocket);
#if defined(STACK_USE_MY_UART)   
            my_uart_println_int((int) PutReady);
#endif
            // Make certain the socket can be written to
            if (PutReady < 125u)
                break;

            // Place the application protocol data into the transmit buffer.  For this example, we are connected to an HTTP server, so we'll send an HTTP GET request.
            switch (type) {
                case CURRENT_DATA:
                    WEB_data_0.out_temp = outsidedata.temp;
                    WEB_data_0.in_temp = inside.t * 100;
                    WEB_data_0.out_hum = outsidedata.hum;
                    WEB_data_0.in_hum = inside.h * 100;
                    WEB_data_0.wind_speed = outsidedata.wind_speed;
                    WEB_data_0.peak_wind_speed = outsidedata.peak_wind_speed;
                    WEB_data_0.bearing = outsidedata.bearing;
                    WEB_data_0.pressure = pressure;
                    WEB_data_0.rainfall = outsidedata.rain;
                    WEB_data_0.rainfall_rate = outsidedata.rain;
                    WEB_data_0.timestamp = unixtime(now);
                    TCPPutROMString(MySocket, (ROM BYTE*) "POST /0 HTTP/1.0\r\nHost: ");
                    TCPPutString(MySocket, ServerName);
                    TCPPutROMString(MySocket, (ROM BYTE*) "\r\nContent-Length: 24\r\n");
                    TCPPutROMString(MySocket, (ROM BYTE*) "\r\nConnection: close\r\n\r\n");
                    TCPPutROMArray(MySocket, &WEB_data_0, 24);
                    break;

                case HISTORY_DATA:
                    TCPPutROMString(MySocket, (ROM BYTE*) "POST /1 HTTP/1.0\r\nHost: ");
                    TCPPutString(MySocket, ServerName);
                    TCPPutROMString(MySocket, (ROM BYTE*) "\r\nContent-Length: 32\r\n");
                    TCPPutROMString(MySocket, (ROM BYTE*) "\r\nConnection: close\r\n\r\n");
                    TCPPutROMArray(MySocket, &History, 32);
                    break;
                case GET_REMOTE:
                    TCPPutROMString(MySocket, (ROM BYTE*) "GET /2 HTTP/1.0\r\n");
                    TCPPutROMString(MySocket, (ROM BYTE*) "Host: ");
                    TCPPutString(MySocket, ServerName);
                    TCPPutROMString(MySocket, (ROM BYTE*) "\r\nConnection: close\r\n\r\n");
                    break;
            }
            // Send the packet
            TCPFlush(MySocket);
            GenericTCPExampleState++;
            break;

        case SM_PROCESS_RESPONSE:
            // Check to see if the remote node has disconnected from us or sent us any application data
            // If application data is available, write it to the UART
            if (!TCPIsConnected(MySocket)) {
                GenericTCPExampleState = SM_DISCONNECT;


#if defined(STACK_USE_MY_UART)
                putrsUART1((ROM char*) "SM_DISCONNECT...\r\n");
#endif
                // Do not break;  We might still have data in the TCP RX FIFO waiting for us
            }

            // Get count of RX bytes waiting
            w = TCPIsGetReady(MySocket);

            // Obtian and print the server reply
            i = sizeof (vBuffer) - 1;
            vBuffer[i] = '\0';
            while (w) {
                if (w < i) {
                    i = w;
                    vBuffer[i] = '\0';
                }
                w -= TCPGetArray(MySocket, vBuffer, i);


                // putsUART is a blocking call which will slow down the rest of the stack 
                // if we shovel the whole TCP RX FIFO into the serial port all at once.  
                // Therefore, let's break out after only one chunk most of the time.  The 
                // only exception is when the remote node disconncets from us and we need to 
                // use up all the data before changing states.
                if (GenericTCPExampleState == SM_PROCESS_RESPONSE) {
                    switch (type) {
                        case GET_REMOTE:
                            if (i == 18) {
                                memcpy(&outsidedata, &vBuffer, 18);
#if defined(STACK_USE_MY_UART)                  
                                my_uart_println_str("Remote Data ");
                                my_uart_println_int(outsidedata.hum);
                                my_uart_println_int(outsidedata.temp);
                                my_uart_println_int(outsidedata.bearing);
                                my_uart_println_int(outsidedata.wind_speed);
                                my_uart_println_int(outsidedata.peak_wind_speed);
                                my_uart_println_int(outsidedata.rain);
                                my_uart_println_int(outsidedata.rssi);
                                my_uart_println_int(outsidedata.status);
#endif
                            }
                            completed = true;
                            break;
defualt:
#if defined(STACK_USE_MY_UART)   
                            my_uart_print((char) vBuffer[0]);
                            my_uart_print((char) vBuffer[1]);
                            my_uart_print((char) vBuffer[2]);
                            my_uart_print((char) vBuffer[3]);
                            my_uart_println_str(" ");
                            my_uart_println_int(vBuffer[0]);
                            my_uart_println_int(vBuffer[1]);
                            my_uart_println_int(vBuffer[2]);
                            my_uart_println_int(vBuffer[3]);
#endif
                            break;
                    }
                    break;
                }
            }

            break;

        case SM_DISCONNECT:
#if defined(STACK_USE_MY_UART)
            putrsUART1((ROM char*) "CLIENT DIS...\r\n");
#endif
            // Close the socket so it can be used by other modules
            // For this application, we wish to stay connected, but this state will still get entered if the remote server decides to disconnect
            TCPDisconnect(MySocket);
            MySocket = INVALID_SOCKET;
            GenericTCPExampleState = SM_DONE;
            break;

        case SM_DONE:
            // Do nothing unless the user pushes BUTTON1 and wants to restart the whole connection/download process
            //	if(BUTTON1_IO == 0u)
            GenericTCPExampleState = SM_HOME;
            status = 1;
            if (completed) status = 2;
            break;
    }
    return status;
}

#endif	//#if defined(STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE)
