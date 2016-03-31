/*
 * LEDdisplay.h
 *
 *  Created on: Mar 22, 2016
 *      Author: Student
 */

#ifndef LEDDISPLAY_H_
#define LEDDISPLAY_H_

#include <msp430.h>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 					LATCH
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 	Device		:	7-Segment Display LED Drivers
 * 	Polarity	:	Active High
 * 	PCB Device	:	U10 and U13
 * 	PCB TP		:	TP09
 * 	GPIO		:	P2.0
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define LATCH_BIT 				BIT0
#define LATCH_PORT 				P2OUT
#define LATCH_DDR 				P2DIR
#define SET_LATCH_AS_OUTPUT 	LATCH_DDR |= LATCH_BIT
#define SET_LATCH_HIGH			LATCH_PORT |= LATCH_BIT
#define SET_LATCH_LOW			LATCH_PORT &= ~LATCH_BIT
#define TOGGLE_LATCH			LATCH_PORT ^= LATCH_BIT

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 					BLANK
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 	Device		:	7-Segment Display LED Drivers
 * 	Polarity	:	Active High
 * 	PCB Device	:	U10 and U13
 * 	PCB TP		:	TP09
 * 	GPIO		:	P1.4
 * 	NOTE		:	When HIGH, disables display but
 * 					retains latch-register value
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define BLANK_BIT 				BIT4
#define BLANK_PORT 				P1OUT
#define BLANK_DDR 				P1DIR
#define SET_BLANK_AS_OUTPUT 	BLANK_DDR |= BLANK_BIT
#define SET_BLANK_HIGH			BLANK_PORT |= BLANK_BIT
#define SET_BLANK_LOW			BLANK_PORT &= ~BLANK_BIT
#define TOGGLE_BLANK			BLANK_PORT ^= BLANK_BIT

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 						LED Display Characters
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Used to convert the hexadecimal value into the value
 * to be sent to the 7-segment display.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#define DISPLAY_0				0x3F
#define DISPLAY_1				0x06
#define DISPLAY_2				0x5B
#define DISPLAY_3				0x4F
#define DISPLAY_4				0x66
#define DISPLAY_5				0x6D
#define DISPLAY_6				0x7D
#define DISPLAY_7				0x07
#define DISPLAY_8				0x7F
#define DISPLAY_9				0x67
#define DISPLAY_A				0x77
#define DISPLAY_B				0x7c
#define DISPLAY_C				0x39
#define DISPLAY_D				0x5E
#define DISPLAY_E				0x79
#define DISPLAY_F				0x71

void ConfigureLEDDisplayPins(void);
void DisplayCharValues(unsigned char leftValue, unsigned char rightValue);
void DisplayHexValue(unsigned char hexValue);
unsigned char ConvertHexValue(unsigned char hexValue);




#endif /* LEDDISPLAY_H_ */
