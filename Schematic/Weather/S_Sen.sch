EESchema Schematic File Version 4
LIBS:Weather-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 10 15
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2900 2200 0    50   Input ~ 0
J18_P1
Text HLabel 2900 2300 0    50   Input ~ 0
J18_P2
Text HLabel 2900 2400 0    50   Input ~ 0
J18_P3
Text HLabel 2900 3650 0    50   Input ~ 0
J18_P4
$Comp
L Weather-rescue:AO3401-Transistor_FET Q?
U 1 1 5CA288FA
P 6000 3750
AR Path="/5C952539/5CA288FA" Ref="Q?"  Part="1" 
AR Path="/5C9F4D88/5CA288FA" Ref="Q5"  Part="1" 
F 0 "Q5" V 6343 3750 50  0000 C CNN
F 1 "AO3401" V 6252 3750 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6200 3675 50  0001 L CIN
F 3 "" H 6000 3750 50  0001 L CNN
	1    6000 3750
	0    1    -1   0   
$EndComp
$Comp
L Transistor_FET:BSS138 Q?
U 1 1 5CA28900
P 5900 5000
AR Path="/5C952539/5CA28900" Ref="Q?"  Part="1" 
AR Path="/5C9F4D88/5CA28900" Ref="Q4"  Part="1" 
F 0 "Q4" H 6106 5046 50  0000 L CNN
F 1 "BSS138" H 6106 4955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6100 4925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 5900 5000 50  0001 L CNN
	1    5900 5000
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM321 U?
U 1 1 5CA28906
P 5750 2350
AR Path="/5C952539/5CA28906" Ref="U?"  Part="1" 
AR Path="/5C9F4D88/5CA28906" Ref="U5"  Part="1" 
F 0 "U5" H 5750 2831 50  0000 C CNN
F 1 "LM321" H 5750 2740 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 5750 2350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm321.pdf" H 5750 2350 50  0001 C CNN
	1    5750 2350
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5CA2890C
P 5150 5000
AR Path="/5C952539/5CA2890C" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA2890C" Ref="R15"  Part="1" 
F 0 "R15" V 4943 5000 50  0000 C CNN
F 1 "2.2K" V 5034 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 5080 5000 50  0001 C CNN
F 3 "~" H 5150 5000 50  0001 C CNN
	1    5150 5000
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5CA28912
P 5550 5450
AR Path="/5C952539/5CA28912" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA28912" Ref="R18"  Part="1" 
F 0 "R18" H 5480 5404 50  0000 R CNN
F 1 "5.1K" H 5480 5495 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 5480 5450 50  0001 C CNN
F 3 "~" H 5550 5450 50  0001 C CNN
	1    5550 5450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5CA28918
P 7050 5100
AR Path="/5C952539/5CA28918" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA28918" Ref="R26"  Part="1" 
F 0 "R26" H 7120 5146 50  0000 L CNN
F 1 "680" H 7120 5055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 6980 5100 50  0001 C CNN
F 3 "~" H 7050 5100 50  0001 C CNN
	1    7050 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5CA2891E
P 6750 4100
AR Path="/5C952539/5CA2891E" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA2891E" Ref="R24"  Part="1" 
F 0 "R24" H 6820 4146 50  0000 L CNN
F 1 "20K" H 6820 4055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 6680 4100 50  0001 C CNN
F 3 "~" H 6750 4100 50  0001 C CNN
	1    6750 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5CA28924
P 6000 4350
AR Path="/5C952539/5CA28924" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA28924" Ref="R20"  Part="1" 
F 0 "R20" H 6070 4396 50  0000 L CNN
F 1 "10K" H 6070 4305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 5930 4350 50  0001 C CNN
F 3 "~" H 6000 4350 50  0001 C CNN
	1    6000 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5CA2892A
P 5450 3900
AR Path="/5C952539/5CA2892A" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA2892A" Ref="R17"  Part="1" 
F 0 "R17" H 5520 3946 50  0000 L CNN
F 1 "2.2k" H 5520 3855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 5380 3900 50  0001 C CNN
F 3 "~" H 5450 3900 50  0001 C CNN
	1    5450 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5CA28930
P 6100 1900
AR Path="/5C952539/5CA28930" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA28930" Ref="R21"  Part="1" 
F 0 "R21" H 6170 1946 50  0000 L CNN
F 1 "4.7K" H 6170 1855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 6030 1900 50  0001 C CNN
F 3 "~" H 6100 1900 50  0001 C CNN
	1    6100 1900
	-1   0    0    1   
