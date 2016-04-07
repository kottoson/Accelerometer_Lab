/*
 * ADC.h
 *
 *  Created on: Mar 31, 2016
 *      Author: student
 */

#ifndef ADC_H_
#define ADC_H_
#include <msp430.h>
void ConfigureADC(void);
void ConfigureADCDataTransfer(char startAddress);
void ReadSample();

#endif /* ADC_H_ */
