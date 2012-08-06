/*
 * gsm.c
 *
 *  Created on: Jun 8, 2011
 *      Author: simtwo
 */

#include <main.h>

void main()
{
	char A[20]="";
			int i=0;
	//DDRB=0xff;
	LCDinit();
	LCDclr();
	set_uartbaud(9600);
	enable_uart_rxcint();
	sei();
	init_gsm();
	LCDclr();
	delete_sms_gsm(1);
	_delay_ms(3000);
	//send_sms_gsm("8601521610","hai");
	//while(1)


		ADCinit();
		LCDinit();
		LCDclr();


		i=read_adc(0);
		sprintf(A,"V= %d ",i);
		LCDGotoXY(0,0);
		LCDdisplay(A);
		while(1)
		{
		if(uart_status==1)
		{
			process_gsm();
			if(strncmp(new_call_num,"8601521610",10)==0)

			{
				sprintf(command,"ATH");
				send_gsm();
				_delay_ms(2000);
			send_sms_gsm( "8765696248",A);}
		}
		else
			_delay_ms(100);
		}

}
