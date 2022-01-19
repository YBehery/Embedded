/*
 * main.c
 *
 *  Created on: 17 Jan 2022
 *      Author: Yusuf
 */

#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"CLCD_interface.h"
#include"CLCD_config.h"
#include"PORT_interface.h"
#include<util/delay.h>
void main()
{

	PORT_VoidInit();
	//char name[]="Behery";
	/*initialize LCD*/
	CLCD_VoidInit();
	u8 pattern[]={0b10001,0b10001,0b10001,0b11111,0b11111,0b00000,0b00110,0b00000};
	u8 pattern1[]={0,0b1,0b1,0b1,0b11111,0,0b01010,0};
	u8 pattern2[]={0,0b01110,0b01010,0b01010,0b01111,0b00100,0b01000,0};
	u8 pattern3[]={0,0b10101,0b10101,0b10101,0b11111,0,0,0};
	u8 pattern4[]={0b00010,0,0b10111,0b10101,0b11111,0,0,0};
	DIO_u8SetPortValue(DIO_u8PORTB,DIO_u8HIGH);
	//DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8OUTPUT);
	u8 test;
	//CLCD_VoidShowNum(1998);
/*while(1)
{
	DIO_u8GetPortValue(DIO_u8PORTB,&test);
	CLCD_VoidShowNum(test);
	_delay_ms(500);
	CLCD_VoidReset_Display();
}*/
	//CLCD_VoidWriteSpecialChar(pattern1,0,0,1);
	//CLCD_VoidSendData('1');
	u8 i=0;
	while(1)
	{
		for (u8 j=0;j<=15;j++)//15 number of visible window on CLCD
		{
			CLCD_VoidWriteSpecialChar(pattern1,0,i,15-j);
			CLCD_VoidWriteSpecialChar(pattern2,1,i,15-j-1);
			CLCD_VoidWriteSpecialChar(pattern3,2,i,15-j-2);
			CLCD_VoidWriteSpecialChar(pattern4,3,i,15-j-3);
			i=!i;
			_delay_ms(500);
			CLCD_VoidReset_Display();
		}
	//	i=!i;
	//	_delay_ms(500);
	//	CLCD_VoidReset_Display();
	}
	//CLCD_VoidSendData('2');
	//CLCD_VoidSendData('3');
	//CLCD_VoidSendData('4');
	//CLCD_VoidSendData('5');
	//CLCD_VoidWriteSpecialChar(pattern,0,0,3);
	//CLCD_VoidSendData('6');
	//CLCD_VoidSendData('7');
	//CLCD_VoidGoToXY(1,15);
	//CLCD_VoidSendString(name);
	while(1)
	{

	}

}
