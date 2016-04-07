/*
 * main.c
 *
 *  Created on: Mar 31, 2016
 *      Author: student
 */
#include <msp430.h>
#include "timerA.h"
#include "pushbutton.h"
#include "LEDdisplay.h"
#include "SPI.h"
#include "ADC.h"
#include "pushbutton.h"
#include "debounce.h"
SwitchDefine gPushButton;
int origin[]={0,0,0};//X,Y,Z
// Function prototypes
void ConfigureClockModule(void);
void main(void)
{
	// Stop the watchdog timer, and configure the clock module.
	WDTCTL = WDTPW + WDTHOLD;
	ConfigureClockModule();
	ConfigureLEDDisplayPins();
	ConfigureTimerA();
	InitializePushButtonPortPin();
	ConfigureSPIPins();
<<<<<<< HEAD
	//TODO: Configure ADC, Configure ADC transfer?
	_BIS_SR(GIE);		// interrupts enabled
	InitializePushButtonPortPin();
	InitializeSwitch(&gPushButton,(char *) &P1IN,(unsigned char) BIT3);


    //Calibration

	int temp=0;
	//Calibrate X:
	//set max and min to their initial values
	int xmax=0/*TODO:pollX()*/;
	//Light up correct LED
	DisplayLED(NORTH);
	//while button is not pressed
	while(Debouncer(&gPushButton)==Low){
		//poll value from ADC
		temp=0/*pollX()*/;
		//update max
		if(temp>xmax) xmax=temp;
	}
	//set min to its initial value
	int xmin=0/*TODO:pollX()*/;
	//Light up next LED
	DisplayLED(SOUTH);
	//wait for button to be not pressed
	while(Debouncer(&gPushButton)==High);
	//while button is not pressed
	while(Debouncer(&gPushButton)==Low){
		//poll value from CORDIC
		temp=0/*pollX()*/;
		//update max
		if(temp<xmin) xmin=temp;
	}
	origin[0]=(xmax+xmin)<<1;
	//wait for button to be not pressed
	while(Debouncer(&gPushButton)==High);


	//Calibrate Y
	int ymax=0/*TODO:pollY()*/;
	DisplayLED(WEST);
	while(Debouncer(&gPushButton)==Low){
		temp=0/*TODO:pollY()*/;
		if(temp>ymax) ymax=temp;
	}
	int ymin=0/*TODO:pollY()*/;
	DisplayLED(EAST);
	while(Debouncer(&gPushButton)==High);
	while(Debouncer(&gPushButton)==Low){
		temp=0/*TODO:pollY()*/;
		if(temp<ymin) ymin=temp;
	}
	origin[1]=(ymax+ymin)<<1;
	while(Debouncer(&gPushButton)==High);

	//Calibrate Z
	int zmax=0/*TODO:pollZ()*/;
	DisplayLED(DISPLAYPLUS);
	while(Debouncer(&gPushButton)==Low){
		temp=0/*TODO:pollZ()*/;
		if(temp>zmax) zmax=temp;
	}
	int zmin=0/*TODO:pollZ()*/;
	DisplayLED(DISPLAYX);
	while(Debouncer(&gPushButton)==High);
	while(Debouncer(&gPushButton)==Low){
		temp=0/*TODO:pollZ()*/;
		if(temp<zmin) zmin=temp;
	}
	origin[2]=(zmax+zmin)<<1;
	while(Debouncer(&gPushButton)==High);

=======
	ConfigureADC();


	_BIS_SR(GIE);		// interrupts enabled
    //Initialize port pins associated with the LEDs, and then turn off LEDs.
>>>>>>> origin/master

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
