/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
main() {
	int i = 0;
	char A[30] = "";
	LCDinit();
	LCDclr();
	ADCinit();
	while (1) {
		i=read_adc(0);
		LCDGotoXY(0, 0);
		sprintf(A, "value= %d", i);
		LCDdisplay(A);
		LCDGotoXY(3, 1);
		if(i>500)
		LCDdisplay("BLACK");
		else
			LCDdisplay("white");


		//LCDshiftRight(1);
		_delay_ms(100);
	}

}

