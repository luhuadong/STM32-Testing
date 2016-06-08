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
#include "usart1.h"
#include "adc.h"
#include "rtc.h"

//#define RTCClockOutput_Enable


extern __IO uint16_t ADC_ConvertedValue;

static float ADC_ConvertedValueLocal;

void MPU_ID_Show(void)
{
	__IO u32 *id_address = (__IO u32 *)0x1FFFF7E8;
	printf("\r\nSTM32F103VE ID: %08x-%08x-%08x\r\n", *(id_address+2), *(id_address+1), *(id_address+0));
}

void InnerFlash_Size_Show(void)
{
	printf("\r\nSize of iFlash: %dK Bytes\r\n", *(__IO u16 *)(0x1FFFF7E0));
}

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
	USART1_Config();
	ADC_Potentiometer_Config();

	/* RTC  */
	RTC_NVIC_Config();

	if (BKP_ReadBackupRegister(BKP_DR1) != 0xA5A5)
	{
		printf("\r\n BKP_DR1 = %x\r\n", BKP_ReadBackupRegister(BKP_DR1));
		/* Backup data register value is not correct or not yet programmed (when
		the first time the program is executed) */
		printf("\r\nThis is a RTC demo!\r\n");
		printf("\r\n\n RTC not yet configured....");
		
		/* RTC Configuration */
		RTC_Configuration();
		
		printf("\r\n RTC configured....");
		
		/* Adjust time by values entred by the user on the hyperterminal */
		Time_Adjust();
		
		BKP_WriteBackupRegister(BKP_DR1, 0xA5A5);
	}
	else
	{
		printf("\r\n BKP_DR1 = %x\r\n", BKP_ReadBackupRegister(BKP_DR1));
		/* Check if the Power On Reset flag is set */
		if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
		{
			printf("\r\n\n Power On Reset occurred....");
		}
		/* Check if the Pin Reset flag is set */
		else if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET)
		{
			printf("\r\n\n External Reset occurred....");
		}
		
		printf("\r\n No need to configure RTC....");
		/* Wait for RTC registers synchronization */
		RTC_WaitForSynchro();
		
		/* Enable the RTC Second */
		RTC_ITConfig(RTC_IT_SEC, ENABLE);
		
		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();
	}
	
#ifdef RTCClockOutput_Enable
	/* Enable PWR and BKP clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
	
	/* Allow access to BKP Domain */
	PWR_BackupAccessCmd(ENABLE);
	
	/* Disable the Tamper Pin */
	BKP_TamperPinCmd(DISABLE); /* To output RTCCLK/64 on Tamper pin, the tamper
	             functionality must be disabled */
	
	/* Enable RTC Clock Output on Tamper Pin */
	BKP_RTCOutputConfig(BKP_RTCOutputSource_CalibClock);
#endif
	
	/* Clear reset flags */
	RCC_ClearFlag();
	
	/* Display time in infinite loop */
	Time_Show();

	/* RTC */

	printf("\r\n Project: STM32-Testing. \r\n");
	printf("\r\n 欢迎进入 STM32 实验系统 \r\n");
	USART1_Printf(USART1, "\r\n Testing from USART1_Printf \r\n");
	MPU_ID_Show();
	InnerFlash_Size_Show();
	
	LED1(ON);
	LED3(ON);
  	
	while (1)
  	{
		ADC_ConvertedValueLocal = (float)ADC_ConvertedValue / 4096 * 3.3;
		printf("ADC_Potentiometer_Value = %.2f (%u%%)\r\n", ADC_ConvertedValueLocal, (u32)(ADC_ConvertedValueLocal/3.3*100));
		LED2(ON);
		Delay_us(100000);
		LED2(OFF);
		Delay_us(100000);


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
