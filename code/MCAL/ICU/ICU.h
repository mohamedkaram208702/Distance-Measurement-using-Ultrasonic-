/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	ICU.h

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	14/10/2022

[DESCRIPTION]  :	Header file for the AVR ICU driver.
------------------------------------------------------------------------------------------*/

#ifndef MCAL_ICU_ICU_H_
#define MCAL_ICU_ICU_H_

#include "../../Helpers/std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Icu_init(const Icu_ConfigType * Config_Ptr);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Icu_init
[DESCRIPTION]   :	Function to initialize the ICU driver
 * 						1. Set the required clock.
 * 						2. Set the required edge detection.
 * 						3. Enable the Input Capture Interrupt.
 * 						4. Initialize Timer1 Registers.
[Args]		    :
				  in  -> Config_Ptr:
				  	  	  pointer to structure.

------------------------------------------------------------------------------------------*/
void Icu_setCallBack(void(*a_ptr)(void));
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Icu_setCallBack
[DESCRIPTION]   :	set the Call Back function address.
[Args]		    :
				  in  -> a_ptr:
				  	  	  pointer to function.

------------------------------------------------------------------------------------------*/
void Icu_setEdgeDetectionType(const Icu_EdgeType edgeType);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Icu_setEdgeDetectionType
[DESCRIPTION]   :	get the Timer1 Value when the input is captured
[Args]		    :
				  in  -> edgeType:

------------------------------------------------------------------------------------------*/
uint16 Icu_getInputCaptureValue(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Icu_getInputCaptureValue
[DESCRIPTION]   :	get the Timer1 Value when the input is captured
              		The value stored at Input Capture Register ICR1

------------------------------------------------------------------------------------------*/
void Icu_clearTimerValue(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Icu_clearTimerValue
[DESCRIPTION]   :	clear the Timer1 Value to start count from ZERO.

------------------------------------------------------------------------------------------*/
void Icu_DeInit(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Icu_clearTimerValue
[DESCRIPTION]   :	disable the Timer1 to stop the ICU Driver.

------------------------------------------------------------------------------------------*/


#endif /* MCAL_ICU_ICU_H_ */
