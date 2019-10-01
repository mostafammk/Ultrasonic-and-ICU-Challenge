 /******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.h
 *
 * Description: Header file for the AVR ICU driver
 *
 * Author: Mahmoud Rezk Mahmoud
 *
 *******************************************************************************/

#ifndef ICU_HARDWARE_H_
#define ICU_HARDWARE_H_

#include "STD_TYPES.h"
#include "REG_Lib.h"
#include "TIMER.h"



#define FALLING 0
#define RISING 1



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void Icu_init( uint8  Prescaller, uint8 EDGE_type);

/*
 * Description: Function to set the Call Back function address.
 */
void Icu_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void Icu_setEdgeDetectionType(uint8 EDGE_type);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 Icu_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void Icu_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void Icu_DeInit(void);
/*********************************************************
 *					Timer1 ICU Interrupt				 *
 *********************************************************/
void __vector_6 (void) __attribute__ ((signal,used));

#endif /* ICU_HARDWARE_H_ */
