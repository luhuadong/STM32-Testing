/* **************************************************
 *
 * LED1 <--> PC3
 * LED2 <--> PC4
 * LED3 <--> PC5
 *
************************************************** */

#ifndef __LED_H__
#define __LED_H__

#include "stm32f10x.h"

#define ON	0
#define OFF	1

#define LED1(x) if(x == OFF) \
				GPIO_SetBits(GPIOC, GPIO_Pin_3); \
				else if(x == ON) \
				GPIO_ResetBits(GPIOC, GPIO_Pin_3)

#define LED2(x) if(x == OFF) \
				GPIO_SetBits(GPIOC, GPIO_Pin_4); \
				else if(x == ON) \
				GPIO_ResetBits(GPIOC, GPIO_Pin_4)

#define LED3(x) if(x == OFF) \
				GPIO_SetBits(GPIOC, GPIO_Pin_5); \
				else if(x == ON) \
				GPIO_ResetBits(GPIOC, GPIO_Pin_5)
				
void LED_GPIO_Config(void);
				

#endif /* __LED_H__ */
