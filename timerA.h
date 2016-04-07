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
#define MAX_VALUE 20 //20*.25ms = 5ms period

// Prototypes
void ConfigureTimerA(void);
void ManageSoftwareTimers();
// Global Variables

unsigned char high;
unsigned char mid;
unsigned char low;
unsigned char g1msTimeout;
unsigned char g1msTimer;
unsigned char ADCInterruptFlag;//LSB will be set to 1 every ms
unsigned char highThreshold;
unsigned char midThreshold;
unsigned char lowThreshold;


#endif /* TIMERA_H_ */
