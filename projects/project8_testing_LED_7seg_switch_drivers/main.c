/*
 * main.c
 *
 *  Created on: 16 Jan 2022
 *      Author: Yusuf
 */
////////////////////////////////////////////////////////////////////////
//////////////////////////////testing done V1.00////////////////////////
////////////////////////////////////////////////////////////////////////
#include"STD_TYPES.h"

#include "LED_interface.h"
#include "DIO_interface.h"
#include "SWITCH_interface.h"
#include "SSD_interface.h"
#include <util/delay.h>
void main()
{
	u8 switch_state;
	LED_t L1={DIO_u8PORTC,DIO_u8PIN_3,LED_u8ConnSource};
	SW_t SW1={DIO_u8PORTC,DIO_u8PIN_7,SW_u8Temporary,SW_u8Pullup};
	SSD_t SSD1={DIO_u8PORTA,SSD_u8CommonAnode,DIO_u8PORTC,DIO_u8PIN_0};
	while(1)
	{
		SW_u8GetState(&SW1, &switch_state);
		if(switch_state==0)
		{
			for(u8 i=0;i<=9;i++)
			{
				SSD_u8ShowNumber(&SSD1,i);
				_delay_ms(500);
			}
			LED_u8TurnON(&L1);
			_delay_ms(100);
			LED_u8TurnOFF(&L1);
			_delay_ms(100);
		}
		else
			SSD_u8Shutdown(&SSD1);
	}
}
