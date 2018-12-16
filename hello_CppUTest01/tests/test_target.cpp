/*
 *
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"
#include "target.h"
#include "calculator-mock.h"

TEST_GROUP(TestFuncGroup) {
    TEST_SETUP() {

    }

    TEST_TEARDOWN() {
        mock().clear(); // Mock資源をクリア
    }
};

TEST(TestFuncGroup, Test1)
{
    const int a = 1;
    const int b = 2;
    const int expect = a + b;

    Calculator *calc = new CalculatorMock();

    mock().expectOneCall("add").withIntParameter("x", a).onObject(calc).andReturnValue(expect);
    Addition adder;
    CHECK_EQUAL(expect, adder.add(a, b));
    mock().checkExpectations();

    delete calc;
}

int main(int argc, char **argv) {
    // テストランナー
    return RUN_ALL_TESTS(argc, argv);
}
