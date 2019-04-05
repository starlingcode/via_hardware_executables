################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f373/src/adc.c \
../stm32f373/src/dac.c \
../stm32f373/src/dma.c \
../stm32f373/src/eeprom.c \
../stm32f373/src/gpio.c \
../stm32f373/src/sdadc.c \
../stm32f373/src/stm32f3xx_hal_msp.c \
../stm32f373/src/stmCriticalSection.c \
../stm32f373/src/system_stm32f3xx.c \
../stm32f373/src/tim.c \
../stm32f373/src/touchsensing.c \
../stm32f373/src/tsc.c \
../stm32f373/src/tsl_user.c 

OBJS += \
./stm32f373/src/adc.o \
./stm32f373/src/dac.o \
./stm32f373/src/dma.o \
./stm32f373/src/eeprom.o \
./stm32f373/src/gpio.o \
./stm32f373/src/sdadc.o \
./stm32f373/src/stm32f3xx_hal_msp.o \
./stm32f373/src/stmCriticalSection.o \
./stm32f373/src/system_stm32f3xx.o \
./stm32f373/src/tim.o \
./stm32f373/src/touchsensing.o \
./stm32f373/src/tsc.o \
./stm32f373/src/tsl_user.o 

C_DEPS += \
./stm32f373/src/adc.d \
./stm32f373/src/dac.d \
./stm32f373/src/dma.d \
./stm32f373/src/eeprom.d \
./stm32f373/src/gpio.d \
./stm32f373/src/sdadc.d \
./stm32f373/src/stm32f3xx_hal_msp.d \
./stm32f373/src/stmCriticalSection.d \
./stm32f373/src/system_stm32f3xx.d \
./stm32f373/src/tim.d \
./stm32f373/src/touchsensing.d \
./stm32f373/src/tsc.d \
./stm32f373/src/tsl_user.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f373/src/%.o: ../stm32f373/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F373xC -DBUILD_F373 -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/synthesis/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/modules/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/stm32f373/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/ui/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/io/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/CMSIS/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


