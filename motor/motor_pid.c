#include "motor_pid.h"

const float err_integral_max =5000;

float kp=2,ki=0,kd=0.5;
float a = 0.3;



void get_now_speed(car_speed *now_speed){
    int16_t encoder_all[4]={0,0,0,0};
    Encoder_Update_Count(encoder_all);
    now_speed->lf_speed=(float)encoder_all[0]*10 *204.203f/ 1040.0f ;
    now_speed->ls_speed=(float)encoder_all[1]*10 *203.204f/ 1040.0f ;
    now_speed->rf_speed=(float)encoder_all[2]*10 *203.204f/ 1040.0f ;
    now_speed->rs_speed=(float)encoder_all[3]*10 *203.204f/ 1040.0f ;
}


float pid_speed(int16_t speed , int16_t last_speed ,int16_t set_speed, int16_t id,car_speed *now_speed,speed_err *now_err){
    float err = set_speed - speed;
    float last_err = 0;
    float err_i=0;
    if(id==0){
        last_err=now_err->lf_err;
        now_err->lf_err = err;
        now_err->lf_err_i += err;
        err_i = now_err->lf_err_i;
    }
    else if(id==1){
        last_err=now_err->ls_err;
        now_err->ls_err = err;
        now_err->ls_err_i += err;
        err_i = now_err->ls_err_i;
    }
    else if(id==2){
        last_err=now_err->rf_err;
        now_err->rf_err=err;
        now_err->rf_err_i += err;
        err_i = now_err->rf_err_i;
    }
    else if(id==3){
        last_err=now_err->rs_err;
        now_err->rs_err=err;
        now_err->rs_err_i += err;
        err_i = now_err->rs_err_i;
    }
    float pwm_val = kp*err +ki*(err_i)+kd*(err-last_err);
    return  pwm_val;
}

void car_set_speed(int16_t s1,int16_t s2,int16_t s3,int16_t s4){
    Motor_Set_Pwm(0,s1);
    Motor_Set_Pwm(1,s2);
    Motor_Set_Pwm(2,s3);
    Motor_Set_Pwm(3,s4);
}

