/* **************************************************
 *
 * KEY1 <--> PE5
 * KEY2 <--> PE6
 *
************************************************** */

#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f10x.h"

#define KEY_ON	0
#define KEY_OFF	1

void Key_GPIO_Config(void);

uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif /* __KEY_H__ */
