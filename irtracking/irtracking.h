#ifndef __IRTRACKING_H_
#define __IRTRACKING_H_
#include "main.h"
#include "motor_pid.h"

#define X1_in HAL_GPIO_ReadPin(X1_GPIO_Port,X1_Pin)
#define X2_in HAL_GPIO_ReadPin(X2_GPIO_Port,X2_Pin)
#define X3_in HAL_GPIO_ReadPin(X3_GPIO_Port,X3_Pin)
#define X4_in HAL_GPIO_ReadPin(X4_GPIO_Port,X4_Pin)

uint8_t teck();


#endif