/*
 * Accelerometer.h
 *
 *  Created on: Mar 31, 2016
 *      Author: student
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 					XOUT
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 	Device		:	Accelerometer (ADXL330)
 * 	Polarity	:	Active High
 * 	PCB Device	:	U2
 * 	PCB TP		:	TP U14 (Red, Top Left)
 * 	GPIO		:	P1.0
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define XOUT_BIT 				BIT0
#define XOUT_PORT 				P1OUT
#define XOUT_DDR 				P1DIR
#define SET_XOUT_AS_INPUT	 	XOUT_DDR &= ~XOUT_BIT

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 					YOUT
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 	Device		:	Accelerometer (ADXL330)
 * 	Polarity	:	Active High
 * 	PCB Device	:	U2
 * 	PCB TP		:	TP U7 (White, Top Left)
 * 	GPIO		:	P1.1
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define YOUT_BIT 				BIT1
#define YOUT_PORT 				P1OUT
#define YOUT_DDR 				P1DIR
#define SET_YOUT_AS_INPUT	 	YOUT_DDR &= ~YOUT_BIT


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 					ZOUT
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 	Device		:	Accelerometer (ADXL330)
 * 	Polarity	:	Active High
 * 	PCB Device	:	U2
 * 	PCB TP		:	TP U8 (Yellow, Bottom Left)
 * 	GPIO		:	P1.2
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define ZOUT_BIT 				BIT2
#define ZOUT_PORT 				P1OUT
#define ZOUT_DDR 				P1DIR
#define SET_ZOUT_AS_INPUT	 	YOUT_DDR &= ~ZOUT_BIT


#endif /* ACCELEROMETER_H_ */
