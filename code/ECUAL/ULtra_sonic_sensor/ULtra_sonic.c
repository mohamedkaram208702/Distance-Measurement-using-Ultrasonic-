/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	ULtra_sonic.c

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	14/10/2022

[DESCRIPTION]  :	Source file for the ULtra_sonic driver.
------------------------------------------------------------------------------------------*/

#include"ULtra_sonic.h"
#include <util/delay.h>
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/ICU/ICU.h"

static volatile uint16 distance; /* Global variable for callback to save distance */
static volatile uint8 ICU_flag; /* Flag to signal that distance calcualtion is done */
static volatile uint8 edges = 0;

/*
 * Function to initialize ultrasonic sensor using ICU
 */
void Ultrasonic_init(void) {
	/* ICU Configuration Structure */
	Icu_ConfigType ICU_config = {F_CPU_8, RISING};

	/* Initialize ICU using configuration structure and callback function */
	Icu_init(&ICU_config);
	Icu_setCallBack(&Ultrasonic_edgeProcessing);

	/* Setup pin for ultrasonic trigger */
	GPIO_setupPinDirection(TRIGGER_PORT, TRIGGER_PIN, PIN_OUTPUT);
}
/*
 * Send trigger ultrasonic sensor to activate
 */
void Ultrasonic_trigger(void) {
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, 1);
	_delay_us(15);
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, 0);
}

/*
 * Function to get ultrasonic sensor distance reading
 * Return: 16-bit distance value in cm
 */
uint16 Ultrasonic_readDistance(void) {
	/* Send Trigger to ultrasonic to activate */
	Ultrasonic_trigger();

	/* Setup ICU to detect rising edge to start pulse width calculation */
	Icu_setEdgeDetectionType(RISING);

	/* Clear timer value to avoid timer overflow */
	Icu_clearTimerValue();

	/* Set ICU_flag to 0 and wait for edgeProcessing to set it to 1 when it calculates distance */
	ICU_flag = 0;
	while(ICU_flag == 0);

	/* Return distance calculated by edgeProcessing */
	return distance;
}

/* Callback function for ICU to process edge detection times and calculate distance */
void Ultrasonic_edgeProcessing(void) {
	static uint16 startTime, endTime;
	if (edges == 0) {
		/* Save pulse start time (rising edge) and set ICU to wait for pulse end (falling edge) */
		startTime = Icu_getInputCaptureValue();
		Icu_setEdgeDetectionType(FALLING);

		/* Set edge to 1 to calculate distance on next function call */
		edges = 1;
	}
	else if (edges == 1) {
		/* Save pulse end time and use it along with start time to calculate distance and save it in global variable*/
		endTime = Icu_getInputCaptureValue();
		distance = (endTime-startTime) / 58;

		/* Set edges to 0 to start all over again on next function call */
		edges = 0;

		/* Set ICU_flag to 1 to signal to readDistance that calculation is done */
		ICU_flag = 1;
	}
}
