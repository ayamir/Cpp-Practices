#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxOperations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left < right) {
            int leftValue = nums[left];
            int rightValue = nums[right];
            if (k == leftValue + rightValue) {
                res++;
                left++;
                right--;
            } else if (k > leftValue + rightValue) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {3, 1, 3, 4, 3};
    cout << s.maxOperations(nums, 6);
    return 0;
}
