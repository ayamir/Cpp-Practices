#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    for (auto i : s.getRow(4)) {
        cout << i << " ";
    }
    return 0;
}
