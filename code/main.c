/*
 * main.c
 *
 *  Created on: Oct 16, 2022
 *      Author: mohamed karam Fouad
 */

#include "./Application/APP.h"
int main(void)
{
	//Initialize
    APP_init();

	//Main loop
	while(1){
		APP_start();
	}
}