$EndComp
$Comp
L Device:D D?
U 1 1 5CA28936
P 7100 2600
AR Path="/5C952539/5CA28936" Ref="D?"  Part="1" 
AR Path="/5C9F4D88/5CA28936" Ref="D4"  Part="1" 
F 0 "D4" V 7150 2800 50  0000 C CNN
F 1 "in916" V 7250 2750 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P2.54mm_Vertical_AnodeUp" H 7100 2600 50  0001 C CNN
F 3 "~" H 7100 2600 50  0001 C CNN
	1    7100 2600
	0    1    1    0   
$EndComp
$Comp
L Device:D D?
U 1 1 5CA2893C
P 6900 2600
AR Path="/5C952539/5CA2893C" Ref="D?"  Part="1" 
AR Path="/5C9F4D88/5CA2893C" Ref="D3"  Part="1" 
F 0 "D3" V 6850 2800 50  0000 C CNN
F 1 "in916" V 6750 2750 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P2.54mm_Vertical_KathodeUp" H 6900 2600 50  0001 C CNN
F 3 "~" H 6900 2600 50  0001 C CNN
	1    6900 2600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5CA28942
P 5200 2350
AR Path="/5C952539/5CA28942" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA28942" Ref="R16"  Part="1" 
F 0 "R16" V 4993 2350 50  0000 C CNN
F 1 "4.7K" V 5084 2350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 5130 2350 50  0001 C CNN
F 3 "~" H 5200 2350 50  0001 C CNN
	1    5200 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	5300 5000 5550 5000
Wire Wire Line
	5550 5000 5550 5300
Connection ~ 5550 5000
Wire Wire Line
	5550 5000 5700 5000
Wire Wire Line
	5550 5600 5550 5850
Wire Wire Line
	5550 5850 6000 5850
Wire Wire Line
	6000 5200 6000 5850
Connection ~ 6000 5850
Wire Wire Line
	6000 4500 6000 4800
Wire Wire Line
	5450 3650 5800 3650
Wire Wire Line
	5450 3750 5450 3650
Wire Wire Line
	5450 4150 6000 4150
Connection ~ 6000 4150
Wire Wire Line
	6000 4150 6000 4200
Wire Wire Line
	6000 5850 6750 5850
Wire Wire Line
	7050 4650 7050 4950
Wire Wire Line
	7050 5250 7050 5850
Connection ~ 7050 5850
Wire Wire Line
	6200 3650 6750 3650
$Comp
L Weather-rescue:AO3401-Transistor_FET Q?
U 1 1 5CA2895B
P 6950 4450
AR Path="/5C952539/5CA2895B" Ref="Q?"  Part="1" 
AR Path="/5C9F4D88/5CA2895B" Ref="Q6"  Part="1" 
F 0 "Q6" H 7156 4496 50  0000 L CNN
F 1 "AO3401" H 7156 4405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7150 4375 50  0001 L CIN
F 3 "" H 6950 4450 50  0001 L CNN
	1    6950 4450
	1    0    0    1   
$EndComp
Wire Wire Line
	7050 5850 7650 5850
$Comp
L Device:R R?
U 1 1 5CA28962
P 6750 5100
AR Path="/5C952539/5CA28962" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA28962" Ref="R25"  Part="1" 
F 0 "R25" H 6820 5146 50  0000 L CNN
F 1 "20K" H 6820 5055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 6680 5100 50  0001 C CNN
F 3 "~" H 6750 5100 50  0001 C CNN
	1    6750 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 4450 6750 4950
Wire Wire Line
	6750 5250 6750 5850
Connection ~ 6750 5850
Wire Wire Line
	6750 5850 7050 5850
Wire Wire Line
	7400 4150 7650 4150
Wire Wire Line
	7650 4150 7650 5850
Connection ~ 6750 3650
Wire Wire Line
	6750 4250 6750 4450
Connection ~ 6750 4450
Wire Wire Line
	5850 1550 5850 2050
$Comp
L Device:R R?
U 1 1 5CA28972
P 7450 2450
AR Path="/5C952539/5CA28972" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA28972" Ref="R28"  Part="1" 
F 0 "R28" V 7243 2450 50  0000 C CNN
F 1 "3.3k" V 7334 2450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 7380 2450 50  0001 C CNN
F 3 "~" H 7450 2450 50  0001 C CNN
	1    7450 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	7100 2750 7000 2750
