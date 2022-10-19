/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	APP.h

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	26/09/2022

[DESCRIPTION]  :	Header file for the application.
------------------------------------------------------------------------------------------*/

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/ICU/ICU.h"
#include "../ECUAL/ULtra_sonic_sensor/ULtra_sonic.h"
#include "../Helpers/common_macros.h"
#include "../Helpers/MCU_configuration.h"
#include "../ECUAL/LCD/LCD.h"

extern uint16 distance;
void APP_init(void);
void APP_start(void);


#endif /* APPLICATION_APP_H_ */
