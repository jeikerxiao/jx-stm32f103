#include "stm32f10x.h"                  // Device header

int main(void)
{
	// Enable the GPIOC clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Push-Pull output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;        // Pin 13
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);            // 初始化
	
//	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);               // PC13输出低电平

	while (1)
	{
		
	}
}
