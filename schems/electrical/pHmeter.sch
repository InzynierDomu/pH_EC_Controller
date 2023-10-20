EESchema Schematic File Version 5
EELAYER 43 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
Comment5 ""
Comment6 ""
Comment7 ""
Comment8 ""
Comment9 ""
$EndDescr
Connection ~ 3300 2100
Connection ~ 3700 2500
Connection ~ 3700 3700
Connection ~ 3800 5350
Connection ~ 5350 5000
Connection ~ 7400 4200
Connection ~ 7650 2750
Wire Wire Line
	3300 1850 3300 2100
Wire Wire Line
	3300 2100 3300 2200
Wire Wire Line
	3300 2800 3300 2900
Wire Wire Line
	3700 2100 3300 2100
Wire Wire Line
	3700 2400 3700 2500
Wire Wire Line
	3700 2500 3600 2500
Wire Wire Line
	3700 3350 3800 3350
Wire Wire Line
	3700 3700 3700 3350
Wire Wire Line
	3700 3800 3700 3700
Wire Wire Line
	3700 4950 3950 4950
Wire Wire Line
	3700 5050 3800 5050
Wire Wire Line
	3700 5150 3950 5150
Wire Wire Line
	3700 5250 4450 5250
Wire Wire Line
	3700 5350 3800 5350
Wire Wire Line
	3700 5450 3950 5450
Wire Wire Line
	3700 5550 3950 5550
Wire Wire Line
	3800 3700 3700 3700
Wire Wire Line
	3800 5050 3800 5350
Wire Wire Line
	3800 5350 4450 5350
Wire Wire Line
	3850 2500 3700 2500
Wire Wire Line
	4200 3350 4850 3350
Wire Wire Line
	4200 3700 4300 3700
Wire Wire Line
	4250 3900 4350 3900
Wire Wire Line
	4300 3450 4850 3450
Wire Wire Line
	4300 3700 4300 3450
Wire Wire Line
	4350 3550 4850 3550
Wire Wire Line
	4350 3900 4350 3550
Wire Wire Line
	4450 4750 4450 5250
Wire Wire Line
	4450 5350 4450 5800
Wire Wire Line
	4600 1500 4600 1700
Wire Wire Line
	4600 1700 4700 1700
Wire Wire Line
	4750 3650 4850 3650
Wire Wire Line
	4750 3750 4850 3750
Wire Wire Line
	5100 1600 5250 1600
Wire Wire Line
	5250 1600 5250 1500
Wire Wire Line
	5250 2450 5250 2750
Wire Wire Line
	5350 5000 5350 4750
Wire Wire Line
	5350 5000 5350 5150
Wire Wire Line
	5450 4750 5450 5000
Wire Wire Line
	5450 5000 5350 5000
Wire Wire Line
	5550 2450 5550 2750
Wire Wire Line
	5850 3750 5900 3750
Wire Wire Line
	5850 3850 6900 3850
Wire Wire Line
	5850 3950 6500 3950
Wire Wire Line
	5850 4050 6150 4050
Wire Wire Line
	5850 4250 5950 4250
Wire Wire Line
	5850 4800 5850 4900
Wire Wire Line
	5850 4900 6250 4900
Wire Wire Line
	5900 3450 6150 3450
Wire Wire Line
	5900 3750 5900 3450
Wire Wire Line
	5950 4250 5950 4800
Wire Wire Line
	5950 4800 6250 4800
Wire Wire Line
	6000 4150 5850 4150
Wire Wire Line
	6000 4700 6000 4150
Wire Wire Line
	6100 3550 6150 3550
Wire Wire Line
	6100 3650 6100 3550
Wire Wire Line
	6100 4150 6150 4150
Wire Wire Line
	6100 4250 6100 4150
Wire Wire Line
	6100 5000 6250 5000
Wire Wire Line
	6100 5150 6100 5000
Wire Wire Line
	6150 2300 6150 2450
Wire Wire Line
	6150 2450 6250 2450
Wire Wire Line
	6150 2550 6250 2550
Wire Wire Line
	6150 2650 6150 2550
Wire Wire Line
	6250 4700 6000 4700
Wire Wire Line
	6500 3950 6500 3750
