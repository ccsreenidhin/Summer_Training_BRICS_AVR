/*
 * gsm_lib.c
 *
 *  Created on: Jun 8, 2011
 *      Author: simtwo
 */

#include <gsm_lib.h>


void send_gsm()
{
	LCDGotoXY(0,1);
	LCDstring(command,16);
	sprintf(rx_buffer,"%c",02);
	rx_wrindex=0;
	sendstring_uart(command);
	_delay_ms(100);
	sendchar_uart(0x0d);
}


void fetch()
{
	int i;
	for(i=0;i<rx_wrindex;i++)
	{
		if(i==0)
			sprintf(uart_buffer,"%c",rx_buffer[i]);
		else
			sprintf(uart_buffer,"%s%c",uart_buffer,rx_buffer[i]);
	}
}
int check_gsm()
{
	rx_wrindex=0;
	sprintf(command,"AT");
	send_gsm();
	_delay_ms(100);
	fetch();
	if(strstr(uart_buffer,"OK"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int enable_echo_gsm()
{
	sprintf(command,"ATE1");
	send_gsm();
	_delay_ms(100);
	sprintf(uart_buffer,"%s",rx_buffer);
	if(strstr(uart_buffer,"OK"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int disable_echo_gsm()
{
	sprintf(command,"ATE0");
	send_gsm();
	_delay_ms(100);
	sprintf(uart_buffer,"%s",rx_buffer);
	if(strstr(uart_buffer,"OK"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int check_sim_gsm()
{
	sprintf(command,"AT+CIMI");
	send_gsm();
	_delay_ms(500);
	sprintf(uart_buffer,"%s",rx_buffer);
	if(strstr(uart_buffer,"+CME ERROR:"))
		return 0;
	else
		return 1;
}

int check_network_gsm()
{
	int net=0;
	sprintf(command,"AT+CSQ");
	send_gsm();
	_delay_ms(500);
	sprintf(uart_buffer,"%s",rx_buffer);
	LCDGotoXY(0,1);
	LCDstring(uart_buffer,16);
	net=(uart_buffer[8]-0x30)*10+(uart_buffer[9]-0x30);
	if(net==99)
		network=0;
	else
		network=1;
	return network;

}

void init_gsm()
{
	while(!check_gsm())
	{
		sprintf(lcd_buffer,"   CHECK GSM    ");
		LCDGotoXY(0,0);
		LCDdisplay(lcd_buffer);
	}
	LCDclr();
	sprintf(lcd_buffer,"   GSM found    ");
	LCDGotoXY(0,0);
	LCDdisplay(lcd_buffer);
	while(!disable_echo_gsm())
	{
		sprintf(lcd_buffer,"Operation failed");
		LCDGotoXY(0,0);
		LCDdisplay(lcd_buffer);
	}
	LCDclr();
	while(!check_sim_gsm())
	{
		sprintf(lcd_buffer,"   INSERT SIM   ");
		LCDGotoXY(0,0);
		LCDdisplay(lcd_buffer);
	}
	LCDclr();
	sprintf(lcd_buffer,"   SIM found    ");
	LCDGotoXY(0,0);
	LCDdisplay(lcd_buffer);
	while(!check_network_gsm())
	{
		sprintf(lcd_buffer,"   NO NETWORK   ");
		LCDGotoXY(0,0);
		LCDdisplay(lcd_buffer);
	}
	caller_id();
	LCDclr();
	LCDGotoXY(0,0);
	sprintf(lcd_buffer,"GSM INITIALIZED ");
	LCDdisplay(lcd_buffer);
}

int caller_id()
{
	sprintf(command,"AT+CLIP=1");
	send_gsm();
	_delay_ms(100);
	sprintf(uart_buffer,"%s",rx_buffer);
	if(strstr(uart_buffer,"OK"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int send_sms_gsm(char number[],char msg[])
{
	sprintf(command,"AT+CMGS=\"+91");
	strncat(command,number,10);
	strcat(command,"\"");
	send_gsm();
	_delay_ms(500);
	sprintf(uart_buffer,rx_buffer);
	if(strstr(uart_buffer,">"))
	{
		strcpy(command,msg);
		send_gsm();
		_delay_ms(100);
		sendchar_uart(0x1a);
		uart_status=0;
	}

	rx_wrindex=0;
	while(!uart_status)
	{
		sprintf(lcd_buffer,"  Sending SMS   ");
		LCDGotoXY(0,0);
		LCDdisplay(lcd_buffer);
	}
	uart_status=0;
	_delay_ms(500);
	sprintf(uart_buffer,rx_buffer);
	if(strstr(uart_buffer,"+CMGS: "))
		return 1;
	else
		return 0;
}

int delete_sms_gsm(int val)
{
	sprintf(command,"AT+CMGD=%d",val);
	send_gsm();
	_delay_ms(1000);
	sprintf(uart_buffer,"%s",rx_buffer);
	if(strstr(uart_buffer,"OK"))
	{
		LCDGotoXY(0,3);
		LCDdisplay("SMS deleted");
		return 1;
	}
	else
	{
		return 0;
	}
}

void read_sms_gsm(int val)
{
	int temp=0,i,j=0,sms=0;
	sprintf(command,"AT+CMGR=%d",val);
	send_gsm();
	uart_status=0;
	while(!uart_status)
	{
		sprintf(lcd_buffer,"  Reading SMS   ");
		LCDGotoXY(0,0);
		LCDdisplay(lcd_buffer);
	}
	_delay_ms(1000);
	uart_status=0;
	sprintf(uart_buffer,"%s",rx_buffer);
	for(i=0;i<strlen(uart_buffer);i++)
	{
		if(uart_buffer[i]=='"')
		{
			temp++;
			j=0;
		}
		else
		{
			switch (temp)
			{
				case 3:
					if(j==3)
						sprintf(new_sms_num,"%c",uart_buffer[i]);
					else
						sprintf(new_sms_num,"%s%c",new_sms_num,uart_buffer[i]);
					j++;
					break;
				case 6:
					if(j==2)
						sprintf(new_sms,"%c",uart_buffer[i]);
					else
						sprintf(new_sms,"%s%c",new_sms,uart_buffer[i]);
					j++;
					break;
				case 8:
					if(j>2 && uart_buffer[i]==0x0d)
					{
						sms=1;
						break;
					}
					if(sms==0)
					{
						if(j==2)
							sprintf(new_sms,"%c",uart_buffer[i]);
						else
							sprintf(new_sms,"%s%c",new_sms,uart_buffer[i]);
						j++;
					}
					break;
			}
		}
	}
	delete_sms_gsm(val);
	LCDclr();
	LCDGotoXY(0,1);
	LCDdisplay(new_sms_num);
	LCDGotoXY(0,2);
	if(strlen(new_sms>20))
		LCDstring(new_sms,20);
	else
		LCDdisplay(new_sms);
	uart_status=0;
}



void process_gsm()
{
	_delay_ms(500);
	uart_status=0;
	sprintf(uart_buffer,"%s",rx_buffer);
	if(chk_sms())
	{

	}
	else
	{
		chk_call();
	}
	rx_wrindex=0;
	sprintf(rx_buffer,"%c",0x30);
}



int chk_sms()
{

	if(strstr(uart_buffer,"+CMTI:"))
	{
		LCDGotoXY(0,1);
		LCDdisplay("new SMS");
		_delay_ms(1000);
		read_sms_gsm(1);
		delete_sms_gsm(1);
		LCDGotoXY(0,0);
		LCDstring(new_sms,16);
		LCDGotoXY(0,1);
		LCDdisplay(new_sms_num);

		if(strncmp(new_sms,"ON",2)==0)
		{
			PORTB=0xff;
		}
		else if(strncmp(new_sms,"OFF",3)==0)
		{
			PORTB=0x00;
		}
		else
		{
		}
		return 1;
	}
	else
		return 0;
}


int chk_call()
{
	char temp[20],temp1[20],temp2[20];
	if(strstr(uart_buffer,"RING"))
	{
		call_id();
		LCDGotoXY(0,0);
		LCDdisplay(new_call_num);
		LCDGotoXY(0,1);
		LCDdisplay("NEW CALL");
		_delay_ms(1000);
		return 1;
	}
	else
		return 0;
}


void call_id()
{

	int temp=0,i,j=0,sms=0;
	for(i=0;i<strlen(uart_buffer);i++)
	{
		if(uart_buffer[i]=='"')
		{
			temp++;
			j=0;
		}
		else
		{
			switch (temp)
			{
				case 1:
					if(j==3)
						sprintf(new_call_num,"%c",uart_buffer[i]);
					else
						sprintf(new_call_num,"%s%c",new_call_num,uart_buffer[i]);
					j++;
					break;
			}
		}
	}
}

void dial(char num[])
{
	sprintf(command,"ATD+91%s;",num);
	send_gsm();
}
