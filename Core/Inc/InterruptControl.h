/*
 * InterruptControl.h
 *
 *  Created on: Oct 3, 2023
 *      Author: aaronvan
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#include "stm32f4xx_hal.h"

#define EXTI0_IRQ_NUMBER 6

void IRQ_enable_intrp(uint8_t num);

void IRQ_disable_intrp(uint8_t num);

void IRQ_clear_pending_intrp(uint8_t num);

void IRQ_set_pending_intrp(uint8_t num);

void EXTI_clear_pending_intrp(uint8_t num);

#endif /* INTERRUPTCONTROL_H_ */
