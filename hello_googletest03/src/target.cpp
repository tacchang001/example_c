/*
 *
 */

#include "target.h"

int inits(void){
    return bcm2835_init();
}

void pinMode(uint8_t pin, uint8_t mode){
    bcm2835_gpio_fsel(pin, mode);
}