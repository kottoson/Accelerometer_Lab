#include <msp430.h>
#include "LED.h"

void InitializeLEDPortPins(void)
{
	// Set the LEDs as outputs
	SET_LED1_AS_AN_OUTPUT;
	SET_LED2_AS_AN_OUTPUT;

	TURN_OFF_LED1;
	TURN_OFF_LED2;

}
void SetLEDState(char choice, char state)
{
	switch (choice) {
		case LED1:
			if (state)
				TURN_ON_LED1;
			else
				TURN_OFF_LED1;
			break;
		case LED2:
			if (state)
				TURN_ON_LED2;
			else
				TURN_OFF_LED2;
			break;
		default:
			break;
	}
	return;
}

