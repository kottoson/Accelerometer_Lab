#include "pushbutton.h"
#include "LED.h"


void InitializePushButtonPortPin (void)
{
	//set P1.3 as an INPUT
	//These are defined in pushbutton.h
	SET_PUSHBUTTON_AS_OUTPUT;
	ENABLE_PULLUP_RESISTOR;
	//INTERRUPT_ON_FALLING_EDGE;
	//ENABLE_PUSHBUTTON_INTERRUPTS;
}


