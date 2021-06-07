#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  static int findKthLargest(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  std::cout << Solution::findKthLargest(nums, 4) << std::endl;
  return 0;
}
