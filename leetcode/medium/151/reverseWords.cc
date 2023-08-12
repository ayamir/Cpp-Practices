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
};

int main(int argc, char *argv[]) {
    Solution s;
    string test = "   Hello word";
    cout << s.reverseWords(test);
    return 0;
}