Wire Wire Line
	7350 4200 7400 4200
Wire Wire Line
	7400 4200 7500 4200
Wire Wire Line
	7400 4250 7400 4200
Wire Wire Line
	7400 4550 7400 4600
Wire Wire Line
	7550 2750 7650 2750
Wire Wire Line
	7650 2750 7700 2750
Wire Wire Line
	7650 2800 7650 2750
Wire Wire Line
	7650 3100 7650 3150
Wire Wire Line
	7800 4400 7800 4600
Wire Wire Line
	8000 2950 8000 3150
Text GLabel 3850 2500 2    50   Input ~ 0
Data
Text GLabel 3950 4950 2    50   Input ~ 0
SPI_MISO
Text GLabel 3950 5150 2    50   Input ~ 0
SPI_CLK
Text GLabel 3950 5450 2    50   Input ~ 0
SPI_MOSI
Text GLabel 3950 5550 2    50   Input ~ 0
SD_CS
Text GLabel 4250 3900 0    50   Input ~ 0
Data
Text GLabel 4750 3650 0    50   Input ~ 0
Ph_vcc
Text GLabel 4750 3750 0    50   Input ~ 0
EC_vcc
Text GLabel 7350 4200 0    50   Input ~ 0
Ph_vcc
Text GLabel 7550 2750 0    50   Input ~ 0
EC_vcc
$Comp
L power:+5V #PWR0105
U 1 1 5FBBEB69
P 3300 1850
F 0 "#PWR0105" H 3300 1700 50  0001 C CNN
F 1 "+5V" H 3315 2023 50  0000 C CNN
F 2 "" H 3300 1850 50  0001 C CNN
F 3 "" H 3300 1850 50  0001 C CNN
	1    3300 1850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0116
U 1 1 631155A3
P 4450 4750
F 0 "#PWR0116" H 4450 4600 50  0001 C CNN
F 1 "+5V" H 4465 4923 50  0000 C CNN
F 2 "" H 4450 4750 50  0001 C CNN
F 3 "" H 4450 4750 50  0001 C CNN
	1    4450 4750
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0109
U 1 1 5FBD5C94
P 4600 1500
F 0 "#PWR0109" H 4600 1350 50  0001 C CNN
F 1 "+BATT" H 4615 1673 50  0000 C CNN
F 2 "" H 4600 1500 50  0001 C CNN
F 3 "" H 4600 1500 50  0001 C CNN
	1    4600 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0110
U 1 1 5FBD69D9
P 5250 1500
F 0 "#PWR0110" H 5250 1350 50  0001 C CNN
F 1 "+9V" H 5265 1673 50  0000 C CNN
F 2 "" H 5250 1500 50  0001 C CNN
F 3 "" H 5250 1500 50  0001 C CNN
	1    5250 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0103
U 1 1 5FBBD084
P 5250 2450
F 0 "#PWR0103" H 5250 2300 50  0001 C CNN
F 1 "+9V" H 5265 2623 50  0000 C CNN
F 2 "" H 5250 2450 50  0001 C CNN
F 3 "" H 5250 2450 50  0001 C CNN
	1    5250 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5FBBDD10
P 5550 2450
F 0 "#PWR0104" H 5550 2300 50  0001 C CNN
F 1 "+5V" H 5565 2623 50  0000 C CNN
F 2 "" H 5550 2450 50  0001 C CNN
F 3 "" H 5550 2450 50  0001 C CNN
	1    5550 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0111
U 1 1 5FBE20D2
P 5850 4800
F 0 "#PWR0111" H 5850 4650 50  0001 C CNN
F 1 "+5V" H 5865 4973 50  0000 C CNN
F 2 "" H 5850 4800 50  0001 C CNN
F 3 "" H 5850 4800 50  0001 C CNN
	1    5850 4800
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0114
U 1 1 5FBEB5E8
P 6150 2300
F 0 "#PWR0114" H 6150 2150 50  0001 C CNN
F 1 "+BATT" H 6165 2473 50  0000 C CNN
F 2 "" H 6150 2300 50  0001 C CNN
F 3 "" H 6150 2300 50  0001 C CNN
	1    6150 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5FBBF5C8
