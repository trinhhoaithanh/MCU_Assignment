/*
 * software_timer.h
 *
 *  Created on: November 28, 2023
 *      Author: Hoai Thanh
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];

void setTimer(int duration, int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
