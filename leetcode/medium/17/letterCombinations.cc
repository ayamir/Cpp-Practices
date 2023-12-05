#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    const string letterMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };
    vector<string> ret;
    string s;
    void backtracking(const string &digits, int index) {
        if (index == digits.size()) {
            ret.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (const auto &letter : letters) {
            s.push_back(letter);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        ret.clear();
        if (digits.size() == 0) {
            return ret;
        }
        backtracking(digits, 0);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
