/* 
 * File:   main.h
 * Author: terry
 *
 * Created on 04 July 2019, 16:00
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#define SaveAppConfig(a)
    
    
// An actual function defined in MainDemo.c for displaying the current IP 
// address on the UART and/or LCD.

void DisplayIPValue(IP_ADDR IPVal);
void Set_Clock();
_Bool Set_DST(DWORD time);
// Define a header structure for validating the AppConfig data structure in EEPROM/Flash
typedef struct
{
	unsigned short wConfigurationLength;	// Number of bytes saved in EEPROM/Flash (sizeof(APP_CONFIG))
	unsigned short wOriginalChecksum;		// Checksum of the original AppConfig defaults as loaded from ROM (to detect when to wipe the EEPROM/Flash record of AppConfig due to a stack change, such as when switching from Ethernet to Wi-Fi)
	unsigned short wCurrentChecksum;		// Checksum of the current EEPROM/Flash data.  This protects against using corrupt values if power failure occurs while writing them and helps detect coding errors in which some other task writes to the EEPROM in the AppConfig area.
} NVM_VALIDATION_STRUCT;


typedef struct data_packet {
  int temp;
  int hum;
  int wind_speed;
  int peak_wind_speed;
  int bearing;
  unsigned char checksum;
} remotedata;

 extern remotedata outsidedata  __attribute__((far));

#define DO_NOTHING     0 
#define GET_INCOMMING  1
#define GET_TIME       2
#define UPLOAD_DATA    3 

 extern BYTE process_item ;

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */
