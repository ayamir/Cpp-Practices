#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        int res = INT_MAX;
        int start = 0, end = 0;
        int sum = nums[start];
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                res = min(res, end - start + 1);
                sum -= nums[start++];
            }
            end++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << s.minSubArrayLen(target, nums);
    return 0;
}
