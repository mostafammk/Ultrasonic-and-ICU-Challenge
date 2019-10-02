/*
 * GccApplication1.c
 *
 * Created: 10/1/2019 12:36:36 PM
 * Author : minam
 */ 

//#include <avr/io.h>
#define F_CPU 8000000ul
#include "ICU.h"
#include "LCD.h"
#include "ULTRS.h"
#include <util/delay.h>

int main(void)
{	
	ULTRS_init();
	ICU_init();
	INTP0_vidEnabled();
	DIO_Init();
	LCD_INIT_4bit();

	static uint16 L_count=0;
    while (1) 
    {
		ULTRS_trig();
		//ULTRS_getDistance();
		LCD_CLR();
		LCD_NUM_DISP(0,5,g_Distance);
		_delay_ms(50);
    }
}

//
//if(L_Distance!=g_Distance)
//{
	//L_Distance=g_Distance;
	//ULTRS_trig();
	//
	////L_count++;
//}
//LCD_CLR();
//LCD_NUM_DISP(0,5,g_Distance);
////LCD_String_DISP(0,0,"                ");
//
//_delay_ms(10);