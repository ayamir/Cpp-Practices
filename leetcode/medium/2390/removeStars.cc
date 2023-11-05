#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Solution {
  public:
    string removeStars(string s) {
        stack<char> stk;
        for (const auto &c : s) {
            if (c != '*') {
                stk.push(c);
            } else {
                if (!stk.empty())
                    stk.pop();
            }
        }
        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string removeStarsDoublePtr(string s) {
        int slow = 0, fast = 0;
        while (fast < s.size()) {
            if (s[fast] == '*') {
                if (slow > 0) {
                    --slow;
                }
                ++fast;
            } else {
                s[slow++] = s[fast++];
            }
        }
        s.resize(slow);
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution solu;
    string s = "erase*****";
    cout << solu.removeStarsDoublePtr(s);
    return 0;
}
