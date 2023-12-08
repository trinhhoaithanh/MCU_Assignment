
#include "global.h"

int status = 0;
int red = 10;
int green = 7;
int yellow = 3;

int sec1 = 0;
int sec2 = 0;

int led_buffer[4] = {0, 0, 0, 0};

void updateClockBuffer(int sec1, int sec2){
	led_buffer[0] = sec1/10;
	led_buffer[1] = sec1%10;
	led_buffer[2] = sec2/10;
	led_buffer[3] = sec2%10;
}

void clearAllLED(){
	HAL_GPIO_WritePin(Traffic_Light1_1_GPIO_Port, Traffic_Light1_1_Pin, RESET);
	HAL_GPIO_WritePin(Traffic_Light1_2_GPIO_Port, Traffic_Light1_2_Pin, RESET);

	HAL_GPIO_WritePin(Traffic_Light2_1_GPIO_Port, Traffic_Light2_1_Pin, RESET);
	HAL_GPIO_WritePin(Traffic_Light2_2_GPIO_Port, Traffic_Light2_2_Pin, RESET);

	HAL_GPIO_WritePin(Pedestrian_Light_1_GPIO_Port, Pedestrian_Light_1_Pin, RESET);
	HAL_GPIO_WritePin(Pedestrian_Light_2_GPIO_Port, Pedestrian_Light_2_Pin, RESET);
}

void turnonTrafficLight1(int led){
	switch(led){
	case RED:
		HAL_GPIO_WritePin(Traffic_Light1_1_GPIO_Port, Traffic_Light1_1_Pin, SET);
		HAL_GPIO_WritePin(Traffic_Light1_2_GPIO_Port, Traffic_Light1_2_Pin, RESET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(Traffic_Light1_1_GPIO_Port, Traffic_Light1_1_Pin, RESET);
		HAL_GPIO_WritePin(Traffic_Light1_2_GPIO_Port, Traffic_Light1_2_Pin, SET);
		break;
	case YELLOW:
		HAL_GPIO_WritePin(Traffic_Light1_1_GPIO_Port, Traffic_Light1_1_Pin, SET);
		HAL_GPIO_WritePin(Traffic_Light1_2_GPIO_Port, Traffic_Light1_2_Pin, SET);
		break;
	case CLEAR:
		HAL_GPIO_WritePin(Traffic_Light1_1_GPIO_Port, Traffic_Light1_1_Pin, RESET);
		HAL_GPIO_WritePin(Traffic_Light1_2_GPIO_Port, Traffic_Light1_2_Pin, RESET);
		break;
	default:
		break;
	}
}

void turnonTrafficLight2(int led){
	switch(led){
	case RED:
		HAL_GPIO_WritePin(Traffic_Light2_1_GPIO_Port, Traffic_Light2_1_Pin, SET);
		HAL_GPIO_WritePin(Traffic_Light2_2_GPIO_Port, Traffic_Light2_2_Pin, RESET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(Traffic_Light2_1_GPIO_Port, Traffic_Light2_1_Pin, RESET);
		HAL_GPIO_WritePin(Traffic_Light2_2_GPIO_Port, Traffic_Light2_2_Pin, SET);
		break;
	case YELLOW:
		HAL_GPIO_WritePin(Traffic_Light2_1_GPIO_Port, Traffic_Light2_1_Pin, SET);
		HAL_GPIO_WritePin(Traffic_Light2_2_GPIO_Port, Traffic_Light2_2_Pin, SET);
		break;
	case CLEAR:
		HAL_GPIO_WritePin(Traffic_Light2_1_GPIO_Port, Traffic_Light2_1_Pin, RESET);
		HAL_GPIO_WritePin(Traffic_Light2_2_GPIO_Port, Traffic_Light2_2_Pin, RESET);
		break;
	default:
		break;
	}
}

void turnonPedestrianLight(int led){
	switch(led){
	case RED:
		HAL_GPIO_WritePin(Pedestrian_Light_1_GPIO_Port, Pedestrian_Light_1_Pin, SET);
		HAL_GPIO_WritePin(Pedestrian_Light_2_GPIO_Port, Pedestrian_Light_2_Pin, RESET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(Pedestrian_Light_1_GPIO_Port, Pedestrian_Light_1_Pin, RESET);
		HAL_GPIO_WritePin(Pedestrian_Light_2_GPIO_Port, Pedestrian_Light_2_Pin, SET);
		break;
	case YELLOW:
		HAL_GPIO_WritePin(Pedestrian_Light_1_GPIO_Port, Pedestrian_Light_1_Pin, SET);
		HAL_GPIO_WritePin(Pedestrian_Light_2_GPIO_Port, Pedestrian_Light_2_Pin, SET);
		break;
	case CLEAR:
		HAL_GPIO_WritePin(Pedestrian_Light_1_GPIO_Port, Pedestrian_Light_1_Pin, RESET);
		HAL_GPIO_WritePin(Pedestrian_Light_2_GPIO_Port, Pedestrian_Light_2_Pin, RESET);
		break;
	default:
		break;
	}
}

void toggleLedRED(){
	HAL_GPIO_TogglePin(Traffic_Light1_1_GPIO_Port, Traffic_Light1_1_Pin);
	HAL_GPIO_TogglePin(Traffic_Light2_1_GPIO_Port, Traffic_Light2_1_Pin);
}

void toggleLedYELLOW(){
	HAL_GPIO_TogglePin(Traffic_Light1_1_GPIO_Port, Traffic_Light1_1_Pin);
	HAL_GPIO_TogglePin(Traffic_Light1_2_GPIO_Port, Traffic_Light1_2_Pin);

	HAL_GPIO_TogglePin(Traffic_Light2_1_GPIO_Port, Traffic_Light2_1_Pin);
	HAL_GPIO_TogglePin(Traffic_Light2_2_GPIO_Port, Traffic_Light2_2_Pin);
}

void toggleLedGREEN(){
	HAL_GPIO_TogglePin(Traffic_Light1_2_GPIO_Port, Traffic_Light1_2_Pin);
	HAL_GPIO_TogglePin(Traffic_Light2_2_GPIO_Port, Traffic_Light2_2_Pin);
}
