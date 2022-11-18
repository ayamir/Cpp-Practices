#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        if (height.size() == 0) {
            return 0;
        }
        int res = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            int curr = h * w;
            if (curr > res) {
                res = curr;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }

    int maxAreaBrute(vector<int> &height) {
        if (height.size() == 0) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int h = min(height[i], height[j]);
                int w = j - i;
                int curr = h * w;
                if (curr > res) {
                    res = curr;
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    /* vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; */
    vector<int> height = {1, 1};
    int res = s.maxArea(height);
    std::cout << res << std::endl;
    return 0;
}
