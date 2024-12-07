#ifndef __ENCODER_H_
#define __ENCODER_H_

#include "main.h"

int16_t Encoder_Read_CNT(uint8_t Motor_id);
void Encoder_Update_Count(int16_t encoder_all[4]);

#endif
