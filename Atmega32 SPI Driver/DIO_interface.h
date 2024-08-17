/*
 * DIO_interface.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Hello
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

                                 /*****           PIN MACROS           *****/
#define  DIO_PIN0    0
#define  DIO_PIN1    1
#define  DIO_PIN2    2
#define  DIO_PIN3    3
#define  DIO_PIN4    4
#define  DIO_PIN5    5
#define  DIO_PIN6    6
#define  DIO_PIN7    7

#define DIO_PIN_OUTPUT  1
#define DIO_PIN_INPUT   0

#define DIO_PIN_HIGH    1
#define DIO_PIN_LOW     0

#define  DIO_PORTA   0
#define  DIO_PORTB   1
#define  DIO_PORTC   2
#define  DIO_PORTD   3

                                 /*****           PORT MACROS           *****/

#define DIO_Port_OUTPUT  0xff
#define DIO_Port_INPUT   0x00

#define DIO_PORT_HIGH    0xff
#define DIO_PORT_LOW     0x00


                                 /*****            APIS            *****/

      /* PIN APIS */
void DIO_SetPinDirection      (U8 PortId , U8 PinId , U8 PinDirection);
void DIO_SetPinValue          (U8 PortId , U8 PinId , U8 PinValue);
void DIO_GetPinValue          (U8 PortId , U8 PinId , U8* PinValue);
void DIO_TogglePinValue       (U8 PortId , U8 PinId);
void DIO_SetInputPinResistance(U8 PortId , U8 PinId);

      /* PPORT APIS*/

void DIO_SetPortDirection      (U8 PortId ,  U8 PortDirection);
void DIO_SetPortValue          (U8 PortId ,  U8 PortValue);
void DIO_GetPortValue          (U8 PortId , U8* PortValue);
void DIO_TogglePortValue       (U8 PortId );
void DIO_SetInputPortResistance(U8 PortId );

#endif /* DIO_INTERFACE_H_ */
