#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define MAX_BUTTON 4

int isButtonPressed(int index);
void getKeyInput();


#endif /* INC_BUTTON_H_ */
