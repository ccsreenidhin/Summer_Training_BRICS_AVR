/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
int main(void) {
	LCDinit();
	LCDclr();
	ADCinit();
	int i = 0;
	char A[30] = "";
	while (1) {
		i = read_adc(0);
		sprintf(A, "value= %d ", i);
		LCDGotoXY(0, 0);
		LCDdisplay(A);
		LCDGotoXY(0, 1);
		if (i > 500)
			LCDdisplay("BLACK ");
		else
			LCDdisplay("WHITE ");
	}

}

