#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] > target) {
                return false;
            }
            if (matrix[i][0] == target) {
                return true;
            }
            if (matrix[i][matrix[i].size() - 1] < target) {
                continue;
            }
            if (matrix[i][matrix[i].size() - 1] == target) {
                return true;
            }
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }

    bool searchMatrixBS(vector<vector<int>> &matrix, int target) {
        for (const auto &row : matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target)
                return true;
        }
        return false;
    }

    bool searchMatrixZ(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] < target)
                x++;
            else
                y--;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},    {2, 5, 8, 12, 19},    {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30},
    };
    cout << s.searchMatrix(matrix, 5) << endl;
    return 0;
}
