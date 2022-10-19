/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	ULtra_sonic.h

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	14/10/2022

[DESCRIPTION]  :	Header file for the ULtra_sonic driver.
------------------------------------------------------------------------------------------*/

#ifndef ECUAL_ULTRA_SONIC_SENSOR_ULTRA_SONIC_H_
#define ECUAL_ULTRA_SONIC_SENSOR_ULTRA_SONIC_H_

#include "../../Helpers/std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TRIGGER_PORT PORTB_ID
#define TRIGGER_PIN PIN5_ID
#define ECHO_PORT PORTD_ID
#define ECHO_PIN PIN6_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void Ultrasonic_init(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Ultrasonic_init
[DESCRIPTION]   :	Function to initialize ultrasonic sensor using ICU

------------------------------------------------------------------------------------------*/
void Ultrasonic_trigger(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Ultrasonic_trigger
[DESCRIPTION]   :	responsible for sending the Trigger pulse to the ultrasonic.

------------------------------------------------------------------------------------------*/
uint16 Ultrasonic_readDistance(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Ultrasonic_readDistance
[DESCRIPTION]   :	1. Send the trigger pulse by using Ultrasonic_Trigger function.
  	  	  	  	    2. Start the measurements by the ICU from this moment.

[Return]        :	16-bit distance value in cm.
------------------------------------------------------------------------------------------*/
void Ultrasonic_edgeProcessing(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	Ultrasonic_edgeProcessing
[DESCRIPTION]   :	responsible for:
                        1.This is the call back function called by the ICU driver.
                        2. This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.

------------------------------------------------------------------------------------------*/
#endif /* ECUAL_ULTRA_SONIC_SENSOR_ULTRA_SONIC_H_ */