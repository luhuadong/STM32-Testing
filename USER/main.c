/**
  ******************************************************************************
  * @file    STM32-Template/USER/main.c 
  * @author  Lu HuaDong
  * @version V3.5.0
  * @date    23-May-2016
  * @brief   Main program body
  ******************************************************************************
  * @attention
  * 
  * The present firmware which is for guidance only aims at providing customers
  * with coding information regarding their products in order for them to save
  * time. As a result, STMicroelectronics shall not be held liable for any
  * direct, indirect or consequential damages with respect to any claims arising
  * from the content of such firmware and/or the use made by customers of the
  * coding information contained herein in connection with their products.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include "led.h"
#include "SysTick.h"
#include "key.h"
#include "exti.h" 


/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	LED_GPIO_Config();
	SysTick_Init();
	//Key_GPIO_Config();
	Exti_Key_Config();
	
	LED1(ON);
	LED3(ON);
  	
	while (1)
  	{
		LED2(ON);
		Delay_us(50000);
		LED2(OFF);
		Delay_us(50000);

		/*
		if(Key_Scan(GPIOE, GPIO_Pin_5) == KEY_ON) {
			GPIO_WriteBit(GPIOC, GPIO_Pin_3, (BitAction)((1 - GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3))));
		}

		if(Key_Scan(GPIOE, GPIO_Pin_6) == KEY_ON) {
			GPIO_WriteBit(GPIOC, GPIO_Pin_5, (BitAction)((1 - GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_5))));
		}
		*/
  	}
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
