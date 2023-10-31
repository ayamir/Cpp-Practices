#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int res = INT_MIN;
        int size = height.size();
        int left = 0, right = size - 1;
        while (right > left) {
            int w = right - left;
            int h = min(height[left], height[right]);
            int currArea = w * h;
            res = res < currArea ? currArea : res;
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return res == INT_MIN ? 0 : res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(height) << endl;
    return 0;
}
