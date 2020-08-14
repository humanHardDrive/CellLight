EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_Push SW1
U 1 1 5F35733D
P 1500 1650
F 0 "SW1" H 1500 1935 50  0000 C CNN
F 1 "SW_Push" H 1500 1844 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_TL3342" H 1500 1850 50  0001 C CNN
F 3 "~" H 1500 1850 50  0001 C CNN
	1    1500 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R1
U 1 1 5F357DB5
P 1950 1400
F 0 "R1" H 2018 1446 50  0000 L CNN
F 1 "10k" H 2018 1355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1990 1390 50  0001 C CNN
F 3 "~" H 1950 1400 50  0001 C CNN
	1    1950 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1650 1950 1650
Wire Wire Line
	1950 1550 1950 1650
Connection ~ 1950 1650
$Comp
L power:GND #PWR0101
U 1 1 5F358880
P 1300 1750
F 0 "#PWR0101" H 1300 1500 50  0001 C CNN
F 1 "GND" H 1305 1577 50  0000 C CNN
F 2 "" H 1300 1750 50  0001 C CNN
F 3 "" H 1300 1750 50  0001 C CNN
	1    1300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1750 1300 1650
$Comp
L power:+3.3V #PWR0102
U 1 1 5F358F61
P 1950 1150
F 0 "#PWR0102" H 1950 1000 50  0001 C CNN
F 1 "+3.3V" H 1965 1323 50  0000 C CNN
F 2 "" H 1950 1150 50  0001 C CNN
F 3 "" H 1950 1150 50  0001 C CNN
	1    1950 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1150 1950 1250
Wire Wire Line
	1950 1650 1950 2000
Text GLabel 1950 2000 3    50   Input ~ 0
RESET
$Comp
L DSPIC33FJ128GP802-I_SO:DSPIC33FJ128GP802-I_SO U1
U 1 1 5F360275
P 5800 3000
F 0 "U1" H 5800 4970 50  0000 C CNN
F 1 "DSPIC33FJ128GP802-I_SO" H 5800 4879 50  0000 C CNN
F 2 "SOIC127P1030X265-28N" H 5800 3000 50  0001 L BNN
F 3 "" H 5800 3000 50  0001 C CNN
	1    5800 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1700 2850 1700
Text GLabel 2850 1700 0    50   Input ~ 0
RESET
$Comp
L Device:C C1
U 1 1 5F36AEA4
P 8450 1500
F 0 "C1" V 8198 1500 50  0000 C CNN
F 1 "10U" V 8289 1500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8488 1350 50  0001 C CNN
F 3 "~" H 8450 1500 50  0001 C CNN
	1    8450 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	8200 1500 8300 1500
$Comp
L power:+3.3V #PWR0103
U 1 1 5F36B77A
P 8200 1150
F 0 "#PWR0103" H 8200 1000 50  0001 C CNN
F 1 "+3.3V" H 8215 1323 50  0000 C CNN
F 2 "" H 8200 1150 50  0001 C CNN
F 3 "" H 8200 1150 50  0001 C CNN
	1    8200 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1150 8200 1300
$Comp
L power:GND #PWR0104
U 1 1 5F36C154
P 8600 1500
F 0 "#PWR0104" H 8600 1250 50  0001 C CNN
F 1 "GND" H 8605 1327 50  0000 C CNN
F 2 "" H 8600 1500 50  0001 C CNN
F 3 "" H 8600 1500 50  0001 C CNN
	1    8600 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5F36C44E
P 8200 4700
F 0 "#PWR0105" H 8200 4450 50  0001 C CNN
F 1 "GND" H 8205 4527 50  0000 C CNN
F 2 "" H 8200 4700 50  0001 C CNN
F 3 "" H 8200 4700 50  0001 C CNN
	1    8200 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 4700 8200 4600
Wire Wire Line
	3400 4100 2800 4100
Wire Wire Line
	3400 4300 2800 4300
Text GLabel 2800 4100 0    50   Input ~ 0
SCL
Text GLabel 2800 4300 0    50   Input ~ 0
SDA
Wire Wire Line
	3400 2000 2850 2000
