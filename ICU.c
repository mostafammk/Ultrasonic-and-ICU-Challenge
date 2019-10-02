

#include "ICU.h"


// TIMER0_ov_Count

float32 G_Pulse_time = 0;
static uint8 edge_flag = 0;
uint8 G_OV_Counts = 0;

void (*G_CallBackFunction)(void) = ( (void*) 0);


void ICU_init()
{

	INTP_vidInit();
	INTP0_vidSetCallBack(ICU_getPulseTime);
	TIMER2_OVF_setCallBack(ICU_Count_OV);
	TIMSK |= (1<<TIMSK_TOIE2);
	TCCR2 |= (1<<TCCR2_CS21); //  Start timer2 with 8 prescaler
}

void ICU_getPulseTime()
{
	
	static uint8 Falling_edge_time = 0;
	edge_flag++;
	if (edge_flag == 1)
	{
		G_OV_Counts = 0;
		TCNT2 = 0;
	
		INTP0_VidSelectEvent(INT0_FallingEdge);

		//	edge_flag = 0;
	}
	else if(edge_flag==2)
	{
		Falling_edge_time = TCNT2;

		G_Pulse_time = ( (float32)Falling_edge_time )  +  ( (float32)( 255u * G_OV_Counts ) )  ;
	
		INTP0_VidSelectEvent(INT0_RisingEdge);
	
		edge_flag = 0;
		G_CallBackFunction();
		
	}
}


void ICU_setCallBack(void(*COPY_CallBackFunction)(void))
{
	G_CallBackFunction = COPY_CallBackFunction;
}

void ICU_Count_OV()
{
	G_OV_Counts++;
}