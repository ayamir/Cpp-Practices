#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        int len = s.size();
        if (len % 2 != 0) {
            return false;
        }
        vector<char> stack;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push_back(s[i]);
            } else if (s[i] == ')') {
                if (stack.size() == 0 || stack.back() != '(') {
                    return false;
                }
                stack.pop_back();
            } else if (s[i] == ']') {
                if (stack.size() == 0 || stack.back() != '[') {
                    return false;
                }
                stack.pop_back();
            } else if (s[i] == '}') {
                if (stack.size() == 0 || stack.back() != '{') {
                    return false;
                }
                stack.pop_back();
            }
        }
        if (stack.size() != 0) {
            return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string str = "([)]";
    cout << s.isValid(str) << endl;
    return 0;
}
