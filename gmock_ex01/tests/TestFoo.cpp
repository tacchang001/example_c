// https://stackoverflow.com/questions/31989040/can-gmock-be-used-for-stubbing-c-functions

#include "IBar.h"
#include "Foo.h"

#include <memory>
#include <iostream>
#include <utility>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "BarMock.h"

using namespace ::testing;
using ::testing::Return;

class FooTest : public ::testing::Test {
public:
    FooTest() : barMock{new BarMock} {
        auto ptr = std::unique_ptr<BarMock>(barMock);
        out.reset(new Foo(std::move(ptr)));
    }

    virtual void SetUp() {}
    virtual void TearDown() {}

    BarMock* barMock;
    std::unique_ptr<Foo> out;
};

TEST_F(FooTest, shouldDoItWhenDoSth) {
    // http://opencv.jp/googlemockdocs/cookbook.html
    barMock->DelegateToFake(); // 委譲先のフェイクを有効にします．

    EXPECT_CALL(*barMock, DoSth());

    out->DoIt();
}