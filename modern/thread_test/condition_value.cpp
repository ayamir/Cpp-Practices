#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

int main() {
    std::queue<int> produced_nums;
    std::mutex mtx;
    std::condition_variable cv;
    // notification signal
    bool notified = false;

    auto producer = [&]() {
        for (int i = 0;; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(900));
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "producing" << i << std::endl;
            produced_nums.push(i);
            notified = true;
            cv.notify_all();
        }
    };

    auto consumer = [&]() {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            while (!notified) {
                cv.wait(lock);
            }

            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            lock.lock();
            while (!produced_nums.empty()) {
                std::cout << "consuming" << produced_nums.front() << std::endl;
                produced_nums.pop();
            }
        }
    };

    std::thread p(producer);
    std::thread cs[2];
    for (int i = 0; i < 2; i++) {
        cs[i] = std::thread(consumer);
    }
    p.join();
    for (int i = 0; i < 2; i++) {
        cs[i].join();
    }
    return 0;
}
