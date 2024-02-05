#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  private:
    unordered_map<char, int> oper_pri = {{'+', 1}, {'-', 1}, {'*', 2},
                                         {'/', 2}, {'%', 2}, {'^', 3}};
    vector<char> opStk;
    vector<string> expStk;

  public:
    int calculate(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == ' ') {
                continue;
            } else if (oper_pri[c] != 0) {
                if (opStk.empty()) {
                    opStk.push_back(c);
                } else {
                    if (oper_pri[c] > oper_pri[opStk.back()]) {
                        opStk.push_back(c);
                    } else {
                        while (!opStk.empty() &&
                               oper_pri[c] <= oper_pri[opStk.back()]) {
                            expStk.push_back(string{opStk.back()});
                            opStk.pop_back();
                        }
                        opStk.push_back(c);
                    }
                }
            } else if (c == '(') {
                opStk.push_back(c);
            } else if (c == ')') {
                while (!opStk.empty() && opStk.back() != '(') {
                    expStk.push_back(string{opStk.back()});
                    opStk.pop_back();
                }
                opStk.pop_back();
            } else {
                int j = i + 1;
                while (j < n && s[j] >= '0' && s[j] <= '9') {
                    j++;
                }
                string num = s.substr(i, j - i);
                i = j - 1;
                expStk.push_back(num);
            }
        }
        while (!opStk.empty()) {
            expStk.push_back(string{opStk.back()});
            opStk.pop_back();
        }
        // evalRPN
        vector<int> stk;
        for (const auto &token : expStk) {
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
    string str = "1*2-3/4+5*6-7*8+9/10";
    cout << s.calculate(str);
    return 0;
}
