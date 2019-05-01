/* 
 * File:   RTCC.h
 * Author: terry
 *
 * Created on 01 May 2019, 17:42
 */
#include <xc.h>
#ifndef RTCC_H
#define	RTCC_H

class RTCC {
public:
    RTCC();
    RTCC(const RTCC& orig);
    virtual ~RTCC();
    void init_RTCC();
    void set_RTCC_time_date(uint32_t time, uint32_t date);
private:

};

#endif	/* RTCC_H */

