#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution {
  private:
    int lsum = 0;
    int rsum = 0;

  public:
    int pivotIndex(vector<int> &nums) {
        int size = nums.size();
        if (size == 0) {
            return -1;
        }
        for (int i = 0; i < size; ++i) {
            lsum += nums[i];
        }
        for (int i = 0; i < size; ++i) {
            lsum -= nums[i];
            if (lsum == rsum) {
                return i;
            }
            rsum += nums[i];
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
