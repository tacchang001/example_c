/*
 *
 */

#include "gtest/gtest.h"
#include "IBar.h"

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
    Addition addition;
    // 様々な Google Test アサーションを利用して値を検証
    EXPECT_EQ(expect, addition.add(x, y));
}

/*
 * テストフィクスチャ：複数のテストで同じデータ設定を使う
 *
 * 同じようなデータを扱うテストを複数書く場合は，テストフィクスチャを利用することができる。
 * これを使うと，異なるテストに対して同じオブジェクト設定を再利用できる。
 */
class AdditionTest02 : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test
        // (right before the destructor).
    }
};

TEST_F(AdditionTest02, twoValues) {
    const int x = 4;
    const int y = 5;
    const int expect = x + y;
    Addition addition;
    EXPECT_EQ(expect, addition.add(x, y));
}