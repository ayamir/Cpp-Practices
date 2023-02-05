#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int res = 0, pre = 0;      // pre[i] = pre[i-1] + nums[i]
        unordered_map<int, int> m; // key: pre, value: count
        m[0] = 1;
        for (auto &num : nums) {
            pre += num;
            // pre[j-1] == pre[i] - k
            if (m.find(pre - k) != m.end()) {
                res += m[pre - k];
            }
            m[pre]++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
