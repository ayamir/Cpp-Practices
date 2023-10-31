#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int size = nums.size();
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < size; fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }

    void iter(vector<int> &nums) {
        for (auto num : nums) {
            std::cout << num << std::endl;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    auto i = s.removeElement(nums, 3);
    std::cout << i << std::endl;
    s.iter(nums);

    return 0;
}
