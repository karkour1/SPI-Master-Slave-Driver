# SPI-Driver-Library for STM32F103C8 & ATmega32

Welcome to the **SPI-Driver-Library for STM32F103C8 & ATmega32** repository! This project provides a robust and efficient SPI (Serial Peripheral Interface) driver specifically tailored for STM32F103C8 and ATmega32 microcontrollers, enabling seamless communication with peripheral devices.

## Features

- **Full-Duplex Communication**: Supports simultaneous sending and receiving of data.
- **Configurable Clock Speed**: Adjust SPI clock speed to match your peripheral requirements.
- **Master and Slave Modes**: Easily switch between SPI master and slave modes.
- **Interrupt and Polling Modes**: Choose between interrupt-driven communication or polling mode for flexibility.
- **Platform Specific Implementations**: Includes separate drivers optimized for STM32F103C8 and ATmega32.
- **Cross-Platform Code Structure**: Easily portable between STM32 and AVR microcontroller families.

## Overview

The SPI (Serial Peripheral Interface) is a widely-used protocol for short-distance communication between microcontrollers and peripheral devices such as sensors, memory, and display modules. This driver library simplifies the process of configuring and using SPI on STM32F103C8 and ATmega32 microcontrollers by providing a comprehensive set of functions for managing SPI operations.

### Platform Specific Implementations

- **STM32F103C8**: This implementation leverages the powerful features of the STM32F103C8 microcontroller, providing flexibility in configuring SPI settings such as baud rate, data frame format, and clock polarity/phase.

- **ATmega32**: The ATmega32 implementation is optimized for the AVR architecture, ensuring efficient SPI communication while maintaining ease of use. The driver provides functions for both master and slave configurations.

### Applications

This SPI driver is ideal for a variety of applications, including:

- **Sensor Communication**: Interface with SPI-based sensors like accelerometers, gyroscopes, and temperature sensors.
- **Memory Access**: Read from and write to SPI-based EEPROMs or flash memory.
- **Display Control**: Manage SPI-based LCDs, OLEDs, or LED matrices.

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
