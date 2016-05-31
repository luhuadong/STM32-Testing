/* **************************************************
 *
 * ���ڱ�ʵ���У�SysTick ���ж������ļ� core_cm3.h 
 * �ĺ������õģ�û��ʹ�� NVIC �������жϣ�����
 * �ɲ���� misc.c �ļ���
 *
 * �� core_cm3.h �ڰ��� stm32f10x.h ͷ�ļ�ʱ�Ѿ�
 * ����ӽ������ˡ�
 *
************************************************** */

#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "stm32f10x.h"

void SysTick_Init(void);

//void Delay_us(__IO u32 nTime);
void Delay_us(uint32_t);

#endif // __SYSTICK_H__
