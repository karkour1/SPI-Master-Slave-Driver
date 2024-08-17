/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ABDULLAH KARKOUR
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "Stm32_F103X6.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "Stm32_F103C6_RCC_driver.h"
#include "Stm32F103C8_SPI_Driver.h"
#include "Stm32_F103C6_UART_driver.h"

//#define MCU_Act_As_Master
#define MCU_Act_As_Slave

uint16_t ch ;

void SPI_IRQ_CallBack(S_IRQ_SRC IRQ_src)
{
#ifdef MCU_Act_As_Slave
	if(IRQ_src.RXNE)
	{
		ch = 0xF ;
		MCAL_SPI_TX_RX(SPI1, &ch, SPI_disable);
		MCAL_UART_SendData(USART1, &ch, enable);
	}
#endif
}

void UART_IRQ_Callback (void)
{

#ifdef MCU_Act_As_Master
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	MCAL_SPI_TX_RX(SPI1, &ch, SPI_enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif
}

int main(void)
{

	//Enable CLock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	//=========	UART Initiate ==========
	UART_PinConfig_t uartCFG ;
	uartCFG.BaudRate = UART_BaudRate_115200 ;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE ;
	uartCFG.IRQ_Enable = UART_IRQ_Enable_RXNEIE ;
	uartCFG.P_IRQ_CallBack = UART_IRQ_Callback ;
	uartCFG.Parity =UART_Parity__NONE ;
	uartCFG.Payload_Length = UART_Payload_Length_8B;
	uartCFG.StopBits = UART_StopBits__1 ;
	uartCFG.Mode = UART_Mode_TX_RX ;

	MCAL_UART_Init(USART1, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	//=======	SPI Initiate ============
	SPI_Config_t SPI_Cfg ;
	SPI_Cfg.Communication_Mode = SPI_Communication_Mode_2line_Full_duplex;
	SPI_Cfg.Data_Size 	 = SPI_Data_Size_8bits ;
	SPI_Cfg.Frame_Format = SPI_Frame_Format_MSB_First;
	SPI_Cfg.clock_phase  = SPI_clock_phase_Second_Edge;
	SPI_Cfg.clock_polarity=SPI_clock_polarity_HIGH ;
	SPI_Cfg.baud_rate_prescalers = SPI_baud_rate_prescalers_8 ;

#ifdef MCU_Act_As_Master

	SPI_Cfg.Dvice_Mode = SPI_Dvice_Mode_Master;
	SPI_Cfg.NSS = SPI_NSS_SW_Internal_select_Set;
	SPI_Cfg.IRQ_Enable = SPI_IRQ_Enable_NONE;


	// SS Control Pin4 PORTA  by GPIO
	GPIO_PinConfig_t Pin_Cfg ;
	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_4;
	Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &Pin_Cfg);

	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

#endif

#ifdef  MCU_Act_As_Slave
	SPI_Cfg.Dvice_Mode = SPI_Dvice_Mode_Slave;
	SPI_Cfg.NSS = SPI_NSS_HW_Slave;
	SPI_Cfg.IRQ_Enable = SPI_IRQ_Enable_RXNEIE;
	SPI_Cfg.P_IRQ_CallBack = SPI_IRQ_CallBack ;
#endif
	MCAL_SPI_Init(SPI1, &SPI_Cfg);
	MCAL_SPI_GPIO_Set_Pins(SPI1);




	/* Loop forever */
	while(1)
	{
	}

}
