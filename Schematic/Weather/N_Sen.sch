EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 10 10
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3700 2850 0    50   Input ~ 0
J17_P1
Text HLabel 3700 3050 0    50   Input ~ 0
J17_P2
Text HLabel 3700 3250 0    50   Input ~ 0
J17_P3
Text HLabel 3700 3450 0    50   Input ~ 0
J17_P4
Text HLabel 3700 4050 0    50   Input ~ 0
J17_P7
Text HLabel 3700 4250 0    50   Input ~ 0
J17_P8
$Comp
L Weather-rescue:AO3401-Transistor_FET Q2
U 1 1 5C8F913C
P 6300 3550
F 0 "Q2" V 6643 3550 50  0000 C CNN
F 1 "AO3401" V 6552 3550 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6500 3475 50  0001 L CIN
F 3 "" H 6300 3550 50  0001 L CNN
	1    6300 3550
	0    1    -1   0   
$EndComp
$Comp
L Transistor_FET:BSS138 Q1
U 1 1 5C904FFF
P 6200 4800
F 0 "Q1" H 6406 4846 50  0000 L CNN
F 1 "BSS138" H 6406 4755 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6400 4725 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 6200 4800 50  0001 L CNN
	1    6200 4800
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM321 U5
U 1 1 5C8F90C7
P 6050 2150
F 0 "U5" H 6050 2631 50  0000 C CNN
F 1 "LM321" H 6050 2540 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 6050 2150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm321.pdf" H 6050 2150 50  0001 C CNN
	1    6050 2150
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5C90C2DD
P 5450 4800
F 0 "R3" V 5243 4800 50  0000 C CNN
F 1 "2.2K" V 5334 4800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5380 4800 50  0001 C CNN
F 3 "~" H 5450 4800 50  0001 C CNN
	1    5450 4800
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5C90E169
P 5850 5250
F 0 "R6" H 5780 5204 50  0000 R CNN
F 1 "5.1K" H 5780 5295 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5780 5250 50  0001 C CNN
F 3 "~" H 5850 5250 50  0001 C CNN
	1    5850 5250
	-1   0    0    1   
$EndComp
$Comp
L Device:R R14
U 1 1 5C90F143
P 7350 4900
F 0 "R14" H 7420 4946 50  0000 L CNN
F 1 "680" H 7420 4855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7280 4900 50  0001 C CNN
F 3 "~" H 7350 4900 50  0001 C CNN
	1    7350 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5C9100FA
P 7050 3900
F 0 "R12" H 7120 3946 50  0000 L CNN
F 1 "20K" H 7120 3855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6980 3900 50  0001 C CNN
F 3 "~" H 7050 3900 50  0001 C CNN
	1    7050 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5C913744
P 6300 4150
F 0 "R8" H 6370 4196 50  0000 L CNN
F 1 "10K" H 6370 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6230 4150 50  0001 C CNN
F 3 "~" H 6300 4150 50  0001 C CNN
	1    6300 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5C91429E
P 5750 3700
F 0 "R5" H 5820 3746 50  0000 L CNN
F 1 "2.2k" H 5820 3655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5680 3700 50  0001 C CNN
F 3 "~" H 5750 3700 50  0001 C CNN
	1    5750 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 5C919740
P 6400 1700
F 0 "R9" H 6470 1746 50  0000 L CNN
F 1 "4.7K" H 6470 1655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6330 1700 50  0001 C CNN
F 3 "~" H 6400 1700 50  0001 C CNN
	1    6400 1700
	-1   0    0    1   
$EndComp
$Comp
L Device:D D2
U 1 1 5C91A5F5
P 7400 2400
F 0 "D2" V 7450 2600 50  0000 C CNN
F 1 "in916" V 7550 2550 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 7400 2400 50  0001 C CNN
F 3 "~" H 7400 2400 50  0001 C CNN
	1    7400 2400
	0    1    1    0   
$EndComp
$Comp
L Device:D D1
U 1 1 5C91BE51
P 7200 2400
F 0 "D1" V 7150 2600 50  0000 C CNN
F 1 "in916" V 7050 2550 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 7200 2400 50  0001 C CNN
F 3 "~" H 7200 2400 50  0001 C CNN
	1    7200 2400
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 5C902560
P 5500 2150
F 0 "R4" V 5293 2150 50  0000 C CNN
F 1 "4.7K" V 5384 2150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5430 2150 50  0001 C CNN
F 3 "~" H 5500 2150 50  0001 C CNN
	1    5500 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 4800 5850 4800
Wire Wire Line
	5850 4800 5850 5100
Connection ~ 5850 4800
Wire Wire Line
	5850 4800 6000 4800
Wire Wire Line
	5850 5400 5850 5650
Wire Wire Line
	5850 5650 6300 5650
Wire Wire Line
	6300 5000 6300 5650
Connection ~ 6300 5650
Wire Wire Line
	6300 4300 6300 4600
