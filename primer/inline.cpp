#include <iostream>
#include <string>

using std::string;

inline auto shorter_string(const string &s1, const string &s2)
    -> const string & {
    return s1.size() <= s2.size() ? s1 : s2;
}

inline auto longer_string(const string &s1, const string &s2)
    -> const string & {
    return s1.size() >= s2.size() ? s1 : s2;
}

constexpr int new_int() {
    const int i = 100;
    return i;
}

constexpr size_t scale(size_t cnt) { return new_int() * cnt; }

int main(int argc, char *argv[]) {
    string s1{"Hello"};
    string s2{"Hello world!"};

    std::cout << shorter_string(s1, s2) << std::endl;
    std::cout << longer_string(s1, s2) << std::endl;

    std::cout << new_int() << " " << scale(10) << std::endl;

    return 0;
}
