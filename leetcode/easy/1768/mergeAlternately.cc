#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
  public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        int len1 = word1.size();
        int len2 = word2.size();
        string res;
        res.reserve(len1 + len2);
        while (i < len1 || j < len2) {
            if (i < len1) {
                res.push_back(word1[i++]);
            }
            if (j < len2) {
                res.push_back(word2[j++]);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string word1 = "abc";
    string word2 = "pqr";
    cout << s.mergeAlternately(word1, word2) << endl;
    return 0;
}
