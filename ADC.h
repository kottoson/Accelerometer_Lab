/*
 * ADC.h
 *
 *  Created on: Mar 31, 2016
 *      Author: student
 */

#ifndef ADC_H_
#define ADC_H_
#include <msp430.h>
//Prototypes
void ConfigureADC(void);
void ConfigureADCDataTransfer();
void ReadSample();
void InitializeBuffer();

//Structs and Enums
typedef struct {
	unsigned int z, y, x;
} sample;

//Global Variables
sample buffer[8];
sample bufferTotal;
sample averages;
char bufferCount;
int origin[3];//X,Y,Z

#endif /* ADC_H_ */
