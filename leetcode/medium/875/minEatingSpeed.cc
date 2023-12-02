#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        auto ask = [&](int k) -> bool {
            int needHours = 0;
            for (int pile : piles) {
                needHours += (pile + k - 1) / k;
            }
            return needHours <= h;
        };
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (ask(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
