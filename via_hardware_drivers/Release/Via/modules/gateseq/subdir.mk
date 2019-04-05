################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Via/modules/gateseq/gateseq_init.cpp \
../Via/modules/gateseq/gateseq_interrupt_handlers.cpp \
../Via/modules/gateseq/gateseq_modes.cpp \
../Via/modules/gateseq/gateseq_pattern_init.cpp \
../Via/modules/gateseq/gateseq_ui_implementation.cpp 

OBJS += \
./Via/modules/gateseq/gateseq_init.o \
./Via/modules/gateseq/gateseq_interrupt_handlers.o \
./Via/modules/gateseq/gateseq_modes.o \
./Via/modules/gateseq/gateseq_pattern_init.o \
./Via/modules/gateseq/gateseq_ui_implementation.o 

CPP_DEPS += \
./Via/modules/gateseq/gateseq_init.d \
./Via/modules/gateseq/gateseq_interrupt_handlers.d \
./Via/modules/gateseq/gateseq_modes.d \
./Via/modules/gateseq/gateseq_pattern_init.d \
./Via/modules/gateseq/gateseq_ui_implementation.d 


# Each subdirectory must supply rules for building sources it contributes
Via/modules/gateseq/%.o: ../Via/modules/gateseq/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c++0x -DBUILD_F373 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F373xC -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/synthesis/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/modules/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/stm32f373/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/ui/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/io/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/CMSIS/Include"  -O3 -funroll-all-loops -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


