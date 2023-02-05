#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        vector<int> leftMin(n, 0);
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }
        vector<int> rightMax(n, 0);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }
        for (int i = 1; i < n - 1; i++) {
            if (leftMin[i] < nums[i] && nums[i] < rightMax[i])
                return true;
        }
        return false;
    }

    bool increasingTriplet2(vector<int> &nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= min1) {
                min1 = nums[i];
            } else if (nums[i] <= min2) {
                min2 = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1};
    cout << s.increasingTriplet(nums) << endl;
    return 0;
}
