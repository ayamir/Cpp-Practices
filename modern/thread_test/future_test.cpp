#include <future>
#include <iostream>
#include <thread>

int main() {
  // encapsulate a lambda which return 7
  // std::packaged_task 's argument is function type will be encapsulated
  std::packaged_task<int()> task([]() { return 7; });
  // get task's future
  std::future<int> result = task.get_future();
  std::thread(std::move(task)).detach();
  std::cout << "waiting ...";
  result.wait();

  std::cout << "done! " << std::endl
            << "future result is " << result.get() << std::endl;

  return 0;
}
