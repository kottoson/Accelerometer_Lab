/*
 * TimerA.c
 *
 *  Created on: Mar 15, 2016
 *      Author: Student
 */

#include "timerA.h"
#include "LEDdisplay.h"
#include "LED.h"


void ConfigureTimerA(void)
{
	//set   USE_SMCLK   /1  COUNT_UP CLEAR_TO_START
	TACTL |= TASSEL_2 | ID_0 | MC_1 | TACLR;

	TACCR0   = 1000<<4;// .25ms at 16MHz
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
		DisplayCharValue(high|mid|low);
	else if(g1msTimeout<midThreshold)
		DisplayCharValue(high|mid);
	else if(g1msTimeout<highThreshold)
		DisplayCharValue(high);
	else DisplayCharValue(0);
}

#pragma vector = TIMER0_A0_VECTOR
// Timer a interrupt service routine,
	__interrupt void TimerA0_routine(void)
{
		g1msTimeout++;
		ADCInterruptFlag|=1;//TODO: Set every 10 ms?
}
