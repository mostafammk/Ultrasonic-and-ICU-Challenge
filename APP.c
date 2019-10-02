/*
 * GccApplication1.c
 *
 * Created: 10/1/2019 12:36:36 PM
 * Author : minam
 */ 


#define F_CPU 8000000ul
#include "ICU.h"
#include "LCD.h"
#include "ULTRS.h"
#include <util/delay.h>

int main(void)
{	
	SERVICE_init();

    while (1) 
    {
		ULTRS_trig();
		//ULTRS_getDistance();
		LCD_CLR();
		LCD_NUM_DISP(0,5,g_Distance);
		_delay_ms(30);
    }
}