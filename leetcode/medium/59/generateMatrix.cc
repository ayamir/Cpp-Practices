#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0, j = 0, k = 1; k <= n * n;) {
            while (j < n && res[i][j] == 0)
                res[i][j++] = k++;
            i++, j--;
            while (i < n && res[i][j] == 0)
                res[i++][j] = k++;
            i--, j--;
            while (j >= 0 && res[i][j] == 0)
                res[i][j--] = k++;
            i--, j++;
            while (i >= 0 && res[i][j] == 0)
                res[i--][j] = k++;
            i++, j++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    for (auto &v : s.generateMatrix(4)) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
