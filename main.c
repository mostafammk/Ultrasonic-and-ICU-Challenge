/*
 * GccApplication1.c
 *
 * Created: 10/1/2019 12:36:36 PM
 * Author : minam
 */ 


#define F_CPU 8000000ul
#include "Service.h"



int main(void)
{	
//uint8 L_PWM_arr[4] = {20 , 40 , 60 , 80};
//DDRD |= (1<<4) | (1 << 5);
	
	//MOTOR_init();
	//MOTOR_Forward(MOTOR2);
	//PORTD |= 0x04;
	//DDRD |= (1<<5) ;
	//DDRD |=  (1<<4);
	//PORTD |= (1<<5);
	//PORTD |= (1<<4);
	//CHANGE_PWM_T1(1);
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

  uint8 objCounter = 0;
  uint8 prevDistance = 0;
  	
  	DDRD |= (1<<5) ;
  	DDRD |=  (1<<4);
  
  SERVICE_init();
    while (1)
    {

	    ULTRS_trig();
	    LCD_CLR();
		LCD_String_DISP(0,0,"Dis:");
	    LCD_NUM_DISP(0,8,g_Distance);
		//LCD_NUM_DISP(1,0,object_counts);
		if((prevDistance==200) && (g_Distance < 200))
		{
			objCounter++;
		}
		LCD_String_DISP(1,0,"Count:");
		LCD_NUM_DISP(1,8,objCounter);

	    Delay(TIMER0,30000);

		prevDistance = g_Distance;

		if(g_Distance<=20)
		{
		CHANGE_PWM_T1(100);
		}

		else if(g_Distance<=40)
		{
		CHANGE_PWM_T1(g_Distance*2);
		}
		else
		{
		CHANGE_PWM_T1(0);
		}
    }
}
    