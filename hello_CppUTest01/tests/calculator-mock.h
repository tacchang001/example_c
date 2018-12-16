/*
 *
 */

#ifndef CALCULATOR_MOCK_H
#define CALCULATOR_MOCK_H

#include "CppUTestExt/MockSupport.h"

#include "calculator.h"

class CalculatorMock : public Calculator {
public:
    ~CalculatorMock() {}
    int add(const int x, const int y) {

        return mock().actualCall("add").withIntParameter("x", x).onObject(this).returnIntValue();
    }
};

#endif //CALCULATOR_MOCK_H
