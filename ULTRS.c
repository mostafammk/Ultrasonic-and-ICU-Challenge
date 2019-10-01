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

#include "ULTRS.h"

uint16 g_Distance =0;

void ULTRS_init(void){
	ICU_setCallBack(ULTRS_getDistance);
}

void ULTRS_getDistance(void){
	uint16 local_Distance =0;
	local_Distance = (uint16)Velocity * (uint8)g_PulsTime;
	g_Distance = local_Distance;
}

void ULTRS_trig(void){
	DIO_Write(PORT_B,PIN4,HIGH);
	Delay(TIMER0,1000);
	DIO_Write(PORT_B,PIN4,HIGH);
}
