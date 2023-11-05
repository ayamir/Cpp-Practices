#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> stk;
        for (const auto &aster : asteroids) {
            bool alive = true;
            while (alive && aster < 0 && !stk.empty() && stk.back() > 0) {
                alive = stk.back() < -aster;
                if (stk.back() <= -aster) {
                    stk.pop_back();
                }
            }
            if (alive) {
                stk.push_back(aster);
            }
        }
        return stk;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> asteroids = {10, 2, -5};
    for (const auto &v : s.asteroidCollision(asteroids)) {
        cout << v << " ";
    }
    return 0;
}
