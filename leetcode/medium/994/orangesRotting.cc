#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
  public:
    int orangeRotting(vector<vector<int>> &grid) {
        int cnt = 0, ret = 0;
        int m = grid[0].size();
        int n = grid.size();
        int dis[10][10];
        memset(dis, -1, sizeof(dis));
        queue<tuple<int, int>> q;
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    dis[i][j] = 0;
                } else if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                    grid[nx][ny] == 0 || ~dis[nx][ny])
                    continue;
                dis[nx][ny] = dis[cx][cy] + 1;
                q.emplace(nx, ny);
                if (grid[nx][ny] == 1) {
                    cnt--;
                    ret = dis[nx][ny];
                    if (cnt == 0)
                        break;
                }
            }
        }
        return cnt != 0 ? -1 : ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1},
    };
    cout << s.orangeRotting(grid);
    return 0;
}
