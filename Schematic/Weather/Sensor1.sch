EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 13
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3000 2650 0    50   Input ~ 0
J4_P1
Text HLabel 3000 2800 0    50   Input ~ 0
J4_P2
Text HLabel 3000 2950 0    50   Input ~ 0
J4_P3
Text HLabel 3000 3100 0    50   Input ~ 0
J4_P4
Wire Wire Line
	4350 2650 3000 2650
Wire Wire Line
	3000 3100 4050 3100
Wire Wire Line
	3000 2950 3350 2950
Wire Wire Line
	3350 2950 3350 3300
Wire Wire Line
	3350 3300 4900 3300
Wire Wire Line
	3000 2800 3650 2800
Wire Wire Line
	3650 2800 3650 3200
Wire Wire Line
	3650 3200 5000 3200
Wire Wire Line
	5000 3200 5000 3650
Wire Wire Line
	4050 4100 4050 3100
Connection ~ 4050 3100
Wire Wire Line
	4900 3800 4900 3300
Connection ~ 4900 3300
Wire Wire Line
	4900 3300 5150 3300
Wire Wire Line
	4350 3950 4350 3000
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5CAF11D2
P 6950 3000
F 0 "J?" H 7000 3200 50  0000 C CNN
F 1 "Conn_01x04_Male" H 7150 3350 50  0000 C CNN
F 2 "" H 6950 3000 50  0001 C CNN
F 3 "~" H 6950 3000 50  0001 C CNN
	1    6950 3000
	1    0    0    1   
$EndComp
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5CAF34CD
P 6950 4050
F 0 "J?" H 7100 4400 50  0000 R CNN
F 1 "Conn_01x05_Male" H 7600 4650 50  0000 R CNN
F 2 "" H 6950 4050 50  0001 C CNN
F 3 "~" H 6950 4050 50  0001 C CNN
	1    6950 4050
	1    0    0    1   
$EndComp
Wire Wire Line
	5250 3950 4350 3950
Wire Wire Line
	5250 3800 4900 3800
Wire Wire Line
	5000 3650 5250 3650
Wire Wire Line
	5250 4100 4050 4100
$Comp
L Weather-rescue:HTU21-MyComponents MOD?
U 1 1 5C959FE9
P 7650 4050
AR Path="/5C959FE9" Ref="MOD?"  Part="1" 
AR Path="/5C9254A0/5C959FE9" Ref="MOD1"  Part="1" 
F 0 "MOD1" H 8278 4046 50  0000 L CNN
F 1 "HTU21" H 8278 3955 50  0000 L CNN
F 2 "footprint:HTU21" H 7850 3750 50  0001 C CNN
F 3 "" H 7850 3750 50  0001 C CNN
	1    7650 4050
	1    0    0    -1  
$EndComp
$Comp
L MyComponents:BMP180 MOD2
U 1 1 5C958DD2
P 7650 2850
F 0 "MOD2" H 8278 2771 50  0000 L CNN
F 1 "BMP180" H 8278 2680 50  0000 L CNN
F 2 "footprint:BMP180" H 7850 2350 50  0001 C CNN
F 3 "" H 7850 2350 50  0001 C CNN
	1    7650 2850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 5CAF0516
P 6700 3000
F 0 "J?" H 6550 2700 50  0000 L CNN
F 1 "Conn_01x04_Female" H 5950 2600 50  0000 L CNN
F 2 "" H 6700 3000 50  0001 C CNN
F 3 "~" H 6700 3000 50  0001 C CNN
	1    6700 3000
	1    0    0    1   
$EndComp
Connection ~ 5000 3200
Wire Wire Line
	4050 3100 6500 3100
Wire Wire Line
	7150 3100 7350 3100
Wire Wire Line
	7350 3100 7350 3200
Wire Wire Line
	7350 3200 7550 3200
Wire Wire Line
	7150 3000 7450 3000
Wire Wire Line
	7450 3000 7450 3050
Wire Wire Line
	7450 3050 7550 3050
Wire Wire Line
	7150 2900 7550 2900
Wire Wire Line
	7150 2800 7450 2800
Wire Wire Line
	7450 2800 7450 2750
Wire Wire Line
	7450 2750 7550 2750
Wire Wire Line
	6500 3000 4350 3000
Connection ~ 4350 3000
Wire Wire Line
	5000 2800 5000 3200
Wire Wire Line
	5150 2900 5150 3300
Wire Wire Line
	6500 2900 5150 2900
Wire Wire Line
	4350 2650 4350 3000
Wire Wire Line
	5000 2800 6500 2800
$Comp
L Connector:Conn_01x05_Female J?
U 1 1 5CAF2250
P 6750 4050
F 0 "J?" H 6650 3700 50  0000 C CNN
F 1 "Conn_01x05_Female" H 6350 3550 50  0000 C CNN
F 2 "" H 6750 4050 50  0001 C CNN
F 3 "~" H 6750 4050 50  0001 C CNN
	1    6750 4050
	1    0    0    1   
$EndComp
$EndSCHEMATC
