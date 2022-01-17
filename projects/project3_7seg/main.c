/*
  * main.c
 *
 *  Created on: 14 Jan 2022
 *      Author: Yusuf
 */

#include<avr/io.h>
#include<util/delay.h>
typedef unsigned char u8;
void main()
{
	DDRA=0xff;
	u8 num_7_seg[]={0b10100000,0b11111001,0b11000100,0b11010000,0b10011001,0b10010010,0b10000011,0b11111000,0b10000000,0b10011000};
	//array used for common anode least sig bit connected to top pin
	while(1)
	{
		for(u8 i=0;i<10;i++)
		{
			PORTA=num_7_seg[i];
			_delay_ms(1000);
		}
	}
}
