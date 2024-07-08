/*
 * ApplicationCode.h
 *
 *  Created on: Sep 5, 2023
 *      Author: aaronvan
 */



#ifndef APPLICATIONCODE_H_
#define APPLICATIONCODE_H_

#include "Scheduler.h"
#include "LED_Driver.h"
#include "Gyro.h"
#include "LCD_Driver.h"


#define SIZEOFNAME 5
#define DEFAULTSIZE 250000

#define RED_SELECT 0
#define GREEN_SELECT 1

#define USE_INTERRUPT_FOR_BUTTON 1


//void Application_Init();
void Green_Init();
void Red_Init();
void Both_Init();

void GreenLED_toggle();
void RedLED_toggle();

void GreenLED_activate();
void RedLED_activate();

void GreenLED_deactivate();
void RedLED_deactivate();

void delay(uint32_t LED);

void app_init_lvl_button();

void executeButtonPollingRoutine();

void init_button_intrp();

void app_Gyro_init();

void app_Gyro_deviceID();

void app_Gyro_power();

void app_Gyro_reboot();

void app_Gyro_temperature();

void app_Gyro_configure_regs();

float app_Gyro_getx();

void ApplicationInit(void);

void RunDemoForLCD(void);

void displayBall();




#endif /* APPLICATIONCODE_H_ */