Wire Wire Line
	5750 3450 6100 3450
Wire Wire Line
	5750 3550 5750 3450
Wire Wire Line
	5750 3950 6300 3950
Connection ~ 6300 3950
Wire Wire Line
	6300 3950 6300 4000
Wire Wire Line
	6300 5650 7050 5650
Wire Wire Line
	7350 4450 7350 4750
Wire Wire Line
	7350 5050 7350 5650
Connection ~ 7350 5650
Wire Wire Line
	6500 3450 7050 3450
$Comp
L Weather-rescue:AO3401-Transistor_FET Q3
U 1 1 5C900ECB
P 7250 4250
F 0 "Q3" H 7456 4296 50  0000 L CNN
F 1 "AO3401" H 7456 4205 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7450 4175 50  0001 L CIN
F 3 "" H 7250 4250 50  0001 L CNN
	1    7250 4250
	1    0    0    1   
$EndComp
Wire Wire Line
	7350 5650 7950 5650
$Comp
L Device:R R13
U 1 1 5C9120FF
P 7050 4900
F 0 "R13" H 7120 4946 50  0000 L CNN
F 1 "20K" H 7120 4855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6980 4900 50  0001 C CNN
F 3 "~" H 7050 4900 50  0001 C CNN
	1    7050 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 4250 7050 4750
Wire Wire Line
	7050 5050 7050 5650
Connection ~ 7050 5650
Wire Wire Line
	7050 5650 7350 5650
Wire Wire Line
	7700 3950 7950 3950
Wire Wire Line
	7950 3950 7950 5650
Connection ~ 7050 3450
Wire Wire Line
	7050 4050 7050 4250
Connection ~ 7050 4250
Wire Wire Line
	6150 1350 6150 1850
$Comp
L Device:R R16
U 1 1 5C914922
P 7750 2250
F 0 "R16" V 7543 2250 50  0000 C CNN
F 1 "3.3k" V 7634 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7680 2250 50  0001 C CNN
F 3 "~" H 7750 2250 50  0001 C CNN
	1    7750 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 2550 7300 2550
$Comp
L Device:R R10
U 1 1 5C96EBEA
P 6400 2650
F 0 "R10" H 6470 2696 50  0000 L CNN
F 1 "4.7K" H 6470 2605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6330 2650 50  0001 C CNN
F 3 "~" H 6400 2650 50  0001 C CNN
	1    6400 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2150 5700 2150
Wire Wire Line
	6350 2050 6400 2050
Wire Wire Line
	7950 3950 8350 3950
Connection ~ 7950 3950
Wire Wire Line
	3850 4050 4600 4050
Wire Wire Line
	4600 4050 4600 5650
Wire Wire Line
	4600 5650 5850 5650
Connection ~ 5850 5650
Wire Wire Line
	3850 3650 4600 3650
Wire Wire Line
	4600 3650 4600 4050
Connection ~ 4600 4050
Wire Wire Line
	3850 3250 4600 3250
Wire Wire Line
	4600 3250 4600 3650
Connection ~ 4600 3650
Wire Wire Line
	4600 2850 4600 3250
Connection ~ 4600 3250
Wire Wire Line
	3850 3850 5100 3850
Wire Wire Line
	5100 3850 5100 4800
Wire Wire Line
	5100 4800 5300 4800
Wire Wire Line
	3850 4250 4900 4250
Wire Wire Line
	4900 4250 4900 2150
Wire Wire Line
	6150 2450 6150 2850
Wire Wire Line
	6150 2850 4600 2850
Wire Wire Line
	3850 3050 5300 3050
Wire Wire Line
	5300 3050 5300 1350
Wire Wire Line
	6150 2850 6400 2850
Wire Wire Line
	6400 2850 6400 2800
Connection ~ 6150 2850
Wire Wire Line
	6150 1350 6400 1350
Wire Wire Line
	6400 1350 6400 1550
Connection ~ 6150 1350
Wire Wire Line
	6400 1850 6400 2050
Connection ~ 6400 2050
Wire Wire Line
	7200 2250 7400 2250
Wire Wire Line
	7300 2550 7300 2850
Connection ~ 7300 2550
Wire Wire Line
	7300 2550 7200 2550
Wire Wire Line
	7900 2250 7950 2250
Wire Wire Line
	7400 2250 7600 2250
Connection ~ 7400 2250
$Comp
L Device:C C4
U 1 1 5C96A149
P 6900 2250
F 0 "C4" V 6648 2250 50  0000 C CNN
F 1 "0.1uF" V 6739 2250 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 6938 2100 50  0001 C CNN
F 3 "~" H 6900 2250 50  0001 C CNN
	1    6900 2250
	0    1    1    0   
$EndComp
Text Label 7300 2850 0    50   ~ 0
0v
Text Label 6150 1300 0    50   ~ 0
5v
Wire Wire Line
	4900 2150 5350 2150
