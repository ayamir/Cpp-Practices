#include <bits/stdc++.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
        string res;
        stack<string> stk;
        int len = s.length();
        for (int i = 0; i < len;) {
            if (s[i] == ' ') {
                i++;
                continue;
            } else if (s[i] != ' ') {
                int j = i;
                string substr = "";
                while (s[j] != ' ' && j < len) {
                    substr += s[j++];
                }
                stk.push(substr);
                i = j;
            }
        }
        while (!stk.empty()) {
            res += stk.top();
            res += " ";
            stk.pop();
        }

        return res.substr(0, res.length() - 1);
    }
    string reverseWords2(string s) {
        string res = "";
        int n = s.size();
        bool firstFlag = true;
        string curr = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (curr == "") {
                    continue;
                } else {
                    if (firstFlag) {
                        res += curr;
                        firstFlag = false;
                    } else {
                        res += " " + curr;
                    }
                    curr = "";
                }
            } else {
                curr = s[i] + curr;
            }
        }
        if (curr != "") {
            if (res != "") {
                res += " " + curr;
            } else {
                res += curr;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string test = "  the sky is blue  ";
    cout << s.reverseWords2(test);
    return 0;
}
