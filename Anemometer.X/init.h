/* 
 * File:   init.h
 * Author: te
 *
 * Created on 12 December 2018, 14:51
 */
#include "Globals.h"

#ifndef INIT_H
#define	INIT_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    byte start_measurement;
     request_data requestdata;
     request_debug requestdebug;

     remotedatapacket remote_data;

   //  byte measurement_type;
     byte return_data;
     byte start_measurement;
     byte measure;

    void init_board();


#ifdef	__cplusplus
}
#endif

#endif	/* INIT_H */

