#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  void iter(vector<int> &nums) {
    for (auto &i : nums) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  vector<int> sortArray(vector<int> &nums) {
    srand((unsigned)time(NULL));
    int r = nums.size() - 1;
    quickSort(nums, 0, (int)r);
    return nums;
  }

private:
  void quickSort(vector<int> &nums, int p, int r) {
    if (p < r) {
      int q = random_partition(nums, p, r);
      quickSort(nums, p, q - 1);
      quickSort(nums, q + 1, r);
    }
    // no need to return
  }

  // random is must
  int random_partition(vector<int> &nums, int p, int r) {
    int i = rand() % (r - p + 1) + p;
    std::swap(nums[r], nums[i]);
    return partition(nums, p, r);
  }

  int partition(vector<int> &a, int p, int r) {
    int x = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; ++j) {
      if (a[j] <= x) {
        i += 1;
        std::swap(a[i], a[j]);
      }
    }
    std::swap(a[i + 1], a[r]);
    return i + 1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums = {5, 1, 1, 2, 0, 0};
  s.sortArray(nums);
  s.iter(nums);
  return 0;
}
