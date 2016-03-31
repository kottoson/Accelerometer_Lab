/*
 * TimerA.c
 *
 *  Created on: Mar 15, 2016
 *      Author: Student
 */

#include "timerA.h"
#include "LEDdisplay.h"
#include "LED.h"

#define ONE_MILLISECOND 1000 // 1000 cycles at 1MHz lasts 1ms
#define ONE_HALF_SECOND	62500 //62500 cycles at 1MHz in div 8 lasts 500ms
unsigned char send=0;
void ConfigureTimerA(void)
{
	//set   USE_SMCLK    /8  COUNT_UP CLEAR_TO_START
	TACTL |= TASSEL_2 | ID_0 | MC_1 | TACLR;

	TACCR0 = ONE_MILLISECOND<<5; //To get 1ms period
	TACCTL0 |= CCIE; //Enable CC interrupts

	TACCR1 = (unsigned int) 0b1111111100; //the initial value of "count"
	TACCTL1 = CCIE; //Enable CC interrupts for PWM
}

#pragma vector = TIMER0_A0_VECTOR
// Timer a interrupt service routine,
	__interrupt void TimerA0_routine(void)
{
//		if (!TACCR1 == 0) TURN_ON_LED1; //don't even turn on the LED if the duty cycle is 0%
//		else TURN_OFF_LED1;
//		g1mSTimeout ++;
		send++;
		if (send>=0x8) send=0;
		DisplayCharValue(~displayArr[send]);
		TOGGLE_LED1;
}


#pragma vector=TIMER0_A1_VECTOR
	__interrupt void Timer0_A1(void)
	{
		switch(__even_in_range(TAIV, 10))
		{
			case 2: {
				TURN_OFF_LED1;
				break;
			}
			case 10: {
				break;
			}
		}
	}
