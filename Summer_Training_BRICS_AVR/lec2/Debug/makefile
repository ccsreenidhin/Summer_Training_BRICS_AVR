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
lec2.lss \

FLASH_IMAGE += \
lec2.hex \

EEPROM_IMAGE += \
lec2.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: lec2.elf secondary-outputs

# Tool invocations
lec2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lec2.map -mmcu=atmega16 -o "lec2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lec2.lss: lec2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lec2.elf  >"lec2.lss"
	@echo 'Finished building: $@'
	@echo ' '

lec2.hex: lec2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex lec2.elf  "lec2.hex"
	@echo 'Finished building: $@'
	@echo ' '

lec2.eep: lec2.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex lec2.elf  "lec2.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lec2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 lec2.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: lec2.elf
	@echo 'Invoking: AVRDude'
	/usr/local/CrossPack-AVR-20100115/bin/avrdude -pm16 -cusbtiny -Uflash:w:lec2.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) lec2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
