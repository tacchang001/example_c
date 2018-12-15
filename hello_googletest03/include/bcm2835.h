/*
 *
 */

#ifndef BCM2835_H
#define BCM2835_H

#include <stdint.h>

__BEGIN_DECLS

#define RPI_V2_GPIO_P1_18       10
#define BCM2835_GPIO_FSEL_OUTP  11

extern int bcm2835_init(void);
extern void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode);

__END_DECLS

#endif //BCM2835_H
