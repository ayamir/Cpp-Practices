#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x = 0, y = 0;
        int loop = n / 2;
        int mid = n / 2;
        int cnt = 1;
        int offset = 1;
        int i, j;
        while (loop--) {
            i = x;
            j = y;
            while (j < n - offset) {
                res[i][j++] = cnt++;
            }
            while (i < n - offset) {
                res[i++][j] = cnt++;
            }
            while (j > y) {
                res[i][j--] = cnt++;
            }
            while (i > x) {
                res[i--][j] = cnt++;
            }
            x++;
            y++;
            offset++;
        }
        if (n % 2 == 1) {
            res[mid][mid] = cnt;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    auto matrix = s.generateMatrix(3);
    for (auto &&row : matrix) {
        for (auto &&num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
