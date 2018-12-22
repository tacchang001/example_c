/*
 *
 */

#ifndef BAR_H
#define BAR_H

#include "IBar.h"

struct Bar : public IBar {
    void DoSth() override;
};

#endif //BAR_H
