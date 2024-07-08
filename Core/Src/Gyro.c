/*
 * Gyro.c
 *
 *  Created on: Nov 9, 2023
 *      Author: aaronvan
 */

#include "Gyro.h"
#include <stdio.h>

static GPIO_InitTypeDef gyro;
static SPI_HandleTypeDef SPI;
static HAL_StatusTypeDef halstatus;

float xAngle = 160;
float xGPosition = 0;

void Gyro_init(){
	__HAL_RCC_GPIOF_CLK_ENABLE();
	gyro.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
	gyro.Mode = GPIO_MODE_AF_PP;
	gyro.Alternate = GPIO_AF5_SPI5;
	gyro.Pull = GPIO_NOPULL;
	gyro.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOF, &gyro);

	__HAL_RCC_GPIOC_CLK_ENABLE();
	gyro.Pin = GPIO_PIN_1;
	gyro.Mode = GPIO_MODE_OUTPUT_OD;
	gyro.Alternate = GPIO_AF5_SPI5;
	gyro.Pull = GPIO_PULLUP;
	gyro.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOC, &gyro);
	Gyro_disable_slave_communication();


	SPI.Instance = SPI5;
	SPI.Init.Mode = SPI_MODE_MASTER;
	SPI.Init.Direction = SPI_DIRECTION_2LINES;
	SPI.Init.DataSize = SPI_DATASIZE_8BIT;
	SPI.Init.CLKPolarity = SPI_POLARITY_HIGH;
	SPI.Init.CLKPhase = SPI_PHASE_2EDGE;
	SPI.Init.NSS = SPI_NSS_SOFT;
	SPI.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
	SPI.Init.FirstBit = SPI_FIRSTBIT_MSB;
	SPI.Init.TIMode = SPI_TIMODE_DISABLE;
	SPI.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	SPI.Init.CRCPolynomial = 0;
	HAL_SPI_Init(&SPI);


}

void Gyro_deviceID(){
	uint8_t retData;
	uint16_t rec = 0x00;
	uint16_t send = (READ | WHO_AM_I);
	Gyro_enable_slave_communication();
	while(HAL_GPIO_ReadPin(NCS_MEMS_SPI_PORT,NCS_MEMS_SPI_PIN) != GPIO_PIN_RESET);
	halstatus = HAL_SPI_TransmitReceive(&SPI, (uint8_t*)&send, (uint8_t*)&rec, 2, DELAY);
	Gyro_disable_slave_communication();
	if(halstatus != HAL_OK){
		for(;;);
	}
	retData = ((0xFF00 & rec) >> 8);
	printf("Device ID is: %d \n", retData);
}

void Gyro_power(){
	uint16_t send = (READ | CTRL_REG1);
	uint16_t retData = 0;
	Gyro_enable_slave_communication();
	HAL_SPI_TransmitReceive(&SPI, (uint8_t*)&send, (uint8_t*)&retData, 2, DELAY);
	Gyro_disable_slave_communication();

	retData = retData >> 8;
	retData |= POWER;
	retData = 1 << 3;
	send = ((WRITE | CTRL_REG1) | retData << 8);
	Gyro_enable_slave_communication();
	HAL_SPI_Transmit(&SPI, (uint8_t*)&send, 2, DELAY);
	Gyro_disable_slave_communication();
}

void Gyro_reboot(){ // reboots gyro.
	uint16_t send = (READ | CTRL_REG5);
	uint16_t retData = 0;
	Gyro_enable_slave_communication();
	halstatus = HAL_SPI_TransmitReceive(&SPI, (uint8_t*)&send, (uint8_t*)&retData, 2, DELAY);
	Gyro_disable_slave_communication();
	Gyro_verify_HAL_status();

	retData = retData >> 8;
	retData |= REBOOT;

	send = ((WRITE | CTRL_REG5) | retData << 8);
	Gyro_enable_slave_communication();
	halstatus = HAL_SPI_Transmit(&SPI, (uint8_t*)&send, 2, DELAY);
	Gyro_disable_slave_communication();

	Gyro_verify_HAL_status();
}

void Gyro_configure_regs(){
	uint16_t regis = 0xF;
	uint16_t send = (WRITE | CTRL_REG1) | (regis << 8);
	Gyro_enable_slave_communication();
	HAL_SPI_Transmit(&SPI, (uint8_t*)&send, 2, DELAY);
	Gyro_disable_slave_communication();

	regis = 0x10;
	send = (WRITE | CTRL_REG4) | (regis << 8);
	Gyro_enable_slave_communication();
	HAL_SPI_Transmit(&SPI, (uint8_t*)&send, 2, DELAY);
	Gyro_disable_slave_communication();


	regis = 0xC0;
	send = (WRITE | CTRL_REG5) | (regis << 8);
	Gyro_enable_slave_communication();
	HAL_SPI_Transmit(&SPI, (uint8_t*)&send, 2, DELAY);
	Gyro_disable_slave_communication();


	regis = 0x40;
	send = (WRITE | FIFO_CTRL_REG) | (regis << 8);
	Gyro_enable_slave_communication();
	HAL_SPI_Transmit(&SPI, (uint8_t*)&send, 2, DELAY);
	Gyro_disable_slave_communication();

}

void Gyro_verify_HAL_status(){
	if(halstatus != HAL_OK){
		APPLICATION_ASSERT(false);
	}
}

void Gyro_enable_slave_communication(){
	HAL_GPIO_WritePin(NCS_MEMS_SPI_PORT, MEMS_INT1_PIN, GPIO_PIN_RESET);
}

void Gyro_disable_slave_communication(){
	HAL_GPIO_WritePin(NCS_MEMS_SPI_PORT, MEMS_INT1_PIN, GPIO_PIN_SET);
}
float Gyro_getx(){
	uint16_t lowx = getxlow();
	uint16_t highx = getxhigh();
	highx = highx << 8;

	int16_t value = highx | lowx;
	float xVelocity = (float)value * VAL;

	if((xGPosition > 281) || (xGPosition < 30)){
		xGPosition = 160;
	}
	float xGPosition = xGPosition + xVelocity;

	return xGPosition;
}

uint16_t getxhigh(){
	uint16_t rec = 0x0;
	uint16_t send = (READ | OUT_X_H);
	Gyro_enable_slave_communication();
	while(HAL_GPIO_ReadPin(NCS_MEMS_SPI_PORT,NCS_MEMS_SPI_PIN) != GPIO_PIN_RESET);
	halstatus = HAL_SPI_TransmitReceive(&SPI, (uint8_t*)&send, (uint8_t*)&rec, 2, DELAY);
	Gyro_disable_slave_communication();

	Gyro_verify_HAL_status();
	rec = ((0xFF00 & rec) >> 8);
	return rec;
}

uint16_t getxlow(){
	uint16_t rec = 0x0;
	uint16_t send = (READ | OUT_X_L);
	Gyro_enable_slave_communication();
	while(HAL_GPIO_ReadPin(NCS_MEMS_SPI_PORT,NCS_MEMS_SPI_PIN) != GPIO_PIN_RESET);
	halstatus = HAL_SPI_TransmitReceive(&SPI, (uint8_t*)&send, (uint8_t*)&rec, 2, DELAY);
	Gyro_disable_slave_communication();

	Gyro_verify_HAL_status();
	rec = ((0xFF00 & rec) >> 8);
	return rec;
}

float getXAngle(){
	return xAngle;
}

