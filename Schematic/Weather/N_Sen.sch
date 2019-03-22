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
Text HLabel 3700 3650 0    50   Input ~ 0
J17_P5
Text HLabel 3700 3850 0    50   Input ~ 0
J17_P6
Text HLabel 3700 4050 0    50   Input ~ 0
J17_P7
Text HLabel 3700 4250 0    50   Input ~ 0
J17_P8
$Comp
L Transistor_FET:AO3401 Q2
U 1 1 5C8F913C
P 6300 3600
F 0 "Q2" V 6643 3600 50  0000 C CNN
F 1 "AO3401" V 6552 3600 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6500 3525 50  0001 L CIN
F 3 "" H 6300 3600 50  0001 L CNN
	1    6300 3600
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
L Amplifier_Operational:LM321 U1
U 1 1 5C8F90C7
P 6300 2150
F 0 "U1" H 6300 2631 50  0000 C CNN
F 1 "LM321" H 6300 2540 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 6300 2150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm321.pdf" H 6300 2150 50  0001 C CNN
	1    6300 2150
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5C90C2DD
P 5450 4800
F 0 "R1" V 5243 4800 50  0000 C CNN
F 1 "R" V 5334 4800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5380 4800 50  0001 C CNN
F 3 "~" H 5450 4800 50  0001 C CNN
	1    5450 4800
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5C90E169
P 5850 5250
F 0 "R4" H 5780 5204 50  0000 R CNN
F 1 "R" H 5780 5295 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5780 5250 50  0001 C CNN
F 3 "~" H 5850 5250 50  0001 C CNN
	1    5850 5250
	-1   0    0    1   
$EndComp
$Comp
L Device:R R10
U 1 1 5C90F143
P 7350 4900
F 0 "R10" H 7420 4946 50  0000 L CNN
F 1 "R" H 7420 4855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7280 4900 50  0001 C CNN
F 3 "~" H 7350 4900 50  0001 C CNN
	1    7350 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5C9100FA
P 7050 3900
F 0 "R7" H 7120 3946 50  0000 L CNN
F 1 "R" H 7120 3855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6980 3900 50  0001 C CNN
F 3 "~" H 7050 3900 50  0001 C CNN
	1    7050 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5C912BAF
P 7700 3800
F 0 "R12" H 7770 3846 50  0000 L CNN
F 1 "R" H 7770 3755 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7630 3800 50  0001 C CNN
F 3 "~" H 7700 3800 50  0001 C CNN
	1    7700 3800
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5C913744
P 6300 4150
F 0 "R5" H 6370 4196 50  0000 L CNN
F 1 "R" H 6370 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6230 4150 50  0001 C CNN
F 3 "~" H 6300 4150 50  0001 C CNN
	1    6300 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5C91429E
P 5750 3750
F 0 "R3" H 5820 3796 50  0000 L CNN
F 1 "R" H 5820 3705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5680 3750 50  0001 C CNN
F 3 "~" H 5750 3750 50  0001 C CNN
	1    5750 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5C919740
P 6650 1700
F 0 "R6" H 6720 1746 50  0000 L CNN
F 1 "R" H 6720 1655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6580 1700 50  0001 C CNN
F 3 "~" H 6650 1700 50  0001 C CNN
	1    6650 1700
	-1   0    0    1   
$EndComp
$Comp
L Device:D D2
U 1 1 5C91A5F5
P 7050 2450
F 0 "D2" H 7050 2666 50  0000 C CNN
F 1 "D" H 7050 2575 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 7050 2450 50  0001 C CNN
F 3 "~" H 7050 2450 50  0001 C CNN
	1    7050 2450
	-1   0    0    1   
$EndComp
$Comp
L Device:D D1
U 1 1 5C91BE51
P 7050 2250
F 0 "D1" H 7050 2466 50  0000 C CNN
F 1 "D" H 7050 2375 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 7050 2250 50  0001 C CNN
F 3 "~" H 7050 2250 50  0001 C CNN
	1    7050 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5C902560
P 5750 2150
F 0 "R2" V 5543 2150 50  0000 C CNN
F 1 "R" V 5634 2150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5680 2150 50  0001 C CNN
F 3 "~" H 5750 2150 50  0001 C CNN
	1    5750 2150
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
	6300 3800 6300 3950
