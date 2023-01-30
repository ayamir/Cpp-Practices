#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

int main() {
    // relaxed model
    // single thread instructions are sequential
    // different threads instructions are random
    std::atomic<int> counter = {0};
    std::vector<std::thread> vt;
    for (int i = 0; i < 100l; i++) {
        vt.emplace_back(
            [&]() { counter.fetch_add(1, std::memory_order_relaxed); });
    }

    for (auto &t : vt) {
        t.join();
    }
    std::cout << "current counter: " << counter << std::endl;

    // release/consume model
    // Different threads instructions'sequence which have dependencies will be
    // limited.
    std::atomic<int *> ptr(nullptr);
    int v;
    std::thread producer([&]() {
        int *p = new int(42);
        v = 1024;
        ptr.store(p, std::memory_order_release);
    });
    std::thread consumer([&]() {
        int *p;
        while (!(p = ptr.load(std::memory_order_consume)))
            ;
        std::cout << "p: " << *p << std::endl;
        std::cout << "v: " << v << std::endl;
    });
    producer.join();
    consumer.join();

    // release/acquire model
    std::vector<int> vec;
    std::atomic<int> flag = {0};
    std::thread release([&]() {
        vec.push_back(42);
        flag.store(1, std::memory_order_release);
    });
    std::thread acqrel([&]() {
        // must before compare_exchange_strong
        int expected = 1;
        while (
            // compare_exchange_strong is Compare-and-swap primitive
            !flag.compare_exchange_strong(expected, 2,
                                          std::memory_order_acq_rel)) {
            // must after compare_exchange_strong
            expected = 1;
            // flag has changed to 2
        }
    });
    std::thread acquire([&]() {
        while (flag.load(std::memory_order_acquire) < 2)
            ;
        // must be 42
        std::cout << vec.at(0) << std::endl;
    });
    release.join();
    acqrel.join();
    acquire.join();

    // consistency model
    std::atomic<int> counter2 = {0};
    std::vector<std::thread> vt2;
    for (int i = 0; i < 100; i++) {
        vt2.emplace_back([&]() {
            // strict consistency limit, may lower performance
            counter2.fetch_add(1, std::memory_order_acq_rel);
        });
    }

    for (auto &t : vt2) {
        t.join();
    }
    std::cout << "current counter2: " << counter2 << std::endl;
}
