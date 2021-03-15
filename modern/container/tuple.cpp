#include <cstddef>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <variant>

// runtime index need to handle out of range manually
template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...> &tp1,
                                          size_t i) {
  if constexpr (n >= sizeof...(T)) {
    throw std::out_of_range("out of range");
  }
  if (i == n)
    return _tuple_index<(n < sizeof...(T) - 1 ? n + 1 : 0)>(tp1, i);
  return _tuple_index<(n < sizeof...(T) - 1 ? n + 1 : 0)>(tp1, i);
}

template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...> &tp1,
                                         size_t i) {
  return _tuple_index<0>(tp1, i);
}

template <typename T0, typename... Ts>
std::ostream &operator<<(std::ostream &s, std::variant<T0, Ts...> const &v) {
  std::visit([&](auto &&x) { s << x; }, v);
  return s;
}

template <typename T> auto tuple_len(T &tuple) {
  return std::tuple_size<T>::value;
}

auto get_student(int id) {
  if (id == 0) {
    return std::make_tuple(3.8, 'A', "张三");
  }
  if (id == 1) {
    return std::make_tuple(2.9, 'C', "李四");
  }
  if (id == 2) {
    return std::make_tuple(1.7, 'D', "王五");
  }

  return std::make_tuple(0.0, 'D', "null");
}

int main() {
  // std::get use a compiling time value.
  auto student = get_student(0);
  std::cout << "ID: 0, "
            << "GPA: " << std::get<0>(student) << ", "
            << "成绩: " << std::get<1>(student) << ", "
            << "姓名: " << std::get<2>(student) << '\n';

  double gpa;
  char grade;
  std::string name;

  std::tie(gpa, grade, name) = get_student(1);
  std::cout << "ID: 1, "
            << "GPA: " << gpa << ", "
            << "成绩: " << grade << ", "
            << "姓名: " << name << '\n';

  std::tuple<std::string, double, double, int> t{"123", 4.5, 6.7, 8};
  std::cout << std::get<std::string>(t) << std::endl;
  // std::cout << std::get<double>(t) << std::endl; error: ambiguous invoke
  std::cout << std::get<3>(t) << std::endl;

  // merge two tuple
  auto new_tuple = std::tuple_cat(get_student(1), std::move(t));

  for (int i = 0; i != tuple_len(new_tuple); ++i) {
    std::cout << tuple_index(new_tuple, i) << std::endl;
  }
}
