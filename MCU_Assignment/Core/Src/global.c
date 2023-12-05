
#include "global.h"

int status = 0;
int red = 5;
int green = 3;
int yellow = 2;

int sec1 = 0;
int sec2 = 0;


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

