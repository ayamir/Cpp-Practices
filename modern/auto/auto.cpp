#include <cstdio>
#include <iostream>
#include <string>
#include <type_traits>

template <typename T, typename U> auto add(T x, U y) { return x + y; }

std::string lookup1();
std::string lookup2();

decltype(auto) lookup_a_string_1() { return lookup1(); }
decltype(auto) lookup_a_string_2() { return lookup2(); }

void test(std::string &a, std::string &b) { printf("%d", 1); }

int main() {
    auto w = add<int, double>(1, 2.1);
    if (std::is_same<decltype(w), double>::value) {
        std::cout << "w is double" << std::endl;
    }
    std::cout << w << std::endl;
    std::string a = "a";
    std::string b = "b";
    test(a, b);
}
