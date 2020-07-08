################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F/%.o: ../Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/StdPeriph_Driver/inc" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/Third-Party/FreeRTOS/org/Source/portable/MemMang" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/Config" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/Debug/Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/Debug/Third-Party/FreeRTOS/org/Source/portable/MemMang" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/Config" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/Third-Party/FreeRTOS" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/Third-Party/FreeRTOS/org/Source/include" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/inc" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/CMSIS/device" -I"C:/Users/sushant/Desktop/RTOS/Workspace/RTOS_Workspace/STM32_Exercise/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


