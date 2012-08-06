################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc_lib.c \
../gsm.c \
../gsm_lib.c \
../lcd_lib.c \
../uart_lib.c 

OBJS += \
./adc_lib.o \
./gsm.o \
./gsm_lib.o \
./lcd_lib.o \
./uart_lib.o 

C_DEPS += \
./adc_lib.d \
./gsm.d \
./gsm_lib.d \
./lcd_lib.d \
./uart_lib.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/Dropbox/LECTURE/AVR/wosd/LFR" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


