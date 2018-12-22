/*
 *
 */

#ifndef BARMOCK_H
#define BARMOCK_H

#include "IBar.h"
#include "FakeBar.h"

#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::_;
using ::testing::Invoke;

struct BarMock: public IBar {
    MOCK_METHOD0(DoSth, void());

    // http://opencv.jp/googlemockdocs/cookbook.html
    void DelegateToFake() {
        ON_CALL(*this, DoSth())
                .WillByDefault(Invoke(&fake_, &FakeBar::DoSth));
    }
private:
    FakeBar fake_;
};

#endif //BARMOCK_H
