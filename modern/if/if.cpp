#include <algorithm>
#include <iostream>
#include <ostream>
#include <type_traits>
#include <typeinfo>
#include <vector>

template <typename T> auto print_type_info(const T &t) {
    if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);

    if (itr != vec.end()) {
        *itr = 3;
    }

    if (const std::vector<int>::iterator itr =
            std::find(vec.begin(), vec.end(), 3);
        itr != vec.end()) {
        *itr = 4;
    }

    for (std::vector<int>::iterator element = vec.begin(); element != vec.end();
         ++element) {
        std::cout << *element << std::endl;
    }

    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}
