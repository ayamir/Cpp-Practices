#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int largestAltitude(vector<int> &gain) {
        int sum = 0, res = 0;
        for (int v : gain) {
            sum += v;
            res = res < sum ? sum : res;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};
    cout << s.largestAltitude(gain);
    return 0;
}
