#include "encoder.h"
#include "tim.h"

int16_t Encoder_Read_CNT(uint8_t Motor_id)
{
	int16_t Encoder_TIM = 0;
	switch (Motor_id)
	{
	case 0: //Motor 1
		Encoder_TIM =0x7fff- __HAL_TIM_GET_COUNTER(&htim4);
		__HAL_TIM_SET_COUNTER(&htim4,0x7fff);
		break;
	case 1:  //Motor2
		Encoder_TIM = 0x7fff-__HAL_TIM_GET_COUNTER(&htim2);
		__HAL_TIM_SET_COUNTER(&htim2,0x7fff);
		break;
	case 2:  //Motor 3
		Encoder_TIM = 0x7fff-__HAL_TIM_GET_COUNTER(&htim5);
		__HAL_TIM_SET_COUNTER(&htim5,0x7fff);
		break;
	case 3:  //Motor 4
		Encoder_TIM = 0x7fff-__HAL_TIM_GET_COUNTER(&htim3);
		__HAL_TIM_SET_COUNTER(&htim3,0x7fff);
		break;
	default:
		break;
	}
	return Encoder_TIM;
}


// Get the total four - way encoder count up to now


// Update the count value of the encoder. call every 10 milliseconds
void Encoder_Update_Count(int16_t encoder_all[4])
{
	encoder_all[0] = -Encoder_Read_CNT(0);   //电机方向是反的
	encoder_all[1] = -Encoder_Read_CNT(1);
	encoder_all[2] = Encoder_Read_CNT(2);
	encoder_all[3] = Encoder_Read_CNT(3);
}
