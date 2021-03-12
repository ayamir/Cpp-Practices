#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U> class MagicType {
public:
  T dark;
  U magic;
};

template <typename T = int, typename U = int> auto add(T x, U y) {
  return x + y;
}

typedef int (*process)(void *);
using NewProcess = int (*)(void *);
template <typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main() {
  TrueDarkMagic<bool> you;
  auto res = add(1, 3);
  std::cout << res << std::endl;
}
