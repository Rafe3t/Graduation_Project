################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/startup_stm32f40xx.s 

C_SRCS += \
../src/delay.c \
../src/main.c \
../src/stm32f4xx_it.c \
../src/system_stm32f4xx.c \
../src/tiny_printf.c 

OBJS += \
./src/delay.o \
./src/main.o \
./src/startup_stm32f40xx.o \
./src/stm32f4xx_it.o \
./src/system_stm32f4xx.o \
./src/tiny_printf.o 

C_DEPS += \
./src/delay.d \
./src/main.d \
./src/stm32f4xx_it.d \
./src/system_stm32f4xx.d \
./src/tiny_printf.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	arm-atollic-eabi-gcc -c "$<" -mcpu=cortex-m4 -std=gnu11 -O0 -g -fstack-usage -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@"
src/%.o: ../src/%.s
	arm-atollic-eabi-gcc -c -mcpu=cortex-m4 -g -Wa,--warn -x assembler-with-cpp -o "$@" "$<"

