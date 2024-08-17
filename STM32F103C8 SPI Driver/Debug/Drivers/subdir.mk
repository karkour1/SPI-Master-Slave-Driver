################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Stm32F103C8_SPI_Driver.c \
../Drivers/Stm32_F103C6_RCC_driver.c \
../Drivers/Stm32_F103C6_UART_driver.c \
../Drivers/Stm32_F103C6_gpio_driver.c 

OBJS += \
./Drivers/Stm32F103C8_SPI_Driver.o \
./Drivers/Stm32_F103C6_RCC_driver.o \
./Drivers/Stm32_F103C6_UART_driver.o \
./Drivers/Stm32_F103C6_gpio_driver.o 

C_DEPS += \
./Drivers/Stm32F103C8_SPI_Driver.d \
./Drivers/Stm32_F103C6_RCC_driver.d \
./Drivers/Stm32_F103C6_UART_driver.d \
./Drivers/Stm32_F103C6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Stm32F103C8_SPI_Driver.o: ../Drivers/Stm32F103C8_SPI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Stm32F103C8_SPI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Stm32_F103C6_RCC_driver.o: ../Drivers/Stm32_F103C6_RCC_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Stm32_F103C6_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Stm32_F103C6_UART_driver.o: ../Drivers/Stm32_F103C6_UART_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Stm32_F103C6_UART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Stm32_F103C6_gpio_driver.o: ../Drivers/Stm32_F103C6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Stm32_F103C6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

