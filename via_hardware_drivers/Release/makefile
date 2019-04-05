################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32f373/src/subdir.mk
-include stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src/subdir.mk
-include stm32f373/Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include Via/ui/src/subdir.mk
-include Via/synthesis/signal_processors/subdir.mk
-include Via/synthesis/sequencers/subdir.mk
-include Via/synthesis/oscillators/subdir.mk
-include Via/modules/sync/subdir.mk
-include Via/modules/scanner/subdir.mk
-include Via/modules/meta/subdir.mk
-include Via/modules/gateseq/subdir.mk
-include Via/modules/calib/subdir.mk
-include Via/io/src/subdir.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: libvia_hardware_drivers.a

# Tool invocations
libvia_hardware_drivers.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Archiver'
	arm-none-eabi-ar -r  "libvia_hardware_drivers.a" @"objects.list" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
