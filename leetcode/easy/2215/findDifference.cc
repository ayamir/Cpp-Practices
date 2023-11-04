#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> res(2, vector<int>());
        unordered_set<int> set1, set2;
        for (int value : nums1)
            set1.insert(value);
        for (int value : nums2)
            set2.insert(value);
        for (int value : set1) {
            if (!set2.count(value)) {
                res[0].push_back(value);
            }
        }
        for (int value : set2) {
            if (!set1.count(value)) {
                res[1].push_back(value);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
