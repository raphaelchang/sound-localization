#ifndef _LED_H_
#define _LED_H_

#include <stdint.h>
#include "ch.h"
#include "hal.h"
#include <math.h>
#include "stm32f4xx_conf.h"

void led_init();
void led_set(uint8_t index, uint8_t value);
void led_clear_all();

#endif /* _LED_H_ */
