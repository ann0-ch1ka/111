#include "irtracking.h"


car_speed now_speed = {0,0,0,0};
speed_err now_err = {0,0,0,0,0,0,0,0};
int16_t encoder_all[4];


uint8_t teck(){
        int16_t lf_l_s= now_speed.lf_speed;
        int16_t ls_l_s= now_speed.ls_speed;
        int16_t rf_l_s= now_speed.rf_speed;
        int16_t rs_l_s= now_speed.rs_speed;
        get_now_speed(&now_speed);
        if(X2_in==0&&X3_in==1){
            int16_t pwm_val_lf = pid_speed(now_speed.lf_speed,lf_l_s,-1000,0,&now_speed,&now_err);
            int16_t pwm_val_ls = pid_speed(now_speed.ls_speed,ls_l_s,-1000,1,&now_speed,&now_err);
            int16_t pwm_val_rf = pid_speed(now_speed.rf_speed,rf_l_s,1500,2,&now_speed,&now_err);
            int16_t pwm_val_rs = pid_speed(now_speed.rs_speed,rs_l_s,1500,3,&now_speed,&now_err);
            car_set_speed(pwm_val_lf,pwm_val_lf,pwm_val_rf,pwm_val_rs);
        }
        else if (X2_in==1&&X3_in==0){
            int16_t pwm_val_lf = pid_speed(now_speed.lf_speed,lf_l_s,1500,0,&now_speed,&now_err);
            int16_t pwm_val_ls = pid_speed(now_speed.ls_speed,ls_l_s,1500,1,&now_speed,&now_err);
            int16_t pwm_val_rf = pid_speed(now_speed.rf_speed,rf_l_s,-1000,2,&now_speed,&now_err);
            int16_t pwm_val_rs = pid_speed(now_speed.rs_speed,rs_l_s,-1300,3,&now_speed,&now_err);
            car_set_speed(pwm_val_lf,pwm_val_lf,pwm_val_rf,pwm_val_rs);
        }
        else{
            int16_t pwm_val_lf = pid_speed(now_speed.lf_speed,lf_l_s,1500,0,&now_speed,&now_err);
            int16_t pwm_val_ls = pid_speed(now_speed.ls_speed,ls_l_s,1500,1,&now_speed,&now_err);
            int16_t pwm_val_rf = pid_speed(now_speed.rf_speed,rf_l_s,1500,2,&now_speed,&now_err);
            int16_t pwm_val_rs = pid_speed(now_speed.rs_speed,rs_l_s,1500,3,&now_speed,&now_err);
            car_set_speed(pwm_val_lf,pwm_val_lf,pwm_val_rf,pwm_val_rs);
        }
        return 1;
}