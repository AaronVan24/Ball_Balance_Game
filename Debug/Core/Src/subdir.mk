################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ApplicationCode.c \
../Core/Src/Button_Driver.c \
../Core/Src/ErrorHandling.c \
../Core/Src/Gyro.c \
../Core/Src/InterruptControl.c \
../Core/Src/LCD_Driver.c \
../Core/Src/LED_Driver.c \
../Core/Src/RNG.c \
../Core/Src/Scheduler.c \
../Core/Src/fonts.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/ApplicationCode.o \
./Core/Src/Button_Driver.o \
./Core/Src/ErrorHandling.o \
./Core/Src/Gyro.o \
./Core/Src/InterruptControl.o \
./Core/Src/LCD_Driver.o \
./Core/Src/LED_Driver.o \
./Core/Src/RNG.o \
./Core/Src/Scheduler.o \
./Core/Src/fonts.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/ApplicationCode.d \
./Core/Src/Button_Driver.d \
./Core/Src/ErrorHandling.d \
./Core/Src/Gyro.d \
./Core/Src/InterruptControl.d \
./Core/Src/LCD_Driver.d \
./Core/Src/LED_Driver.d \
./Core/Src/RNG.d \
./Core/Src/Scheduler.d \
./Core/Src/fonts.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/ApplicationCode.cyclo ./Core/Src/ApplicationCode.d ./Core/Src/ApplicationCode.o ./Core/Src/ApplicationCode.su ./Core/Src/Button_Driver.cyclo ./Core/Src/Button_Driver.d ./Core/Src/Button_Driver.o ./Core/Src/Button_Driver.su ./Core/Src/ErrorHandling.cyclo ./Core/Src/ErrorHandling.d ./Core/Src/ErrorHandling.o ./Core/Src/ErrorHandling.su ./Core/Src/Gyro.cyclo ./Core/Src/Gyro.d ./Core/Src/Gyro.o ./Core/Src/Gyro.su ./Core/Src/InterruptControl.cyclo ./Core/Src/InterruptControl.d ./Core/Src/InterruptControl.o ./Core/Src/InterruptControl.su ./Core/Src/LCD_Driver.cyclo ./Core/Src/LCD_Driver.d ./Core/Src/LCD_Driver.o ./Core/Src/LCD_Driver.su ./Core/Src/LED_Driver.cyclo ./Core/Src/LED_Driver.d ./Core/Src/LED_Driver.o ./Core/Src/LED_Driver.su ./Core/Src/RNG.cyclo ./Core/Src/RNG.d ./Core/Src/RNG.o ./Core/Src/RNG.su ./Core/Src/Scheduler.cyclo ./Core/Src/Scheduler.d ./Core/Src/Scheduler.o ./Core/Src/Scheduler.su ./Core/Src/fonts.cyclo ./Core/Src/fonts.d ./Core/Src/fonts.o ./Core/Src/fonts.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

