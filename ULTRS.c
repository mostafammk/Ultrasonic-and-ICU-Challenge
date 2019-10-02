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


float32 g_Distance = 0;


void ULTRS_init(void){
	ICU_setCallBack(ULTRS_getDistance);
}

void ULTRS_getDistance(void){
	float32 local_Distance =0;
	if (G_Pulse_time < 11764)
	{
		local_Distance = (G_Pulse_time * Velocity) / 2.0;
		//DIO_Write(PORT_D,HIGH);
		g_Distance = local_Distance;
		
	}
	else
	{
		g_Distance = 200;
	}
	

}

void ULTRS_trig(void){
	DIO_Write(Trig , HIGH);
	Delay(TIMER0 , 1000);
	DIO_Write(Trig , LOW);

}
