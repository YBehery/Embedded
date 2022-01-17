/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	HAL				**********************/
/**************		SWC:	LED				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"

/*****************************************************************/
/**************************TURN ON********************************/
/*****************************************************************/
u8 LED_u8TurnON(LED_t *ptrStructLEDn)
{
	u8 Local_u8ErrorState=0;
	
	if((ptrStructLEDn->LED_u8Pin)<=DIO_u8PIN_7)
	{
		if((ptrStructLEDn->LED_u8Conn)==LED_u8ConnSource)
		{	switch(ptrStructLEDn->LED_u8Port)
			{
				case DIO_u8PORTA:
				DIO_u8SetPinDirection(DIO_u8PORTA,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTA,(ptrStructLEDn->LED_u8Pin),DIO_u8HIGH);
				break;
				
				case DIO_u8PORTB:
				DIO_u8SetPinDirection(DIO_u8PORTB,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTB,(ptrStructLEDn->LED_u8Pin),DIO_u8HIGH);
				break;
				
				case DIO_u8PORTC:
				DIO_u8SetPinDirection(DIO_u8PORTC,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTC,(ptrStructLEDn->LED_u8Pin),DIO_u8HIGH);
				break;
				
				case DIO_u8PORTD:
				DIO_u8SetPinDirection(DIO_u8PORTD,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTD,(ptrStructLEDn->LED_u8Pin),DIO_u8HIGH);
				break;
				
				default://Port argument error
				Local_u8ErrorState=1;
			}
		}
		else if((ptrStructLEDn->LED_u8Conn)==LED_u8ConnSink)
		{
			switch(ptrStructLEDn->LED_u8Port)
			{
				case DIO_u8PORTA:
				DIO_u8SetPinDirection(DIO_u8PORTA,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTA,(ptrStructLEDn->LED_u8Pin),DIO_u8LOW);
				break;
				
				case DIO_u8PORTB:
				DIO_u8SetPinDirection(DIO_u8PORTB,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTB,(ptrStructLEDn->LED_u8Pin),DIO_u8LOW);
				break;
				
				case DIO_u8PORTC:
				DIO_u8SetPinDirection(DIO_u8PORTC,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTC,(ptrStructLEDn->LED_u8Pin),DIO_u8LOW);
				break;
				
				case DIO_u8PORTD:
				DIO_u8SetPinDirection(DIO_u8PORTD,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTD,(ptrStructLEDn->LED_u8Pin),DIO_u8LOW);
				break;
				
				default://Port argument error
				Local_u8ErrorState=1;
			}
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;//input argument error
	}
	
	return Local_u8ErrorState;
}

/*****************************************************************/
/**************************TURN OFF*******************************/
/*****************************************************************/
u8 LED_u8TurnOFF(LED_t *ptrStructLEDn)
{
	u8 Local_u8ErrorState=0;
	
	if((ptrStructLEDn->LED_u8Pin)<=DIO_u8PIN_7)
	{
		if((ptrStructLEDn->LED_u8Conn)==LED_u8ConnSource)
		{	switch(ptrStructLEDn->LED_u8Port)
			{
				case DIO_u8PORTA:
				DIO_u8SetPinDirection(DIO_u8PORTA,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTA,(ptrStructLEDn->LED_u8Pin),DIO_u8LOW);
				break;
				
				case DIO_u8PORTB:
				DIO_u8SetPinDirection(DIO_u8PORTB,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTB,(ptrStructLEDn->LED_u8Pin),DIO_u8LOW);
				break;
				
				case DIO_u8PORTC:
				DIO_u8SetPinDirection(DIO_u8PORTC,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTC,(ptrStructLEDn->LED_u8Pin),DIO_u8LOW);
				break;
				
				case DIO_u8PORTD:
				DIO_u8SetPinDirection(DIO_u8PORTD,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTD,(ptrStructLEDn->LED_u8Pin),DIO_u8LOW);
				break;
				
				default://Port argument error
				Local_u8ErrorState=1;
			}
		}
		else if((ptrStructLEDn->LED_u8Conn)==LED_u8ConnSink)
		{
			switch(ptrStructLEDn->LED_u8Port)
			{
				case DIO_u8PORTA:
				DIO_u8SetPinDirection(DIO_u8PORTA,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTA,(ptrStructLEDn->LED_u8Pin),DIO_u8HIGH);
				break;
				
				case DIO_u8PORTB:
				DIO_u8SetPinDirection(DIO_u8PORTB,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTB,(ptrStructLEDn->LED_u8Pin),DIO_u8HIGH);
				break;
				
				case DIO_u8PORTC:
				DIO_u8SetPinDirection(DIO_u8PORTC,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTC,(ptrStructLEDn->LED_u8Pin),DIO_u8HIGH);
				break;
				
				case DIO_u8PORTD:
				DIO_u8SetPinDirection(DIO_u8PORTD,(ptrStructLEDn->LED_u8Pin),DIO_u8OUTPUT);//set PIN to output
				DIO_u8SetPinValue(DIO_u8PORTD,(ptrStructLEDn->LED_u8Pin),DIO_u8HIGH);
				break;
				
				default://Port argument error
				Local_u8ErrorState=1;
			}
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;//input argument error
	}
	
	return Local_u8ErrorState;	
}
