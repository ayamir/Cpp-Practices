#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<bool> vis;
    int num;

    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int unVisitedRoomNum = rooms.size();
        vector<int> canVisited;
        canVisited.reserve(unVisitedRoomNum);
        queue<int> keys;
        keys.push(0);
        while (!keys.empty()) {
            int curr = keys.front();
            keys.pop();
            auto currRoomKeys = rooms[curr];
            for (auto k : currRoomKeys) {
                if (k != 0 && find(canVisited.begin(), canVisited.end(), k) ==
                                  canVisited.end()) {
                    canVisited.push_back(k);
                    keys.push(k);
                }
            }
        }
        int last = 0;
        for (int curr : canVisited) {
            cout << curr << endl;
            if (last != curr) {
                unVisitedRoomNum--;
                last = curr;
            }
        }
        return unVisitedRoomNum == 1;
    }
    void dfs(vector<vector<int>> &rooms, int x) {
        vis[num] = true;
        num++;
        for (auto &n : rooms[x]) {
            if (!vis[n]) {
                dfs(rooms, n);
            }
        }
    }
    bool canVisitAllRoomsDFS(vector<vector<int>> &rooms) {
        int n = rooms.size();
        num = 0;
        vis.resize(n);
        dfs(rooms, 0);
        return num == n;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> rooms{{1}, {2}, {3}, {0}};
    cout << s.canVisitAllRooms(rooms);
    return 0;
}
