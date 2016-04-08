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
	ConfigureADC();
	InitializeBuffer();
	ConfigureADCDataTransfer();
	ConfigureTimerA();
	InitializePushButtonPortPin();
	ConfigureSPIPins();
	_BIS_SR(GIE);		// interrupts enabled
	InitializeSwitch(&gPushButton,(char *) &P1IN,BIT3);

    //Calibration

	int temp;
	//Calibrate X:
	//set max and min to their initial values
	int xmax=averages.x;
	//Light up correct LED
	DisplayLED(NORTH);
	//while button is not pressed
	Debouncer(&gPushButton);
	while(gPushButton.CurrentState==DbExpectHigh||gPushButton.CurrentState==DbValidateHigh){
		//poll value from ADC
		temp=averages.x;
		//update max
		if(temp>xmax) xmax=temp;
		Debouncer(&gPushButton);
	}
	//set min to its initial value
	int xmin=averages.x;
	//Light up next LED
	DisplayLED(SOUTH);
	//wait for button to be not pressed
	while(gPushButton.CurrentState==DbExpectLow||gPushButton.CurrentState==DbValidateLow){Debouncer(&gPushButton);};
	//while button is not pressed
	while(Debouncer(&gPushButton)==Low){
		//poll value from CORDIC
		temp=averages.x;
		//update max
		if(temp>xmin) xmin=temp;
	}
	origin[0]=(xmax+xmin)<<1;
	//wait for button to be not pressed
	while(Debouncer(&gPushButton)==High);


	//Calibrate Y
	int ymax=averages.y;
	DisplayLED(WEST);
	while(Debouncer(&gPushButton)==Low){
		temp=averages.y;
		if(temp>ymax) ymax=temp;
	}
	int ymin=averages.y;
	DisplayLED(EAST);
	while(Debouncer(&gPushButton)==High);
	while(Debouncer(&gPushButton)==Low){
		temp=averages.y;
		if(temp>ymin) ymin=temp;
	}
	origin[1]=(ymax+ymin)<<1;
	while(Debouncer(&gPushButton)==High);

	//Calibrate Z
	int zmax=averages.z;
	DisplayLED(DISPLAYPLUS);
	while(Debouncer(&gPushButton)==Low){
		temp=averages.z;
		if(temp>zmax) zmax=temp;
	}
	int zmin=averages.z;
	DisplayLED(DISPLAYX);
	while(Debouncer(&gPushButton)==High);
	while(Debouncer(&gPushButton)==Low){
		temp=averages.z;
		if(temp>zmin) zmin=temp;
	}
	origin[2]=(zmax+zmin)<<1;
	while(Debouncer(&gPushButton)==High);


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
