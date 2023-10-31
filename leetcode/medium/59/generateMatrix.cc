#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    // 6ms
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startX = 0, startY = 0;
        int loop = n / 2;
        int mid = n / 2;
        int cnt = 1;
        int offset = 1;
        int i, j;
        while (loop-- != 0) {
            i = startX;
            j = startY;
            for (j = startY; j < n - offset; j++) {
                res[i][j] = cnt++;
            }
            for (i = startX; i < n - offset; i++) {
                res[i][j] = cnt++;
            }
            for (; j > startY; j--) {
                res[i][j] = cnt++;
            }
            for (; i > startX; i--) {
                res[i][j] = cnt++;
            }
            startX++;
            startY++;

            offset += 1;
        }
        if (n % 2 == 1) {
            res[mid][mid] = cnt;
        }
        return res;
    }

    vector<vector<int>> generateMatrixOpt(int n) {
        vector<vector<int>> nums(n, vector<int>(n, 0));
        for (int i = 0, j = 0, num = 1; num <= n * n;) {
            // first line from left to right
            while (j < n && nums[i][j] == 0) {
                nums[i][j++] = num++;
            }
            i++, j--;
            // last column from up to down
            while (i < n && nums[i][j] == 0) {
                nums[i++][j] = num++;
            }
            i--, j--;
            // last line from right to left
            while (j >= 0 && nums[i][j] == 0) {
                nums[i][j--] = num++;
            }
            i--, j++;
            // first column from down to up
            while (i >= 0 && nums[i][j] == 0) {
                nums[i--][j] = num++;
            }
            i++, j++;
        }

        return nums;
    }

    void iter(vector<vector<int>> nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    int target = 4;
    s.iter(s.generateMatrixOpt(target));
    return 0;
}
