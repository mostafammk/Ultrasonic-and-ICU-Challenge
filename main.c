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
	uint8 L_PWM_arr[4] = {20 , 40 , 60 , 80};
	DDRD |= (1<<4) | (1 << 5);
	SERVICE_init();
	MOTOR_init();
	MOTOR_Forward(MOTOR2);
	//PORTD |= 0x04;
	//DDRD |= (1<<5) ;
	//DDRD |=  (1<<4);
	//PORTD |= (1<<5);
	//PORTD |= (1<<4);
	CHANGE_PWM_T1(1);
/*
	while(1)
	{

	for (uint8 i = 0 ; i < 4 ; i++)
	{
		MOTOR_Forward(MOTOR1);
		MOTOR_Forward(MOTOR2);
		CHANGE_PWM_T1(L_PWM_arr[i]);
		Delay(TIMER0,4000000);
	}

	MOTOR_Stop(MOTOR1);
	MOTOR_Stop(MOTOR2);
	Delay(TIMER0,4000000);

	for (sint8 i = 3 ; i >= 0 ; i--)
	{
		MOTOR_Reverse(MOTOR1);
		MOTOR_Reverse(MOTOR2);
		CHANGE_PWM_T1(L_PWM_arr[i]);
		Delay(TIMER0,4000000);
	}

	MOTOR_Stop(MOTOR1);
	MOTOR_Stop(MOTOR2);
	Delay(TIMER0,4000000);

  }
  */



    while (1)
    {
	    ULTRS_trig();
	    LCD_CLR();
	    LCD_NUM_DISP(0,5,g_Distance);
	    _delay_ms(30);
    }
}
    