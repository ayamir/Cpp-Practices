#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int binarySearch(vector<int> nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        if (target < nums[lo] || target > nums[n]) {
            return -1;
        }
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (target < nums[mid]) {
                hi = mid;
            } else if (target > nums[mid]) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << s.binarySearch(nums, target);
    return 0;
}
