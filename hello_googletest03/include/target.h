/*  Test target
 */

#ifndef TARGET_H
#define TARGET_H

#include "bcm2835.h"

__BEGIN_DECLS

extern int inits(void);
extern void pinMode(uint8_t pin, uint8_t mode);

__END_DECLS

#endif //TARGET_H
