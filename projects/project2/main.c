/*
 * main.c
 *
 *  Created on: 14 Jan 2022
 *      Author: Yusuf
 */

#include<avr/io.h>
#include<util/delay.h>
void main()
{
	DDRA=1;
	while(1)
	{
		PORTA=1;
		_delay_ms(1000);
		//PORTA=0;
		_delay_ms(1000);
	}
}
