################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ADC.lss \

FLASH_IMAGE += \
ADC.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: ADC.elf secondary-outputs

# Tool invocations
ADC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADC.map -mmcu=atmega16 -o "ADC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC.lss: ADC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADC.elf  >"ADC.lss"
	@echo 'Finished building: $@'
	@echo ' '

ADC.hex: ADC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex ADC.elf  "ADC.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 ADC.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: ADC.elf
	@echo 'Invoking: AVRDude'
	/usr/local/CrossPack-AVR-20100115/bin/avrdude -pm16 -cusbtiny -u -Uflash:w:ADC.hex:a -Ulfuse:w:0xe1:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) ADC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
