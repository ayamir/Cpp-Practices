#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    bool containsNearbyDuplicates(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                int prev = hash[nums[i]];
                if (abs(i - prev) <= k) {
                    return true;
                }
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
