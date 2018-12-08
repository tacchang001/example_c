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

#define EXPECT_BLOCKS   12345
#define EXPECT_BAVAIL   67890

int statvfs(const char *path, struct statvfs *buf) {

    mock().actualCall("statvfs");

    buf->f_blocks = EXPECT_BLOCKS;
    buf->f_bavail = EXPECT_BAVAIL;

    return 0;
}

// テストを実行するメソッド
TEST(TestFuncGroup, Test1)
{
    mock().expectOneCall("statvfs");
    ulong ds = get_disk_space(".");
    CHECK_EQUAL(EXPECT_BLOCKS*EXPECT_BAVAIL, ds);
}

int main(int argc, char **argv) {
    // テストランナー
    return RUN_ALL_TESTS(argc, argv);
}
