/*
 * SPI_Programme.c
 *
 *  Created on: Apr 1, 2024
 *  Author: Abdullah Karkour
 */

/****************************************
 * Includes
 ****************************************/
#include"SPI_interface.h"

/****************************************
 * Generic Variables
 ****************************************/
SPI_mode_t G_Device_Mode ;
void (*G_P_CallBack)(void);

/****************************************
 * APIS Supported By SPI_interface.h
 ****************************************/
/**================================================================
 * @Fn			-MCAL_SPI_init
 * @brief 		-Initializes the SPI according to the specified parameters in the PinConfig
 * @param [in] 	-device		  : master or slave
 * @param [in] 	-CLK_Phase 	  : Clock Phase ,Sample at first/last edge of clock
 * @param [in] 	-Data_Order   : MSB/LSB transmit first
 * @param [in] 	-SSM 		  : Slave Select management , Specified in master mode
 * @param [in] 	-IRQ_Enable   : Enable interrupt of SPI
 * @param [in] 	-CLK_Rate 	  : control the SCK rate of the device configured as a Master
 * @retval 		-none
 * Note			-ALL Parameter Must be Define From The Reference definition of it to initiate the SPI Correctly
 */
void MCAL_SPI_init(SPI_mode_t device_Mode , uint8_t CLK_Phase , uint8_t Data_Order , uint8_t SSM , uint8_t IRQ_Enable , void (*P_CallBack)(void)  , uint8_t CLK_Rate)
{
	G_Device_Mode = device_Mode ;

	// Clock Phase SPCR Bit 2 – CPHA: Clock Phase
	SPCR |= CLK_Phase ;

	// Clock Rate SPCR Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0
	if ((CLK_Rate == SPI_CLK_Rate_fosc_2) || (CLK_Rate == SPI_CLK_Rate_fosc_8) || (CLK_Rate == SPI_CLK_Rate_fosc_32))
	{
		SPSR |= 1 ;// SPSR Bit 0 – SPI2X: Double SPI Speed Bit
		SPCR |= (CLK_Rate - 4) ;
	}
	else
	{
		SPCR |= CLK_Rate ;
	}

	// Data Order SPCR Bit 5 – DORD: Data Order
	SPCR |= Data_Order ;

	if(device_Mode == master)
	{
		/* Set MOSI and SCK output and SS output, all others input */
		DIO_SetPinDirection(DIO_PORTB, MOSI, DIO_PIN_OUTPUT);
		DIO_SetPinDirection(DIO_PORTB, SCK , DIO_PIN_OUTPUT);
		DIO_SetPinDirection(DIO_PORTB, MISO, DIO_PIN_INPUT );

		if (SSM == SPI_SSM_Master_Input)
		{
			DIO_SetPinDirection(DIO_PORTB, SS  , DIO_PIN_INPUT);
		}
		else
		{
			DIO_SetPinDirection(DIO_PORTB, SS  , DIO_PIN_OUTPUT);
		}

		/* Enable SPI Master Mode */
		SPCR |= (1<<4);

	}
	else if (device_Mode == slave)
	{
		/* Set MOSI , SCK and SS input, MISO output */
		DIO_SetPinDirection(DIO_PORTB, MOSI, DIO_PIN_INPUT );
		DIO_SetPinDirection(DIO_PORTB, SCK , DIO_PIN_INPUT );
		DIO_SetPinDirection(DIO_PORTB, SS  , DIO_PIN_INPUT );
		DIO_SetPinDirection(DIO_PORTB, MISO, DIO_PIN_OUTPUT);

	}

	// IRQ_Enable SPCR  Bit 7 – SPIE: SPI Interrupt Enable
	SPCR |= IRQ_Enable ;
	if(IRQ_Enable == SPI_IRQ_Enable)
		G_P_CallBack = P_CallBack ;

	/* Enable SPI */
	SPCR |= (1<<6);
}
void MCAL_SPI_Transmit(uint8_t *data , uint8_t IRQ_Enable )
{
	/* Start transmission */
	SPDR = *data;

	if(IRQ_Enable == SPI_IRQ_Disable)
	{
		/* Wait for transmission complete */
		while(!(SPSR & (1<<7)));

		/* Return data register */
		*data = SPDR ;
	}

}
void MCAL_SPI_Recieve_Interrupt(uint8_t* data)
{
	/* Return data register */
	*data = SPDR ;
}

/****************************************
 *				ISR
 ****************************************/
// ISR FUNCTION PROTOTYPE FOR SPI

void __vector_12 (void) __attribute__ (( signal ));

void __vector_12(void)
{
	if (G_Device_Mode == master)
	{
		/* when interrupt-driven SPI transmission is used in master mode, and there exists a possibility that SS is driven low,
		 * the interrupt should always check that the MSTR bit is still set.
		 * If the MSTR bit has been cleared by a slave select, it must be set by the user to re-enable SPI master mode.
		 */
		if(GET_BIT(SPCR , 4) == 0)
			SPCR |= (1<<4);
	}

	// CallBack Function
	G_P_CallBack();
}
