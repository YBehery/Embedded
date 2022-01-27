/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	ADC				**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

//Prescaler
#define DivBy2					1
#define DivBy4              	2
#define DivBy8              	3
#define DivBy16             	4
#define DivBy32             	5
#define DivBy64             	6
#define DivBy128            	7

//Refrence selection
#define AREF					1
#define AVCC					2
#define Internal				3

//Left adjustment
#define Left					1
#define Right					2

//Bit masks
#define Prescaler_BIT_MASK		0b11111000
#define MUX_BIT_MASK			0b11100000
#define Autotrigger_BIT_MASK	0b00011111
//ADC states
#define IDLE					0
#define BUSY					1

#define ENABLED					1
#define DISABLED				2


#define FreeRunning				0
#define AnalogComparator		32//1<<5
#define INT0					64//1<<7

#define ADC_EightBitMode		0
#define ADC_TenBitMode			1
/*timers*/
/*#define Timer0CmpMatch
#define Timer0Overflow
#define Timer1*/
#endif
