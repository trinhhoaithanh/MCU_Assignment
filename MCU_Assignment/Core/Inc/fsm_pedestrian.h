/*
 * fsm_pedestrian.h
 *
 *  Created on: Dec 7, 2023
 *      Author: Phuc Toan
 */

#ifndef INC_FSM_PEDESTRIAN_H_
#define INC_FSM_PEDESTRIAN_H_


#include "global.h"

void toggle_buzzer(int volume);
void buzzer_run();

void fsm_pedestrian_run();

#endif /* INC_FSM_PEDESTRIAN_H_ */
