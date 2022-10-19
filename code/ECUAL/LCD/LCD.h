/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	LCD.h

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	02/10/2022

[DESCRIPTION]  :	Header file for the AVR LCD driver.
------------------------------------------------------------------------------------------*/

#ifndef ECUAL_LCD_LCD_H_
#define ECUAL_LCD_LCD_H_
#include "../../Helpers/std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE 8

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTB_ID
#define LCD_RS_PIN_ID                  PIN0_ID

#define LCD_RW_PORT_ID                 PORTB_ID
#define LCD_RW_PIN_ID                  PIN1_ID

#define LCD_E_PORT_ID                  PORTB_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTA_ID

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID                 PIN3_ID
#define LCD_DB5_PIN_ID                 PIN4_ID
#define LCD_DB6_PIN_ID                 PIN5_ID
#define LCD_DB7_PIN_ID                 PIN6_ID

#endif


/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_init(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LCD_init
[DESCRIPTION]   :	Initialize the LCD:
 	 	 	 	 	 	 * 1. Setup the LCD pins directions by use the GPIO driver.
 	 	 	 	 	 	 * 2. Setup the LCD Data Mode 4-bits or 8-bits.

------------------------------------------------------------------------------------------*/

void LCD_sendCommand(uint8 command);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LCD_sendCommand
[DESCRIPTION]   :	Send the required command to the screen.
[Args]		    :
				  in  -> command :
				  	  	  The required command
------------------------------------------------------------------------------------------*/

void LCD_displayCharacter(uint8 data);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LCD_displayCharacter
[DESCRIPTION]   :	Display the required character on the screen
[Args]		    :
				  in  -> command :
				  	  	  The required character
------------------------------------------------------------------------------------------*/

void LCD_displayString(const char *Str);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LCD_displayString
[DESCRIPTION]   :	Display the required string on the screen
[Args]		    :
				  in  -> command :
				  	  	  The required string
------------------------------------------------------------------------------------------*/

void LCD_moveCursor(uint8 row,uint8 col);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LCD_moveCursor
[DESCRIPTION]   :	Move the cursor to a specified row and column index on the screen.
[Args]		    :
				  in  -> command :
				  	  	  The required row and column.
------------------------------------------------------------------------------------------*/

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LCD_displayStringRowColumn
[DESCRIPTION]   :	Display the required string in a specified row and column index on the screen
[Args]		    :
				  in  -> command :
				  	  	  The required row and column and the string .
------------------------------------------------------------------------------------------*/

void LCD_intgerToString(int data);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LCD_intgerToString
[DESCRIPTION]   :	Display the required decimal value on the screen.
[Args]		    :
				  in  -> command :
				  	  	  The required data.
------------------------------------------------------------------------------------------*/

void LCD_clearScreen(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LCD_clearScreen
[DESCRIPTION]   :	Send the clear screen command.

------------------------------------------------------------------------------------------*/

#endif /* ECUAL_LCD_LCD_H_ */
