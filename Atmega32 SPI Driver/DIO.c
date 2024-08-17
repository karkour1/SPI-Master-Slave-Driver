/*
 * DIO.c
 *
 *  Created on: Mar 1, 2023
 *      Author: Hello
 */

  /* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL*/
#include "DIO_interface.h"

                                 /*****            APIS            *****/

  /* PIN APIS */
void DIO_SetPinDirection (U8 PortId , U8 PinId , U8 PinDirection)
{
	if ((PortId <= 3) && (PinId <= 7) && ((PinDirection == DIO_PIN_OUTPUT) || (PinDirection == DIO_PIN_INPUT)))
	{
		 switch(PortId)
		 {

		 case 0 :
			 if(PinDirection == DIO_PIN_OUTPUT)
			 {
			     SET_BIT(DDRA, PinId);
			 }
			 else
			 {
				 CLEAR_BIT(DDRA , PinId);
			 }
			 break;
		 case 1 :
			 if(PinDirection == DIO_PIN_OUTPUT)
			 {
			     SET_BIT(DDRB, PinId);
			 }
			 else
			 {
				 CLEAR_BIT(DDRB , PinId);
			 }
			 break;
		 case 2 :
			 if(PinDirection == DIO_PIN_OUTPUT)
			 {
			     SET_BIT(DDRC, PinId);
			 }
			 else
			 {
				 CLEAR_BIT(DDRC , PinId);
			 }
			 break;
		 case 3 :
			 if(PinDirection == DIO_PIN_OUTPUT)
			 {
			     SET_BIT(DDRD, PinId);
			 }
			 else
			 {
				 CLEAR_BIT(DDRD , PinId);
			 }
			 break;
		 }
	}

}
void DIO_SetPinValue     (U8 PortId , U8 PinId , U8 PinValue)
{
	if ((PortId <= 3) && (PinId <= 7) && ((PinValue == 1) || (PinValue == 0)))
		{
			 switch(PortId)
			 {

			 case 0 :
				 if(PinValue == DIO_PIN_HIGH)
				 {
				     SET_BIT(PORTA, PinId);
				 }
				 else
				 {
					 CLEAR_BIT(DDRA , PinId);
				 }
				 break;
			 case 1 :
				 if(PinValue == DIO_PIN_HIGH)
				 {
				     SET_BIT(PORTB, PinId);
				 }
				 else
				 {
					 CLEAR_BIT(PORTB , PinId);
				 }
				 break;
			 case 2 :
				 if(PinValue == DIO_PIN_HIGH)
				 {
				     SET_BIT(PORTC, PinId);
				 }
				 else
				 {
					 CLEAR_BIT(PORTC , PinId);
				 }
				 break;
			 case 3 :
				 if(PinValue == DIO_PIN_HIGH)
				 {
				     SET_BIT(PORTD, PinId);
				 }
				 else
				 {
					 CLEAR_BIT(PORTD , PinId);
				 }
				 break;
			 }
		}

}
void DIO_GetPinValue     (U8 PortId , U8 PinId , U8* PinValue)
{
	if ((PortId <= 3) && (PinId <= 7) )
		{
			 switch(PortId)
			 {

			 case 0 :
				 if(GET_BIT(PINA , PinId) == DIO_PIN_HIGH)
				 {
				     *PinValue = DIO_PIN_HIGH;
				 }
				 else
				 {
					 *PinValue = DIO_PIN_LOW;
				 }
				 break;
			 case 1 :
				 if(GET_BIT(PINB , PinId) == DIO_PIN_HIGH)
				 {
				     *PinValue = DIO_PIN_HIGH;
				 }
				 else
				 {
					 *PinValue = DIO_PIN_LOW;
				 }
				 break;
			 case 2 :
				 if(GET_BIT(PINC , PinId) == DIO_PIN_HIGH)
				 {
				     *PinValue = DIO_PIN_HIGH;
				 }
				 else
				 {
					 *PinValue = DIO_PIN_LOW;
				 }
				 break;
			 case 3 :
				 if(GET_BIT(PIND , PinId) == DIO_PIN_HIGH)
				 {
				     *PinValue = DIO_PIN_HIGH;
				 }
				 else
				 {
					 *PinValue = DIO_PIN_LOW;
				 }
				 break;
			 }
		}

}
void DIO_TogglePinValue  (U8 PortId , U8 PinId)
{
	if ((PortId <= 3) && (PinId <= 7) )
		{
			 switch(PortId)
			 {

			 case 0 :
				 TOG_BIT(PORTA , PinId);
				 break;
			 case 1 :
				 TOG_BIT(PORTB , PinId);
				 break;
			 case 2 :
				 TOG_BIT(PORTC , PinId);
				 break;
			 case 3 :
				 TOG_BIT(PORTD , PinId);
				 break;
			 }
		}



}
void DIO_SetInputPinResistance(U8 PortId , U8 PinId)
{
	if ((PortId <= 3) && (PinId <= 7) )
			{
				 switch(PortId)
				 {

				 case 0 :
					 SET_BIT(PORTA , PinId);
					 break;
				 case 1 :
					 SET_BIT(PORTB , PinId);
					 break;
				 case 2 :
					 SET_BIT(PORTC , PinId);
					 break;
				 case 3 :
					 SET_BIT(PORTD , PinId);
					 break;
				 }
			}
}
  /* PORT APIS */

