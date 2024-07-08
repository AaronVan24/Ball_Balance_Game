/*
 * LED_Driver.h
 *
 *  Created on: Sep 5, 2023
 *      Author: aaronvan
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "stm32f4xx_hal.h"

#define GREEN_LED 0
#define RED_LED 1

void init_Specific_LED(uint8_t);
void enables_clock_LED(uint8_t);
void enable_LED(uint8_t);
void disable_LED(uint8_t);
void toggle_LED(uint8_t);

#endif /* LED_DRIVER_H_ */
