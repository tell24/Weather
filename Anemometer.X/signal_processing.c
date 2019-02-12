#include<xc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <dsp.h>
#include <math.h>
#include "signal_processing.h"
//#include "uart.h"
#include "utils.h"
#include "fir.h"
#include <p33EP256GP502.h>



int accumulative_bearing = 0;
double accumulative_ws = 0;
int tx_sequence = 0;
int tx_trig = 0;
int direction = 0;
int16_t bearing;
FIRStruct firfilter;
fractional FSignal[ARRAYSIZE] __attribute__((far));
fractional FSignal_1[ARRAYSIZE] __attribute__((far));

abc_val Exp_formula_pos, Exp_formula_neg;
peak_vals predicted;

void Init_Filter() {

    // IIR module initialisation
    IIRTransposedInit(&BPFFilter);

    // FIR Filter structure initialization
    FIRStructInit(&firfilter, NY, coeffecients, 0xFF00, (fractional*) z);
    FIRDelayInit(&firfilter);

};

void add_data(int *dat) {
    T3CONbits.TON = 0;
    IFS0bits.T3IF = 0;
    IEC1bits.T4IE = 0; // Disable Timer4 interrupt
    IFS1bits.T4IF = 0;
    IFS0bits.DMA0IF = 0; //Clear the DMA interrupt flag bit
    IEC0bits.DMA0IE = 0; //Set the DMA interrupt enable bit

    LATBbits.LATB10 = 0;
    LATBbits.LATB11 = 0;
    LATBbits.LATB12 = 0;
    LATBbits.LATB13 = 0;

    int i = 0;
    if (samples == 0) {
        do {
            int_signal[i] = dat[i];
            i++;
        } while (i < ARRAYSIZE);
    } else {
        do {
            int_signal[i] += dat[i];
            i++;
        } while (i < ARRAYSIZE);
    }
    if (samples == 5) {
        samples = 0;
        calc_zero_point();
    } else samples++;

    TMR2 = 0;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1; // Enable Timer1 interrupt
}

