#include <bits/stdc++.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
  private:
  public:
    int calculate(string s) {
        stack<int> st;
        int op = 1;
        long res = 0, num = 0;
        st.push(op);
        for (const auto &c : s) {
            if (c == ' ') {
                continue;
            } else if (c >= '0') {
                num = num * 10 + c - '0';
            } else {
                res += op * num;
                num = 0;

                if (c == '+') {
                    op = st.top();
                } else if (c == '-') {
                    op = -st.top();
                } else if (c == '(') {
                    st.push(op);
                } else {
                    st.pop();
                }
            }
        }
        return res + op * num;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string str = " 21-(1111 +   2) ";
    cout << s.calculate(str);
    return 0;
}
