#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
        if (numRows < 2) {
            return s;
        }
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows - 1) {
                flag = -flag;
            }
            i += flag;
        }
        string res;
        for (const string &row : rows) {
            res += row;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string testStr = "PAYPALISHIRING";
    cout << s.convert(testStr, 3);
    return 0;
}
