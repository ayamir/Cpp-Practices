#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
    bool containsDuplicate2(vector<int> &nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}
