/*
 *
 */

#ifndef FAKEBAR_H
#define FAKEBAR_H

#include "IBar.h"

#include <iostream>
using namespace std;

class FakeBar : public IBar {
public:
    void DoSth() {
        std::cout <<"+++ FakeBar is doing sth +++" << std::endl;
    }
};

#endif //FAKEBAR_H
