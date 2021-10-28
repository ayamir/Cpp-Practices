#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char *argv[]) {
  vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (int i = 10; i < 100; i++) {
    ivec.push_back(i);
  }

  for (const auto &ele : ivec) {
    std::cout << ele << " ";
  }

  return 0;
}
