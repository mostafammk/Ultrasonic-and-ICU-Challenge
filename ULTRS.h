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

#include "ICU.h"
#include "DIO.h"
#include "Service.h"

#define Velocity (0.034)


extern float32 g_Distance;


extern void ULTRS_init(void);
extern void ULTRS_trig(void);
extern void ULTRS_getDistance(void);

#endif /* ULTRS_H_ */
