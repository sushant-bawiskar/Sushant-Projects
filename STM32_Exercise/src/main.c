
/**
  ******************************************************************************
  * @Author  Sushant Bawiskar
  * @Application UART
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    08-july-2020
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xTaskHandle1 = NULL;//This is TCB for particular task
TaskHandle_t xTaskHandle2 = NULL;

char txt[250] = {0};
void vTask1(void* params);//This are two tasks
void vTask2(void* params);
static void UART_SETUP(void);
void msg(char*);

#define TRUE 1
#define AVAILABLE TRUE
#define NOTAVAILABLE !(AVAILABLE)
uint32_t SEMA = AVAILABLE;

int main(void)
{
	DWT->CTRL |= (1 << 0);
	RCC_DeInit();

	SystemCoreClockUpdate();

	UART_SETUP();
	sprintf(txt, "--START-- \n");
	msg(txt);

	xTaskCreate(vTask1, "Task-1",configMINIMAL_STACK_SIZE, NULL,2, &xTaskHandle1);
	xTaskCreate(vTask2, "Task-2",configMINIMAL_STACK_SIZE, NULL,2, &xTaskHandle2);

	vTaskStartScheduler();
	for(;;);
}

void vTask1(void* params)
	{
	while(1)
		{
		if(SEMA == AVAILABLE){

		SEMA = NOTAVAILABLE;
		msg(" TASK-1 \n\n\r");
		SEMA = AVAILABLE;

		taskYIELD();

		}
		}
	}

void vTask2(void* params)
	{
	while(1)
		{

		if(SEMA == AVAILABLE){
		msg(" TASK-2 \n\n\r");
		SEMA = AVAILABLE;

		taskYIELD();
		}
		}


	}


static void UART_SETUP(void)
{
	GPIO_InitTypeDef gpio_uart_pins;
	USART_InitTypeDef uart2_init;

	//1. Enable the UART2  and GPIOA Peripheral clock
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

	//PA2 is UART2_TX, PA3 is UART2_RX

	//2. Alternate function configuration of MCU pins to behave as UART2 TX and RX

	//zeroing each and every member element of the structure
	memset(&gpio_uart_pins,0,sizeof(gpio_uart_pins));

	gpio_uart_pins.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	gpio_uart_pins.GPIO_Mode = GPIO_Mode_AF;
	gpio_uart_pins.GPIO_PuPd = GPIO_PuPd_UP;
	gpio_uart_pins.GPIO_OType= GPIO_OType_PP;
	gpio_uart_pins.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOA, &gpio_uart_pins);


	//3. AF mode settings for the pins
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); //PA2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); //PA3

	//4. UART parameter initializations
	//zeroing each and every member element of the structure
	memset(&uart2_init,0,sizeof(uart2_init));

	uart2_init.USART_BaudRate = 115200;
	uart2_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	uart2_init.USART_Mode =  USART_Mode_Tx | USART_Mode_Rx;
	uart2_init.USART_Parity = USART_Parity_No;
	uart2_init.USART_StopBits = USART_StopBits_1;
	uart2_init.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2,&uart2_init);


	//5. Enable the UART2 peripheral
	USART_Cmd(USART2,ENABLE);

}


void msg(char* text)
	{
	for(uint32_t i = 0; i < strlen(text); i++)
		{
			while(USART_GetFlagStatus(USART2,USART_FLAG_TXE) != SET);
			USART_SendData(USART2,text[i]);
		}
	while(!(USART_GetFlagStatus(USART2,USART_FLAG_TC)));


	}

