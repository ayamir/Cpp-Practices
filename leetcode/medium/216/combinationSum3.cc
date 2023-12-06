#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<int> path;
    vector<vector<int>> ret;

    void backtracking(int targetSum, int startIndex, int k, int sum) {
        if (sum > targetSum) {
            return;
        }
        if (path.size() == k) {
            if (sum == targetSum)
                ret.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, i + 1, k, sum);
            sum -= i;
            path.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ret.clear();
        path.clear();
        backtracking(n, 1, k, 0);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
