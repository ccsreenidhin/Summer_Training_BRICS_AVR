/*
 * global.h
 *
 *  Created on: Jun 8, 2011
 *      Author: simtwo
 */

#ifndef MAIN_H_
#define MAIN_H_

//header files
#include <avr/io.h>

#include <avr/interrupt.h>
#include <util/delay.h>

#include <lcd_lib.h>
#include <uart_lib.h>
#include <gsm_lib.h>

#include <string.h>

char lcd_buffer[16];

#endif /* MAIN_H_ */
