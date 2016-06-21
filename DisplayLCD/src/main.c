/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

#include "gpio_setup.h"
#include "lcd.h"


int main(void)
{
	HAL_Init();

	LCD.enable = GPIO_PIN_0;
	LCD.rs = GPIO_PIN_1;
	LCD.pinos[0] = GPIO_PIN_5;
	LCD.pinos[1] = GPIO_PIN_6;
	LCD.pinos[2] = GPIO_PIN_7;
	LCD.pinos[3] = GPIO_PIN_8;
	LCD.porta = GPIOA;
	init_gpio();
	init_display();

	// limpa o display
	clear();
	/*printf("Timer do Kopper");


	uint32_t start = 0;
	bool rodando = true;
	GPIO_PinState ultimo_estado = true; */

	printf("Super Potenciometro");

	for(;;) {
		/*
		uint32_t now = HAL_GetTick();
		GPIO_PinState botao = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
		if(!botao && (botao != ultimo_estado)) {
			rodando = !rodando;
			if(rodando)
				HAL_ResumeTick();
			else
				HAL_SuspendTick();
		}
		ultimo_estado = botao;

		if(!rodando)
			continue;

		gotoxy(0, 1);

		uint32_t delta = now - start;
		uint32_t ms = delta % 1000;
		uint32_t segundos = (delta/1000);
		uint32_t minutos = segundos/60;

		printf("%02lu:%02lu.%03lu", minutos%60, segundos%60, ms);
		HAL_Delay(11);
		*/
		gotoxy(0, 1);
		uint16_t leitura;
		HAL_ADC_Start(&hadc1);
		leitura = HAL_ADC_GetValue(&hadc1);
		printf("%04d", leitura);
		HAL_Delay(30);
	}
}
