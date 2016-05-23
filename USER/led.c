#include "led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	// Enable GPIOC periph clock before call GPIO_Init().
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	// Initialize GPIOC(3, 4, 5).
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	// Initial assignment, so periphs have certain value.
	GPIO_SetBits(GPIOC, GPIO_InitStruct.GPIO_Pin); 
}
