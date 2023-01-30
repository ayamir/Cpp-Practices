#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int inf = 1e9;
        int minPrice = inf, res = 0;
        for (int price : prices) {
            res = max(res, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> prices = {2, 4, 1};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
