

#include "ICU.h"
#include "TIMER.h"


// TIMER0_ov_Count

float32 G_Pulse_time = 0;
void (*G_CallBackFunction)(void) = ( (void*) 0);


void ICU_init()
{

	INTP_vidInit();
	TCCR1B |= (1<<TCCR1B_CS12) | (1<<TCCR1B_CS10);  //  Start timer1 with 1024 prescaler      
	INTP0_vidSetCallBack(ICU_getPulseTime);
	
}

void ICU_getPulseTime()
{
	
	static uint16 Rising_edge_time = 0 , Falling_edge_time = 0 , edge_difference = 0;
	static uint8 edge_flag = 1;
	if (edge_flag == 1)
	{
		//TCNT1H = 0;
		TCNT1L = 0;
		INTP0_VidSelectEvent(INT0_FallingEdge);
		edge_flag = 0;
	}
	else
	{
		Falling_edge_time = TCNT1L;

		G_Pulse_time = ( ( (float32)Falling_edge_time * 0.128) /1000.0 );
		INTP0_VidSelectEvent(INT0_RisingEdge);
		edge_flag = 1;
		G_CallBackFunction();
		
	}
}


void ICU_setCallBack(void(*COPY_CallBackFunction)(void))
{
	G_CallBackFunction = COPY_CallBackFunction;
}