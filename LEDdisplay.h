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
 * Used to convert cardinal direction to bit values for
 * output
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#define NORTHEAST 	BIT6
#define EAST 		BIT5
#define SOUTHEAST 	BIT4
#define SOUTH 		BIT3
#define SOUTHWEST 	BIT2
#define WEST		BIT1
#define NORTHWEST	BIT0
#define NORTH		BIT7
#define DISPLAYX	NORTHEAST|NORTHWEST|SOUTHEAST|SOUTHWEST
#define DISPLAYPLUS	NORTH|SOUTH|EAST|WEST
const static unsigned char displayArr[]=	{NORTH,NORTHEAST,EAST,SOUTHEAST,SOUTH,SOUTHWEST,WEST,NORTHWEST};



void ConfigureLEDDisplayPins(void);
void DisplayLED(unsigned char value);

#endif /* LEDDISPLAY_H_ */
