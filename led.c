#include "led.h"

const I2CConfig i2ccfg = {
    OPMODE_I2C,
    100000,
    STD_DUTY_CYCLE,
};

void led_init()
{
    i2cStart(&I2CD2, &i2ccfg);
    palSetPadMode(GPIOB, 10, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN);
    palSetPadMode(GPIOB, 11, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN);

    uint8_t txbuf[2];
    uint8_t rxbuf[1];
    txbuf[0] = 0x14;
    txbuf[1] = 0xFF;
    i2cMasterTransmitTimeout(&I2CD2, 0x60, txbuf, 2, rxbuf, 0, MS2ST(5));
    txbuf[0] = 0x15;
    i2cMasterTransmitTimeout(&I2CD2, 0x60, txbuf, 2, rxbuf, 0, MS2ST(5));
    txbuf[0] = 0x16;
    i2cMasterTransmitTimeout(&I2CD2, 0x60, txbuf, 2, rxbuf, 0, MS2ST(5));
    txbuf[0] = 0x17;
    i2cMasterTransmitTimeout(&I2CD2, 0x60, txbuf, 2, rxbuf, 0, MS2ST(5));
}

void led_set(uint8_t index, uint8_t value)
{
    if (index > 15)
        return;
    uint8_t txbuf[2];
    uint8_t rxbuf[1];
    txbuf[0] = 0x02 + index;
    txbuf[1] = value;
    i2cMasterTransmitTimeout(&I2CD2, 0x60, txbuf, 2, rxbuf, 0, MS2ST(5));
}

void led_clear_all()
{
    for (int i = 0; i < 16; i++)
        led_set(i, 0);
}
