/******************************************************************************
 *
 * Module: UltraSonic
 *
 * File Name: ULTRS.c
 *
 * Description: source file containing functions definitions
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/
 #define F_CPU 8000000ul
#include "ULTRS.h" 
#include <util/delay.h>

float32 g_Distance = 0;


void ULTRS_init(void){
	ICU_setCallBack(ULTRS_getDistance);
}

void ULTRS_getDistance(void){
	float32 local_Distance =0;
	//local_Distance = (float32)Velocity * G_Pulse_time ;
	//local_Distance = (0.034 * G_Pulse_time);
	//local_Distance = 150u / 58u ;

	//local_Distance = ((0.034)*G_Pulse_time)/2;
	if (G_Pulse_time < 11764)
	{
		local_Distance = (G_Pulse_time * Velocity) / 2.0;
		DIO_Write(PORT_D,HIGH);
		g_Distance = local_Distance;
	}
	else
	{
		g_Distance = 200;
	}
	

}

void ULTRS_trig(void){
	//DDRB|=(1<<0);
	//PORTB|=(1<<0);
	DIO_Write(Trig , HIGH);
	Delay(TIMER0 , 1000);

	DIO_Write(Trig , LOW);
	//PORTB&=~(1<<0);
}
