#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        if (n == 0) {
            return res;
        }
        int left = 0, right = n - 1;
        n = n - 1;
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare < rightSquare) {
                res[n--] = rightSquare;
                right--;
            } else {
                res[n--] = leftSquare;
                left++;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    for (const auto &num : s.sortedSquares(nums)) {
        cout << num << endl;
    }
    return 0;
}
