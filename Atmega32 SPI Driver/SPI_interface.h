/*
 * SPI_interface.h
 *
 *  Created on: Apr 1, 2024
 *  Author: Abdullah Karkour
 */

#ifndef INC_SPI_INTERFACE_H_
#define INC_SPI_INTERFACE_H_

/****************************************
 * Includes
 ****************************************/
#include <stdint.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL*/
#include "DIO_interface.h"

/****************************************
 * Macros
 ****************************************/
#define SS 		DIO_PIN4
#define MOSI 	DIO_PIN5
#define MISO 	DIO_PIN6
#define SCK 	DIO_PIN7

typedef enum {
	master,
	slave
}SPI_mode_t;

// @ref SPI_CLK_Phase_Define
#define SPI_CLK_Phase_Sample_At_First_Edge			(0x00)
#define SPI_CLK_Phase_Sample_At_Last_Edge			(1<<2)

// @ref SPI_Data_Order_Define
#define SPI_Data_Order_MSB_First					(0x00)
#define SPI_Data_Order_LSB_First					(1<<5)

// @ref SPI_SSM_Define
/*
 * When the SPI is configured as a Slave, the Slave Select (SS) pin is always input
 * When the SPI is configured as a Master, the user can determine the direction of the SS pin.
 * If SS is configured as an output, the pin is a general output pin which does not affect the SPI system. Typically, the pin will be driving the SS pin of the SPI Slave.
 * If SS is configured as an input, it must be held high to ensure Master SPI operation.
   If the SS pin is driven low the SPI system interprets this as another master selecting the SPI as a slave and starting to send data to it.
 */
#define SPI_SSM_Slave_Input				0
#define SPI_SSM_Master_Input			1
#define SPI_SSM_Master_Output			2

// @ref SPI_IRQ_Enable_Define
#define SPI_IRQ_Enable					(1<<7)
#define SPI_IRQ_Disable					(0x00)

// @ref SPI_CLK_Rate_Define
// Normal SPI Speed
#define SPI_CLK_Rate_fosc_4				0
#define SPI_CLK_Rate_fosc_16			1
#define SPI_CLK_Rate_fosc_64			2
#define SPI_CLK_Rate_fosc_128			3
// Double SPI Speed
#define SPI_CLK_Rate_fosc_2				4
#define SPI_CLK_Rate_fosc_8				5
#define SPI_CLK_Rate_fosc_32			6


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
void MCAL_SPI_init(SPI_mode_t device_Mode , uint8_t CLK_Phase , uint8_t Data_Order , uint8_t SSM , uint8_t IRQ_Enable , void (*P_CallBack)(void) , uint8_t CLK_Rate);
void MCAL_SPI_Transmit(uint8_t *data , uint8_t IRQ_Enable );
void MCAL_SPI_Recieve_Interrupt(uint8_t* data);

#endif /* INC_SPI_INTERFACE_H_ */
