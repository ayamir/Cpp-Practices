#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> count = {0};

struct C {
    float x;
    int y;
    long long z;
};

int main() {
    int a = 0;
    int flag = 0;

    std::thread t1([&]() {
        while (flag != 1) {
            int b = a;
            // will not be executed probably
            std::cout << "b = " << b << std::endl;
        }
    });

    std::thread t2([&]() {
        // this command may be executed later than the next command.
        a = 5;
        flag = 1;
    });

    t1.join();
    t2.join();

    std::thread t3([&]() { count.fetch_add(1); });
    std::thread t4([&]() {
        // equal to fetch_add
        count++;
        // equal to fetch_add
        count += 1;
    });
    t3.join();
    t4.join();

    std::cout << count << std::endl;

    std::atomic<C> c;
    // use is_lock_free to check if C can provide atomic operation
    std::cout << std::boolalpha << c.is_lock_free() << std::endl;

    return 0;
}
