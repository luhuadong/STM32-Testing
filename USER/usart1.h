/* **************************************************
 *
 * USART1_CK <--> PA8
 * USART1_TX <--> PA9
 * USART1_RX <--> PA10
 *
************************************************** */

#ifndef __USART1_H__
#define __USART1_H__

#include "stm32f10x.h"

void USART1_Config(void);

void USART1_Printf(USART_TypeDef* USARTx, uint8_t *Data, ...);

// void USART1_NVIC_Config(void);

#endif	// __USART1_H__