Wire Wire Line
	3400 2100 2850 2100
Wire Wire Line
	3400 2200 2850 2200
Text GLabel 2850 2100 0    50   Input ~ 0
PGEC
Text GLabel 2850 2200 0    50   Input ~ 0
PGED
Text GLabel 2850 2000 0    50   Input ~ 0
PORT1_IO
Wire Wire Line
	3400 3200 2850 3200
Wire Wire Line
	3400 3500 2850 3500
Text GLabel 2850 3200 0    50   Input ~ 0
PORT2_IO
Text GLabel 2850 3500 0    50   Input ~ 0
PORT3_IO
Wire Wire Line
	3400 1900 2850 1900
Wire Wire Line
	3400 1800 2850 1800
Text GLabel 2850 1800 0    50   Input ~ 0
RX
Text GLabel 2850 1900 0    50   Input ~ 0
TX
Wire Wire Line
	3400 2600 2850 2600
Text GLabel 2850 2600 0    50   Input ~ 0
PWM_OUT
Wire Wire Line
	3400 2400 2850 2400
Wire Wire Line
	3400 2500 2850 2500
Text GLabel 2850 2400 0    50   Input ~ 0
PORT1_SEL
Text GLabel 2850 2500 0    50   Input ~ 0
PORT2_SEL
Wire Wire Line
	3400 3900 2800 3900
Text GLabel 2800 3900 0    50   Input ~ 0
PORT3_SEL
$Comp
L Device:C C2
U 1 1 5F36FE4F
P 9500 1350
F 0 "C2" H 9615 1396 50  0000 L CNN
F 1 "0.1U" H 9615 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9538 1200 50  0001 C CNN
F 3 "~" H 9500 1350 50  0001 C CNN
	1    9500 1350
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0106
U 1 1 5F370E83
P 9500 1200
F 0 "#PWR0106" H 9500 1050 50  0001 C CNN
F 1 "+3.3V" H 9515 1373 50  0000 C CNN
F 2 "" H 9500 1200 50  0001 C CNN
F 3 "" H 9500 1200 50  0001 C CNN
	1    9500 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5F3712C2
P 9500 1500
F 0 "#PWR0107" H 9500 1250 50  0001 C CNN
F 1 "GND" H 9505 1327 50  0000 C CNN
F 2 "" H 9500 1500 50  0001 C CNN
F 3 "" H 9500 1500 50  0001 C CNN
	1    9500 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F39076D
P 1700 5350
F 0 "R?" H 1768 5396 50  0000 L CNN
F 1 "4.7k" H 1768 5305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1740 5340 50  0001 C CNN
F 3 "~" H 1700 5350 50  0001 C CNN
	1    1700 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F3923D8
P 2200 5350
F 0 "R?" H 2268 5396 50  0000 L CNN
F 1 "4.7k" H 2268 5305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2240 5340 50  0001 C CNN
F 3 "~" H 2200 5350 50  0001 C CNN
	1    2200 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 5200 1700 5100
Wire Wire Line
	1700 5100 1950 5100
Wire Wire Line
	2200 5100 2200 5200
Text GLabel 1300 5600 0    50   Input ~ 0
SDA
Text GLabel 1300 5800 0    50   Input ~ 0
SCL
Wire Wire Line
	1300 5600 1700 5600
Wire Wire Line
	1700 5600 1700 5500
Wire Wire Line
	1300 5800 2200 5800
Wire Wire Line
	2200 5800 2200 5500
$Comp
L power:+3.3V #PWR?
U 1 1 5F3937F3
P 1950 4950
F 0 "#PWR?" H 1950 4800 50  0001 C CNN
F 1 "+3.3V" H 1965 5123 50  0000 C CNN
F 2 "" H 1950 4950 50  0001 C CNN
F 3 "" H 1950 4950 50  0001 C CNN
	1    1950 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4950 1950 5100
Connection ~ 1950 5100
Wire Wire Line
	1950 5100 2200 5100
Text GLabel 2850 3700 0    50   Input ~ 0
FRAM_WP
Wire Wire Line
	2850 3700 3400 3700
$EndSCHEMATC
