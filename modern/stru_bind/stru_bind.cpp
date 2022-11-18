#include <hash_map>
#include <iostream>
#include <map>
#include <tuple>

std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value> &m, F foo) {}

int main() {
    auto [x, y, z] = f();
    std::cout << x << ", " << y << ", " << z << std::endl;

    std::map<std::string, long long int> m{
        {"a", 1},
        {"b", 2},
        {"c", 3},
    };
    update(m, [](std::string key) { return std::hash<std::string>{}(key); });
    for (auto &&[key, value] : m) {
        std::cout << key << ":" << value << std::endl;
    }

    return 0;
}
