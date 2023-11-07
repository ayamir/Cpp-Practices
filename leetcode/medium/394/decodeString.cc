#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string getCnt(const string &s, int &pos) {
        string res;
        while (isdigit(s[pos])) {
            res.push_back(s[pos++]);
        }
        return res;
    }

    string getUnit(vector<string> &v) {
        string res;
        for (const auto &s : v) {
            res += s;
        }
        return res;
    }

    string decodeString(string s) {
        vector<string> stk;
        int i = 0;
        int size = s.size();
        while (i < size) {
            char curr = s[i];
            if (isdigit(curr)) {
                stk.push_back(getCnt(s, i));
            } else if (curr == '[' || isalpha(curr)) {
                stk.push_back(string(1, s[i++]));
            } else {
                ++i;
                vector<string> str;
                while (stk.back() != "[") {
                    str.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(str.begin(), str.end());
                stk.pop_back();
                int cnt = stoi(stk.back());
                stk.pop_back();
                string replicated = "";
                string unit = getUnit(str);
                while (cnt > 0) {
                    replicated += unit;
                    cnt--;
                }
                stk.push_back(replicated);
            }
        }
        return getUnit(stk);
    }

    string decodeStringFast(string s) {
        stack<int> cntStk;
        stack<string> strStk;
        string res;
        int currCnt = 0;
        for (const auto &c : s) {
            if (isdigit(c)) {
                currCnt = currCnt * 10 + c - '0';
            } else if (c == '[') {
                cntStk.push(currCnt);
                currCnt = 0;
                strStk.push(res);
                res = "";
            } else if (c == ']') {
                string tmp = strStk.top();
                strStk.pop();
                int cnt = cntStk.top();
                cntStk.pop();
                for (int i = 0; i < cnt; ++i) {
                    tmp.append(res);
                }
                res = tmp;
            } else {
                res.append(1, c);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
