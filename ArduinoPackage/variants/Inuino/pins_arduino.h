/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8

//Set SPI and I2C to digital pins
static const uint8_t SS   = 19;
static const uint8_t MOSI = 18;
static const uint8_t MISO = 17;
static const uint8_t SCK  = 16;

static const uint8_t SDA = 14;
static const uint8_t SCL = 15;

//Set LED_BUILTIN to digital pins
#define LED_BUILTIN 13

//Set analog pins to digital pins
static const uint8_t A0 = 31;
static const uint8_t A1 = 30;
static const uint8_t A2 = 29;
static const uint8_t A3 = 28;
static const uint8_t A4 = 27;
static const uint8_t A5 = 26;
static const uint8_t A6 = 25;
static const uint8_t A7 = 24;


//Set analog pins to digital pins, A?=D?
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? 31 - (p) : -1)



//Set which digital pins has pwm(timer)
#if defined(__AVR_ATmega644P__)
#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 19 || (p) == 20)
#elif defined(__AVR_ATmega1284P__)
#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 16 || (p) == 17 || (p) == 19 || (p) == 20)
#endif


// Set digitalPin To PCICR
// p.s. All digitalPin on 644p/1284p has PCICR
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (&PCICR) : ((uint8_t *)0)) 

// Set digitalPin To PCICR bit
// PortD = 3,PortC = 2,PortB = 1,PortA = 0
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 3 : (((p) <= 15) ? 2 : (((p) <= 23) ? 1 : 0)))

// Set digitalPin To PCMSK 
// PortD = &PCMSK3,PortC = &PCMSK2,PortB = &PCMSK1,PortA = &PCMSK0
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK3) : (((p) <= 15) ? (&PCMSK2) : (((p) <= 23) ? (&PCMSK1) : (&PCMSK0))))  


// Set digitalPin To PCMSK bit
// Relative to digital_pin_to_port_PGM and digital_pin_to_bit_mask_PGM
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? ((p) % 8) : (((p) <= 13) ? ( (p) - 6 ) : (((p) <= 15) ? ( 15 - (p)) : (((p)<=23)?( 23 - (p) ):((p) % 8))))) 

//Set which digital pins has interrupt
#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) == 21 ? 2 : NOT_AN_INTERRUPT)))


#ifdef ARDUINO_MAIN


// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PD, //D0
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PC, //D8
	PC,
	PC,
	PC,
	PC,
	PC,
	PC, 
	PC,
	PB, //D16
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PA, //D24,AD7
	PA,
	PA,
	PA,
	PA,
	PA,
	PA,
	PA
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), // D0 , port D0
	_BV(1), // D1 , port D1
	_BV(2), // D2 , port D2
	_BV(3), // D3 , port D3
	_BV(4), // D4 , port D4
	_BV(5), // D5 , port D5
	_BV(6), // D6 , port D6
	_BV(7), // D7 , port D7
	_BV(2), // D8 , port C2
	_BV(3), // D9 , port C3
	_BV(4), // D10, port C4
	_BV(5), // D11, port C5
	_BV(6), // D12, port C6
	_BV(7), // D13, port C7
	_BV(1), // D14, port C1
	_BV(0), // D15, port C0
	_BV(7), // D16, port B7
	_BV(6), // D17, port B6
	_BV(5), // D18, port B5
	_BV(4), // D19, port B4
	_BV(3), // D20, port B3
	_BV(2), // D21, port B2
	_BV(1), // D22, port B1
	_BV(0), // D23, port B0
	_BV(0), // D24 AD7, port A0
	_BV(1), // D25 AD6, port A1
	_BV(2), // D26 AD5, port A2
	_BV(3), // D27 AD4, port A3
	_BV(4), // D28 AD3, port A4
	_BV(5), // D29 AD2, port A5
	_BV(6), // D30 AD1, port A6
	_BV(7)  // D31 AD0, port A7
};



#if defined(__AVR_ATmega644P__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
	NOT_ON_TIMER, 	//D0	 PD0
	NOT_ON_TIMER, 	//D1	 PD1
	NOT_ON_TIMER, 	//D2	 PD2
	NOT_ON_TIMER,   //D3	 PD3
	TIMER1B,		//D4	 PD4
	TIMER1A,	 	//D5	 PD5
	TIMER2B,	 	//D6	 PD6
	TIMER2A,		//D7	 PD7
	
	NOT_ON_TIMER, 	//D8	 PC2
	NOT_ON_TIMER,   //D9	 PC3
	NOT_ON_TIMER,   //D10	 PC4
	NOT_ON_TIMER,	//D11	 PC5
	NOT_ON_TIMER,	//D12	 PC6
	NOT_ON_TIMER,   //D13	 PC7
	NOT_ON_TIMER,  	//D14	 PC1
	NOT_ON_TIMER,  	//D15	 PC0
	
	NOT_ON_TIMER, 	//D16	 PB7
	NOT_ON_TIMER, 	//D17	 PB6
	NOT_ON_TIMER, 	//D18	 PB5
	TIMER0B, 		//D19	 PB4
	TIMER0A,   		//D20	 PB3
	NOT_ON_TIMER,   //D21	 PB2
	NOT_ON_TIMER,   //D22	 PB1
	NOT_ON_TIMER,   //D23	 PB0
	
	NOT_ON_TIMER,   //D24	 PA0
	NOT_ON_TIMER,   //D25	 PA1
	NOT_ON_TIMER,   //D26	 PA2
	NOT_ON_TIMER,   //D27	 PA3
	NOT_ON_TIMER,   //D28	 PA4
	NOT_ON_TIMER,   //D29	 PA5
	NOT_ON_TIMER,   //D30	 PA6
	NOT_ON_TIMER    //D31	 PA7
};

#elif defined(__AVR_ATmega1284P__)

const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
	NOT_ON_TIMER, 	//D0	 PD0
	NOT_ON_TIMER, 	//D1	 PD1
	NOT_ON_TIMER, 	//D2	 PD2
	NOT_ON_TIMER,   //D3	 PD3
	TIMER1B,		//D4	 PD4
	TIMER1A,	 	//D5	 PD5
	TIMER2B,	 	//D6	 PD6
	TIMER2A,		//D7	 PD7
	
	NOT_ON_TIMER, 	//D8	 PC2
	NOT_ON_TIMER,   //D9	 PC3
	NOT_ON_TIMER,   //D10	 PC4
	NOT_ON_TIMER,	//D11	 PC5
	NOT_ON_TIMER,	//D12	 PC6
	NOT_ON_TIMER,   //D13	 PC7
	NOT_ON_TIMER,  	//D14	 PC1
	NOT_ON_TIMER,  	//D15	 PC0
	
	TIMER3B, 		//D16	 PB7
	TIMER3A, 		//D17	 PB6
	NOT_ON_TIMER, 	//D18	 PB5
	TIMER0B, 		//D19	 PB4
	TIMER0A,   		//D20	 PB3
	NOT_ON_TIMER,   //D21	 PB2
	NOT_ON_TIMER,   //D22	 PB1
	NOT_ON_TIMER,   //D23	 PB0
	
	NOT_ON_TIMER,   //D24	 PA0
	NOT_ON_TIMER,   //D25	 PA1
	NOT_ON_TIMER,   //D26	 PA2
	NOT_ON_TIMER,   //D27	 PA3
	NOT_ON_TIMER,   //D28	 PA4
	NOT_ON_TIMER,   //D29	 PA5
	NOT_ON_TIMER,   //D30	 PA6
	NOT_ON_TIMER    //D31	 PA7
};
#endif //Timer define






#endif //Arduino Main

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
