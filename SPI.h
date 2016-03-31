/* Ottoson, K. (kjo9fq) 2/16/2016
 * SPI.h
 *
 * Contains header information for serialFlash.c
 */

#ifndef SPI_H_
#define SPI_H_

#include <msp430.h>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 					SERIAL INPUT
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 	Device		:	7-Segment Display LED Drivers
 * 	PCB Device	:	U10 and U13
 * 	PCB TP		:	TP12
 * 	GPIO		:	P1.7
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define SERIAL_IN_BIT 				BIT7
#define SERIAL_IN_PORT 				P1OUT
#define SERIAL_IN_DDR 				P1DIR
#define SET_SERIAL_IN_AS_OUTPUT 	SERIAL_IN_DDR |= SERIAL_IN_BIT
#define SET_SERIAL_IN_HIGH			SERIAL_IN_PORT |= SERIAL_IN_BIT
#define SET_SERIAL_IN_LOW			SERIAL_IN_PORT &= ~SERIAL_IN_BIT
#define TOGGLE_SERIAL_IN			SERIAL_IN_PORT ^= SERIAL_IN_BIT

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 					SYSTEM CLOCK
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 	Device		:	7-Segment Display LED Drivers
 * 	PCB Device	:	U10 and U13
 * 	PCB TP		:	TP11
 * 	GPIO		:	P1.5
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define SCLK_BIT 				BIT5
#define SCLK_PORT 				P1OUT
#define SCLK_DDR 				P1DIR
#define SET_SCLK_AS_OUTPUT 		SCLK_DDR |= SCLK_BIT
#define SET_SCLK_HIGH			SCLK_PORT |= SCLK_BIT
#define SET_SCLK_LOW			SCLK_PORT &= ~SCLK_BIT
#define TOGGLE_SCLK				SCLK_PORT ^= SCLK_BIT


void ConfigureSPIPins(void);
void SPISendByte(unsigned char byte_value);
void SPIClockToggle();


#endif /* SPI_H_ */
