#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        for (int j = 1; j < nums.size();) {
            if (nums[i] == nums[j]) {
                nums.erase(nums.begin() + j);
            } else {
                i++;
                j++;
            }
        }
        return nums.size();
    }

    int removeDuplicatesLC(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 5, 6, 7, 7, 7, 8, 9, 10, 10};
    int k = s.removeDuplicatesLC(nums);
    std::cout << k << std::endl;
    return 0;
}
