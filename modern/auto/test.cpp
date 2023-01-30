#include "test.h"
#include <string>

void test(std::string &a, std::string &b) { printf("%d", 1); }

int main(int argc, char *argv[]) {
    std::string a = "a";
    std::string b = "b";
    test(a, b);
    Test::TestEnum testEnum = Test::test1;
    return 0;
}
