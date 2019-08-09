/*********************************************************************
 *
 *	Generic TCP Server Example Application
 *  Module for Microchip TCP/IP Stack
 *   -Implements an example "ToUpper" TCP server on port 9760 and 
 *	  should be used as a basis for creating new TCP server 
 *    applications
 *
 *********************************************************************
 * FileName:        GenericTCPServer.c
 * Dependencies:    TCP
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
 * Author               Date    	Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder     10/19/06	Original
 * Microchip            08/11/10    Added ability to close session by
 *                                  pressing the ESCAPE key.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Description of how to run the demo:
 *   1) Connect the ethernet port of the programmed demo board to a 
 *        computer either directly or through a router.
 *   2) Determine the IP address of the demo board.  This can be done several
 *        different ways.
 *      a) If you are using a demo setup with an LCD display (e.g. Explorer 16
 *           or PICDEM.net 2), the IP address should be displayed on the second
 *           line of the display.
 *      b) Open the Microchip Ethernet Device Discoverer from the start menu.
 *           Press the "Discover Devices" button to see the addresses and host
 *           names of all devices with the Announce Protocol enabled on your
 *           network.  You may have to configure your computer's firewall to 
 *           prevent it from blocking UDP port 30303 for this solution.
 *      c) If your board is connected directly with your computer with a
 *           crossover cable: 
 *              1) Open a command/DOS prompt and type 'ipconfig'.  Find the 
 *                   network adaptor that is connected to the board.  The IP
 *                   address of the board is located in the 'Default Gateway'
 *                   field
 *              2) Open up the network status for the network adaptor that
 *                   connects the two devices.  This can be done by right clicking
 *                   on the network connection icon in the network settings folder 
 *                   and select 'status' from the menu. Find the 'Default Gateway'
 *                   field.
 *   3) Open a command/DOS prompt.  Type "telnet ip_address 9760" where
 *        ip_address is the IP address that you got from step 2.
 *   4) As you type characters, they will be echoed back in your command prompt
 *        window in UPPER CASE.
 *   5) Press Escape to end the demo.
 *
 ********************************************************************/
#define __GENERICTCPSERVER_C

#include "TCPIPConfig.h"
#include <string.h>
#include <stdint.h>

#if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)

#include "TCPIP Stack/TCPIP.h"
#include "main.h"


// Defines which port the server will listen on
#define SERVER_PORT	80

/*****************************************************************************
  Function:
    void GenericTCPServer(void)

  Summary:
    Implements a simple ToUpper TCP Server.

  Description:
    This function implements a simple TCP server.  The function is invoked
    periodically by the stack to listen for incoming connections.  When a 
    connection is made, the server reads all incoming data, transforms it
    to uppercase, and echos it back.
	
    This example can be used as a model for many TCP server applications.

  Precondition:
    TCP is initialized.

  Parameters:
    None

  Returns:
    None
 ***************************************************************************/

