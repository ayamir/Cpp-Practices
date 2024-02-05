#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int low = i;
            i++;
            while (i < n && nums[i] - nums[i - 1] == 1) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp += "->";
                temp += to_string(nums[high]);
            }
            res.emplace_back(std::move(temp));
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    for (const auto &str : s.summaryRanges(nums)) {
        cout << str << endl;
    }
    return 0;
}