void calc_zero_point() {
    samples = 0;
    T3CONbits.TON = 0;
    IFS0bits.T3IF = 0;
    IEC1bits.T4IE = 0; // Disable Timer4 interrupt
    IFS1bits.T4IF = 0;
    IFS0bits.DMA0IF = 0; //Clear the DMA interrupt flag bit
    IEC0bits.DMA0IE = 0; //Clear the DMA interrupt enable bit
    IFS0bits.T2IF = 0;
    int i = 0;
    int x_peak = 0;

    // convert to fractional for Filter
    do {
        FSignal[i] = Float2Fract((float) int_signal[i] / 20480);
        i++;
    } while (i < ARRAYSIZE);
    i = 0;

    //        **************************  FIR Filter instruction  *******************************
    FIR(ARRAYSIZE, &FSignal_1[0], &FSignal[0], &firfilter); // FIR filtering on buffer

    //        **************************  IIR Filter instruction  *******************************
    IIRTransposed(ARRAYSIZE, &FSignal[i], &FSignal_1[0], &BPFFilter);

    //      ************ convert and normalise *************************

    x_peak = normalize_data_to_1(&FSignal[0]);

    // clear int_signal array
    i = 0;
    do {
        int_signal[i] = 0;
        i++;
    } while (i < ARRAYSIZE);

    i = 0;

    // if signal is large enough proceed
   
        predicted = get_peaks(&signal[0], '+', x_peak);
        if (predicted.found == false) goto MyLabel;

        Exp_formula_pos = ExpRegression(predicted);
        predicted = get_peaks(&signal[0], '-', x_peak);
        if (predicted.found == false) goto MyLabel;

        Exp_formula_neg = ExpRegression(predicted);
        double x_zero = 0;
        double x_zero1p = (-Exp_formula_pos.b + sqrt(pow(Exp_formula_pos.b, 2) - 4 * Exp_formula_pos.c * Exp_formula_pos.a)) / (2 * Exp_formula_pos.c);
        double x_zero1n = (-Exp_formula_neg.b - sqrt(pow(Exp_formula_neg.b, 2) - 4 * Exp_formula_neg.c * Exp_formula_neg.a)) / (2 * Exp_formula_neg.c);

        double min_x = (x_zero1p + x_zero1n)*0.5;
        x_zero = find_phase_zero(&signal[0], min_x);

        switch (direction) {
            case 0:
                ns_zero = x_zero;
                direction++;
                break;
            case 1:
                sn_zero = x_zero;
                direction++;
                break;
            case 2:
                ew_zero = x_zero;
                direction++;
                break;
            case 3:
                passes++;
                we_zero = x_zero;
                direction = 0;
                double t = requestdata.temp / 10;
                double h = requestdata.hum / 10;
                double p = requestdata.pressure;
                double SOS = Abs_SpeedOfSound(t, h, p);
                double TOF = 0.5 / SOS;
                ws = ((SOS - (0.5 / ((sqrt(pow(ns_zero - sn_zero, 2) + pow(0, 2)) / 2)*(1 / 500e3) + TOF)))*((3600 * 1.093613) / 1760)) * 100;

                if ((ew_zero - we_zero) != 0) {
                    bearing = (int16_t) (atan((ew_zero - we_zero) / (ns_zero - sn_zero))*57.295);

                    if (sn_zero > ns_zero)
                        bearing += 180;
                    else
                        if (ew_zero < we_zero) bearing += 360;
                }

                accumulative_bearing += bearing;
                accumulative_ws += ws;
                if (ws >= remote_data.peak_wind_speed)remote_data.peak_wind_speed = (int) ws;
                if (passes > 20) {
                    T2CONbits.TON = 0;
                    T3CONbits.TON = 0;
                    T4CONbits.TON = 0;
                    IFS0bits.T3IF = 0;
                    IEC1bits.T4IE = 0; // Disable Timer4 interrupt
                    IFS1bits.T4IF = 0;
                    IFS0bits.DMA0IF = 0; //Clear the DMA interrupt flag bit
                    IEC0bits.DMA0IE = 0; //Clear the DMA interrupt enable bit
                    IFS0bits.T2IF = 0;
                    IEC0bits.T2IE = 0; // Enable Timer1 interrupt
                    remote_data.bearing = (int) ((double) accumulative_bearing / passes);
                    remote_data.wind_speed = (int) ((double) accumulative_ws / passes);
                }
                delay_mS(1000);
                break;
        }

   

MyLabel: // if you jump here then speed/bearing not calculated

    IFS0bits.T2IF = 0;

}

int normalize_data_to_1(fractional * data) {
    int x = 0;
    int x_peak;
    double max_signal = 0;
    double mean_signal = 0;
    //*************  move data to double type array  *************************
    do {
        signal[x] = (double) data[x]*3.051757813e-05;
        mean_signal += signal[x];
        x++;
    } while (x < ARRAYSIZE);
    x = 0;
    mean_signal /= ARRAYSIZE;
    do {
        signal[x] -= mean_signal;
        x++;
    } while (x < ARRAYSIZE);
    x = 0;
    double scale = 0;
    double max_s = 0;
    //*************  scale to signals to 1  *************************
    //
    do {
        if (signal[x] > max_s) {
            max_s = signal[x];
            x_peak = x;
        }
        if (-signal[x] > max_s) {
            max_s = -signal[x];
            x_peak = x;
        }
        x++;
    } while (x < ARRAYSIZE);
    max_signal = max_s;
    scale = 1.0 / max_s;
    x = 0;
    do {
        signal[x] *= scale;
        x++;
    } while (x < ARRAYSIZE);
    if (scale > 15)  remote_data.status = 8;
    return x_peak;
}

peak_vals get_peaks(double *d_in, char sign, int start) {
    peak_vals dis;
    dis.found = true;
    int point = 0;
    int sample = 0;
    double mean = 0.1;
    if (sign == '+') {
        sample = start - 140;
        while (d_in[sample] < mean) sample++;

        point = 0;

        while ((point < 6)&(sample < 1024)) {
            if (d_in[sample] >= d_in[sample - 1])
                sample++;
            else {
                if (d_in[sample - 1] > mean) {
                    dis.arr[point][0] = (double) sample - 1;
                    dis.arr[point][1] = (d_in[sample - 1]);
                    point++;
                }
                sample += 4;
            }
        }
    } else {
        sample = start - 140;
        while (d_in[sample] > -mean) sample++;

        point = 0;

        while ((point < 6)&(sample < 1024)) {
            if (d_in[sample] <= d_in[sample - 1])
                sample++;
            else {
                if (d_in[sample - 1] < -mean) {
                    dis.arr[point][0] = (double) sample - 1;
                    dis.arr[point][1] = (d_in[sample - 1]);
                    point++;
                }
                sample += 8;
            }
        }
    }
    dis.points = point;

    if (point < 4)  dis.found = false;
    return dis;
}

