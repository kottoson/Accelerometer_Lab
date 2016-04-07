/*
 * TimerA.c
 *
 *  Created on: Mar 15, 2016
 *      Author: Student
 */

#include "timerA.h"
#include "LEDdisplay.h"
<<<<<<< HEAD
=======

>>>>>>> origin/master


void ConfigureTimerA(void)
{
	//set   USE_SMCLK   /1  COUNT_UP CLEAR_TO_START
	TACTL |= TASSEL_2 | ID_0 | MC_1 | TACLR;

<<<<<<< HEAD
	TACCR0   = 1250<<4;// 1.25ms at 16MHz
=======
	TACCR0   = 1250<<4;// .25ms at 16MHz
>>>>>>> origin/master
	TACCTL0 |= CCIE; //Enable CC interrupts

	high = NORTH;
	mid  = NORTHEAST|NORTHWEST;
	low  = EAST|WEST;
	highThreshold=10;
	 midThreshold=3;
	 lowThreshold=1;
}

void ManageSoftwareTimers(){
	if(g1msTimeout>=MAX_VALUE)
		g1msTimeout=0;
	if(g1msTimeout<lowThreshold)
		DisplayLED(high|mid|low);
	else if(g1msTimeout<midThreshold)
		DisplayLED(high|mid);
	else if(g1msTimeout<highThreshold)
		DisplayLED(high);
	else DisplayLED(0);
}

#pragma vector = TIMER0_A0_VECTOR
// Timer a interrupt service routine,
	__interrupt void TimerA0_routine(void)
{
		g1msTimeout++;
		g1msTimer++;
		ADCInterruptFlag|=1;
}
