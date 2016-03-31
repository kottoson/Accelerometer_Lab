/*
 * main.c
 *
 *  Created on: Mar 31, 2016
 *      Author: student
 */
#include <msp430.h>
#include "LED.h"

// Function prototypes
void ConfigureClockModule(void);
void TimeDelay(unsigned int delay, unsigned int resolution);
void main(void)
{
	// Stop the watchdog timer, and configure the clock module.
	WDTCTL = WDTPW + WDTHOLD;
	ConfigureClockModule();

    // Initialize port pins associated with the LEDs, and then turn off LEDs.
    InitializeLEDPortPins();
    TURN_ON_LED1;
    TURN_OFF_LED2;

	// Infinite loop
}

void ConfigureClockModule(void)
{
    // Configure Digitally Controlled Oscillator (DCO) for 16 MHz using factory
    // calibrations.
	DCOCTL  = CALDCO_1MHZ;
	BCSCTL1 = CALBC1_1MHZ;
}
