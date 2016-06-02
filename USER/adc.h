/* **************************************************
 *
 * PC1/ADC123_IN11 <--> potentiometer
 *
************************************************** */

#ifndef __ADC_H__
#define __ADC_H__

#include "stm32f10x.h"

#define ADC1_DR_Address ((u32)0x40012400+0x4c)
void ADC_Potentiometer_Config(void);

#endif // __ADC_H__
