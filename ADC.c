/*
 * ADC.c
 *
 *  Created on: Mar 31, 2016
 *      Author: student
 */


void ConfigureADC(void) {
	ADC10CTL1 = (INCH_2 | ADC10DIV_1 | ADC10SSEL_3 | CONSEQ_1);
	ADC10AE0 |= BIT0; //Enable ADC10 A0 (P1.0)
	ADC10CTL0 = (SREF_0 | ADC10SHT_3 | ADC10ON);
}

void ConfigureADCDataTransfer(char startAddress) {
	ADC10DTC0 = ADC10CT;
	ADC10SA = startAddress << 1;
	ADC10DTC1 = 3;
}

void ReadSample() {
	ADC10CTL0 |= ENC | ADC10SC;
	while(ADC10CTL1 & BUSY);
	ADC10CTL0 &= ~ENC;
}
