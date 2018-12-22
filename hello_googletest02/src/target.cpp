/*
 *
 */

#include "IBar.h"

Addition::Addition(Calculator *aCalc) {
    calc = aCalc;
}

int Addition::add(const int a, const int b) {
    return calc->add(a, b);
}