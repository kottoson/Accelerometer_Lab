/* Ottoson, K. (kjo9fq) 2/16/2016
 * SPI.c
 *
 * Contains source code relating to SPI operations.
 */

#include "SPI.h"


void ConfigureSPIPins(void) {
	SET_SERIAL_IN_AS_OUTPUT;
	SET_SCLK_AS_OUTPUT;

	SET_SERIAL_IN_LOW;
	SET_SCLK_LOW;
}

/*============================================================
 * SPISendByte
 * ===========================================================
 * Sends one byte serially to the LED Drivers for the
 * 7-segment LED displays (LSB first).
 *
 * Input:
 * byte_value:  the byte being sent
 *
 * Notes:
 * This code should be sent twice to give both displays a
 * new value. Send the value for the right display (LSB) and
 * then the value for the left display
 *
 * Toggle the latch to display the new values once they have
 * been sent
 * ===========================================================
 */
void SPISendByte(unsigned char byte_value) {
	SET_SCLK_LOW;
	int i;
	for(i=8; i>0; i-=1) {
		SET_SERIAL_IN_LOW;
		if(byte_value & BIT7) SET_SERIAL_IN_HIGH;
		byte_value <<= 1;
		SET_SCLK_HIGH;
		SET_SCLK_LOW;
	}
}

/*===========================================================
 * SPIClockToggle
 *===========================================================
 * Toggles the clock High to Low after initially setting the
 * clock to low
 *
 * ==========================================================
 */
void SPIClockToggle() {
	int i;
	SET_SCLK_LOW;
	for(i = 8; i > 0; i--) {
		SET_SCLK_HIGH;
		SET_SCLK_LOW;
	}
}



