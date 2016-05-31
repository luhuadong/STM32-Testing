#include "exti.h"


void Exti_Key_Config(void)
{
	NVIC_InitTypeDef NVIC_KeyInit;
	EXTI_InitTypeDef EXTI_InitStructure;

	NVIC_KeyInit.NVIC_IRQChannel = ;
	NVIC_KeyInit.NVIC_IRQChannelPreemptionPriority = ;
	NVIC_KeyInit.NVIC_IRQChannelSubPriority = ;
	NVIC_KeyInit.NVIC_IRQChannelCmd = ;


	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	EXTI_InitStructure.EXTI_Line = EXTI_Line5;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;

	EXTI_Init(&EXTI_InitStructure);
}
