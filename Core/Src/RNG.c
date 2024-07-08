/*
 * RNG.c
 *
 *  Created on: Dec 11, 2023
 *      Author: aaronvan
 */

#include "RNG.h"
static RNG_HandleTypeDef config_RNG;
HAL_StatusTypeDef status;
uint32_t RNG_1;
uint32_t RNG_2;

void RNG_init(){
	config_RNG.ErrorCode = 0;
	config_RNG.Instance = RNG; // check RNG
	config_RNG.Lock = HAL_UNLOCKED;
	config_RNG.RandomNumber = 0;
	config_RNG.State = HAL_RNG_STATE_RESET;

	__HAL_RCC_RNG_CLK_ENABLE();
	status =HAL_RNG_Init(&config_RNG);

	if(status != HAL_OK){
		for(;;);
	}
}

uint32_t getRNG(){
	status = HAL_RNG_GenerateRandomNumber(&config_RNG,&RNG_1);
	if(status != HAL_OK){
		for(;;);
	}
	RNG_2 = RNG_1 % 160;
	if(RNG_2 < 0){
		RNG_2 = RNG_2 *(-1);
	}
	return RNG_2;
}
