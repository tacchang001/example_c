//
// Created by devel on 18/12/01.
//

#include <sys/statvfs.h>
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"
#include "target.h"

// テストグループを定義
TEST_GROUP(TestFuncGroup) {
    // 各テストケースの実行直前に呼ばれる仮想メソッド
    TEST_SETUP() {

    }

    // 各テストケースの実行直後に呼ばれる仮想メソッド
    TEST_TEARDOWN() {
        mock().clear(); // Mock資源をクリア
    }
};

int statvfs(const char *path, struct statvfs *buf) {

    mock().actualCall("statvfs");

    buf->f_blocks = 1;
    buf->f_bavail = 10;

    return 0;
}

// テストを実行するメソッド
TEST(TestFuncGroup, Test1)
{
    mock().expectOneCall("statvfs");
    ulong ds = get_disk_space(".");
    CHECK_EQUAL(10, ds);
}

int main(int argc, char **argv) {
    // テストランナー
    return RUN_ALL_TESTS(argc, argv);
}
