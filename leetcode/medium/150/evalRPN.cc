#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stk;
        for (const auto &token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                stk.push_back(stoi(token));
            } else {
                int b = stk.back();
                stk.pop_back();
                int a = stk.back();
                stk.pop_back();
                if (token == "+") {
                    stk.push_back(a + b);
                } else if (token == "-") {
                    stk.push_back(a - b);
                } else if (token == "*") {
                    stk.push_back(a * b);
                } else if (token == "/") {
                    stk.push_back(a / b);
                }
            }
        }
        return stk.back();
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << s.evalRPN(tokens);
    return 0;
}
