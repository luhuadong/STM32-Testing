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

void delay(unsigned int time)
{
	int i, count;
	for(i=0; i<time; i++)
	{
		count=0x40;
		while(count--) ;
	}
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	int const count = 1000;
	int i, j;

	LED_GPIO_Config();
	
	LED1(ON);
	LED3(ON);
  	
	while (1)
  	{
		for(i=0; i<=count; i++)
		{
			j = count-i;
			LED2(ON);
			delay(i);
			LED2(OFF);
			delay(j);
		}

		for(i=count; i>=0; i--)
		{
			j = count-i;
			LED2(ON);
			delay(i);
			LED2(OFF);
			delay(j);
		}

		delay(20000);

  	}
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
