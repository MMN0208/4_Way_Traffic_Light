################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/buzzer_interfacing.c \
../Core/Src/fsm_for_multi_mode.c \
../Core/Src/fsm_for_pedestrian.c \
../Core/Src/global.c \
../Core/Src/gpio.c \
../Core/Src/input_reading.c \
../Core/Src/main.c \
../Core/Src/pedestrian_light_processing.c \
../Core/Src/sched.c \
../Core/Src/software_timer.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tim.c \
../Core/Src/traffic_light_processing.c \
../Core/Src/uart_communication.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/buzzer_interfacing.o \
./Core/Src/fsm_for_multi_mode.o \
./Core/Src/fsm_for_pedestrian.o \
./Core/Src/global.o \
./Core/Src/gpio.o \
./Core/Src/input_reading.o \
./Core/Src/main.o \
./Core/Src/pedestrian_light_processing.o \
./Core/Src/sched.o \
./Core/Src/software_timer.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tim.o \
./Core/Src/traffic_light_processing.o \
./Core/Src/uart_communication.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/buzzer_interfacing.d \
./Core/Src/fsm_for_multi_mode.d \
./Core/Src/fsm_for_pedestrian.d \
./Core/Src/global.d \
./Core/Src/gpio.d \
./Core/Src/input_reading.d \
./Core/Src/main.d \
./Core/Src/pedestrian_light_processing.d \
./Core/Src/sched.d \
./Core/Src/software_timer.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tim.d \
./Core/Src/traffic_light_processing.d \
./Core/Src/uart_communication.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/buzzer_interfacing.d ./Core/Src/buzzer_interfacing.o ./Core/Src/buzzer_interfacing.su ./Core/Src/fsm_for_multi_mode.d ./Core/Src/fsm_for_multi_mode.o ./Core/Src/fsm_for_multi_mode.su ./Core/Src/fsm_for_pedestrian.d ./Core/Src/fsm_for_pedestrian.o ./Core/Src/fsm_for_pedestrian.su ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/input_reading.d ./Core/Src/input_reading.o ./Core/Src/input_reading.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/pedestrian_light_processing.d ./Core/Src/pedestrian_light_processing.o ./Core/Src/pedestrian_light_processing.su ./Core/Src/sched.d ./Core/Src/sched.o ./Core/Src/sched.su ./Core/Src/software_timer.d ./Core/Src/software_timer.o ./Core/Src/software_timer.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/traffic_light_processing.d ./Core/Src/traffic_light_processing.o ./Core/Src/traffic_light_processing.su ./Core/Src/uart_communication.d ./Core/Src/uart_communication.o ./Core/Src/uart_communication.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

