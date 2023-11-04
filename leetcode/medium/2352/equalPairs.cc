#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int equalPairs(vector<vector<int>> &grid) {
        int size = grid.size();
        map<vector<int>, int> cnt;
        for (const auto &row : grid) {
            cnt[row]++;
        }
        int res = 0;
        for (int j = 0; j < size; ++j) {
            vector<int> col;
            for (int i = 0; i < size; ++i) {
                col.emplace_back(grid[i][j]);
            }
            if (cnt.find(col) != cnt.end()) {
                res += cnt[col];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
