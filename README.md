# SPI-Driver-Library for STM32F103C8 & ATmega32

Welcome to the **SPI-Driver-Library for STM32F103C8 & ATmega32** repository! This project provides a robust and efficient SPI (Serial Peripheral Interface) driver specifically tailored for STM32F103C8 and ATmega32 microcontrollers, enabling seamless communication with peripheral devices.

## Features

- **Full-Duplex Communication**: Supports simultaneous sending and receiving of data.
- **Configurable Clock Speed**: Adjust SPI clock speed to match your peripheral requirements.
- **Master and Slave Modes**: Easily switch between SPI master and slave modes.
- **Interrupt and Polling Modes**: Choose between interrupt-driven communication or polling mode for flexibility.
- **Platform Specific Implementations**: Includes separate drivers optimized for STM32F103C8 and ATmega32.
- **Cross-Platform Code Structure**: Easily portable between STM32 and AVR microcontroller families.

## Getting Started

### Prerequisites

To use this SPI driver, you'll need:

- STM32F103C8 or ATmega32 microcontroller.
- An IDE that supports C programming (e.g., Keil for STM32, Atmel Studio for AVR).
- Basic understanding of SPI protocol.

### Installation

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/SPI-Driver-Library.git
    ```

2. Include the appropriate SPI driver source files in your project:
    - For STM32F103C8:
      - `stm32_spi_driver.c`
      - `stm32_spi_driver.h`
    - For ATmega32:
      - `atmega32_spi_driver.c`
      - `atmega32_spi_driver.h`

3. Configure the SPI settings in the corresponding header file according to your hardware specifications.

### Usage

#### STM32F103C8 Example:

1. **Initialize the SPI Interface:**
    ```c
    STM32_SPI_Init(SPI_Mode_Master, SPI_BaudRatePrescaler_16);
    ```

2. **Send Data:**
    ```c
    uint8_t dataToSend = 0x55;
    STM32_SPI_SendData(dataToSend);
    ```

3. **Receive Data:**
    ```c
    uint8_t receivedData = STM32_SPI_ReceiveData();
    ```

#### ATmega32 Example:

1. **Initialize the SPI Interface:**
    ```c
    ATmega32_SPI_Init(SPI_Mode_Master, SPI_BaudRatePrescaler_16);
    ```

2. **Send Data:**
    ```c
    uint8_t dataToSend = 0x55;
    ATmega32_SPI_SendData(dataToSend);
    ```

3. **Receive Data:**
    ```c
    uint8_t receivedData = ATmega32_SPI_ReceiveData();
    ```