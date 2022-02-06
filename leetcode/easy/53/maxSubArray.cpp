#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArrayDP(vector<int> &nums) {
    // result = max_{0 ≤ i ≤ n-1} { f(i) }
    // f(i) = max{f(i-1) + nums[i], nums[i]}
    int prev = 0, res = nums[0];
    for (const auto &num : nums) {
      prev = max(prev + num, num);
      res = max(res, prev);
    }
    return res;
  }

  int maxSubArrayDC(vector<int> &nums) {
    return getMax(nums, 0, nums.size() - 1);
  }

  int getMax(vector<int> &nums, int left, int right) {
    if (left == right) {
      return nums[left];
    }
    int mid = (left + right) / 2;
    int lSum = getMax(nums, left, mid);
    int rSum = getMax(nums, mid + 1, right);
    int mSum = getCrossMax(nums, left, mid, right);
    return max(max(lSum, rSum), mSum);
  }

  int getCrossMax(vector<int> &nums, int left, int mid, int right) {
    int lSum = 0, rSum = 0, sum;

    sum = 0;
    for (int i = mid; i >= left; i--) {
      sum += nums[i];
      lSum = max(lSum, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
      sum += nums[i];
      rSum = max(rSum, sum);
    }

    return (lSum + rSum);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << s.maxSubArrayDP(test) << endl;
  cout << s.maxSubArrayDC(test) << endl;
  return 0;
}
