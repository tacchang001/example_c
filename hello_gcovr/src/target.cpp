#include "target.h"

int target_function(const int a, const int b)
{
    int ans = -1;

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