void DIO_SetPortDirection (U8 PortId ,  U8 PortDirection)
{
	if ((PortId <= 3) && ((PortDirection == DIO_Port_OUTPUT)|| (PortDirection == DIO_Port_INPUT)))
	{
		switch(PortId)
	 {
		case 0 :
			if (PortDirection == DIO_Port_OUTPUT)
			{
				DDRA = 0xff ;
			}
			else
			{
				DDRA = 0x00 ;
			}

			break;
		case 1 :
			if (PortDirection == DIO_Port_OUTPUT)
			{
				DDRB = 0xff ;
			}
			else
			{
				DDRB = 0x00 ;
			}

			break;
		case 2 :
			if (PortDirection == DIO_Port_OUTPUT)
			{
				DDRC = 0xff ;
			}
			else
			{
				DDRC = 0x00 ;
			}

			break;
		case 3 :
			if (PortDirection == DIO_Port_OUTPUT)
			{
				DDRD = 0xff ;
			}
			else
			{
				DDRD = 0x00 ;
			}

			break;
	 }
	}
}
void DIO_SetPortValue     (U8 PortId ,  U8 PortValue)
{
	if ((PortId <= 3))
		{
			switch(PortId)
		 {
			case 0 :
				PORTA = PortValue ;
				break;
			case 1 :
				PORTB = PortValue ;
				break;
			case 2 :
				PORTC = PortValue ;
				break;
			case 3 :
				PORTB = PortValue ;
				break;
		 }
		}
}
void DIO_GetPortValue     (U8 PortId , U8* PortValue)
{
	if ((PortId <= 3) )
			{
				switch(PortId)
			 {
				case 0 :
					*PortValue = PINA ;
					break;
				case 1 :
					*PortValue = PINB ;
					break;
				case 2 :
					*PortValue = PINC ;
					break;
				case 3 :
					*PortValue = PIND ;
					break;
			 }
			}
}
void DIO_TogglePortValue  (U8 PortId )
{
	if ((PortId <= 3) )
				{
					switch(PortId)
				 {
					case 0 :
						PORTA = ~PORTA ;
						break;
					case 1 :
						PORTB = ~PORTB ;
						break;
					case 2 :
						PORTC = ~PORTC ;
						break;
					case 3 :
						PORTD = ~PORTD ;
						break;
				 }
				}
}
void DIO_SetInputPortResistance(U8 PortId )
{
	if ((PortId <= 3) )
				{
					switch(PortId)
				 {
					case 0 :
						PORTA = 0xff ;
						break;
					case 1 :
						PORTB = 0xff ;
						break;
					case 2 :
						PORTC = 0xff ;
						break;
					case 3 :
						PORTD = 0xff ;
						break;
				 }
				}
}
