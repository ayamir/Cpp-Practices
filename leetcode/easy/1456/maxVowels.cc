#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int curr = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                curr++;
            }
        }
        int res = 0;
        for (int right = k; right < s.length(); ++right) {
            if (isVowel(s[right - k]))
                curr--;
            if (isVowel(s[right]))
                curr++;
            res = res < curr ? curr : res;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution solu;
    string s = "leetcode";
    cout << solu.maxVowels(s, 3);
    return 0;
}
