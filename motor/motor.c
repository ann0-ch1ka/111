#include "motor.h"

// Set motor speed, speed:± (3600-MOTOR_IGNORE_PULSE), 0 indicates stop

static int16_t Motor_Ignore_Dead_Zone(int16_t pulse)
{
    if (pulse > 0)
        return pulse + MOTOR_IGNORE_PULSE;
    if (pulse < 0)
        return pulse - MOTOR_IGNORE_PULSE;
    return 0;
}


void Motor_Set_Pwm(uint8_t id, int16_t speed)
{
    speed = Motor_Ignore_Dead_Zone(speed);
    if (speed >= MOTOR_MAX_PULSE)
        speed = MOTOR_MAX_PULSE;
    if (speed <= -MOTOR_MAX_PULSE)
        speed = -MOTOR_MAX_PULSE;
    if(id==0){
        speed=-speed;
        if(speed>=0){
            __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_1,speed);
            __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_2,0);
        }
        else{
            __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_1,0);
            __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_2,-speed);
        }
    }
    else if(id==1){
        speed=-speed;
        if(speed>=0){
            __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_3,speed);
            __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_4,0);
        }
        else{
            __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_3,0);
            __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_4,-speed);
        }
    }
    else if(id==2){
       if(speed>=0){
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,speed);
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,0);
        }
        else{
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,0);
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,-speed);
        }
    }
    else if(id==3){
        if(speed>=0){
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,speed);
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,0);
        }
        else{
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,0);
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,-speed);
        }
    }
}
