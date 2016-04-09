/*
 * ADC.c
 *
 *  Created on: Mar 31, 2016
 *      Author: student
 */

#include "ADC.h"

void ConfigureADC(void) {
	ADC10CTL1 = (INCH_2 | ADC10DIV_1 | ADC10SSEL_3 | CONSEQ_1);
	ADC10AE0 |= BIT0 | BIT1 | BIT2; //Enable ADC10 A0, A1, and A2
	ADC10CTL0 = (SREF_0 | ADC10SHT_3 | ADC10ON | MSC);
}

void ConfigureADCDataTransfer() {
	ADC10DTC0 = ADC10CT;
	ADC10DTC1 = 0x18;
	ADC10SA = (unsigned short) &buffer;
}

void ReadSample() {
	bufferTotal.x -= (buffer[bufferCount].x);
	bufferTotal.y -= (buffer[bufferCount].y);
	bufferTotal.z -= (buffer[bufferCount].z);
	ADC10CTL0 |= ENC | ADC10SC;
	while(ADC10CTL1 & BUSY);
	ADC10CTL0 &= ~ENC;
	bufferTotal.x += (buffer[bufferCount].x);
	bufferTotal.y += (buffer[bufferCount].y);
	bufferTotal.z += (buffer[bufferCount].z);
	bufferCount = (bufferCount + 1 ) & 0x7;
	averages.x = bufferTotal.x >> 3;
	averages.y = bufferTotal.y >> 3;
	averages.z = bufferTotal.z >> 3;
}


void InitializeBuffer() {
	int i;
	for (i=7; i >= 0; i--) {
		buffer[i].x = 0;
		buffer[i].y = 0;
		buffer[i].z = 0;
	}
	averages.x = 0;
	averages.y = 0;
	averages.z = 0;
	bufferTotal.x = 0;
	bufferTotal.y = 0;
	bufferTotal.z = 0;
	bufferCount = 0;

	int origin[]={0,0,0};//X,Y,Z
}
