/*
 * main.c
 *
 *  Created on: 16 Jan 2022
 *      Author: Yusuf
 */
/**************************************************************/
/*****************DIO_Version_1.1 tested successfully**********/
/**************************************************************/
#include"STD_TYPES.h"
#include"DIO_interface.h"
void main()
{
	u8 test;
	DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN_3,DIO_u8OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN_4,DIO_u8OUTPUT);

	DIO_u8SetPinDirection(DIO_u8PORTC,DIO_u8PIN_7,DIO_u8INPUT);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_7,DIO_u8HIGH);
	while(1)
	{
		DIO_u8SetPortValue(DIO_u8PORTA,0b10100000);

		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_3,DIO_u8HIGH);


		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN_7,&test);

		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN_4,test);
	}
}
