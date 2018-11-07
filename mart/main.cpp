#include "myFunc.h"

unsigned int tCount = 0, hou = 0, min = 0, sec = 0;
int mode = NORMAL_MODE;

ISR(TIMER0_OVF_vect)
{
	tCount++;
	if (tCount >= 61)
	{
		// 1 second
		sec++;
		if (sec > 59) { min++; sec = 0; }
		if (min > 59) { hou++; min = 0; }
		if (hou > 23) { hou = min = sec = 0; }
		tCount = 0;
	}
}

int main(void)
{
	initSystem();
	unsigned char inputKey = 0;
    while (1) 
    {
		inputKey = getKey();
		if (mode == NORMAL_MODE)
		{
			DisplayClock(hou,min,sec);			
			if (inputKey == KEY_MENU) mode = MENU_MODE;			
		}
		else if (mode == MENU_MODE)
		{
			lcd_putsf(0,0,(unsigned char *)"1: Calculation  ");
			lcd_putsf(0,1,(unsigned char *)"1: Total Sales  ");
			if (inputKey == KEY_1) mode = CALC_MODE;
			else if (inputKey == KEY_2) mode = TOTAL_MODE;
			inputKey = 0;
			_delay_ms(50);
		}
		else if (mode == CALC_MODE)
		{
			lcd_putsf(0,0,(unsigned char *)"Calculation Mode  ");
		}
		else if (mode == TOTAL_MODE)
		{
			lcd_putsf(0,0,(unsigned char *)"Total Sales Mode  ");
		}
		// Whenever client push the lobby key, then go back to normal mode.		
		if (inputKey == KEY_LOBBY) mode = NORMAL_MODE;
    }
}

