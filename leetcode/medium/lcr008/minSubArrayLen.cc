#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

class Solution {
  public:
    int minSubArrayLenBrute(int s, vector<int> &nums) {
        int res = INT_MAX;
        int size = nums.size();
        int subLen = 0;
        for (int i = 0; i < size; i++) {
            int sum = 0;
            for (int j = i; j < size; j++) {
                sum += nums[j];
                if (sum >= s) {
                    subLen = j - i + 1;
                    res = subLen < res ? subLen : res;
                    break;
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }

    int minSubArrayLenSlideWindow(int target, vector<int> &nums) {
        int res = INT_MAX;
        int size = nums.size();
        int left = 0;
        int subLen = 0;
        int sum = 0;
        for (int right = 0; right < size; right++) {
            sum += nums[right];
            while (sum >= target) {
                subLen = right - left + 1;
                res = res < subLen ? res : subLen;
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int target = 12;
    vector<int> nums = {4, 6, 2, 4, 9, 8, 7};
    cout << s.minSubArrayLenSlideWindow(target, nums) << endl;
    return 0;
}
