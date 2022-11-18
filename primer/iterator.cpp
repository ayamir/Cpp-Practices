#include <cctype>
#include <iostream>
#include <string>

using std::string;

int main(int argc, char *argv[]) {
    string str = "some string";
    if (str.begin() != str.end()) {
        auto it = str.begin();
        *it = std::toupper(*it);
    }
    for (auto b = str.begin(); b != str.end(); ++b) {
        std::cout << *b;
    }
    return 0;
}
