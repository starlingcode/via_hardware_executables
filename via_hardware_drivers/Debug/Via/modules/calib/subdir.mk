################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Via/modules/calib/calib_ui_implementation.cpp \
../Via/modules/calib/calibration_helpers.cpp 

OBJS += \
./Via/modules/calib/calib_ui_implementation.o \
./Via/modules/calib/calibration_helpers.o 

CPP_DEPS += \
./Via/modules/calib/calib_ui_implementation.d \
./Via/modules/calib/calibration_helpers.d 


# Each subdirectory must supply rules for building sources it contributes
Via/modules/calib/%.o: ../Via/modules/calib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c++0x -DBUILD_F373 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F373xC -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/synthesis/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/modules/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/stm32f373/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/ui/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Via/io/inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/Users/willmitchell/Documents/via_hardware_executables/via_hardware_drivers/Drivers/CMSIS/Include"  -O3 -funroll-all-loops -g3 -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


