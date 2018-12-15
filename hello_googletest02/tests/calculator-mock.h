/*
 * 偽物計算機(Calculatorのモック）
 */

#ifndef CALCULATOR_MOCK_H
#define CALCULATOR_MOCK_H

#include "calculator.h"
#include <gmock/gmock.h>
using namespace std;

class MockCalculator : public Calculator
{
public:
    MOCK_METHOD2(add, int(int x, int y));
};

#endif //CALCULATOR_MOCK_H
