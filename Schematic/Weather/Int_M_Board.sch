EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 11 15
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2600 3750 0    50   Input ~ 0
J0_P1
Text HLabel 2600 3400 0    50   Input ~ 0
J0_P2
Wire Wire Line
	2600 3750 2700 3750
Wire Wire Line
	2950 3750 2950 4250
Wire Wire Line
	2950 4250 4000 4250
$Comp
L MyComponents:AMS1117 U8
U 1 1 5CB0A6F0
P 3550 2500
F 0 "U8" V 3050 2450 60  0000 L CNN
F 1 "AMS1117" V 4050 2300 60  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 3550 2500 60  0001 C CNN
F 3 "" H 3550 2500 60  0000 C CNN
	1    3550 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 2750 4000 4250
Wire Wire Line
	4200 2500 4000 2500
Wire Wire Line
	2950 3400 2950 1900
Wire Wire Line
	2950 1900 4000 1900
Wire Wire Line
	4000 1900 4000 2250
$Comp
L Device:C C6
U 1 1 5CB0A6FC
P 4400 4100
F 0 "C6" H 4515 4146 50  0000 L CNN
F 1 "0.1uF" H 4515 4055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 4438 3950 50  0001 C CNN
F 3 "~" H 4400 4100 50  0001 C CNN
	1    4400 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 3400 2700 3400
$Comp
L Device:CP C5
U 1 1 5CB0A703
P 2950 3600
F 0 "C5" H 3068 3646 50  0000 L CNN
F 1 "47uF" H 3068 3555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D5.0mm_P2.50mm" H 2988 3450 50  0001 C CNN
F 3 "~" H 2950 3600 50  0001 C CNN
	1    2950 3600
	1    0    0    -1  
$EndComp
Connection ~ 2950 3750
$Comp
L Device:CP C7
U 1 1 5CB0A70A
P 4800 4100
F 0 "C7" H 4918 4146 50  0000 L CNN
F 1 "47uF" H 4918 4055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D5.0mm_P2.50mm" H 4838 3950 50  0001 C CNN
F 3 "~" H 4800 4100 50  0001 C CNN
	1    4800 4100
	1    0    0    -1  
$EndComp
Connection ~ 4400 4250
Wire Wire Line
	4400 4250 4800 4250
Wire Wire Line
	4200 3700 4400 3700
Wire Wire Line
	4000 4250 4400 4250
Connection ~ 4000 4250
Wire Wire Line
	4800 3950 4800 3700
Wire Wire Line
	4400 3950 4400 3700
Connection ~ 4400 3700
Wire Wire Line
	4400 3700 4800 3700
Text Label 3450 2400 0    50   ~ 0
3.3v
$Comp
L Device:R R58
U 1 1 5CB0A721
P 5300 2650
F 0 "R58" H 5370 2696 50  0000 L CNN
F 1 "4.7K" H 5370 2605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5230 2650 50  0001 C CNN
F 3 "~" H 5300 2650 50  0001 C CNN
	1    5300 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R57
U 1 1 5CB0A727
P 5050 2650
F 0 "R57" H 5120 2696 50  0000 L CNN
F 1 "4.7K" H 5120 2605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4980 2650 50  0001 C CNN
F 3 "~" H 5050 2650 50  0001 C CNN
	1    5050 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 2500 5050 2500
Connection ~ 5050 2500
Wire Wire Line
	2950 3450 2950 3400
Connection ~ 2950 3400
$Comp
L Mechanical:MountingHole_Pad H19
U 1 1 5CB0A73F
P 2700 3300
F 0 "H19" H 2800 3349 50  0000 L CNN
F 1 "MountingHole_Pad" H 2800 3258 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 2700 3300 50  0001 C CNN
F 3 "~" H 2700 3300 50  0001 C CNN
	1    2700 3300
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H20
U 1 1 5CB0A745
P 2700 3650
F 0 "H20" H 2800 3699 50  0000 L CNN
F 1 "MountingHole_Pad" H 2800 3608 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 2700 3650 50  0001 C CNN
F 3 "~" H 2700 3650 50  0001 C CNN
	1    2700 3650
	1    0    0    -1  
$EndComp
Connection ~ 2700 3750
Wire Wire Line
	2700 3750 2950 3750
Connection ~ 2700 3400
Wire Wire Line
	2700 3400 2950 3400
Wire Wire Line
	4200 2500 5050 2500
Wire Wire Line
	4850 3900 4850 3700
Wire Wire Line
	4850 3700 4800 3700
Connection ~ 4800 3700
Connection ~ 4200 2500
Wire Wire Line
	4200 2500 4200 3700
Wire Wire Line
	5050 2800 5050 3800
Wire Wire Line
	5300 2800 5300 3700
Text HLabel 10250 1600 2    50   Input ~ 0
J1_P1
Text HLabel 10250 1800 2    50   Input ~ 0
J1_P2
Text HLabel 10250 2000 2    50   Input ~ 0
J1_P3
Text HLabel 10250 2400 2    50   Input ~ 0
J1_P5
Text HLabel 10300 4050 2    50   Input ~ 0
J2_P4
Text HLabel 10300 3850 2    50   Input ~ 0
J2_P3
Text HLabel 10300 3650 2    50   Input ~ 0
J2_P2
Text HLabel 10300 3450 2    50   Input ~ 0
J2_P1
$Comp
L Connector:Conn_01x05_Female J1
U 1 1 5CB40D1B
P 9000 1950
F 0 "J1" H 8950 2300 50  0000 L CNN
F 1 "Conn_01x05_Female" H 8750 1500 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9000 1950 50  0001 C CNN
F 3 "~" H 9000 1950 50  0001 C CNN
	1    9000 1950
	1    0    0    -1  
