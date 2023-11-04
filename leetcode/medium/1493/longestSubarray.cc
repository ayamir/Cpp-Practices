#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &nums) {
        int size = nums.size();
        int left = 0, right = 0, zeroCnt = 0;
        while (right < size) {
            if (nums[right] == 0) {
                ++zeroCnt;
            }
            ++right;
            if (zeroCnt > 1) {
                if (nums[left] == 0) {
                    --zeroCnt;
                }
                ++left;
            }
        }
        return right - left - 1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
