/*
 * RNG.h
 *
 *  Created on: Dec 11, 2023
 *      Author: aaronvan
 */

#ifndef INC_RNG_H_
#define INC_RNG_H_

#include "stm32f4xx_hal.h"

void RNG_init();
uint32_t getRNG();

#endif /* INC_RNG_H_ */
