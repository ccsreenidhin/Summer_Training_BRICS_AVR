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
	int i=0;
	char A[20]="";
	LCDinit();
	LCDclr();
	ADCinit();

	while(1){
		i=read_adc(0);
		sprintf(A,"V= %d ",i);
		LCDGotoXY(4,0);
			LCDdisplay(A);
			//LCDshiftRight(1);
	_delay_ms(200);
	}
}

