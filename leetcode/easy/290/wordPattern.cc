#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        int m = pattern.size(), n = s.size();
        int i = 0;
        for (const auto c : pattern) {
            if (i >= n) {
                return false;
            }
            int j = i;
            while (j < n && s[j] != ' ')
                j++;
            const auto &sub = s.substr(i, j - i);
            if (s2p.count(sub) != 0 && s2p[sub] != c) {
                return false;
            }
            if (p2s.count(c) != 0 && p2s[c] != sub) {
                return false;
            }
            s2p[sub] = c;
            p2s[c] = sub;
            i = j + 1;
        }
        return i >= n;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string pattern = "abba";
    string str = "dog cat cat dog";
    cout << s.wordPattern(pattern, str);
    return 0;
}
