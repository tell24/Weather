/* 
 * File:   RTCC.cpp
 * Author: terry
 * 
 * Created on 01 May 2019, 17:42
 */

#include "RTCC.h"

RTCC::RTCC() {
}

RTCC::RTCC(const RTCC& orig) {
}

RTCC::~RTCC() {
}

void RTCC::init_RTCC(){

  SYSKEY = 0x0; // ensure OSCCON is locked
SYSKEY = 0xAA996655; // Write Key1 to SYSKEY
SYSKEY = 0x556699AA; // Write Key2 to SYSKEY
// OSCCON is now unlocked
// make the desired change
OSCCONbits.SOSCEN = 1; // enable Secondary Oscillator
// Relock the SYSKEY
   RTCCONbits.RTCWREN = 1;
   RTCCONbits.RTSECSEL = 1;
   RTCCONbits.RTCOE = 1;
   RTCCONbits.ON = 1; // turn off the RTCC
SYSKEY = 0x0; // Write any value other tha
while(RTCCONbits.RTCCLKON == 0); // wait f


}


void RTCC::set_RTCC_time_date(uint32_t time, uint32_t date){

  __builtin_enable_interrupts();
while((RTCCON&0x4)!=0); // wait for not RTCSYNC
RTCTIME=time; // safe to update the time
RTCDATE=date; // update the date
  __builtin_disable_interrupts();
}