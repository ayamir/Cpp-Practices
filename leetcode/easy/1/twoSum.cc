#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    vector<int> twoSumHashMap(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {it->second, i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {2, 3, 4};
    int target = 6;
    auto res = s.twoSumHashMap(nums, target);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}
