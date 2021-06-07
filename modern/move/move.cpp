#include <iostream>
#include <string>
#include <utility> // std::move
#include <vector>

class A {
public:
  int *pointer;
  A() : pointer(new int(1)) { std::cout << "构造" << pointer << std::endl; }
  A(A &a) : pointer(new int(*a.pointer)) {
    std::cout << "拷贝" << pointer << std::endl;
  }
  A(A &&a) : pointer(a.pointer) {
    a.pointer = nullptr;
    std::cout << "移动" << pointer << std::endl;
  }
  ~A() {
    std::cout << "析构" << pointer << std::endl;
    delete pointer;
  }
};

A return_rvalue(bool test) {
  A a, b;
  if (test)
    return a;
  else
    return b;
}

int main() {
  A obj = return_rvalue(false);
  std::cout << "obj:" << std::endl;
  std::cout << obj.pointer << std::endl;
  std::cout << *obj.pointer << std::endl;

  std::string str = "Hello, world";
  std::vector<std::string> v;
  // push_back(const T&) copy
  v.push_back(str);
  std::cout << "str: " << str << std::endl;
  // push_back(const T&&) move, so str's content is empty.
  v.push_back(std::move(str));
  std::cout << "str: " << str << std::endl;

  return 0;
}
