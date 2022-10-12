#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = len - 1;
            for (int k = i + 1; k < len; k++) {
                if (k > i + 1 && nums[k] == nums[k - 1]) {
                    continue;
                }
                while (k < j && nums[k] + nums[j] + nums[i] > 0) {
                    --j;
                }
                if (k == j) {
                    break;
                }
                if (nums[k] + nums[j] + nums[i] == 0) {
                    res.push_back({nums[i], nums[k], nums[j]});
                }
            }
        }

        return res;
    }
};

void iter(vector<vector<int>> nums) {
    for (auto vec : nums) {
        for (auto num : vec) {
            std::cout << num << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    iter(s.threeSum(nums));
    return 0;
}
