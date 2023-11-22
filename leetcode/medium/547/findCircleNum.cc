#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i])
                continue;
            dfs(isConnected, visited, i);
            ret++;
        }
        return ret;
    }

    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int i) {
        int n = isConnected.size();
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 0)
                continue;
            if (visited[j])
                continue;
            visited[j] = true;
            dfs(isConnected, visited, j);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