P 3300 2900
F 0 "#PWR0106" H 3300 2650 50  0001 C CNN
F 1 "GND" H 3305 2727 50  0000 C CNN
F 2 "" H 3300 2900 50  0001 C CNN
F 3 "" H 3300 2900 50  0001 C CNN
	1    3300 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5FBB2E6D
P 3700 3800
F 0 "#PWR0101" H 3700 3550 50  0001 C CNN
F 1 "GND" H 3705 3627 50  0000 C CNN
F 2 "" H 3700 3800 50  0001 C CNN
F 3 "" H 3700 3800 50  0001 C CNN
	1    3700 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 6311431F
P 4450 5800
F 0 "#PWR0115" H 4450 5550 50  0001 C CNN
F 1 "GND" H 4455 5627 50  0000 C CNN
F 2 "" H 4450 5800 50  0001 C CNN
F 3 "" H 4450 5800 50  0001 C CNN
	1    4450 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5FBB342B
P 5350 5150
F 0 "#PWR0102" H 5350 4900 50  0001 C CNN
F 1 "GND" H 5355 4977 50  0000 C CNN
F 2 "" H 5350 5150 50  0001 C CNN
F 3 "" H 5350 5150 50  0001 C CNN
	1    5350 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 00000000
P 6100 3650
F 0 "#PWR01" H 6100 3400 50  0001 C CNN
F 1 "GND" H 6105 3477 50  0000 C CNN
F 2 "" H 6100 3650 50  0001 C CNN
F 3 "" H 6100 3650 50  0001 C CNN
	1    6100 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 00000000
P 6100 4250
F 0 "#PWR02" H 6100 4000 50  0001 C CNN
F 1 "GND" H 6105 4077 50  0000 C CNN
F 2 "" H 6100 4250 50  0001 C CNN
F 3 "" H 6100 4250 50  0001 C CNN
	1    6100 4250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5FBE2EAB
P 6100 5150
F 0 "#PWR0112" H 6100 4900 50  0001 C CNN
F 1 "GND" H 6105 4977 50  0000 C CNN
F 2 "" H 6100 5150 50  0001 C CNN
F 3 "" H 6100 5150 50  0001 C CNN
	1    6100 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5FBEAF0A
P 6150 2650
F 0 "#PWR0113" H 6150 2400 50  0001 C CNN
F 1 "GND" H 6155 2477 50  0000 C CNN
F 2 "" H 6150 2650 50  0001 C CNN
F 3 "" H 6150 2650 50  0001 C CNN
	1    6150 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5FBD16B4
P 7400 4600
F 0 "#PWR0107" H 7400 4350 50  0001 C CNN
F 1 "GND" H 7405 4427 50  0000 C CNN
F 2 "" H 7400 4600 50  0001 C CNN
F 3 "" H 7400 4600 50  0001 C CNN
	1    7400 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5FF44E7C
P 7650 3150
F 0 "#PWR0108" H 7650 2900 50  0001 C CNN
F 1 "GND" H 7655 2977 50  0000 C CNN
F 2 "" H 7650 3150 50  0001 C CNN
F 3 "" H 7650 3150 50  0001 C CNN
	1    7650 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 00000000
P 7800 4600
F 0 "#PWR03" H 7800 4350 50  0001 C CNN
F 1 "GND" H 7805 4427 50  0000 C CNN
F 2 "" H 7800 4600 50  0001 C CNN
F 3 "" H 7800 4600 50  0001 C CNN
	1    7800 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 00000000
P 8000 3150
F 0 "#PWR04" H 8000 2900 50  0001 C CNN
F 1 "GND" H 8005 2977 50  0000 C CNN
F 2 "" H 8000 3150 50  0001 C CNN
F 3 "" H 8000 3150 50  0001 C CNN
	1    8000 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5FBC1A88
P 3700 2250
F 0 "R1" H 3770 2296 50  0000 L CNN
F 1 "4,7K" H 3770 2205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3630 2250 50  0001 C CNN
F 3 "~" H 3700 2250 50  0001 C CNN
	1    3700 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 00000000
P 7400 4400
F 0 "R2" H 7470 4446 50  0000 L CNN
F 1 "100k" H 7470 4355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7330 4400 50  0001 C CNN
F 3 "~" H 7400 4400 50  0001 C CNN
	1    7400 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 00000000
