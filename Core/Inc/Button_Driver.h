/*
 * Button_Driver.h
 *
 *  Created on: Sep 26, 2023
 *      Author: aaronvan
 */


#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include "stm32f4xx_hal.h"
#include "InterruptControl.h"
#include <stdbool.h>

#define PORT_A GPIOA
#define PIN_NUMBER GPIO_PIN_0
#define BUTTON_PRESSED 1
#define BUTTON_NOT_PRESSED 0

void init_button();

void enable_clock();

bool button_pressed();

void init_intrp_mode();





#endif /* BUTTON_DRIVER_H_ */
