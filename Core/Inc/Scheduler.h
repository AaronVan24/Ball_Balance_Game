/*
 * Scheduler.h
 *
 *  Created on: Sep 5, 2023
 *      Author: aaronvan
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Button_Driver.h"
#include <stdint.h>

#define LED_TOGGLE_EVENT (1<<0)
#define DELAY_EVENT (1<<1)
#define BUTTON_POLL (1<<2)

#define EVENTFLAG_TEMP (1<<3)
#define EVENTFLAG_AXIS_DATA (1<<4)
#define EVENTFLAG_REBOOT_CMD (1<<5)
#define START_GAME (1<<6)
#define BEGIN_SCREEN (1<<7)


uint32_t getScheduledEvents();

void addSchedulerEvent(uint32_t addEvents);

void removeSchedulerEvent(uint32_t removeEvents);

#endif /* SCHEDULER_H_ */
