


#ifndef ICU_H_
#define ICU_H_


#include "ExtInter.h"

extern float32 G_Pulse_time;

void ICU_init(void);
void ICU_setCallBack(void(*COPY_CallBackFunction)(void));
void ICU_getPulseTime(void);



#endif