#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int minReoredrBFS(int n, vector<vector<int>> &connections) {
        int ret = 0;
        vector<vector<int>> conn_idx(n, vector<int>());
        for (int i = 0; i < connections.size(); ++i) {
            conn_idx[connections[i][0]].push_back(i);
            conn_idx[connections[i][1]].push_back(i);
        }
        vector<bool> visited(connections.size(), false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto idx : conn_idx[curr]) {
                if (visited[idx])
                    continue;
                visited[idx] = true;

                int a = connections[idx][0];
                int b = connections[idx][1];
                ret += (a == curr);
                a = (a == curr) ? b : a;
                q.push(a);
            }
        }
        return ret;
    }

    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<int>> table(n, vector<int>());
        for (auto &connection : connections) {
            table[connection[0]].push_back(connection[1]);
            table[connection[1]].push_back(-connection[0]);
        }
        // DFS
        int res = 0;
        vector<bool> visited(n, false);
        dfs(table, visited, 0, res);
        return res;
    }

    void dfs(vector<vector<int>> &table, vector<bool> &visited, int cur,
             int &res) {
        visited[cur] = true;
        for (int &next : table[cur]) {
            if (!visited[abs(next)]) {
                if (next > 0)
                    ++res;
                dfs(table, visited, abs(next), res);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
