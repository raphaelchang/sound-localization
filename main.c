#include "ch.h"
#include "hal.h"
#include "stm32f4xx_conf.h"
#include "comm_usb.h"
#include "chprintf.h"
#include "led.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    halInit();
    chSysInit();

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    led_init();
    int inx = 0;

    for (;;)
    {
        led_clear_all();
        led_set(inx, 255);
        inx++;
        inx %= 16;
        chThdSleepMilliseconds(10);
    }
}
