#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int x = 0, votes = 0;
        for (const int num : nums) {
            if (votes == 0) {
                x = num;
            }
            votes += num == x ? 1 : -1;
        }
        return x;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {0, 1, 1, 2, 2, 2};
    cout << s.majorityElement(nums) << endl;
    return 0;
}
