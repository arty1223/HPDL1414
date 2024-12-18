#ifndef HPDL1414_h
#define HPDL1414_h
#include <stddef.h>
#include <stdint.h>
#include <_ansi.h>

_BEGIN_STD_C

#include "hpdl1414_conf.h"

#if defined(STM32G0)
#include "stm32g0xx_hal.h"
#elif defined(STM32F1)
#include "stm32f1xx_hal.h"
#elif defined(STM32F4)
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#else
#error "HPDL1414 library was tested only on STM32G0, STM32F1, STM32F4 MCU families. Please modify hpdl1414.hpp if you know what you are doing. Also please send a pull request if it turns out the library works on other MCU's as well!"
#endif

#if defined(__GPIOB)
#define __GPIO_PORT GPIOB
#elif defined(__GPIOA)
#define __GPIO_PORT GPIOA
#elif defined(__GPIOC)
#define __GPIO_PORT GPIOC
#endif

void hpdl1414_init();
void hpdl1414_update(unsigned int digit, unsigned int sprite);
void hpdl1414_string(char str[]);
void hpdl1414_num(int numb);
void hpdl1414_mix(char ltr, int num);

_END_STD_C

#endif
