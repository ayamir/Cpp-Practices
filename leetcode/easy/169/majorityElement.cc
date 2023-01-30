#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        return majorityElementRecu(nums, 0, nums.size() - 1);
    }

    int majorityElementRecu(vector<int> &nums, int start, int end) {
        if (start == end)
            return nums[start];
        int mid = (start + end) / 2;
        int left = majorityElementRecu(nums, start, mid);
        int right = majorityElementRecu(nums, mid + 1, end);
        if (left == right)
            return left;
        return count(nums.begin() + start, nums.begin() + end + 1, left) >
                       count(nums.begin() + start, nums.begin() + end + 1,
                             right)
                   ? left
                   : right;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
