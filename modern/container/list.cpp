#include <algorithm>
#include <array>
#include <forward_list> // Single direction link list
#include <iostream>
#include <list> // Double directions link list

void foo(int *p, int len) { return; }

int main(int argc, char *argv[]) {
  std::array<int, 4> arr = {1, 10, 5, 4};
  std::cout << arr.empty() << std::endl;
  std::cout << arr.size() << std::endl;

  std::sort(arr.begin(), arr.end(), [](int a, int b) { return a < b; });
  for (auto i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  constexpr int len = 4;
  std::array<int, len> arr2 = {4, 3, 2, 1};

  // Be compatible with C style functions
  foo(&arr2[0], arr.size());
  foo(arr2.data(), arr2.size());

  std::sort(arr2.begin(), arr2.end());
  for (auto i : arr2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::list<int> list1 = {1, 2, 3, 4, 5};
  std::forward_list<int> forward = {4, 1, 3, 2, 5};
  forward.sort();
  for (auto i : forward) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
