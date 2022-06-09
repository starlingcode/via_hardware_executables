# Adapted from https://github.com/pichenettes/mutable-dev-environment
# and https://www.openstm32.org/System+Workbench+for+STM32
# See LICENSE.md for details

DRIVERS = hardware_drivers

PACKAGES       = $(TARGET)/Drivers/STM32F3xx_HAL_Driver/Src \
		$(TARGET)/src \
		$(TARGET)/startup \

IFLAGS = -I$(DRIVERS)/Via/synthesis/inc \
			-I$(DRIVERS)/Via/modules/inc \
			-I$(DRIVERS)/stm32f373/Middlewares/ST/STM32_TouchSensing_Library/inc \
			-I$(DRIVERS)/stm32f373/inc \
			-I$(DRIVERS)/Via/ui/inc \
			-I$(DRIVERS)/Via/io/inc \
			-I$(DRIVERS)/Drivers/STM32F3xx_HAL_Driver/Inc \
			-I$(DRIVERS)/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy \
			-I$(DRIVERS)/Drivers/CMSIS/Device/ST/STM32F3xx/Include \
			 -I$(DRIVERS)/Drivers/CMSIS/Include \
			 -I$(TARGET)/inc \

DFLAGS = -DBUILD_F373 \
			'-D__weak=__attribute__((weak))' \
			'-D__packed="__attribute__((__packed__))"' \
			-DUSE_HAL_DRIVER \
			-DSTM32F373xC

AFLAGS = -mcpu=cortex-m4 \
 			-mthumb \
 			-mfloat-abi=hard \
 			-mfpu=fpv4-sp-d16 

CPPFLAGS = $(AFLAGS) $(IFLAGS) $(DFLAGS) \
			-std=c++0x \
			-Og \
			-g3 \
			-Wall \
			-fmessage-length=0 \
			-ffunction-sections \
			-fno-exceptions \
			-fno-rtti

CFLAGS = $(AFLAGS) $(IFLAGS) $(DFLAGS) \
			-O3 \
			-g3 \
			-Wall \
			-fmessage-length=0 \
			-ffunction-sections \


TOOLCHAIN_PATH ?= /usr/local/gcc-arm-none-eabi-7-2017-q4-major/

# TOOLCHAIN_PATH ?= /Applications/Ac6/SystemWorkbench.app/Contents/Eclipse/plugins/fr.ac6.mcu.externaltools.arm-none.macos64_1.16.0.201807130628/tools/compiler/


TOOLCHAIN_BIN = $(TOOLCHAIN_PATH)bin/

BUILD_ROOT     = build/
BUILD_DIR      = $(BUILD_ROOT)$(TARGET)/

CC             = $(TOOLCHAIN_BIN)arm-none-eabi-gcc
CXX            = $(TOOLCHAIN_BIN)arm-none-eabi-g++
AS 				= $(TOOLCHAIN_BIN)arm-none-eabi-as
OBJCOPY 	   = $(TOOLCHAIN_BIN)arm-none-eabi-objcopy
SIZE 	   		= $(TOOLCHAIN_BIN)arm-none-eabi-size
NM 	   			= $(TOOLCHAIN_BIN)arm-none-eabi-nm

VPATH          = $(PACKAGES)

CC_FILES       = $(notdir $(wildcard $(patsubst %,%/*.cpp,$(PACKAGES))))
C_FILES        = $(notdir $(wildcard $(patsubst %,%/*.c,$(PACKAGES))))
AS_FILES       = $(notdir $(wildcard $(patsubst %,%/*.s,$(PACKAGES))))

$(BUILD_DIR)%.o: %.s
	$(AS) -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g -o "$@" "$<"

$(BUILD_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"

$(BUILD_DIR)%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"


OBJ_FILES      = $(CC_FILES:.cpp=.o) $(C_FILES:.c=.o) $(AS_FILES:.s=.o)
OBJS           = $(patsubst %,$(BUILD_DIR)%,$(OBJ_FILES))

LIBVIA = build/$(DRIVERS)/

VIAARCHIVE = $(LIBVIA)/$(DRIVERS).a

LINKER_SCRIPT = $(TARGET)/STM32F373CCTx_FLASH.ld

LIBS = -l$(DRIVERS)

TARGET_ELF = $(BUILD_DIR)$(TARGET).elf

TARGET_BIN = $(BUILD_DIR)$(TARGET).bin

# All Target
all: $(BUILD_DIR) $(TARGET_ELF) 

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Tool invocations
$(TARGET_ELF): $(OBJS) $(VIAARCHIVE)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU G++ Linker'
	$(CXX) -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -L$(LIBVIA) -specs=nosys.specs -specs=nano.specs -T$(LINKER_SCRIPT) -Wl,-Map=$(BUILD_DIR)output.map -Wl,--gc-sections -fno-exceptions -fno-rtti -o $(TARGET_ELF) $(OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	make -f $(TARGET)/makefile --no-print-directory post-build

$(VIAARCHIVE):
	make -f $(DRIVERS)/makefile

clean:

	rm -r build/$(TARGET) || true
#	rm -r build/$(DRIVERS) || true

post-build:
	-@echo 'Generating binary and Printing size information:'
	$(OBJCOPY) -O binary $(TARGET_ELF) $(TARGET_BIN)
	$(NM) --print-size --size-sort --radix=d $(TARGET_ELF)
	$(SIZE) $(TARGET_ELF)
	-@echo ' '
	python append_resources.py    

.SECONDARY: post-build

# ------------------------------------------------------------------------------
# Firmware flashing
# ------------------------------------------------------------------------------

OPENOCD_TARGET_SCRIPT ?= target/stm32f3x.cfg

OPENOCD_INTERFACE_SCRIPT = interface/stlink-v2.cfg

BASE_JTAG_CMD = openocd \
			-s /opt/local/share/openocd/scripts \
			-f $(OPENOCD_INTERFACE_SCRIPT) \
			-f $(OPENOCD_TARGET_SCRIPT) \
			-c "init" -c "halt" -c "sleep 200"

POSTLUDE = -c "sleep 200" -c "reset run" -c "shutdown"

upload: $(BUILD_DIR) $(TARGET_ELF)
	$(BASE_JTAG_CMD) \
				-c "flash erase_address 0x08000000 32768" \
				-c "reset halt" \
				-c "flash write_image erase $(TARGET_BIN) 0x08000000" \
				-c "verify_image $(TARGET_BIN) 0x08000000" \
				$(POSTLUDE)

calib: 
	$(BASE_JTAG_CMD) \
				-c "reset_config none separate" \
				-c "reset halt" \
				-c "sleep 200" \
				-c "stm32f1x options_write 0 USEROPT 0x$(TARGET_VERSION)$(TARGET_ID)" \
				-c "stm32f1x options_load 0" -c "sleep 200" -c "shutdown"
	$(BASE_JTAG_CMD) \
				-c "stm32f1x options_read 0" \
				$(POSTLUDE)

upload-usb: $(BUILD_DIR) $(TARGET_ELF)
	sudo dfu-util --device 0483:df11 -a 0 -s 0x08000000 -D $(TARGET_BIN) -R

calib-usb: $(BUILD_DIR)
	python3 dfuobgen.py $(TARGET) $(TARGET_ID) $(TARGET_VERSION)
	sudo dfu-util --device 0483:df11 -a 1 -s 0x1FFFF800:will-reset -D $(BUILD_DIR)optionbytes.temp

.PHONY: upload calib upload-usb calib-usb