void GenericTCPServer(int *TCP_status, DWORD *post_data_size) {
    BYTE i, c, lc, lc2;
    WORD w, w2;
    BYTE AppBuffer[512];
    WORD wMaxGet, wMaxPut, wCurrentChunk;
    int POST = 0;
    int a_index = 0;
    DWORD ds = *post_data_size;
    static TCP_SOCKET MySocket;

    static enum _TCPServerState {
        SM_HOME = 0,
        SM_LISTENING,
        SM_GET,
        SM_HOMEPAGE,
        SM_CURRENT,
        SM_DIS,
        SM_POST,
        SM_Wait_DataSize,
        SM_DataSize,
        SM_Proc_Data
    } TCPServerState = SM_HOME;

    switch (TCPServerState) {
        case SM_HOME:
            *TCP_status = 0;
            // Allocate a socket for this server to listen and accept connections on
            MySocket = TCPOpen(0, TCP_OPEN_SERVER, SERVER_PORT, TCP_PURPOSE_GENERIC_TCP_SERVER);
            if (MySocket == INVALID_SOCKET) {
                *TCP_status = 0;
                //  return 0;
                ds = 0;
                break;
            }
            putrsUART2((ROM char*) "SOCKET OBTAINED...\r\n");
            TCPServerState = SM_LISTENING;
            *TCP_status = 1;

        case SM_LISTENING:
            // See if anyone is connected to us
            if (!TCPIsConnected(MySocket)) {
                *TCP_status = 0;
                TCPServerState = SM_LISTENING;
                break;
            }
            putrsUART2((ROM char*) "SOCKET CONNECTED...\r\n");
            TCPServerState = SM_GET;
            *TCP_status = 2;
            *post_data_size = 0;

            break;

        case SM_GET:
            if (!TCPIsConnected(MySocket)) {
                putrsUART2((ROM char*) "SOCKET BROKEN...\r\n");
                *TCP_status = 1;
                break;
            }
            if (TCPIsGetReady(MySocket)) {

                putrsUART((ROM char*) "SOCKET GET READY...\r\n");
                while (TCPGet(MySocket, &c)) {

                    AppBuffer[a_index] = c;
                    a_index++;
                }

                if (((AppBuffer[0] == 'G')&&(AppBuffer[1] == 'E'))) {

                    switch (AppBuffer[5]) {
                        case ' ':
                            TCPServerState = SM_HOMEPAGE;
                            break;
                        case '0':
                            TCPServerState = SM_CURRENT;
                            break;
                        case '1':
                            break;
                        case '2':
                            break;
                        case 'f':
                            TCPServerState = SM_POST;
                            break;
                        default:
                            TCPServerState = SM_HOMEPAGE;
                            break;
                    }
                    *TCP_status = 2;
                    *post_data_size = 0;
                    break;
                }
                if (((AppBuffer[0] == 'P')&&(AppBuffer[1] == 'O'))) {
                    TCPServerState = SM_Wait_DataSize;
                    *TCP_status = 2;
                    *post_data_size = 0;
                    break;
                }
            }
            break;

        case SM_Wait_DataSize:
            if (TCPIsGetReady(MySocket)) {
                a_index = 0;
                // 	putrsUART((ROM char*)"SOCKET GET READY...\r\n");
                while (TCPGet(MySocket, &c)) {
                    AppBuffer[a_index] = c;
                    a_index++;
                }
            }
            if ((AppBuffer[0] == 'C')&&(AppBuffer[1] == 'o')&&(AppBuffer[8] == 'L')) {
                TCPServerState = SM_DataSize;
                *TCP_status = 2;
                *post_data_size = 0;
            }

            break;

        case SM_DataSize:
            if (TCPIsGetReady(MySocket)) {
                a_index = 0;
                // 	putrsUART((ROM char*)"SOCKET GET READY...\r\n");
                while (TCPGet(MySocket, &c)) {
                    AppBuffer[a_index] = c;
                    a_index++;
                }

                if ((AppBuffer[0] == '\r') && (AppBuffer[1] == '\n')) break;
                AppBuffer[a_index] = 0;
                TCPServerState = SM_Proc_Data;
                *TCP_status = 2;
                *post_data_size = atoi(AppBuffer);
            }
            break;

        case SM_Proc_Data:
            if (TCPIsGetReady(MySocket)) {
                a_index = 0;
                // 	putrsUART((ROM char*)"SOCKET GET READY...\r\n");
                while (TCPGet(MySocket, &c)) {
                    AppBuffer[a_index] = (BYTE) c;
                    a_index++;
                }
            }
            if (a_index >= ds) {
                int ii = 0;
                //    outsidedata.temp = 0;
                memcpy(&outsidedata, &AppBuffer, ds);
                my_uart_println_str("");
                my_uart_println_int(outsidedata.temp);
                my_uart_println_int(outsidedata.hum);
                my_uart_println_int(outsidedata.wind_speed);
                my_uart_println_int(outsidedata.peak_wind_speed);
                my_uart_println_int(outsidedata.bearing);
                my_uart_println_int(outsidedata.rain);
                my_uart_println_str("");
                
                outside.t = (double)outsidedata.temp/10;
                outside.h = (double)outsidedata.hum/10;
                TCPServerState = SM_POST;
                *TCP_status = 2;
                *post_data_size = 0;
            }
            break;

        case SM_HOMEPAGE:
            //  putrsUART2((ROM char*) "SOCKET PUT...\r\n");
            if (TCPIsPutReady(MySocket)) {
                DWORD offset = *post_data_size;
                MPFS_HANDLE f = MPFSOpen("index.htm");
                DWORD fs = MPFSGetSize(f);
                DWORD sent = fs - offset;
                MPFSSeek(f, offset, MPFS_SEEK_FORWARD);
                if (offset == 0) {
                    char buf[30];
                    sprintf(&buf, "Content-Length: %010d\r\n", fs);
                    TCPPutROMString(MySocket, (ROM BYTE*) "HTTP/1.1 200 OK\r\n");
                    TCPPutROMString(MySocket, (ROM BYTE*) "Content-Type: text/html\r\n");
                    TCPPutROMArray(MySocket, &buf, 28);
                    TCPPutROMString(MySocket, (ROM BYTE*) "Pragma: no-cache\r\n");
                    TCPPutROMString(MySocket, (ROM BYTE*) "Connection: close\r\n");
                    TCPPutROMString(MySocket, (ROM BYTE*) "\r\n");
                    TCPFlush(MySocket);
                }
                do {
                    if (sent > 256) {
                        if (TCPIsPutReady(MySocket) < 256) {
                            *post_data_size = offset;
                            MPFSClose(f);
                            return;
                        }
                        WORD st = MPFSGetArray(f, &AppBuffer, 256);
                        sent -= 256;
                        offset += 256;
                        TCPPutROMArray(MySocket, &AppBuffer, 256);
                        TCPFlush(MySocket);
                        *post_data_size = offset;
                    } else break;
                } while (true);
                if (TCPIsPutReady(MySocket) < 256) {
                    *post_data_size = offset;
                    MPFSClose(f);
                    return;
                }
                if (sent > 0) {
                    WORD st = MPFSGetArray(f, &AppBuffer, sent);
                    TCPPutROMArray(MySocket, &AppBuffer, sent);
                    TCPFlush(MySocket);
                }
                MPFSClose(f);

                TCPServerState = SM_DIS;

                *TCP_status = 2;
                *post_data_size = 0;
            }
            break;

        case SM_CURRENT:
            if (TCPIsPutReady(MySocket)) {
                char buf[100];
                /*
                  int out_temp;
        int in_temp;
        int out_hum;
        int in_hum;
        int wind_speed;
        int peak_wind_speed;
        int bearing;
        int pressure;
        int rainfall;
        int rainfall_rate;
                 */

                struct tm;
                rtccTime tm;
                tm.l = RtccGetTime();
                WEB_data_0.out_temp = outsidedata.temp;
                WEB_data_0.in_temp = inside.t * 10;
                WEB_data_0.out_hum = outsidedata.hum;
                WEB_data_0.in_hum = inside.h * 10;
                WEB_data_0.wind_speed = outsidedata.wind_speed;
                WEB_data_0.peak_wind_speed = outsidedata.peak_wind_speed;
                WEB_data_0.bearing = outsidedata.bearing;
                WEB_data_0.pressure = pressure;
                WEB_data_0.rainfall = outsidedata.rain;
                WEB_data_0.rainfall_rate = outsidedata.rain;


                TCPPutROMString(MySocket, (ROM BYTE*) "HTTP/1.1 200 OK\r\n");
                TCPPutROMString(MySocket, (ROM BYTE*) "Content-Type: application/zip \r\n");
                TCPPutROMString(MySocket, (ROM BYTE*) "Content-Length: 20\r\n");
                TCPPutROMString(MySocket, (ROM BYTE*) "Connection: close\r\n");
                TCPPutROMString(MySocket, (ROM BYTE*) "\r\n");
                memcpy(&buf, &WEB_data_0, 20);
                TCPPutROMArray(MySocket, &buf, 20);
                TCPFlush(MySocket);
            }


            TCPServerState = SM_DIS;

            *TCP_status = 2;
            *post_data_size = 0;
            break;

        case SM_POST:

            putrsUART((ROM char*) "SOCKET POST...\r\n");
            TCPPutROMString(MySocket, (ROM BYTE*) "HTTP/1.1 200 OK\r\n");
            TCPPutROMString(MySocket, (ROM BYTE*) "Content-Type: text/html\r\n");
            TCPPutROMString(MySocket, (ROM BYTE*) "Connection: close\r\n");
            TCPPutROMString(MySocket, (ROM BYTE*) "\r\n");
            TCPFlush(MySocket);

            TCPServerState = SM_DIS;
            *TCP_status = 2;
            *post_data_size = 0;
            break;

        case SM_DIS:
            if (TCPIsPutReady(MySocket)) {
                putrsUART((ROM char*) "SOCKET DIS...\r\n");
                TCPDisconnect(MySocket);
                TCPClose(MySocket);
                DelayMs(100);
                TCPServerState = SM_HOME;
                *TCP_status = 0;
                *post_data_size = 0;
            }
            break;
    }
}

#endif //#if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)
