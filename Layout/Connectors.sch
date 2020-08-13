EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
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
L Connector_Generic:Conn_01x03 J?
U 1 1 5F383B41
P 2350 2100
AR Path="/5F383B41" Ref="J?"  Part="1" 
AR Path="/5F3717FF/5F383B41" Ref="J1"  Part="1" 
F 0 "J1" V 2350 2350 50  0000 R CNN
F 1 "Conn_01x03" V 2450 2250 50  0000 R CNN
F 2 "" H 2350 2100 50  0001 C CNN
F 3 "~" H 2350 2100 50  0001 C CNN
	1    2350 2100
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J?
U 1 1 5F383B47
P 2350 2900
AR Path="/5F383B47" Ref="J?"  Part="1" 
AR Path="/5F3717FF/5F383B47" Ref="J2"  Part="1" 
F 0 "J2" V 2350 3150 50  0000 R CNN
F 1 "Conn_01x03" V 2450 3050 50  0000 R CNN
F 2 "" H 2350 2900 50  0001 C CNN
F 3 "~" H 2350 2900 50  0001 C CNN
	1    2350 2900
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J?
U 1 1 5F383B4D
P 2350 3700
AR Path="/5F383B4D" Ref="J?"  Part="1" 
AR Path="/5F3717FF/5F383B4D" Ref="J3"  Part="1" 
F 0 "J3" V 2350 3950 50  0000 R CNN
F 1 "Conn_01x03" V 2450 3850 50  0000 R CNN
F 2 "" H 2350 3700 50  0001 C CNN
F 3 "~" H 2350 3700 50  0001 C CNN
	1    2350 3700
	-1   0    0    -1  
$EndComp
$Comp
L power:PRI_HI #PWR?
U 1 1 5F383B59
P 2750 2800
AR Path="/5F383B59" Ref="#PWR?"  Part="1" 
AR Path="/5F3717FF/5F383B59" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 2750 2650 50  0001 C CNN
F 1 "PRI_HI" H 2765 2973 50  0000 C CNN
F 2 "" H 2750 2800 50  0001 C CNN
F 3 "" H 2750 2800 50  0001 C CNN
	1    2750 2800
	1    0    0    -1  
$EndComp
$Comp
L power:PRI_HI #PWR?
U 1 1 5F383B5F
P 2750 3600
AR Path="/5F383B5F" Ref="#PWR?"  Part="1" 
AR Path="/5F3717FF/5F383B5F" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 2750 3450 50  0001 C CNN
F 1 "PRI_HI" H 2765 3773 50  0000 C CNN
F 2 "" H 2750 3600 50  0001 C CNN
F 3 "" H 2750 3600 50  0001 C CNN
	1    2750 3600
	1    0    0    -1  
$EndComp
$Comp
L power:PRI_LO #PWR?
U 1 1 5F383B65
P 2750 2200
AR Path="/5F383B65" Ref="#PWR?"  Part="1" 
AR Path="/5F3717FF/5F383B65" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 2750 2050 50  0001 C CNN
F 1 "PRI_LO" H 2765 2373 50  0000 C CNN
F 2 "" H 2750 2200 50  0001 C CNN
F 3 "" H 2750 2200 50  0001 C CNN
	1    2750 2200
	-1   0    0    1   
$EndComp
$Comp
L power:PRI_LO #PWR?
U 1 1 5F383B6B
P 2750 3000
AR Path="/5F383B6B" Ref="#PWR?"  Part="1" 
AR Path="/5F3717FF/5F383B6B" Ref="#PWR0111"  Part="1" 
F 0 "#PWR0111" H 2750 2850 50  0001 C CNN
F 1 "PRI_LO" H 2765 3173 50  0000 C CNN
F 2 "" H 2750 3000 50  0001 C CNN
F 3 "" H 2750 3000 50  0001 C CNN
	1    2750 3000
	-1   0    0    1   
$EndComp
$Comp
L power:PRI_LO #PWR?
U 1 1 5F383B71
P 2750 3800
AR Path="/5F383B71" Ref="#PWR?"  Part="1" 
AR Path="/5F3717FF/5F383B71" Ref="#PWR0112"  Part="1" 
F 0 "#PWR0112" H 2750 3650 50  0001 C CNN
F 1 "PRI_LO" H 2765 3973 50  0000 C CNN
F 2 "" H 2750 3800 50  0001 C CNN
F 3 "" H 2750 3800 50  0001 C CNN
	1    2750 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	2750 3600 2550 3600
Wire Wire Line
	2750 2800 2550 2800
Wire Wire Line
	2750 2000 2550 2000
$Comp
L power:PRI_HI #PWR?
U 1 1 5F383B53
P 2750 2000
AR Path="/5F383B53" Ref="#PWR?"  Part="1" 
AR Path="/5F3717FF/5F383B53" Ref="#PWR0113"  Part="1" 
F 0 "#PWR0113" H 2750 1850 50  0001 C CNN
F 1 "PRI_HI" H 2765 2173 50  0000 C CNN
F 2 "" H 2750 2000 50  0001 C CNN
F 3 "" H 2750 2000 50  0001 C CNN
	1    2750 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3000 2750 3000
Wire Wire Line
	2550 3800 2750 3800
Wire Wire Line
	2550 2200 2750 2200
Text GLabel 2950 2100 2    50   Input ~ 0
PORT1_IO
Text GLabel 2950 2900 2    50   Input ~ 0
PORT2_IO
Text GLabel 2950 3700 2    50   Input ~ 0
PORT3_IO
Wire Wire Line
	2550 3700 2950 3700
Wire Wire Line
	2550 2900 2950 2900
Wire Wire Line
	2550 2100 2950 2100
$EndSCHEMATC
