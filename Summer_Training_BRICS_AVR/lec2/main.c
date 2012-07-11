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

	PORTB=0b00000001;
	_delay_ms(1000);
	PORTB=0b00000010;
	_delay_ms(1000);
	PORTB=0b00000100;
	_delay_ms(1000);
	PORTB=0b00001000;
	_delay_ms(1000);

}
