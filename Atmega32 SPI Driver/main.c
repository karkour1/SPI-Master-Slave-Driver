/*
 * main.c
 *
 *  Created on: Apr 1, 2024
 *  Author: Abdullah Karkour
 */

#include <util/delay.h>
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL*/
#include "DIO_interface.h"
#include"SPI_interface.h"

uint8_t ch ;
void CallBack(void)
{
	MCAL_SPI_Recieve_Interrupt(&ch);
}

int main(void)
{
	// Global Interrupt
	GI_Enable;
	// Set PortA Output
	DIO_SetPortDirection(DIO_PORTA, DIO_Port_OUTPUT);

	// init master
	MCAL_SPI_init(slave, SPI_CLK_Phase_Sample_At_Last_Edge, SPI_Data_Order_MSB_First, SPI_SSM_Slave_Input, SPI_IRQ_Enable , CallBack , SPI_CLK_Rate_fosc_16);

	while(1)
	{
			MCAL_SPI_Transmit(&ch, SPI_IRQ_Enable);
			DIO_SetPortValue(DIO_PORTA, ch);
	}
}