$Comp
L Device:R R?
U 1 1 5CA28979
P 6100 2850
AR Path="/5C952539/5CA28979" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA28979" Ref="R22"  Part="1" 
F 0 "R22" H 6170 2896 50  0000 L CNN
F 1 "4.7K" H 6170 2805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 6030 2850 50  0001 C CNN
F 3 "~" H 6100 2850 50  0001 C CNN
	1    6100 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2350 5400 2350
Wire Wire Line
	6050 2250 6100 2250
Wire Wire Line
	7650 4150 8050 4150
Connection ~ 7650 4150
Wire Wire Line
	4300 5850 5550 5850
Connection ~ 5550 5850
Wire Wire Line
	5850 2650 5850 3050
Wire Wire Line
	5850 3050 4300 3050
Wire Wire Line
	5850 3050 6100 3050
Wire Wire Line
	6100 3050 6100 3000
Connection ~ 5850 3050
Wire Wire Line
	5850 1550 6100 1550
Wire Wire Line
	6100 1550 6100 1750
Connection ~ 5850 1550
Wire Wire Line
	6100 2050 6100 2250
Connection ~ 6100 2250
Wire Wire Line
	6900 2450 7100 2450
Wire Wire Line
	7000 2750 7000 3050
Connection ~ 7000 2750
Wire Wire Line
	7000 2750 6900 2750
Wire Wire Line
	7600 2450 7650 2450
Wire Wire Line
	7100 2450 7300 2450
Connection ~ 7100 2450
$Comp
L Device:C C?
U 1 1 5CA28996
P 6600 2450
AR Path="/5C952539/5CA28996" Ref="C?"  Part="1" 
AR Path="/5C9F4D88/5CA28996" Ref="C2"  Part="1" 
F 0 "C2" V 6348 2450 50  0000 C CNN
F 1 "0.1uF" V 6439 2450 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 6638 2300 50  0001 C CNN
F 3 "~" H 6600 2450 50  0001 C CNN
	1    6600 2450
	0    1    1    0   
$EndComp
Text Label 7000 3050 0    50   ~ 0
0v
Text Label 5850 1500 0    50   ~ 0
5v
Wire Wire Line
	4600 2350 5050 2350
Text Label 5500 3650 0    50   ~ 0
24v
$Comp
L Device:R R?
U 1 1 5CA289A0
P 6300 2450
AR Path="/5C952539/5CA289A0" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA289A0" Ref="R23"  Part="1" 
F 0 "R23" V 6093 2450 50  0000 C CNN
F 1 "4.7K" V 6184 2450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 6230 2450 50  0001 C CNN
F 3 "~" H 6300 2450 50  0001 C CNN
	1    6300 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 2250 6100 2700
Wire Wire Line
	6050 2450 6150 2450
Wire Wire Line
	6750 2450 6900 2450
Connection ~ 6900 2450
Wire Wire Line
	6100 3050 7000 3050
Connection ~ 6100 3050
$Comp
L Device:R R?
U 1 1 5CA289AC
P 5600 2700
AR Path="/5C952539/5CA289AC" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA289AC" Ref="R19"  Part="1" 
F 0 "R19" V 5393 2700 50  0000 C CNN
F 1 "4.7K" V 5484 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 5530 2700 50  0001 C CNN
F 3 "~" H 5600 2700 50  0001 C CNN
	1    5600 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	5450 2700 5400 2700
Wire Wire Line
	5400 2700 5400 2350
Connection ~ 5400 2350
Wire Wire Line
	5400 2350 5450 2350
Wire Wire Line
	5750 2700 6050 2700
Wire Wire Line
	6050 2700 6050 2450
Connection ~ 6050 2450
Text HLabel 2900 3750 0    50   Input ~ 0
J18_P5
Wire Wire Line
	5450 4050 5450 4150
Wire Wire Line
	6000 3950 6000 4150
$Comp
L power:GNDS #PWR?
U 1 1 5CA289BC
P 6000 5850
AR Path="/5C952539/5CA289BC" Ref="#PWR?"  Part="1" 
AR Path="/5C9F4D88/5CA289BC" Ref="#PWR03"  Part="1" 
F 0 "#PWR03" H 6000 5600 50  0001 C CNN
F 1 "GNDS" H 6005 5677 50  0000 C CNN
F 2 "" H 6000 5850 50  0001 C CNN
F 3 "" H 6000 5850 50  0001 C CNN
	1    6000 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3650 6750 3950
Connection ~ 7400 3650
Wire Wire Line
	6750 3650 7050 3650
Connection ~ 7050 3650
Wire Wire Line
	7400 3650 7400 3850
