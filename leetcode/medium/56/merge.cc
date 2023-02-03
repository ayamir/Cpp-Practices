#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (res.size() == 0 || res.back()[1] < left) {
                res.push_back({left, right});
            } else {
                res.back()[1] = max(res.back()[1], right);
            }
        }
        return res;
    }

    vector<vector<int>> mergeDoublePtr(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size();) {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            res.push_back({intervals[i][0], t});
            i = j;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> intervals = {{1, 4}, {0, 4}};
    for (auto &v : s.merge(intervals)) {
        cout << "{";
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
