 /******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.c
 *
 * Description: Source file for the AVR ICU driver
 *
 * Author: Mahmoud Rezk Mahmoud
 *
 *******************************************************************************/

#include "ICU_hardware.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

void __vector_6 (void)
{
	if(g_callBackPtr != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void Icu_init( uint8  Prescaller, uint8 EDGE_type )
{
	/* Timer1 always operates in Normal Mode */
	TCCR1A = (1<<TCCR1A_FOC1A) | (1<<TCCR1A_FOC1B);

	/*
	 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
	 * of TCCR1B Register
	 */
	switch(Prescaller)
	{
	case F_CPU:
		TCCR1B |=  F_CPU;
		break;
	case F_CPU_1:
		TCCR1B |=  F_CPU_1;
		break;
	case F_CPU_8:
		TCCR1B |=  F_CPU_8;
		break;
	case F_CPU_64:
		TCCR1B |=  F_CPU_64;
		break;
	case F_CPU_256:
		TCCR1B |=  F_CPU_256;
		break;
	case F_CPU_1024:
		TCCR1B |=  F_CPU_1024;
		break;
	default:
		break;
	}

	/*
     * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B |= (EDGE_type<<6);

	/* Initial Value for Timer1 */
	TCNT1L = 0;

	/* Initial Value for the input capture register */
	ICR1L = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	TIMSK |= (1<<TIMSK_TICIE1);
}

/*
 * Description: Function to set the Call Back function address.
 */
void Icu_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}

/*
 * Description: Function to set the required edge detection.
 */
void Icu_setEdgeDetectionType(uint8 EDGE_type)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B |= (EDGE_type<<6);
}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 Icu_getInputCaptureValue(void)
{
	return ICR1L;
}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void Icu_clearTimerValue(void)
{
	TCNT1L = 0;
}

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void Icu_DeInit(void)
{
	/* Clear All Timer1 Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1L = 0;
	ICR1L = 0;

	/* Disable the Input Capture interrupt */
	TIMSK &= ~(1<<TIMSK_TICIE1);
}
