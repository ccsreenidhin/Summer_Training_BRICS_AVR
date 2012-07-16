#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>

int main(void) {
	int i, j, k, l;
	char A[20];
	LCDinit();
	LCDclr();
	ADCinit();
	while (1) {
		i = read_adc(0);
		j = read_adc(1);
		k = read_adc(2);
		l = read_adc(3);
		sprintf(A, "%4d%4d%4d%4d", i, j, k, l);
		LCDGotoXY(0, 0);
		LCDdisplay(A);
		_delay_ms(10);
	}
	return 0;
}
