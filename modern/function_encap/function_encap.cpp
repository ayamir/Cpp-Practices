#include <functional>
#include <iostream>

// define function type
using foo = void(int);
// foo -> foo*
void functional(foo f) {
  f(1); // invoked by function pointer
}

// functional encapsulation
int fooFunction(int para) { return para; }

void print_num(int i) { std::cout << i << std::endl; }

int fooBind(int a, int b, int c) { return a + b + c; }

int main() {

  // define lambda
  auto f = [](int value) { std::cout << value << std::endl; };
  // pass closure object
  functional(f);

  // encapsulate a function which return value is int and argument is int.
  std::function<int(int)> func = fooFunction;
  int importentValue = 10;
  // & for auto capture importentValue
  std::function<int(int)> func2 = [&](int value) -> int {
    return 1 + value + importentValue;
  };
  std::cout << func(10) << std::endl;
  std::cout << func2(10) << std::endl;

  // encapsulate print_num in line 33.
  std::function<void(int)> f_display = print_num;
  f_display(-9);

  // use bind to bind arguments' value by sort in advance.
  // use placeholders::_1 to reserve the first argument's place.
  auto bindFoo = std::bind(fooBind, std::placeholders::_1, 1, 2);
  std::cout << bindFoo(1) << std::endl;

  return 0;
}
