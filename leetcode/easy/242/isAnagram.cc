#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> cnt(26, 0);
        for (auto &c : s) {
            cnt[c - 'a']++;
        }
        for (auto &c : t) {
            cnt[c - 'a']--;
        }
        for (auto &c : cnt) {
            if (c != 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string s1 = "anagram", t1 = "nagaram";
    cout << s.isAnagram(s1, t1) << endl;
    return 0;
}
