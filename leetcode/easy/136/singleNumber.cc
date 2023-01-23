#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (auto v : nums) {
            res ^= v;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
