/*
 * main.c
 *
 *  Created on: Mar 31, 2016
 *      Author: student
 */
#include <msp430.h>
#include "LED.h" //because the LED's use P1.0, it conflicts with the accelerometer, which uses the same port.
#include "timerA.h"
#include "LEDdisplay.h"
#include "SPI.h"
#include "ADC.h"

// Function prototypes
void ConfigureClockModule(void);
void main(void)
{
	// Stop the watchdog timer, and configure the clock module.
	WDTCTL = WDTPW + WDTHOLD;
	ConfigureClockModule();
	ConfigureLEDDisplayPins();
	ConfigureTimerA();
	ConfigureSPIPins();
	_BIS_SR(GIE);		// interrupts enabled
    //Initialize port pins associated with the LEDs, and then turn off LEDs.
    InitializeLEDPortPins();
    TURN_ON_LED1;
    TURN_OFF_LED2;

	// Infinite loop
    while(1){
    	ManageSoftwareTimers();
    }
}

void ConfigureClockModule(void)
{
    // Configure Digitally Controlled Oscillator (DCO) for 16 MHz using factory
    // calibrations.
	DCOCTL  = CALDCO_16MHZ;
	BCSCTL1 = CALBC1_16MHZ;
}
