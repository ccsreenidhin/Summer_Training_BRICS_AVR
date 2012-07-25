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
LED1.lss \

FLASH_IMAGE += \
LED1.hex \

EEPROM_IMAGE += \
LED1.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: LED1.elf secondary-outputs

# Tool invocations
LED1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LED1.map -mmcu=atmega16 -o "LED1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LED1.lss: LED1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LED1.elf  >"LED1.lss"
	@echo 'Finished building: $@'
	@echo ' '

LED1.hex: LED1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex LED1.elf  "LED1.hex"
	@echo 'Finished building: $@'
	@echo ' '

LED1.eep: LED1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LED1.elf  "LED1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LED1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 LED1.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: LED1.elf
	@echo 'Invoking: AVRDude'
	/usr/local/CrossPack-AVR-20100115/bin/avrdude -pm16 -cusbtiny -Uflash:w:LED1.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) LED1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
