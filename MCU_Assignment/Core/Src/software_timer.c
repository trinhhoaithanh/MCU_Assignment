/*
 * software_timer.c
 *
 *  Created on: November 28, 2023
 *      Author: Hoai Thanh
 */


#include "software_timer.h"
#define TICK 10

int timer_counter[10] = {0};
int timer_flag[10] = {0};

void setTimer(int duration, int index){
 	if(index >= 0 && index < 10){
		timer_counter[index] = duration / TICK;
		timer_flag[index] = 0;
	}
}

void timerRun(){
	for(int i = 0; i <= 5; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
