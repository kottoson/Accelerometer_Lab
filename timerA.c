/*
 * TimerA.c
 *
 *  Created on: Mar 15, 2016
 *      Author: Student
 */

#include "timerA.h"
#include "LEDdisplay.h"
#include "ADC.h"
#include "CORDIC.h"
void ConfigureTimerA(void)
{
	//set   USE_SMCLK   /1  COUNT_UP CLEAR_TO_START
	TACTL |= TASSEL_2 | ID_0 | MC_1 | TACLR;

	TACCR0   = 1250<<4;// 1.25ms at 16MHz
	TACCTL0 |= CCIE; //Enable CC interrupts

	high = NORTH;
	mid  = NORTHEAST|NORTHWEST;
	low  = EAST|WEST;
	highThreshold=10;
	 midThreshold=3;
	 lowThreshold=1;

	 theta = 540;
	 phi = 90;
}

void ManageSoftwareTimers(){
	if(g1msTimeout>=MAX_VALUE)
		g1msTimeout=0;
	UpdateLEDs();
	if(g1msTimeout<lowThreshold)
		DisplayLED(high|mid|low);
	else if(g1msTimeout<midThreshold)
		DisplayLED(high|mid);
	else if(g1msTimeout<highThreshold)
		DisplayLED(high);
	else DisplayLED(0);
}

void UpdateLEDs() {
	coordinates currentReading;
	currentReading.x = ((averages.y - origin[1]) << 2) + (averages.y - origin[1]);
	currentReading.y = (averages.x - origin[0]) << 1;
	currentReading.z = ((averages.z - origin[2]) << 2) + (averages.z - origin[2]);
	measurements cordicResults;
	cordicResults = getDisplaySetting(&currentReading);
	theta = cordicResults.angle;
	phi = cordicResults.tilt;

	highThreshold = (unsigned char) (phi >> 9) + 3;
	midThreshold = (unsigned char) (phi >> 10) + 2;
	lowThreshold = (unsigned char) (phi >> 11) + 1;

	if(phi < 200) {
		high = NORTH|SOUTH|EAST|WEST|NORTHEAST|NORTHWEST|SOUTHEAST|SOUTHWEST;
		mid = 0;
		low = 0;
		highThreshold = MAX_VALUE + 1;
		return;
	}

	//Determine which led's light up based on the X and Y values (theta)
	//Note that theta values used are 2x the true value (to eliminate any fp math)
	//Values range from -90 degrees to 270 degrees for coders convenience.
	if (theta > 24750 && theta < 29250) {
		high = SOUTH;
		mid = SOUTHEAST | SOUTHWEST;
		low = EAST | WEST;
	} else if (theta > 29250 && theta < 33750) {
		high = SOUTHEAST;
		mid = SOUTH | EAST;
		low = SOUTHWEST | NORTHEAST;
	} else if (theta > 33750 || theta < 2250) {
		high = EAST;
		mid = SOUTHEAST | NORTHEAST;
		low = SOUTH | NORTH;
	} else if (theta > 2250 && theta < 6750) {
		high = NORTHEAST;
		mid = NORTH | EAST;
		low = NORTHWEST | SOUTHEAST;
	} else if (theta > 6750 && theta < 11250) {
		high = NORTH;
		mid = NORTHWEST | NORTHEAST;
		low = WEST | EAST;
	} else if (theta > 11250 && theta < 15750) {
		high = NORTHWEST;
		mid = NORTH | WEST;
		low = NORTHEAST | SOUTHWEST;
	} else if (theta > 15750 && theta < 20250) {
		high = WEST;
		mid = NORTHWEST | SOUTHWEST;
		low = NORTH | SOUTH;
	} else if (theta > 20250 && theta < 24750) {
		high = SOUTHWEST;
		mid = SOUTH | WEST;
		low = SOUTHEAST | NORTHWEST;
	}
}

#pragma vector = TIMER0_A0_VECTOR
// Timer a interrupt service routine,
	__interrupt void TimerA0_routine(void)
{
		g1msTimeout++;
		g1msTimer++;
		//ADCInterruptFlag|=1;
		ReadSample();
}