Wire Wire Line
	5750 3500 6100 3500
Wire Wire Line
	5750 3600 5750 3500
Wire Wire Line
	5750 3900 5750 3950
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
	6500 3500 7050 3500
Wire Wire Line
	7350 4050 7350 3500
Connection ~ 7350 3500
Wire Wire Line
	7350 3500 7700 3500
$Comp
L Transistor_FET:AO3401 Q3
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
L Device:R R8
U 1 1 5C9120FF
P 7050 4900
F 0 "R8" H 7120 4946 50  0000 L CNN
F 1 "R" H 7120 4855 50  0000 L CNN
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
	7700 3650 7700 3500
Connection ~ 7700 3500
Wire Wire Line
	7700 3500 7950 3500
Wire Wire Line
	7700 3950 7950 3950
Wire Wire Line
	7950 3950 7950 5650
Wire Wire Line
	7050 3750 7050 3500
Connection ~ 7050 3500
Wire Wire Line
	7050 3500 7350 3500
Wire Wire Line
	7050 4050 7050 4250
Connection ~ 7050 4250
Wire Wire Line
	6400 1350 6400 1850
$Comp
L Device:R R11
U 1 1 5C914922
P 7500 2350
F 0 "R11" V 7293 2350 50  0000 C CNN
F 1 "R" V 7384 2350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7430 2350 50  0001 C CNN
F 3 "~" H 7500 2350 50  0001 C CNN
	1    7500 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 2350 7950 2350
Wire Wire Line
	7950 2350 7950 3500
Wire Wire Line
	7200 2250 7200 2350
Wire Wire Line
	7350 2350 7200 2350
Connection ~ 7200 2350
Wire Wire Line
	7200 2350 7200 2450
Wire Wire Line
	6900 2450 6900 2250
Wire Wire Line
	6900 2250 6600 2250
Connection ~ 6900 2250
$Comp
L Device:R R9
U 1 1 5C96EBEA
P 6650 2650
F 0 "R9" H 6720 2696 50  0000 L CNN
F 1 "R" H 6720 2605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6580 2650 50  0001 C CNN
F 3 "~" H 6650 2650 50  0001 C CNN
	1    6650 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2150 6000 2150
Wire Wire Line
	6600 2050 6650 2050
Wire Wire Line
	7950 3500 8350 3500
Connection ~ 7950 3500
Wire Wire Line
	7950 3950 8350 3950
Connection ~ 7950 3950
$Comp
L MyComponents:4_Way_Wire J?
U 1 1 5C97CF3A
P 3950 2850
F 0 "J?" H 4119 2611 50  0000 L CNN
F 1 "4_Way_Wire" H 4119 2520 50  0000 L CNN
F 2 "" H 3850 2900 50  0001 C CNN
F 3 "" H 3850 2900 50  0001 C CNN
	1    3950 2850
	1    0    0    -1  
$EndComp
$Comp
L MyComponents:4_Way_Wire J?
U 1 1 5C97DFDF
P 3950 3650
F 0 "J?" H 4119 3411 50  0000 L CNN
F 1 "4_Way_Wire" H 4119 3320 50  0000 L CNN
F 2 "" H 3850 3700 50  0001 C CNN
F 3 "" H 3850 3700 50  0001 C CNN
	1    3950 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3450 5750 3450
Wire Wire Line
	5750 3450 5750 3500
Connection ~ 5750 3500
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
	3850 2850 4600 2850
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
	4900 2150 5600 2150
Wire Wire Line
	6400 2450 6400 2850
Wire Wire Line
	6400 2850 4600 2850
Connection ~ 4600 2850
Wire Wire Line
	3850 3050 5300 3050
Wire Wire Line
	5300 3050 5300 1350
Wire Wire Line
	5300 1350 6400 1350
Wire Wire Line
	6400 2850 6650 2850
Wire Wire Line
	6650 2850 6650 2800
Connection ~ 6400 2850
Wire Wire Line
	6650 2500 6650 2050
Wire Wire Line
	6400 1350 6650 1350
Wire Wire Line
	6650 1350 6650 1550
Connection ~ 6400 1350
Wire Wire Line
	6650 1850 6650 2050
Connection ~ 6650 2050
$EndSCHEMATC
