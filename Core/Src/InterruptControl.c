/*
 * InterruptControl.c
 *
 *  Created on: Oct 3, 2023
 *      Author: aaronvan
 */
#include "interruptControl.h"
void IRQ_enable_intrp(uint8_t num){
//	if(num < 32){
//		*NVIC_ISER0 |= (1 << num);
//	}
//
//	if(num >= 32){
//		*NVIC_ISER1 |= (1 << num%32);
//	}
	HAL_NVIC_EnableIRQ(num);
}

void IRQ_disable_intrp(uint8_t num){
//	if(num < 32){
//		*NVIC_ICER0 |= (1 << num);
//	}
//
//	if(num >= 32){
//		*NVIC_ICER1 |= (1 << num%32);
//	}
	HAL_NVIC_DisableIRQ(num);
}

void IRQ_clear_pending_intrp(uint8_t num){
//	if(num < 32){
//		*NVIC_ICPR0 |= (1 << num);
//	}
//
//	if(num >= 32){
//		*NVIC_ICPR1 |= (1 << num%32);
//	}
	HAL_NVIC_ClearPendingIRQ(num);
}

void IRQ_set_pending_intrp(uint8_t num){
//	if(num < 32){
//		*NVIC_ISPR0 |= (1 << num);
//	}
//
//	if(num >= 32){
//		*NVIC_ISPR1 |= (1 << num%32);
//	}
	HAL_NVIC_SetPendingIRQ(num);
}

void EXTI_clear_pending_intrp(uint8_t num){
	EXTI->PR |= (1 << num);
}
