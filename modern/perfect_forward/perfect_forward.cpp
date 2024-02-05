#include <iostream>
#include <utility>

void reference(int &v) { std::cout << "左值引用" << std::endl; }

void reference(int &&v) { std::cout << "右值引用" << std::endl; }

template <typename T> void pass(T &&v) {
    std::cout << "             普通传参：";
    reference(v);
    std::cout << "       std::move 传参：";
    reference(std::move(v));
    std::cout << "    std::forward 传参：";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参：";
    reference(static_cast<T &&>(v));
}

int main(int argc, char *argv[]) {
    std::cout << "传递左值:" << std::endl;
    int l = 1;
    pass(l);

    std::cout << "传递右值:" << std::endl;
    pass(std::move(l));

    return 0;
}
