#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if (n * m != r * c) {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < n * m; ++i) {
            res[i / c][i % c] = mat[i / m][i % m];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}};
    auto res = s.matrixReshape(mat, 3, 2);
    for (auto &v : res) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
