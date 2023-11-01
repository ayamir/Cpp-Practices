#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int size = nums.size();
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = sum;
        for (int i = k; i < size; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    cout << s.findMaxAverage(nums, 4);
    return 0;
}
