/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>

int main(void)
{
	char A[20]="";
	int i=0;
ADCinit();
LCDinit();
LCDclr();

while(1){
i=read_adc(0);
sprintf(A,"V= %d ",i);
LCDGotoXY(0,0);
LCDdisplay(A);

}
}

