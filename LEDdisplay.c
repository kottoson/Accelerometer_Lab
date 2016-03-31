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
void DisplayCharValues(unsigned char leftValue, unsigned char rightValue) {

	SPISendByte(rightValue);
	SPISendByte(leftValue);

	TOGGLE_LATCH;
	TOGGLE_LATCH;

}

//displays the 2-digit hex value arguement on the 7-segment LED display
void DisplayHexValue(unsigned char hexValue) {
	unsigned char leftValue = hexValue >> 4;
	leftValue = ConvertHexValue(leftValue);
	unsigned char rightValue = hexValue & 0x0F;
	rightValue = ConvertHexValue(rightValue);
	DisplayCharValues(leftValue, rightValue);
}

//Converts a 1-digit hex value arguement into a 2-digit hex value that, when
//sent to the display, causes it to display said arguement
unsigned char ConvertHexValue(unsigned char hexValue) {
	hexValue = hexValue & 0x0F;
	if (!hexValue) hexValue = DISPLAY_0;
	else if (hexValue == 0x01) hexValue = DISPLAY_1;
	else if (hexValue == 0x02) hexValue = DISPLAY_2;
	else if (hexValue == 0x03) hexValue = DISPLAY_3;
	else if (hexValue == 0x04) hexValue = DISPLAY_4;
	else if (hexValue == 0x05) hexValue = DISPLAY_5;
	else if (hexValue == 0x06) hexValue = DISPLAY_6;
	else if (hexValue == 0x07) hexValue = DISPLAY_7;
	else if (hexValue == 0x08) hexValue = DISPLAY_8;
	else if (hexValue == 0x09) hexValue = DISPLAY_9;
	else if (hexValue == 0x0A) hexValue = DISPLAY_A;
	else if (hexValue == 0x0B) hexValue = DISPLAY_B;
	else if (hexValue == 0x0C) hexValue = DISPLAY_C;
	else if (hexValue == 0x0D) hexValue = DISPLAY_D;
	else if (hexValue == 0x0E) hexValue = DISPLAY_E;
	else if (hexValue == 0x0F) hexValue = DISPLAY_F;
	else hexValue = 0b10000000;

	return hexValue;
}
