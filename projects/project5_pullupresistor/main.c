/*
 * main.c

 *
 *  Created on: 14 Jan 2022
 *      Author: Yusuf
 */
#include "avr/delay.h"
#include "typedefs.h"

#include"DIO_Int.h"
//#include<avr/io.h>

void main()
{

	DIO_SetPinDir(PORTD,7,INPUT);//make input
	DIO_SetPinDir(PORTD,0,OUTPUT);
	DIO_SetPinVal(PORTD,7,HIGH);//make pin7 internal pull up
	while(1)
	{
		if ( DIO_GetPinVal(PORTD, 7))
		{
			DIO_SetPinVal(PORTD,0,HIGH);
		}
		else
			{DIO_SetPinVal(PORTD,0,LOW);}

		/*if(((PORTB) >> (0)) & 0x01)
			(PORTB) |=  (1 << (1));
		else
			(PORTB) &= ~(1 << (1));*/
		//PORTD=PORTB;
	}
}

