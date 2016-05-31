#include "exti.h"
#include "key.h"


void Exti_Key_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;

	// GPIO pin and mode setting
	Key_GPIO_Config();

	// Enable alternate-function I/O clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	// NVIC configuration
	// 1 bits for pre-emption priority 3 bits for subpriority 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;	// External Line[9:5] Interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	// top level	
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	// top level
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	// Selects the GPIO pin used as EXTI Line.
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource6);

	EXTI_InitStructure.EXTI_Line = EXTI_Line5 | EXTI_Line6;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
}
