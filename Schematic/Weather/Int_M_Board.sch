EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 14 14
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2400 3550 0    50   Input ~ 0
J2_P1
Text HLabel 2400 3200 0    50   Input ~ 0
J2_P2
Text HLabel 6800 4500 3    50   Input ~ 0
J3_P1
Text HLabel 6650 4500 3    50   Input ~ 0
J3_P2
Text HLabel 6500 4500 3    50   Input ~ 0
J3_P3
Text HLabel 6350 4500 3    50   Input ~ 0
J3_P4
Wire Wire Line
	2400 3550 2500 3550
Wire Wire Line
	2750 3550 2750 4050
Wire Wire Line
	2750 4050 3800 4050
$Comp
L MyComponents:AMS1117 U1
U 1 1 5CB0A6F0
P 3350 2300
F 0 "U1" V 2850 2250 60  0000 L CNN
F 1 "AMS1117" V 3850 2100 60  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 3350 2300 60  0001 C CNN
F 3 "" H 3350 2300 60  0000 C CNN
	1    3350 2300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3800 2550 3800 4050
Wire Wire Line
	4000 2300 3800 2300
Wire Wire Line
	2750 3200 2750 1700
Wire Wire Line
	2750 1700 3800 1700
Wire Wire Line
	3800 1700 3800 2050
$Comp
L Device:C C2
U 1 1 5CB0A6FC
P 4200 3900
F 0 "C2" H 4315 3946 50  0000 L CNN
F 1 "0.1uF" H 4315 3855 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 4238 3750 50  0001 C CNN
F 3 "~" H 4200 3900 50  0001 C CNN
	1    4200 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 3200 2500 3200
$Comp
L Device:CP C1
U 1 1 5CB0A703
P 2750 3400
F 0 "C1" H 2868 3446 50  0000 L CNN
F 1 "47uF" H 2868 3355 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D5.0mm_P2.50mm" H 2788 3250 50  0001 C CNN
F 3 "~" H 2750 3400 50  0001 C CNN
	1    2750 3400
	1    0    0    -1  
$EndComp
Connection ~ 2750 3550
$Comp
L Device:CP C3
U 1 1 5CB0A70A
P 4600 3900
F 0 "C3" H 4718 3946 50  0000 L CNN
F 1 "47uF" H 4718 3855 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D5.0mm_P2.50mm" H 4638 3750 50  0001 C CNN
F 3 "~" H 4600 3900 50  0001 C CNN
	1    4600 3900
	1    0    0    -1  
$EndComp
Connection ~ 4200 4050
Wire Wire Line
	4200 4050 4600 4050
Wire Wire Line
	4000 3500 4200 3500
Wire Wire Line
	3800 4050 4200 4050
Connection ~ 3800 4050
Wire Wire Line
	4600 3750 4600 3500
Wire Wire Line
	4200 3750 4200 3500
Connection ~ 4200 3500
Wire Wire Line
	4200 3500 4600 3500
Text Label 3250 2200 0    50   ~ 0
3.3v
$Comp
L Device:R R2
U 1 1 5CB0A721
P 5100 2450
F 0 "R2" H 5170 2496 50  0000 L CNN
F 1 "4.7K" H 5170 2405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5030 2450 50  0001 C CNN
F 3 "~" H 5100 2450 50  0001 C CNN
	1    5100 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CB0A727
P 4850 2450
F 0 "R1" H 4920 2496 50  0000 L CNN
F 1 "4.7K" H 4920 2405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4780 2450 50  0001 C CNN
F 3 "~" H 4850 2450 50  0001 C CNN
	1    4850 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2300 4850 2300
Connection ~ 4850 2300
Wire Wire Line
	2750 3250 2750 3200
Connection ~ 2750 3200
$Comp
L Mechanical:MountingHole_Pad H17
U 1 1 5CB0A73F
P 2500 3100
F 0 "H17" H 2600 3149 50  0000 L CNN
F 1 "MountingHole_Pad" H 2600 3058 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 2500 3100 50  0001 C CNN
F 3 "~" H 2500 3100 50  0001 C CNN
	1    2500 3100
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H18
U 1 1 5CB0A745
P 2500 3450
F 0 "H18" H 2600 3499 50  0000 L CNN
F 1 "MountingHole_Pad" H 2600 3408 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 2500 3450 50  0001 C CNN
F 3 "~" H 2500 3450 50  0001 C CNN
	1    2500 3450
	1    0    0    -1  
$EndComp
Connection ~ 2500 3550
Wire Wire Line
	2500 3550 2750 3550
Connection ~ 2500 3200
Wire Wire Line
	2500 3200 2750 3200
Text HLabel 6200 4500 3    50   Input ~ 0
J3_P5
Text HLabel 6050 4500 3    50   Input ~ 0
J3_P6
Wire Wire Line
	7250 4050 6800 4050
Connection ~ 4600 4050
Wire Wire Line
	6800 4500 6800 4050
Connection ~ 6800 4050
Wire Wire Line
	6800 4050 4600 4050
Wire Wire Line
	4000 2300 4850 2300
Wire Wire Line
	4650 3700 4650 3500
Wire Wire Line
	4650 3500 4600 3500
Connection ~ 4600 3500
Wire Wire Line
	6150 3700 5200 3700
Wire Wire Line
	6050 4300 5200 4300
Wire Wire Line
	5200 4300 5200 3700
Wire Wire Line
	6050 4300 6050 4500
Connection ~ 5200 3700
Wire Wire Line
	5200 3700 4650 3700
Wire Wire Line
	6200 4200 6200 4500
Wire Wire Line
	5900 4000 6350 4000
Wire Wire Line
	6350 4000 6350 4500
Wire Wire Line
	6150 3600 5900 3600
Connection ~ 5900 3600
Wire Wire Line
	5900 3600 5900 4000
Wire Wire Line
	7100 4200 6200 4200
Wire Wire Line
	7100 4200 7100 3600
Wire Wire Line
	7100 3600 6650 3600
Connection ~ 4000 2300
Wire Wire Line
	4000 2300 4000 3500
Wire Wire Line
	4850 3600 5900 3600
Wire Wire Line
	4850 2600 4850 3600
Wire Wire Line
	6650 3400 7250 3400
Wire Wire Line
	7250 3400 7250 4050
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J15
U 1 1 5CB2F470
P 6350 3500
F 0 "J15" H 6400 3817 50  0000 C CNN
F 1 "Conn_02x04_Odd_Even" H 6400 3726 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 6350 3500 50  0001 C CNN
F 3 "~" H 6350 3500 50  0001 C CNN
	1    6350 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3500 6050 3500
Wire Wire Line
	5100 2600 5100 3500
Wire Wire Line
	6500 4500 6500 3900
Wire Wire Line
	6500 3900 6950 3900
Wire Wire Line
	6950 3900 6950 3500
Wire Wire Line
	6950 3500 6650 3500
Wire Wire Line
	6650 4500 6650 3800
Wire Wire Line
	6650 3800 6050 3800
Wire Wire Line
	6050 3800 6050 3500
Connection ~ 6050 3500
Wire Wire Line
	6050 3500 5100 3500
$EndSCHEMATC
