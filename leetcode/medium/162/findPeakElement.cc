#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        int l = -1, r = nums.size() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[m + 1]) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
