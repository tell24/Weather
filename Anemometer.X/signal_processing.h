/* 
 * File:   signal_processing.h
 * Author: te
 *
 * Created on 12 December 2018, 15:09
 */
#include "Globals.h"
#ifndef SIGNAL_PROCESSING_H
#define	SIGNAL_PROCESSING_H

#ifdef	__cplusplus
extern "C" {
#endif

    void Init_Filter();
    void add_data(int *dat);
    void calc_zero_point();
    int normalize_data_to_1(fractional * data);
    peak_vals get_peaks(double *d_in, char sign, int start);
    abc_val ExpRegression(peak_vals predicted);
    double find_phase_zero(double *d_in, double x_min);
    double Abs_SpeedOfSound(double Temp, double Rh, double mbar);

#ifdef	__cplusplus
}
#endif

#endif	/* SIGNAL_PROCESSING_H */

