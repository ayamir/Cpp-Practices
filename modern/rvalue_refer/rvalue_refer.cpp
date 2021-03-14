#include <iostream>
#include <string>
#include <vector>

class Foo {
  const char *&&right = "this is a rvalue";

public:
  void bar() { right = "still rvalue"; }
};

std::vector<int> foo() {
  std::vector<int> xvalue = {1, 2, 3, 4};
  return xvalue;
}

void reference(std::string &str) { std::cout << "left value: " << std::endl; }

// use && to realize right value reference
void reference(std::string &&str) { std::cout << "right value: " << std::endl; }

int main(int argc, char *argv[]) {
  const char *const &left = "this is a lvalue";

  // move implicitly
  auto v = foo();

  std::string lv1 = "string";
  // std::string &&r1 = lv1; error, right reference can't refer left value.
  // move explicitly to make left value be right value.
  std::string &&rv1 = std::move(lv1);

  std::cout << rv1 << std::endl; // string

  // constant reference prolong temp object life time.
  const std::string &lv2 = lv1 + lv1;
  // lv2 += "Test"; error, constant reference can't be modify.
  std::cout << lv2 << std::endl; // stringstring

  // right reference prolong temp object life time.
  std::string &&rv2 = lv1 + lv2;
  // non constant reference is modifiable.
  rv2 += "Test";
  std::cout << rv2 << std::endl; // stringstringstringTest

  // rv2 is a reference so still a left value.
  reference(rv2);
}
