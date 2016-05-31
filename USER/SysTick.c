/******************** (C) COPYRIGHT 2012 WildFire Team ***************************
 * �ļ���  ��SysTick.c
 * ����    ��SysTick ϵͳ�δ�ʱ��10us�жϺ�����,�ж�ʱ����������ã�
 *           ���õ��� 1us 10us 1ms �жϡ�         
 * ʵ��ƽ̨��Ұ��STM32������
 * Ӳ�����ӣ�-----------------
 *          |                 |
 *          |      ��         |
 *          |                 |
 *           -----------------
 * ��汾  ��ST3.5.0
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "SysTick.h" 

static __IO u32 TimingDelay;

/*
 * ��������SysTick_Init
 * ����  ������ϵͳ�δ�ʱ�� SysTick
 * ����  ����
 * ���  ����
 * ����  ���ⲿ���� 
 */
void SysTick_Init()
{
	// ST 3.5.0 version Libs, per 10us occur one interruption.
	// The param express count of pulse.
	if(SysTick_Config(SystemCoreClock / 100000))
	{
		// Capture error
		while(1);
	}

	// Disable SysTick, because we do not use it now.
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

/*
 * ��������Delay_us
 * ����  ��us��ʱ����,10usΪһ����λ
 * ����  ��- nTime
 * ���  ����
 * ����  ��Delay_us( 1 ) ��ʵ�ֵ���ʱΪ 1 * 10us = 10us
 *       ���ⲿ���� 
 */
void Delay_us(uint32_t nTime)
{
	TimingDelay = nTime;

	// Enable SysTick timer
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

	// Waiting here
	while(TimingDelay != 0) ;

	// Should I disable SysTick timer here 
	//SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

/*
 * ��������TimingDelay_Decrement
 * ����  ����ȡ���ĳ���
 * ����  ����
 * ���  ����
 * ����  ���� SysTick �жϺ��� SysTick_Handler()����
 */  
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00) { 
		TimingDelay--;
	}
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