Wire Wire Line
	5300 1350 6150 1350
Wire Wire Line
	3850 2850 4600 2850
Connection ~ 4600 2850
Text Label 5800 3450 0    50   ~ 0
24v
$Comp
L Device:R R11
U 1 1 5C96E23C
P 6600 2250
F 0 "R11" V 6393 2250 50  0000 C CNN
F 1 "4.7K" V 6484 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6530 2250 50  0001 C CNN
F 3 "~" H 6600 2250 50  0001 C CNN
	1    6600 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 2050 6400 2500
Wire Wire Line
	6350 2250 6450 2250
Wire Wire Line
	7050 2250 7200 2250
Connection ~ 7200 2250
Wire Wire Line
	6400 2850 7300 2850
Connection ~ 6400 2850
$Comp
L Device:R R7
U 1 1 5C97DE0F
P 5900 2500
F 0 "R7" V 5693 2500 50  0000 C CNN
F 1 "4.7K" V 5784 2500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5830 2500 50  0001 C CNN
F 3 "~" H 5900 2500 50  0001 C CNN
	1    5900 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 2500 5700 2500
Wire Wire Line
	5700 2500 5700 2150
Connection ~ 5700 2150
Wire Wire Line
	5700 2150 5750 2150
Wire Wire Line
	6050 2500 6350 2500
Wire Wire Line
	6350 2500 6350 2250
Connection ~ 6350 2250
Wire Wire Line
	3850 2850 3700 2850
Connection ~ 3850 2850
Wire Wire Line
	3850 3050 3700 3050
Connection ~ 3850 3050
Wire Wire Line
	3850 3250 3700 3250
Connection ~ 3850 3250
Wire Wire Line
	3850 3650 3700 3650
Connection ~ 3850 3650
Wire Wire Line
	3850 3850 3700 3850
Connection ~ 3850 3850
Wire Wire Line
	3850 4050 3700 4050
Connection ~ 3850 4050
Wire Wire Line
	3700 4250 3850 4250
Connection ~ 3850 4250
Text HLabel 3700 3850 0    50   Input ~ 0
J17_P6
Text HLabel 3700 3650 0    50   Input ~ 0
J17_P5
$Comp
L MyComponents:4_Way_Wire J3
U 1 1 5C97DFDF
P 3950 3650
F 0 "J3" H 3900 2950 50  0000 L CNN
F 1 "4_Way_Wire" H 3750 2800 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3850 3700 50  0001 C CNN
F 3 "" H 3850 3700 50  0001 C CNN
	1    3950 3650
	1    0    0    -1  
$EndComp
$Comp
L MyComponents:4_Way_Wire J2
U 1 1 5C97CF3A
P 3950 2850
F 0 "J2" H 3900 3000 50  0000 L CNN
F 1 "4_Way_Wire" H 3800 3100 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3850 2900 50  0001 C CNN
F 3 "" H 3850 2900 50  0001 C CNN
	1    3950 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3850 5750 3950
Wire Wire Line
	6300 3750 6300 3950
Wire Wire Line
	3700 3450 3850 3450
Connection ~ 5750 3450
Connection ~ 3850 3450
Wire Wire Line
	3850 3450 5750 3450
$Comp
L power:GNDS #PWR0101
U 1 1 5CFCB28B
P 8350 3950
F 0 "#PWR0101" H 8350 3700 50  0001 C CNN
F 1 "GNDS" H 8355 3777 50  0000 C CNN
F 2 "" H 8350 3950 50  0001 C CNN
F 3 "" H 8350 3950 50  0001 C CNN
	1    8350 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3450 7050 3750
Connection ~ 7700 3450
Wire Wire Line
	7050 3450 7350 3450
Connection ~ 7350 3450
Wire Wire Line
	7700 3450 7700 3650
$Comp
L Device:R R15
U 1 1 5C912BAF
P 7700 3800
F 0 "R15" H 7770 3846 50  0000 L CNN
F 1 "47K" H 7770 3755 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7630 3800 50  0001 C CNN
F 3 "~" H 7700 3800 50  0001 C CNN
	1    7700 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	7350 3450 7350 4050
Wire Wire Line
	7350 3450 7700 3450
Wire Wire Line
	7700 3450 7950 3450
Wire Wire Line
	7950 3450 8350 3450
Wire Wire Line
	7950 2250 7950 3450
$Comp
L power:Vdrive #PWR02
U 1 1 5C99BC4B
P 8350 3450
F 0 "#PWR02" H 8150 3300 50  0001 C CNN
F 1 "Vdrive" H 8367 3623 50  0000 C CNN
F 2 "" H 8350 3450 50  0001 C CNN
F 3 "" H 8350 3450 50  0001 C CNN
	1    8350 3450
	1    0    0    -1  
$EndComp
Connection ~ 7950 3450
$EndSCHEMATC
