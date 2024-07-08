/*
 * ApplicationCode.c
 *
 *  Created on: Sep 5, 2023
 *      Author: aaronvan
 */

#include <ApplicationCode.h>
#include <stdio.h>


static uint8_t colorLED;

void Green_Init(){
	init_Specific_LED(GREEN_LED);
}
void Red_Init(){
	init_Specific_LED(RED_LED);
}
void Both_Init(){
	init_Specific_LED(GREEN_LED);
	init_Specific_LED(RED_LED);
}

void GreenLED_toggle(){
	toggle_LED(GREEN_LED);
}
void RedLED_toggle(){
	toggle_LED(RED_LED);
}

void GreenLED_activate(){
	enable_LED(GREEN_LED);
}
void RedLED_activate(){
	enable_LED(RED_LED);
}

void GreenLED_deactivate(){
	disable_LED(GREEN_LED);
}
void RedLED_deactivate(){
	disable_LED(RED_LED);
}

void delay(uint32_t LED){
	char arrName[SIZEOFNAME] = {'A','A','R','O','N'};
	[[maybe_unused]]char arrDest[SIZEOFNAME];

	for(uint32_t i = 0; i < LED ;i++){
		for(uint32_t j = 0; j < SIZEOFNAME ;j++){
			arrDest[j] = arrName[j];
		}
	}
	return;
}

void ApplicationInit(){
	//Red_Init();
	//addSchedulerEvent(LED_TOGGLE_EVENT);
	//addSchedulerEvent(DELAY_EVENT);

//	Green_Init();
//	Red_Init();
//	colorLED = GREEN_SELECT;
//	GreenLED_deactivate();
	//app_init_lvl_button();
//	addSchedulerEvent(LED_TOGGLE_EVENT);
//	addSchedulerEvent(DELAY_EVENT);
	app_Gyro_init();
	init_intrp_mode();
//	addSchedulerEvent(EVENTFLAG_TEMP);
//	addSchedulerEvent(EVENTFLAG_AXIS_DATA);
//	#if USE_INTERRUPT_FOR_BUTTON == 0
//		init_button_intrp();
//	#elif USE_INTERRUPT_FOR_BUTTON == 0
//		app_init_lvl_button();
//		addSchedulerEvent(BUTTON_POLL);
//	#else
//		init_button_intrp();
//	#endif

	LTCD__Init();
    LTCD_Layer_Init(0);
    LCD_Clear(0,LCD_COLOR_WHITE);
}
void app_init_lvl_button(){
	init_button();
}
void executeButtonPollingRoutine(){
	if(button_pressed() == true){
		if(colorLED == GREEN_SELECT){
			GreenLED_activate();
		}
		if(colorLED == RED_SELECT){
			RedLED_deactivate();
		}
	}

	if(button_pressed() == false){
		if(colorLED == GREEN_SELECT){
			GreenLED_deactivate();
		}
		if(colorLED == RED_SELECT){
			RedLED_deactivate();
		}

	}
}
#if USE_INTERRUPT_FOR_BUTTON == 1
void init_button_intrp(){
	init_intrp_mode();
}

void EXTI0_IRQHandler(){
	IRQ_disable_intrp(EXTI0_IRQn);
	LCD_Clear(0,LCD_COLOR_GREEN);
	LCD_SetTextColor(LCD_COLOR_BLACK);

	LCD_DisplayChar(60,140,'G');
	LCD_DisplayChar(75,140,'A');
	LCD_DisplayChar(90,140,'M');
	LCD_DisplayChar(105,140,'E');
	LCD_DisplayChar(115,140,' ');
	LCD_DisplayChar(125,140,'R');
	LCD_DisplayChar(140,140,'E');
	LCD_DisplayChar(155,140,'S');
	LCD_DisplayChar(170,140,'E');
	LCD_DisplayChar(185,140,'T');

//	startScreen();

	addSchedulerEvent(EVENTFLAG_REBOOT_CMD);

//	if(colorLED == GREEN_SELECT){
//		GreenLED_toggle();
//		EXTI_clear_pending_intrp(PIN_NUMBER);
//
//	}
	//IRQ_clear_pending_intrp(EXTI0_IRQn);
	//printf("REBOOT activated \n");
	IRQ_clear_pending_intrp(EXTI0_IRQn);
	EXTI_clear_pending_intrp(PIN_NUMBER);
	IRQ_enable_intrp(EXTI0_IRQn);

//
//	startScreen();
}

void app_Gyro_init(){
	Gyro_init();
}

void app_Gyro_deviceID(){
	Gyro_deviceID();
}

void app_Gyro_power(){
	Gyro_power();
}

void app_Gyro_reboot(){
	Gyro_reboot();
}

void app_Gyro_temperature(){
	Gyro_temperature();
}

void app_Gyro_configure_regs(){
	Gyro_configure_regs();
}

float app_Gyro_getx(){
	return Gyro_getx();
}

void RunDemoForLCD(void)
{
	QuickDemo();
}

#endif

