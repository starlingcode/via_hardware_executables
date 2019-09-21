# Copyright 2017 Emilie Gillet.
# 
# Author: Emilie Gillet (emilie.o.gillet@gmail.com)
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# 
# See http://creativecommons.org/licenses/MIT/ for more information.

DRIVERS = hardware_drivers

IFLAGS = -I$(DRIVERS)/Via/synthesis/inc \
			-I$(DRIVERS)/Via/modules/inc \
			-I$(DRIVERS)/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/inc \
			-I$(DRIVERS)/stm32f373/inc \
			-I$(DRIVERS)/Via/ui/inc \
			-I$(DRIVERS)/Via/io/inc \
			-I$(DRIVERS)/Drivers/STM32F3xx_HAL_Driver/Inc \
			-I$(DRIVERS)/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy \
			-I$(DRIVERS)/Drivers/CMSIS/Device/ST/STM32F3xx/Include \
			 -I$(DRIVERS)/Drivers/CMSIS/Include

DFLAGS = -DBUILD_F373 \
			'-D__weak=__attribute__((weak))' \
			'-D__packed="__attribute__((__packed__))"' \
			-DUSE_HAL_DRIVER \
			-DSTM32F373xC

AFLAGS = -mcpu=cortex-m4 \
 			-mthumb \
 			-mfloat-abi=hard \
 			-mfpu=fpv4-sp-d16

CPPFLAGS = $(AFLAGS) -std=c++0x $(DFLAGS) $(IFLAGS) \
			-O3 \
			-funroll-all-loops \
			-Wall \
			-fmessage-length=0 \
			-ffunction-sections \
			-fdata-sections \
			-c \
			-fno-exceptions \
			-fno-rtti 

CFLAGS = $(AFLAGS) $(DFLAGS) $(IFLAGS) \
			-O3 \
			-Wall \
			-fmessage-length=0 \
			-ffunction-sections \
			-fdata-sections 
					

# Packages to build
TARGET         = $(DRIVERS)
PACKAGES       = $(DRIVERS) \
		$(DRIVERS)/Drivers/STM32F3xx_HAL_Driver/Src \
		$(DRIVERS)/stm32f373/src \
		$(DRIVERS)/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/src \
		$(DRIVERS)/stm32f373/Drivers/STM32F3xx_HAL_Driver/Src \
		$(DRIVERS)/Via/io/src \
		$(DRIVERS)/Via/modules/atsr \
		$(DRIVERS)/Via/modules/calib \
		$(DRIVERS)/Via/modules/delay \
		$(DRIVERS)/Via/modules/gateseq \
		$(DRIVERS)/Via/modules/meta \
		$(DRIVERS)/Via/modules/osc3 \
		$(DRIVERS)/Via/modules/scanner \
		$(DRIVERS)/Via/modules/sinebeat \
		$(DRIVERS)/Via/modules/sync \
		$(DRIVERS)/Via/modules/sync3 \
		$(DRIVERS)/Via/modules/touch \
		$(DRIVERS)/Via/synthesis/oscillators \
		$(DRIVERS)/Via/synthesis/sequencers \
		$(DRIVERS)/Via/synthesis/signal_processors \
		$(DRIVERS)/Via/ui/src


TOOLCHAIN_PATH ?= /usr/local/gcc-arm-none-eabi-7-2017-q4-major/

# TOOLCHAIN_PATH ?= /Applications/Ac6/SystemWorkbench.app/Contents/Eclipse/plugins/fr.ac6.mcu.externaltools.arm-none.macos64_1.16.0.201807130628/tools/compiler/

TOOLCHAIN_BIN = $(TOOLCHAIN_PATH)bin/

BUILD_ROOT     = build/
BUILD_DIR      = $(BUILD_ROOT)$(TARGET)/

CC             = $(TOOLCHAIN_BIN)arm-none-eabi-gcc
CXX            = $(TOOLCHAIN_BIN)arm-none-eabi-g++
AR             = $(TOOLCHAIN_BIN)arm-none-eabi-ar

VPATH          = $(PACKAGES)

CC_FILES       = $(notdir $(wildcard $(patsubst %,%/*.cpp,$(PACKAGES))))
C_FILES        = $(notdir $(wildcard $(patsubst %,%/*.c,$(PACKAGES))))
AS_FILES       = $(notdir $(wildcard $(patsubst %,%/*.s,$(PACKAGES))))

$(BUILD_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"

$(BUILD_DIR)%.o: %.cpp
	$(CXX) $(CPPFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"


OBJ_FILES      = $(CC_FILES:.cpp=.o) $(C_FILES:.c=.o) $(AS_FILES:.s=.o)
OBJS           = $(patsubst %,$(BUILD_DIR)%,$(OBJ_FILES))

all: $(BUILD_DIR) $(BUILD_DIR)lib$(DRIVERS).a

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Tool invocations
$(BUILD_DIR)lib$(DRIVERS).a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Archiver'
	$(AR) -r  "$(BUILD_DIR)lib$(DRIVERS).a" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

clean:
	rm -r build/$(DRIVERS)
