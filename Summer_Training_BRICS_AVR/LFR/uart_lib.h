/*
 * uart_lib.h
 *
 *  Created on: Apr 27, 2011
 *      Author: simplifix
 */
#include<main.h>

#define FOSC 4000000// Clock Speed


#define rx_buffersize 150

char rx_buffer[rx_buffersize];
char uart_buffer[rx_buffersize];
int rx_wrindex;
int rx_overflow;
int uart_status;



void set_uartbaud(int );

void disable_uart();

void enable_uart_txcint();

void enable_uart_rxcint();

void enable_uart_udreint();

void disable_uart_txcint();

void disable_uart_rxcint();

void disable_uart_udreint();

void sendchar_uart(char);

char getchar_uart();

void sendstring_uart(char []);