abc_val ExpRegression(peak_vals predicted) {
    abc_val form;
    long double s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0;
    int i = 0;
    int n = predicted.points;
    while (i < n) {
        long double x = (long double) predicted.arr[i][0];
        long double y = (long double) predicted.arr[i][1];
        s1 += x;
        s2 += x * x;
        s3 += x * x * x;
        s4 += x * x * x * x;
        s5 += y;
        s6 += x * y;
        s7 += x * x * y;
        i++;
    }

    long double denom, a, b, c;

    denom = (double) n * (s2 * s4 - s3 * s3) -
            s1 * (s1 * s4 - s2 * s3) +
            s2 * (s1 * s3 - s2 * s2);
    a = (s5 * (s2 * s4 - s3 * s3) -
            s6 * (s1 * s4 - s2 * s3) +
            s7 * (s1 * s3 - s2 * s2)) / denom;

    b = ((double) n * (s6 * s4 - s3 * s7) -
            s1 * (s5 * s4 - s7 * s2) +
            s2 * (s5 * s3 - s6 * s2)) / denom;

    c = ((double) n * (s2 * s7 - s6 * s3) -
            s1 * (s1 * s7 - s5 * s3) +
            s2 * (s1 * s6 - s5 * s2)) / denom;

    form.a = (double) a;
    form.b = (double) b;
    form.c = (double) c;

    return form;
}

double find_phase_zero(double *d_in, double x_min) {
    double phase_zero = 0;
    int count = x_min;
    int phase_count = 0;

    if (d_in[count ] >= 0)
        while (count < ARRAYSIZE) {
            if (d_in[count ] < 0) {
                phase_zero = count - 1 + (d_in[count - 1] / (d_in[count - 1 ] - d_in[count]));
                break;
            }
            count++;
            phase_count++;
        } else
        while (count >= 0) {
            if (d_in[count ] > 0) {
                phase_zero = count + (d_in[count] / (d_in[count ] - d_in[count + 1]));
                break;
            }
            count--;
        }

    return phase_zero;
}

double Abs_SpeedOfSound(double Temp, double Rh, double mbar) {
    double e = 2.71828182845905;
    double T_Kel = Temp + 273.15;
    double P = mbar * 0.133322 * 1000;
    double ENH = 3.141593 * pow(10, -8) * P + 1.00062 + pow(Temp, 2) * 5.6 * pow(10, -7);
    double PSV1 = pow(T_Kel, 2) * 1.2378847 * pow(10, -5) - 1.9121316 * pow(10, -2) * T_Kel;
    double PSV2 = 33.93711047 - 6.3431645 * pow(10, 3) / T_Kel;
    double PSV = pow(e, PSV1) * pow(e, PSV2);
    double H = Rh * ENH * PSV / P;
    double Xw = H / 100;
    double Xc = 400 * pow(10, -6);
    double C1 = 0.603055 * Temp + 331.5024 - pow(Temp, 2)* 5.28 * pow(10, -4) + (0.1495874 * Temp + 51.471935 - pow(Temp, 2) * 7.82 * pow(10, -4)) * Xw;
    double C2 = (-1.82 * pow(10, -7) + 3.73 * pow(10, -8) * Temp - pow(Temp, 2) * 2.93 * pow(10, -10)) * P + (-85.20931 - 0.228525 * Temp + pow(Temp, 2) * 5.91 * pow(10, -5)) * Xc;
    double C3 = pow(Xw, 2) * 2.835149 - pow(P, 2) * 2.15 * pow(10, -13) + pow(Xc, 2) * 29.179762 + 4.86 * pow(10, -4) * Xw * P * Xc;
    double C = C1 + C2 - C3;
    return C;
}
