/*
 * Button_Driver.c
 *
 *  Created on: Sep 26, 2023
 *      Author: aaronvan
 */

#include "Button_Driver.h"

void init_button(){
	GPIO_InitTypeDef* config_button = {0};
	config_button->Pin = GPIO_PIN_0;
	config_button->Mode = GPIO_MODE_INPUT;
	enable_clock();
	HAL_GPIO_Init(GPIOA,config_button);
}

void enable_clock(){
//	GPIO_enable_disable(PORT_A,ENABLE);
	__HAL_RCC_GPIOA_CLK_ENABLE();
}

bool button_pressed(){
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == BUTTON_PRESSED){
		return true;
	}

	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == BUTTON_NOT_PRESSED){
		return false;
	}
	return 0;
}

void init_intrp_mode(){
	GPIO_InitTypeDef interrupt = {0};
//	interrupt.pGPIOx = PORT_A;
	interrupt.Pin = PIN_NUMBER;
	interrupt.Mode = GPIO_MODE_IT_RISING;
	interrupt.Pull = GPIO_NOPULL;
	enable_clock();
	HAL_GPIO_Init(GPIOA,&interrupt);
	HAL_NVIC_EnableIRQ(EXTI0_IRQ_NUMBER);
}

