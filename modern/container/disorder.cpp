#include <iostream>
#include <map>
#include <string>
#include <unordered_map> // use hash, better performance

int main(int argc, char *argv[]) {
  std::unordered_map<int, std::string> u = {
      {1, "1"},
      {3, "3"},
      {2, "2"},
  };
  std::map<int, std::string> v = {
      {1, "1"},
      {3, "3"},
      {2, "2"},
  };

  std::cout << "std::unordered_map" << std::endl;
  for (const auto &n : u) {
    std::cout << "Key: [" << n.first << "] Value: [" << n.second << "]\n";
  }
  std::cout << std::endl;
  std::cout << "std::map" << std::endl;
  for (const auto &n : v) {
    std::cout << "Key: [" << n.first << "] Value: [" << n.second << "]\n";
  }
}
