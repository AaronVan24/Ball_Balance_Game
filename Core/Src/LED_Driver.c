/*
 * LED_Driver.c
 *
 *  Created on: Sep 5, 2023
 *      Author: aaronvan
 */

#include <LED_Driver.h>

static GPIO_InitTypeDef* redLED;
static GPIO_InitTypeDef* greenLED;

void init_Specific_LED(uint8_t s_led){
	switch(s_led){
		case GREEN_LED:{
			greenLED->Pin = GPIO_PIN_13;
			greenLED->Mode = GPIO_MODE_OUTPUT_PP;
			greenLED->Speed = GPIO_SPEED_FREQ_MEDIUM;
			greenLED->Pull = GPIO_NOPULL;
			__HAL_RCC_GPIOG_CLK_ENABLE();
			HAL_GPIO_Init(GPIOG,greenLED);

			break;
		}
		case RED_LED:{
			redLED->Pin = GPIO_PIN_14;
			redLED->Mode = GPIO_MODE_OUTPUT_PP;
			redLED->Speed = GPIO_SPEED_FREQ_MEDIUM;
			redLED->Pull = GPIO_NOPULL;
			__HAL_RCC_GPIOG_CLK_ENABLE();
			HAL_GPIO_Init(GPIOG,redLED);

			break;
		}
		default:{
			for(;;);
			break;
		}
	}
}

void toggle_LED(uint8_t led){
	switch(led){
		case GREEN_LED:{
			HAL_GPIO_TogglePin(GPIOG, greenLED->Pin);
			break;
		}
		case RED_LED:{
			HAL_GPIO_TogglePin(GPIOG, redLED->Pin);
			break;
		}
		default:{
			for(;;);
			break;
		}
	}
}

void disable_LED(uint8_t led){
	switch(led){
		case GREEN_LED:{
			HAL_GPIO_WritePin(GPIOG, greenLED->Pin, GPIO_PIN_RESET);
			break;
		}
		case RED_LED:{
			HAL_GPIO_WritePin(GPIOG, redLED->Pin, GPIO_PIN_RESET);
			break;
		}
		default:{
			for(;;);
			break;
		}
	}
}

void enable_LED(uint8_t led){
	switch(led){
		case GREEN_LED:{
			HAL_GPIO_WritePin(GPIOG, greenLED->Pin,GPIO_PIN_SET);
			break;
		}
		case RED_LED:{
			HAL_GPIO_WritePin(GPIOG , redLED->Pin,GPIO_PIN_SET);
			break;
		}
		default:{
			for(;;);
			break;
		}
	}
}
