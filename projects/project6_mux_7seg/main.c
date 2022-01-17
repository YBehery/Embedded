/*
 * main.c
 *
 *  Created on: 15 Jan 2022
 *      Author: Yusuf
 */
//#include<avr/io.h>

#include <util/delay.h>
#include "typedefs.h"

#include"DIO_Int.h"
void main()
{
	/*u8 num_7_seg[]={0b10100000,0b11111001,0b11000100,0b11010000,0b10011001,0b10010010,0b10000011,0b11111000,0b10000000,0b10011000};
	DDRA=0xff;//both 7 segs connected to PORTA
	DDRB=0b11;//bit 0 is common anode for the right 7 seg and bit 1 is common anode for left 7 seg
	while(1)
	{
		for(u8 i=9;i>=0;i--)
		{
			PORTB=0b01;
			PORTA=num_7_seg[i];//count down
			_delay_ms(10);
			PORTB=0b10;
			PORTA=num_7_seg[9-i];//count up
			_delay_ms(10);
		}
	}*/
	u8 num_7_seg[]={0b10100000,0b11111001,0b11000100,0b11010000,0b10011001,0b10010010,0b10000011,0b11111000,0b10000000,0b10011000};
	DIO_SetPortDir(PORTD,0xff);
	//DDRD=0xff;
	DIO_SetPortDir(PORTA,0xff);
    //DDRA=0xff;

	//DDRC=0b00;//first 2 pins in port C input
	//PORTC=0b11;//internal pullup
	//start at number 50
	//PORTA=num_7_seg[0];
	//PORTD=num_7_seg[5];
	//first 2 pins in port C input/////
	DIO_SetPinDir(PORTC,0,INPUT);
	DIO_SetPinDir(PORTC,1,INPUT);
	//internal pullup///////////
	DIO_SetPinVal(PORTC,0,HIGH);
	DIO_SetPinVal(PORTC,1,HIGH);
	//start at number 50///////////
	DIO_SetPortVal(PORTA,num_7_seg[0]);
	DIO_SetPortVal(PORTD,num_7_seg[5]);

	u8 counter1=0;//counter defined so that if 8 iterations are done while pressing the button the increase speed is increases after 8 iterations it will be 2 secs
	u8 counter2=0;
	u8 start=50;//starting number is 50
	while(1)
	{
		if(!(DIO_GetPinVal(PORTC,1)))//if low then decrease number (we can't check on high as pin is internally pulled up)
					{
						counter1=0;//reset other counter
						counter2++;
						start--;
						DIO_SetPortVal(PORTA,num_7_seg[start%10]);
						DIO_SetPortVal(PORTD,num_7_seg[start/10]);
						if(counter2>=2)
								{
									_delay_ms(250);//minimum delay for debouncing( max decrease speed)
								}
								else
								{
									_delay_ms(1000);//slow decrease
								}
					}
		if(!(DIO_GetPinVal(PORTC,0)))//if low then increase number (we can't check on high as pin is internally pulled up)
		{
			counter2=0;//reset other counter
			counter1++;
			start++;
			DIO_SetPortVal(PORTA,num_7_seg[start%10]);
			DIO_SetPortVal(PORTD,num_7_seg[start/10]);
			//if counter1 is more than 2(2 secs) we get fast increase
			if(counter1>=2)
			{
				_delay_ms(250);//minimum delay for debouncing
			}
			else
			{
				_delay_ms(1000);//slow increase
			}
		}
	}
}
