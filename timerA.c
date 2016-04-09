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
	calculations currentReading;
	currentReading.x = averages.x - origin[0];
	currentReading.y = averages.y - origin[1];
	Cordic(&currentReading, 1);
	theta = currentReading.angle >> 8;


	//Determine which led's light up based on the X and Y values (theta)
	//Note that theta values used are 2x the true value (to eliminate any fp math)
	//Values range from -90 degrees to 270 degrees for coders convenience.
	if (theta < -135 || theta > 495) {
		high = SOUTH;
		mid = SOUTHEAST | SOUTHWEST;
		low = EAST | WEST;
	} else if (theta > -135 && theta < -45) {
		high = SOUTHEAST;
		mid = SOUTH | EAST;
		low = SOUTHWEST | NORTHEAST;
	} else if (theta > -45 && theta < 45) {
		high = EAST;
		mid = SOUTHEAST | NORTHEAST;
		low = SOUTH | NORTH;
	} else if (theta > 45 && theta < 135) {
		high = NORTHEAST;
		mid = NORTH | EAST;
		low = NORTHWEST | SOUTHEAST;
	} else if (theta > 135 && theta < 225) {
		high = NORTH;
		mid = NORTHWEST | NORTHEAST;
		low = WEST | EAST;
	} else if (theta > 225 && theta < 315) {
		high = NORTHWEST;
		mid = NORTH | WEST;
		low = NORTHEAST | SOUTHWEST;
	} else if (theta > 315 && theta < 405) {
		high = WEST;
		mid = NORTHWEST | SOUTHWEST;
		low = NORTH | SOUTH;
	} else if (theta > 405 && theta < 495) {
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
