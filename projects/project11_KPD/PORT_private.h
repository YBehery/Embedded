/*****************************************************************/
/*****************************************************************/
/**************		Author:	Youssef Behery	**********************/
/**************		Layer: 	MCAL			**********************/
/**************		SWC:	PORT			**********************/
/**************		Version:1.00			**********************/
/*****************************************************************/
/*****************************************************************/
#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_
/*concatinate bits*/
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)				CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
/*PORT DIRECTION CONC*/
#define PORTA_DIR		CONC(PORTA_PIN_7_DIR, PORTA_PIN_6_DIR, PORTA_PIN_5_DIR, PORTA_PIN_4_DIR, PORTA_PIN_3_DIR, PORTA_PIN_2_DIR, PORTA_PIN_1_DIR, PORTA_PIN_0_DIR)
#define PORTB_DIR		CONC(PORTB_PIN_7_DIR, PORTB_PIN_6_DIR, PORTB_PIN_5_DIR, PORTB_PIN_4_DIR, PORTB_PIN_3_DIR, PORTB_PIN_2_DIR, PORTB_PIN_1_DIR, PORTB_PIN_0_DIR)
#define PORTC_DIR		CONC(PORTC_PIN_7_DIR, PORTC_PIN_6_DIR, PORTC_PIN_5_DIR, PORTC_PIN_4_DIR, PORTC_PIN_3_DIR, PORTC_PIN_2_DIR, PORTC_PIN_1_DIR, PORTC_PIN_0_DIR)
#define PORTD_DIR		CONC(PORTD_PIN_7_DIR, PORTD_PIN_6_DIR, PORTD_PIN_5_DIR, PORTD_PIN_4_DIR, PORTD_PIN_3_DIR, PORTD_PIN_2_DIR, PORTD_PIN_1_DIR, PORTD_PIN_0_DIR)
/*PORT OUTPUT CONC*/
#define PORTA_InitValue		CONC(PORTA_PIN_7_InitValue, PORTA_PIN_6_InitValue, PORTA_PIN_5_InitValue, PORTA_PIN_4_InitValue, PORTA_PIN_3_InitValue, PORTA_PIN_2_InitValue, PORTA_PIN_1_InitValue, PORTA_PIN_0_InitValue)
#define PORTB_InitValue		CONC(PORTB_PIN_7_InitValue, PORTB_PIN_6_InitValue, PORTB_PIN_5_InitValue, PORTB_PIN_4_InitValue, PORTB_PIN_3_InitValue, PORTB_PIN_2_InitValue, PORTB_PIN_1_InitValue, PORTB_PIN_0_InitValue)
#define PORTC_InitValue		CONC(PORTC_PIN_7_InitValue, PORTC_PIN_6_InitValue, PORTC_PIN_5_InitValue, PORTC_PIN_4_InitValue, PORTC_PIN_3_InitValue, PORTC_PIN_2_InitValue, PORTC_PIN_1_InitValue, PORTC_PIN_0_InitValue)
#define PORTD_InitValue		CONC(PORTD_PIN_7_InitValue, PORTD_PIN_6_InitValue, PORTD_PIN_5_InitValue, PORTD_PIN_4_InitValue, PORTD_PIN_3_InitValue, PORTD_PIN_2_InitValue, PORTD_PIN_1_InitValue, PORTD_PIN_0_InitValue)


#define INPUT 	0
#define OUTPUT	1

#endif