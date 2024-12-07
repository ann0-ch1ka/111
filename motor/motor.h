#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "main.h"
#include "tim.h"
#define MOTOR_IGNORE_PULSE (1600)
#define MOTOR_MAX_PULSE (3600)

typedef enum
{
	MOTOR_ID_M1 = 0,
	MOTOR_ID_M2,
	MOTOR_ID_M3,
	MOTOR_ID_M4,
	MAX_MOTOR
} Motor_ID;

void Motor_Set_Pwm(uint8_t id, int16_t speed);


#endif
