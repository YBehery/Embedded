/*
 * main.c

 *
 *  Created on: 15 Jan 2022
 *      Author: Yusuf
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
//#include<avr/io.h>
#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
void main()
{
	u8 x;
	DIO_u8SetPortDirection(PORTA,OUTPUT);
	//DDRA=0xff;
	*((volatile u8*)0x3a) =0xff;
	DIO_u8SetPinDirection(PORTC,PIN_3,OUTPUT);
	DIO_u8SetPinDirection(PORTC,PIN_4,OUTPUT);
	//*((volatile u8*)0x34) =0b1000;
	//SET_BIT(*((volatile u8*)0x34),PIN_3);
	DIO_u8SetPinDirection(PORTC,PIN_7,INPUT);
	DIO_u8SetPinValue(PORTC,PIN_7,HIGH);
	//DDRA=0xff;
	//DDRC=0xff;
	while(1)
	{
		DIO_u8GetPinValue(PORTC,PIN_7,&x);
		DIO_u8SetPinValue(PORTC,PIN_4,x);
		//PORTA=0;
		//PORTC=0b1000;
		//*((volatile u8*)0x3b) =0xff;
		//*((volatile u8*)0x35) =0b1000;
		DIO_u8SetPortValue(PORTA,0b10100000);
		//DIO_u8SetPinValue(PORTC,PIN_3,HIGH);
		//DIO_u8SetPortValue(3,LOW);
	}
}
