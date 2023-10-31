#include <bits/stdc++.h>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int size = nums.size();
        int left = 0, right = 0;
        while (right < size) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }

    void iter(const vector<int> &nums) {
        for (auto value : nums) {
            cout << value << " ";
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {0, 0, 1};
    s.moveZeroes(nums);
    s.iter(nums);
    return 0;
}
