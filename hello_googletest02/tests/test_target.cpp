/*
 *
 */

#include "gtest/gtest.h"
#include "target.h"
#include "calculator-mock.h"
using namespace testing;

/*
 * 簡単なテスト
 *
 * TEST() マクロを利用してテスト関数を定義し，名前を付け
 */
TEST(
        AdditionTest01, // テストケースの名前
        twoValues)      // テストケースに含まれるテストの名前。アンダースコアは禁止
{
    const int x = 4;
    const int y = 5;
    const int expect = x + y;

    MockCalculator calc;
    EXPECT_CALL(calc, add(x, y))
            .Times(AtLeast(1))
            .WillOnce(Return(expect));

    Addition addition(&calc);
    // 様々な Google Test アサーションを利用して値を検証
    EXPECT_EQ(expect, addition.add(x, y));
}
