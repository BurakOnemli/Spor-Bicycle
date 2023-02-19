################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/src/adc.c \
../libraries/src/exti.c \
../libraries/src/gpio.c \
../libraries/src/measurements.c \
../libraries/src/systemclockconfig.c \
../libraries/src/timer.c \
../libraries/src/uart.c 

OBJS += \
./libraries/src/adc.o \
./libraries/src/exti.o \
./libraries/src/gpio.o \
./libraries/src/measurements.o \
./libraries/src/systemclockconfig.o \
./libraries/src/timer.o \
./libraries/src/uart.o 

C_DEPS += \
./libraries/src/adc.d \
./libraries/src/exti.d \
./libraries/src/gpio.d \
./libraries/src/measurements.d \
./libraries/src/systemclockconfig.d \
./libraries/src/timer.d \
./libraries/src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/src/%.o libraries/src/%.su: ../libraries/src/%.c libraries/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L011xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"/Users/burak/git/Spor-Bicycle/Bicycle/libraries/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-libraries-2f-src

clean-libraries-2f-src:
	-$(RM) ./libraries/src/adc.d ./libraries/src/adc.o ./libraries/src/adc.su ./libraries/src/exti.d ./libraries/src/exti.o ./libraries/src/exti.su ./libraries/src/gpio.d ./libraries/src/gpio.o ./libraries/src/gpio.su ./libraries/src/measurements.d ./libraries/src/measurements.o ./libraries/src/measurements.su ./libraries/src/systemclockconfig.d ./libraries/src/systemclockconfig.o ./libraries/src/systemclockconfig.su ./libraries/src/timer.d ./libraries/src/timer.o ./libraries/src/timer.su ./libraries/src/uart.d ./libraries/src/uart.o ./libraries/src/uart.su

.PHONY: clean-libraries-2f-src

