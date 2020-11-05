EESchema Schematic File Version 4
EELAYER 30 0
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
$EndDescr
$Comp
L LED:WS2812B D1
U 1 1 5F9DB47E
P 4100 2800
F 0 "D1" H 4444 2846 50  0000 L CNN
F 1 "WS2812B" H 4444 2755 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 4150 2500 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 4200 2425 50  0001 L TNN
	1    4100 2800
	1    0    0    -1  
$EndComp
$Comp
L LED:WS2812B D2
U 1 1 5F9DDBEF
P 5300 2800
F 0 "D2" H 5644 2846 50  0000 L CNN
F 1 "WS2812B" H 5644 2755 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 5350 2500 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 5400 2425 50  0001 L TNN
	1    5300 2800
	1    0    0    -1  
$EndComp
$Comp
L LED:WS2812B D3
U 1 1 5F9DE96B
P 6450 2800
F 0 "D3" H 6794 2846 50  0000 L CNN
F 1 "WS2812B" H 6794 2755 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 6500 2500 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 6550 2425 50  0001 L TNN
	1    6450 2800
	1    0    0    -1  
$EndComp
$Comp
L LED:WS2812B D4
U 1 1 5F9DF1E8
P 7650 2800
F 0 "D4" H 7994 2846 50  0000 L CNN
F 1 "WS2812B" H 7994 2755 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 7700 2500 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 7750 2425 50  0001 L TNN
	1    7650 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 2250 6450 2250
Wire Wire Line
	4100 2250 4100 2500
Wire Wire Line
	5300 2500 5300 2250
Connection ~ 5300 2250
Wire Wire Line
	5300 2250 4100 2250
Wire Wire Line
	6450 2500 6450 2250
Connection ~ 6450 2250
Wire Wire Line
	6450 2250 5300 2250
Wire Wire Line
	7650 2250 7650 2500
Wire Wire Line
	4100 3100 4100 3400
Wire Wire Line
	4100 3400 5300 3400
Wire Wire Line
	7650 3400 7650 3100
Wire Wire Line
	6450 3100 6450 3400
Connection ~ 6450 3400
Wire Wire Line
	6450 3400 7650 3400
Wire Wire Line
	5300 3100 5300 3400
Connection ~ 5300 3400
Wire Wire Line
	5300 3400 6450 3400
Wire Wire Line
	4400 2800 5000 2800
Wire Wire Line
	5600 2800 6150 2800
Wire Wire Line
	6750 2800 7350 2800
$Comp
L Device:C C1
U 1 1 5F9E3629
P 3300 2800
F 0 "C1" H 3415 2846 50  0000 L CNN
F 1 "C" H 3415 2755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3338 2650 50  0001 C CNN
F 3 "~" H 3300 2800 50  0001 C CNN
	1    3300 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2250 3300 2250
Wire Wire Line
	3300 2250 3300 2650
Connection ~ 4100 2250
Wire Wire Line
	3300 2950 3300 3400
Wire Wire Line
	3300 3400 4100 3400
Connection ~ 4100 3400
Wire Wire Line
	3800 2800 3600 2800
Wire Wire Line
	7950 2800 8100 2800
$Comp
L SparkFun-PowerSymbols:5V #SUPPLY0101
U 1 1 5F9E56C3
P 3300 2250
F 0 "#SUPPLY0101" H 3350 2250 45  0001 L BNN
F 1 "5V" H 3300 2526 45  0000 C CNN
F 2 "XXX-00000" H 3300 2431 60  0000 C CNN
F 3 "" H 3300 2250 60  0001 C CNN
	1    3300 2250
	1    0    0    -1  
$EndComp
Connection ~ 3300 2250
$Comp
L SparkFun-PowerSymbols:GND #GND0101
U 1 1 5F9E5E02
P 3300 3400
F 0 "#GND0101" H 3350 3350 45  0001 L BNN
F 1 "GND" H 3300 3230 45  0000 C CNN
F 2 "" H 3300 3300 60  0001 C CNN
F 3 "" H 3300 3300 60  0001 C CNN
	1    3300 3400
	1    0    0    -1  
$EndComp
Connection ~ 3300 3400
Wire Wire Line
	3600 1750 3600 2800
Wire Wire Line
	8100 1750 8100 2800
Text Label 3600 1750 3    50   ~ 0
Din
Text Label 8100 1750 3    50   ~ 0
Dout
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5F9EA073
P 5050 4550
F 0 "J1" H 4968 4867 50  0000 C CNN
F 1 "Conn_01x03" H 4968 4776 50  0000 C CNN
F 2 "Connector_JST:JST_SUR_SM03B-SURS-TF_1x03-1MP_P0.80mm_Horizontal" H 5050 4550 50  0001 C CNN
F 3 "~" H 5050 4550 50  0001 C CNN
	1    5050 4550
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5F9EA809
P 7100 4550
F 0 "J2" H 7180 4592 50  0000 L CNN
F 1 "Conn_01x03" H 7180 4501 50  0000 L CNN
F 2 "Connector_JST:JST_SUR_SM03B-SURS-TF_1x03-1MP_P0.80mm_Horizontal" H 7100 4550 50  0001 C CNN
F 3 "~" H 7100 4550 50  0001 C CNN
	1    7100 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4550 5850 4550
Wire Wire Line
	5250 4650 6350 4650
Wire Wire Line
	5250 4450 5400 4450
Wire Wire Line
	5400 4450 5400 4050
$Comp
L SparkFun-PowerSymbols:5V #SUPPLY0102
U 1 1 5F9F1628
P 5850 4550
F 0 "#SUPPLY0102" H 5900 4550 45  0001 L BNN
F 1 "5V" H 5850 4826 45  0000 C CNN
F 2 "XXX-00000" H 5850 4731 60  0000 C CNN
F 3 "" H 5850 4550 60  0001 C CNN
	1    5850 4550
	1    0    0    -1  
$EndComp
Connection ~ 5850 4550
Wire Wire Line
	5850 4550 6900 4550
$Comp
L SparkFun-PowerSymbols:GND #GND0102
U 1 1 5F9F21F4
P 6350 4650
F 0 "#GND0102" H 6400 4600 45  0001 L BNN
F 1 "GND" H 6350 4480 45  0000 C CNN
F 2 "" H 6350 4550 60  0001 C CNN
F 3 "" H 6350 4550 60  0001 C CNN
	1    6350 4650
	1    0    0    -1  
$EndComp
Connection ~ 6350 4650
Wire Wire Line
	6350 4650 6900 4650
Wire Wire Line
	6900 4450 6750 4450
Wire Wire Line
	6750 4450 6750 4050
Text Label 5400 4050 3    50   ~ 0
Din
Text Label 6750 4050 3    50   ~ 0
Dout
$Comp
L Mechanical:MountingHole H1
U 1 1 5F9EE45B
P 2500 4750
F 0 "H1" H 2600 4796 50  0000 L CNN
F 1 "MountingHole" H 2600 4705 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_Pad" H 2500 4750 50  0001 C CNN
F 3 "~" H 2500 4750 50  0001 C CNN
	1    2500 4750
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5F9EE9B2
P 2500 5050
F 0 "H2" H 2600 5096 50  0000 L CNN
F 1 "MountingHole" H 2600 5005 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.7mm_M2.5_Pad" H 2500 5050 50  0001 C CNN
F 3 "~" H 2500 5050 50  0001 C CNN
	1    2500 5050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