$Comp
L Device:R R?
U 1 1 5CA289C7
P 7400 4000
AR Path="/5C952539/5CA289C7" Ref="R?"  Part="1" 
AR Path="/5C9F4D88/5CA289C7" Ref="R27"  Part="1" 
F 0 "R27" H 7470 4046 50  0000 L CNN
F 1 "47K" H 7470 3955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 7330 4000 50  0001 C CNN
F 3 "~" H 7400 4000 50  0001 C CNN
	1    7400 4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	7050 3650 7050 4250
Wire Wire Line
	7050 3650 7400 3650
Wire Wire Line
	7400 3650 7650 3650
Wire Wire Line
	7650 3650 8050 3650
Wire Wire Line
	7650 2450 7650 3650
Connection ~ 7650 3650
Wire Wire Line
	4300 3050 4300 3550
Wire Wire Line
	4450 1550 5850 1550
$Comp
L MyComponents:3_Way_Wire J?
U 1 1 5CA289DB
P 3350 2200
AR Path="/5C952539/5CA289DB" Ref="J?"  Part="1" 
AR Path="/5C9F4D88/5CA289DB" Ref="J12"  Part="1" 
F 0 "J12" H 3200 1800 50  0000 L CNN
F 1 "3_Way_Wire" H 3150 1650 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3350 2200 50  0001 C CNN
F 3 "" H 3350 2200 50  0001 C CNN
	1    3350 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2200 4300 3050
Wire Wire Line
	2900 2200 3250 2200
Connection ~ 3250 2200
Wire Wire Line
	3250 2200 4300 2200
Connection ~ 4300 3050
$Comp
L MyComponents:3_Way_Wire J?
U 1 1 5CA289E6
P 3300 3550
AR Path="/5C952539/5CA289E6" Ref="J?"  Part="1" 
AR Path="/5C9F4D88/5CA289E6" Ref="J11"  Part="1" 
F 0 "J11" H 3200 3150 50  0000 L CNN
F 1 "3_Way_Wire" H 3150 3000 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3300 3550 50  0001 C CNN
F 3 "" H 3300 3550 50  0001 C CNN
	1    3300 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 3550 4300 3550
Connection ~ 4300 3550
Wire Wire Line
	4300 3550 4300 5850
Wire Wire Line
	4450 2300 4450 1550
Wire Wire Line
	2900 2300 3250 2300
Connection ~ 3250 2300
Wire Wire Line
	3250 2300 4450 2300
Wire Wire Line
	4600 2350 4600 2400
Wire Wire Line
	4600 2400 3250 2400
Wire Wire Line
	2900 2400 3250 2400
Connection ~ 3250 2400
Wire Wire Line
	2900 3750 3200 3750
Wire Wire Line
	3200 3750 5000 3750
Wire Wire Line
	5000 3750 5000 5000
Connection ~ 3200 3750
Wire Wire Line
	2900 3650 3200 3650
Wire Wire Line
	3200 3650 5450 3650
Connection ~ 3200 3650
Connection ~ 5450 3650
$Comp
L Mechanical:MountingHole_Pad H7
U 1 1 5CA2EA1E
P 8050 3550
F 0 "H7" H 8150 3599 50  0000 L CNN
F 1 "MountingHole_Pad" H 8150 3508 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 8050 3550 50  0001 C CNN
F 3 "~" H 8050 3550 50  0001 C CNN
	1    8050 3550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H9
U 1 1 5CA3B689
P 8050 4050
F 0 "H9" H 8150 4099 50  0000 L CNN
F 1 "MountingHole_Pad" H 8150 4008 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 8050 4050 50  0001 C CNN
F 3 "~" H 8050 4050 50  0001 C CNN
	1    8050 4050
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H8
U 1 1 5CA554AA
P 8050 3750
F 0 "H8" H 7950 3707 50  0000 R CNN
F 1 "MountingHole_Pad" H 7950 3798 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 8050 3750 50  0001 C CNN
F 3 "~" H 8050 3750 50  0001 C CNN
	1    8050 3750
	-1   0    0    1   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H10
U 1 1 5CA56382
P 8050 4250
F 0 "H10" H 7950 4207 50  0000 R CNN
F 1 "MountingHole_Pad" H 7950 4298 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_Drill0.8mm" H 8050 4250 50  0001 C CNN
F 3 "~" H 8050 4250 50  0001 C CNN
	1    8050 4250
	-1   0    0    1   
$EndComp
Connection ~ 8050 3650
Connection ~ 8050 4150
$EndSCHEMATC
