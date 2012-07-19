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
vvvvv.lss \

FLASH_IMAGE += \
vvvvv.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: vvvvv.elf secondary-outputs

# Tool invocations
vvvvv.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,vvvvv.map -mmcu=atmega16 -o "vvvvv.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

vvvvv.lss: vvvvv.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S vvvvv.elf  >"vvvvv.lss"
	@echo 'Finished building: $@'
	@echo ' '

vvvvv.hex: vvvvv.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex vvvvv.elf  "vvvvv.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: vvvvv.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 vvvvv.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) vvvvv.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
