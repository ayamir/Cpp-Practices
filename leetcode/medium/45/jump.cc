#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int jump(vector<int> &nums) {
        int res = 0;
        int start = 0;
        int end = 1;
        while (end < nums.size()) {
            int maxPos = 0;
            for (int i = start; i < end; i++) {
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end;
            end = maxPos + 1;
            res++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.jump(nums) << endl;
    return 0;
}
