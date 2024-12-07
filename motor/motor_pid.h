#ifndef __MOTOR_PID_H_
#define __MOTOR_PID_H_

#include "motor.h"
#include "encoder.h"
#include "main.h"

typedef struct __speed{
    float lf_speed;
    float ls_speed;
    float rf_speed;
    float rs_speed;
}car_speed;

typedef struct __error{
    float lf_err;
    float ls_err;
    float rf_err;
    float rs_err;
    float lf_err_i;
    float ls_err_i;
    float rf_err_i;
    float rs_err_i;
}speed_err;



void get_now_speed(car_speed *now_speed);
float pid_speed(int16_t speed , int16_t last_speed ,int16_t set_speed, int16_t id,car_speed *now_speed,speed_err *now_err);
void car_set_speed(int16_t s1,int16_t s2,int16_t s3,int16_t s4);
float limit_err(float err);


#endif
