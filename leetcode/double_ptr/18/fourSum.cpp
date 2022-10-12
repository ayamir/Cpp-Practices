#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int goal = target - nums[i];
            int j = n - 1;
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    s.fourSum(nums, target);
    return 0;
}
