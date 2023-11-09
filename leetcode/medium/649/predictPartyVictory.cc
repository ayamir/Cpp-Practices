#include <bits/stdc++.h>
#include <queue>
#include <string>

using namespace std;

class Solution {
  public:
    string predictPartyVictory(string senate) {
        int size = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < size; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() || !dire.empty()) {
            int currRadiant = radiant.front();
            int currDire = dire.front();
            if (currRadiant < currDire) {
                radiant.push(currRadiant + size);
            } else {
                dire.push(currDire + size);
            }
            radiant.pop();
            dire.pop();
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