$EndComp
Text HLabel 10250 2200 2    50   Input ~ 0
J1_P4
Connection ~ 4800 4250
Wire Wire Line
	4800 4250 7000 4250
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5CAF2DD7
P 9050 3700
F 0 "J2" H 8950 3400 50  0000 L CNN
F 1 "Conn_01x04_Female" H 8550 3950 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9050 3700 50  0001 C CNN
F 3 "~" H 9050 3700 50  0001 C CNN
	1    9050 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 3700 5300 3700
Wire Wire Line
	6250 4000 6250 3700
Wire Wire Line
	6850 4000 6250 4000
Wire Wire Line
	6850 4700 6850 4000
Wire Wire Line
	7150 3700 6850 3700
Wire Wire Line
	7150 4100 7150 3700
Wire Wire Line
	6700 4100 7150 4100
Wire Wire Line
	6700 4700 6700 4100
Connection ~ 6250 3700
Wire Wire Line
	6350 3700 6250 3700
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J3
U 1 1 5CB2F470
P 6550 3700
F 0 "J3" H 6600 4017 50  0000 C CNN
F 1 "Conn_02x04_Odd_Even" H 6900 4100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 6550 3700 50  0001 C CNN
F 3 "~" H 6550 3700 50  0001 C CNN
	1    6550 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3600 7450 4250
Wire Wire Line
	6850 3600 7450 3600
Wire Wire Line
	5050 3800 6100 3800
Wire Wire Line
	7300 3800 6850 3800
Wire Wire Line
	7300 4400 7300 3800
Wire Wire Line
	7300 4400 6400 4400
Wire Wire Line
	6100 3800 6100 4200
Connection ~ 6100 3800
Wire Wire Line
	6350 3800 6100 3800
Wire Wire Line
	6550 4200 6550 4700
Wire Wire Line
	6100 4200 6550 4200
Wire Wire Line
	6400 4400 6400 4700
Wire Wire Line
	5400 3900 4850 3900
Wire Wire Line
	6250 4500 6250 4700
Wire Wire Line
	5400 4500 5400 3900
Wire Wire Line
	6250 4500 5400 4500
Connection ~ 5400 3900
Wire Wire Line
	6350 3900 5400 3900
Wire Wire Line
	7000 4700 7000 4250
Connection ~ 7000 4250
Wire Wire Line
	7450 4250 7000 4250
Text HLabel 6250 4700 3    50   Input ~ 0
J3_P6
Text HLabel 6400 4700 3    50   Input ~ 0
J3_P5
Text HLabel 6550 4700 3    50   Input ~ 0
J3_P4
Text HLabel 6700 4700 3    50   Input ~ 0
J3_P3
Text HLabel 6850 4700 3    50   Input ~ 0
J3_P2
Text HLabel 7000 4700 3    50   Input ~ 0
J3_P1
Wire Wire Line
	10250 1600 8050 1600
Wire Wire Line
	8050 1750 8800 1750
Wire Wire Line
	8050 1750 8050 3300
Wire Wire Line
	8050 3600 8850 3600
Connection ~ 8050 1750
Wire Wire Line
	10300 3450 10300 3300
Wire Wire Line
	10300 3300 8050 3300
Connection ~ 8050 3300
Wire Wire Line
	8050 3300 8050 3600
Wire Wire Line
	7450 3600 8050 3600
Connection ~ 7450 3600
Connection ~ 8050 3600
Wire Wire Line
	8800 2050 8500 2050
Wire Wire Line
	7700 2050 7700 1900
Wire Wire Line
	7700 1900 4000 1900
Connection ~ 4000 1900
Wire Wire Line
	8850 3900 8550 3900
Wire Wire Line
	7700 3900 7700 2050
Connection ~ 7700 2050
Wire Wire Line
	10250 2200 9950 2200
Wire Wire Line
	9950 2250 8500 2250
Wire Wire Line
	8500 2250 8500 2050
Connection ~ 8500 2050
Wire Wire Line
	8500 2050 7700 2050
Wire Wire Line
	10300 4050 8550 4050
Wire Wire Line
	8550 4050 8550 3900
Connection ~ 8550 3900
Wire Wire Line
	8550 3900 7700 3900
Wire Wire Line
	8800 1950 8500 1950
Wire Wire Line
	6100 1950 6100 3800
Wire Wire Line
	8800 1850 8400 1850
Wire Wire Line
	6250 1850 6250 3700
Wire Wire Line
	8850 3700 8700 3700
Wire Wire Line
	8400 3700 8400 1850
Connection ~ 8400 1850
Wire Wire Line
	8400 1850 6250 1850
Wire Wire Line
	8850 3800 8700 3800
Wire Wire Line
	8200 3800 8200 1950
Connection ~ 8200 1950
Wire Wire Line
	8200 1950 6100 1950
Wire Wire Line
	10300 3650 10300 3500
Wire Wire Line
	10300 3500 8700 3500
Wire Wire Line
	8700 3500 8700 3700
Connection ~ 8700 3700
Wire Wire Line
	8700 3700 8400 3700
Wire Wire Line
	10300 3850 8700 3850
Wire Wire Line
	8700 3850 8700 3800
Connection ~ 8700 3800
Wire Wire Line
	8700 3800 8200 3800
Wire Wire Line
	8050 1600 8050 1750
Wire Wire Line
	9950 2200 9950 2250
Wire Wire Line
	10250 1800 8400 1800
Wire Wire Line
	8400 1800 8400 1850
Wire Wire Line
	10250 2000 8500 2000
Wire Wire Line
	8500 2000 8500 1950
Connection ~ 8500 1950
Wire Wire Line
	8500 1950 8200 1950
$EndSCHEMATC
