#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string simplifyPath(string path) {
        vector<string> stk;
        int n = path.size();
        int start = 1, end = 1;
        while (end < n) {
            while (path[end] != '/' && end < n) {
                end++;
            }
            string dir = path.substr(start, end - start);
            end += 1;
            start = end;
            if (dir == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else if (dir != "." && dir != "") {
                stk.push_back(dir);
            }
        }
        string res = "";
        if (stk.empty()) {
            res = "/";
        } else {
            for (const string &dir : stk) {
                res += "/" + dir;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string path = "/a//b////c/d//././/..";
    cout << s.simplifyPath(path);
    return 0;
}
