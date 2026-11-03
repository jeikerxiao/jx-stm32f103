#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	// Enable the GPIOA clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	// Configure GPIOA Pin 0 as output
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  	// Push-Pull output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;			// PA0
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	// 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);			    // Initialize GPIOA Pin 0
	
	while (1)
	{
		// 写法1
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);              // Set PA0 to low
		Delay_ms(500);
		GPIO_SetBits(GPIOA, GPIO_Pin_0);  		        // Set PA0 to high	
		Delay_ms(500);
		// 写法2
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);    // Set PA0 to low
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);      // Set PA0 to high
		Delay_ms(500);
		// 写法3
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)0); // Set PA0 to low
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)1); // Set PA0 to high
		Delay_ms(500);
	}
}
