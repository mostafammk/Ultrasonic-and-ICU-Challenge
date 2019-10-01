/********************************************************************
 * Project Name:		MovingCar									*
 *																	*
 * Project Description:						                        *
 *																	*
 * Project Author:       Mahmoud Rezk Mahmoud						*
 ********************************************************************/
#include "Service.h"
extern uint16 g_Distance;
int main (void)
{
	static uint16 L_Distance=g_Distance;
	static uint16 L_count=0;
	SERVICE_init();
	while(1)
	{
		if(L_Distance!=g_Distance)
		{
			L_Distance=g_Distance;
			ULTRS_trig();
			DIO_write(PORT_B,PIN4,HIGH);
			L_count++;
		}
		else
		{
			DIO_write(PORT_B,PIN4,LOW);
		}
		LCD_displayString("Distance = ");
		LCD_intgerToString(L_Distance);

	}





	return 0;
}
