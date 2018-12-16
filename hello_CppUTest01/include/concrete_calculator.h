/*
 *
 */

#ifndef CONCRETE_CALCULATOR_H
#define CONCRETE_CALCULATOR_H

#include "calculator.h"

class ConcreteCalculator : public Calculator {
public:
    int add(const int x, const int y);
};

#endif //CONCRETE_CALCULATOR_H
