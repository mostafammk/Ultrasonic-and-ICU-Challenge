


#ifndef ICU_H_
#define ICU_H_


#include "ExtInter.h"
#include "TIMER.h"

extern float32 G_Pulse_time;

void ICU_init(void);
void ICU_setCallBack(void(*COPY_CallBackFunction)(void));
void ICU_getPulseTime(void);
void ICU_Count_OV();

extern volatile uint8 G_OV_Counts;



#endif