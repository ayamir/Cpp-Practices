#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
  public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int idx;
        for (int i = 0, j = s.length() - 1; i < j;) {
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            if (!isVowel(s[i]))
                i++;
            if (!isVowel(s[j]))
                j--;
        }
        return s;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.reverseVowels("leetcode") << endl;
    return 0;
}
