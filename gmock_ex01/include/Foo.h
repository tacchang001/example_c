/*
 *
 */

#ifndef FOO_H
#define FOO_H

#include <memory>
#include <iostream>
#include <utility>

#include "IBar.h"

struct Foo {
    Foo(std::unique_ptr<IBar> bar);

    void DoIt();
private:
    std::unique_ptr<IBar> bar;
};

#endif //FOO_H
