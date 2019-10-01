/******************************************************************************
 *
 * Module: UltraSonic header file
 *
 * File Name: ULTRS.h
 *
 * Description: header file containing functions prototypes
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef ULTRS_H_
#define ULTRS_H_

#include <avr/io.h>
#include "std_types.h"
#include <util/delay.h>

#define Velocity (34000)

extern float32 g_PulsTime;

extern void ULTRS_init(void);
extern void ULTRS_trig(void);
extern void ULTRS_getDistance(void);

#endif /* ULTRS_H_ */
