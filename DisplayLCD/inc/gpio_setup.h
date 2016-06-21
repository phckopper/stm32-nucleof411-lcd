/*
 * gpio_setup.h
 *
 *  Created on: 15/06/2016
 *      Author: PedroHenrique
 */

#ifndef GPIO_SETUP_H_
#define GPIO_SETUP_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;
void init_gpio(void);

#endif /* GPIO_SETUP_H_ */
