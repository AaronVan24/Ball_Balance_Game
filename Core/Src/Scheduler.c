/*
 * Scheduler.c
 *
 *  Created on: Sep 5, 2023
 *      Author: aaronvan
 */


#include <Scheduler.h>

static uint32_t scheduledEvents;

void addSchedulerEvent(uint32_t addEvents){
	scheduledEvents |= addEvents;
}

void removeSchedulerEvent(uint32_t removeEvents){
	scheduledEvents &= ~(removeEvents);
}

uint32_t getScheduledEvents(){
	return scheduledEvents;
}





