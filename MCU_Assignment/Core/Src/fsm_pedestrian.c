/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 7, 2023
 *      Author: Phuc Toan
 */

#include "fsm_pedestrian.h"
int pedestrian_flag = 0;
int buzzer_flag = 0;
int delay = 500;
int adder = 0;

void toggle_buzzer(int volume){
	if(buzzer_flag == 0){
		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,volume);
		buzzer_flag = 1;
	}
	else{
		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
		buzzer_flag = 0;
	}
}

void reset_buzzer(){
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
	adder = 0;
}

void buzzer_run(){
	if(timer_flag[3] == 1){
		int volume;
		if(sec1 > 10){
			delay = 500;
			volume = 5;
		}
		else{
			int period = 11 - sec1;
			delay = 500/period;
			volume =  (period-1)*period + 5;
			volume += adder;
			adder++;
		}
		toggle_buzzer(volume);
		setTimer(delay, 3);
	}
}

void buzzer_init(){
	delay = 500;
	adder = 0;
	if(sec1 > 10){
		delay = 500;
	}
	else{
		int period = 11 - sec1;
		delay = 500/period;
	}
	setTimer(delay, 3);
}

void fsm_pedestrian_run(){
	if(isButtonPressed(3) == 1){
		pedestrian_flag = 1;
		int pedestrianLightPeriod = (red + yellow + green)*2*1000;
		setTimer(pedestrianLightPeriod, 1);
		buzzer_init();
	}

	if(timer_flag[1] == 1){
		pedestrian_flag = 0;
		turnonPedestrianLight(CLEAR);
		reset_buzzer();
	}

	if(pedestrian_flag){
		switch(status){
		case RED1_GREEN2:
			turnonPedestrianLight(GREEN);
			buzzer_run();
			break;
		case RED1_YELLOW2:
			turnonPedestrianLight(YELLOW);
			buzzer_run();
			break;
		case GREEN1_RED2:
			turnonPedestrianLight(RED);
			reset_buzzer();
			break;
		case YELLOW1_RED2:
			turnonPedestrianLight(RED);
			reset_buzzer();
			break;
		default:
			break;
		}
	}
}
