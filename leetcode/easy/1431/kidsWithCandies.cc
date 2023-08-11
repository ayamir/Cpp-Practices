#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<bool> kindsWithCandies(vector<int> &candies, int extraCandies) {
        int max = 0;
        int len = candies.size();
        vector<bool> res;
        res.reserve(len);
        for (auto val : candies) {
            if (val >= max) {
                max = val;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (candies[i] + extraCandies >= max) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    auto res = s.kindsWithCandies(candies, extraCandies);
    for (auto val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
