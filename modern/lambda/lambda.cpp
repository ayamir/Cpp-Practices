#include <iostream>
#include <memory> // for make_unique

// value capture
void lambda_value_capture() {
    int value = 1;
    auto copy_value = [value] { return value; };
    value = 10;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
}

// reference capture
void lambda_reference_capture() {
    int value = 1;
    auto copy_value = [&value] { return value; };
    value = 10;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
}

int main() {
    lambda_value_capture();
    lambda_reference_capture();

    // expression capture
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 0, v2 = std::move(important)](int x, int y) -> int {
      *v2 = 10;
      return x + y + v1 + *(v2.get());
    };
    std::cout << add(0, 0) << std::endl;

    // generic lambda
    auto add2 = [](auto x, auto y) { return x + y; };
    std::cout << add2(1, 2) << std::endl;
    std::cout << add2(1.1, 2.2) << std::endl;

    // define lambda
    auto f = [](int value) { std::cout << value << std::endl; };
    // invoked by lambda
    f(1);

    return 0;
}
