/*
 * LEDdisplay.c
 *
 *  Created on: Mar 22, 2016
 *      Author: Student
 */

#include "LEDdisplay.h"
#include "SPI.h"

void ConfigureLEDDisplayPins(void) {
	SET_LATCH_AS_OUTPUT;
	SET_BLANK_AS_OUTPUT;

	SET_LATCH_LOW;
	SET_BLANK_LOW;
}


//sends the char values (representing what to display) to the 7-segment display
//left value will appear on the left display, etc.
void DisplayLED(unsigned char value) {

	SPISendByte(value);

	TOGGLE_LATCH;
	TOGGLE_LATCH;

}
