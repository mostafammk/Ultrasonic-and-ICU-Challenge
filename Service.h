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
/*
#include "ULTRS.h"
#include "lcd.h"
*/

uint8 SERVICE_init (void);
uint8 Delay(uint8 TIMER_ID,uint32 Delay);
#endif /* SERVICE_H_ */
