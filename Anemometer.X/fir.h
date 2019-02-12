/* 
 * File:   fir.h
 * Author: te
 *
 * Created on 13 November 2018, 15:16
 */
#include "Globals.h"

#ifndef FIR_H
#define	FIR_H

#ifdef	__cplusplus
extern "C" {
#endif


    ////////////////////////////////////////
     // FIR Coeffecient Buffer 40KHz Band Pass Project
    //
        
      fractional coeffecients[NY] __attribute__ ((space(xmemory),far)) = {  // wider band pass
0xFFF3	,0xFF71	,0xFEE6	,0xFEB4	,0xFF1C	,0xFFD8	,0x000F	,0xFEC3	,0xFB99	,0xF78F	,
0xF4E7	,0xF622	,0xFC78	,0x06B4	,0x1157	,0x181B	,0x181B	,0x1157	,0x06B4	,0xFC78	,
0xF622	,0xF4E7	,0xF78F	,0xFB99	,0xFEC3	,0x000F	,0xFFD8	,0xFF1C	,0xFEB4	,0xFEE6	,
0xFF71	,0xFFF3	};
  

    // FIR Delay Buffer
    fractional z[NY] __attribute__((space(ymemory), far));
    //fractional z[NY] __attribute__((space(ymemory), address(0x9000)));







#ifdef	__cplusplus
}
#endif

#endif	/* FIR_H */

