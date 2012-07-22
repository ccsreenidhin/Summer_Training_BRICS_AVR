/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>


int main(void){
	int i=0;
	char A[20];
LCDinit();
LCDclr();
while (1)
     {
	i++;
///	A="RAJIV SHANKAR SINHA";
	sprintf(A,"VALUE: %d %d %d %d ",i,j,k,l);
      LCDGotoXY(0,0);
      LCDdisplay(A);
      _delay_ms(1000);

      }
return 0;
}

