/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
LCDinit();
LCDclr();
while (1)
     {
      LCDGotoXY(5,0);
      LCDdisplay("BRiCS");
      _delay_ms(10);

      }
return 0;
}

