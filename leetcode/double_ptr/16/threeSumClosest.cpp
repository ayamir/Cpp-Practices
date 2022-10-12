#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = 0;
        int min = 1e7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = n - 1, k = i + 1;
            while (k < j) {
                int curr = nums[i] + nums[k] + nums[j];
                if (curr == target) {
                    return target;
                }
                int dist = abs(curr - target);
                if (dist < min) {
                    min = dist;
                    res = curr;
                }
                if (curr < target) {
                    int k0 = k + 1;
                    while (k0 < j && nums[k0] == nums[k]) {
                        ++k0;
                    }
                    k = k0;
                } else {
                    int j0 = j - 1;
                    while (k < j0 && nums[j0] == nums[j]) {
                        --j0;
                    }
                    j = j0;
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {-1, 2, 1, 4};
    int target = 1;
    int res = s.threeSumClosest(nums, target);
    std::cout << res << std::endl;
    return 0;
}
