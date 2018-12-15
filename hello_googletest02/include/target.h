/*  Test target
 */

#ifndef TARGET_H
#define TARGET_H

#include "calculator.h"

class Addition {
public:
    Addition(Calculator *aCalc);
    int add(const int a, const int b);
private:
    Calculator *calc;
};

#endif //TARGET_H
