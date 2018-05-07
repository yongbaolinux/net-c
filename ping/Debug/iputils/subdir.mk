################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../iputils/arping.c \
../iputils/clockdiff.c \
../iputils/ping.c \
../iputils/ping6_common.c \
../iputils/ping_common.c \
../iputils/rarpd.c \
../iputils/rdisc.c \
../iputils/tftpd.c \
../iputils/tftpsubs.c \
../iputils/tracepath.c \
../iputils/traceroute6.c 

OBJS += \
./iputils/arping.o \
./iputils/clockdiff.o \
./iputils/ping.o \
./iputils/ping6_common.o \
./iputils/ping_common.o \
./iputils/rarpd.o \
./iputils/rdisc.o \
./iputils/tftpd.o \
./iputils/tftpsubs.o \
./iputils/tracepath.o \
./iputils/traceroute6.o 

C_DEPS += \
./iputils/arping.d \
./iputils/clockdiff.d \
./iputils/ping.d \
./iputils/ping6_common.d \
./iputils/ping_common.d \
./iputils/rarpd.d \
./iputils/rdisc.d \
./iputils/tftpd.d \
./iputils/tftpsubs.d \
./iputils/tracepath.d \
./iputils/traceroute6.d 


# Each subdirectory must supply rules for building sources it contributes
iputils/%.o: ../iputils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


