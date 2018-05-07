################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../iputils/ninfod/ni_ifaddrs.c \
../iputils/ninfod/ninfod.c \
../iputils/ninfod/ninfod_addrs.c \
../iputils/ninfod/ninfod_core.c \
../iputils/ninfod/ninfod_name.c 

OBJS += \
./iputils/ninfod/ni_ifaddrs.o \
./iputils/ninfod/ninfod.o \
./iputils/ninfod/ninfod_addrs.o \
./iputils/ninfod/ninfod_core.o \
./iputils/ninfod/ninfod_name.o 

C_DEPS += \
./iputils/ninfod/ni_ifaddrs.d \
./iputils/ninfod/ninfod.d \
./iputils/ninfod/ninfod_addrs.d \
./iputils/ninfod/ninfod_core.d \
./iputils/ninfod/ninfod_name.d 


# Each subdirectory must supply rules for building sources it contributes
iputils/ninfod/%.o: ../iputils/ninfod/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


