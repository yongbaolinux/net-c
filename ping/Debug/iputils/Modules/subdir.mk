################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../iputils/Modules/pg3.c 

OBJS += \
./iputils/Modules/pg3.o 

C_DEPS += \
./iputils/Modules/pg3.d 


# Each subdirectory must supply rules for building sources it contributes
iputils/Modules/%.o: ../iputils/Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


