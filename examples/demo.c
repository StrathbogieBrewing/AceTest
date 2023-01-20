#include <stdio.h>
#include <stdlib.h>

#include "acetest.h"

ACETEST_FUNCTION(test_1) {
    ACETEST_ASSERT(1);
    ACETEST_ASSERT(1);
}

ACETEST_FUNCTION(test_2) {
    ACETEST_ASSERT(1);
    ACETEST_ASSERT(0);
}

/* Must define a call back function to log the test results */
void acetest_callback(const char *name, int line) {
    if (line < 0) {
        printf("ACETEST : fail in %s line %d\n", name, -line);
        exit(-1);
    } else {
        printf("ACETEST : pass in %s line %d\n", name, line);
    }
}

/* Process that runs the tests */
int main(int argc, char *argv[]) {
    ACETEST_RUN(test_1);
    ACETEST_RUN(test_2);

    return EXIT_SUCCESS;
}
