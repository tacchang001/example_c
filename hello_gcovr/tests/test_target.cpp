#include "CppUTest/CommandLineTestRunner.h"
#include "IBar.h"

// テストグループを定義
TEST_GROUP(TestFuncGroup) {
    // 各テストケースの実行直前に呼ばれる仮想メソッド
    TEST_SETUP() {

    }

    // 各テストケースの実行直後に呼ばれる仮想メソッド
    TEST_TEARDOWN() {

    }
};

// テストを実行するメソッド
TEST(TestFuncGroup, Test1)
{
    int ans = target_function(1, 2);
    CHECK_EQUAL(3, ans);
}

int main(int argc, char **argv) {
    return RUN_ALL_TESTS(argc, argv);
}
