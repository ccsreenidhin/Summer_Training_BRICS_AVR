/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include <avr/io.h>
#include <util/delay.h>

main(){
	DDRA=255;
	LCDinit();
	LCDclr();
	while(1){
	     LCDGotoXY(5,0);
	      LCDdisplay("BRiCS");

	PORTA=1;_delay_ms(1000);
	PORTA=2;_delay_ms(1000);
	PORTA=4;_delay_ms(1000);
	PORTA=8;_delay_ms(1000);
	PORTA=16;_delay_ms(1000);
	PORTA=32;_delay_ms(1000);
	PORTA=64;_delay_ms(1000);
	PORTA=128;_delay_ms(1000);
}

}
