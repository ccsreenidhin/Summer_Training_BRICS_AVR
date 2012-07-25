/*
 * main.c
 *
 *  Created on: Mar 29, 2012
 *      Author: apple
 */

#include <avr/io.h>
#include <util/delay.h>

main(){
	DDRB=255;
while(1){
	for(PORTB=1;PORTB>100;PORTB=PORTB*2){
		PORTC=PORTB;
		_delay_ms(100);
	}
}
}
