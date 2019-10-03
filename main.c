/*
 * GccApplication1.c
 *
 * Created: 10/1/2019 12:36:36 PM
 * Author : minam
 */ 



#include "Service.h"



int main(void)
{	
uint8 L_PWM_arr[5] = {20 , 40 , 60 , 80 , 100};
	//DDRD |= (1<<4) | (1 << 5);
	SERVICE_init();
	
	DDRD |= (1<<5) ;
	DDRD |=  (1<<4);
	DDRD |= (1<<2) | (1<<3) | (1<<6) |(1<<7);
	//CHANGE_PWM_T1(1);
	 LCD_CLR();
	LCD_String_DISP(0,0,"Speed = ");
	while(1)
	{

	for (uint8 i = 0 ; i < 5 ; i++)
	{
		MOTOR_Forward(MOTOR1);
		MOTOR_Forward(MOTOR2);
		CHANGE_PWM_T1(L_PWM_arr[i]);
		LCD_NUM_DISP(0,7,L_PWM_arr[i]);
		Delay(TIMER0,4000000);
	}

		LCD_String_DISP(0,0,"Speed =        ");
	for (sint8 i = 3 ; i >= 0 ; i--)
	{
		MOTOR_Forward(MOTOR1);
		MOTOR_Forward(MOTOR2);
		CHANGE_PWM_T1(L_PWM_arr[i]);
		LCD_NUM_DISP(0,7,L_PWM_arr[i]);
		Delay(TIMER0,4000000);
	}

	MOTOR_Stop(MOTOR1);
	MOTOR_Stop(MOTOR2);
	LCD_NUM_DISP(0,7,0);
	Delay(TIMER0,4000000);

  }
  
/*
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
	*/
}
    