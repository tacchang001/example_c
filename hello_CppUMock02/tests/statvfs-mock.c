//
// Created by devel on 18/12/08.
//

#include <sys/statvfs.h>
#include "target.h"

#include "CppUTestExt/MockSupport_c.h"

int statvfs(const char *path, struct statvfs *buf) {
    // https://cpputest.github.io/mocking_manual.html
    // https://groups.google.com/forum/#!topic/cpputest/AmN6yMdnx4E
    // https://gist.github.com/davisford/3894730
    // https://github.com/cpputest/cpputest/issues/991

    mock_c()->actualCall("statvfs")
            ->withOutputParameterOfType("StatvfsBuf", "buf", buf);

    return mock_c()->intReturnValue();
}

