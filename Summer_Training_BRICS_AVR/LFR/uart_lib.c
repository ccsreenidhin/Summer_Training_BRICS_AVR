/*
 * uart_lib.c
 *
 *  Created on: Apr 27, 2011
 *      Author: simplifix
 */


#include<uart_lib.h>


ISR(USART_RXC_vect)
{
	unsigned char c;
	c = UDR;
	rx_buffer[rx_wrindex]=c;
	rx_wrindex++;
	if(rx_wrindex >= rx_buffersize)
	{
		rx_wrindex=0;
		rx_overflow=1;
	}
		uart_status=1;
}



void set_uartbaud(int BAUD)
{
	UBRRH = (unsigned char)((FOSC/16/BAUD-1)>>8);
	UBRRL = (unsigned char)(FOSC/16/BAUD-1);
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UCSRB|=(1<<RXEN)|(1<<TXEN);
}

void disable_uart()
{
	UCSRB&=~(1<<TXEN);
	UCSRB&=~(1<<RXEN);
}



void enable_uart_txcint()
{
	UCSRB|=(1<<TXCIE);
}

void enable_uart_rxcint()
{
	UCSRB|=(1<<RXCIE);
}

void enable_uart_udreint()
{
	UCSRB|=(1<<UDRIE);
}

void disable_uart_txcint()
{
	UCSRB&=~(1<<TXCIE);
}

void disable_uart_rxcint()
{
	UCSRB&=~(1<<RXCIE);
}

void disable_uart_udreint()
{
	UCSRB&=~(1<<UDRIE);
}

void sendchar_uart(char data)
{
	int temp;
	temp=UCSRA&(1<<UDRE);
	temp=temp>>UDRE;
	while(!temp);// wait for UDR empty
	UDR=data;//transmits data
}

char getchar_uart()
{
	while((UCSRA&(1<<RXC)) == 0);// Wait until a byte has been received
	return UDR;	// Return received data
}

void sendstring_uart(char v[])
{
	int i;
	for(i=0;i<strlen(v);i++)
	{
		sendchar_uart(v[i]);
		_delay_ms(10);
	}
}
