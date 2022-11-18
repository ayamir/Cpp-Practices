#include <cctype>
#include <iostream>
#include <string>

using std::string;
int main(int argc, char *argv[]) {
    string a{"abc"};
    string a1(a);
    string a2 = "abc";
    string a3 = a2;
    std::cout << a << a1 << std::endl;

    /* string word; */
    /* while (std::cin >> word) { */
    /*   std::cout << word << std::endl; */
    /* } */

    string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            std::cout << line << "'s length = " << line.length() << std::endl;
            std::cout << line << "'s size = " << line.size() << std::endl;
            auto size = line.size();
            std::cout << typeid(size).name() << std::endl;
            auto len = line.length();
            std::cout << typeid(len).name() << std::endl;
        } else {
            std::cout << "Empty string, quit..." << std::endl;
            break;
        }
    }

    string s1 = "hello";
    string s2 = "world";
    // 正确，+左右两边的至少有一个是string
    string s3 = s1 + "!" + "\n";
    // 错误，+左右两边的都是字面量
    /* string s4 = ", " + "\n" + s2; */

    string str{"hello string!!!"};
    decltype(str.size()) punct_cnt = 0;
    for (auto c : str) {
        if (std::ispunct(c)) {
            punct_cnt++;
        }
    }
    std::cout << punct_cnt << " punctuation char in " << str << std::endl;
    for (auto &c : str) {
        c = std::toupper(c);
    }
    std::cout << str << std::endl;

    return 0;
}
