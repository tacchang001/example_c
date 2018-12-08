//
// Created by devel on 18/12/01.
//

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"
#include <sys/statvfs.h>
#include "target.h"

// テストグループを定義
TEST_GROUP(TestFuncGroup) {
    // 各テストケースの実行直前に呼ばれる仮想メソッド
    TEST_SETUP() {

    }

    // 各テストケースの実行直後に呼ばれる仮想メソッド
    TEST_TEARDOWN() {
        mock().checkExpectations();
        mock().removeAllComparatorsAndCopiers();
        mock().clear(); // Mock資源をクリア
    }
};

class StatvfsCopier : public MockNamedValueCopier
{
public:
    virtual void copy(void* out, const void* in)
    {
        struct statvfs *outp = (struct statvfs*)out;
        const struct statvfs *inp = (const struct statvfs*)in;
        outp->f_blocks = inp->f_blocks;
        outp->f_bavail = inp->f_bavail;
    }
};

// テストを実行するメソッド
TEST(TestFuncGroup, Test1)
{
    #define EXPECT_BLOCKS   12345
    #define EXPECT_BAVAIL   67890

    /* setup */
    StatvfsCopier copier;
    mock().installCopier("StatvfsBuf", copier);
    struct statvfs out;
    out.f_blocks = EXPECT_BLOCKS;
    out.f_bavail = EXPECT_BAVAIL;
    mock().expectOneCall("statvfs")
            .withOutputParameterOfTypeReturning("StatvfsBuf", "buf", &out)
            .andReturnValue(0);

    /* test */
    ulong ds = get_disk_space(".");
    CHECK_EQUAL(EXPECT_BLOCKS*EXPECT_BAVAIL, ds);
}

int main(int argc, char **argv) {
    // テストランナー
    return RUN_ALL_TESTS(argc, argv);
}
