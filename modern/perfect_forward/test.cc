#include <iostream>
#include <utility>

using namespace std;

struct TestForward {
  int a;
  float b;
  TestForward(int a, float b) : a(a), b(b) {}
  TestForward(TestForward &testForward) { cout << "Copy" << endl; }
  TestForward(const TestForward &testForward) { cout << "Copy Const" << endl; }
  TestForward(TestForward &&testForward) { cout << "Move" << endl; }
  TestForward(const TestForward &&testForward) { cout << "Move Const" << endl; }
};

// template <typename T> void test1(T &&nums) {
//   auto new_nums{std::forward<T>(nums)};
//   return;
// }
// template <typename T> void test1(const T &&nums) {
//   auto new_nums{std::forward<const T>(nums)};
//   return;
// }

void test1(TestForward nums) {
  auto new_nums = std::move(nums);
  return;
}

int main(int argc, char *argv[]) {
  TestForward testForward{10, 1.0};
  test1(testForward);
  test1(std::move(testForward));
  // test1(const_cast<const TestForward &>(testForward));
  // test1(const_cast<const TestForward &&>(std::move(testForward)));
  return 0;
}
