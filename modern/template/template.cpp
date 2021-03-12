#include <initializer_list>
#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T, typename U> class MagicType {
public:
  T dark;
  U magic;
};

// 类型模板参数推导
template <typename T = int, typename U = int> auto add(T x, U y) {
  return x + y;
}

typedef int (*process)(void *);
using NewProcess = int (*)(void *);
template <typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

// 变长参数模版
template <typename Require, typename... Ts> class Magic;

template <typename... Ts> void magic(Ts... args) {
  std::cout << sizeof...(args) << std::endl;
}

// 递归模版参数
template <typename T0> void printf1(T0 value) {
  std::cout << value << std::endl;
}

template <typename T, typename... Ts> void printf1(T value, Ts... args) {
  std::cout << value << std::endl;
  printf1(args...);
}

// 变参模版展开
template <typename T0, typename... T> void printf2(T0 t0, T... t) {
  std::cout << t0 << std::endl;
  if constexpr (sizeof...(t) > 0)
    printf2(t...);
}

// 初始化列表展开
template <typename T, typename... Ts> auto printf3(T value, Ts... args) {
  std::cout << value << std::endl;
  (void)std::initializer_list<T>{
      ([&args] { std::cout << args << std::endl; }(), value)...};
}

// 折叠表达式
template <typename... T> auto sum(T... t) { return (t + ...); }

// 非类型模版参数推导
template <typename T, int BufSize> class buffer_t {
public:
  T &alloc();
  void free(T &item);

private:
  T data[BufSize];
};

// 类型推导模版参数 C++2a above support
template <auto value> void foo() {
  std::cout << value << std::endl;
  return;
}

int main() {
  TrueDarkMagic<bool> you;
  auto res = add(1, 3);
  std::cout << res << std::endl;

  magic();
  std::cout << std::endl;
  magic(1);
  std::cout << std::endl;
  magic(1, "", 1.2);
  std::cout << std::endl;

  printf1(1, 2, "123", 1.1);
  std::cout << std::endl;
  printf2(1, 2, "123", 1.1);
  std::cout << std::endl;
  printf3(1, 2, "123", 1.1);
  std::cout << std::endl;

  std::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;

  buffer_t<int, 100> buf;

  foo<10>();

  return 0;
}
