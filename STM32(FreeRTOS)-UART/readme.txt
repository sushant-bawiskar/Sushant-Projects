STM32(FreeRTOS)- UART:
	
Hardware: STM32F4 - Nucleo (ARM Cortex M4)
OS: FreeRTOS

In this code two tasks are created Task1 and Task2.
RTOS scheduler is used to schedule both the tasks.
Both task will alternatively use UART bus.
Cooperative scheduling is used.
Output of the code can be observed on TeraTerm software.

APIs used :
	xTaskCreate : To create task
	vTaskStartScheduler : To start scheduler
	taskYIELD	 : For Scheduling