P 7650 2950
F 0 "R3" H 7720 2996 50  0000 L CNN
F 1 "100k" H 7720 2905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7580 2950 50  0001 C CNN
F 3 "~" H 7650 2950 50  0001 C CNN
	1    7650 2950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 00000000
P 6350 3450
F 0 "J1" H 6450 3425 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 6450 3325 50  0000 L CNN
F 2 "" H 6350 3450 50  0001 C CNN
F 3 "~" H 6350 3450 50  0001 C CNN
	1    6350 3450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 00000000
P 6350 4050
F 0 "J4" H 6450 4025 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 6200 3850 50  0000 L CNN
F 2 "" H 6350 4050 50  0001 C CNN
F 3 "~" H 6350 4050 50  0001 C CNN
	1    6350 4050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5FBE8BFA
P 6450 2450
F 0 "J3" H 6530 2442 50  0000 L CNN
F 1 "Conn_01x02" H 6530 2351 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6450 2450 50  0001 C CNN
F 3 "~" H 6450 2450 50  0001 C CNN
	1    6450 2450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5FBB0E15
P 4000 3350
F 0 "SW1" H 4000 3635 50  0000 C CNN
F 1 "SW_Push" H 4000 3544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H8mm" H 4000 3550 50  0001 C CNN
F 3 "~" H 4000 3550 50  0001 C CNN
	1    4000 3350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5FBB7749
P 4000 3700
F 0 "SW2" H 4000 3985 50  0000 C CNN
F 1 "SW_Push" H 4000 3894 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H8mm" H 4000 3900 50  0001 C CNN
F 3 "~" H 4000 3900 50  0001 C CNN
	1    4000 3700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW3
U 1 1 5FBD3764
P 4900 1700
F 0 "SW3" H 4900 1985 50  0000 C CNN
F 1 "SW_SPDT" H 4900 1894 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4900 1700 50  0001 C CNN
F 3 "~" H 4900 1700 50  0001 C CNN
	1    4900 1700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 5FBDC3A4
P 6450 4800
F 0 "J2" H 6530 4792 50  0000 L CNN
F 1 "Conn_01x04" H 6530 4701 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6450 4800 50  0001 C CNN
F 3 "~" H 6450 4800 50  0001 C CNN
	1    6450 4800
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q1
U 1 1 00000000
P 7700 4200
F 0 "Q1" H 7950 4225 50  0000 L CNN
F 1 "2N7000" H 7950 4125 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 7900 4125 50  0001 L CIN
F 3 "https://www.vishay.com/docs/70226/70226.pdf" H 7700 4200 50  0001 L CNN
	1    7700 4200
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q2
U 1 1 00000000
P 7900 2750
F 0 "Q2" H 8150 2775 50  0000 L CNN
F 1 "2N7000" H 8150 2675 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8100 2675 50  0001 L CIN
F 3 "https://www.vishay.com/docs/70226/70226.pdf" H 7900 2750 50  0001 L CNN
	1    7900 2750
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Temperature:DS18B20 U1
U 1 1 5FBBBB4C
P 3300 2500
F 0 "U1" H 3070 2546 50  0000 R CNN
F 1 "DS18B20" H 3070 2455 50  0000 R CNN
F 2 "Button_Switch_THT:SW_CuK_JS202011AQN_DPDT_Angled" H 2300 2250 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 3150 2750 50  0001 C CNN
	1    3300 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector:SD_Card J5
U 1 1 63108573
P 2800 5250
F 0 "J5" H 2800 4585 50  0000 C CNN
F 1 "SD_Card" H 2800 4676 50  0000 C CNN
F 2 "" H 2800 5250 50  0001 C CNN
F 3 "http://portal.fciconnect.com/Comergent//fci/drawing/10067847.pdf" H 2800 5250 50  0001 C CNN
	1    2800 5250
	-1   0    0    1   
$EndComp
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5FBAAA96
P 5350 3750
F 0 "A1" H 5350 2661 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 5350 2570 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 5350 3750 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 5350 3750 50  0001 C CNN
	1    5350 3750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
