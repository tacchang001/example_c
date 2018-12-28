#include "target.h"

int c_function(const int a, const int b)
{
    int ans = -1;

    /*
     * C0 : 命令網羅。それぞれの命令文が少なくとも１回は実行される
     * C1 : 分岐網羅。それぞれの判定条件における真偽が少なくとも１回は実行される
     * C2 : 条件網羅。それぞれの条件文における真偽が少なくとも１回は実行される
     */
    if ((a < 0) || (a > 100)) {
        ans = a + b;
    } else {
        if ((b < 0) || (b > 100)) {
            ans = a - b;
        } else {
            ans = a + b;
        }
    }

    return ans;
}