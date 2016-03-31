/*
 * TimerA.h
 *
 *  Created on: Mar 15, 2016
 *      Author: K. Ottoson (kjo9fq)
 */

#ifndef TIMERA_H_
#define TIMERA_H_

#include <msp430.h>

#define DOWN 0
#define UP 1

// Prototypes
void ConfigureTimerA(void);

// Global Variables
unsigned char g1mSTimeout;
unsigned int g1msTimer;
int direction;



#endif /* TIMERA_H_ */
