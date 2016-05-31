#include "key.h"

void delay(unsigned int time)
{
	while(time--) ;
}

void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	// Enable GPIOE periph clock before call GPIO_Init().
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

	// Initialize GPIOE(5, 6).
	GPIO_Init(GPIOE, &GPIO_InitStruct);
}

uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
		// debounce
		delay(1000);
		if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
			// Waiting for release
			while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) ;
			return KEY_ON;
		}
	}
	return KEY_OFF;
}
