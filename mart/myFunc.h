#ifndef MYFUNC_H_
#define MYFUNC_H_

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

void initSystem()
{
	// Register Setting
	DDRA = 0xff;	// 0,1 : Motor | 5,6,7 : RGY LED
	DDRD = 0x0f;	// 0,1,2,3 : Row 0, 1, 2, 3 | 4,5,6,7 : Col 4, 5, 6, 7
	lcd_init();
	lcd_clear();
	for (int i=0; i<2; i++)
	{
		lcd_putsf(0,0,(unsigned char *)"     MARKET     ");
		lcd_putsf(0,1,(unsigned char *)"     SYSTEM     ");	
		PORTA = 0b00000000;
		_delay_ms(100);
		lcd_clear();
		PORTA = 0b11100000;
		_delay_ms(100);
	}	
}

#endif