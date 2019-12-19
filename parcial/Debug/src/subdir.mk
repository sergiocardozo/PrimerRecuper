################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Linkedlist.c \
../src/controller.c \
../src/eComputer.c \
../src/parcial.c \
../src/parser.c \
../src/utn.c 

OBJS += \
./src/Linkedlist.o \
./src/controller.o \
./src/eComputer.o \
./src/parcial.o \
./src/parser.o \
./src/utn.o 

C_DEPS += \
./src/Linkedlist.d \
./src/controller.d \
./src/eComputer.d \
./src/parcial.d \
./src/parser.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


