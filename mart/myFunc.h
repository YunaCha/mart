#ifndef MYFUNC_H_
#define MYFUNC_H_

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "lcd.h"

void initSystem()
{
	// Register Setting
	DDRA = 0xff;	// 0,1 : Motor | 5,6,7 : RGY LED
	DDRD = 0x0f;	// 0,1,2,3 : Row 0, 1, 2, 3 | 4,5,6,7 : Col 4, 5, 6, 7
	TIMSK = 0x01;
	TCCR0 = 0x07;	// 1024분주
	
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
	sei();	// Global Interrupt Enable
}

void DisplayClock(unsigned int hou, unsigned int min, unsigned sec)
{
	char str[16];
	sprintf(str,"    %02d:%02d:%02d",hou,min,sec);
	lcd_putsf(0,0,(unsigned char *)"    WELCOME!!   ");
	lcd_putsf(0,1,(unsigned char *)str);	
}

#endif