/*
 * Service.h
 *
 *  Created on: Sep 25, 2019
 *      Author: alx
 */

#ifndef SERVICE_H_
#define SERVICE_H_
#include "DIO.h"
#include "TIMER.h"
#include "ULTRS.h"
#include "lcd.h"
#include "ICU.h"
#include "ExtInter.h"
#include "Motor.h"

#define F_CPU 8000000ul

uint8 SERVICE_init (void);
uint8 Delay(uint8 TIMER_ID,uint64 Delay);
#endif /* SERVICE_H_ */
