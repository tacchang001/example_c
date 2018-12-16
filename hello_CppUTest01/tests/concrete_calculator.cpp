/*
 *
 */

#include <assert.h>
#include "concrete_calculator.h"

#include "CppUTestExt/MockSupport.h"

int ConcreteCalculator::add(const int x, const int y) {
    return mock().actualCall("add").withIntParameter("x", x).onObject(this).returnIntValue();
}