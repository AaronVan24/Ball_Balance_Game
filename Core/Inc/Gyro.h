/*
 * Gyro.h
 *
 *  Created on: Nov 9, 2023
 *      Author: aaronvan
 */



#ifndef INC_GYRO_H_
#define INC_GYRO_H_

#include "stm32f4xx_hal.h"
#include "ErrorHandling.h"
#include <stdbool.h>

#define WHO_AM_I 0x0F
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
#define REFERENCE_DATACAPTURE 0x25
#define OUT_TEMP 0x26
#define STATUS_REG 0x27
#define OUT_X_L 0x28
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x2B
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D
#define FIFO_CTRL_REG 0x2E
#define FIFO_SRC_REG 0x2F
#define INT1_CFG 0x30
#define INT1_SRC 0x31
#define INT1_THS_XH 0x32
#define INT1_THS_XL 0x33
#define INT1_THS_YH 0x34
#define INT1_THS_YL 0x35
#define INT1_THS_ZH 0x36
#define INT1_THS_ZL 0x37
#define INT1_DURATION 0x38

#define GPIOF_PORT GPIOF
#define NCS_MEMS_SPI_PORT GPIOC
#define GPIOA_PORT GPIOA

#define SPI5_SCK_PIN GPIO_PIN_7
#define SPI5_MISO_PIN GPIO_PIN_8
#define SPI5_MOSI_PIN GPIO_PIN_9
#define NCS_MEMS_SPI_PIN GPIO_PIN_1
#define MEMS_INT2_PIN GPIO_PIN_2
#define MEMS_INT1_PIN GPIO_PIN_1

#define WRITE (0 << 7)
#define READ  (1 << 7)
#define REBOOT (1 << 7)
#define POWER (1 << 3)

#define I3G425OD_SENSITIVITY_245DPS ((float)8.75f)
#define I3G425OD_SENSITIVITY_500DPS ((float)17.50f)
#define I3G425OD_SENSITIVITY_2000DPS ((float)70.00f)
#define TIME_REG ((float)0.000125)

#define VAL (TIME_REG * 0.0065 * I3G425OD_SENSITIVITY_500DPS)

#define DELAY 200


void Gyro_init();
void Gyro_deviceID();
void Gyro_power();
void Gyro_reboot();
void Gyro_temperature();
void Gyro_configure_regs();
void Gyro_verify_HAL_status();
void Gyro_enable_slave_communication();
void Gyro_disable_slave_communication();
float Gyro_getx();
uint16_t getxlow();
uint16_t getxhigh();
float getXAngle();

#endif /* INC_GYRO_H_ */
