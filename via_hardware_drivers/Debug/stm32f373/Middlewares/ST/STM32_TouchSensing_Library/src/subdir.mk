################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_acq.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_acq_tsc.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_dxs.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_ecs.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_filter.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_globals.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_linrot.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_object.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_time.c \
../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_touchkey.c 

OBJS += \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_acq.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_acq_tsc.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_dxs.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_ecs.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_filter.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_globals.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_linrot.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_object.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_time.o \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_touchkey.o 

C_DEPS += \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_acq.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_acq_tsc.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_dxs.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_ecs.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_filter.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_globals.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_linrot.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_object.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_time.d \
./stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/tsl_touchkey.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/%.o: ../stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F373xC -DBUILD_F373 -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/synthesis/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/modules/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/stm32f373/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/ui/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/io/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/CMSIS/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


