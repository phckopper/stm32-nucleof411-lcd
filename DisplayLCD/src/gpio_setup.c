/*
 * gpio_setup.c
 *
 *  Created on: 15/06/2016
 *      Author: PedroHenrique
 */
#include "gpio_setup.h"


ADC_HandleTypeDef hadc1;

void init_gpio(void) {
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_init; // Declara uma estrutura para popularmos

	GPIO_init.Pin = GPIO_PIN_13; // Botão B1
	GPIO_init.Mode = GPIO_MODE_INPUT; // Modo de entrada
	GPIO_init.Pull = GPIO_NOPULL; // Já temos um pull-up externo
	GPIO_init.Speed = GPIO_SPEED_FAST; // Fast GPIO for reasons.

	HAL_GPIO_Init(GPIOC, &GPIO_init);

	GPIO_init.Pin = GPIO_PIN_0;
	GPIO_init.Mode = GPIO_MODE_ANALOG;
	GPIO_init.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_init);

	__HAL_RCC_ADC1_CLK_ENABLE();
	ADC_ChannelConfTypeDef sConfig;

	    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
	    */
	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = (uint32_t) 0x00000000;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ScanConvMode = DISABLE;
	hadc1.Init.ContinuousConvMode = DISABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.NbrOfConversion = 1;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	HAL_ADC_Init(&hadc1);

	/**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	*/
	sConfig.Channel = ADC_CHANNEL_8;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_ADC_Start(&hadc1);
}
