#include <avr/io.h>
#include <util/delay.h>

main() {
	DDRB=255;

	while(1){
	PORTB=1;_delay_ms(100);
	PORTB=2;_delay_ms(100);
	PORTB=4;_delay_ms(100);
	PORTB=8;_delay_ms(100);
	PORTB=16;_delay_ms(100);
	PORTB=32;_delay_ms(100);
	PORTB=64;_delay_ms(100);
	PORTB=128;_delay_ms(100);
	}
}
