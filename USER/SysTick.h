/* **************************************************
 *
 * 由于本实验中，SysTick 的中断是在文件 core_cm3.h 
 * 的函数配置的，没有使用 NVIC 来配置中断，所以
 * 可不添加 misc.c 文件。
 *
 * 而 core_cm3.h 在包含 stm32f10x.h 头文件时已经
 * 被添加进工程了。
 *
************************************************** */

#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "stm32f10x.h"

void SysTick_Init(void);

//void Delay_us(__IO u32 nTime);
void Delay_us(uint32_t);

#endif // __SYSTICK_H__
