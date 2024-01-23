#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(nums, 3);
    for (const int num : nums) {
        cout << num << " ";
    }
    return 0;
}
