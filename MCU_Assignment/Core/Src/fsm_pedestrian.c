/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 7, 2023
 *      Author: Phuc Toan
 */

#include "fsm_pedestrian.h"

int pedestrian_flag = 0;
int set_val;

void buzzer_stable(){
	htim3.Instance->CCR1 = (htim3.Instance->CCR1 == 0 ? 50 : 0);
	setTimer(500, 5);


    set_val--;
    setTimer(1000, 6);
}

// còn 10 giây
void buzzer_speed_up(){
	uint8_t value = (10-set_val)*25;
  	while(value < 255){
  		int i=10-set_val;
  		htim3.Instance->CCR1 = (htim3.Instance->CCR1 == 0 ? value : 0);
  		value += (25);
       	setTimer(1000 - 10 * i, 6);
       	i++;
  	}
}

void fsm_buzzer(){
	set_val = sec1;
	while(set_val>10){
		buzzer_stable();
	}

	buzzer_speed_up();
}

void fsm_pedestrian_run(){
	if(isButtonPressed(3) == 1){
		pedestrian_flag = 1;
		int pedestrianLightPeriod = (red + yellow + green)*2*1000;
		setTimer(pedestrianLightPeriod, 1);
	}

	if(timer_flag[1] == 1){
		pedestrian_flag = 0;
		turnonPedestrianLight(CLEAR);
	}

	if(pedestrian_flag){
		switch(status){
		case RED1_GREEN2:
			turnonPedestrianLight(GREEN);

			fsm_buzzer();

			break;
		case RED1_YELLOW2:
			turnonPedestrianLight(YELLOW);

			fsm_buzzer();

			break;
		case GREEN1_RED2:
			turnonPedestrianLight(RED);
			break;
		case YELLOW1_RED2:
			turnonPedestrianLight(RED);
			break;
		default:
			break;
		}
	}
}
