#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[1] < b[1];
             });
        int n = intervals.size();
        int right = intervals[0][1];
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= right) {
                res++;
                right = intervals[i][1];
            }
        }
        return n - res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
