#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        // find exits
        int x = entrance[0];
        int y = entrance[1];
        int m = maze.size();
        int n = maze[0].size();
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        queue<tuple<int, int, int>> q;
        q.emplace(x, y, 0);
        maze[x][y] = '+';
        while (!q.empty()) {
            auto [cx, cy, d] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    maze[nx][ny] == '.') {
                    if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) {
                        return d + 1;
                    }
                    maze[nx][ny] = '+';
                    q.emplace(nx, ny, d + 1);
                }
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<char>> maze{
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'},
    };
    vector<int> entrance;
    entrance.reserve(2);
    entrance.push_back(1);
    entrance.push_back(2);
    cout << s.nearestExit(maze, entrance);
    return 0;
}
