################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/ULtra_sonic_sensor/ULtra_sonic.c 

OBJS += \
./ECUAL/ULtra_sonic_sensor/ULtra_sonic.o 

C_DEPS += \
./ECUAL/ULtra_sonic_sensor/ULtra_sonic.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/ULtra_sonic_sensor/%.o: ../ECUAL/ULtra_sonic_sensor/%.c ECUAL/ULtra_sonic_sensor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


