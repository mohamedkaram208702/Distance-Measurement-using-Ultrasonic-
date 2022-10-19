/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	main.c

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	26/09/2022

[DESCRIPTION]  :	Design a system to measure the distance using ultrasonic sensor HC-SR04 using ATmega32 microcontroller
------------------------------------------------------------------------------------------*/
#include "../Application/APP.h"



uint16 distance =0;

void APP_init(void){


	/* Global Interrupt Enable */
	SREG |= (1<<7);


	/* Ultrasonic and LCD initialization */
	Ultrasonic_init();
	LCD_init();

	LCD_displayString("Distance =    cm");
}

void APP_start(void){
	distance = Ultrasonic_readDistance();
	LCD_moveCursor(0, 11);
	if (distance < 10) LCD_displayCharacter(' ');
	if (distance < 100) LCD_displayCharacter(' ');
	LCD_intgerToString(distance);
}
