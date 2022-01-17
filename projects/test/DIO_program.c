/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	DIO				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
/**************************************************************************/
/***************setting direction of PIN***********************************/
/**************************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	if (Copy_u8Port<=PORTD&&Copy_u8Pin<=PIN_7)
	{
			if(Copy_u8Direction==INPUT)//if direction is input clear bits
			{
				switch(Copy_u8Port)
				{
					case PORTA:
						CLR_BIT(DDRA_reg,Copy_u8Pin);
						break;
					case PORTB:
						CLR_BIT(DDRB_reg,Copy_u8Pin);
						break;
					case PORTC:
						CLR_BIT(DDRC_reg,Copy_u8Pin);
						break;
					case PORTD:
						CLR_BIT(DDRD_reg,Copy_u8Pin);
				}
			}
			else if(Copy_u8Direction==OUTPUT)//if direction is output set bits to one
			{


				switch(Copy_u8Port)
				{
					case PORTA:
					SET_BIT(DDRA_reg,Copy_u8Pin);
					break;
					case PORTB:
					SET_BIT(DDRB_reg,Copy_u8Pin);
					break;
					case PORTC:
					SET_BIT(DDRC_reg,Copy_u8Pin);
					break;
					case PORTD:
					SET_BIT(DDRD_reg,Copy_u8Pin);
				}
			}
			else//direction is neither input or output return 0
			return 0;//error
		return 1;//no error
	}
	else
		return 0;//error 
}

/***************************************************************************/
/***************setting direction of PORT***********************************/
/***************************************************************************/

u8 DIO_u8SetPortDirection(u8 Copy_u8Port ,u8 Copy_u8Direction)
{
	if(Copy_u8Port<=PORTD)
	{
		if(Copy_u8Direction==INPUT)
		{
			switch (Copy_u8Port)
			{	
				case PORTA:
				for(u8 i=0 ; i<=7 ; i++)//clearing all bits in the port
				{
					CLR_BIT(DDRA_reg,i);
				}
				break;
				
				case PORTB:
				for(u8 i=0 ; i<=7 ; i++)//clearing all bits in the port
				{
					CLR_BIT(DDRB_reg,i);
				}
				break;
				
				case PORTC:
				for(u8 i=0 ; i<=7 ; i++)//clearing all bits in the port
				{
					CLR_BIT(DDRC_reg,i);
				}
				break;
				
				case PORTD:
				for(u8 i=0 ; i<=7 ; i++)//clearing all bits in the port
				{
					CLR_BIT(DDRD_reg,i);
				}
			}
		}	
		else if(Copy_u8Direction==OUTPUT)
		{
			switch (Copy_u8Port)
			{	
				case PORTA:

				for(u8 i=0 ; i<=7 ; i++)//setting all bits in the port
				{
					SET_BIT(DDRA_reg,i);

				}
				break;
				
				case PORTB:
				for(u8 i=0 ; i<=7 ; i++)//setting all bits in the port
				{
					SET_BIT(DDRB_reg,i);
				}
				break;
				
				case PORTC:
				for(u8 i=0 ; i<=7 ; i++)//setting all bits in the port
				{
					SET_BIT(DDRC_reg,i);
				}
				break;
				
				case PORTD:
				for(u8 i=0 ; i<=7 ; i++)//setting all bits in the port
				{
					SET_BIT(DDRD_reg,i);
				}
			}
		}
		else 		//incorrect direction
			return 0;	 //error incorrect input
			
		return 1;//correct input
	}
	else
		return 0;//error
}

/******************************************************************************/
/***********************Setting pin value**************************************/
/******************************************************************************/

u8 DIO_u8SetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	if(Copy_u8Port<=PORTD&&Copy_u8Pin<=PIN_7)
	{
		if (Copy_u8Value)//if value is 1 SET the required PIN
		{
			switch(Copy_u8Port)
			{
				case PORTA:
				SET_BIT(PORTA_reg,Copy_u8Pin);
				break;
				
				case PORTB:
				SET_BIT(PORTB_reg,Copy_u8Pin);
				break;
				
				case PORTC:
				SET_BIT(PORTC_reg,Copy_u8Pin);
				break;
				
				case PORTD:
				SET_BIT(PORTD_reg,Copy_u8Pin);
			}
		}
		else//value is 0 so we clear the bits
		{
			switch(Copy_u8Port)
			{
				case PORTA:
				CLR_BIT(PORTA_reg,Copy_u8Pin);
				break;
				
				case PORTB:
				CLR_BIT(PORTB_reg,Copy_u8Pin);
				break;
				
				case PORTC:
				CLR_BIT(PORTC_reg,Copy_u8Pin);
				break;
				
				case PORTD:
				CLR_BIT(PORTD_reg,Copy_u8Pin);
			}
		}
		
		return 1; //correct
	}
	else
		return 0;	//incorrect input
}
/******************************************************************************/
/***********************Setting port value*************************************/
/******************************************************************************/

u8 DIO_u8SetPortValue(u8 Copy_u8Port ,u8 Copy_u8Value)
{
	if(Copy_u8Port<=PORTD)
	{
			switch(Copy_u8Port)
			{
				case PORTA:
					PORTA_reg=Copy_u8Value;
					break;
				case PORTB:
					PORTB_reg=Copy_u8Value;
					break;
				case PORTC:
					PORTC_reg=Copy_u8Value;
					break;
				case PORTD:
					PORTD_reg=Copy_u8Value;

			}
		return 1;//correct input
	}
	else
		return 0;//incorrect input
}
/******************************************************************************/
/***********************Getting PIN value*************************************/
/******************************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin,u8* Copy_pu8Value)
{
	if(Copy_u8Port<=PORTD&&Copy_u8Pin<=PIN_7)
	{
		switch(Copy_u8Port)
		{
			case PORTA:
			*Copy_pu8Value=GET_BIT(PINA_reg,Copy_u8Pin);
			break;
			
			case PORTB:
			*Copy_pu8Value=GET_BIT(PINB_reg,Copy_u8Pin);
			break;
			
			case PORTC:
			*Copy_pu8Value=GET_BIT(PINC_reg,Copy_u8Pin);
			break;
			
			case PORTD:
			*Copy_pu8Value=GET_BIT(PIND_reg,Copy_u8Pin);
		}
		return 1;
	}
	else
		return 0;
}
