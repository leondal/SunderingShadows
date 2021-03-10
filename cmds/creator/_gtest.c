#include <std.h>

int x = 0;

int cmd_gtest(string str) {

    x += 1;
    tell_object(TP, "The test result is "+x);
    return 1;
}
