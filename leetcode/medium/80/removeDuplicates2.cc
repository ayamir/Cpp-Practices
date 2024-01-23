#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicate2(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 5};
    int len = s.removeDuplicate2(nums);
    cout << len << endl;
    for (auto &&num : nums) {
        cout << num << endl;
    }
    return 0;
}
