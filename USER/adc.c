/* **************************************************
 *
 * PC1/ADC123_IN11 <--> potentiometer
 *
************************************************** */
#include "adc.h"

__IO uint16_t ADC_ConvertedValue;

void ADC_Potentiometer_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	DMA_InitTypeDef  DMA_InitStruct;
	ADC_InitTypeDef  ADC_InitStruct;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_ADC1, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

	/* ADC GPIO config */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	/* DMA mode config */
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStruct.DMA_BufferSize = 1;	// 单位是 HalfWord
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;	// 指定外设是数据源
	DMA_InitStruct.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStruct.DMA_MemoryBaseAddr = (u32)&ADC_ConvertedValue;	// 内存地址
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Disable;
	DMA_InitStruct.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStruct.DMA_PeripheralBaseAddr = ADC1_DR_Address;	// 外设地址 ADC1_DR
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_Priority = DMA_Priority_High;
	DMA_Init(DMA1_Channel1, &DMA_InitStruct);
	// 启动 DMA1_Channel1 
	DMA_Cmd(DMA1_Channel1, ENABLE);

	/* ADC mode config */
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_Init(ADC1, &ADC_InitStruct);

	// ADC 时钟为 PCLK2 的8分频，即9Hz
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	// 设置 ADC1 使用第 11 转换通道，第 1 转换次序，采样时间为 55.5 个周期
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_55Cycles5);
	// 允许 ADC1 发起 DMA 请求
	ADC_DMACmd(ADC1, ENABLE);
	// 启动 ADC1
	ADC_Cmd(ADC1, ENABLE);

	/* ADC calibration */
	ADC_ResetCalibration(ADC1);
	while(RESET != ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(RESET != ADC_GetCalibrationStatus(ADC1));

	/* selected ADC software start conversion  */
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);

	

}
