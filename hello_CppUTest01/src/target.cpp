/*
 *
 */

#include "IBar.h"
#include "concrete_calculator.h"

int Addition::add(const int a, const int b) {
    ConcreteCalculator calc; // モックにできない。いい方法はないか？
    return calc.add(a, b);
}