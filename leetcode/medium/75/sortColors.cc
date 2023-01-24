#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int redIndex = 0, whiteIndex = 0, blueIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                nums[blueIndex++] = 2;
                nums[whiteIndex++] = 1;
                nums[redIndex++] = 0;
            } else if (nums[i] == 1) {
                nums[blueIndex++] = 2;
                nums[whiteIndex++] = 1;
            } else {
                nums[blueIndex++] = 2;
            }
        }
    }

    void sortColorsSinglePtr(vector<int> &nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr++]);
            }
        }
        for (int i = ptr; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr++]);
            }
        }
    }

    void sortColorsDoublePtr(vector<int> &nums) {
        int n = nums.size();
        int ptr1 = 0, ptr2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr2++]);
            } else if (nums[i] == 0) {
                swap(nums[i], nums[ptr1++]);
                if (ptr1 < ptr2) {
                    swap(nums[i], nums[ptr2]);
                }
                ++ptr2;
            }
        }
    }

    void sortColorsDoublePtr2(vector<int> &nums) {
        int n = nums.size();
        int ptr1 = 0, ptr2 = n - 1;
        for (int i = 0; i <= ptr2; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr1++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[ptr2--]);
                --i;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColorsDoublePtr2(nums);
    for (auto n : nums) {
        cout << n << " ";
    }
    return 0;
}
