/* **************************************************
 *
 *
************************************************** */

#ifndef __MYRTC_H__
#define __MYRTC_H__

#include "stm32f10x.h"

void RTC_NVIC_Config(void);
void RTC_Configuration(void);

uint32_t Time_Regulate(void);
void Time_Adjust(void);
void Time_Display(uint32_t TimeVar);
void Time_Show(void);


#endif // __MYRTC_H__
