#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
  public:
    int longestOnes(vector<int> &nums, int k) {
        int size = nums.size();
        int left = 0, lsum = 0, rsum = 0;
        int res = 0;
        for (int right = 0; right < size; ++right) {
            rsum += 1 - nums[right];
            while (lsum < rsum - k) {
                lsum += 1 - nums[left];
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0,
                        1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << s.longestOnes(nums, 3);
    return 0;
}
