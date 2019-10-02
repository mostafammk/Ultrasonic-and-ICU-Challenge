

#include "ICU.h"
#include "TIMER.h"


// TIMER0_ov_Count

//float32 G_Pulse_time = 0;
float32 G_Pulse_time = 0;
	static uint8 edge_flag = 0;
void (*G_CallBackFunction)(void) = ( (void*) 0);


void ICU_init()
{

	INTP_vidInit();
	INTP0_vidSetCallBack(ICU_getPulseTime);
	TCCR1B |= (1<<TCCR1B_CS11); //  Start timer1 with 8 prescaler      
}

void ICU_getPulseTime()
{
	
	static uint16 Falling_edge_time = 0;
	edge_flag++;
	if (edge_flag == 1)
	{
		//TCNT1H = 0;
		TCNT1L = 0;
		INTP0_VidSelectEvent(INT0_FallingEdge);
	//	edge_flag = 0;
	}
	else if(edge_flag==2)
	{
		Falling_edge_time = TCNT1L;

		G_Pulse_time = (float32)Falling_edge_time;
		INTP0_VidSelectEvent(INT0_RisingEdge);
		edge_flag = 0;
		G_CallBackFunction();
		
	}
}


void ICU_setCallBack(void(*COPY_CallBackFunction)(void))
{
	G_CallBackFunction = COPY_CallBackFunction;
}