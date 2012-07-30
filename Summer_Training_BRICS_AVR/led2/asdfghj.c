#include <avr/io.h>
#include <util/delay.h>

main(){
	DDRB=255;

	while(1){
		for(PORTB=1;;PORTB=PORTB*2){
			if(PORTB==0)PORTB=1;
			PORTC=PORTB;
			PORTB=0x5C;

			_delay_ms(100);
		}
			}
}
