/*
 * fsm_automatic.c
 *
 *  Created on: November 28, 2023
 *      Author: Hoai Thanh
 */


#include "fsm_automatic.h"


int index_led = 0;


void fsm_automatic_run(){
	switch(status){
	case INIT:
		status = RED1_GREEN2;
		setTimer(1000, 0);

		sec1 = red;
		sec2 = green;
		break;
	case RED1_GREEN2:
		turnonTrafficLight1(RED);
		turnonTrafficLight2(GREEN);

		if(timer_flag[0] == 1){
			setTimer(1000, 0);
			if(sec1 > 0) sec1--;
			if(sec2 > 0) sec2--;
		}

		if(sec2 <= 0){
			status = RED1_YELLOW2;
			sec2 = yellow;
		}
		if(isButtonPressed(0) == 1){
			status = MAN_RED;
			setTimer(250, 2);
			clearAllLED();
		}
		break;
	case RED1_YELLOW2:
		turnonTrafficLight1(RED);
		turnonTrafficLight2(YELLOW);

		if(timer_flag[0] == 1){
			setTimer(1000, 0);
			if(sec1 > 0) sec1--;
			if(sec2 > 0) sec2--;
		}

		if(sec2 <= 0){
			status = GREEN1_RED2;
			sec1 = green;
			sec2 = red;
		}
		if(isButtonPressed(0) == 1){
			status = MAN_RED;
			setTimer(250, 2);
			clearAllLED();
		}
		break;
	case GREEN1_RED2:
		turnonTrafficLight1(GREEN);
		turnonTrafficLight2(RED);

		if(timer_flag[0] == 1){
			setTimer(1000, 0);
			if(sec1 > 0) sec1--;
			if(sec2 > 0) sec2--;
		}

		if(sec1 <= 0){
			status = YELLOW1_RED2;
			sec1 = yellow;
		}
		if(isButtonPressed(0) == 1){
			status = MAN_RED;
			setTimer(250, 2);
			clearAllLED();
		}
		break;
	case YELLOW1_RED2:
		turnonTrafficLight1(YELLOW);
		turnonTrafficLight2(RED);

		if(timer_flag[0] == 1){
			setTimer(1000, 0);
			if(sec1 > 0) sec1--;
			if(sec2 > 0) sec2--;
		}
		if(sec1 <= 0){
			status = RED1_GREEN2;
			sec1 = red;
			sec2 = green;
		}
		if(isButtonPressed(0) == 1){
			status = MAN_RED;
			setTimer(250, 2);
			clearAllLED();
		}
		break;
	default:
		break;
	}

}
