#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isSubsequence(string s, string t) {
        bool res = false;
        int sp = 0, tp = 0;
        while (sp < s.size() && tp < t.size()) {
            if (s.at(sp) == t.at(tp)) {
                sp++;
                tp++;
            } else {
                tp++;
            }
        }
        if (sp == s.size() && tp <= t.size()) {
            res = true;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution solu;
    string s = "ace";
    string t = "axrde";
    cout << solu.isSubsequence(s, t) << endl;
    return 0;
}
