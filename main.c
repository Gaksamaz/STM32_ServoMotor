#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

void gpioConfig(){

	GPIO_InitTypeDef GPIOInitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIOInitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIOInitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; // tim2 chanel 1
	GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIOInitStructure);

}

void timerConfig(){

	TIM_TimeBaseInitTypeDef TIMERInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIMERInitStructure.TIM_Prescaler = 100;
	TIMERInitStructure.TIM_Period = 13999;
	TIMERInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIMERInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM2, &TIMERInitStructure);
	TIM_Cmd(TIM2, ENABLE);

}

// servo 1
void pwmConfig(uint16_t timPulse){

	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse = timPulse;
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

}

// servo 2
void pwm1Config(uint16_t timPulse){

	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse = timPulse;
	
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

}

void delay(uint32_t time){

	while(time--);
}

int main(){

	gpioConfig();
	timerConfig();
	
	
	while(1){
	
		pwmConfig(1049);//0 degree
		delay(7200000);
		pwmConfig(1399);// 90 degree
		delay(7200000);
		pwmConfig(699); //180 degree
		delay(7200000);
		 
		pwm1Config(1049);//0 degree
		delay(7200000);
		pwm1Config(1399);// 90 degree
		delay(7200000);
		pwm1Config(699); //180 degree
		delay(7200000);	
	}

}

