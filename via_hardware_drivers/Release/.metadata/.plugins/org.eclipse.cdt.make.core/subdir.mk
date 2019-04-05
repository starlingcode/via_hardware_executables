################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.make.core/specs.c 

CPP_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp 

OBJS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 

C_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 

CPP_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 


# Each subdirectory must supply rules for building sources it contributes
.metadata/.plugins/org.eclipse.cdt.make.core/%.o: ../.metadata/.plugins/org.eclipse.cdt.make.core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DBUILD_F373 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F373xC -I"/Users/willmitchell/Documents/via_hardware_executables/Via/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/stm32f373/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/Drivers/CMSIS/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

.metadata/.plugins/org.eclipse.cdt.make.core/%.o: ../.metadata/.plugins/org.eclipse.cdt.make.core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c++0x -DBUILD_F373 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F373xC -I"/Users/willmitchell/Documents/via_hardware_executables/Via/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/stm32f373/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/Users/willmitchell/Documents/via_hardware_executables/Via/Drivers/CMSIS/Include"  -O3 -funroll-all-loops -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


