#include "myFunc.h"
#define NORMAL_MODE 0
#define MENU_MODE 1
#define CALC_MODE 2
#define TOTAL_MODE 3

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
    while (1) 
    {
		if (mode == NORMAL_MODE)
		{
			DisplayClock(hou,min,sec);			
			_delay_ms(100);
		}
    }
}

