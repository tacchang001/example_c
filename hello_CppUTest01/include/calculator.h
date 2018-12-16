/*
 * 計算機 抽象型
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    virtual int add(const int x, const int y) = 0;
    virtual ~Calculator() {}
};

#endif //CALCULATOR_H
