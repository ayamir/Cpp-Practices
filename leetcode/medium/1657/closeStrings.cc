#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (const char &c : word1)
            cnt1[c - 'a']++;
        for (const char &c : word2)
            cnt2[c - 'a']++;
        for (int i = 0; i < 26; ++i)
            if ((cnt1[i] == 0 && cnt2[i] != 0) ||
                (cnt1[i] != 0 && cnt2[i] == 0))
                return false;
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        if (cnt1 != cnt2)
            return false;
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
