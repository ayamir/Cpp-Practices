#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (val != nums[fast]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    int val = 2;
    cout << s.removeElement(nums, val) << endl;
    for (const auto &e : nums) {
        cout << e << " ";
    }
    return 0;
}
