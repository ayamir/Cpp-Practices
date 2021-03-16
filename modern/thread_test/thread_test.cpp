#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void critical_section(int change_v) {
  static std::mutex mtx;
  std::unique_lock<std::mutex> lock(mtx);

  v = change_v;
  std::cout << v << std::endl;

  lock.unlock();

  lock.lock();
  v += 1;
  std::cout << v << std::endl;
}

int main(int argc, char *argv[]) {
  std::thread t1(critical_section, 2), t2(critical_section, 3);
  t1.join();
  t2.join();

  std::cout << v << std::endl;

  return 0;
}
