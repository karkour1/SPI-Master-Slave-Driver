 /*
 * ATMEGA32_REG.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Hello
 */

#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

#include <stdint.h>
                      /* DIO REGISTER */

/* DATA DIRCTION REGISTERS */

#define DDRA  (*(volatile uint8_t*)0x3A)
#define DDRB  (*(volatile uint8_t*)0x37)
#define DDRC  (*(volatile uint8_t*)0x34)
#define DDRD  (*(volatile uint8_t*)0x31)

/* OUTPUT REGISTER */

#define PORTA  (*(volatile uint8_t*)0x3B)
#define PORTB  (*(volatile uint8_t*)0x38)
#define PORTC  (*(volatile uint8_t*)0x35)
#define PORTD  (*(volatile uint8_t*)0x32)

/* INPUT REGISTER */

#define PINA  (*(volatile uint8_t*)0x39)
#define PINB  (*(volatile uint8_t*)0x36)
#define PINC  (*(volatile uint8_t*)0x33)
#define PIND  (*(volatile uint8_t*)0x30)

/* EXTERNAL INTERRUPT REGISTERS */

// MCU CONTROL REGISTER
# define MCUCR   (*(volatile uint8_t* ) 0x55 )

// MCU CONTROL AND STATUS REGISTER
# define MCUCSR  (*(volatile uint8_t* ) 0x54 )

// GENERAL INTERRUPT CONTROL REGISTER
# define GICR    (*(volatile uint8_t* ) 0x5B )

// GENERAL INTERRUPT FLAG REGISTER
# define GIFR    (*(volatile uint8_t* ) 0x5A )

// STATUS REGISTER
# define SREG    (*(volatile uint8_t* ) 0x5F )


/* ADC REGISTERS */


// ADC Multiplexer selection Register
#define  ADMUX   (*(volatile uint8_t* ) 0x27 )

// ADC Control and Status Register A
#define  ADCSRA   (*(volatile uint8_t* ) 0x26 )

// The ADC Data Registers
#define  ADCL     (*(volatile uint8_t* ) 0x24 )
#define  ADCH     (*(volatile uint8_t* ) 0x25 )
#define  ADC_U16   (*(volatile uint16_t*) 0x24 )

// Special FunctionsIO  Register
#define  SFIOR    (*(volatile uint8_t* ) 0x50 )


/* TIMRS REGISTERS */


/* TIMER0 */

/*Timer/Counter0 Control Register*/
#define  TCCR0     (*(volatile uint8_t* ) 0x53 )

/*Timer/Counter Register*/
#define  TCNT0     (*(volatile uint8_t* ) 0x52 )

/*Timer/Counter0 Output Compare Register*/
#define  OCR0      (*(volatile uint8_t* ) 0x5C )

/*Timer/Counter  Interrupt Mask Register*/
#define  TIMSK     (*(volatile uint8_t* ) 0x59 )

/*Timer/Counter Interrupt Flag Register*/
#define  TIFR      (*(volatile uint8_t* ) 0x58 )

/* TIMER1 */

/*Timer/Counter1 Control Register A */
#define  TCCR1A     (*(volatile uint8_t* ) 0x4F )

/*Timer/Counter1 Control Register B */
#define  TCCR1B    (*(volatile uint8_t* ) 0x4E )

// Timer/Counter1
#define  TCNT1L     (*(volatile uint8_t* ) 0x4C )
#define  TCNT1H     (*(volatile uint8_t* ) 0x4D )
#define  TCNT1_U16  (*(volatile uint16_t*) 0x4C )

// OUTPUT COMPARE REGISTER 1 A
#define  OCR1AL     (*(volatile uint8_t* ) 0x4A )
#define  OCR1AH     (*(volatile uint8_t* ) 0x4B )
#define  OCR1A_U16  (*(volatile uint16_t*) 0x4A )

// OUTPUT COMPARE REGISTER 1 B
#define  OCR1BL     	  (*(volatile uint8_t* ) 0x48 )
#define  OCR1BH    		  (*(volatile uint8_t* ) 0x49 )
#define  OCR1B_U16   	  (*(volatile uint16_t*) 0x48 )

// INPUT CAPTURE REGISTER 1
#define  ICR1L     (*(volatile uint8_t* ) 0x46 )
#define  ICR1H     (*(volatile uint8_t* ) 0x47 )
#define  ICR1_U16  (*(volatile uint16_t*) 0x46 )

/* WDT */

// Watchdog Timer Control Register
#define  WDTCR     (*(volatile uint8_t* ) 0x41 )


/* USART REGISTERS */

// USART I/O Data Register
# define UDR   (*(volatile uint8_t* ) 0x2C )

// USART Control and Status Register A
# define UCSRA  (*(volatile uint8_t* ) 0x2B )

// USART Control and Status Register B
# define UCSRB    (*(volatile uint8_t* ) 0x2A )

// USART Control and Status Register C
# define UCSRC    (*(volatile uint8_t* ) 0x40 )

// USART Baud Rate Registers
# define UBRRL    (*(volatile uint8_t* ) 0x29 )
# define UBRRH    (*(volatile uint8_t* ) 0x40 )

/* SPI REGISTERS */

//SPI Data Register – SPDR
# define SPDR    (*(volatile uint8_t* ) 0x2F )
//SPI Status Register – SPSR
# define SPSR    (*(volatile uint8_t* ) 0x2E )
//SPI Control Register – SPCR
# define SPCR    (*(volatile uint8_t* ) 0x2D )

/* Generic Macros */
#define GI_Enable			(SREG|= (1<<7))
#define GI_Disable 			(SREG&= ~(1<<7))
#endif /* ATMEGA32_REG_H_ */
