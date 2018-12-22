/*  Test target
 */

#ifndef TARGET_H
#define TARGET_H

#include<memory>
#include<iostream>
#include<utility>

struct IBar {
    virtual ~IBar() = default;
    virtual void DoSth() = 0;
};

#endif //TARGET_H
